#include "externalsort.h"
#include "pfile/splitfile.h"
#include "pfile/mergefile.h"

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
    m_inputFilename = options->param("-i"); //input file
    m_countParts = stoi(options->param("-d"));  //count parts file
    m_outputFilename = options->param("-o");    //output file
    ILog("Sorting options:\n\tInput file: "+ m_inputFilename
         + "\n\tOutput file: " + m_outputFilename
         + "\n\tCount Parts: " + to_string(m_countParts) + "\n");
}

void ExternalSort::run()
{

    ILog("Start split");
    SplitFile stepSplit(m_inputFilename);
    stepSplit.split(m_countParts);

    ILog("Start merge");
    MergeFile stepMerge(stepSplit.getParts());
    stepMerge.merge(m_outputFilename);
    ILog("Finish sorting!");
}
