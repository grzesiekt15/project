#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//poczatek funkcji los, ktora to losuje elemnty do  tablicy o stopniu podanym przez uzytkownika, nastepnie wypisuje ja
los(int size, int j, int i)
{
	printf("Podaj rozmiar tablicy: ");
	scanf("%d",&size);
	int array[size][size];
	for(i=0; i<size;i++)
	{
		for(j=0; j<size;j++)
		{
			array[i][j] = rand()%10;
		}
	}
	printf("Twoja tablica: \n\n");
	i =0; j=0;
	while(i<size)
	{
		j=0;
		printf("| ");
		while(j<size)
		{
			printf("%d ",array[i][j]);
			j++;
		}
		printf("|\n");
		i++;
	}
	printf("\n");
}
int main()
{
    int size, j,i;
    // losowanie liczb i zapisywanie ich do tablicy jednowymiarowej
	srand(time(0));
    los(size,i,j);
	/*int i, k;
	int suma_i, suma_k;
    int tablica[3][3] =
    {
        {3,5,8},
        {4,6,1},
        {7,2,1}, // gotowe elementy w tablicy
    };
    for(i = 0;  i<3; i++)
     // w tej petli, wypisujemy indeksy wierszy i kolumn oraz wartosci im przypisane,
	 // np: W[0]K[0]: 3, ozn to ze wartosc 3 znajduje sie 'pod' wierszem o indeksie 0 i kolumnie rowniez o indeksie 0
	 // oprocz tego liczymy i wypisujemy sume liczb w kazdym wierszu
    for(i=0;i<3;i++)
    {
    	for(k=i; k<3; k++)
    	suma_i = 0;
    	for(k=0;k<3;k++)
    	{
    		printf("W[%d]K[%d]: %d, ",i,k, tablica[i][k]);
    		printf("\n");
			suma_i += tablica[i][k];
		}
		printf("\n");
		//liczenie sumy w danym wierszu
		printf("|Suma dla W[%d] = %d|\n",i,suma_i);
		printf("\n");
	}
	//liczenie sumy w danej kolumnie
	for(i=0;i<3;i++)
	{
		suma_k = 0;
		for(k=0; k<3; k++)
		{
			suma_k += tablica[k][i];
		}
		printf("|Suma dla K[%d]: %d|\n",i,suma_k);
	}
*/ return 0;
}
