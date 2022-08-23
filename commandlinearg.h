#pragma once

#include <map>
#include <vector>

#include "iface/ioptions.h"

struct CommandLineArg : public IOptions
{
    CommandLineArg(int argc, char* argv[]);
    ~CommandLineArg() override;

    bool prepareData() override;
    std::string param(const std::string& key) const override;

protected:
    bool parse();
    bool checkValidArguments();
private:
    std::vector<std::string> m_listArgv;
    std::map<std::string, std::string> m_arguments;
};

