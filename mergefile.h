#pragma once

#include <fstream>
#include <vector>

struct MergeFile
{
    MergeFile(const std::vector<std::string>& vecFilename);
    ~MergeFile();
    void sortMerge(std::string filename);

private:
    std::vector<std::ifstream> m_files;
};
