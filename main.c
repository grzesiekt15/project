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
//funkcja poczatkowa pozwalajaca na wybranie z jakiej tablicy bedzie korzystal program
welcome(makechoice)
{
	printf("Start programu...");
    printf("Wpisz:\n '1' aby wylosowac nowa tablice\n '2' aby utworzyc wlasna tablice\n");
	do
    {
        printf("Wprowadz: ");
        scanf("%d",&makechoice);
    }
    while(makechoice != 1 && makechoice != 2);
}
//funkcja yours pozwala wprowadzic wlasne elementy do tablicy(macierzy) (elemntami moga byc liczby 0 - 9)
int yours()
{

    FILE *fp;
    long int  size;
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
    fwrite(array,sizeof(int),size,fp); // zapisywanie do pliku tablica.txt tablicy utworzonej przez uzytkownika
    printf("Twoja tablica:\n\n"); // sizeof podaje iloœæ pamiêci w bajtach dp przechowania typu int
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
    smartopen();
    int count = 0;
    int tab[0];
    clock_t start = clock() ;
    int i,j,rowsum,columnsum,rowindex,columnindex = 0;
    printf("Indeksy wierszy spelniajace warunek(liczymy od zera): ");
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
        if(rowsum > columnsum)
        {
            tab[count] = i;
            printf("%d ", tab[count]); //zapisanie wyniku do tablicy
                write(count,tab);
        }
            count +1; // liczenie ile indeksow wierszy spelnia warunek, aby ustalic wielkosc tablicy

        //printf("Suma W[%d]: %d, Suma K[%d]: %d\n",i,rowsum,i,columnsum);
    }
       // read();
        printf("\n");
        printf( "Czas wykonywania: %lu ms\n", clock() - start );
}
//koniec funkcji count
//funkcja smartopen otwiera plik dodajac znak nowej linii aby nowe wyniki programu zapisywaly sie w nowej linii
{
    FILE *file;
    file = fopen("file.txt","a+");
    fprintf(file,"\n");
    fclose(file);
}
//funkcja write odpowiada za zapisanie do pliku indeksow wierszy spelniajacych warunek
//ostatnie wyniki algorytmu zapisane sa w ostatniej linii pliku badz jesli nie mieszcza sie w niej
//przeniesione do nastepnej
write(int count, int tab[count])
{
    FILE * file;
        int i;
        file = fopen("file.txt","a+");
        if(file==NULL)
        {
            printf("Nie mozna otworzyc pliku");
            return 1;
        }
        for(i=0;i<=count;i++)
        {
            fprintf(file,"%d ",tab[i]);
        }
        fclose(file);
}
//koniec funkcji write
// funkcja los, ktora losuje elemnty do tablicy o stopniu podanym przez uzytkownika
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
    return 0;
}
