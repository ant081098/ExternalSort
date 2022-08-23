#include "externalsort.h"
#include "sortfile.h"
#include "partfile.h"

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
    auto filenameParts = split();
    merge(filenameParts);

}

std::vector<string> ExternalSort::split()
{
    std::vector<std::string> vecFilenameParts;
    vecFilenameParts.reserve(m_countParts);

    SortFile file(m_inputFilename);

    long inputfileSize = file.getSize();
    long blockSize = inputfileSize / m_countParts;
    long offset = 0L;

    for (int part = 0; part< m_countParts; ++part){
        string filename = m_inputFilename + ".part" + std::to_string(part);
        if(part == m_countParts - 1){
            file.writeBlockIntoFile(filename, offset, inputfileSize - offset, true);
        } else {
            offset += file.writeBlockIntoFile(filename, offset, blockSize) + 1;
        }
        vecFilenameParts.push_back(filename);
    }

    return move(vecFilenameParts);
}


void ExternalSort::merge(std::vector<std::string> &vecFilenameParts)
{
    for(auto& filename : vecFilenameParts){
        //sort(filename);
    }

}

void ExternalSort::sort(std::string filename)
{
    auto block = PartFile(filename);
    block.sorting();
}
