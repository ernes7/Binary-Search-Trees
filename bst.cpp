// BST.cpp
// Ernesto Martinez
// ******************
// This file will implement the BST
// class methods.
// ******************
#include "bst.h"

// ********************
// BST class implementation
// ********************

// ***** Constructor *****
BST::BST()
{
	root = NULL; // root to null
}

// ***** Insert *****
// Will insert a last name to the tree node
// and will call the insert lll function 
// to also insert the first name into  the list
// ALL in order
// *****************************************
bool BST::insert(char lastT[], char firstT[], char contact1T[], char contact2T[], char contact3T[])
{
	// memory for bnode
	bnode * current = new bnode;
	current->last = new char[strlen(lastT)+1];
	strcpy(current->last, lastT);
	
	// LLL data
	current->list.insert_sort(firstT, contact1T, contact2T, contact3T);

	return insert(root, current); // call recursive func
}

bool BST::insert(bnode*&root, bnode*current)
{
	if(!root) // base case
	{
		// Add node at leaf of beginning
		root = current;
		// copy data
		root->left = NULL;
		root->right = NULL;
		return true;
	}	
	else if(strcmp(current->last, root->last)<0) // compare
	{
		insert(root->left, current); // go left if less
	}
	else
	{
		insert(root->right, current); // go right if bigger
	}	
	return false;
}


// ***** Display BST  *****
// Will display all the data in the BST
// in order and also the data in each corresponding
// node in the tree which contain a list each one
// ********************************************
bool BST::display()
{
	if(!root) // if not list
	{
		cout << "It is empty" << endl;
		return false;
	}
	display(root); return true; // call recursive func
}

bool BST::display(bnode*root)
{
	if(!root) return false; // base case to stop

	display(root->left); // go all the way left

	// Start displaying
	if(root->list.display())
		cout << root->list.display(); // first name 
	if(root->last)
		cout << root->last; // last name
	root->list.disp_contact();

	cout << endl;

	display(root->right); // now go right

	return true;
}

// ***** Remove ALL BST *****
// Remove entire BST and deallocate arrays
// ***************************************

bool BST::remove_bst(bnode*&root)
{
	if(!root) return true;
	
	remove_bst(root->left);
	remove_bst(root->right);

	if(root->last) // check if exist
		delete [] root->last;
	root->list.remove_all(); // delete list in node
	delete root; // delete root
	root = NULL; // set it to null
	
	return false;
}

// ***** Destructor *****
BST::~BST()
{
	remove_bst(root); // assistance func
}





