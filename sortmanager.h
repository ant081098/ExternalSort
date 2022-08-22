#pragma once

#include <memory>

#include "iface/ioptions.h"
#include "iface/isorting.h"

struct SortManager
{
public:
    SortManager();
    void setOptions(IOptions* options);
    void sort();
    ~SortManager();

protected:
    void splitFileIntoParts();

private:
    std::unique_ptr<IOptions> m_options;



};
