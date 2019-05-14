// bst.h
// Ernesto Martinez
// ***************
// File purpose is to declare
// the classes which will manage
// the data structures
// ***************
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

// Struct holding the data inside node
struct node
{
	node*next;
	char * first; // first name

	// Ways to contact person
	char * contact1;
	char * contact2;
	char * contact3;
};

// This class will manage the LLL of first names plus the info
class LLL
{
public:
	LLL(); // default constructor

	//  Insert function
	bool insert_sort(char hold[], char hold1[], char hold2[], char hold3[]);
	bool insert_sort(node*&head, node*temp);
	
	//  Display Function
	bool display();
	bool display(node*head);

	// Display contact info
	bool disp_contact();
	bool disp_contact(node*head);

	// Remove all nodes
	bool remove_all();
	bool remove_all(node*&head);
	~LLL(); // Destructor
private:

	node * head; // head pointer of list
};

// Struct holds info inside bst node
struct bnode
{
	bnode*left;
	bnode*right;
	char * last; // last name
	LLL list; // object of list
};

// BST class will manage all the BST operations
class BST
{
public:
	BST(); // constructor

	// Insert into BST in sorted order
	bool insert(char lastT[], char firstT[], char contact1T[], char contact2T[], char contact3T[]);
	bool insert(bnode*&root, bnode*current); // insert

	// remove all
	bool remove_bst(bnode*&root);
	// display
	bool display();
	bool display(bnode*root);

	// destructor
	~BST();
private:
	bnode*root; // root
};
