#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAXCHAR = 256;

struct Profile {
    char name[MAXCHAR];
    int age;
    char favColor[MAXCHAR];
    char funFact[MAXCHAR];
};

void openFile(ifstream& inFile);
void openFile(ofstream& outFile);
void getUserInfo(Profile& p, ifstream& inFile);
void generateAboutMeWebPage(ofstream& outFile, Profile p);
        
int main() {
Profile p;


    // Load data from file
    ifstream petFile;
    char inFilename[MAXCHAR] = "cats_vs_dogs.csv";
    openFile(petFile, inFilename);
    
    // get data from file
    getUserInfo(p);

    ofstream outFile;
    openFile(outFile);

    generateAboutMeWebPage(outFile, p);

    outFile.close();
    cout << "Your HTML file has been created! Open 'AboutOurClass.html' in a browser to see it." << endl;
    return 0;
}

// Get user input for the users name, age, favorite color, and a fun fact.
// Modify to use a struct for a "profile"
void getUserInfo(Profile p, ifstream& inFile){



}


void openFile(ifstream& inFile){
  inFile.open("");
  if(!inFile.is_open()){
    cout << "Could not open " << filename << "for reading, exiting..." << endl;
    exit(1);
  }
}


void openFile(ofstream& outFile){
    outFile.open("AboutOurClass.html");
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing." << endl;
        exit(1);
    }
}

// Modify to use a struct for a "profile"
void generateAboutMeWebPage(ofstream& outFile, Profile p){
    
    outFile << "<!DOCTYPE html>\n";
    outFile << "<html>\n";
    outFile << "    <head>\n";
    outFile << "        <title>About Our 161B Class</title>\n";
    outFile << "    </head>\n";
    outFile << "    <body>\n";
    
    // read the csv file into an array of Profile structs

    outFile << "    <div style=\"background-color: " << p.favColor << ";\">\n";
    outFile << "        <h1>Hello! My name is " << p.name << ".</h1>\n";
    outFile << "        <p>" << p.age << "</p>\n";
    outFile << "        <p><b>Fun fact:</b> " << p.funFact << "</p>\n"  ;
    outFile << "    </div>\n";
    
    
    outFile << "    </body>\n";
    outFile << "</html>\n";
}




