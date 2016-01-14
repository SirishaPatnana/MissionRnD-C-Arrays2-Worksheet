/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
long long int fun(char *date)
{
	int d, m, y, i, year, mon, day, count = 0, j = 0;
	int b[10];
	for (i = 0; i<10; i++)
		b[i] = (*(date + i) - 48);
	d = (b[0] * 10) + b[1];
	m = (b[3] * 10) + b[4];
	y = (b[6] * 1000) + (b[7] * 100) + (b[8] * 10) + b[9];
	return (d * 1000000) + (m * 10000) + y;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *C;
	if (A == NULL || B == NULL)
		return NULL;
	C = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction));
	int k = -1, j = 0;
	for (int i = 0; i < ALen; i++)
	{
		for (int j = k+1; j < BLen; j++)
		{
			if (fun(A[i].date) == fun(B[j].date))
			{
				C[i] = A[j];
				k = j;
				break;
			}
		}
	}
	if (k == -1)
		return NULL;
	return C;
}