#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, k;
    int tablica[3][3] =
    {
        {3,5,8},
        {4,2,1}, //przygotowanie tablicy statycznej
        {6,9,7},
    };
    //petla wypisuje elementy tablicy
    for(i = 0;  i<3; i++)
    {
    	for(k=i; k<3; k++)
    	{
    		printf("W[%d]K[%d]: %d, ",i,k, tablica[i][k]);
		}
	}


    return 0;
}
