#include <string>
#include <vector>

using namespace std;

namespace Library_Methods {

	class Book 
	{
	public:
		Book();
		Book(string title, string author, int ISBN);
		string getTitle();
		string getAuthor();
		int getISBN();

	private:
		string title;
		string author;
		int ISBN;
	};

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
};
	

