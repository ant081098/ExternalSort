#include "externalsort.h"
#include "pfile/splitfile.h"
#include "pfile/sortfile.h"
#include "pfile/mergefile.h"

#include <filesystem>

using namespace std;

ExternalSort::ExternalSort() : ISorting(), m_inputFilename(""), m_outputFilename(""), m_countParts(1)
{

}

ExternalSort::~ExternalSort()
{

}

void ExternalSort::setOptions(IOptions *options)
{
    m_inputFilename = options->param("-i");
    m_countParts = stoi(options->param("-d"));
    m_outputFilename = options->param("-o");
}

void ExternalSort::run()
{
    SplitFile stepSplit(m_inputFilename);
    if(stepSplit.split(m_countParts)){
        for(auto& filename : stepSplit.getParts()){
            SortFile stepSort(filename);
            stepSort.sort();
        }
        MergeFile stepMerge(stepSplit.getParts());
        stepMerge.merge(m_outputFilename);
    }
}
