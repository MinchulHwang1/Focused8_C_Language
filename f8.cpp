/*
* FILE : f8.cpp
* Project : Focused8
* Programmer : Minchul Hwang
* FirstVersion : 2022-11-16
* Description : Save the argument of command line,(Number, contents, path, filename)
*				The number refers to the number of lines of text that are generated.
*				Contents represents the contents which is line
*				path is saving location of the file
*				fileaname is the saved file name
* The functions in this file are nothing.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma warning(disable: 4996)
#define kStringLength 21

//the struct to save some data of argements of command line.
struct MyData {    
	unsigned int howMany;   
	char theText[kStringLength];       
	char directoryPath[kStringLength];    
	char filename[kStringLength];         
};


int main(int argc, char* argv[]) {
	int argNum = 1;
	
	struct MyData myArgs = { *argv[argNum], *argv[argNum+1], *argv[argNum+2], *argv[argNum+3]};
	char buffer[200] = "C:\\Users\\hmc91\\source\\repos\\Focused_8";

	//Put argument into struct.
	myArgs.howMany = *argv[argNum];
	strcpy(myArgs.theText, argv[argNum+1]);    
	strcpy(myArgs.directoryPath, argv[argNum+2]);
	strcpy(myArgs.filename, argv[argNum+3]);

	//Attach address of file into the file.
	strcat(buffer, myArgs.directoryPath);
	strcat(buffer, "\\");
	strcat(buffer, myArgs.filename);
	
	//Create a file
	FILE* fp = NULL;
	char record[81] = { 0 };
	
	//error check to open file
	fp = fopen(buffer, "wt");
	if (fp == NULL) {
		printf("Can't open file\n");
		return 1;
	}

	//error check for file.
	if (ferror(fp) != 0) {
		printf("There is an error on the file.\n");
		return 2; 
	}

	for (int i = 0; i < (myArgs.howMany - '0'); i++) {
		fprintf(fp, "%c %s\n", myArgs.howMany, myArgs.theText);
	}

	//error check to close file
	if (fclose(fp) != 0) {
		printf("Can't close file opened for writing\n");
		return 3;
	}

	return 0;
}


