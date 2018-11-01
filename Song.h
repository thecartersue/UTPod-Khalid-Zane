// Created by Khalid Ahmad on 10/29/18.
//
#include <string>
#include <iostream>
using namespace std;

class Song {
private:

    string artist;
    string title;
    int size;

public:

    Song();
    Song(string newArtist ,string newTitle , int newSize);
    //Artist
//Artist
    string getArtist() const{
        return artist;
    }

    void setArtist(string newArtist){
        artist = newArtist;
    }

//Title
    string getTitle() const{
        return title;
    }
    void setTitle(string newTitle){
        title = newTitle;
    }

//Size
    int getSize() const{
        return size;
    }
    void setSize(int newSize){
        size = newSize;
    }

//Operators
    bool operator > (Song const &rhs) {
        if (artist != rhs.artist) {
            return (artist < rhs.artist);
        } else {
            if (title != rhs.title) {
                return (title < rhs.title);
            } else {
                return (size < rhs.size);
            }
        }
    }

    bool operator < (Song const &rhs) {
        if (artist != rhs.artist) {
            return (artist > rhs.artist);
        } else {
            if (title != rhs.title) {
                return (title > rhs.title);
            } else {
                return (size > rhs.size);
            }
        }
    }
    bool operator == (Song const &rhs) {
        if (artist == rhs.artist && title == rhs.title && size == rhs.size) {
            return true;
        } else return false;
    }
    //Destructor
};

