
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;


class House {
    public: 
        House() {};
        ~House() {};
        void setVisited(bool bVisited) { visited = bVisited; };
        void setPosX(int iPosX) { posX = iPosX;};
        void setPosY(int iPosY) { posY = iPosY;};
        int getPosX() {return posX;};
        int getPosY() {return posY;};
        bool getVisited() {return visited;};
    private:
        bool visited = false;
        int posX = 0;
        int posY = 0;
};
enum Direction {
    LEFT = '<',
    TOP = '^',
    RIGHT = '>',
    BOTTOM = 'v'
};
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
    int housesVisited = 1;

    if (argc < 2)
    {
        cerr << ("You must provided a file to have this program working.") << endl;
        return -1;
    }
    string fileName = (string)argv[1];
    string fileLineContent;
    ifstream currentFileInput;
    vector<string> currentPath;
    vector<House>* currentHouses = new vector<House>();
    currentFileInput.open(fileName);
    House currentHouse = House();
    currentHouse.setPosX(0);
    currentHouse.setPosY(0);
    currentHouse.setVisited(true);
    currentHouses->push_back(currentHouse);
    if (currentFileInput.is_open())
    {
        while (getline(currentFileInput, fileLineContent))
        {
            bool found = false;
           currentPath = split('\n', fileLineContent);
           for (auto direction: currentPath) {
                switch (direction[0])
                {
                case LEFT :
                    {
                        currentHouse = currentHouses->at(currentHouses->size()-1);
                        int currentHousePosX = currentHouse.getPosX();
                        int currentHousePosY = currentHouse.getPosY(); 
                        auto houseIt = currentHouses->begin();
                        for (auto houseIt = currentHouses->begin(); houseIt != currentHouses->end(); houseIt++) {
                            if (houseIt->getPosX() == currentHousePosX-1 && houseIt->getPosY() == currentHousePosY) {
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            House newCurrentHouse = House();
                            newCurrentHouse.setPosX(currentHousePosX-1);
                            newCurrentHouse.setPosY(currentHousePosY);
                            newCurrentHouse.setVisited(true);
                            currentHouses->push_back(newCurrentHouse);
                        }
                        break;
                    }
                case TOP : {
                    currentHouse = currentHouses->at(currentHouses->size()-1);
                        int currentHousePosX = currentHouse.getPosX();
                        int currentHousePosY = currentHouse.getPosY(); 
                        auto houseIt = currentHouses->begin();
                        for (auto houseIt = currentHouses->begin(); houseIt != currentHouses->end(); houseIt++) {
                            if (houseIt->getPosY() == currentHousePosY-1 && houseIt->getPosX() == currentHousePosX) {
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            House newCurrentHouse = House();
                            newCurrentHouse.setPosX(currentHousePosX);
                            newCurrentHouse.setPosY(currentHousePosY-1);
                            newCurrentHouse.setVisited(true);
                            currentHouses->push_back(newCurrentHouse);
                        }
                        break;
                }
                case BOTTOM : {
                    currentHouse = currentHouses->at(currentHouses->size()-1);
                        int currentHousePosX = currentHouse.getPosX();
                        int currentHousePosY = currentHouse.getPosY(); 
                        auto houseIt = currentHouses->begin();
                        for (auto houseIt = currentHouses->begin(); houseIt != currentHouses->end(); houseIt++) {
                            if (houseIt->getPosX() == currentHousePosX+1 && houseIt->getPosY() == currentHousePosY) {
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            House newCurrentHouse = House();
                            newCurrentHouse.setPosX(currentHousePosX+1);
                            newCurrentHouse.setPosY(currentHousePosY);
                            newCurrentHouse.setVisited(true);
                            currentHouses->push_back(newCurrentHouse);
                        }
                        break;
                }
                case RIGHT : {
                    currentHouse = currentHouses->at(currentHouses->size()-1);
                        int currentHousePosX = currentHouse.getPosX();
                        int currentHousePosY = currentHouse.getPosY(); 
                        auto houseIt = currentHouses->begin();
                        for (auto houseIt = currentHouses->begin(); houseIt != currentHouses->end(); houseIt++) {
                            if (houseIt->getPosY() == currentHousePosY+1 && houseIt->getPosX() == currentHousePosX) {
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            House newCurrentHouse = House();
                            newCurrentHouse.setPosX(currentHousePosX);
                            newCurrentHouse.setPosY(currentHousePosY+1);
                            newCurrentHouse.setVisited(true);
                            currentHouses->push_back(newCurrentHouse);
                        }
                        break;
                }
                default:
                    break;
                }
           }
        }

        cout << currentHouses->size() << " houses visited" << endl;
        //cout << std::accumulate(totalPresentGiftRibbon->begin(), totalPresentGiftRibbon->end(), 0) << " feet of ribbon" << endl;
        // printf("You have stopped at floor %i",endingFloor);
    }
    else
    {
        cerr << ("You have provided a file with not computable data.") << endl;
        return -1;
    }

    return 0;
}