#include "externalsort.h"
#include "sortfile.h"
using namespace std;

ExternalSort::ExternalSort() : ISorting()
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
    split();

}

std::vector<string> ExternalSort::split()
{
    std::vector<std::string> vecFilenameParts;
    vecFilenameParts.reserve(m_countParts);

    SortFile file(m_inputFilename);
    long inputfileSize = 0L; file.getSize();
    long blockSize = inputfileSize / m_countParts;

    long offset = 0L;
    for (int part = 0; part< m_countParts; ++part){
        string filename = m_inputFilename + ".part" + std::to_string(part);
        long recordedBlockSize = file.writeBlockIntoFile(filename, offset, blockSize);
        offset+=recordedBlockSize;
        if(part == m_countParts-1 && offset < inputfileSize){
            file.writeBlockIntoFile(filename, offset, inputfileSize - offset);
        }
        vecFilenameParts.push_back(filename);
    }
    return move(vecFilenameParts);
}


void ExternalSort::merge(std::vector<std::string> &vecFilenameParts)
{

}
