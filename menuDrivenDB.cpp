#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// globals
const int MAXCHAR = 64;
const int MAXPETS = 32;

// structs
struct Pet {
  char name[MAXCHAR];
  char species[MAXCHAR];
  int age;
};

struct PetDB { // DB stands for database
  Pet pets[MAXPETS];
  int size = 0;
};

// prototypes
void printDB(const PetDB& db);
void addPet(PetDB& db);
void removeEntry(PetDB& db, int position);
void delPet(PetDB& db);
PetDB loadPetsFile(ifstream& f);
PetDB initDatabase();
void mainMenuLoop(PetDB& db);
void writeFile(const PetDB& db);

// Check out this small main function that primarily just calls
// other functions
int main(){
  PetDB db = initDatabase();
  mainMenuLoop(db);
  writeFile(db);
  return 0;
}


void printDB(const PetDB& db){
  // Print out each pet in the database as follows:
  // [<num>] <name> is a <species> and is <age> years old
  // [1] vim is a cat and is 3 years old
  // [2] Mr. Glubbs is a goldfish and is 1 years old
  // Include a number for each pet so the user can delete a particular entry
  for(int i = 0; i < db.size + 1; i++) {
    cout << "[" << i << "]" << " " << db.pets[i].name << " is a " << db.pets[i].species << " and is " << db.pets[i].age << " years old" << endl;
  }
}


void addPet(PetDB& db){
  // Create a new Pet struct, and prompt the user to enter the pets
  // name, species and age.
  // Then, add that pet to the database
}


void removeEntry(PetDB& db, int position){
  // you know what to do 
}


void delPet(PetDB& db){
  cout << "Which pet would you like to remove? (Enter the number associated with each pet)" << endl;
  int entryToDelete;
  cin >> entryToDelete;
  cin.ignore(999, '\n');
  removeEntry(db, entryToDelete);
}


PetDB loadPetsFile(ifstream& f){
  // Create a PetDB struct
  PetDB db; 
  // Read each line of data from the pet spreadsheet csv file, loading it 
  // into a Pet struct. Add that Pet struct to the PetDB
  f.ignore(9999, '\n'); // ignore header line
  while(!f.eof() && db.size < MAXPETS - 1 ){
    Pet p;
    f.getline(p.name, 256, ',');
    f.getline(p.species, 256, ',');
    f >> p.age;
    f.ignore(256, '\n');
    
    // debug text
    // cout << "[" << db.size << "]" << " " << db.pets[db.size].name << " is a " << db.pets[db.size].species << " and is " << db.pets[db.size].age << " years old" << endl;
    strcpy(db.pets[db.size].name, p.name);
    strcpy(db.pets[db.size].species, p.species);
    db.pets[db.size].age = p.age;

    
    db.size++;
  }
  db.size--;

  return db;

}


PetDB initDatabase(){
  ifstream inFile;
  inFile.open("petSpreadsheet.csv");
  if(!inFile.is_open()){
    cerr << "Error: could not open petSpreadsheet.csv, exiting..." << endl;
    exit(1);
  }
  
  PetDB db = loadPetsFile(inFile);
  inFile.close();
  return db;
}


void mainMenuLoop(PetDB& db){
  int option;
  do {
    cout << endl;
    cout << "Welcome to our pets database!" << endl;
    cout << "Choose a menu option: " << endl;
    cout << "1: Add a pet" << endl;
    cout << "2: Delete a pet" << endl;
    cout << "3: See all known pets" << endl;
    cout << "0: Quit and write out the data" << endl;
    cout << endl;
    cin >> option;
    cin.ignore(999, '\n');
    switch(option){
    case 1:
      addPet(db);
      break;
    case 2:
      delPet(db);
      break;
    case 3:
      printDB(db);
      break;
    }
    
  }while(option != 0);
}


void writeFile(const PetDB& db){
  cout << "Writing to disk, do not close this program..." << endl;

  // open petSpreadsheet.csv and overwrite it with the current
  // contents of the pet database. Make sure to include the header, and 
  // follow proper csv formatting, and to close the file. 

  cout << "File written. Goodbye." << endl;
}


