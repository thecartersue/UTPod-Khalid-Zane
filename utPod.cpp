#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "UtPod.h"
using namespace std;

UtPod::UtPod(){
    songs = NULL;
    memSize = MAX_MEMORY;
}

UtPod::UtPod(int size){
    if(size > MAX_MEMORY || size < 0){
        memSize = MAX_MEMORY;
    }else memSize = size;
}

int UtPod::addSong(Song const &s) {
    if (s.getArtist() == "" || s.getTitle() == "" || s.getSize() < 1) {
        return -1;
    } else {
        if (getRemainingMemory() - s.getSize() >= 0) { ;
            SongNode *temp = songs;
            temp = new SongNode;
            temp->s = s;
            if (songs == NULL) {
                temp->next = NULL;
                songs = temp;

            } else {
                SongNode *current = songs;
                while (current->next) {
                    current = current->next;
                }
                current->next = temp;
                temp->next = NULL;
            }
            return 0;
        }
        return -1;
    }
}

int UtPod::removeSong(Song const &s) {
    SongNode *findSong = songs;
    SongNode *trail = findSong;
    while(!(findSong->s == s)) {
        trail = findSong;
        if (findSong->next != NULL) {
            findSong = findSong->next;
        }else return -1;
    }
    //readjusting the ll
    if(findSong == songs){
        songs = findSong->next;
    }else {
        trail->next = findSong->next;
    }
    //delete node
    delete findSong;
    return 0;
}

void UtPod::shuffle() {

    SongNode *tempSort = songs;
    string tempArtist, tempTitle;
    int tempSize = 0, random = 0, counter = 0;
    int fiftyPercent = 5;
    //get number of songs
    while(tempSort){
        tempSort = tempSort->next;
        counter++;
    }
    tempSort = songs;
    srand(time(NULL));
    for(int j = 0; j < counter ; j++){
        while(tempSort->next){
            if(rand()%10+1 >= fiftyPercent){
                tempArtist = tempSort->s.getArtist();
                tempTitle = tempSort->s.getTitle();
                tempSize = tempSort->s.getSize();

                //change the trailing node
                tempSort->s.setArtist(tempSort->next->s.getArtist());
                tempSort->s.setTitle(tempSort->next->s.getTitle());
                tempSort->s.setSize(tempSort->next->s.getSize());

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


void UtPod::showSongList() {
    SongNode *songList = songs;
    if(songs == NULL){
        cout << "No songs to display." << "\n";
    }
    while(songList) {
        cout << songList->s.getTitle() << ", " << songList->s.getArtist() << ", " << songList->s.getSize() << "\n";
        songList = songList->next;
    }
}

void UtPod::sortSongList() {
    SongNode *tempSort = songs;
    string tempArtist, tempTitle;
    int counter = 0, tempSize = 0;
    //get number of songs
    while(tempSort){
        tempSort = tempSort->next;
        counter++;
    }
    tempSort = songs;
    for(int j = 0; j < counter ; j++){
        while(tempSort->next){
            if(tempSort->s < tempSort->next->s){
                tempArtist = tempSort->s.getArtist();
                tempTitle = tempSort->s.getTitle();
                tempSize = tempSort->s.getSize();

                //change the trailing node
                tempSort->s.setArtist(tempSort->next->s.getArtist());
                tempSort->s.setTitle(tempSort->next->s.getTitle());
                tempSort->s.setSize(tempSort->next->s.getSize());

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
    SongNode *current = songs;
    SongNode *trail = current;
    while (current){
        trail = current;
        current = current->next;
        trail->next = NULL;
        delete trail;
    }
    songs = NULL;
}

int UtPod::getRemainingMemory() {
    SongNode *memoryTrack = songs;
    int memoryUsed = 0;
    while(memoryTrack != NULL){
        memoryUsed = memoryUsed + memoryTrack->s.getSize();
        memoryTrack = memoryTrack->next;
    }
    return (getTotalMemory() - memoryUsed);
}

UtPod::~UtPod(){
    clearMemory();
}
