#pragma once


#include <fstream>
#include <vector>
#include <optional>

struct MergeFile
{
    MergeFile(const std::vector<std::string>& m_parts);
    ~MergeFile();
    bool merge(std::string filename);
protected:
    bool ready() const;
    std::optional<std::string> getNextLine(size_t indexFile);
private:
    bool m_ready;
    std::vector<std::fstream> m_files;
};
