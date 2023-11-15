#ifndef STRINGSPLIT_H
#define STRINGSPLIT_H
#include <vector>
#include <string>
class StringSplit
{
public:
    StringSplit();
    ~StringSplit();
    const std::vector<std::string> &split(std::string &original_string, char delimiter);

private:
    std::vector<std::string> *stringSplitted;
    std::string currentString;
};
#endif