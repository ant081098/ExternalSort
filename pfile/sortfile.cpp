#include "sortfile.h"
#include "exceptfile.h"
#include "fileline.h"

#include <set>
#include <fstream>

#include "../iface/ilog.h"

using namespace std;



SortFile::SortFile(std::string filename) : m_filename(filename)
{
    ILog("\tsort block: " + filename);
}

SortFile::~SortFile()
{

}

void SortFile::sort()
{
    fstream file;
    multiset<FileLine> setLines;
    file.open(m_filename, ios::in);

    if(!file.is_open()) {
        throw ExceptFile(ExceptFile::Step::SORT_PARTS, "File '" + m_filename + "' not found");
    }
    ILog("\t\treading");
    for(string buffer; getline(file, buffer, '\n');){
        FileLine line(buffer);
        setLines.insert(line);
    }
    file.close();

    ILog("\t\twriting");
    file.open(m_filename, ios::out);
    if(!file.is_open()) {
        throw ExceptFile(ExceptFile::Step::SORT_PARTS, "Failed output in '" + m_filename + "'");
    }
    for(auto& line : setLines){
        file << line.toLine() << "\n";
    }
    file.close();
}
