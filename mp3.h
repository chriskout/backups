#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mp3 {
	char *name;
	char* title;
	int year;
	int runtime;
	struct mp3* next;
	struct mp3* prev;
	} mp3_t;

int addMp3(mp3_t * toAdd);

int removeMp3(char * toRemove, mp3_t * current);

int deleteMp3Rec(char * nta, mp3_t* current);

int printMp3(mp3_t* start);

int printMp3Rev(mp3_t* start);

