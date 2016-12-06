#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

#include "Copy.h"
#include "Own.h"
#include "COW.h"
#include "Link Reference.h"

using namespace std;
class Test
{
public:
	Test(){};

void cons_CPointer()
{
	cout<<"-----------Testing For Copy Pointer's Class----------- "<<endl;
	cout<<"\n.\n.\n."<<endl;
	copyString obj;
	obj.reserve(10);
	obj.append('A');
	obj.append('B');

	copyString obj1(obj);

	for(int i = 0; i < 2;++i)
	{
		if(obj.charAt(i) != obj1.charAt(i))
		{
			
			cout<<"-----------Your Test Has Been Failed-----------"<<endl;
			cout<<"\n.\n.\n."<<endl;
			return;
		}
	}
	cout <<"-----------Your Test Has Been Passed-----------"<<endl;
	cout<<"\n.\n.\n."<<endl;
}



void cons_OwnPointer()
{
	ownString* obj = new ownString();
	obj->reserve(10);
	obj->append('A');
	cout<<"-----------Testing For Owned Pointer's Class----------- "<<endl;
	cout<<"\n.\n.\n."<<endl;

	ownString* obj1 = new ownString(*obj);
	obj1->reserve(10);
	*obj1 = *obj;

	for(int i = 0; i < 2;++i)
	{
		if(obj->charAt(i) != obj1->charAt(i))
		{
			cout<<"-----------Your Test Has Been Failed-----------"<<endl;
			cout<<"\n.\n.\n."<<endl;
			return;
		}
	}
	cout <<"-----------Your Test Has Been Passed-----------"<<endl;
	cout<<"\n.\n.\n."<<endl;
	
}


void cons_RCount_P()
{
	refCount obj;
	obj.reserve(10);
	obj.append('A');
	obj.append('B');
	refCount op1;
	op1.reserve(10);
	op1 = obj;
    cout<<"-----------Testing For Reference Count Pointer's Class----------- "<<endl;
    cout<<"\n.\n.\n."<<endl;
	for(int i = 0; i < 2;++i)
	{
		if(obj.charAt(i) != op1.charAt(i))
		{
			cout<<"-----------Your Test Has Been Failed-----------"<<endl;
			cout<<"\n.\n.\n."<<endl;
			return;
		}
	}
	cout<<"-----------Your Test Has Been Passed-----------"<<endl;
	cout<<"\n.\n.\n."<<endl;

}


void cons_RLink_P()
{
	ref_Link* obj = new ref_Link();
	obj->reserve(10);
	obj->append('A');
	ref_Link* obj1 = new ref_Link();
	obj1->reserve(10);
	*obj = *obj1;
    cout<<"-----------Testing For Reference Linked Pointer's Class----------- "<<endl;
    cout<<"\n.\n.\n."<<endl;
	for(int i = 0; i < 2;++i)
	{
		if(obj->charAt(i) != obj1->charAt(i))
		{
			cout<<"-----------Your Test Has Been Failed-----------"<<endl;
			cout<<"\n.\n.\n."<<endl;
			return;
		}
	}
	cout<<"-----------Your Test Has Been Passed-----------"<<endl;
	cout<<"\n.\n.\n."<<endl;
	

}



void lCopy()
{
	cout<<"-----------Testing for Checking Length of Copied Class----------- "<<endl;
	cout<<"\n.\n.\n."<<endl;
	copyString le;
	le.reserve(10);
	le.append('A');
	int len = le.length();
	if(len == 1)
	{
		cout<<"-----------Your Test Has Been Passed-----------"<<endl;
	    cout<<"\n.\n.\n."<<endl;
	}
	else
	{
		cout<<"-----------Your Test Has Been Failed-----------"<<endl;
	    cout<<"\n.\n.\n."<<endl;
	}
}



void lOwned()
{
	cout<<"-----------Testing for Checking Length of Owned Class----------- "<<endl;
	ownString* obj = new ownString();
	obj->reserve(10);
	obj->append('A');
	int len = obj->length();
	if(len == 1)
	{
		cout<<"-----------Your Test Has Been Passed-----------"<<endl;
	    cout<<"\n.\n.\n."<<endl;
	}
	else
	{
		cout<<"-----------Your Test Has Been Failed-----------"<<endl;
	    cout<<"\n.\n.\n."<<endl;
	}
}


void lRCount()
{
	cout<<"-----------Testing for Checking Length of Reference Count Class----------- "<<endl;
	refCount obj;
	obj.reserve(10);
	obj.append('A');
	obj.append('B');

	int len = obj.length();
	if(len == 2)
	{
		cout<<"-----------Your Test Has Been Passed-----------"<<endl;
	    cout<<"\n.\n.\n."<<endl;
	}
	else
	{
		cout<<"-----------Your Test Has Been Failed-----------"<<endl;
	    cout<<"\n.\n.\n."<<endl;
	}
}


void lRLink()
{
	cout<<"-----------Testing for Checking Length of Reference Linked Class----------- "<<endl;
	cout<<"\n.\n.\n."<<endl;
	ref_Link* obj = new ref_Link();
	obj->reserve(10);
	obj->append('A');
	//obj.append('B');

	int len = obj->length();
	if(len == 1)
	{
		cout<<"-----------Your Test Has Been Passed-----------"<<endl;
	    cout<<"\n.\n.\n."<<endl;
	}
	else
	{
		cout<<"-----------Your Test Has Been Failed-----------"<<endl;
		cout<<"\n.\n.\n."<<endl;
	}
}



void ACopy()
{
	cout<<"-----------Testing for Checking Append of Copied Class----------- "<<endl;
	cout<<"\n.\n.\n."<<endl;
	copyString le;
	le.reserve(10);
	le.append('A');
	int len = le.length();
	if(len == 1)
	{
		cout<<"-----------Your Test Has Been Passed-----------"<<endl;
		cout<<"\n.\n.\n."<<endl;
	}
	else
	{
		cout<<"-----------Your Test Has Been Failed-----------"<<endl;
		cout<<"\n.\n.\n."<<endl;
    }
}




void AOwned()
{
	ownString* obj = new ownString();
	obj->reserve(10);
	obj->append('A');
	cout<<"-----------Testing for Checking Append of Owned Class----------- "<<endl;
	cout<<"\n.\n.\n."<<endl;

	int len = obj->length();
	if(len == 1)
	{
		cout<<"-----------Your Test Has Been Passed-----------"<<endl;
	 	cout<<"\n.\n.\n."<<endl;
	}
	else
	{
		cout<<"-----------Your Test Has Been Failed-----------"<<endl;
		cout<<"\n.\n.\n."<<endl;
	}
}



void ARef_Count()
{
	cout<<"-----------Testing for Checking Append of Reference Count Class----------- "<<endl;
	cout<<"\n.\n.\n."<<endl;
	refCount obj;
	obj.reserve(10);
	obj.append('A');
	obj.append('B');
	int len = obj.length();
	if(len == 2)
	{
		cout<<"-----------Your Test Has Been Passed-----------"<<endl;
		cout<<"\n.\n.\n."<<endl;
	}
	else
	{
		cout<<"-----------Your Test Has Been Failed-----------"<<endl;
		cout<<"\n.\n.\n."<<endl;
	}

}


void ARef_Link()
{
	cout<<"-----------Testing for Checking Append of Reference Linked Class----------- "<<endl;
	cout<<"\n.\n.\n."<<endl;
	ref_Link* obj = new ref_Link();
	obj->reserve(1);
	obj->append('A');
	//obj.append('B');

	int len = obj->length();
	if(len == 1)
	{
		cout<<"-----------Your Test Has Been Passed-----------"<<endl;
		cout<<"\n.\n.\n."<<endl;
	}
	else
	{
		cout<<"-----------Your Test Has Been Failed-----------"<<endl;
		cout<<"\n.\n.\n."<<endl;
	}
}


void P_Copy()
{
	cout<<"-----------Testing for Copied of Pointers----------- "<<endl;
	cout<<"\n.\n.\n."<<endl;
	copyString le;
	le.reserve(1);
	le.append('A');
	le.print();
	cout<<endl;
	if(le.charAt(0) == 'A')
	{
		cout<<"-----------Your Test Has Been Passed-----------"<<endl;	
		cout<<"\n.\n.\n."<<endl;
	}
	else
	{
		cout<<"-----------Your Test Has Been Failed-----------"<<endl;
		cout<<"\n.\n.\n."<<endl;
	}
}



void P_Owned()
{
	cout<<"-----------Testing for Owned of Pointers----------- "<<endl;
	cout<<"\n.\n.\n."<<endl;
	ownString* obj = new ownString();
	obj->reserve(1);
	obj->append('A');
	//obj.append('B');
	obj->print();
	
	cout<<endl;

	if(obj->charAt(0) == 'A')
	{
		cout<<"-----------Your Test Has Been Passed-----------"<<endl;	
		cout<<"\n.\n.\n."<<endl;
	}
	else
	{
		cout<<"-----------Your Test Has Been Failed-----------"<<endl;
		cout<<"\n.\n.\n."<<endl;
	}
	
}


void PRef_Count()
{
	cout<<"-----------Testing for Checking Reference Count of Pointer----------- "<<endl;
	cout<<"\n.\n.\n."<<endl;
	refCount obj;
	obj.reserve(1);
	obj.append('A');
	//obj.append('B');
	obj.print();

	cout<<endl;
	if(obj.charAt(0) == 'A')
	{
		cout<<"-----------Your Test Has Been Passed-----------"<<endl;	
		cout<<"\n.\n.\n."<<endl;
	}
	else
	{
		cout<<"-----------Your Test Has Been Failed-----------"<<endl;
		cout<<"\n.\n.\n."<<endl;
	}

}


void PRef_Link()
{
	cout<<"-----------Testing for Checking Reference Linked of Pointer----------- "<<endl;
	cout<<"\n.\n.\n."<<endl;
	ref_Link* obj = new ref_Link();
	obj->reserve(1);
	obj->append('A');
	
	obj->print();
	cout<<endl;

	if(obj->charAt(0) == 'A')
	{
		cout<<"-----------Your Test Has Been Passed-----------"<<endl;	
		cout<<"\n.\n.\n."<<endl;
	}
	else
	{
		cout<<"-----------Your Test Has Been Failed-----------"<<endl;
		cout<<"\n.\n.\n."<<endl;
	}

	
}
};


int main(int argc, char const *argv[])
{

	Test t1;

	t1.cons_CPointer();
	t1.cons_OwnPointer();
	t1.cons_RCount_P();
	t1.cons_RLink_P();	

    t1.lCopy();
	t1.lOwned();
	t1.lRCount();
	t1.lRLink();


    t1.ACopy();
	t1.AOwned();
	t1.ARef_Count();
	t1.ARef_Link();

    t1.P_Copy();
	t1.P_Owned();
	t1.PRef_Count();
	t1.PRef_Link();

	return 0;
}