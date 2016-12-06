#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class copyString{
public :
     copyString(char* x = 0) throw()     : string_buffer(x) 
     {
        len = 0;
     }
    ~copyString();                  //Destructor
    copyString(const copyString&);  //Constructor
    copyString(char*,int);          //Constructor 
    char charAt(int) const;         
    int length() const;             //Return Length of Buffer
    void reserve(int);                             
    void append(char);                         
    void print();

    copyString& operator= (const copyString &temp )
    { 
        if (this != &temp)
        {
            delete[] string_buffer;
            string_buffer = new char [temp.len];
            strcpy(string_buffer, temp.string_buffer);
            len = temp.len;       
        }
        return *this;
    }

private:
    char* string_buffer;        //Declaration of Private Variables;
    int len;

};
copyString::copyString(const copyString& temp)
{
    string_buffer = new char [temp.len];
    strcpy(string_buffer, temp.string_buffer);
    len = temp.len;       
}


copyString::copyString(char* str,int len1)
{
    string_buffer = str;
    len = len1;
}
copyString::~copyString()  
{

    delete[] string_buffer;
   
}
char copyString::charAt(int index) const
{
	return string_buffer[index];
}
void copyString::print()
{
    
    for (int i = 0; i < len ; ++i)
    {
         cout<<*(string_buffer + i) ;
    }
    
}
void copyString::reserve(int index)
{
	string_buffer = new char[index];
}

void copyString::append(char letter)
{
	string_buffer[len] = letter;
	len += 1;
}
int copyString::length() const
{
    return len;
}



