#pragma once


#include <fstream>
#include <vector>
#include <optional>

//Merge stage sorting
struct MergeFile
{
    MergeFile(const std::vector<std::string>& m_parts);
    ~MergeFile();
    bool merge(const std::string& filename);
protected:
    std::optional<std::string> getNextLine(size_t indexFile); //Get next line from file by index
private:
    std::vector<std::fstream> m_files;  //file stream list for merge
};
