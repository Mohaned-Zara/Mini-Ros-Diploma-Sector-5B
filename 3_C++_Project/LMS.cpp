#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// Book class 
class Book{
    protected:
        string title,author,isbn;
        bool isAvailable;
    public:
        //ctor
        Book(string t,string a,string isbn,bool isAva=true)
        :title(t),author(a),isbn(isbn),isAvailable(isAva){}   
        
        //setter
        void setTitle(string t) { title = t; }
        void setAuthor(string a) { author = a; }
        void setISBN(string i) { isbn = i; }
        void setAvailabile(bool isAva){isAvailable=isAva;}

        //getter
        string getTitle(){return title;}
        string getAuthor(){return author;}
        string getIsbn(){return isbn;}
        bool getIsAvailabile(){return isAvailable;}

        void displayBookDetails(){
            cout<<"Title: "<<title<<", Author: "<<author<<"\n"
            <<"[ISBN"<<isbn<<"]\n"
            <<"Is it Available?"<<"\n"
            << (isAvailable? "YES!" : "No")<<"\n"<<endl;
        }
//todo Store all books using a std::vector<std::shared_ptr<Book>>.
};

// BorrowRecord class
class BorrowRecord{
    private:
        shared_ptr<Book> book_ptr;
        int borrowID;
        string dueDate;
    public:
        //ctor
        BorrowRecord(shared_ptr<Book>temp,int idb,string dd)
        :book_ptr(temp),borrowID(idb),dueDate(dd){}

        //getter
        shared_ptr<Book> getBook_ptr(){return book_ptr;}
        int getBorrowID(){return borrowID;}
        string getDueDate(){return dueDate;}

        void dispalyBorrowRecordDetails(){
            cout << "Borrower ID: " << borrowID<<"\n"
            << "Book_Isbn:" << book_ptr->getIsbn()<<"\n"
            <<"Title: "<<book_ptr->getTitle()<<"\n"
            << "Due: " << dueDate << "\n";
        }

        //distor
        ~BorrowRecord(){}
//todo 3.2 Each "Member" has a (vector<std::shared_ptr<BorrowRecord>>) to track their borrowed books.
//keda haroh7 ahtoha fi el class member
};

// User Class
class User{
    protected:
        string name;
        int id;
    public:
        User(string n, int i):name(n),id(i){}   //ctor
        virtual void displayMenu()=0;           //pure virtual fun
        
        //getter
        string getName(){return name;}
        int getId(){return id;}

        virtual ~User(){}                       //virtual distor
    };

// Librarian Class
//todo Can add/remove books and view borrowed books
class Librarian:public User{
    public:
        vector<shared_ptr<Book>> &books; //! should i put "&" ? --> aiwa ya 7loof
        //ctor
        Librarian(string n, int i, vector<shared_ptr<Book>> &b)
        :User(n,i),books(b){}
        
        void addnewbook(string title, string author, string isbn){
            shared_ptr<Book> b = make_shared<Book>(title, author, isbn);
            books.push_back(b);
            cout << "Book added successfully!\n";
        }

        void removebooks(string isbn){        
            for(int i=0;i<books.size();i++){
                shared_ptr<Book> temp = books[i];
                if (temp->getIsbn()==isbn)
                {
                    books.erase(books.begin()+i); 
                    cout << "Book removed successfully!\n";
                }
            }
            cout << "Book not found!\n";
        }
            
        void ViewAll_Books(){
            cout << "\n--- All Books ---\n";
            for (int i = 0; i < books.size(); i++) {
                books[i]->displayBookDetails();
            }
            cout << "-----------------\n";
        } 
        void displayMenu() override {
            int choice;
            string title, author, isbn;
            do {
                cout << "\n===== Librarian Menu =====\n";
                cout << "1. Add Book\n2. Remove Book\n3. View All Books\n0. Exit\n";
                cin >> choice;
                cin.ignore();

                if (choice == 1) {
                    cout << "Title: "; getline(cin, title);
                    cout << "Author: "; getline(cin, author);
                    cout << "ISBN: "; getline(cin, isbn);
                    addnewbook(title, author, isbn);
                } else if (choice == 2) {
                    cout << "ISBN: "; getline(cin, isbn);
                    removebooks(isbn);
                } else if (choice == 3) {
                    ViewAll_Books();
                }

            } while (choice != 0);
        }
        
        //distor
        ~Librarian(){};
};

// Member Class
//todo Can borrow/return books and view available books
class Member:public User{
    private:
        vector<shared_ptr<BorrowRecord>> borrowedBooks;
        vector<shared_ptr<Book>> &books; //! should i put & ??
    public:
        //ctor
        Member(string n,int i,vector<shared_ptr<Book>> &b)\
        :User(n,i),books(b){}
        
        //borrow
        void borrowBook(string isbn){
            for (int i = 0; i < books.size(); i++) {
                shared_ptr<Book> temp = books[i];
                if (temp->getIsbn() == isbn) {
                    if (temp->getIsAvailabile()){
                        temp->setAvailabile(false);
                        borrowedBooks.push_back(make_shared<BorrowRecord>(temp,id,"2035"));
                        cout << "Book borrowed successfully!\n";
                    } else {
                        cout << "Book not found!n";
                    }
                }
                break;   
            }
        }
        
        //retrun
        void returnbook(string isbn){
            for (int i = 0; i < borrowedBooks.size(); i++)
            {
                shared_ptr<BorrowRecord> record = borrowedBooks[i];
                shared_ptr<Book> book = record->getBook_ptr();
                if (book->getIsbn() == isbn) {
                    borrowedBooks.erase(borrowedBooks.begin() + i);
                    cout << "Book returned!\n";
                    break;
                }
            }
            cout << "No such book borrowed!\n";
        }

        void viewMyBooks(){
            for (int i = 0; i < borrowedBooks.size(); i++)
            {
                shared_ptr<BorrowRecord>temp=borrowedBooks[i];
                temp->dispalyBorrowRecordDetails();
            }
            
        }
    void displayMenu() override {
        int choice;
        string isbn;
        do {
            cout << "\n===== Member Menu =====\n";
            cout << "1. Borrow Book\n2. Return Book\n3. View My Books\n0. Exit\n";
            cin >> choice; cin.ignore();

            if (choice == 1) {
                cout << "ISBN: "; getline(cin, isbn);
                borrowBook(isbn);
            } else if (choice == 2) {
                cout << "ISBN: "; getline(cin, isbn);
                returnbook(isbn);
            } else if (choice == 3) {
                viewMyBooks();
            }

        } while (choice != 0);
    }
    
        //distor
        ~Member(){}
};



// EL-Main
int main() {

    vector<shared_ptr<Book>> books;

    while (true) {
        cout << "\n===== Main Menu =====\n";
        cout << "1. Librarian\n";
        cout << "2. Member\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        int userType;
        cin >> userType;
        cin.ignore();

        if (userType == 1) {
            Librarian lib("Admin", 1, books);
            lib.displayMenu();
        } 
        else if (userType == 2) {
            Member mem("User", 2, books);
            mem.displayMenu(); 
        }
        else if (userType == 0) {
            cout << "Exiting the program...\n";
            break;
        }
        else {
            cout << "Invalid choice, try again!\n";
        }
    }

    return 0;
}