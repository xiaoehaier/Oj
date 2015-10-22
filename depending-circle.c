#include <stdlib.h>
#include <stdio.h>
#define FALSE 0
#define TRUE 1

typedef char bool;


bool dfs(bool *isFinding, int **clue, int n, int toFind)
{
	if(isFinding[toFind])
		return FALSE;

	if(!clue[toFind][0])
		return TRUE;

	isFinding[toFind] = TRUE;

	for(int i=1; i<=n; ++i){
		if(clue[toFind][i]){
			if(isFinding[i])
				return TRUE;
			if(!dfs(isFinding, clue, n, i))
				return FALSE;
		}
	}

	isFinding[toFind] = FALSE;
	return TRUE;
}

int main(int argc, char const *argv[])
{
	bool *isFinding;
	int **clue;
	int tCnt, rCnt;

	while(scanf("%d %d\n", &tCnt, &rCnt) != EOF){
		clue = calloc(tCnt, sizeof(bool*));
		isFinding = calloc(tCnt, sizeof(bool));

		for(int i=0; i<tCnt; ++i)
			clue[i] = calloc(tCnt+1, sizeof(bool));
		

		for(int i=0, prior, base; i<rCnt; ++i){
			scanf("%d %d", &prior, &base);
			clue[prior-1][base] = TRUE; 
		}

		if(dfs(isFinding, clue, tCnt, 0))
			printf("YES\n");
		else printf("NO\n");

		//free calloc
		for(int i=0; i<tCnt; ++i)
			free(clue[i]);
		free(clue);
		free(isFinding);
	}

	return 0;
}