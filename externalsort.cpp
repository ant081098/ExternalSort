#include "externalsort.h"
#include "pfile/splitfile.h"
#include "pfile/sortfile.h"
#include "pfile/mergefile.h"

#include <iostream>

#include "iface/ilog.h"

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
    auto tm = ILog::getTime();
    auto tmBegin = tm;

    ILog("start split");
    SplitFile stepSplit(m_inputFilename);
    stepSplit.split(m_countParts);
    ILog("finish split (" + to_string(ILog::getTime() - tm) + " sec)");

//    tm = ILog::getTime();
//    ILog("start sort");
//    for(auto& filename : stepSplit.getParts()){
//        SortFile stepSort(filename);
//        stepSort.sort();
//    }
//    ILog("finish sort (" + to_string(ILog::getTime() - tm) + " sec)");

    tm = ILog::getTime();
    ILog("start merge");
    MergeFile stepMerge(stepSplit.getParts());
    stepMerge.merge(m_outputFilename);
    ILog("finish merge (" + to_string(ILog::getTime() - tm) + " sec)");

    std::cout << ("End (" + to_string(ILog::getTime() - tmBegin) + " sec)");
}
