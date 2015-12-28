// intro_to_arrays_in_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void printSingleDimensionalArrayToCout(int intArray[], int arraySize, char * arrayName);
void printSingleDimensionalArrayToCoutAsSingleLine(int * intArray, int arraySize, char * arrayName);
void print1dArrayInfo(int array1d[], int numElements);
void print2dArrayInfo(int array2d[][2], int numElementsInFirstDimension);
void print2dArrayInfo_2(int * array2d[3], int numElementsInFirstDimension);
int * get1dArray();
int ** get2dArray(unsigned int numElementsIn2ndDimension);
void initializeArrayDemo();
void accessingArrayDemo();
void charArrayDemo();
void multidimensionalArrayDemo();
void arraysAsFunctionParametersDemo();
void returnArrayFromFunctionsDemo();
void cstringArrayDemo();
void doWaitForInput(char * message);

char * ARRAY_3_NAME = "array3";
char * ARRAY_7_NAME = "array7";
char * ARRAY_5_NAME = "array5";

int main()
{
	int myArr[5];
	for (int i : myArr)
	{
		cout << i << " ";
	}
	char optionSelected = '0';

	while (optionSelected != 'q' && optionSelected != 'Q')
	{
		cout << "Select a demo (q to exit)." << endl;
		cout << "\t1: Initialize single dimensional arrays" << endl
			<< "\t2: Accessing array data" << endl
			<< "\t3: Multidimensional arrays" << endl
			<< "\t4: Arrays as function parameters" << endl
			<< "\t5: Returning arrays from functions" << endl
			<< "\t6: Using ranges to iterate arrays" << endl
			<< "\t7: Character strings as arrays" << endl;
		cin >> optionSelected; 
		switch (optionSelected)
		{
		case '1':
			// DEMO 1: INITIALIZATION OF SINGLE DIMENSIONAL ARRAYS //
			initializeArrayDemo();
			break;
		case '2':
			// DEMO 2: ACCESSING ARRAY DATA // bracket, byte sums
			accessingArrayDemo();
			break;
		case '3':
			// DEMO 3: INITIALIZING MULTI-DIMENSIONAL ARRAYS //
			multidimensionalArrayDemo();
			break;
		case '4':
			arraysAsFunctionParametersDemo();
			break;
		case '5':
			// DEMO 5: RETURN ARRAYS FROM FUNCTIONS //
			returnArrayFromFunctionsDemo();
			break;
		case '6':
			// DEMO 5: USING RANGE for TO ITERATE ARRAYS //
			cout << "NOT IMPLEMENTED!" << endl;
			break;
		case '7':
			// DEMO 7: C_STRING AS ARRAY //
			cstringArrayDemo();
			break;
		default:
			cout << "Invalid option selected.  Try again." << endl;
		}

		// DEMO 3: PASSING ARRAYS TO FUNCTIONS // *, &

		// DEMO 4: INITIALIZING MULTI-DIMENSIONAL ARRAYS // size =2, 5

		// DEMO 5: OTHER ARRAY TYPES (CHAR ARRAY & STRING)

		// DEMO 5: ACCESSING ARRAYS OUT OF BOUNDS //
	}

    return 0;
}

void doWaitForInput(char * message)
{
	char resp;
	cout << message;
	cin >> resp;
}

void printSingleDimensionalArrayToCout(int * intArray, int arraySize, char * arrayName)
{
	int arrayLength = sizeof(intArray) / sizeof(*intArray);
	cout << "Array information for :" << arrayName << endl;
	cout << "Array size: " << sizeof(intArray) << endl;
	cout << "Array* size: " << sizeof(*intArray) << endl;
	
	for (int i = 0; i < arraySize; ++i)
	{
		cout << arrayName << "[" << i << "]: " << intArray[i] << endl;
	}
}

void printSingleDimensionalArrayToCoutAsSingleLine(int * intArray, int arraySize, char * arrayName)
{
	cout << arrayName << " values: {";
	for (int i = 0; i < arraySize; ++i)
	{
		cout << intArray[i];
		if (i < arraySize - 1) cout << ", ";
	}
	cout << "}" << endl;
}

