#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    // losowanie liczb i zapisywanie ich do tablicy jednowymiarowej
    srand(time(0));
	int i=0;
	int tab_los[7];
	while(i<= 6)
	{
		 tab_los[i] = rand()%10;
		 printf("Indeks[%d] = %d; ", i, tab_los[i]);
		 i++;
	}
	//deklaracja zmiennych
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
