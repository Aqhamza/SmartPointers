#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


class ref_Link{

public :
    
    ref_Link(ref_Link* x = 0) throw()   : stringBuffer(0) 
    {
        prePtr = nextPtr = this;
    }


    ~ref_Link();               
    char charAt(int) const;   
    int length() const;                            
    void reserve(int);                             
    void append(char);               
    void print();
    char* get() const throw()
    {
        return stringBuffer;
    }
	ref_Link(const ref_Link& temp)
	{
        Fetching(temp);
        len = temp.len;   
	}
    ref_Link& operator= (const ref_Link &temp )
    { 
    	if (this != &temp) {
            ref_delete();
            Fetching(temp);
        }
        return *this;
    }

    bool unique()   const throw()  
     {
     	if(prePtr == this && nextPtr == this)
     		return 1;
     	else
     		return 0;
     }
     //Private...
private:
                                       
    char* stringBuffer; 
    int len;
    
    ref_Link*   prePtr;
    ref_Link*   nextPtr;
    
    void Fetching(const ref_Link& temp) throw()
    { 
        stringBuffer = temp.stringBuffer;
        len = temp.len;
        nextPtr = temp.nextPtr;
        nextPtr->prePtr = this;
        (const_cast<ref_Link*>(&temp))->nextPtr = this;
    }

    void ref_delete()
    { 
        if (unique()) 
        	delete[] stringBuffer;
        else
        {
            prePtr->nextPtr = nextPtr;
            nextPtr->prePtr = prePtr;
            prePtr = nextPtr = 0;
        }
       
    }

};
ref_Link::~ref_Link()  
{
	ref_delete();
	
}
int ref_Link::length() const
{
	return len;
}


char ref_Link::charAt(int i) const
{
	return stringBuffer[i];
}


void ref_Link::reserve(int i)
{
	stringBuffer = new char[i];
}

void ref_Link::append(char strr)
{
	if(unique())
	{
		stringBuffer[len] = strr;
		len += 1;
	}
	else
	{
		char* temp = new char[len];
		strncpy(temp,stringBuffer,len);
		ref_delete();
		stringBuffer = new char[len];
		strncpy(stringBuffer,temp,len);
		stringBuffer[len] = strr;
		len += 1;
		delete[] temp;
		nextPtr = prePtr = this;
	}	
}

void ref_Link::print()
{
    
    for (int i = 0; i < len ; ++i)
    {
         cout<<*(stringBuffer + i) ;
    }
}

