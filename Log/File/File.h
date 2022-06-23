#ifndef CUSTOMFILE
#define CUSTOMFILE

#include <iostream>
#include <fstream>

using namespace std;

class File {
private:
	fstream file;
public:
	File(const string name, int mode);
	~File();
	ostream& getToWrite();
	istream& getToRead();
};

#endif