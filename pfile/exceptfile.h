#pragma once

#include <exception>
#include <string>

//Exception File
struct ExceptFile : public std::exception
{
    //Type of exception
    enum Step {
        SPLIT,
        SORT_PARTS,
        MERGE,
        READ_FILE
    };

    ExceptFile(Step step, const std::string& message);
    std::string step() const;
    std::string message() const;

private:
    Step m_step;
    std::string m_message;
};

