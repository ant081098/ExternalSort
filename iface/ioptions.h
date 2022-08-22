#pragma once
#include <string>

struct IOptions
{
    IOptions();
    virtual bool prepareData() = 0;
    virtual std::string param(const std::string& key) const = 0;
    virtual ~IOptions();
};

