#include "sortfile.h"

#include <memory>

using namespace std;

SortFile::SortFile(std::string filename)
{
    m_file.open(filename, ios::in | ios::binary);
    if(!m_file.is_open())
        return; //throw invalid file
}

SortFile::~SortFile()
{
    m_file.close();
}

long SortFile::getSize()
{
    m_file.seekg(0, ios::end);
    return m_file.tellg();
}

long SortFile::writeBlockIntoFile(std::string filename, long offset, long blockSize)
{
    unique_ptr<char> buffer = unique_ptr<char>(new char[blockSize]);
    m_file.seekg(offset, ios::beg);
    m_file.read(buffer.get(), blockSize);

    while(blockSize > 0 && buffer.get()[--blockSize]!='\n');

    ofstream outFile(filename, ios::out | ios::binary);
    outFile.write(buffer.get(), blockSize);
    outFile.close();

    return blockSize;
}
