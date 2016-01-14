/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
long long int func(char *date)
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
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *C;
	if (A == NULL || B == NULL)
		return NULL;
	C = (struct transaction* )malloc((ALen+BLen)*sizeof(struct transaction));
	int j = 0, k = 0;
	for (int i = 0; i < ALen + BLen; i++)
	{
		if ((func(A[j].date) < func(B[k].date)) && (j <= ALen - 1 && k <= BLen - 1))
		{
			C[i] = A[j];
			j++;
		}
		else if ((func(A[j].date) > func(B[k].date)) && (j <= ALen - 1 && k <= BLen - 1))
		{
			C[i] = B[k];
			k++;
		}
		else if ((func(A[j].date) == func(B[k].date)) && (k <= BLen - 1 && j <= ALen - 1))
		{
			C[i] = A[j];
			i++;
			C[i] = B[k];
			j++;
			k++;
		}
		else if (j <= ALen - 1)
		{
			C[i] = A[j];
			j++;
		}
		else
		{
			C[i] = B[k];
			k++;
		}
	}
	return C;
}