#include "mergefile.h"
#include "exceptfile.h"
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
    multimap<pair<string, string>, int> heap;

    for(size_t i = 0; i< m_files.size(); i++){
        string buffer;
        getline(m_files[i], buffer, '\n');
        if(m_files[i].eof()) continue;
        auto separator = buffer.find(':');
        string key = buffer.substr(0, separator);
        string value = buffer.substr(separator + 1);
        auto pair = make_pair(key, value);
        heap.insert(make_pair(pair, i));
    }

    ofstream outFile(filename);
    while(!heap.empty()){
        auto indexFile = begin(heap)->second;
        auto line = begin(heap)->first.first + ":" + begin(heap)->first.second + "\n";
        outFile << line;
        heap.erase(begin(heap));
        string buffer;
        getline(m_files[indexFile], buffer, '\n');
        if(m_files[indexFile].eof()) continue;
        auto separator = buffer.find(':');
        string key = buffer.substr(0, separator);
        string value = buffer.substr(separator + 1);
        auto pair = make_pair(key, value);
        heap.insert(make_pair(pair, indexFile));
    }
    outFile.close();
    return true;

}

bool MergeFile::ready() const
{
    return m_ready;
}
