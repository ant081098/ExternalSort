#pragma once

#include <string>
#include <ostream>

struct ILog : public std::ostream
{
    ILog(std::string log);
    ~ILog();

    static time_t getTime();

protected:
    std::string timeLog();

};

