#ifndef TRACKACTIONS_HPP
#define TRACKACTIONS_HPP

#include <fstream>
#include <iostream>
#include <string>
#include "boats/Track.hpp"
#include "collections/List.hpp"

void addTrack();
void addTrackFromFile();
void displayTrack();

extern List<Track*>* tracks;

#endif
