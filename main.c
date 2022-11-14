#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//funkcja choice przyjmuje wartosc zmiennej value i na tej podstawie uruchamia odpowiednia funkcje
choice(int value)
{
	if(value == 1) los();

	else if(value == 2) ready();

	else if(value == 3) yours();

}
//funkcja poczatkowa pozwalajaca na wybranie z jakiej tablicy bedzie korzystal program
welcome(makechoice)
{
	printf("Start programu...");
    printf("Wpisz:\n '1' aby wylosowac nowa tablice\n '2' aby skorzystac z szablonow\n '3' aby utworzyc wlasna tablice");
	do
    {
        printf("\nWprowadz: ");
        scanf("%d",&makechoice);
    }
    while(makechoice != 1 && makechoice != 2 && makechoice != 3 );
}
//funkcja z gotowymi szablonami tablic(macierzy)
ready()
{
    int select;
	int i = 0;
	int j = 0;
	printf("1.\n[16,11,9]\n[13,27,1]\n[39,19,3]\n\n");
	printf("2.\n[2,77,5,83]\n[9,44,1,24]\n[65,8,0,37]\n[33,25,2,6]\n\n");
	printf("3.\n[31,4,8,22,13]\n[3,21,66,99,5]\n[16,28,4,10,3]\n[70,81,4,7,69]\n[23,52,4,11,3]\n\n");
	printf("Wybierz tablice z 3 podanych: ");
	scanf("%d",&select);

	//if (select == 1) tab1();
	//else if (select == 2) tab2();
	//else if(select == 3 ) tab3();
	//else printf("Podaj odpowiednia wartosc");
}

//koniec funkcji ready
//koniec funkcji welcome
int yours()
{
    FILE *fp;
    int size;
    printf("Podaj rozmiar tablicy: ");
	scanf("%d",&size);
    int array[size][size];
    int i, j;
    fp  = fopen("tablica.txt","w");
    printf("\nWprowadz elementy: \n ");

    //wpisywanie podanych przez uzytkownika liczb do tablicy
    for(i=0;i<size;i++)
    {
        printf("Wiersz[%d]: \n",i);
        for(j=0;j<size; j++)
        {
            //petla do while wygodniejsza choc nie dziala jak powinna
           /* int k = 0;
            do
            {
                scanf("%d",&array[i][j]);
              // printf("%d,%d ,%d , %d",i,j,array[i][j],k);
              k++;
            }
            while(array[i][j] <= 9 && k<1);*/
            scanf("%d",&array[i][j]);
            if(array[i][j] > 9)
            {
                printf("Nalezy podac liczbe z zakresu 0-9");
                return 0;
            }

        }

    }
    fwrite(array,sizeof(int),size,fp);
    printf("Twoja tablica:\n\n");
     for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf(" %d ",array[i][j]);
        }
        printf("\n");
    }
    fclose(fp);
  /*  FILE *plik;

    int tablica[5] = {0};

    plik = fopen("tablica.txt","r");
    if (plik == NULL)
    {
        printf("Nie");
    }
    fgets(plik,5,tablica[5]);

    fclose(plik);

    for (int i=0; i<5; i++)
    {
        printf("%d",tablica[i]);
    }*/

}
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
    printf("Podaj rozmiar tablicy: ");
	scanf("%d",&size);
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
    int makechoice;
    int value = welcome(makechoice); //przypisanie wartosci jaka zwraca funkcja do zmiennej value
    int size, j,i;
	choice(value);
    //los(size);
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
