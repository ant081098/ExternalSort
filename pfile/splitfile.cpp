#include "splitfile.h"
#include <memory>
#include <filesystem>

using namespace std;

SplitFile::SplitFile(std::string filename)
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
        filesystem::remove(filename);
    }
}

bool SplitFile::split(int countBlock)
{
    m_parts.reserve(countBlock);

    ifstream file(m_filename, ios::binary | ios::in);
    if(!file.is_open()){
        return false;
    }

    long sizeFile = getFileSize(file);
    long sizeBlock = sizeFile / countBlock;
    long offsetFile = 0L;

    for (int block = 0; block < countBlock; ++block){
        auto filename = m_filename + ".part." + std::to_string(block);
        unique_ptr<char> buffer;
        auto bufferSize = 0L;
        if(block == countBlock - 1){
            bufferSize = readBlock(file, buffer.get(), offsetFile, sizeFile - offsetFile, true);
        } else {
            bufferSize = readBlock(file, buffer.get(), offsetFile, sizeBlock);
            offsetFile += bufferSize;
        }
        writeBlock(filename, buffer.get(), bufferSize);
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

void SplitFile::writeBlock(std::string filename, char *buffer, long size)
{
    ofstream outFile(filename, ios::out | ios::binary);
    outFile.write(buffer, size);
    outFile.close();
}

long SplitFile::readBlock(std::ifstream &file, char* buffer, long offset, long size, bool lastBlock)
{
    buffer = new char[size];
    file.seekg(offset, ios::beg);
    file.read(buffer, size);
    for(;!lastBlock && size > 0 && buffer[size - 1] != '\n' ; size--);
    return size;
}