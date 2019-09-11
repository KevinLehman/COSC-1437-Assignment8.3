/*
Kevin Lehman  - 1463553
Tarrant County College - COSC 1437- Fall 2017
Assignment 3 - Week 8
*/

#include<iostream>
#include<fstream>
using namespace std;

const int NAME_SIZE = 20;
const int STREET_SIZE = 30;
const int CITY_SIZE = 20;
const int STATE_CODE_SIZE = 3;

struct Customers
{
	long customerNumber;
	char name[NAME_SIZE];
	char streetAddress_1[STREET_SIZE];
	char streetAddress_2[STREET_SIZE];
	char city[CITY_SIZE];
	char state[STATE_CODE_SIZE];
	int zipCode;
	char isDeleted;
	char newLine;
};

long getLastCustomerNumber(fstream &);
void showExistingCustomerData(fstream &);

int main()
{
	Customers newCust;
	char loop = 'n';
	char menuChoice;
	long deleteNum;
	long undeleteNum;
	long lastCust = 0;

	fstream customer("customer.dat", ios::in | ios::out | ios::binary);

	if (customer.fail())
	{
		customer.open("customer.dat", ios::out | ios::binary);
	}
	
	cout << "Menu Options: " << endl;
	cout << "1. Add Customer Data" << endl;
	cout << "2. Show Existing Customer Data" << endl;
	cout << "3. Delete Customer Data" << endl;
	cout << "4. UnDelete Customer Data" << endl;
	cout << "X. Exit" << endl;
	cin >> menuChoice;

	if (menuChoice == '1')
	{
		lastCust = getLastCustomerNumber(customer);
		customer.close();
		customer.open("customer.dat", ios::in | ios::app | ios::binary);
		cin.ignore();
		do
		{

			newCust.customerNumber = (lastCust);
			cout << "Enter new customers name:" << endl;
			cin.getline(newCust.name, NAME_SIZE);
			cout << "Enter new customers address line 1:" << endl;
			cin.getline(newCust.streetAddress_1, STREET_SIZE);
			cout << "Enter new customers address line 2:" << endl;
			cin.getline(newCust.streetAddress_2, STREET_SIZE);
			cout << "Enter new customers city" << endl;
			cin.getline(newCust.city, CITY_SIZE);
			cout << "Enter new customers state code:" << endl;
			cin.getline(newCust.state, STATE_CODE_SIZE);
			cout << "Enter new customers zip code:" << endl;
			cin >> newCust.zipCode;
			cin.ignore();

			newCust.isDeleted = 'N';
			newCust.newLine = '\n';
			customer.write(reinterpret_cast<char *>(&newCust), sizeof(newCust));



			cout << "Would you like to add another new customer? Y for yes and N for no" << endl;
			cin >> loop;
			cin.ignore();
			lastCust++;
		} while (loop == 'Y' || loop == 'y');
	customer.close();
	}
	else if (menuChoice == '2')
	{
		customer.close();
		customer.open("customer.dat", ios::in | ios::binary);
		showExistingCustomerData(customer);
		customer.close();
	}
	else if (menuChoice == '3')
	{
		customer.close();
		customer.open("customer.dat", ios::in | ios::out | ios::ate | ios::binary);
		cout << "Enter a customer number you wish to delete: " << endl;
		cin >> deleteNum;

		while (!customer.eof())
		{
			customer.read(reinterpret_cast<char *>(&newCust), sizeof(newCust));
			if (!customer.eof())
			{
				if (newCust.customerNumber == deleteNum)
				{
					if (newCust.isDeleted == 'N')
					{
						
						newCust.customerNumber = newCust.customerNumber;
						for (int idx = 0; idx < NAME_SIZE; idx++)
						{
							newCust.name[idx] = newCust.name[idx];
						}
						for (int idx1 = 0; idx1 < STREET_SIZE; idx1++)
						{
							newCust.streetAddress_1[idx1] = newCust.streetAddress_1[idx1];
						}
						for (int idx2 = 0; idx2 < STREET_SIZE; idx2++)
						{
							newCust.streetAddress_2[idx2] = newCust.streetAddress_2[idx2];
						}
						for (int idx3 = 0; idx3 < CITY_SIZE; idx3++)
						{
							newCust.city[idx3] = newCust.city[idx3];
						}
						for (int idx4 = 0; idx4 < STATE_CODE_SIZE; idx4++)
						{
							newCust.state[idx4] = newCust.state[idx4];
						}

						newCust.zipCode = newCust.zipCode;
						newCust.isDeleted = 'Y';
						newCust.newLine = '\n';
						customer.write(reinterpret_cast<char *>(&newCust), sizeof(newCust));
						cout << "Customer Number " << deleteNum << " found to delete." << endl;
					}
					if (newCust.isDeleted == 'Y')
					{
						cout << "Customer is already deleted." << endl;
					}
				}
				else
				{
					cout << "Customer Number " << deleteNum << " not found to delete." << endl;
				}
			}
		}
	customer.close();
	}
	else if (menuChoice == '4')
	{
		customer.close();
		customer.open("customer.dat", ios::in | ios::out | ios::binary);
		cout << "Enter a customer number you wish to undelete: " << endl;
		cin >> undeleteNum;

		while (!customer.eof())
		{
			customer.read(reinterpret_cast<char *>(&newCust), sizeof(newCust));
			if (newCust.customerNumber == undeleteNum)
			{
				if (newCust.isDeleted == 'N')
				{
					cout << "Customer is already not deleted." << endl;
				}
				if (newCust.isDeleted == 'Y')
				{
					newCust.customerNumber = newCust.customerNumber;
					for (int idx = 0; idx < NAME_SIZE; idx++)
					{
						newCust.name[idx] = newCust.name[idx];
					}
					for (int idx1 = 0; idx1 < STREET_SIZE; idx1++)
					{
						newCust.streetAddress_1[idx1] = newCust.streetAddress_1[idx1];
					}
					for (int idx2 = 0; idx2 < STREET_SIZE; idx2++)
					{
						newCust.streetAddress_2[idx2] = newCust.streetAddress_2[idx2];
					}
					for (int idx3 = 0; idx3 < CITY_SIZE; idx3++)
					{
						newCust.city[idx3] = newCust.city[idx3];
					}
					for (int idx4 = 0; idx4 < STATE_CODE_SIZE; idx4++)
					{
						newCust.state[idx4] = newCust.state[idx4];
					}

					newCust.zipCode = newCust.zipCode;
					newCust.isDeleted = 'N';
					customer.write(reinterpret_cast<char *>(&newCust), sizeof(newCust));
					cout << "Customer Number " << undeleteNum << " found to undelete." << endl;
				}
			}
			else
			{
				cout << "Customer Number " << undeleteNum << " not found to undelete." << endl;
			}
		}
		customer.close();
	}
	else if (menuChoice == 'X' || menuChoice == 'x')
	{
		customer.close();
		system("PAUSE");
		return 0;
	}
	customer.close();
	system("PAUSE");
	return 0;
}

