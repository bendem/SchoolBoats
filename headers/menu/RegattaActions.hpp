#include "boats/Regatta.hpp"
#include "boats/Track.hpp"
#include "collections/List.hpp"
#include "collections/OrderedList.hpp"

void addRegatta();
void displayRegattaList();
void displayRegatta();
void deleteRegatta();

void addContestant();
void addContestantFromFile();
void startRegatta();

extern Regatta* currentRegatta;
extern OrderedList<Regatta*>* regattas;
extern List<Track*>* tracks;
