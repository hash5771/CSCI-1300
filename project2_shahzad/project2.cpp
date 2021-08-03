#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Book.h"
#include "User.h"
using namespace std;

//unfinished, missed one case on number 11 and a majority of cases on number 12

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 2 - Problem 11

// OPTION 1 //
int split(string phrase, char del, string words[], int size)
{
    if (phrase.length() == 0)
    {
        return 0;
    }

    string piece = "";
    int arrpos = 0;

    for (int pos = 0; pos < phrase.length(); pos++)
    {
        if (phrase[pos] != del)
        {
            piece = piece + phrase[pos];
        }
        else
        {
            if (pos != 0 && pos != (phrase.length() - 1))
            {
                words[arrpos] = piece;
                piece = "";
                arrpos++;

                int check = pos + 1;
                if (phrase[check] == del)
                {
                    pos++;
                }
            }
            else
            {
                if (pos == (phrase.length() - 1))
                {
                    pos++;
                }
            }
        }
    }
    words[arrpos] = piece;

    int count = arrpos + 1;
    if (count > size)
    {
        return -1;
    }
    return count;
}

class Book
{
    public:
        Book();
        Book(string title, string author, string genre);
        string getTitle();
        void setTitle(string titleInput);
        string getAuthor();
        void setAuthor(string authorInput);
        string getGenre();
        void setGenre(string genreInput);
        
    private:
        string title;
        string author;
        string genre;
};

Book::Book()
        {
            title = "";
            author = "";
            genre = "";
        }
Book::Book(string title, string author, string genre)
        {
            setTitle(title);
            setAuthor(author);
            setGenre(genre);
        }
string Book::getTitle()
        {
            return title;
        }
void Book::setTitle(string titleInput)
        {
            title = titleInput;
        }
string Book::getAuthor()
        {
            return author;
        }
void Book::setAuthor(string authorInput)
        {
            author = authorInput;
        }
string Book::getGenre()
        {
            return genre;
        }
void Book::setGenre(string genreInput)
        {
            genre = genreInput;
        }

class User
{
    public:
    User();
    User(string username, int ratings[], int numRatings);
    string getUsername();
    void setUsername(string usernameInput);
    int getRatingAt(int index);
    bool setRatingAt(int index, int value);
    int getNumRatings();
    void setNumRatings(int numRatingsInput);
    int getSize();

    private:
    string username;
    static const int size = 50;
    int ratings[size];
    int numRatings;
};

User::User()
{
    username = "";
    numRatings = 0;
    for (int i = 0; i < size; i++)
    {
        ratings[i] = 0;
    }
}
User::User(string username, int ratings[], int numRatings)
{
    setUsername(username);
    setRatingAt(ratings[size], size);
    setNumRatings(numRatings);
}
string User::getUsername()
{
    return username;
}
void User::setUsername(string usernameInput)
{
    username = usernameInput;
}
int User::getRatingAt(int index)
{
    if (index >= size || index < 0)
    {
        return -1;
    }
    else
    {
        return ratings[index];
    }
}
bool User::setRatingAt(int index, int value)
{
    if (index >= 0 && index < size && value >= 0 && value <= 5)
    {
        ratings[index] = value;
        return true;
    }
    else
    {
        return false;
    }
}
int User::getNumRatings()
{
    return numRatings;
}
void User::setNumRatings(int numRatingsInput)
{
    numRatings = numRatingsInput;
}
int User::getSize()
{
    return size;
}

// Paste your program here, but do NOT paste your #include statements or using namespace std;
#include <iomanip>
class Book
{
    public:
        Book();
        Book(string title, string author, string genre);
        string getTitle();
        void setTitle(string titleInput);
        string getAuthor();
        void setAuthor(string authorInput);
        string getGenre();
        void setGenre(string genreInput);
        
    private:
        string title;
        string author;
        string genre;
};

Book::Book()
        {
            title = "";
            author = "";
            genre = "";
        }
Book::Book(string title, string author, string genre)
        {
            setTitle(title);
            setAuthor(author);
            setGenre(genre);
        }
string Book::getTitle()
        {
            return title;
        }
