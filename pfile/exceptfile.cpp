#include "exceptfile.h"

ExceptFile::ExceptFile(Step step, const std::string& message) : m_step(step), m_message(message)
{

}

std::string ExceptFile::step() const
{
    switch (m_step) {
    case Step::SPLIT: return "{SPLIT}";
    case Step::SORT_PARTS: return "{SORT PARTS}";
    case Step::MERGE: return "{MERGE}";
    case Step::READ_FILE: return "{READ_FILE}";
    default: return "{UNKNOW}";
    }
}

std::string ExceptFile::message() const
{
    return m_message;
}

