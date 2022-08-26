#pragma once

#include <string>

struct FileLine
{
    FileLine(const std::string& line);
    ~FileLine();
    void fromLine(const std::string& line);
    std::string toLine() const;
    bool operator<(const FileLine& line) const;

protected:
    std::string value() const ;
    unsigned long long key() const;

private:
    unsigned long long m_key;
    std::string m_value;

};

