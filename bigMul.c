// write your code here cpp

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Pi 3.14

char* bigMul(char* a, char* b)
{
	if(!a || !b) return NULL;

	int al = strlen(a), bl = strlen(b);
	char *result = (char*)calloc(al+bl, sizeof(char));

	for(int i=bl-1; i>=0; --i)
		for(int j=al-1, k=al+i; j>=0; --j, --k){
			result[k] += (a[j]-'0')*(b[i]-'0');
			result[k-1] += result[k]/10;
			result[k] %= 10;
		}

	return result;
}

