#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "song.h"
using namespace std;

Song::Song(){
    artist = "";
    title = "";
    size = 0;
}

Song::Song(string newArtist ,string newTitle , int newSize){
    artist = newArtist;
    title = newTitle;
    size = newSize;
}
