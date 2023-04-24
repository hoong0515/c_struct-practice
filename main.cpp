#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID_LEN 8
#define NAME_LEN 11

typedef struct{
	char id[ID_LEN];
	char name[NAME_LEN];
	int math, eng;
} STUDENT;

void show(STUDENT** list, int num);
void add(STUDENT** list, int* pnum);
void search(STUDENT** list, int num);
void entstd(STUDENT** list, int num);

int main()
{
	char menu = 0;
	int num = 0;
	int* pnum = &num;
	printf("How many students? ");
	scanf("%d", &num);
	getchar();
	printf("\n");
	STUDENT** list = NULL;
	list = (STUDENT**)malloc(sizeof(STUDENT*) * num);
	for(int i = 0; i < num; i++)
	{
		*(list + i) = (STUDENT*) malloc(sizeof(STUDENT));
	}
	entstd(list, num);
	for(;;)
	{
		printf("<Select Menu>\n");
		printf("Press 1 to 'SHOW' the scores.\n");
		printf("Press 2 to 'ADD' a new student.\n");
		printf("Press 3 to 'SEARCH' a student.\n");
		printf("Press 4 to 'EXIT'\n");
		scanf("%c", &menu);
		getchar();
		switch(menu)
		{
			case '1':
				{
					show(list, num);
					break;
				}
			case '2':
				{
					add(list, pnum);
					break;
				}
			case '3':
				{
					search(list, num);
					break;
				}
			case '4':
				{
					printf("Bye!\n");
					list = NULL;
					free(list);
					return 0;
				}
			default:
				{
					printf("\n\n");
					break;
				}
		}
	}
}

void show(STUDENT** list, int num)	// 'SHOW' function
{
	float avg = 0;
	for(int i = 0; i < 80; i++)
	{
		printf("-");
	}
	printf("\n");
	printf("STUDENT ID    NAME          MATH SCORE    ENGLISH SCORE AVERAGE SCORE\n");
	for(int j = 0; j < num; j++)
	{
		avg = (float) ((*(list + j))->eng + (*(list + j))->math) / 2;
		printf("%s       %-10s    %-3d           %-3d           %-5.1f\n", (*(list + j))->id, (*(list + j))->name, (*(list + j))->math, (*(list + j))->eng, avg);
	}
	for(int i = 0; i < 80; i++)
	{
		printf("-");
	}
	printf("\n\n");
	return;
}
void add(STUDENT** list, int* pnum)	//'ADD' function
{
	*pnum += 1;
	list = (STUDENT**)realloc(list, sizeof(STUDENT*) * (*pnum));
	*(list + (*pnum)) = (STUDENT*)malloc(sizeof(STUDENT));
	printf("Enter data for new student\n");
	printf("ID: ");
	scanf("%s", (*(list + (*pnum) - 1))->id);
	getchar();
	printf("NAME: ");
	scanf("%s", (*(list + (*pnum) - 1))->name);
	getchar();
	printf("Math score: ");
	scanf("%d", &((*(list + (*pnum) - 1))->math));
	getchar();
	printf("English score: ");
	scanf("%d", &((*(list + (*pnum) - 1))->eng));
	getchar();
	printf("\n");
	show(list, *pnum);
	return;
}
void search(STUDENT** list, int num)	//'SEARCH' function
{
	int i = 0;
	char id[ID_LEN];
	printf("Enter student ID: ");
	scanf("%s", id);
	getchar();
	while(strcmp(id, (*(list + i))->id) != 0)
	{
		i++;
		if(i > num - 1)
			break;
	}
	if(strcmp(id, (*(list + i))->id) == 0)
	{
		printf("ID: %s\n", (*(list + i))->id);
		printf("NAME: %s\n", (*(list + i))->name);
		printf("Math score: %d\n", (*(list + i))->math);
		printf("English score: %d\n", (*(list + i))->eng);
		printf("Average score: %.1f\n", (float) ((*(list + i))->math + (*(list + i))->eng) / 2);
	}
	else
	{
		printf("The ID didn't match with any student's ID\n");
	}
	printf("\n\n");
	return;
}
void entstd(STUDENT** list, int num)	//function for enter data for students
{
	for(int i = 0; i < num; i++)
	{
		printf("Enter data for student No.%d\n", i + 1);
		printf("ID: ");
		scanf("%s", (*(list + i))->id);
		getchar();
		printf("NAME: ");
		scanf("%s", (*(list + i))->name);
		getchar();
		printf("Math score: ");
		scanf("%d", &((*(list + i))->math));
		getchar();
		printf("English score: ");
		scanf("%d", &((*(list + i))->eng));
		getchar();
		printf("\n");
	}
	return;
}
