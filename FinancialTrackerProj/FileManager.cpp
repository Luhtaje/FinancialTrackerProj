#pragma once
#include <sstream>
#include "FileManager.h"

/*
FileManager handles all actions with files- saving,reading and clearing.
*/
using namespace std;
FileManager::FileManager() {

}

//Goes through the vector in temporary memory and saves transaction strings into the datafile.
void FileManager::saveToDisk(Record& recordobj) const{

	ofstream datafile("datafile.txt", std::ios_base::app);
	if (datafile.is_open()) {
		datafile << recordobj;
	}
	datafile.close();
}

/*
Reads data from the disk and creates transactions in to the record.
Record needs to be empty when reading from the disk.
*/
void FileManager::readFromDisk(Record& recordobj)const {
	ifstream datafile("datafile.txt");

	if (datafile.is_open()) {
		datafile >> recordobj;
	}
	else {
		cout << "Error reading from file. File not open." << endl;
	}
	datafile.close();
}

//Deletes all contets of the datafile.
void FileManager::clearDisk()const {
	fstream datafile;
	fclose(fopen("datafile.txt", "w"));

}