void print1dArrayInfo(int array1d[], int numElements)
{
	cout << "INSIDE OF print1dArrayInfo().  Info of array1d[]:" << endl;
	cout << "\tsizeof(array1d): " << sizeof(array1d) << endl;
	cout << "\tarray1d elements: { ";
	for (int i = 0; i < numElements; ++i)
	{
		cout << array1d[i];
		if (i != (numElements - 1)) cout << ", ";
		else cout << " }" << endl;
	}
	cout << endl;
}

void print2dArrayInfo(int array2d[][2], int numElementsInFirstDimension)
{
	cout << "INSIDE OF print2dArrayInfo().  Info of array2d[][2]:" << endl;
	cout << "\tsizeof(array2d): " << sizeof(array2d) << endl;
	cout << "\tsizeof(*array2d): " << sizeof(*array2d) << endl;
	cout << "\tarray2d elements: { ";
	for (int i = 0; i < numElementsInFirstDimension; ++i)
	{
		cout << "{ ";
		for (int j = 0; j < 2; ++j)
		{
			cout << array2d[i][j];
			if (j < 1) cout << ", ";
			else cout << " }";
		}
		if (i != (numElementsInFirstDimension - 1)) cout << ", ";
		else cout << " }" << endl;
	}
	cout << endl;
}

void print2dArrayInfo_2(int * array2d[3], int numElementsInFirstDimension)
{
	cout << "INSIDE OF print2dArrayInfo_2().  Info of array2d[][2]:" << endl;
	cout << "\tsizeof(array2d): " << sizeof(array2d) << endl;
	cout << "\tsizeof(*array2d): " << sizeof(*array2d) << endl;
	cout << "\tarray2d elements: { ";
	for (int i = 0; i < numElementsInFirstDimension; ++i)
	{
		cout << "{ ";
		for (int j = 0; j < 3; ++j)
		{
			cout << array2d[i][j];
			if (j < 2) cout << ", ";
			else cout << " }";
		}
		if (i != (numElementsInFirstDimension - 1)) cout << ", ";
		else cout << " }" << endl;
	}
	cout << endl;
}

int * get1dArray()
{
	int * array1d = new int[3];
	for (int i = 0; i < 3; ++i)
	{
		array1d[i] = (i + 1) * 100;
	}

	return array1d;
}

int ** get2dArray(unsigned int numElementsIn2ndDimension)
{
	int ** array2d = new int*[2];
	for (int firstDimension = 0; firstDimension < 2; ++firstDimension)
	{
		array2d[firstDimension] = new int[numElementsIn2ndDimension];
	}

	for (int firstDimension = 0; firstDimension < 2; ++firstDimension)
	{
		for (int secondDimension = 0; secondDimension < numElementsIn2ndDimension; ++secondDimension)
		{
			array2d[firstDimension][secondDimension] = firstDimension + secondDimension;
		}
	}
	return array2d;
}

void initializeArrayDemo()
{
	int array3[3];
	int *array7 = new int[7];
	
	cout << "SIZE OF ARRAYS" << endl;
	cout << "sizeof(array3): " << sizeof(array3) << endl;
	cout << "sizeof(array7): " << sizeof(array7) << endl;

	// Initialization of heapArray1[3] //
	doWaitForInput("Press any key and hit enter to see array3 initial values...");

	cout << ARRAY_3_NAME << " INITIAL VALUES" << endl;
	printSingleDimensionalArrayToCout(array3, 3, ARRAY_3_NAME);
	doWaitForInput("Press any key and hit enter to initialize array3...");

	for (int i = 0; i < 3; ++i)
	{
		array3[i] = 0;
	}
	doWaitForInput("Press any key and hit enter to view initialized array3...");
	printSingleDimensionalArrayToCout(array3, 3, ARRAY_3_NAME);

	// Initialization of heapArray2[7] //
	doWaitForInput("Press any key and hit enter to view array7 initial values...");
	cout << ARRAY_7_NAME << " INITIAL VALUES" << endl;
	printSingleDimensionalArrayToCout(array7, 7, ARRAY_7_NAME);
	doWaitForInput("Press any key and hit enter to initialize array7...");

	for (int i = 0; i < 7; ++i)
	{
		array7[i] = i + 1;
	}
	doWaitForInput("Press any key and hit enter to view initialized array7...");
	printSingleDimensionalArrayToCout(array7, 7, ARRAY_7_NAME);

	// Initialization using explicit values //
	doWaitForInput("Press any key and hit enter to initialize array5...");
	int array5[] = { 5, 10, 15, 20, 25 };
	cout << "Size of " << ARRAY_5_NAME << ": " << sizeof(array5) << endl;;
	
	doWaitForInput("Press any key and hit enter to view initialized array5...");
	printSingleDimensionalArrayToCout(array5, 5, ARRAY_5_NAME);

	cout << endl << "INITIALIZE ARRAYS DEMO COMPLETE" << endl;
}

