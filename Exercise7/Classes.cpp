#include <iostream>
#include <string>
#include <vector>
#include <format>
#include <fstream>

using namespace std;

namespace Library_Methods {

	class Book
	{
	public:
		Book();
		Book(string var1, string var2, int var3);
		string getTitle();
		string getAuthor();
		int getISBN();

	private:
		string title;
		string author;
		int ISBN;
	};

	Book::Book()
	{
		title = "";
		author = "";
		ISBN = 0;
	}

	Book::Book(string var1, string var2, int var3)
	{
		this->title = var1;
		this->author = var2;
		this->ISBN = var3;
	}

	string Book::getTitle() {
		return title;
	}

	string Book::getAuthor() {
		return author;
	}

	int Book::getISBN() {
		return ISBN;
	}

	class Library
	{
	public:
		Library();
		void addBook(Book item);
		void removeBook(int item_ISBN);
		void viewBooks();
		void safeLibrary();
		vector<Book> getCollection();

	private:
		vector<Book> collection;
	};

	Library::Library()
	{
	}

	void Library::addBook(Book item)
	{
		collection.push_back(item);
		//cout << format("El libro {} ha sido añadido exitosamente.", item.getTitle());
	}

	void Library::removeBook(int item_ISBN)
	{
		int removed{ 0 };
		for (int i = 0; i < collection.size(); i++)
		{
			if (collection[i].getISBN() == item_ISBN)
			{
				collection.erase(collection.begin() + i);
				removed = 1;
			}
		}
		if (removed == 0)
		{
			cout << format("El elemento con el ISBN {} no se encuentra en el inventario.", item_ISBN);
		}
	}

	void Library::viewBooks()
	{
		for (int i = 0; i < collection.size(); i++)
		{
			string title = collection[i].getTitle();
			string author = collection[i].getAuthor();
			int ISBN = collection[i].getISBN();
			cout << format("Book #{}\n Title: {}\n Author: {}\n ISBN: {}\n\n", i + 1, title, author, ISBN);
		}
	};

	void Library::safeLibrary()
	{
		ofstream output_file("library.csv");
		if (output_file) {
			for (int i = 0; i < collection.size(); i++) {
				string title = collection[i].getTitle();
				string author = collection[i].getAuthor();
				int ISBN = collection[i].getISBN();
				output_file << title << ',' << author << ',' << ISBN << ',' << endl;
			}
			output_file.close(); // Cierra el archivo
			cout << "El archivo se ha guardado correctamente." << std::endl;
		}
		else {
			cout << "Error al guardar el archivo" << endl;
		}
	}

	vector<Book> Library::getCollection() {
		return collection;
	}
}