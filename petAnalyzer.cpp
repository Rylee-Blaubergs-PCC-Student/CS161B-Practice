#include <iostream>
#include <fstream>
using namespace std;

struct PetData {
    int count;
    char states[][MAXCHAR];
    double householdsWithPets[];
    double dogOwners[];
    double meanDogs[];
    double catOwners[];
    double meanCats[]
}

const int MAXCHAR = 128;
const int MAXDATA = 256;

void openFile(ifstream& inFile, char filename[]);
void openFile(ofstream& statsFile, char filename[]);
void loadPetData(ifstream& inFile, PetData& pd);
void generatePetStats(ofstream& statsFile, PetData& pd);
void printData(const PetData& pd);



int main(){

  return 0;
}


// Open the file. If failed, print "Could not open <filename> for reading, exiting..."
void openFile(ifstream& inFile, char filename[]){
  
}


// Open the file. If failed, print "Could not open <filename> for reading, writing..."
void openFile(ofstream& statsFile, char filename[]){
  
}


// Read each line of data, storing a line's contents into the PetData.
// Make sure to skip reading the header line of the file
void loadPetData(ifstream& inFile, PetData& pd){


}


// Calculate something interesting about the data, and store this information into a file.
// eg: the state with the highest dog ownership, average pet ownership,
// biggest difference between dog and cat ownership, etc.
void generatePetStats(ofstream& statsFile, PetData& pd){

}


// For debugging
void printData(const PetData& pd){
  
  for (int i=0; i<pd.count; i++){
    cout << pd.states[i] << endl;
    cout << "Percent households with pets: \t\t" << pd.householdsWithPets[i] << endl;
    cout << "Percent dog owners:\t\t\t" << pd.dogOwners[i] << endl;
    cout << "Mean number of dogs per household:\t" << pd.meanDogs[i] << endl;
    cout << "Percent cat owners:\t\t\t" << pd.catOwners[i] << endl;
    cout << "Mean number of cats per household:\t" << pd.meanCats[i] << endl;
    cout << endl << "-------------------------------------" << endl;
  }
}


