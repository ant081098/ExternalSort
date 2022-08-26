#pragma once

#include "ioptions.h"

//Interface sorting
struct ISorting
{
    ISorting();
    virtual void setOptions(IOptions* options) = 0; //Set options for sorting
    virtual void run() = 0; //Start sorting
    virtual ~ISorting();
};
