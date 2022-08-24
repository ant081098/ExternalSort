#include "sortfile.h"
#include <memory>

using namespace std;

SortFile::SortFile(std::string filename)
{
    m_file.open(filename, ios::in | ios::binary);
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


long SortFile::writeBlockIntoFile(string filename, long offset, long blockSize, bool lastBlock)
{
    unique_ptr<char> buffer = unique_ptr<char>(new char[blockSize]);
    m_file.seekg(offset, ios::beg);
    m_file.read(buffer.get(), blockSize);

    while(!lastBlock && blockSize > 0){
        if(buffer.get()[blockSize]=='\n'){
            blockSize += 1;
            break;
        }
        --blockSize;
    }

    ofstream outFile(filename, ios::out | ios::binary);
    outFile.write(buffer.get(), blockSize);
    outFile.close();
    return blockSize;
}
