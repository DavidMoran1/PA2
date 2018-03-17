//  CS 3377 Project 2
//
//  Created by David Moran on 2/13/18.
//  Copyright © 2018 David Moran. All rights reserved.
//

#include <iostream>
#include <sys/stat.h>
#include <dirent.h>

void fcount(const char *);

// Declare variables to hold the counts
int numberOfFiles = 0;
int numberOfDir = 0;
unsigned long numberOfBytes = 0;

int main(int argc, const char * argv[]) {

	// Make sure that the correct number of arguments was passed
    if(argc != 2){
        std::cout << "The number of arguments is incorrect." << std::endl;
        return 0;
    }else{
    		// Make a call to get the counts
    		fcount(argv[1]);
    }
    
    // Output the results
    std::cout << "The number of files is: " << numberOfFiles << std::endl;
    std::cout << "The number of directories is: " << numberOfDir << std::endl;
    std::cout << "The number of bytes in the path is: " << numberOfBytes << std::endl;
    
    return 0;
}

void fcount(const char* path){

	// Create a structure that stores the directory
	struct dirent *entry;
	DIR *dp;

	// Set the beginning of the directory
	dp = opendir(path);

	// Make sure a path is stored
	if(dp == NULL){
		printf ("Cannot open directory '%s'\n", path);
		return;
	}

	// Loop to iterate through the directory
	while((entry = readdir(dp)) != NULL){
		// If the current path is a regular file, increment the count
		if(entry->d_type == DT_REG) numberOfFiles++;
		// If the current path is a directory, increment the directory
		else if(entry->d_type == DT_DIR) numberOfDir++;
		// Get the size and add it to the current size
		numberOfBytes += (entry->d_reclen);
	}

	// Close the directory
	closedir(dp);

	return;
}
