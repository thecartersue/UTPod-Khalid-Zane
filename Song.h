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

    }
    Song(string ,string ,int){

    }
    //Artist
    string getArtist() const{
        return "Holder";
    }
    void setArtist(string){

    }

    //Title
    string getTitle() const{
        return "Holder";
    }
    void setTitle(string){

    }

    //Size
    int getSize() const{
        return 1;
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

