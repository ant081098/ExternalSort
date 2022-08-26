#pragma once

#include <string>

struct SortFile
{
    SortFile(std::string filename);
    ~SortFile();
    void sort();

private:
    std::string m_filename;
};

