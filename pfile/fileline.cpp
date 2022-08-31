#include "fileline.h"
#include "exceptfile.h"

#include <charconv>
#include <string_view>

using namespace std;

FileLine::FileLine(const string &line) : m_key(0L), m_value("")
{
    fromLine(line);
}

FileLine::~FileLine()
{

}

void FileLine::fromLine(const std::string_view &line)
{
    auto separator = line.find(':');
    if(separator == string::npos) { //if not found symbol ':'
        throw ExceptFile(ExceptFile::Step::READ_FILE, "Invalid format file");
    }

    //parse and convert key from string
    auto [ptr, ec] = from_chars(line.data(), line.data() + separator, m_key);
    if(!(ec == errc{} && ptr == line.data() + separator)){
        throw ExceptFile(ExceptFile::Step::READ_FILE, "Invalid format key in file");
    }
    //m_key = stoull(string{line.substr(0, separator)});
    m_value = line.substr(separator + 1); //parse value
}

string FileLine::toLine() const
{
    return to_string(m_key) + ":" + m_value;
}

string FileLine::value() const
{
    return m_value;
}

unsigned long long FileLine::key() const
{
    return m_key;
}

bool FileLine::operator<(const FileLine &line) const //compare for sorting
{
    return m_key < line.key();
}
