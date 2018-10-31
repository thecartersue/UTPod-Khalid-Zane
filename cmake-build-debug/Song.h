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

    Song(){
        artist = "";
        title = "";
        size = 0;
    }
    Song(string newArtist ,string newTitle , int newSize){
        artist = newArtist;
        title = newTitle;
        size = newSize;
    }
    //Artist
    string getArtist(Song const &s) const{
        return s.artist;
    }

    void setArtist(string newArtist){
    }

    //Title
    string getTitle(Song const &s) const{
        return s.title;
    }
    void setTitle(string newTitle){
    }

    //Size
    int getSize(Song const &s) const{
        return s.size;
    }
    void setSize(int){

    }

    //Operators
    bool operator > (const Song &){
        return 0;
    }
    bool operator < (const Song &){
        return 0;
    }
    bool operator == (const Song &){
        return 0;
    }
    //Destructor
    ~Song(){};
};

