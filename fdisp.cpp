/*
 * David Moran
 * CS 3377.0W1
 * Spring 2018
 * File Display
 */
#include <iostream>
#include <string>

int main(int argc, const char * argv[]){
	// Create strings to store the piped input
	std::string dirLine = " ";
	std::string fileLine = " ";
	std::string sizeLine = " ";

	// Pipe the inputs(We can use 3 variables because we know the order they will be printed)
	getline(std::cin, fileLine);
	getline(std::cin, dirLine);
	getline(std::cin, sizeLine);

	
	// Determine what to output based on the input
	// If "-d" was entered, output the directory line
	if(argv[1][1] == 'd'){
		std::cout << dirLine << std::endl;
	}// If "-f" was entered, output the file line
	else if(argv[1][1] == 'f'){
		std::cout << fileLine << std::endl;
	}// If "-b" was entered, output the size line
	else if(argv[1][1] == 'b'){
		std::cout << sizeLine << std::endl;
	}

	return 0;
}
