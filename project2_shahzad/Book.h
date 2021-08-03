#include <iostream>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 2 - Problem 1/2/3/4/5/8/11

/*
declaration of the book class
*/

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