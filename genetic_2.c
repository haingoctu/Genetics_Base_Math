/*
Hai Tu
COP 3502C
Dr. Szumlanski
Nov 25, 2015
Lab 8: Genetics
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_CHAR 15
#define BASE_FOUR 4

int baseFour(char *seq, int len);
int str_to_int(char *seq, int len);
void baseTen_to_Four(int num);
void baseTen_helper(int num, int n);
void printResults(int num);

int main(void)
{
	int numOfSeq, userSeq, n = 0, num;
	char *seq = malloc(sizeof(char) * MAX_CHAR + 1);
	
	scanf("%d", &numOfSeq);
	while ( n++ < numOfSeq )
	{
		scanf("%s", seq);
		/* Determine if user input is a base10 number or genetic sequence */
		if (seq[0] - '0' >= 1 && seq[0] - '0' <= 9)//if it's a base10 number
		{
			num = atoi(seq);//convert string to integer
			baseTen_helper(num, n);//function converts to genetic sequence
		}
		else//if it's genetic sequence
		{
			userSeq = baseFour(seq, strlen(seq));//function converts to int
			printf("Sequence #%d: %d\n", n, userSeq);//print results
		}
	}
	free(seq);
	return 0;
}

/* 
*	Recursive: Takes in user's genetic sequence and the length of it.
*	returns base10 number.
*/
int baseFour(char *seq, int len)
{
	int newLen = len-1;
	
	if (seq[0] == '\0')
		return;
	
	if (seq[0] == 'A')
		return baseFour(seq+1, newLen ) + 0 * (pow(BASE_FOUR, newLen));
	else if (seq[0] == 'C')
		return baseFour(seq+1, newLen ) + 1 * (pow(BASE_FOUR, newLen));
	else if (seq[0] == 'G')
		return baseFour(seq+1, newLen ) + 2 * (pow(BASE_FOUR, newLen));
	else
		return baseFour(seq+1, newLen ) + 3 * (pow(BASE_FOUR, newLen));
}

/* 
*	takes in user's base10 sequence and current sequence number.
*	helper function that calls baseTen function then prints a new line.
*/
void baseTen_helper(int num, int n)
{
	printf("Sequence #%d: ",n);
	baseTen_to_Four(num);
	printf("\n");
}

/* 
*	Recursive: takes in user's base10 sequence and computes base4
*/
void baseTen_to_Four(int num)
{
	int result;
	
	if (num == 0)
		return;

	result = num%BASE_FOUR;
	baseTen_to_Four(num/BASE_FOUR);
	printResults(result);
}

/* 
*	takes in a num within base4 and prints out the genetic version.
*/
void printResults(int num)
{
		if (num == 0)
			printf("A");
		else if (num == 1)
			printf("C");
		else if (num == 2)
			printf("G");
		else
			printf("T");
}
