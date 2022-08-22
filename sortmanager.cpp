#include "sortmanager.h"

using namespace std;

SortManager::SortManager()
{

}

SortManager::~SortManager()
{

}

void SortManager::setOptions(IOptions *options)
{
    m_options = unique_ptr<IOptions>(options);
    m_options->prepareData();
}

void SortManager::sort(ISorting* sorting)
{
    unique_ptr<ISorting> instanceSort = unique_ptr<ISorting>(sorting);
    instanceSort->setOptions(m_options.get());
    instanceSort->run();
}