void accessingArrayDemo()
{
	doWaitForInput("Press any key and hit enter to initialize array3[3] and array7[7]...");

	// Initialize two arrays //
	int array3[] = { 10, 20, 30 };
	int *array7 = new int[7];
	for (int i = 0; i < 7; ++i)
	{
		array7[i] = (i + 1) * 11;
	}

	printSingleDimensionalArrayToCoutAsSingleLine(array3, 3, ARRAY_3_NAME);
	printSingleDimensionalArrayToCoutAsSingleLine(array7, 7, ARRAY_7_NAME);

	doWaitForInput("Press any key and hit enter to access array3[] using an index...");
	cout << "Number of elements in array3[]: 3" << endl << endl;
	int indexToAccess = 0;
	while (true)
	{
		cout << "Enter an index to get the memory location and value of the array element (negative number to continue): ";
		cin >> indexToAccess;
		if (indexToAccess < 0) break;
		try {
			cout << &(array3[indexToAccess]) << " [" << (int)(&(array3[indexToAccess])) << "]: " << array3[indexToAccess] << endl;
		}
		catch (...)
		{
			cout << "Exception while accessing the array with index " << indexToAccess << endl;
			indexToAccess = -1;
		}
	}

	doWaitForInput("Press any key and hit enter to access array3[] using integer addition...");
	int byteOffset = 0;
	cout << "Size of integer: " << sizeof(byteOffset) << "bytes." << endl << endl;
	while (true)
	{
		cout << "Enter an integer to access array3[] using a memory offset: ";
		cin >> byteOffset;
		if (byteOffset < 0) break;
		cout << array3 + byteOffset << " [" << (int)(array3 + byteOffset) << "]: " << *(array3 + byteOffset) << endl;
		cout << &array3 + byteOffset << " [" << (int)(&array3 + byteOffset) << "]: " << *(&array3 + byteOffset) << endl;
	}

	cout << endl << "ACCESSING ARRAYS DEMO COMPLETE" << endl;
}

void multidimensionalArrayDemo()
{
	doWaitForInput("Press any key and hit enter to intiialize a 2-d array array2d[3][4]...");
	cout << "int array2d[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };" << endl;
	int array2d[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	
	doWaitForInput("Press any key and hit enter to view the contents of array2d[3][4] using a loop...");
	cout << "for (int row = 0; row < 3; ++row)" << endl << "{" << endl
		<< "\tfor (int col = 0; col < 4; ++col)" << endl << "\t{" << endl
		<< "\t\tcout << array2d[row][col] << \"\\t\";" << endl << "\t}" << endl << "\tcout << endl;" << endl << "}" << endl << endl;
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 4; ++col)
		{
			cout << array2d[row][col] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	doWaitForInput("Press any key and hit enter to view the memory locations of each element in array2d[3][4]...");
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 4; ++col)
		{
			cout << "array2d[" << row << "][" << col << "]: " << &(array2d[row][col]) << " (" << (int)(&(array2d[row][col])) << ")" << endl << endl;
		}
	}

	doWaitForInput("Press any key and hit enter to view the memory locations for the start of each row...");
	for (int row = 0; row < 3; ++row)
	{
		cout << "array2d[" << row << "]: " << &(array2d[row]) << " (" << (int)(&(array2d[row])) << ")" << endl << endl;
	}

	doWaitForInput("Press any key and hit enter to view the memory locations for the start of each column...");
	for (int col = 0; col < 4; ++col)
	{
		// Access the first row as a pointer //
		cout << "(*array2d)[" << col << "]: " << &((*array2d)[col]) << " (" << (int)(&((*array2d)[col])) << ")" << endl << endl;
	}
}

