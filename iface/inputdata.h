#pragma once
#include <string>

struct InputData
{
    InputData();
    virtual bool prepareData() = 0;
    virtual std::string operator()(const std::string& key) const = 0;
    virtual ~InputData();
};

