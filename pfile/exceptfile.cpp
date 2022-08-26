#include "exceptfile.h"

ExceptFile::ExceptFile(Step step, std::string message) : m_step(step), m_message(message)
{

}

std::string ExceptFile::step() const
{
    switch (m_step) {
    case Step::SPLIT: return "{SPLIT}";
    case Step::SORT_PARTS: return "{SORT PARTS}";
    case Step::MERGE: return "{MERGE}";
    default: return "{UNKNOW}";
    }
}

std::string ExceptFile::message() const
{
    return m_message;
}

