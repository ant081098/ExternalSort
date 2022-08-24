#include "partfile.h"

#include <queue>
#include <map>
#include <fstream>

using namespace std;

PartFile::PartFile(std::string filename) : m_filename(filename)
{
}

PartFile::~PartFile()
{

}

void PartFile::sorting()
{
    fstream file;
    multimap<string, string> mapData;
    file.open(m_filename, ios::in);
    for(string buffer; getline(file, buffer, '\n');){
        auto separator = buffer.find(':');
        string key = buffer.substr(0, separator);
        string value = buffer.substr(separator + 1);
        mapData.insert(move(make_pair(move(key), move(value))));
    }
    file.close();
    file.open(m_filename, ios::out);
    for(auto& [key, value] : mapData){
        file << key << ":" << value << "\n";
    }
    file.close();
}
