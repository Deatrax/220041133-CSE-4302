#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <fstream>
#include <sstream>


#define nl "\n"
#define spc <<' '<<""
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
typedef long long ll;
using namespace std;

class Book{
    private:
        string title;
        string author;
        string ISBN;

    public:

        Book(string ti, string au, string isbn):
        title(ti)
        ,author(au)
        ,ISBN(isbn){}

        string getTitle(){
            return title;
        }

        string getAuthor(){
            return author;
        }

        string getISBN(){
            return ISBN;
        }

        const void getData(string &til, string &au, string &isbn){
            til=title;
            au=author;
            isbn=ISBN;
            return;
        }

        void displayDetails(){
            cout<<"\t"<<title<<" \tby "<<author<<", \tISBN:"<<ISBN<<endl; 
        }

        bool operator==(const Book &other) const {
            return ISBN == other.ISBN;  // Compare by ISBN (or title/author)
        }

    
};


class Library{
    private:
        vector<Book> inventory;
        deque<Book>  borrowedBooks;
        list<Book>   archivedBooks;
        unordered_map<string, Book> all;
        string file="libDat.lib";
        bool isEdited=false;

        Book findBook(string isbn){
            if( all.find(isbn) != all.end() ) return all.find(isbn)->second;
            return Book("noFound", "", "");
        }

    public:
        Library(){}

        bool isLibEdited(){
            return isEdited;
        }

        void addBook(){
            string name;
            string author;
            string ISBN;

            cout<<"Please give the title of the book: ";
            fflush(stdin);
            getline(cin, name);
            cout<<"Please give the author of the book: ";
            cin>>author;
            cout<<"Please give the ISBN of the book: ";
            cin>>ISBN;
            
            Book book2=findBook(ISBN);
            if(book2.getTitle() != "noFound"){
                cout<<"Book with that ISBN already exists\n";
                return;
            }

            Book book(name, author, ISBN);
            all.emplace(book.getISBN() , book);
            inventory.push_back(book);
            isEdited=true;
            return;
        }

        void borrowBook(string isbn){
            Book book=findBook(isbn);
            if(book.getTitle() == "noFound"){
                cout<<"Book with that ISBN does not exist\n";
                return;
            }

            inventory.erase( find( inventory.begin() , inventory.end() , book));

            borrowedBooks.emplace_back(book);
            isEdited=true;
            return;
        }

        void returnBook(string isbn){
            Book book=findBook(isbn);
            if(book.getTitle() == "noFound"){
                cout<<"Book with that ISBN does not exist\n";
                return;
            }

            if(book.getTitle() == "noFound"){
                cout<<"Book with that ISBN does not exist\n";
            }

            if( borrowedBooks.front() == book) borrowedBooks.pop_front();
            else borrowedBooks.erase( find( borrowedBooks.begin() , borrowedBooks.end() , book));
            inventory.push_back(book);
            isEdited=true;
            return;
        }

        void archiveBook(string isbn){
            Book book=findBook(isbn);
            if(book.getTitle() == "noFound"){
                cout<<"Book with that ISBN does not exist\n";
                return;
            }

            inventory.erase( find( inventory.begin() , inventory.end() , book));
            archivedBooks.push_back(book);
            isEdited=true;
        }

        void displayAll(){
            cout<<"\n\nThe Current inventory: "<<endl;
            for(auto &it : inventory){
                it.displayDetails();
            }

            cout<<"\n\nThe Currently Borrowed Books: "<<endl;
            for(auto &it : borrowedBooks){
                it.displayDetails();
            }

            cout<<"\n\nThe Archived Books: "<<endl;
            for(auto &it : archivedBooks){
                it.displayDetails();
            }
        }

        
        bool saveData() {
            ofstream outfile(file, ios::out);  
            if (!outfile) return false;  
        
            
            auto writeBooks = [&](auto &books, char status) {
                for (Book &book : books) {
                    outfile << book.getTitle() << "," 
                            << book.getAuthor() << "," 
                            << book.getISBN() << "," 
                            << status << "\n";
                }
            };
        
            
            writeBooks(inventory, '1'); 
            writeBooks(borrowedBooks, '2'); 
            writeBooks(archivedBooks, '3');  
        
            outfile.close(); 
            isEdited=false;
            return true; 
        }
        

        bool loadData(){
            ifstream infile(file, ios::in);
            if(!infile) return false;
            string readLine;
            while(getline(infile,readLine)){
                stringstream lineParse(readLine);

                string title;
                string author;
                string ISBN;
                string status;

                getline(lineParse , title , ',');
                getline(lineParse , author , ',');
                getline( lineParse , ISBN , ',');
                getline(lineParse , status , ',');

                Book book(title, author, ISBN);

                char c=status.front();

                switch (c)
                {
                case '1':
                    inventory.push_back(book);
                    break;
                
                case '2':
                    borrowedBooks.push_back(book);
                    break;
                
                case '3':
                    archivedBooks.push_back(book);
                    break;
                }

                all.emplace(ISBN,book);
            }
            return true;
        }

};

int main(){

    Library library;
    cout<<"Welcome to the Library portal, Mr. Manager\n"<<endl;
    int c=0;
    while(c!=8){
        cout<<"\n\nPlease select your operation :"<<endl
            <<"1. Add book"<<endl
            <<"2. Borrow book"<<endl
            <<"3. Return book"<<endl
            <<"4. Archive book"<<endl
            <<"5. Load Library"<<endl
            <<"6. Save Library"<<endl
            <<"7. Display All"<<endl
            <<"8. Exit portal"<<endl
            <<"Please choose and option :";

            fflush(stdin);
            cin>>c;
            string isbn;

            switch (c)
            {
            case 1:
                library.addBook();
                break;
            
            case 2:
                cout<<"Please give the ISBN of the book =";
                cin>>isbn;
                library.borrowBook(isbn);
                break;
            
            case 3:
                cout<<"Please give the ISBN of the book =";
                cin>>isbn;
                library.returnBook(isbn);
                break;

            case 4:
                cout<<"Please give the ISBN of the book =";
                cin>>isbn;
                library.archiveBook(isbn);  
                break;  
            
            case 5:
                if(library.loadData())
                    cout<<"Library loaded successfully!!\n";
                else
                    cout<<"Library failed to load successfully!!\nPlease check file or save library first\n\n";
                break;

            case 6:
                if(library.saveData())
                    cout<<"Library saved successfully!!\n";
                else
                    cout<<"Library failed to save successfully!!\nPlease check file\n";
                break;

            case 7:
                library.displayAll();
                break;

            case 8:
                if(library.isLibEdited()){
                    cout<<"Library has unsaved changes, do you wat to quit? [y/n] =";
                    fflush(stdin);
                    char i;
                    cin>>i;
                    if(i =='y'){
                        cout<<"Thank you Mr. Manager, have a great day\n\n";
                    }
                    else if( i == 'n') c=0;
                }
                break;

            default:
                cout<<"Invalid Option, please try again. Press any key to continue\n\n:";
                break;
            }
    }
    
}