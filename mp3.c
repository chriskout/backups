
#include "mp3.h"


mp3_t * head = NULL;
mp3_t * tail = NULL;

#define BUFFERSIZE 128
//basic cleanup function
int cleanup(mp3_t * current) {
        free(current->title);
        free(current->name);
        free(current);
        return 0;
}


//inpute Void
//output VOid
//Effect Creates a node in the linked list based on user defined input
int insert() {
	char  buffer[BUFFERSIZE];
 	mp3_t *mp3;
  	int  len;

	printf("Enter a name: ");
	if (fgets(buffer, BUFFERSIZE , stdin) != NULL) {
	len = 0;
	}
  	if (fgets(buffer, BUFFERSIZE , stdin) != NULL)
  	{
    	len = (int) strlen(buffer);
    	printf("length [%d] of string %s", len, buffer); // notice the length!
    	buffer[len - 1] = '\0';                 // why minus 1 ???
 	mp3 = (mp3_t *) malloc(sizeof(mp3_t));
    	mp3->name = (char *) malloc(len);
    	strcpy(mp3->name, buffer);
    	printf("Name is [%s]...\n", mp3->name);
  	//free(mp3->name);
	}
  	   // line free 1
	printf("Enter a title: ");
  	if(fgets(buffer, BUFFERSIZE , stdin) != NULL)
  	{
    	len = (int) strlen(buffer);
    	printf("length [%d] of string %s", len, buffer); // notice the length!
    	buffer[len - 1] = '\0';                 // why minus 1 ???
    	mp3->title = (char *) malloc(len);
    	strcpy(mp3->title, buffer);
    	printf("Name is [%s]...\n", mp3->title);
  	//free(mp3->title);
	}
	printf("Enter the year this song was made: ");
        if(fgets(buffer, BUFFERSIZE , stdin) != NULL)
        {
        len = (int) strlen(buffer);
        printf("length [%d] of string %s", len, buffer); // notice the length!
        buffer[len - 1] = '\0';                 // why minus 1 ???
        mp3->year = atoi(buffer);
        printf("Year is [%d]...\n", mp3->year);
        }
	printf("Enter the runtime of the song: ");
	if(fgets(buffer, BUFFERSIZE , stdin) != NULL)
        {
        len = (int) strlen(buffer);
        printf("length [%d] of string %s", len, buffer); // notice the length!
        buffer[len - 1] = '\0';                 // why minus 1 ???
        mp3->runtime = atoi(buffer);
        printf("Year is [%d]...\n", mp3->runtime);
        }

	//this is the section where all the pointer magic happens;
	if (head != NULL) {
		mp3_t *old_last = tail;
		//old_last = (mp3_t *) malloc(sizeof(mp3_t));
		old_last->next = mp3;
		mp3->prev = old_last;
		tail = mp3;
		//free(old_last);
		printf("added entered song as the tail of the list, Press Enter to continue");
	}
	else {
		head = mp3;
		tail = mp3;
		printf("added entered song as the head of the list, Press enter to continue");
	}
	len = (int) strlen(buffer);
	//free(mp3);         // line free 2
	//free(buffer);
  	return 0;
}
//inpute: Mp3 pointer
//output: void
//Effect: Prints the list in forwards order
int printMp3(mp3_t * toprint) {
	if (head == NULL) {
		printf("There aint no list, try inserting");
		return 0;
	}
	int lenname = (int) strlen(toprint->name);
	int lentitle = (int) strlen(toprint->title);
	//printf("length of name: %d \n", lenname);
	 printf("\n%s created the song %s in %d, which had a runtime of %d\n", toprint->name, toprint->title, toprint->year, toprint->runtime);
	if (tail == toprint) {
	//toprint->name = (char *) malloc(lenname);
        //toprint->title = (char *) malloc(lentitle);
        //printf("\n%s created the song %s in %d, which had a runtime of %d\n", toprint->name, toprint->title, toprint->year, toprint->runtime); 
	//free(toprint->name);
	//free(toprint->title);
	return 0;
	}
	else {
	//toprint->name = (char *) malloc(lenname);
	//toprint->title = (char *) malloc(lentitle);
	//printf("\n%s created %s in %d, which had a length of %d", toprint->name, toprint->title, toprint->year, toprint->runtime);
	
	mp3_t * nextprint = toprint->next;
	//free(toprint->name);
        //free(toprint->title);

	printMp3(nextprint);
	return 0;
	}
}
//input: Mp3 pointer
//output:void
//Effect: Prints the list in backwards order
int printMp3Rev(mp3_t * toprint) {
	if (head == NULL) {
		printf("There is no list, try inserting");
		return 0;
	}
        int lenname = (int) strlen(toprint->name);
        int lentitle = (int) strlen(toprint->title);
        //printf("length of name: %d \n", lenname);
        printf("\n%s created the song %s in %d, which had a runtime of %d\n", toprint->name, toprint->title, toprint->year, toprint->runtime);
        if (head == toprint) {
        //toprint->name = (char *) malloc(lenname);
        //toprint->title = (char *) malloc(lentitle);
        //printf("\n%s created the song %s in %d, which had a runtime of %d\n", toprint->name, toprint->title, toprint->year, toprint->runtime);
        //free(toprint->name);
        //free(toprint->title);
        return 0;
        }
        else {
        //toprint->name = (char *) malloc(lenname);
        //toprint->title = (char *) malloc(lentitle);
        //printf("\n%s created %s in %d, which had a length of %d", toprint->name, toprint->title, toprint->year, toprint->runtime);
        
        mp3_t * nextprint = toprint->prev;
        //free(toprint->name);
        //free(toprint->title);

        printMp3Rev(nextprint);
        return 0;
        }
}
//inpute: mp3 pointer represestning the current state of the iteration on the list.
//output: void
//Effect: removes the given pointer, and reconenct the list where needed
int removeHelper(mp3_t *current) {
        if (current == head && current == tail) {
                head = NULL;
                tail = NULL; //needs free code
                return 0;
        }
        else if (current == head) {
                head = current->next;
		cleanup(current);
                return 0;
        }
        else if (current == tail) {
                tail = current->prev;
                cleanup(current);
		return 0;
        }
        else {
                current->next->prev = current->prev;
                current->prev->next = current->next;
		cleanup(current);
                return 0;
        }
}

