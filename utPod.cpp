#include <cstdlib>
#include <iostream>
#include <string>
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
    if (s.getArtist() == "" || s.getTitle() == "" || s.getSize()<1){
        return -1;
    }else{
        if(memSize - s.getSize() >= 0){
            SongNode *temp = songs;
            temp = new SongNode;
            temp->s = s;
            if (songs == nullptr){
                songs = temp;
            }else {
                SongNode *current = songs;
                while (current->next != nullptr){
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
    return 1;
}

void UtPod::shuffle() {


}

void UtPod::showSongList() {

}

void UtPod::sortSongList() {

}

void UtPod::clearMemory() {

}

int UtPod::getRemainingMemory() {

    return 500;
}

UtPod::~UtPod() {

    SongNode *current = songs;
    while (current != nullptr){
        current = current->next;
        delete songs;
        songs = current;
    }
}
