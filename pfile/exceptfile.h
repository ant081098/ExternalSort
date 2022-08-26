#pragma once

#include <exception>
#include <string>

struct ExceptFile : public std::exception
{
    enum Step {
        SPLIT,
        SORT_PARTS,
        MERGE
    };

    ExceptFile(Step step, std::string message);
    std::string step() const;
    std::string message() const;

private:
    Step m_step;
    std::string m_message;
};

