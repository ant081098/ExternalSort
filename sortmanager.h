#pragma once

#include <memory>

#include "iface/inputdata.h"

struct SortManager
{
public:
    SortManager();
    void setSourceData(InputData* source);
    ~SortManager();

private:
    std::unique_ptr<InputData> m_source;
};
