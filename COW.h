#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


class refCount{

public :
    refCount() throw()   : temp_count(0) 
    {
        len = 0;   
    }


    ~refCount();               
    char charAt(int) const;  
    int length() const;     //Returns the length of Buffer String
    void reserve(int);                             
    void append(char);                          
    void print();
    char* get() const throw()
    {
        return stringBuffer;
    }
    refCount(const refCount& temp)
    {
        _fetching(temp.temp_count);
        len = temp.len; 
    }
    refCount& operator= (const refCount &temp )
    { 
        if (this != &temp) 
        {
            ref_delete();
            _fetching(temp.temp_count);
        }
        stringBuffer = temp.stringBuffer;
        len = temp.len;
        return *this;
    }
    bool unique() const throw()
        {
            return (temp_count ? temp_count->count == 1 : true);
        }
private:
    struct _count 
    {
        _count(unsigned c = 1) :  count(c) {}
        unsigned    count;
    }* temp_count;  
                
    char* stringBuffer; 
    int len;

    void _fetching(_count* c) throw()
    { 
        //cout<<"acquired"<<endl;
        temp_count = c;
        if (c) ++c->count;
    }

    void ref_delete()
    { 
        //cout<<"ref_deleteeased"<<endl;
        if (temp_count) {
          if (--temp_count->count == 0) 
            {
                delete[] stringBuffer;
                delete temp_count;
            }
        }
    }

};



refCount::~refCount()  
{
    ref_delete();
    
}



int refCount::length() const{
    return len;
}


char refCount::charAt(int index) const
{
    return stringBuffer[index];
}


void refCount::reserve(int index)
{
    stringBuffer = new char[index];
    temp_count = new _count();
}

void refCount::append(char letter)
{
    if(temp_count->count > 1)
    {
        --temp_count->count;
        temp_count = new _count();
        char* temp = new char[len];
        strncpy(temp,stringBuffer,len);
        stringBuffer = new char[len];
        strncpy(stringBuffer,temp,len);
        stringBuffer[len] = letter;
        len += 1;
        cout<<"New Copy"<<endl;
        delete[] temp;
       

    }
    else
    {
        stringBuffer[len] = letter;    
        len += 1;
    }
}

void refCount::print()
{
    
    for (int i = 0; i < len; ++i)
    {
         cout<<*(stringBuffer + i) ;
    }
}

