#pragma once

#include <string>

//Format line in file
struct FileLine
{
    FileLine(const std::string& line);
    ~FileLine();
    void fromLine(const std::string& line); //convert from string
    std::string toLine() const; //Convert to line
    bool operator<(const FileLine& line) const;

protected:
    std::string value() const ;
    unsigned long long key() const;

private:
    unsigned long long m_key; //key
    std::string m_value;    //value

};

