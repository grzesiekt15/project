#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//funkcja choice przyjmuje wartosc zmiennej value i na tej podstawie uruchamia odpowiednia funkcje
choice(int value)
{
	if(value == 1) los();

	//else if(value == 2) ready();

	else if(value == 2) yours();

}
//funkcja remove usuwa plik, bedzie ona na koncu programu a wiec plik z wynikiem po skonczonym programie zostanie usuniety
void removee()
{
    if( remove( "file.txt" ) == -1 )
    perror( "Nie mozna usunac pliku!" );
   else
      printf( "Usunieto plik 'file.txt'" );
}

//funkcja poczatkowa pozwalajaca na wybranie z jakiej tablicy bedzie korzystal program
welcome(makechoice)
{
	printf("Start programu...");
    printf("Wpisz:\n '1' aby wylosowac nowa tablice\n '2' aby utworzyc wlasna tablice");
	do
    {
        printf("\nWprowadz: ");
        scanf("%d",&makechoice);
    }
    while(makechoice != 1 && makechoice != 2);
}
//funkcja z gotowymi szablonami tablic(macierzy)
/*ready()
{
    int select;
	int i = 0;
	int j = 0;
	printf("1.\n[16,11,9]\n[13,27,1]\n[39,19,3]\n\n");
	printf("2.\n[2,77,5,83]\n[9,44,1,24]\n[65,8,0,37]\n[33,25,2,6]\n\n");
	printf("3.\n[31,4,8,22,13]\n[3,21,66,99,5]\n[16,28,4,10,3]\n[70,81,4,7,69]\n[23,52,4,11,3]\n\n");
	printf("Wybierz tablice z 3 podanych. ");
	do
    {
        printf("Twoj wybor: ");
        scanf("%d",&select);
    }while(select != 1 && select != 2 && select != 3 );

	if (select == 1) tab1();
	else if (select == 2) tab2();
    else if(select == 3 ) tab3();
}
//koniec funkcji ready
//funkcja tab1 tworzaca macierz 3 stopnia
tab1()
{
	int i, j;
	int array[3][3] = {{16,11,9},{13,27,1},{39,19,3}};
	printf("Twoja tablica: \n\n");
	while(i <3)
    {
        j=0;
        printf("| ");
        while(j<3)
        {
            printf("%d ",array[i][j]);
            j++;
        }
        printf("|\n");
        i++;
    }
    printf("\n");
	count2(3,array);
}
//koniec funkcji tab1
//funkcja tab2 tworzaca macierz 4 stopnia
tab2()
{
    int i,j;
	int array[4][4] = {{2,77,5,83},{9,44,1,24},{65,8,0,37},{33,5,2,64},};
	printf("Twoja tablica: \n\n");
	while(i<4)
	{
		j=0;
		printf("| ");
		while(j<4)
		{
			printf("%d ",array[i][j]);
			j++;
		}
		printf("|\n");
		i++;
	}
	printf("\n");
	count2(4,array);
}
//koniec funkcji tab2
//funkcja tab3 tworzaca macierz 5 stopnia
tab3()
{
    int i,j;
	int array[5][5] = {{31,4,8,22,13},{3,21,66,99,5},{16,28,4,10,3},{70,81,4,7,69},{23,52,4,11,3},};
	printf("Twoja tablica: \n\n");
	while(i<5)
	{
		j=0;
		printf("| ");
		while(j<5)
		{
			printf("%d ",array[i][j]);
			j++;
		}
		printf("|\n");
		i++;
	}
	printf("\n");
	count2(5,array);
}*/
//koniec funkcji tab3
//funkcja yours pozwala wprowadzic wlasne elementy do tablicy(macierzy) (elemntami moga byc liczby 0 - 9)
int yours()
{

    FILE *fp;
    int size;
    printf("Podaj rozmiar tablicy: ");
	scanf("%d",&size);
    int array[size][size];
    int i, j;
    fp  = fopen("tablica.txt","w");
    printf("\nWprowadz elementy(tylko z zakresu 0-9): \n");

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
        printf("\n");
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
    printf("\n");
    count(size,array);
}
int count(int size, int array[size][size])
{
     clock_t start = clock() ;
    //..
    int i,j,rowsum,columnsum,rowindex,columnindex = 0;
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
        }
        write(rowsum, columnsum,rowindex);
        //printf("Suma W[%d]: %d, Suma K[%d]: %d\n",i,rowsum,i,columnsum);
    }
        read();
        printf( "Czas wykonywania: %lu s\n", (clock() - start)/CLOCKS_PER_SEC );
}
//koniec funkcji count
//funkcja count2
int count2(int size, int array[size][size])
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
        write(rowsum, columnsum,rowindex);
       // printf("Suma W[%d]: %d, Suma K[%d]: %d\n",i,rowsum,i,columnsum);
    }
    read();
}
//koniec funkcji count
//funkcja write
write(int rowsum, int columnsum, int rowindex)
        {
            FILE * file;
            if (rowsum > columnsum)
            {
                file = fopen("file.txt","a+");
                if(file==NULL)
                {
                    printf("Nie mozna otworzyc pliku");
                    return 1;
                }
                fprintf(file,"%d  ",rowindex); //zapisanie do pliku indeksow wierszy spelniajacych warunek
                fclose(file);
            }
        }
//funkcja read
 read()
    {
                FILE *file;
        char index[300];
        file = fopen("file.txt","r");
            if(file==NULL)
            {
                printf("Nie mozna otworzyc pliku");
                return 1;
            }
        fgets(index,300,file);
        fclose(file);
        printf("\n");
        printf("Numery wierszy spelniajace warunek: %s",index);
    }
//koniec funkcji read
//koniec funkcji write
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
	if(size <=10) //dla lepszej widocznosci i przejrzystoci program bedzie pokazywal tablice max 10 stopnia
    {
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
	printf("\n\n");
    }
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
	FILE *file;
	removee();

	/*char delete[255];
    file = fopen("file.txt","w");
    fprintf("%s",delete);
    fclose(file);*/
    return 0;
}
