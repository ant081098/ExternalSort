#pragma once

#include <fstream>

struct SortFile
{
    SortFile(std::string filename);
    ~SortFile();
    long getSize();
    long writeBlockIntoFile(std::string filename, long offset, long blockSize);


private:
    std::ifstream m_file;
};
