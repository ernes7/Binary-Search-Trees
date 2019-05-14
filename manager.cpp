// manager.cpp
// Ernesto Martinez
// **************
// This file will implement
// the methods in the manager class
// and also the methods in the broadcasting
// and emergency class
// ****************
#include "manager.h" 

// CLASS MANAGER IMPLEMENTATION
// **************************

// ***** Constructor *****
manager::manager()
{
	x = 0;
}

// ***** Prompt *****
// Prompt info from user
// ********************
void manager::prompt()
{	
	
	welcome();
	
	// MENU
	do{
		cout << "*****MENU*****" << endl;
		cout << "[0] QUIT!\n";
		cout << "[1] Add Person\n";
		cout << "[2] Display People\n";
		cin >> x;
		cin.ignore(100, '\n');

		if(x == 1)
		{
			cout << "Enter First Name: ";
			cin.get(test1, 30, '\n');
			cin.ignore(100, '\n');

			cout << "Enter Last Name: ";
			cin.get(test, 30, '\n');
			cin.ignore(100, '\n');

			cout << "Enter Contact info 1: ";
			cin.get(con1, 30, '\n');
			cin.ignore(100, '\n');

			cout << "Enter Contact info 2: ";
			cin.get(con2, 30, '\n');
			cin.ignore(100, '\n');

			cout << "Enter Contact info 3: ";
			cin.get(con3, 30, '\n');
			cin.ignore(100, '\n');

			tree.insert(test, test1, con1, con2, con3);
		}
		if(x == 2)
		{
			tree.display();
			cout << '\n';
		}
		
	}while(x != 0);
	
	cout << "BYE" << endl;
}

// ***** Welcome *****
// *******************8
void manager::welcome()
{
	cout << "Welcome to the Broadcasting system program\n";
	cout << "You can add people to a contact list with the way\n to reach them in case of emergency\n"; 
	return;
}
// *******************************
// Broadcast Class Implementation
// *******************************

// ***** Copy Constructor *****
broadcast broadcast::operator + (const broadcast& p) const
{
	broadcast broad;
	broad.count = this->count + p.count;
	if(p.social)
	{
		broad.social = new char[strlen(p.social)+1];
		strcpy(broad.social, p.social);
	}
	return broad;
}

// 
broadcast& broadcast::operator += (const broadcast& p)
{
	count += p.count;
	return *this;
}

// ****Comparison *****
bool broadcast::operator == (const broadcast& p) const
{
	if(count == p.count || strcmp(social, p.social)==0)
		return true;
	else
		return false;
}

// Output operator function
ostream& operator << (ostream& out, const broadcast& p)
{
	out << "Count: " << p.count << "Social: " << p.social;
	return out;
}

// *******************************
// Emergency Class Implementation
// *******************************

// ***** Copy Constructor *****
emergency emergency::operator + (const emergency& e) const
{
	emergency alert;
	alert.people  = this->people + e.people;
	
	return alert;
}

// 
emergency& emergency::operator += (const emergency& e)
{
	people += e.people;
	return *this;
}

// ****Comparison *****
bool emergency::operator == (const emergency& e) const
{
	if(people == e.people)
		return true;
	else
		return false;
}

// Output operator function
ostream& operator << (ostream& out, const emergency& e)
{
	out << "People: " << e.people;
	return out;
}






