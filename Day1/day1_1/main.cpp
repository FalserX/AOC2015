
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char** argv) {
    int endingFloor = 0;
    if (argc < 2) {
        cerr << ("You must provided a file to have this program working.") << endl;
        return -1;
    }

    string fileName = (string)argv[1];    
    ifstream currentFileInput;
    currentFileInput.open(fileName);
    if (currentFileInput.is_open()) {

        string fileContent;
        currentFileInput >> fileContent;
        currentFileInput.close();

        if (fileContent.find_last_of('\n') > -1) {
            fileContent.pop_back();
        } else if (fileContent.find_last_of('\r\n') > -1) {
            fileContent.substr(0, fileContent.find_last_of('\r\n'));
        }
        int fileContentPos = 0;
        while (fileContent[fileContentPos] != '\0') {
            if (fileContent[fileContentPos] == '(') {
                endingFloor++;
            } else if (fileContent[fileContentPos] == ')') {
                endingFloor--;
            }
            fileContentPos++;
        }
        
        printf("You have stopped at floor %i",endingFloor);
    } else {
        cerr << ("You have provided an unknown file.") << endl;
        return -1;
    }

    return 0;
}