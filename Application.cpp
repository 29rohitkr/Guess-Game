// Basic User Mgmt using struct 
#include <bits/stdc++.h>
using namespace std;

struct Person{
	int age = 0;
	string name = "";
};

vector<Person> records;

void AddRecord(string newName, int newAge)
{
	Person newRecord;
	newRecord.name = newName;
	newRecord.age = newAge;
	records.push_back(newRecord);
	cout << "\nUser record added successfully.\n\n";
}

Person FetchRecord(int UserId)
{
	return records.at(UserId);
}

int main()
{
	cout << "User SignUp Application\n" << endl;
	bool IsRunning = true;
	while(IsRunning){
		cout << "Please select an option:\n";
		cout << "1: Add Record\n";
		cout << "2: Fetch Record\n";
		cout << "3: Quit\n\n";
		cout << "Enter option: ";
		string inputString;
		getline(cin, inputString);
		switch (stoi(inputString)){
			case 1:
				{
					string name = "";
					int age = 0;
					cout << "\nAdd User. Please enter user name and age:";
					cout << "\nName: ";
					getline(cin, name);
					cout << "Age: ";
					getline(cin, inputString);
					age = stoi(inputString);
					AddRecord(name, age);
				}
				break;
			case 2:
				{
					int UserId =0;
					cout << "\n\nPlease enter user ID:\n";
					cout << "User ID: ";
					getline(cin, inputString);
					UserId = stoi(inputString);
					Person person;
					try 
					{
						person = FetchRecord(UserId);
						cout << "User Name: " << person.name << "\n";
						cout << "User Age: " << person.age << "\n\n";
	
					}
					catch(const out_of_range& oor)
					{
						cout << "\nError: Invalid User Id.\n\n";
					}
					//cout << "User Name: " << person.name << "\n";
					//cout << "User Age: " << person.age << "\n\n";

				}	

				break;
			case 3:
				IsRunning = false;
				break;
			default:
				cout << "\nInvalid Option Selection.\n\n";
				break;
		}
	}
}
