/* Assignment: 4
Campus: Beer Sheva
Author: Freddy Maidanik, ID: 310017280
*/

// This is the .cpp file of the school.

#include "School.h"
#include <typeinfo>

// This is the ctor. Here I build the school with layers and classes.
School::School(){
	NumOfPersons = 0;
	OneManager = false;
	Persons = new Person*[NumOfPersons];
	Layers = new Layer*[NumOfLayers];
	char tav = 'a';
	for (int i = 0; i < NumOfLayers; i++) {
		Layers[i] = new Layer(tav);
		tav++;
	}
}

// This is the dtor.
School::~School(){
	for (int i = 0; i < NumOfLayers; i++)
		delete Layers[i];
	delete[] Layers;
	for (int i = 0; i < NumOfPersons; i++)
		delete Persons[i];
	delete[] Persons;
}

// This function makes a new place for a person on the array.
void School::addPerson() {
	Person** tmpPersons = new Person*[NumOfPersons]; // Build a tmp array of persons.
	for (int i = 0; i < NumOfPersons; i++) // Move the persons to the tmp array.
		tmpPersons[i] = dynamic_cast<Person*>(Persons[i]);
	NumOfPersons++;
	Persons = new Person*[NumOfPersons]; // Make the array bigger and move them back.
	for (int i = 0; i < NumOfPersons - 1; i++) {
		if(tmpPersons[i] != NULL)
			Persons[i] = tmpPersons[i];
	}
}