void arraysAsFunctionParametersDemo()
{
	doWaitForInput("Press any key and hit enter to pass array3[3] to a function that prints the array information...");
	cout << "int array3[3] = { 2, 4, 6 };" << endl;
	int array3[3] = { 2, 4, 6 };
	print1dArrayInfo(array3, 3);

	doWaitForInput("Press any key and hit enter to pass array3_2[3][2] to a function that prints the array information...");
	int array3_2[3][2] = { {1, 11}, {2, 22}, {3, 33} };
	cout << "int array3_2[3][2] = { {1, 11}, {2, 22}, {3, 33} };" << endl;
	print2dArrayInfo(array3_2, 3);
}

void returnArrayFromFunctionsDemo()
{
	doWaitForInput("Press any key and hit enter to return a 1d array from get1dArray()...");
	int * array1d = get1dArray();
	cout << "\tint * array1d = get1dArray();" << endl;
	doWaitForInput("Press any key and hit enter to print the contents of array1d...");
	cout << "\tprint1dArrayInfo(array1d, 3);" << endl;
	print1dArrayInfo(array1d, 3);
	cout << endl;

	doWaitForInput("Press any key and hit enter to return a 2d array from get2dArray()...");
	unsigned int numElementsIn2ndDimension = 3;
	int ** array2d = get2dArray(numElementsIn2ndDimension);
	cout << "\tunsigned int numElementsIn2ndDimension = 3;\r\n\tint ** array2d = get2dArray(numElementsIn2ndDimension);" << endl;
	doWaitForInput("Press any key and hit enter to print the contents of array2d...");
	cout << "\tprint2dArrayInfo_2(array2d, 2);" << endl;
	print2dArrayInfo_2(array2d, 2);
}

void cstringArrayDemo()
{
	doWaitForInput("Press any key and hit enter to initialize a character array using double quotes...");
	char c1[] = "blah";	
	cout << "\tchar c1[] = \"blah\";" << endl;
	cout << "\tsizeof(c1): " << sizeof(c1) << endl << endl;
	doWaitForInput("Press any key and hit enter to print the c_string to cout...");
	cout << "\tcout << \"\\t\" << c1;" << endl;
	cout << "\t" << c1 << endl << endl;

	doWaitForInput("Press any key and hit enter to access c1[] using an index...");
	cout << "Number of elements in c1[]: 5" << endl << endl;
	int indexToAccess = 0;
	while (true)
	{
		cout << "Enter an index to get the memory location and value of the c_string element (negative number to skip): ";
		cin >> indexToAccess;
		if (indexToAccess < 0) break;
		try {
			cout << "c1[" << indexToAccess << "]: " << c1[indexToAccess] << endl;
		}
		catch (...)
		{
			cout << "Exception while accessing the array with index " << indexToAccess << endl;
			indexToAccess = -1;
		}
	}

	doWaitForInput("Press any key and hit enter to initialize a character array using an initializer list...");
	char s3[] = { 'b', 'l', 'a', 'h', '\0' };
	cout << "\tchar s3[] = { 'b', 'l', 'a', 'h', '\0' };" << endl;
	cout << "\tsizeof(s3): " << sizeof(s3) << endl;
	doWaitForInput("Press any key and hit enter to print s3 to cout...");
	cout << "\tcout << \"\\t\" << s3 << endl;" << endl;
	cout << "\t" << s3 << endl;

	doWaitForInput("Press any key and hit enter to initialize a character array without null...");
	char s2[] = { 'b', 'l', 'a', 'h' };
	cout << "\tchar s2[] = { 'b', 'l', 'a', 'h' };" << endl;
	cout << "\tsizeof(s2): " << sizeof(s2) << endl;
	doWaitForInput("Pres any key and hit enter to print s2 to cout...");
	cout << "\tcout << \"\\t\" << s2 << endl;" << endl;
	cout << "\t" << s2 << endl;

	cout << endl;
}