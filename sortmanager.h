#pragma once

#include <memory>

#include "iface/ioptions.h"
#include "iface/isorting.h"

struct SortManager
{
public:
    SortManager();
    ~SortManager();
    bool setOptions(IOptions* options);
    void sort(ISorting* sorting);

protected:
    void splitFileIntoParts();

private:
    std::unique_ptr<IOptions> m_options;



};
