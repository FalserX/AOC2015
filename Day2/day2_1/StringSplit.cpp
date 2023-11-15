#include "StringSplit.h"

StringSplit::StringSplit()
{
    stringSplitted = new std::vector<std::string>();
}

StringSplit::~StringSplit()
{
    delete stringSplitted;
}

const std::vector<std::string> &StringSplit::split(std::string &original_string, char delimiter)
{
    currentString = original_string;

    while (currentString != "\0" || currentString != "")
    {
        stringSplitted->push_back(currentString.substr(0, currentString.find_first_of(delimiter)));
        currentString = currentString.substr(currentString.find_first_of(delimiter) + 1);
    }

    return *stringSplitted;
}
