#include "sortmanager.h"

using namespace std;

SortManager::SortManager()
{

}

SortManager::~SortManager()
{

}

bool SortManager::setOptions(IOptions *options)
{
    m_options = unique_ptr<IOptions>(options);
    if(!options->prepareData())
        return false;
    return true;
}

void SortManager::sort(ISorting* sorting)
{
    unique_ptr<ISorting> instanceSort = unique_ptr<ISorting>(sorting);
    instanceSort->setOptions(m_options.get());
    instanceSort->run();
}
