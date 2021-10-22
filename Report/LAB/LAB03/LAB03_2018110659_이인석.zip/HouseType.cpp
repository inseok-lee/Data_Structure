#include "ItemType.h"




// ItemType.cpp is the implementation file for data for the real 
//  estate manipulation program.

void HouseType::GetFromFile(std::ifstream& file)
{
	lastName.GetStringFile(true, NOT_NEW, file);
	firstName.GetStringFile(true, NOT_NEW, file);
	address.GetStringFile(true, NOT_NEW, file);
	file >> price >> squareFeet >> bedRooms;
}

void HouseType::WriteToFile(std::ofstream& file)
{
	using std::endl;
	lastName.PrintToFile(false, file);
	firstName.PrintToFile(true, file);
	address.PrintToFile(true, file);
	file << endl << price << endl;
	file << squareFeet << endl;
	file << bedRooms << endl;
}

void HouseType::GetFromUser()
{
	using namespace std;
	cout << "Enter last name; press return." << endl;
	lastName.GetString(true, NOT_NEW);
	cout << "Enter first name; press return." << endl;
	firstName.GetString(true, NOT_NEW);
	cout << "Enter address; press return." << endl;
	address.GetString(true, NOT_NEW);
	cout << "Enter price, square feet, number of bedrooms, number of bathrooms;"			//추가.
		<< " press return." << endl;
	cin >> price >> squareFeet >> bedRooms>>bathRooms;			//추가.
}

void HouseType::PrintHouseToScreen()
{
	using namespace std;
	firstName.PrintToScreen(false);
	cout << " ";
	lastName.PrintToScreen(false);
	address.PrintToScreen(true);
	cout << endl << "Price: " << price << endl;
	cout << "Square Feet: " << squareFeet << endl;
	cout << "Bedrooms: " << bedRooms << endl;
	cout << "Bathrooms: " << bathRooms << endl;				//추가함.
}

void HouseType::GetNameFromUser()
{
	using namespace std;
	cout << "Enter last name;  press return." << endl;
	lastName.GetString(true, NOT_NEW);
	cout << "Enter first name;  press return." << endl;
	firstName.GetString(true, NOT_NEW);
}

void HouseType::PrintNameToScreen()
{
	using namespace std;
	firstName.PrintToScreen(false);
	cout << " ";
	lastName.PrintToScreen(false);
	cout << endl;
}

bool HouseType::operator<(const HouseType& other) {			// B번.
	if (this->lastName < other.lastName || this->firstName < other.firstName)				// 멤버함수가 작을시 true 반환.
		return true;
	else if (other.lastName < this->lastName || other.firstName < this->firstName)			// 멤버함수가 클시 false 반환.
		return false;
}

bool HouseType::operator==(const HouseType& other) {			// B번.
	if (this->lastName == other.lastName && this->firstName == other.firstName)
		return true;
	else		// 멤버함수가 클시 false 반환.
		return false;
}





RelationType HouseType::ComparedTo(HouseType house)
{
	if (*this == house) { return EQUAL; }
	else if (*this < house) { return LESS; }
	else { return  GREATER; }
}


/*
RelationType HouseType::ComparedTo(HouseType house)
{
	if (lastName < house.lastName)
		return LESS;
	else if (house.lastName < lastName)
		return GREATER;
	else if (firstName < house.firstName)
		return LESS;
	else if (house.firstName < firstName)
		return GREATER;
	else return EQUAL;
}
*/

