#include "splitfile.h"
#include "exceptfile.h"
#include "fileline.h"

#include <deque>
#include <vector>
#include <memory>
#include <algorithm>
#include <filesystem>

#include "../iface/ilog.h"

using namespace std;

SplitFile::SplitFile(const std::string& filename) : m_filename(filename)
{

}

SplitFile::~SplitFile()
{
    removeParts();
}

std::vector<string> SplitFile::getParts() const
{
    return m_parts;
}

void SplitFile::removeParts()
{
    for(auto& filename : m_parts){
        filesystem::remove(filename);   //remove file
    }
}

bool SplitFile::split(int countBlock)
{
    m_parts.reserve(countBlock);    //reserve space
    ifstream file(m_filename, ios::binary | ios::in);
    if(!file.is_open()){
        throw ExceptFile(ExceptFile::Step::SPLIT, "File '" + m_filename + "' not found");
    }

    long long sizeFile = getFileSize(file);
    long long sizeBlock = sizeFile / countBlock;
    long long offsetFile = 0L; //Offset for input file

    for (int block = 0; block < countBlock; ++block){
        auto filename = m_filename + ".part." + std::to_string(block); //filename part
        unique_ptr<char> buffer;    //reserve pointer<char> for content
        auto bufferSize = 0L;

        ILog("\tRead "+ to_string(block + 1) +" block <-- '" + m_filename + "'");

        if(block == countBlock - 1){ //Read last block
            bufferSize = readBlock(file, buffer, offsetFile, sizeFile - offsetFile, true);

        } else {
            bufferSize = readBlock(file, buffer, offsetFile, sizeBlock);
            offsetFile += bufferSize;   //modify offset for input file
        }

        ILog("\tWrite block --> '" + filename + "'");
        writeBlock(filename, buffer.get(), bufferSize); //Write block in part file
        m_parts.push_back(filename);
    }

    file.close();
    return true;
}

long SplitFile::getFileSize(ifstream& file) const
{
    file.seekg(0, ios::end);
    return file.tellg();
}

void SplitFile::writeBlock(const std::string& filename, char *buffer, long size)
{
    deque<FileLine> lines; //Set lines autosorting by key

    auto pos = buffer;
    for (long index = 0; index < size; index++) {
        if(buffer[index]=='\n'){    //Find symbol \n
            buffer[index] = '\0';   //cut string
            lines.push_back(FileLine(pos));  //append line in deque
            pos = buffer + (index + 1);
        }
    }


    vector vectorLines(begin(lines), end(lines));
    sort(begin(vectorLines), end(vectorLines));

    stringstream stream; //intermediate buffer
    for(auto& line : vectorLines){
        stream << line.toLine() << "\n";
    }
    ofstream outFile(filename, ios::out | ios::binary);
    if(!outFile.is_open()){
        throw ExceptFile(ExceptFile::Step::SPLIT, "Failed output in '" + filename + "'");
    }
    outFile << stream.rdbuf();  //Write stream buffer in output file
    outFile.close();

}

long SplitFile::readBlock(std::ifstream &file, std::unique_ptr<char>& buffer, long offset, long size, bool lastBlock)
{
    buffer = unique_ptr<char>(new char[size]);
    file.seekg(offset, ios::beg);
    file.read(buffer.get(), size);

    //Find prev symbol '\n'
    for(;!lastBlock && size > 0 && buffer.get()[size - 1] != '\n' ; size--);
    return size;
}
