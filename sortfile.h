#pragma once

#include <fstream>
#include <memory>

struct SortFile
{
    SortFile(std::string filename);
    ~SortFile();
    long getSize();
    long writeBlockIntoFile(std::string filename, long offset, long blockSize, bool lastBlock = false);

private:
    std::ifstream m_file;
};
