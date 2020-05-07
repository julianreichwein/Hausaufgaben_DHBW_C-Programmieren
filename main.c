#include <stdio.h>
#include <stdlib.h>

int main()
{
	int xlen=5;
	int ylen=5;
	
	int **mat=malloc(sizeof(int)*xlen);
	
	for(int i=0; i<xlen; i++)
	{
		mat[i] = malloc(sizeof(int)*ylen);
	}
	
	printf("Values of mat: \n");
	for(int y=0; y<xlen; y++)
	{
		for(int x=0; x<ylen; x++)
		{
			printf("%d - %d : %d\n",x,y,mat[x][y]);
		}
		printf("\n");
	}
	
	
	
	
	
	return 0;
}