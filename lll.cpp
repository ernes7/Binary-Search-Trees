// lll.cpp
// Ernesto Martinez
// ***************
// This file will implement the Linear Linked
// List functions
// ********************
#include "bst.h"

// CLASS LLL implementation
// ***********************

// ***** Constructor *****
LLL::LLL()
{
	head = NULL;
}
// ***** Insert sort *****
// Will insert info and first name into the lll
// ******************************************
bool LLL::insert_sort(char hold[], char hold1[], char hold2[], char hold3[])
{
	//Storing info
	node*temp = new node;
	// *****************
	temp->first = new char[strlen(hold)+1];
	strcpy(temp->first, hold);
	// *****************
	temp->contact1 = new char[strlen(hold1)+1];
	strcpy(temp->contact1, hold1);
	// *****************
	temp->contact2 = new char[strlen(hold2)+1];
	strcpy(temp->contact2, hold2);
	// ******************
	temp->contact3 = new char[strlen(hold3)+1];
	strcpy(temp->contact3, hold3);
	// *****************
	
		
	if(!head) // if not head
	{
		// adding
		head = temp;
		return true;
	}

	// lets check head before traverse
	if(strcmp(temp->first, head->first)<0)
	{
		// insert at beginning
		temp->next = head;
		head = temp;		
		return true;
	}

	return insert_sort(head, temp); // now traverse
	
}

bool LLL::insert_sort(node *& head, node*temp)
{

	if(!head->next) // if we reach the end
	{
		head->next = temp;
		temp->next = NULL;

		return true;
	}
	if(strcmp(temp->first, head->next->first)<0) // compare
	{
		temp->next = head->next;
		head->next = temp;
		
		return true;	
	}
	return insert_sort(head->next, temp); // keep going

}

// ***** Display *****
// Diplay every node in LLL 
// with first name
// ***********************
bool LLL::display()
{
	if(!head) // if not list
	{
		cout << "List is empty" << endl;
		return false;
	}

	return display(head);
}
bool LLL::display(node*head)
{
	if(!head) return false; // base case
	
	cout << head->first << " "; // display first name
	
	return display(head->next);
}

// ***** Display Contact Info *****
// WIll display contact info only
// **********************************
bool LLL::disp_contact()
{
	return disp_contact(head);
}
bool LLL::disp_contact(node*head)
{
	cout << '\n';
	if(head->contact1)
		cout << "Contact 1: " << head->contact1 << endl;
	if(head->contact2)
		cout << "Contact 2: " << head->contact2 << endl;
	if(head->contact3)
		cout << "Contact 3: " << head->contact3 << endl;

	return true;
}


// ***** Remove All *****
// Assist destructor
// and delete every node in lll with info and arrays
// ********************************************
bool LLL::remove_all()
{
	remove_all(head);
	 return true;
}
bool LLL::remove_all(node*&head)
{
	if(!head) return true;
	// removing in the way back

	remove_all(head->next); // traverse to the end
	if(head->first) delete [] head->first; // delete first name
	// Delete contacts
	if(head->contact1) delete [] head->contact1; 
	if(head->contact2) delete [] head->contact2;
	if(head->contact3) delete [] head->contact3;
	if(head) delete head; // delete node
	head = NULL;
	return true;
}

// ***** Destructor // *****
LLL::~LLL()
{
	remove_all(head);

}

// **********************
