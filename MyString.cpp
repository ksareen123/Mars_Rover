#include "MyString.h"

//constructors and destructor
MyString::MyString() : len(0), space(1), arr(new char[0]) {}
MyString::MyString(const MyString& str) : len(str.size()), space(str.capacity()), arr(new char[str.size()]) {
    for (size_t i = 0; i < len; i++) {
        arr[i] = str.data()[i];
    }
}
MyString::MyString(const char* s) : len(0), space(1), arr(new char[0]) {
    if (s == nullptr) {
        return;
    }
    size_t i = 0;
    while (s[i] != '\0') {
        i ++;
    }
    len = i;
    space = i+1;
    //std::cout << "set size to " << i << std::endl;
    delete[] arr;
    arr = new char[i];
    i = 0;
    while (s[i] != '\0') {
        arr[i] = s[i];
        //std::cout << s[i] << std::endl;
        i++;
    }
    //arr[i] = '\0';
}
MyString::~MyString() {
    if (arr) {
        delete[] arr;
    }
}

//methods
void MyString::resize(size_t n) {
    char* resized = new char[n];
    for (size_t i = 0; i < len; i++) {
        resized[i] = arr[i];
    }
    delete[] arr;
    arr = resized;
    len = len;
    space = n;
    //std::cout << "Method Works" << std::endl;
}
void MyString::clear() {
    delete[] arr;
    arr = new char[0];
    len = 0;
    space = 1;
    //std::cout << "Method Works" << std::endl;
}
int MyString::find(const MyString& str, size_t pos) const noexcept{
    int pos_found = -1;
    bool exists = true;
    for (size_t i = pos; i < len; i++) {
        if (arr[i] == str.at(0)) {
            size_t length = str.size();
            for (size_t j = 0; j < length; j++) {
                if (arr[i+j] != str.at(j)) {
                    exists = false;
                    break;
                }
            }
            if (exists == true) {
                pos_found = i;
                break;
            }
        }
    }
    //std::cout << "Method Works" << std::endl;
    return pos_found;
}
const char& MyString::at(size_t pos) const {
    if (pos >= len) {
        throw std::out_of_range("index out of range");
    }
    //std::cout << "Method Works" << std::endl;
    return arr[pos];
}

//descriptor-methods
size_t MyString::capacity() const {
    //std::cout << "Method Works" << std::endl;
    return space;
}
size_t MyString::size() const {
    //std::cout << "Method Works" << std::endl;
    return len;
}
size_t MyString::length() const {
    //std::cout << "Method Works" << std::endl;
    return len;
}
char* MyString::data() const noexcept{
    //std::cout << "Method Works" << std::endl;
    return arr;
}
bool MyString::empty() const noexcept{
    if (len == 0) {
        return true;
    }
    return false;
}
const char& MyString::front() const {
    //std::cout << "Method Works" << std::endl;
    if (len == 0) {
        throw std::out_of_range("no front");
    }
    return arr[0];
}

//operators
MyString& MyString::operator= (const MyString& str) {
    delete[] arr;
    len = str.size();
    space = str.capacity();
    arr = new char[len];
    for (size_t i = 0; i < len; i++) {
        arr[i] = str.data()[i];
    }
    return *this;
}
MyString& MyString::operator+= (const MyString& str) {
    size_t size = str.size() + this->size();
    this->resize(size);
    for (size_t i = 0; i < str.size(); i++) {
        arr[len + i] = str.at(i);
    }
    len = size;
    space = size + 1;
    //arr[size] = '\0';
    return *this;
}

//stream operator
std::ostream& operator<< (std::ostream& os, const MyString& str) {
    //std::cout << "Method Works" << std::endl;
    for (size_t i = 0; i < str.size(); i++) {
        os << str.at(i);
    }
    return os;
}
// extra operators
bool operator== (const MyString& lhs, const MyString& rhs) {
    if (lhs.size() == rhs.size()) {
        if (lhs.capacity() == rhs.capacity()) {
            for (size_t i = 0; i < lhs.size(); i++) {
                if (lhs.at(i) != rhs.at(i)) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    else {
        return false;
    }
}

MyString operator+ (const MyString& lhs, const MyString& rhs) {
    MyString newstring = MyString(lhs);
    newstring += rhs;
    return newstring;
}
