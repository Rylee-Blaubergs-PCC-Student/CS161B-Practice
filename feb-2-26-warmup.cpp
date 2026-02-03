#include <iostream>
#include <iomanip>

using namespace std;

// function prototypes
bool setContains(const int set[], const int size, int searchNum);
bool setAddItem(int set[], int& size, int newNum);

// declare const
const int setConst[20] = {1, 2, 3};

// a set is a list of objects in no paticular order, but there cannot be any duplicates

int main() {

int set[6] = {1, 2, 3};
int size = 6;

cout << "setContains when it is true: " << setContains(setConst, 3, 2) << endl;
cout << "setContains when it is false: " << setContains(setConst, 3, 4) << endl << endl;


//what current set looks like
for (int i = 0; i < size; i++) {
 cout << set[i] << endl;  
}

cout << "add items true: " << setAddItem(set, size, 4) << endl;
cout << "add items false: " << setAddItem(set, size, 2) << endl;

//what current set looks like
for (int i = 0; i < size; i++) {
 cout << set[i] << endl;  
}

return 0;
}

bool setContains(const int set[], const int size, int searchNum) {
    // iterate through set
    for (int i = 0; i < size; i++) {
        // check if current iteration is our search number
     if (set[i] == searchNum) {
      return true;   
     }  
    }
    // if not then return false
    return false;
}

bool setAddItem(int set[], int& size, int newNum) {
    int count = 0;
    while (set[count] != 0) {
        //check if you're trying to enter the same number twice
        if (set[count] == newNum) {
        cout << "you can't have the same number twice." << endl;
        return false;   
        }
    count++;
    }
    if (count > size) {
        cout << "you are over capacity" << endl;
        return false;    
    } else if (count < size) {
        cout << "count is: " << count << endl;
        // set the count index to our newNum
        set[count] = newNum;
        return true;
    }
}
