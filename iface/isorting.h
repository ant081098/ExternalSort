#pragma once

#include "ioptions.h"

struct ISorting
{
    ISorting();
    virtual void setOptions(IOptions* options) = 0;
    virtual void run() = 0;
    virtual ~ISorting();
};
