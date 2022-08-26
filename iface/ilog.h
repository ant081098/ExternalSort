#pragma once

#include <string>
#include <ostream>

//Logging class
struct ILog : public std::ostream
{
    ILog(const std::string& log);
    ~ILog();
protected:
    std::string timeLog(); //prefix time
};

