#include "File.h"
#include <ctime>
#include <Windows.h>

File::File(const string name, int mode) {
	if (mode == 1) {
		file.open(name, ios::out);
	}
	else if (mode == 2) {
		file.open(name, ios::app);
	}
	else if (mode == 3) {
		file.open(name, ios::in || ios::ate);
	}
	else {
		file.open(name, ios::in);
	}

	if (!file.is_open()) {
		throw 0;
	}
	else if (!mode && file.peek() == EOF) {
		throw 1;
	}
}

File::~File() {
	file.close();
}

ostream& File::getToWrite() {
	return file;
}

istream& File::getToRead() {
	return file;
}