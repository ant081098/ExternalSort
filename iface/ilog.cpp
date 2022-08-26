#include "ilog.h"

#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

ILog::ILog(std::string log)
{
    cout << timeLog() << " " << log << "\n";
}

ILog::~ILog()
{

}

time_t ILog::getTime()
{
    auto currentTime = time(0);
    auto nowTime = localtime(&currentTime);
    return ((nowTime->tm_hour) * 60 + nowTime->tm_min) * 60 + nowTime->tm_sec;
}

string ILog::timeLog()
{
    stringstream stream;
    auto currentTime = time(0);
    auto nowTime = localtime(&currentTime);
    stream.setf(ios::fixed);
    stream << "[" << std::put_time(nowTime, "%H:%M:%S") << "]";
    return stream.str();
}
