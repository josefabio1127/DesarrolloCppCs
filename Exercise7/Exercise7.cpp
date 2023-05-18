#include <iostream>
#include <string>
#include <format>
#include <fstream>
#include <sstream>
#include "Classes.h"

using namespace std;
using namespace Library_Methods;

int add_book(Library& library1)
{
	string title{ "" };
	string author{ "" };
	int ISBN{ 0 };
	string ISBN_str{ 0 };
	cout << "Type the data of the book\n";
	cout << "Title: ";
	cin >> title;
	cout << "Author: ";
	cin >> author;
	cout << "ISBN: ";
	cin >> ISBN_str;

	try {
		ISBN = stoi(ISBN_str);
		Book book1(title, author, ISBN);
		library1.addBook(book1);
		return 1;
	}
	catch (const invalid_argument& e) {
		cout << "ISBN debe ser un número entero";
		return 0;
	}	
}

Library open_library()
{
	Library library;
	ifstream file("library.csv");
	if (file)
	{
		string linea;
		while (getline(file, linea)) {
			
			string title{ "" };
			string author{ "" };
			int ISBN{ 0 };
			char coma;
			istringstream ss(linea);
			if (getline(ss, title, ',') && getline(ss, author, ',') && (ss >> ISBN) && (ss >> coma)) {
				Book book1(title, author, ISBN);
				library.addBook(book1);
			}
			else
			{
				cout << "Incorrect format in file, can't read the data";
			}
		}
		file.close();
		return library;
	}
}

int main()
{
	while (true)
	{
		Library library = open_library();
		int choose{ 0 };
		cout << "\nWelcome to the library!\n";
		cout << "1- View all the books.\n";
		cout << "2- Add a book.\n";
		cout << "3- Remove a book\n";
		cout << "0- Exit.\n";
		cout << "Option: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			library.viewBooks();
			break;
		case 2:
		{
			while (true)
			{
				int correct = add_book(library);
				if (correct)
				{
					library.viewBooks();
					library.safeLibrary();
					int cont{ 0 };
					cout << "Press 1 if you want to add another book, if no press 0: ";
					cin >> cont;
					if (not cont)
					{
						break;
					}
				}
				else {
					break;
				}
				
			}
			break;
		}
		case 3:
		{
			int isbn_remove{ 0 };
			cout << "Write the ISBN of the book that you want to remove.\nISBN: ";
			cin >> isbn_remove;
			library.removeBook(isbn_remove);
			library.safeLibrary();
			break;
		}
		case 0:
		{
		default:
			cout << "Done!\n";
			return 0;
		}
		}
	}
}
