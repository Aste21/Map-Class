#include "Employee.h" // Defines class Employee
#include "Map.h"
#include "Book.h"
typedef unsigned int ID;			// Identification number of employee
typedef Map<ID, Employee> Database; // Database of employees
typedef std::string Title;
typedef Map<Title, Book> Library; // Database of books in the library

using namespace std;

void addEmployees(Database &database);
void modifyEmployees(Database &database);
void addBooks(Library &library);
void modifyBooks(Library &library);

int main()
{
	Database database;
	addEmployees(database);

	Database newDatabase = database;									// Make a copy of database
	newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43)); // Add fourth employee
	modifyEmployees(newDatabase);

	cout << "Original database:" << endl
		 << database << endl;
	cout << "Modified database:" << endl
		 << newDatabase << endl;

	database = newDatabase; // Update original database

	cout << "Database after the assignment:" << endl
		 << database << endl;

	addEmployees(database);

	cout << "Database after adding already existing keys:" << endl
		 << database << endl;



	cout <<"Test of finding inexisting key:" << endl;
	try
	{
		database.find(123);
		cout << "Exception thrown and catched incorrectly." << endl << endl;
	}
	catch(const OutOfRangeException e)
	{
		cout << "Exception thrown and catched correctly." << endl << endl;
	}
	

	Library library;

	// Test Book Addition
	addBooks(library);

	cout << "Original library:" << endl
		 << library << endl;

	Library newLibrary = library;

	newLibrary.add("The Great Gatsby", Book("F. Scott Fitzgerald", "Classic", 180, true));

	// Test Book Modification
	modifyBooks(newLibrary);

	// Print the library after modification
	std::cout << "Library Contents after Modification:" << std::endl;
	std::cout << newLibrary << std::endl;

	library = newLibrary;
	cout << "Library after the assignment:" << endl
		 << library << endl;
}

void addEmployees(Database &database)
{
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28));	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54)); // Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32)); // Add third employee
}

void modifyEmployees(Database &database)
{
	Employee *employeePtr;

	employeePtr = database.find(510212881); // Find employee using its ID
	employeePtr->position = "salesman";		// Modify the position of employee

	employeePtr = database.find(761028073); // Find employee using its ID
	employeePtr->age = 29;					// Modify the age of employee
}

void addBooks(Library &library)
{
    // Add books to the library
    library.add("The Catcher in the Rye", Book("J.D. Salinger", "Fiction", 224, false));
    library.add("To Kill a Mockingbird", Book("Harper Lee", "Classic", 281, true));
    library.add("1984", Book("George Orwell", "Dystopian", 328, false));
}

void modifyBooks(Library &library)
{
    // Find and modify a book
    Book *bookPtr = library.find("The Catcher in the Rye");
    if (bookPtr != nullptr)
    {
        bookPtr->isBorrowed = true;
    }
}