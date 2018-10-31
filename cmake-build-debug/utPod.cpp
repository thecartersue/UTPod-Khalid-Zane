#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "utPod.h"
using namespace std;

UtPod::UtPod(){
    songs = nullptr;
    memSize = MAX_MEMORY;
}

UtPod::UtPod(int size){
    if(size > MAX_MEMORY || size < 0){
        memSize = MAX_MEMORY;
    }else memSize = size;
}

int UtPod::addSong(Song const &s) {
    if (s.getArtist(s) == "" || s.getTitle(s) == "" || s.getSize(s) < 1) {
        return -1;
    } else {
        if (memSize - s.getSize(s) >= 0) {
            memSize = memSize - s.getSize(s);
            SongNode *temp = songs;
            temp = new SongNode;
            temp->s = s;
            if (songs == nullptr) {
                songs = temp;
            } else {
                SongNode *current = songs;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = temp;
                temp->next = nullptr;
            }
            return 0;
        }
        return -1;
    }
}

int UtPod::removeSong(Song const &s) {
    SongNode *findSong = songs;
    SongNode *trail = songs;
    while(findSong->s.getTitle(s) != s.getTitle(s) && findSong->s.getArtist(s) != s.getArtist(s) && findSong->s.getSize(s) != s.getSize(s)) {
        trail = findSong;
        if (findSong->next != nullptr) {
            findSong = findSong->next;
        }else return -1;
    }
    //readjusting the ll
    trail->next= findSong->next;
    //readjust memory
    memSize = memSize + s.getSize(s);
    //delete node
    delete findSong;
    return 0;
}

void UtPod::shuffle() {

}

void UtPod::showSongList() {
    SongNode *songList = songs;
    while(songList != nullptr) {
        cout << songList->s.getTitle(songList->s) << ", " << songList->s.getArtist(songList->s) << ", " << songList->s.getSize(songList->s) << "\n";
        songList = songList->next;
    }
}

void UtPod::sortSongList() {
    SongNode *tempSort = songs;
    string tempArtist, tempTitle;
    int counter = 0, tempSize = 0;
    //get number of songs
    while(tempSort!= nullptr){
        tempSort = tempSort->next;
        counter++;
    }
    tempSort = songs;
    for(int j = 0; j < counter ; j++){
        while(tempSort->next != nullptr){
            if(tempSort->s > tempSort->next->s){
                tempArtist = tempSort->s.getArtist(tempSort->s);
                tempTitle = tempSort->s.getTitle(tempSort->s);
                tempSize = tempSort->s.getSize(tempSort->s);

                //change the trailing node
                tempSort->s.setArtist(tempSort->next->s.getArtist(tempSort->next->s));
                tempSort->s.setTitle(tempSort->next->s.getTitle(tempSort->next->s));
                tempSort->s.setSize(tempSort->next->s.getSize(tempSort->next->s));

                //change the first node
                tempSort->next->s.setArtist(tempArtist);
                tempSort->next->s.setTitle(tempTitle);
                tempSort->next->s.setSize(tempSize);

                tempSort = tempSort->next;
            }else{
                tempSort = tempSort->next;
            }
        }
        //repeat
        tempSort = songs;
    }
}

void UtPod::clearMemory() {

}

int UtPod::getRemainingMemory() {
    return 500;
}

UtPod::~UtPod() {
    SongNode *current = songs;
    while (current != nullptr) {
        current = current->next;
        delete songs;
        songs = current;
    }
}
