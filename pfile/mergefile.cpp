#include "mergefile.h"
#include "exceptfile.h"
#include "fileline.h"
#include <map>
#include <queue>

using namespace std;

MergeFile::MergeFile(const vector<string>& parts) : m_ready(true)
{
    m_files.resize(parts.size());
    for(size_t i = 0; i<parts.size(); i++){
        m_files[i].open(parts[i]);
        if(!m_files[i].is_open()){
            throw ExceptFile(ExceptFile::Step::SORT_PARTS, "File '" + parts[i] + "' not found");
        }
    }
}

MergeFile::~MergeFile()
{
    for(auto& f : m_files){
        f.close();
    }
}

bool MergeFile::merge(std::string filename)
{
    multimap<FileLine, int> heapLines;

    for(size_t i = 0; i< m_files.size(); i++){
        auto opt = getNextLine(i);
        if(!opt->empty()) {
            FileLine line(opt.value());
            heapLines.insert(make_pair(line, i));
        }
    }

    ofstream outFile(filename);
    while(!heapLines.empty()){
        auto indexFile = begin(heapLines)->second;
        auto line = begin(heapLines)->first;
        outFile << line.toLine() << "\n";
        heapLines.erase(begin(heapLines));
        auto opt = getNextLine(indexFile);
        if(!opt->empty()){
            line.fromLine(opt.value());
            heapLines.insert(make_pair(move(line), indexFile));
        }
    }
    outFile.close();
    return true;

}

bool MergeFile::ready() const
{
    return m_ready;
}

std::optional<string> MergeFile::getNextLine(size_t indexFile)
{
    string buffer;
    getline(m_files[indexFile], buffer, '\n');
    if(m_files[indexFile].eof()) return {};
    return { move(buffer) };
}