void Book::setTitle(string titleInput)
        {
            title = titleInput;
        }
string Book::getAuthor()
        {
            return author;
        }
void Book::setAuthor(string authorInput)
        {
            author = authorInput;
        }
string Book::getGenre()
        {
            return genre;
        }
void Book::setGenre(string genreInput)
        {
            genre = genreInput;
        }

class User
{
    public:
    User();
    User(string username, int ratings[], int numRatings);
    string getUsername();
    void setUsername(string usernameInput);
    int getRatingAt(int index);
    bool setRatingAt(int index, int value);
    int getNumRatings();
    void setNumRatings(int numRatingsInput);
    int getSize();

    private:
    string username;
    static const int size = 50;
    int ratings[size];
    int numRatings;
};

User::User()
{
    username = "";
    numRatings = 0;
    for (int i = 0; i < size; i++)
    {
        ratings[i] = 0;
    }
}
User::User(string username, int ratings[], int numRatings)
{
    setUsername(username);
    setRatingAt(ratings[size], size);
    setNumRatings(numRatings);
}
string User::getUsername()
{
    return username;
}
void User::setUsername(string usernameInput)
{
    username = usernameInput;
}
int User::getRatingAt(int index)
{
    if (index >= size || index < 0)
    {
        return -1;
    }
    else
    {
        return ratings[index];
    }
}
bool User::setRatingAt(int index, int value)
{
    if (index >= 0 && index < size && value >= 0 && value <= 5)
    {
        ratings[index] = value;
        return true;
    }
    else
    {
        return false;
    }
}
int User::getNumRatings()
{
    return numRatings;
}
void User::setNumRatings(int numRatingsInput)
{
    numRatings = numRatingsInput;
}
int User::getSize()
{
    return size;
}

int readBooks(string filename, Book books[], int numBooksStored, int booksArrSize) //returns number of books in a book array
{
    if (numBooksStored == booksArrSize) // returns -2 if the array is filled
    {
        return -2;
    }
    ifstream file;
    file.open(filename);
    int totalBooks = 0;

    if (!file.is_open()) // returns -1 if the file did not open successfully
    {
        return -1;
    }
    else if (file.is_open()) // fills the array with information
    {
        string lines = "";
        string booksArray[booksArrSize * 3];
        string authorArray[booksArrSize];
        string titleArray[booksArrSize];
        string genreArray[booksArrSize];
        int totalBooks = 0;
        int i = numBooksStored;
        while (getline(file, lines))
        {
            if (i >= booksArrSize)
            {
                break;
            }
            if (lines != "")
            {
                split(lines, ',', booksArray, booksArrSize);
                titleArray[i] = booksArray[1];
                authorArray[i] = booksArray[0];
                genreArray[i] = booksArray[2];
                books[i] = Book(booksArray[1], booksArray[0], booksArray[2]);
                i++;
                totalBooks++;
            }
        }
        file.close();
        return totalBooks + numBooksStored;
    }
}

// OPTION 2 //
void printAllBooks(Book books[], int numBooks)
{
    if (numBooks <= 0)
    {
        cout << "No books are stored" << endl;
    }
    else if (numBooks > 0)
    {
        cout << "Here is a list of books" << endl;
        for (int i = 0; i < numBooks; i++)
        {
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }
    }
}

// OPTION 3 //
int countGenre (string genre, Book books[], int numBooksStored)
{
    int count = 0;
    for (int i = 0; i < numBooksStored; i++)
    {
        if (books[i].getGenre() == genre)
        {
            count++;
        }
    }
    return count;
}

// OPTION 4 //
int printAuthorGenre(string genre, char authorFirstLetter, Book books[], int numBooksStored)
{
    int count = 0;
    int j = 0;
    string matchTitle[numBooksStored];
    string matchAuthor[numBooksStored];
    for (int i = 0; i < numBooksStored; i++)
    {
        if (books[i].getGenre() == genre) //checks to see if genre matches
        {
            string author = books[i].getAuthor();
            author.at(0);
            if (author.at(0) == authorFirstLetter) //checks to see how many authors match
            {
                matchTitle[j] = books[i].getTitle();
                matchAuthor[j] = books[i].getAuthor();
                j++;
                count++;
            }
        }
    }
    if (count == 0)
    {
        cout << "No titles found for this genre-author pair." << endl;
    }
    else if (count > 0)
    {
        cout << "Here is a list of books that match this genre-author pair:" << endl;
        for (int k = 0; k < count; k++)
        {
            cout << matchTitle[k] << " by " << matchAuthor[k] << endl;
        }
    }
    return count;
}

