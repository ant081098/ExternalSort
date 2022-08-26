#pragma once

#include <fstream>
#include <vector>

struct MergeFile
{
    MergeFile(const std::vector<std::string>& m_parts);
    ~MergeFile();
    bool merge(std::string filename);
protected:
    bool ready() const;
private:
    bool m_ready;
    std::vector<std::fstream> m_files;
};
