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
    if (s.getArtist() == "" || s.getTitle() == "" || s.getSize() < 1) {
        return -1;
    } else{
        SongNode *temp = new SongNode;
        SongNode *current = new SongNode;
        temp = songs;
        current = songs;
        temp->s = s;
        while (songs != nullptr){

        }

    }
        return 0;
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
    /*current = head;
     * while(current != nulptr){
     * current = current.next
     * delete head;
     * head = current; 
     *
     */
}