//inpute: String of characters representing the artist to be removed
//	  Mp3 Pointer: current point in the iteration of the list
//Effect: Removes the pointers that match the string, reconnects the list where needed
int removeMp3(char * toRemove, mp3_t* current) {
	
        
	char * artist = current->name;
	int cmp = strcmp(artist, toRemove);
	if (cmp == 0 && tail == current) {
		removeHelper(current);
		return 0;
	}
	if (cmp == 0) {
		removeHelper(current);
	}
	if (tail == NULL && head == NULL) {return 0;}
	else if (tail == current) {
		return 0;
	}
	else {

		fflush(stdout);
		removeMp3(toRemove, current->next);
		return 0;
	}
	
}

//inpute: pointer, should always be a pointer to the head of the list
//output: none
//frees all memory in the list
int cleanall(mp3_t * current) {
	if (current == tail){
		cleanup(current);
		return 0;
	}
	else {
		mp3_t * todelete = current->next;
		cleanup(current);
		cleanup(todelete);
	}
	
}

//main, only has simple io
int main(int argc, char *argv[]) {
	char buffer[2];
	
	while(1) {
//		char buffer[2];
		printf("\nDo you want to insert(i), remove(r), print(p) printbackwards(b), or exit(e)");
		if (fgets(buffer, 2, stdin) != NULL)
		{
			buffer[1] = '\0';
			if (buffer[0] == 'e') 
			{	
				if (head == NULL) {return 1;} //catches removal is no items are in the list 
				cleanall(head);
				//free(buffer);
				return 1;
			}
			else if (buffer[0] == 'i')
			{
				insert();
			}
			else if (buffer[0] == 'r')
			{	if (head == NULL) {
					printf("Nothing to remove, try inserting first");
				}
				else {
				printf("\nWhat Artist do you want to delete\n");
				if (fgets(buffer, BUFFERSIZE, stdin) != NULL) {
					int iijidi = 0;
				}
				if (fgets(buffer, BUFFERSIZE, stdin) != NULL) {
					int len = (int)strlen(buffer);
					buffer[len - 1] = '\0';
					char * artist =(char *)malloc(len);
					strcpy(artist, buffer);
					removeMp3(artist, head);
					printf("songs made by given artist have been removed, press Enter to continue");

				}
				
				}
			}
			else if (buffer[0] == 'p')
			{
				printMp3(head);

			}
			else if (buffer[0] == 'b')
			{
			printMp3Rev(tail);
			}
			else {
			printf("Invalid input, please inpute i, r, p, b, or e");
			//fflush(stdout);
			}
			int len = (int) strlen(buffer); 
			if (buffer[len-1] != '\n') { 
			// check for buffer overflow 
			int c; 
			while ((c=getchar()) != '\n' && c != EOF){    // clear stdin
			}
			}
		//fgets(buffer, BUFFERSIZE, stdin);
			
		}
	
	}
}

