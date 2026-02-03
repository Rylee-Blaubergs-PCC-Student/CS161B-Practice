/*This is the starter file for Midterm Practice 2.
You will write a function name keepUnique that accepts an array of integers
numbers and it's length as parameters and removes multiple occurences of an element
in the array and returns the count of unique values that occur in the array.
An element is "removed" by shifting all subsequent elements one index to the left 
to cover it up, placing a 0 into the last index.  
The original ordering of number's elements should be retained or remain the same.
Please see examples in the midterm practice 2 document.*/

#include <iostream>

using namespace std;

void keepUnique(int numbers[], int count);

int main()
{
	int numbers[] = {7, 7, 2, 2, 1, 2, 2, 7};
    keepUnique(numbers, 8);

	for(int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
	return 0;
}
