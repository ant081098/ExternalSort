#include "sortfile.h"
#include "exceptfile.h"
#include "fileline.h"

#include <set>
#include <fstream>
#include <sstream>
#include <memory>
#include <algorithm>

#include "../iface/ilog.h"

using namespace std;



SortFile::SortFile(std::string filename) : m_filename(filename)
{
    ILog("\tsort block: " + filename);
}

SortFile::~SortFile()
{

}

void SortFile::sort()
{
    multiset<FileLine> setLines;
    ifstream reader(m_filename, /*ios::binary |*/ ios::in);

    if(!reader.is_open()) {
        throw ExceptFile(ExceptFile::Step::SORT_PARTS, "File '" + m_filename + "' not found");
    }
    ILog("\t\treading");



    for(string buffer; getline(reader, buffer, '\n');){
        FileLine line(buffer);
        setLines.insert(line);
    }



//    long sizeFile = getFileSize(reader);
//    unique_ptr<char> buffer = unique_ptr<char>(new char[sizeFile]);

//    stringstream ss(buffer.get());
//    char* s;
//    ss.getline(s, '\n');

//    reader.seekg(0, ios::beg);
//    reader.read(buffer.get(), sizeFile);
//    reader.close();
//    auto pos = buffer.get();
//    for (long index=0; index < sizeFile; index++) {
//        if(buffer.get()[index]=='\n'){
//            buffer.get()[index] = '\0';
//            string tempLine(pos);
//            pos = buffer.get() + (index + 1);
//            FileLine line(move(tempLine));
//            setLines.insert(line);
//        }
//    }
//    buffer.reset();

    ILog("\t\twriting");
    ofstream writer(m_filename, ios::out);
    if(!writer.is_open()) {
        throw ExceptFile(ExceptFile::Step::SORT_PARTS, "Failed output in '" + m_filename + "'");
    }
    for(auto& line : setLines){
        writer << line.toLine() << "\n";
    }
    writer.close();
}

long SortFile::getFileSize(std::ifstream &file) const
{
    file.seekg(0, ios::end);
    return file.tellg();
}