// OPTION 5 //
int addUser(string username, User users[], int numRatings, int numUsersStored, int usersArrSize)
{
    if (numUsersStored >= usersArrSize)
    {
        return -2;
    }
    for (int i = 0; i < numUsersStored; i++)
    {
        if (users[i].getUsername() == username || username == "")
        {
            return -1;
        }
    }
    for (int j = 0; j < usersArrSize; j++)
    {
        users[j].setRatingAt(0, 0);
    }
    users[numUsersStored].setUsername(username);
    numUsersStored++;
    return numUsersStored;
}

// OPTION 6 //
int readRatings(string filename, User users[], int numUsersStored, int usersArrSize, int maxCol)
{
    users[usersArrSize];
    if (numUsersStored >= usersArrSize)
    {
        return -2;
    }
    ifstream file;
    file.open(filename);
    if (!file.is_open())
    {
        return -1;
    }

    string lines = "";
    while (getline(file, lines))
    {
        if (numUsersStored >= usersArrSize)
        {
            break;
        }
        else if (lines == "")
        {
            numUsersStored = numUsersStored;
        }
        else
        {
            string storage[100];
            int count = split(lines, ',', storage, 100);
            int j = 1;
            users[numUsersStored].setUsername(storage[0]);
            for (int i = 0; i < count-1; i++)
            {
                users[numUsersStored].setRatingAt(i, stoi(storage[j]));
                j++;
            }
            numUsersStored++;
        }
    }
    file.close();
    return numUsersStored;
}

// OPTION 7 //
string lowercase(string name)
{
    string lowerCaseString = name;
    for (int a = 0; a < name.length(); a++)
    {
        if (name[a] >= 'A' && name[a] <= 'Z')
        {
            lowerCaseString[a] = name[a] + 32;
        }
    }
    return lowerCaseString;
}

int getRating(string username, string bookTitle, User users[], Book books[], int numUsers, int numBooks)
{
    for (int i = 0; i < numUsers; i++)
    {
        if (lowercase(users[i].getUsername()) == lowercase(username))
        {
            for (int j = 0; j < numBooks; j++)
            {
                if (lowercase(books[j].getTitle()) == lowercase(bookTitle))
                {
                    return users[i].getRatingAt(j);
                }
            }
        }
    }
    return -3;
}

// OPTION 8 //
int getUserStats(string username, User users[], int numUsers, int numBooks)
{
    for (int i = 0; i < numUsers; i++)
    {
        if (users[i].getUsername() == username)
        {
            if (users[i].getNumRatings() == 0)
            {
                cout << username << " has not rated any books." << endl;
                return 0;
            }
            double average = 0.00;
            int count = 0;
            for (int j = 0; j < numBooks; j++)
            {
                if (users[i].getRatingAt(j) == 0)
                {
                    average = average;
                }
                else
                {
                    average += users[i].getRatingAt(j);
                    users[i].setNumRatings(j);
                    count++;
                }
            }
            cout << username << " rated " << count << " books" << endl;
            average = average / count;
            cout << username << "'s average rating was " << fixed << setprecision(2) << average << endl;
            return 1;
        }
    }
    cout << username << " does not exist." << endl;
    return -3;
}

// MAIN FUNCTION CONTROLLING THE MENU

