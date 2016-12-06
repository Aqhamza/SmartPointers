#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class ownString{
private:
    bool check;
    char* stringBuffer;                                   
    int len;                                   
public :
    ownString(char* x = 0) throw()     : check(x!=0), stringBuffer(x) {}
    ~ownString();                
    ownString(char*,int);   
    char charAt(int) const;   
    int length() const;                            
    void reserve(int);                             
    void append(char);                          
    void print();
	ownString(const ownString& temp) throw(): check(temp.check), stringBuffer(temp.release()) {}
    ownString& operator =(const ownString &temp )
    { 
    	if (&temp != this) {
            if (stringBuffer != temp.stringBuffer)
            {
                if (check)
                {
                	delete[] stringBuffer;
                	delete stringBuffer;
                }
                check = temp.check;
            }
            else if (temp.check) check = true;
            delete[] stringBuffer;
            stringBuffer = temp.release();
            len = temp.len;
        }
        return *this;
    }
    char* release()  const throw()
    {
    	(const_cast<ownString* >(this))->check = false; 
    	return stringBuffer;
    }
};
ownString::ownString(char* str,int len)
{
    stringBuffer = str;
    len = len;
}
ownString::~ownString()  
{
	if (check)
	{
		delete[] stringBuffer;
	}
	delete stringBuffer;	
}
int ownString::length() const
{
	return len;
}
char ownString::charAt(int index) const
{
	return stringBuffer[index];
}
void ownString::reserve(int index)
{
	stringBuffer = new char[index];
}
void ownString::append(char letter)
{
	stringBuffer[len] = letter;
	len += 1;
}
void ownString::print()
{
   for (int i = 0; i < len+1 ; ++i)
    {
         cout<<*(stringBuffer + i);
    }    
}