
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

const vector<string> &split(const char &delimiter, const string &originalString)
{
    vector<string> *result = new vector<string>();
    string currentString = originalString;
    char currentDelimiter = delimiter;
    auto pos = 0;
    do
    {
        pos = currentString.find(currentDelimiter);
        result->push_back(currentString.substr(0, pos));
        currentString.erase(0, pos + 1);
    } while (currentString.length() > 0 && pos != string::npos);

    return *result;
}

int main(int argc, const char **argv)
{
    int endingFloor = 0;
    if (argc < 2)
    {
        cerr << ("You must provided a file to have this program working.") << endl;
        return -1;
    }
    string fileName = (string)argv[1];
    string fileLineContent;
    vector<int> *totalPresentGiftWrap = new vector<int>();
    vector<int> *totalPresentGiftRibbon = new vector<int>();
    int frontPaper;
    int sidePaper;
    int topPaper;
    int smallestSizePaper;
    int giftRibbon = 0;
    ifstream currentFileInput;
    currentFileInput.open(fileName);
    if (currentFileInput.is_open())
    {
        while (getline(currentFileInput, fileLineContent))
        {
            vector<string> lineInfo = split('x', fileLineContent);
            frontPaper = stoi(lineInfo.at(0)) * stoi(lineInfo.at(1));
            if (stoi(lineInfo.at(0)) + stoi(lineInfo.at(1)) <= (stoi(lineInfo.at(0)) + stoi(lineInfo.at(2))) &&
                stoi(lineInfo.at(0)) + stoi(lineInfo.at(1)) <= (stoi(lineInfo.at(1)) + stoi(lineInfo.at(2))))
            {
                giftRibbon = stoi(lineInfo.at(0)) + stoi(lineInfo.at(1));
            }
            else if (stoi(lineInfo.at(1)) + stoi(lineInfo.at(2)) <= (stoi(lineInfo.at(0)) + stoi(lineInfo.at(2))) &&
                     stoi(lineInfo.at(1)) + stoi(lineInfo.at(2)) <= (stoi(lineInfo.at(1)) + stoi(lineInfo.at(0))))
            {
                giftRibbon = stoi(lineInfo.at(1)) + stoi(lineInfo.at(2));
            }
            else
            {
                giftRibbon = stoi(lineInfo.at(0)) + stoi(lineInfo.at(2));
            }
            totalPresentGiftRibbon->push_back((2 * (giftRibbon)) + (stoi(lineInfo.at(0)) * stoi(lineInfo.at(1)) * stoi(lineInfo.at(2))));
            sidePaper = stoi(lineInfo.at(1)) * stoi(lineInfo.at(2));
            topPaper = stoi(lineInfo.at(2)) * stoi(lineInfo.at(0));
            if (frontPaper <= sidePaper && frontPaper <= topPaper)
            {
                smallestSizePaper = frontPaper;
            }
            else if (sidePaper <= frontPaper && sidePaper <= topPaper)
            {
                smallestSizePaper = sidePaper;
            }
            else
            {
                smallestSizePaper = topPaper;
            }
            totalPresentGiftWrap->push_back(2 * frontPaper + 2 * sidePaper + 2 * topPaper + smallestSizePaper);
        }

        cout << std::accumulate(totalPresentGiftWrap->begin(), totalPresentGiftWrap->end(), 0) << " square feet of wrapping paper in total" << endl;
        cout << std::accumulate(totalPresentGiftRibbon->begin(), totalPresentGiftRibbon->end(), 0) << " feet of ribbon" << endl;
        // printf("You have stopped at floor %i",endingFloor);
    }
    else
    {
        cerr << ("You have provided a file with not computable data.") << endl;
        return -1;
    }

    return 0;
}