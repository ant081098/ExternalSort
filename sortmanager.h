#pragma once

#include <memory>

#include "iface/ioptions.h"
#include "iface/isorting.h"

//Sorting Manager
struct SortManager
{
public:
    SortManager();
    ~SortManager();
    bool setOptions(IOptions* options); //set options (argc, argv)
    void sort(ISorting* sorting); //sorting

private:
    std::unique_ptr<IOptions> m_options; //Options

};
