#pragma once

#include <string>
#include <ostream>

struct ILog : public std::ostream
{
    ILog(std::string log);
    ~ILog();
protected:
    std::string timeLog();

};

