#include "sortfile.h"
#include "exceptfile.h"
#include <queue>
#include <map>
#include <fstream>

using namespace std;

SortFile::SortFile(std::string filename) : m_filename(filename)
{

}

SortFile::~SortFile()
{

}

void SortFile::sort()
{
    fstream file;
    multimap<string, string> mapData;
    file.open(m_filename, ios::in);

    if(!file.is_open()) {
        throw ExceptFile(ExceptFile::Step::SORT_PARTS, "File '" + m_filename + "' not found");
    }

    for(string buffer; getline(file, buffer, '\n');){
        auto separator = buffer.find(':');
        string key = buffer.substr(0, separator);
        string value = buffer.substr(separator + 1);
        mapData.insert(move(make_pair(move(key), move(value))));
    }
    file.close();

    file.open(m_filename, ios::out);
    if(!file.is_open()) {
        throw ExceptFile(ExceptFile::Step::SORT_PARTS, "Failed output in '" + m_filename + "'");
    }
    for(auto& [key, value] : mapData){
        file << key << ":" << value << "\n";
    }
    file.close();
}
