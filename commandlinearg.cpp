#include "commandlinearg.h"
#include <algorithm>

using namespace std;

CommandLineArg::CommandLineArg(int argc, char *argv[]) : IOptions()
{
    m_listArgv.reserve(argc);
    for(int i=0;i<argc;i++)
        m_listArgv.push_back(argv[i]);
}

CommandLineArg::~CommandLineArg()
{

}

bool CommandLineArg::prepareData()
{
    return parse();
}

string CommandLineArg::param(const std::string &key) const
{
    return m_arguments.at(key); //Check exist key!
}

bool CommandLineArg::parse()
{
    auto key = begin(m_listArgv);
    while(key != end(m_listArgv)){
        key = find_if(key, end(m_listArgv), [](string& param){ //find key argument
                return param.front() == '-';
    });
        if(key == end(m_listArgv)) break;
        auto value = next(key); //Read value argument
        if(value == end(m_listArgv)) break;
        m_arguments[*key] = *value; //Append argument
        key = next(value);
    }
    if(m_listArgv.size() - 1 != m_arguments.size() * 2){ //Check count argument
        return false;
    }

    return checkValidArguments();
}

bool CommandLineArg::checkValidArguments()
{
    if(!(m_arguments.count("-o") && m_arguments.count("-i"))){ //Check contain compulsory key
        return false;
    }
    if(m_arguments.count("-d")){ // check -d argument
        try {
            auto delims = stoi(m_arguments["-d"]);
            if(delims < 0 || delims > 200)  // check range
                throw invalid_argument("Invalid range (-d)");
        } catch(invalid_argument &e){
            return false;
        }
    } else{
        m_arguments["-d"] = "200";  //Default value split
    }
    return true;
}
