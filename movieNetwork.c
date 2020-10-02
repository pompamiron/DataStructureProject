

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "movieNetwork.h"

MOVIE_T *movieListHead = NULL;
MOVIE_T *movieListTail = NULL;

MOVIE_T *userListHead = NULL;
MOVIE_T *userListTail = NULL;


MOVIE_T* findFirstRiver()
	{
	MOVIE_T* pFound = movieListHead;
	return pFound;	
	}

MOVIE_T* findMovieByName(char *name)
	{
	MOVIE_T *pFound = NULL;
	MOVIE_T *pCurrent = movieListHead;
	while((pCurrent != NULL) && (pFound == NULL))
			{
		if(strcmp(pCurrent->movieName,name) == 0)
			{
			pFound = pCurrent;
			}
		
		else
			{
			pCurrent = pCurrent->next;
			}
		}
	return pFound;
	}

void printAllMovie()
	{
	printf("PRINTALLMOVIEFUNCTION\n");
	MOVIE_T* pCurrent = movieListHead;
	while (pCurrent != NULL)
		{
		printf("\tMovie name :%s Type: %d\n",pCurrent->movieName,pCurrent->movieType);
		pCurrent = pCurrent->next;
		}

	}

/* 1 ok -1 มีอยู่แล้ว 0 allocation error */

int addMovie(char *name,int movieType)
	{
	MOVIE_T *pFound = findMovieByName(name);
	
	int status = 1;
	
	if( pFound != NULL)
		{
		status = -1; /*This river is already in the graph.*/
		}
    else
		{
		MOVIE_T *pNew = (MOVIE_T*) calloc(1,sizeof(MOVIE_T));
		char *pName = strdup(name);
		
		if(pNew != NULL)
			{
			/* จะแอดอะไรบ้าง */
			pNew->movieName = pName;
			pNew->movieType = movieType;

			if(movieListHead == NULL) /* The first river in the list. */
				{
				movieListHead = pNew;
				}
			else
				{
				movieListTail->next = pNew; 
				}	
			movieListTail = pNew;
			}
		else
			{
			status = 0; /* Memory allocation error. */
			}
		}	
    return status;
	}
