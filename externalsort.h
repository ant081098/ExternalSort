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
    std::vector<std::string> split();
    void merge(std::vector<std::string>& vecFilenameParts);
private:
    std::string m_inputFilename, m_outputFilename;
    int m_countParts;
};