long getLastCustomerNumber(fstream &customer)
{
	Customers currentCust;
	long custCurrent;
	long lastCustNum = 0;


	while (!customer.eof())
	{
		customer.read(reinterpret_cast<char *>(&currentCust), sizeof(currentCust));
		custCurrent = currentCust.customerNumber;
		if (lastCustNum < custCurrent)
		{
			lastCustNum = custCurrent;
		}
		
	}
	lastCustNum++;
	return lastCustNum;
}

void showExistingCustomerData(fstream &customer)
{
	Customers currentC;
	
	while (!customer.eof())
	{
		customer.read(reinterpret_cast<char *>(&currentC), sizeof(currentC));
		if(!customer.eof())
		{
			cout << "Customer Number: " << currentC.customerNumber << endl;
			cout << "Customer Name: " << currentC.name << endl;
			cout << "Customer Address Line #1: " << currentC.streetAddress_1 << endl;
			cout << "Customer Address Line #2: " << currentC.streetAddress_2 << endl;
			cout << "Customer City: " << currentC.city << endl;
			cout << "Customer State Code: " << currentC.state << endl;
			cout << "Customer Zip Code: " << currentC.zipCode << endl;
			cout << "Customers delete status: " << currentC.isDeleted << endl;
			
			if (currentC.isDeleted == 'N')
			{
				cout << " Customer has not already been deleted." << endl;
			}
			else
			{
				cout << " Customer has already been deleted." << endl;
			}
		}
	}
}