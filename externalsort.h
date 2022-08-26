#pragma once

#include <vector>
#include "iface/isorting.h"

//Algorithm file sorting
struct ExternalSort : public ISorting
{
    ExternalSort();
    ~ExternalSort() override;
    void setOptions(IOptions* options) override;    //Setting options
    void run() override;    //start sort

private:
    std::string m_inputFilename, m_outputFilename;  //Input, Output file
    int m_countParts;   //Count parts
};
