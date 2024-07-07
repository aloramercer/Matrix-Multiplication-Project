

#include <iostream>
#include <ctime>//in order to randomize the sizes and the values of the matrixes
#include <fstream>//in order to Read and Write to a file
#include <string>//in order to use the getline function


using namespace std;

//*******************************************************************************************************************************
//*************                         STUDENT NAME: BEYZA KOMis                                              ******************
//*************                         ASSiGNMENT #: Project 1                                                ******************
//*************                         and i got help from some recources                                     ******************
//*******************************************************************************************************************************





void generate(int **B,int **C,int b,int c) {//Creatingg a generate function to generate the B input matrix and the core matrix into the file

	ofstream file;//calling the fstream library for output

	{   file.open("data.txt", ios::out);//opening the file named data.txtt

	if (file.is_open())//Checking if the file open or not.
	{
		//now time for generating them in the file

		file << "input matrix" << endl;


		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < b; j++)

			{
				file << B[i][j] << " ";
			}
			file << endl;
		}



		file << "core matrix" << endl;


		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < c; j++)

			{
				file << C[i][j] << " ";
			}
			file << endl;
		}


		file.close();//close the file
	}}


}



void retrieve() {//creating the retrieve function to store the matrixes from the file.

	

	ifstream file;//calling the fstream libray for input and reading.


	file.open("data.txt", ios::in);


	char p;//creating a char p to know where my breaking point will start
	streampos position;//i used int before this but it was not matching with the tellg return type so i used streampos
	while (true)//creating an infinite loop to break when needed
	{           //this first while loop is for to know where we stopped.

		position = file.tellg();//pinning the begining to work with it later

		file >> p;//saving every letter of the file

		if (isdigit(p))//UNTiL it reaches a digit
		{
			break;
		}

	}


	file.clear();//clearing the error flags that might happen
	file.seekg(position, ios::beg);//setting it back to where i pinned.

	int size = 0;//initializing the size of inputmatrix
	string line;//initializing for the get line function to count and read the lines 
	char q;//again using a char to check and save the charachters in a file
	while (true)//this loop is for counting the size of my array
	{

		file >> q;//again saving every letter to the file
		getline(file, line);//this is to read the whole line until it encounters an  alphabet more apecifically the start of the title 'core matrix'


		if (!(isdigit(q)))
		{
			break;
		}
		size++;//and know it counts until the digits have finished 

	}


	file.clear();//clearing the file
	file.seekg(position, ios::beg);//setting this to the start of the file before storing it into a new array 


	int** M = new int* [size * size];//now we know the size and we can use it to store it to a new matrix named M
	for (int i = 0; i < size; i++) { M[i] = new int[size]; }//initializing a 2d array dynamically by using new keyword

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			file >> M[i][j];//storing them one by one in the file.
		}

	}

	 
	//AND doing the whole process for the CORE MATRiX


	char r;
	streampos positioncore;
	while (true)
	{

		positioncore = file.tellg();

		file >> r;

		if (isdigit(r))
		{
			break;
		}

	}


	file.clear();


	int sizecore = 0;
	string lines;
	char s;
	while (getline(file, lines))
	{

		file >> s;

		sizecore++;

	}



	file.clear();
	file.seekg(positioncore, ios::beg);


	int** N = new int* [sizecore * sizecore];
	for (int i = 0; i < sizecore; i++) { N[i] = new int[sizecore]; }

	for (int i = 0; i < sizecore; i++)
	{
		for (int j = 0; j < sizecore; j++)
		{
			file >> N[i][j];

		}

	}



	int outputsize = size - sizecore + 1;//initilizing the size of the output array

	int** A = new int* [outputsize];//initializing the outpout array 
	for (int i = 0; i < outputsize; i++)
	{
		A[i] = new int[outputsize];
	}



	cout << "The Output Matrix:" << endl;

	for (int i = 0; i <= outputsize-1; i++) {//This for function is to shift the input matrix window
		for (int j = 0; j <= outputsize-1; j++) {//i did -1 because i think it wasnt getting the last members or the coloumns

			int output = (0);//initiliazing the output matrixes values like this for proper code running

			//This for loops is to multiply the matrixes and with the indices correctly put this for loops helps us to reverse the B input matrix as well.
			for (int x = 0; x < sizecore; x++) {
				for (int y = 0; y < sizecore; y++) {

					//Here we are storing every multiplied matrix and summing the value in the output variable    
					output += N[x][y] * M[sizecore + i - x - 1][j + sizecore - y - 1];
					//We're using the '-x' and the '-y' to reverse B matrix and....
					//We're using the '+i'and '+j 'in order to shift the window and -1 to access the last element of the output matrix.
				}
			}
			//Here we are storing each summed output variable to the output matrix by dividing it with the number of elements the core matrix consists.
			A[i][j] = output / (sizecore * sizecore);
			
		}
	}



		for (int i = 0; i < outputsize; i++)//This is to print the output matrix.
		{
			for (int j = 0; j <outputsize; j++)
			{
				cout << A[i][j] << " ";
			}
			cout << endl;
		}



	for (int i = 0; i < outputsize; i++) {//Then deleting the output matrix from the heap to free mmemory
		delete[] A[i];
	}
	delete[] A;
	A = NULL;




	file.close();//Closing the file.




	}








int main() {


	srand(static_cast<unsigned int>(time(0)));//so i have used srand((time0)) but it was giving me an error and found this block of code that was more efficient to use apparently

	int b = 5 + (rand() % (20 - 5 + 1));//randomizing the size of the input matrix B
	int c = 2 + (rand() % (5 - 2 + 1));//randomizing the size of the core matrix C
	

	//initializing the B input matrix dynamically 
	int** B = new int* [b];
	for (int i = 0; i < b; i++)
	{
		B[i] = new int[b];
	}
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < b; j++)

		{
			B[i][j] = 10 + (rand() % (20 - 10 + 1));//and randomizing the values inside from 10 to 20
		}
	}

	//initializing the C  core  matrix dynamically 
	int** C = new int* [c];
	for (int i = 0; i < c; i++)
	{
		C[i] = new int[c];
	}


	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)

		{
			C[i][j] = 1 + (rand() % (10 - 1 + 1));//and randomizing the values inside from 1 to 10
		}
	}

	
	//using a switch case to create the menu

	int x;//initializing the integer user going to enter
	cout << "Press 1-To generate new matrix or press 2-To read the matrixes" << endl;//asking the user
	cin >> x;//user entering

	switch (x)
	{
	case 1: generate( B, C, b, c);//if case 1 is chosen its going to generate the wanted matrixes in the file
		retrieve();//and this is to print out the output matrix
		
		break;//if case 1 is called its goint to generate the B and the C matrix.


	case 2: retrieve(); break;//in here we are retreiving the matrixes with this function whem 2 is selected
		
		
	default:cout << "Please enter either the integer 1 or 2!" << endl;//and if the user has entered some other variable it breaks right away.
		break;
	}
	
	
	// i have read and print the function here regardless of everything so we can see the input and the core matrix

	ifstream file;



	file.open("data.txt", ios::in);


	string line;

	while (getline(file, line))
	{
		cout << line << endl;

	}

	file.close();

	



	return 0;
}
