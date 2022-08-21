#include "sortmanager.h"

using namespace std;

SortManager::SortManager()
{

}

void SortManager::setSourceData(InputData *source)
{
    m_source = unique_ptr<InputData>(source);
    m_source->prepareData();
}

SortManager::~SortManager()
{

}
