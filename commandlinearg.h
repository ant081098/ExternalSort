#pragma once

#include <map>
#include <vector>

#include "iface/ioptions.h"

//Command line oprions (argc, argv)
struct CommandLineArg : public IOptions
{
    CommandLineArg(int argc, char* argv[]);
    ~CommandLineArg() override;

    bool prepareData() override;
    std::string param(const std::string& key) const override;

protected:
    bool parse(); //parsing argv
    bool checkValidArguments(); //checker
private:
    std::vector<std::string> m_listArgv;    //list arguments
    std::map<std::string, std::string> m_arguments; //map arguments by key
};

