// manager.h
// Ernesto Martinez
// ***************
// This file will declare
// the ADT classes and the 
// Manager class which will 
// control the program
// ***************
#include "bst.h"

// Manager class will control the program
class manager
{
public:
	manager(); // constructor

	void prompt(); // prompting user
	void welcome(); // welcoming user
private:
	// TEMPS for info
	char test[30];
	char test1[30];
	char con1[30];
	char con2[30];
	char con3[30];

	int x; // for menu
	BST tree; // object of BST
};

// Broadcat class will manage the social media frequency 
// in which the people use as contacts
// social media includes facebook,twitter and instagram only. 
class broadcast
{
public:
	broadcast() { count = 0; social=NULL;};	

	broadcast operator + (const broadcast&) const;
	broadcast& operator += (const broadcast&);
	friend ostream& operator << (ostream&, const broadcast&);
	bool operator == (const broadcast&) const;
	
private:
	int count;
	char * social;	
};

// emergency class will manage the amount of people who is contacted
// through  social media and separate them from those who dont. 
class emergency:public broadcast
{
public:
	emergency() { people = 0; };
	
	emergency operator + (const emergency&) const;
	emergency& operator += (const emergency&);
	friend ostream& operator << (ostream&, const emergency&);
	bool operator == (const emergency&) const;
	
private:
	int people;
};
