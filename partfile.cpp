#include "partfile.h"

#include <queue>
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
    priority_queue<pair<string, string>> queueData;

    file.open(m_filename, ios::in);
    for(string buffer; getline(file, buffer, '\n');){
        auto separator = buffer.find(':');
        queueData.push(make_pair(buffer.substr(0, separator), buffer.substr(separator + 1)));
    }
    file.close();



}
