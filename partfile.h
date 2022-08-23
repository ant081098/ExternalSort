#pragma once

#include <string>

struct PartFile
{
    PartFile(std::string filename);
    ~PartFile();
    void sorting();

private:
    std::string m_filename;
};

