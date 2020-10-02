

typedef struct _review
	{
	char* review;

	struct _review *next;

	}
	REVIEW_T;

typedef struct _movie
	{
	char *movieName;
	int movieType;
	struct _movie *next; /* Next movie in the list */
	
	REVIEW_T *reviewHeads;

	}
	MOVIE_T;

typedef struct _user
	{
	char *username;
	char *password;
	char *email;
	int movieType;
	struct _user *next; /* Next user in the list */

	REVIEW_T *reviewUserHead;

	}
	USER_T;


MOVIE_T* findFirstRiver();

MOVIE_T* findMovieByName(char *name);

int addMovie(char *name,int movieType);

void printAllMovie();