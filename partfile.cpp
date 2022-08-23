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
    multimap<string, string> queueData;
    file.open(m_filename, ios::in);
    for(string buffer; getline(file, buffer, '\n');){
        auto separator = buffer.find(':');
        queueData.insert(make_pair(buffer.substr(0, separator), buffer.substr(separator + 1)));
    }
    file.close();
    file.open(m_filename, ios::out);
    for(auto& [key, value] : queueData){
        file << key << ":" << value << "\n";
    }
    file.close();

}
