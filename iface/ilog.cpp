#include "ilog.h"

#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

ILog::ILog(std::string log)
{
    cout << timeLog() << " " << log << "\n";
}

ILog::~ILog()
{

}

string ILog::timeLog()
{
    stringstream stream;
    auto currentTime = time(0);
    auto nowTime = localtime(&currentTime);
    stream << "[" << nowTime->tm_hour << ":" << nowTime->tm_min << ":" << nowTime->tm_sec << "]";
    return stream.str();
}
