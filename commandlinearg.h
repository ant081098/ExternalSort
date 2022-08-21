#pragma once

#include <map>
#include <vector>

#include "iface/inputdata.h"

struct CommandLineArg : public InputData
{
    CommandLineArg(int argc, char* argv[]);
    bool prepareData();
    std::string operator()(const std::string& key) const;
    ~CommandLineArg();

protected:
    bool parse();
    bool checkValidArguments();
private:
    std::vector<std::string> m_listArgv;
    std::map<std::string, std::string> m_arguments;
};

