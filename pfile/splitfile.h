#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <memory>

struct SplitFile
{
    SplitFile(std::string filename);
    ~SplitFile();
    std::vector<std::string> getParts() const;
    bool split(int partCount);
protected:
    void removeParts();
    long getFileSize(std::ifstream& file) const;
    void writeBlock(std::string filename, char* buffer, long size);
    long readBlock(std::ifstream& file, std::unique_ptr<char>& buffer, long offset, long size, bool lastBlock = false);
private:
    std::string m_filename;
    std::vector<std::string> m_parts;
};
