#include <iostream>
#include "Book.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 7 - Problem 3/4/5/6

/*
implementation of the book class
*/

Book::Book()
        {
            title = "";
            author = "";
            genre = "";
        }
Book::Book(string author, string title, string genre)
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