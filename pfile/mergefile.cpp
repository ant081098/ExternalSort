#include "mergefile.h"
#include "exceptfile.h"
#include "fileline.h"
#include <set>

using namespace std;

MergeFile::MergeFile(const vector<string>& parts)
{
    m_files.resize(parts.size());
    for(size_t i = 0; i<parts.size(); i++){
        m_files[i].open(parts[i]);  //open all parts of file
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

bool MergeFile::merge(const std::string& filename)
{
    multiset<pair<FileLine, int>> heapLines; //autosorting when inserting [Line, IndexFile]

    for(size_t i = 0; i< m_files.size(); i++){
        auto opt = getNextLine(i);  //get next line from file by index
        if(!opt->empty()) {
            FileLine line(opt.value());
            heapLines.insert({move(line), i}); //append line in map
        }
    }

    ofstream outFile(filename);
    while(!heapLines.empty()){
        auto indexFile = begin(heapLines)->second;  //get minimal key
        auto line = begin(heapLines)->first;    //get minimal pair value
        outFile << line.toLine() << "\n"; //write in output file
        heapLines.erase(begin(heapLines));  //Remove recorded line
        if(auto opt = getNextLine(indexFile); !opt->empty()){ //get a new line from the same file
            line.fromLine(opt.value());
            heapLines.insert({move(line), indexFile}); //append line in map
        }
    }
    outFile.close();
    return true;

}

std::optional<string> MergeFile::getNextLine(size_t indexFile)
{
    string buffer;
    getline(m_files[indexFile], buffer, '\n');  //get next line
    if(m_files[indexFile].eof()) return {};
    return { move(buffer) };
}
