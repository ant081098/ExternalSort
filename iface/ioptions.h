#pragma once
#include <string>

//Interface input options
struct IOptions
{
    IOptions();
    virtual bool prepareData() = 0; //Prepare data options
    virtual std::string param(const std::string& key) const = 0; //Get parameter by key
    virtual ~IOptions();
};