// This is the menu function. From here I control everything at the school.
void School::Menu() {
	int n = -1;
	cout << "Welcome to the School, here are your options:" << endl;
	do { // Run the school as long as you won't press 10.
		cout << "1. Add pupil." << endl;
		cout << "2. Add teacher." << endl;
		cout << "3. Add tutor." << endl;
		cout << "4. Add manager." << endl;
		cout << "5. Add secretary." << endl;
		cout << "6. Print workers and pupil details." << endl;
		cout << "7. Print outstanding people." << endl;
		cout << "8. Print tutor's class." << endl;
		cout << "9. Print Worker details with the biggest salary." << endl;
		cout << "10. Exit." << endl;
		cin >> n;
		if (n == 1) { // Add pupil.
			bool flag = true;
			char layer;
			int nclass, id;
			string first, last;
			cout << "Please enter the id of the pupil: ";
			cin >> id;
			for (int i = 0; i < NumOfPersons; i++) // Check if the id is not taken.
				if (Persons[i]->getPersonId() == id) {
					flag = false;
					break;
				}
			if (flag == true) { // If the id is not taken.
				cout << "Please enter the first name of the pupil: ";
				cin >> first;
				cout << "Please enter the last name of the pupil: ";
				cin >> last;
				cout << "Please enter the layer you want to add the pupil to ('a' - 'f'): ";
				cin >> layer;
				if (layer < 'a' || layer > 'f') { // If not ('a' - 'f').
					do
					{
						cout << "Wrong choice, try again ('a' - 'f'): ";
						cin >> layer;
					} while (layer < 'a' || layer > 'f');
				}
				cout << "Please enter the class you want to add the pupil to (1 - 3): ";
				cin >> nclass;
				if (nclass < 1 || nclass > 3) { // If not (1 - 3).
					do
					{
						cout << "Wrong choice, try again (1 - 3): ";
						cin >> nclass;
					} while (nclass < 1 || nclass > 3);
				}
				int numOfGrades = ((int)layer) - 92;
				int* grades = new int[numOfGrades]; // Build an array of grades.
				for (int i = 0; i < numOfGrades; i++) { // Add grades according to layer.
					cout << "Enter the grade for the student at place " << i + 1 << ": ";
					cin >> grades[i];
					if (grades[i] < 0 || grades[i] > 100) { // If not (0 - 100).
						do
						{
							cout << "Wrong choice, try again (0 - 100): ";
							cin >> grades[i];
						} while (grades[i] < 0 || grades[i] > 100);
					}
				}
				addPerson(); // Make place for the pupil in the array of persons.
				Persons[NumOfPersons - 1] = new Pupil(first, last, id, layer, nclass, numOfGrades, grades);
				Pupil *p = new Pupil(first, last, id, layer, nclass, numOfGrades, grades); // Make a new pupil.
				Layers[(int)layer - 97]->returnClass(nclass)->addPupil(p); // Add him to his class.
				cout << "Added a pupil." << endl;
			}
			if(flag == false) // If the id is taken.
				cout << "Sorry, we have someone with this id." << endl;
		}
		else if (n == 2) { // Add teacher.
			bool flag = true;
			int nclass, id, nwork;
			string first, last;
			string* names = NULL;
			cout << "Please enter the id of the teacher: ";
			cin >> id;
			for (int i = 0; i < NumOfPersons; i++) // Check if the id is taken.
				if (Persons[i]->getPersonId() == id) {
					flag = false;
					break;
				}
			if (flag == true) { // The id is not taken.
				cout << "Please enter the first name of the teacher: ";
				cin >> first;
				cout << "Please enter the last name of the teacher: ";
				cin >> last;
				cout << "Please enter the years the teacher teaches: ";
				cin >> nwork;
				cout << "Please enter the number of classes the teacher teaches: ";
				cin >> nclass;
				if (nclass != 0) { // Add classes to the teacher.
					names = new string[nclass];
					cout << "Now enter the teacher's name of classes: " << endl;
					for (int i = 0; i < nclass; i++) {
						cout << i + 1 << ". ";
						cin >> names[i];
					}
				}
				addPerson(); // Make place for the teacher in the array and add him.
				Persons[NumOfPersons - 1] = new Teacher(first, last, id, nwork, nclass, names);
				cout << "Added a teacher." << endl;
			}
			if (flag == false) // Id is taken.
				cout << "Sorry, we have someone with this id." << endl;
		}
		else if (n == 3) { // Add tutor.
			bool flag = true;
			int nclass, id, nwork, clas;
			char layer;
			string first, last;
			string* names = NULL;
			Class *c;
			Tutor *t;
			cout << "Please enter the id of the tutor: ";
			cin >> id;
			for (int i = 0; i < NumOfPersons; i++) { // Check if id is taken.
				if (Persons[i]->getPersonId() == id) {
					flag = false;
					break;
				}
			}
			if (flag == true) { // Id is not taken.
				cout << "Please enter the first name of the tutor: ";
				cin >> first;
				cout << "Please enter the last name of the tutor: ";
				cin >> last;
				cout << "Please enter the years the teacher tutor: ";
				cin >> nwork;
				cout << "Please enter the number of classes the tutor teaches: ";
				cin >> nclass;
				if (nclass != 0) { // Add classes to the teacher.
					names = new string[nclass];
					cout << "Now enter the tutor's name of classes: " << endl;
					for (int i = 0; i < nclass; i++) {
						cout << i + 1 << ". ";
						cin >> names[i];
					}
				}
				cout << "Now enter the layer of the tutor's class ('a' - 'f'): ";
				cin >> layer;
				if (layer < 'a' || layer > 'f') { // If not ('a' - 'f').
					do
					{
						cout << "Wrong choice, try again ('a' - 'f'): ";
						cin >> layer;
					} while (layer < 'a' || layer > 'f');
				}
				cout << "Now enter the number of class of the tutor (1 - 3): ";
				cin >> clas;
				if (clas < 1 || clas > 3) { // If not (1 - 3).
					do
					{
						cout << "Wrong choice, try again (1 - 3): ";
						cin >> clas;
					} while (clas < 1 || clas > 3);
				}
				c = Layers[(int)layer - 97]->returnClass(clas);
				if (c->checkTutor()) {
					addPerson(); // Make place for the tutor at the array of the persons and add him.
					Persons[NumOfPersons - 1] = new Tutor(first, last, id, nwork, nclass, names, c);
					t = dynamic_cast<Tutor*>(Persons[NumOfPersons - 1]);
					if (t != NULL) // Downcast the tutor and add him to his class.
						Layers[(int)layer - 97]->returnClass(clas)->addTutor(t);
					cout << "Added a tutor." << endl;
				}
				else
					cout << "We have a tutor at this class already." << endl;
			}
			if (flag == false) // Id is taken.
				cout << "Sorry, we have someone with this id." << endl;
		}
		else if (n == 4) { // Add manager.
			if (!OneManager) { // If no manager is present.
				bool flag = true;
				int id, nwork;
				string first, last;
				cout << "Please enter the id of the manager: ";
				cin >> id;
				for (int i = 0; i < NumOfPersons; i++) // Check if id is taken.
					if (Persons[i]->getPersonId() == id) {
						flag = false;
						break;
					}
				if (flag == true) { // Id is not taken and we don't have a manager yet.
					cout << "Please enter the first name of the manager: ";
					cin >> first;
					cout << "Please enter the last name of the manager: ";
					cin >> last;
					cout << "Please enter the years the manager works: ";
					cin >> nwork;
					addPerson(); // Make space for the manager at the array of persons and add him.
					Persons[NumOfPersons - 1] = new Manager(first, last, id, nwork);
					cout << "Added a manager." << endl;
					OneManager = true;
				}
				if (flag == false) // Id is taken.
					cout << "Sorry, we have someone with this id." << endl;
			}
			else // If found a manager.
				cout << "We have a manager already." << endl;
		}
		else if (n == 5) { // Add secretary.
			bool flag = true;
			int nkids, id, nwork;
			string first, last;
			cout << "Please enter the id of the secretary: ";
			cin >> id;
			for (int i = 0; i < NumOfPersons; i++) // Check if the id is taken.
				if (Persons[i]->getPersonId() == id) {
					flag = false;
					break;
				}
			if (flag == true) { // Id is not taken.
				cout << "Please enter the first name of the secretary: ";
				cin >> first;
				cout << "Please enter the last name of the secretay: ";
				cin >> last;
				cout << "Please enter the years the secretary works: ";
				cin >> nwork;
				cout << "Please enter how many kids the secretary have: ";
				cin >> nkids;
				addPerson(); // Make space for the secretary at the array of persons and add her.
				Persons[NumOfPersons - 1] = new Secretary(first, last, id, nwork, nkids);
				cout << "Added a secretary." << endl;
				OneManager = true;
			} // Id is taken.
			if (flag == false)
				cout << "Sorry, we have someone with this id." << endl;
		}
		else if (n == 6) { // Print all persons.
			for (int i = 0; i < NumOfPersons; i++) {
				cout << "----------------------------------------" << endl;
				Persons[i]->printPerson(); // Print the person.
				cout << endl;
			}
		}
		else if (n == 7) { // Print outstanding people.
			for (int i = 0; i < NumOfPersons; i++) {
				if (Persons[i]->isExcellent()) { // If the person is excellent.
					cout << "-------------------------------------------" << endl;
					cout << "Excellent person:" << endl;
					Persons[i]->printPerson();
					cout << endl;
				}
			}
		}
		else if (n == 8) { // Print tutor's class.
			Tutor *t;
			int id;
			bool flag = false;
			cout << "Please enter the id of the tutor you want: ";
			cin >> id;
			for (int i = 0; i < NumOfPersons; i++) {
				t = dynamic_cast<Tutor*>(Persons[i]); // Downcast the person and check if tutor.
				if (t != NULL) {
					if (id == Persons[i]->getPersonId()) { // If the id is okay, print his class.
						t->PrintClass();
						flag = true;
					}
				}
			}
			if (!flag) // If not found.
				cout << "No tutor with this id." << endl;
		}
		else if (n == 9) { // Print worker details with biggest salary.
			int index = 0;
			float check = 0;
			Worker *w;
			bool flag = false;
			for (int i = 0; i < NumOfPersons; i++) {
				w = dynamic_cast<Worker*>(Persons[i]); // Downcast the person.
				if (w != NULL) { // If found a worker.
					if (w->getCheck() > check) { // If his salary is bigger.
						check = w->getCheck();
						index = i;
						flag = true;
					}
				}
			}
			if (!flag) // If not found a worker.
				cout << "No workers yet." << endl;
			if (flag) { // If found at least one, print him.
				cout << "The worker with the biggest salary is: " << endl;
				Persons[index]->printPerson();
				cout << endl;
			}
		}
		else if (n == 10) // Exit.
			continue;
		else // Wrong choice.
			cout << "Wrong Choice." << endl;
		system("pause");
		system("cls");
	} while (n != 10); // End.
	cout << "Thank you and goodbye." << endl;
}
