#include "externalsort.h"

using namespace std;

ExternalSort::ExternalSort() : ISorting()
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
    split();

}

void ExternalSort::split()
{

}
