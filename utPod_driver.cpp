/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "UtPod.h"
using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    t.getTotalMemory();

    Song s1("Khalid", "Location", 5);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    Song s2("Zane", "Pillow Talk", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    Song s3("Drake", "Zrammys", 5);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Tupac", "Hail Mary", 5);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    t.sortSongList();

    t.showSongList();

    cout << t.getTotalMemory() << "\n";

    cout << t.getRemainingMemory() << "\n";

    t.shuffle();

    t.showSongList();

    t.clearMemory();

    t.showSongList();

    t.addSong(s1);

    t.addSong(s3);

    t.addSong(s4);

    t.shuffle();

    t.showSongList();

    t.removeSong(s4);

    t.showSongList();
}