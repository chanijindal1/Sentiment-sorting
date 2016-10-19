// C Program for counting sort
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h> 

#define MIN -5
#define MAX 5
#define RANGE (MAX - MIN)
#define MAX_NUMBERS 100

void convert(char*,int*);
void sentimentSort(int*, int, int*);
void printOutput(int*, int, int*);
void striptrailspace( char *);
int len = 0;

 