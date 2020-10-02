

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "movieNetwork.h"
#include "movieNetworkBuilder.h"

#define MAXINPUT 128


/* Parse a line from the network builder file. If the
 * syntax is correct, call the addVertex or addEdge
 * function as appropriate. Handle errors and 
 * give feed back if bVerbose is set to true.
 * Arguments
 *   command  - Line read from network builder file
 *   bVerbose - If true, give information about all operations executed
 */
void processCommand(char* command, int bVerbose)
    {
    char typeArgument[MAXINPUT];
    char movieName[MAXINPUT];
    int movieType = 0;

    char userName[MAXINPUT];
    char userPassword[MAXINPUT];
    char userEmail[MAXINPUT];


    int movieRating = 0;
    char movieReview[MAXINPUT];



    if (!strncasecmp(command,"movie",5))
        {
        sscanf(command,"%s %s %d",typeArgument,movieName,&movieType);
        if (bVerbose)
            {
            printf("  Read movie Name:%-10s Type:%-2d \n",movieName,movieType);
            }
        addMovie(movieName,movieType);
        }
    else if (!strncasecmp(command,"user",4)) 
        {
        //sscanf(command,"%s %s %s %s %d",typeArgument,userName,userPassword,userEmail,&movieType);
        //if (bVerbose)
          //  {
         //   printf("  Read user username:%-10s pw: %-10s Email:%-10s Type%-2d\n",userName,userPassword,userEmail,movieType);
           // }
        
        }
    else if (!strncasecmp(command,"review",6))
        {
        //sscanf(command,"%s %s %s %d %s",typeArgument ,userName ,movieName ,&movieRating, movieReview);
        if (bVerbose)
            {
            //printf("  Read review:%-10s pw: %-10s Email:%-10s Type%-2d\n",userName,userPassword,userEmail,movieType);
            } 
        }  
    else
        {
        printf("Error processCommand\n");
        }   
    }


/* Opens and reads a network definition file that is supposed to follow
 * the structure explained above. If 'bVerbose' is true, displays messages
 * as it processes the file, explaining what it is doing.
 * Arguments
 *    filename    -   filename to read, with path
 *    bVerbose    -   if non-zero, print messages as processing goes on
 *                    if zero, prints only error messages
 * Returns 1 if successful, 
 * -1 if any error occurs.
 */  
int readNetworkDefinition(char* filename, int bVerbose)
    {
    int status = 1;

    FILE* pInput = NULL;

    char inputline[128];

    pInput = fopen(filename,"r");
    if (pInput == NULL)
       {
       status = -1;
       printf("Error - cannot open file %s\n", filename);
       }
    else
       {
       if (bVerbose)
           printf(">> Successfully opened file %s\n", filename);

       while (fgets(inputline,sizeof(inputline),pInput) != NULL)
          {
          inputline[strlen(inputline) - 1] = '\0';  
          processCommand(inputline,bVerbose);
          }        
	   fclose(pInput);
       }
    return status;
    }



