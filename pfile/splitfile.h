#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <memory>

//Split stage sorting
struct SplitFile
{
    SplitFile(const std::string& filename);
    ~SplitFile();
    std::vector<std::string> getParts() const;  //Get list of filenames
    bool split(int partCount);
protected:
    void removeParts(); //Remove all parts on disk
    long getFileSize(std::ifstream& file) const;
    //Write block in .part file
    void writeBlock(const std::string& filename, char* buffer, long size);
    //Read block from input file
    long readBlock(std::ifstream& file, std::unique_ptr<char>& buffer, long offset, long size, bool lastBlock = false);
private:
    std::string m_filename; //Input filename
    std::vector<std::string> m_parts;   //filename parts
};
