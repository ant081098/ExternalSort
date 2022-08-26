#pragma once

#include <string>

struct SortFile
{
    SortFile(std::string filename);
    ~SortFile();
    void sort();
protected:
    long getFileSize(std::ifstream& file) const;

private:
    std::string m_filename;
};

