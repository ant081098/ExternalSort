#pragma once

#include <vector>
#include "iface/isorting.h"

struct ExternalSort : public ISorting
{
    ExternalSort();
    ~ExternalSort() override;
    void setOptions(IOptions* options) override;
    void run() override;

protected:
    void split(std::string filename, int parts);
    void sort();
    void merge(std::vector<std::string> listFilename);
private:
    std::string m_inputFilename, m_outputFilename;
    int m_countParts;
};
