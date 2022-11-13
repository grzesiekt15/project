#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//poczatek funkcji count ktora liczy sume elementow w danym wierszu i kolumnie oraz wypisuje te sumy
int count(int size, int array[size][size])
{
    int i,j;
    int rowsum;
    int columnsum;
    int rowindex;
    int columnindex;
    for(i=0;i<size;i++)
    {
        rowsum = 0;
        columnsum = 0;
        for(j=0;j<size;j++)
        {
            rowsum += array[i][j]; //liczenie sumy elementow w wierszu
            columnsum += array[j][i];	//liczenie sumy elementow w kolumnie
            rowindex = i;
            columnindex = i;
            //i = 0, k = 2
        }
            printf("Suma W[%d]: %d, Suma K[%d]: %d\n",i,rowsum,i,columnsum);
    }
}
//koniec funkcji count
//poczatek funkcji los, ktora to losuje elemnty do  tablicy o stopniu podanym przez uzytkownika, nastepnie wypisuje ja
void los(int size)
{
    int array[size][size];
    int i,j;
	for(i=0; i<size;i++)
	{
		for(j=0; j<size;j++)
		{
			array[i][j] = rand()%10;
		}
	}
	printf("Twoja tablica: \n\n");
	i =0; j=0;
	/*for(int k = 0;k<size;k++)
        {
            printf(" %d",k);
        }
        printf(" <-- nr.indeksu");
        printf("\n\n"); */ //tylko gdy tablica jest max 10 stopnia
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
	printf("\n\n");
    count(size,array); //wywolanie funkcji count

}
//koniec funkcji los
int main()
{
    srand(time(0));
    int size, j,i;
	printf("Podaj rozmiar tablicy: ");
	scanf("%d",&size);
    los(size);
  //  count(size,i,j);
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
