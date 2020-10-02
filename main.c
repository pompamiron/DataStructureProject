#include <stdio.h>

#include "movieNetwork.h"
#include "movieNetworkBuilder.h"


int main()
	{
	printf("Read\n");
	readNetworkDefinition("database.txt",1);	


	printAllMovie();
	/*
	MOVIE_T* pCurrent = findFirstRiver();
	while (pCurrent != NULL)
		{
		printf("name %s\n",pCurrent->movieName);
		pCurrent = pCurrent->next;
		}
	*/

	}