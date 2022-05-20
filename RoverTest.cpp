#include <iostream>
#include <fstream>
#include "Rover.h"
#include "MyString.h"
using std::cin, std::cout, std::endl, std::ifstream, std::istream;


// helper function "stoi" to converts MyString to int, works a lot like number slicing in reverse
int stoi(const MyString& str, size_t* pos = nullptr, int base = 10) { // just doing base 10 here
	int result = 0;
	for (unsigned int i = 0; i < str.size(); i++) { // MyString: size()
		if (str.at(i) >= '0' && str.at(i) <= '9') { // MyString: at()
			result *= 10; // increase digit (reverse of number slicing)
			result += str.at(i) - 48; // using ascii for conversion
		}
	}
	return result;
}

// helper function for insertion allows reading from input stream to MyString
istream& operator>>(istream& is, MyString& str) {
	str.clear();
	while (!is.eof()) {
		char c;
		is >> std::noskipws >> c; // use the noskipws manipulator
		if (isspace(c) || is.fail()) break; // if whitespace, can stop adding to string
		const char* newstr = new char[2] {c, '\0'};
		MyString newc = MyString(newstr); // MyString: copy constructor
		delete[] newstr;
		str += newc; // MyString: operator+=()
	}
	return is;
}


int main () {
	
	// open command file
	MyString filename; // MyString: default constructor

	cin >> filename; // operator>> is provided above

	ifstream commands(filename.data()); // MyString: data() return const char* type (otherwise, have to implement ifstream constructor for MyString type)

	if (!commands.is_open()) {
		cout << "Unable to open file" << endl;
		return 1;
	}

	// setup test rover
	Rover testRover;

	// read commands
	MyString comm;
	MyString data;
	while (!commands.eof()) {
		commands >> comm;

		if (comm.front() == 'P') { // MyString: front()
			testRover.print();
			continue;
		}

		if (comm.front() == 'C') {
			testRover.clear();
			continue;
		}

		commands >> data;

		switch (comm.front()) {
			case 'S':
				testRover.setSMILE(data);
				break;
			case 'R':
				testRover.read(stoi(data)); // stoi is provided above
				break;
			case 'J':
				testRover.join(data);
				break;
			case 'T':
				cout << testRover.test(data) << endl;
				break;
			case 'F':
				cout << data << " "; // MyString: operator<<()
				if (testRover.find(data)) {
					cout << "was found" << endl;
				} else {
					cout << "was not found" << endl;
				}
				break;
			default:
				continue;
		}
	}
	*/
	/*
	MyString str = MyString();
	std::cout << "Default" << std::endl;
	MyString str2 = MyString("bruh"); 
	std::cout << "C-string" << std::endl;
	MyString str3 = MyString(str2);
	std::cout << "Copy" << std::endl;


	std::cout << "String: " << str3.at(0) << std::endl;
	str2 += str3;
	std::cout << "str2+str3 = ";
	for (size_t i = 0; i < str2.size(); i++) {
		std::cout << str2.at(i);
	}
	std::cout << std::endl;

	std::cout << "string uh found at :" << str2.find("uh") << std::endl;
	*/
	/*
	std::cout << "attempt to add _ and string" << std::endl;
	MyString str4 = MyString(" "); 
	MyString str5 = MyString("string"); 
	str4 += str5; 
	std::cout << "string concatination " << str4 << std::endl;
	
	MyString str = "hello, world!";
    std::cout << str << std::endl;
    const char* data = str.data();
    std::cout << data << std::endl;
    return 0;
}
