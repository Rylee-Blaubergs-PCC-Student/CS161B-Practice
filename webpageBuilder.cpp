#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAXCHAR = 256;

// Create a "profile" struct here

void openFile(ofstream& outFile);
void getUserInfo(char name[], int& age, char favColor[], char funFact[]);
void generateAboutMeWebPage(ofstream& outFile, char name[], int age, char favColor[], char funFact[]);
        
int main() {
    char name[MAXCHAR];
    int age;
    char favColor[MAXCHAR];
    char funFact[MAXCHAR];
    
    getUserInfo(name, age, favColor, funFact);

    ofstream outFile;
    openFile(outFile);

    generateAboutMeWebPage(outFile, name, age, favColor, funFact);

    outFile.close();
    cout << "Your HTML file has been created! Open 'AboutOurClass.html' in a browser to see it." << endl;
    return 0;
}

// Get user input for the users name, age, favorite color, and a fun fact.
// Modify to use a struct for a "profile"
void getUserInfo(char name[], int& age, char favColor[], char funFact[]){
    cout << "What's your name?: ";
    cin.getline(name, 100);

    cout << "What's your age?: ";
    cin >> age;
    cin.ignore(99999, '\n');

    cout << "What's your favorite color?: ";
    cin.getline(favColor, 100);

    cout << "What's fun fact about yourself?: ";
    cin.getline(funFact, 100);

}


void openFile(ofstream& outFile){
    outFile.open("AboutOurClass.html");
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing." << endl;
        exit(1);
    }
}

// Modify to use a struct for a "profile"
void generateAboutMeWebPage(ofstream& outFile, char name[], int age, char favColor[], char funFact[]){
    
    outFile << "<!DOCTYPE html>\n";
    outFile << "<html>\n";
    outFile << "    <head>\n";
    outFile << "        <title>About Our 161B Class</title>\n";
    outFile << "    </head>\n";
    outFile << "    <body>\n";
    
    outFile << "    <div style=\"background-color: " << favColor << ";\">\n";
    outFile << "        <h1>Hello! My name is " << name << ".</h1>\n";
    outFile << "        <p>" << age << "</p>\n";
    outFile << "        <p><b>Fun fact:</b> " << funFact << "</p>\n"  ;
    outFile << "    </div>\n";
    
    
    
    outFile << "    </body>\n";
    outFile << "</html>\n";
}