int main ()
{
    static const int booksArrSize = 50;
    static const int usersArrSize = 100;
    Book books[booksArrSize];
    User users[usersArrSize];
    int input;
    int numBooks;
    int numBooksStored;
    do
    {
        cout << "Select a numerical option:" << endl;
        cout << "======Main Menu=====" << endl;
        cout << "1. Read books from file" << endl;
        cout << "2. Print all books" << endl;
        cout << "3. Book-count by genre" << endl;
        cout << "4. Filter books by genre, author" << endl;
        cout << "5. Add user" << endl;
        cout << "6. Read ratings" << endl;
        cout << "7. Get rating" << endl;
        cout << "8. Get user statistics" << endl;
        cout << "9. Quit" << endl;
        cin >> input;
        if (input == 1)
        {
            string filename;
            cout << "Enter a book file name:" << endl;
            cin >> filename;
            int returnValue = readBooks(filename, books, numBooksStored, booksArrSize);
            if (returnValue == -1)
            {
                cout << "No books saved to the database." << endl;
            }
            else if (returnValue == -2)
            {
                cout << "Database is already full. No books were added." << endl;
            }
            else if (returnValue == booksArrSize)
            {
                cout << "Database is full. Some books may have not been added." << endl;
                numBooks = 50;
                numBooksStored = 50;
            }
            else
            {
                cout << "Total books in the database: " << returnValue << endl;
                numBooks = returnValue;
                numBooksStored = returnValue;
            }
        }
        else if (input == 2)
        {
            printAllBooks(books, numBooks);
        }
        else if (input == 3)
        {
            cout << "Enter the genre:" << endl;
            string genreInput;
            cin >> genreInput;
            int totalGenreBooks = countGenre(genreInput, books, numBooksStored);
            cout << "Total " << genreInput << " books in the database: " << totalGenreBooks << endl;
        }
        else if (input == 4)
        {
            cout << "Enter the genre:" << endl;
            string genreInput;
            cin >> genreInput;
            getline(cin, genreInput);
            cout << "Enter first char of author name:" << endl;
            char authorFirstLetter;
            cin >> authorFirstLetter;
            int numReturnedTitles = printAuthorGenre(genreInput, authorFirstLetter, books, numBooksStored);
            cout << "Number of titles found for this filter: " << numReturnedTitles << endl;
        }
        else if (input == 5)
        {
            cout << "Enter a user name:" << endl;
            string username;
            cin >> username;
            getline(cin, username);
            int numRatings;
            int numUsersStored;
            int returnValue = addUser(username, users, numRatings, numUsersStored, usersArrSize);
            if (returnValue == -2)
            {
                cout << "Database is already full. User cannot be added." << endl;
            }
            else if (returnValue == -1)
            {
                cout << "User already exists or the username is empty.";
            }
            else
            {
                cout << "Welcome, " << username << "!" << endl;
            }
        }
        else if (input == 6)
        {
            cout << "Enter the ratings file name:" << endl;
            string filename;
            cin >> filename;
            getline(cin, filename);
            int numUsersStored;
            int maxCol;
            int returnValue = readRatings(filename, users, numUsersStored, usersArrSize, maxCol);
            if (returnValue == -1)
            {
                cout << "No ratings saved to the database." << endl;
            }
            else if (returnValue == -2)
            {
                cout << "Database is already full. No ratings were added." << endl;
            }
            else if (returnValue == usersArrSize)
            {
                cout << "Database is full. Some ratings may have not been added." << endl;
            }
            else
            {
                cout << "Total users in the database:" << returnValue << endl;
            }
        }
        else if (input == 7)
        {
            cout << "Enter a user name:" << endl;
            string username;
            cin >> username;
            getline(cin, username);
            cout << "Enter a book Title:" << endl;
            string bookTitle;
            cin >> bookTitle;
            getline(cin, bookTitle);
            int numUsers;
            int returnValue = getRating(username, bookTitle, users, books, numUsers, numBooks);
            if (returnValue == -3)
            {
                cout << username << " or " << bookTitle << " does not exist.";
            }
            else
            {
                cout << username << " rated " << bookTitle << " with " << returnValue;
            }
        }
        else if (input == 8)
        {
            cout << "Enter a user name:" << endl;
            string username;
            cin >> username;
            getline(cin, username);
            int numUsers;
            getUserStats(username, users, numUsers, numBooks);
        }
        else if (input == 9)
        {
            break;
        }
        else
        {
            cout << "Invalid input." << endl;
        }
        
    } while (input != 9);
    cout << "Good bye!" << endl;
    return 0;
}