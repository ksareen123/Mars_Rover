#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString {
    private:
        size_t len;
        size_t space;
        char* arr;
    public:
        //constructors and destructor
        MyString();
        MyString(const MyString& str);
        MyString(const char* s);
        ~MyString();

        //methods
        void resize(size_t n);
        void clear();
        int find (const MyString& str, size_t pos = 0) const noexcept;
        const char& at(size_t pos) const;

        //operators
        MyString& operator= (const MyString& str);
        MyString& operator+= (const MyString& str);
 
        //descriptor-methods
        size_t capacity() const;
        size_t size() const;
        size_t length() const;
        char* data() const noexcept;
        bool empty() const noexcept;
        const char& front() const;
        
        // DOESN'T WORK
        // ostream& operator<< (ostream& os, const MyString& str);
};

std::ostream& operator<< (std::ostream& os, const MyString& str);
bool operator== (const MyString& lhs, const MyString& rhs);
MyString operator+ (const MyString& lhs, const MyString& rhs);
#endif