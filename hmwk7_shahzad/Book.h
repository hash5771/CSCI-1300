#include <iostream>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 7 - Problem 3/4/5/6

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