#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int welcome();
int los();
int yours();
int count(int **tablica, int rozmiar);
int write(int indeks,int licznik);
//funkcja poczatkowa pozwalajaca na wybranie z jakiej tablicy bedzie korzystal program
int welcome()
{
    int makechoice;
	printf("Start programu...");
    printf("Wpisz:\n '1' aby wylosowac nowa tablice\n '2' aby utworzyc wlasna tablice\n");
	do
    {
        printf("Wprowadz: ");
        scanf("%d",&makechoice);
    }
    while(makechoice != 1 && makechoice != 2);
    //return makechoice;
}
//koniec funkcji welcome
//funkcja count odpowiada za policzenie sumy elementow w kazdym wierszu i kolumnie,
//porownanie ich oraz wypisanie na ekranie i wpisanie do pliku indeksy wierszy spelniajacych glowny warunek
//dodatkowo zapisujemy zaleznosc czasu trwania algorytmu do rozmiaru tablicy(macierzy) do pliku
int count(int **tablica, int rozmiar)
{
    FILE *file;
    file = fopen("file.txt", "a+");
    //smartopen();
    clock_t start = clock() ;
    // count = 1;
    printf("Ilosc elementow: %d\n\n1",rozmiar*rozmiar);
    int i,j,rowsum,columnsum,rowindex,columnindex;
    i,j,rowsum,columnsum,rowindex,columnindex = 0;
    printf("Indeksy wierszy spelniajace warunek(liczymy od zera): ");
    for(i=0;i<rozmiar;i++)
    {
        rowsum = 0;
        columnsum = 0;
        for(j=0;j<rozmiar;j++)
        {
            rowsum += tablica[i][j]; //liczenie sumy elementow w wierszu np. tablica[0][0] + tablica[0][1] + ... + tablica[0][n] gdzie n to rozmiar - 1
            columnsum += tablica[j][i];	//liczenie sumy elementow w kolumnie np. tablica[1][0] + tablica[2][0] + .. + tablica[n][0] - = -
            rowindex = i;
            columnindex = i;
        }
        //if(rozmiar<=5) printf("Suma W[%d]: %d, Suma K[%d]: %d\n",i,rowsum,i,columnsum); //wypisanie sumy dla macierzy max 5 stopnia, aby spradzic ze dziala
        if(rowsum > columnsum) //glowny warunek, wypisanie indeksy spelniajacych go na ekranie oraz wpisanie do pliku
        {
            fprintf(file,"%d ",i);
            printf("%d ",i);
           // write(i,count);
        }
    }
    fclose(file);
    printf("\nCzas wykonywania: %lu ms\n", clock() - start ); // czas wykonania algorytmu tzn. obliczanie sum, porownanie ich oraz wypisanie na ekranie i zapis do pliku
    int czas = clock() - start;
    FILE *wyniki;
    wyniki = fopen("wyniki.txt","a+");
    fprintf(wyniki,"\n   %d         %dms",rozmiar,czas); //zapis wynikow pomiarow do pliku
    fclose(wyniki);
}
//funkcja los odpowiada za losowanie tablicy o rozmiarze podanym przez uztkownika, wywolujemy funkcje count
int los()
{
    int size;
    printf("Podaj rozmiar tablicy: ");
	scanf("%d",&size);
    int i,j;
    int **array; //deklaracja tablicy, upraszczajac pierwszy wskaznik wskazuje na wiersz, drugi na kolumne(konkretna wartosc)
    array = malloc( size * sizeof(int*)); //typ int zajmuje 4B a wiec mnozymy ta wartosc razy rozmiar
    if ( array == NULL )
    {
        printf("Nie mozna przydzielic pamieci!\n");
    }
    for(i=0;i<size;i++) array[i] = malloc(size * sizeof(int*)); //przydzielenie pamięć dla każdego wiersza

          for(i=0; i<size;i++)
        {
            for(j=0; j<size;j++)
            {
                array[i][j] = rand()%10;
			}
			//printf("\n");
        }
        //warunek z petlami ponizej - wyswietlanie tablicy max 5 stopnia - dla przejrzystosci
        if(size<=5)
        {
            for(i=0; i<size;i++)
            {
                for(j=0; j<size;j++)
                {
                    printf(" %d ",array[i][j]);
                }
                printf("\n");
            }

        }
    count(array, size); //wywolanie funkcji count przyjmujacej tablice z funkcji los() jako argument oraz jej rozmiar(stopien)
}
//koniec funkcji los
//funkcja write odpowiedzialna jest za zapis do pliku indeksow wierszy spelniajacych warunek
//lepszym rozwiazaniem byloby zapisanie wszystkich indeksow do tablicy i otworzenie pliku tylko jeden raz
//aby kazdy element z tablicy zapisac do pliku; w tym przypadku plik otwieramy wielokrotnie co obciaza sprzet
//ostatecznie nie korzystamy z tej funkcji w programie
int write(int indeks,int licznik)
{
    FILE * file;
    int k;
    file = fopen("file.txt","a+");
    if(file==NULL)
    {
        printf("Nie mozna otworzyc pliku");
        return 1;
    }
    fprintf(file,"%d ",indeks);
    fclose(file);
}
//funkcja yours odpowiada za utworzenie macierzy, stopien macierzy i elementy podaje uzytkownik
int yours()
{
    FILE *tablica;
    int size;
    int i,j;
    printf("Podaj rozmiar tablicy: ");
	scanf("%d",&size);
	int **array; //deklaracja tablicy
    array = malloc( size * sizeof(int*)); //przydzielanie pamieci dla adresow
    if ( array == NULL )
    {
        printf("Nie da rady!\n");
    }
    for(i=0;i<size;i++) array[i] = malloc(size * sizeof(int*));
    printf("\nWprowadz elementy(zakres 0-9): \n");

    //wpisywanie podanych przez uzytkownika liczb do tablicy
    for(i=0;i<size;i++)
    {
        printf("Wiersz[%d]: \n",i);
        for(j=0;j<size; j++)
        {
            do
            scanf("%d",&array[i][j]);
            while(array[i][j]>9);
        }
        printf("\n");
    }
    //wypisanie tablicy na ekranie;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size; j++)
        {
           printf(" %d ",array[i][j]);
        }
        printf("\n");
    }
    //zapis utworzonej tablicy do pliku
    tablica = fopen("tablica.txt","a+");
    fprintf(tablica,"\nTablica:\n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            fprintf(tablica," %d ",array[i][j]);
        }
        fprintf(tablica,"\n");
    }
    fclose(tablica);
    printf("\n");
    count2(size,array);
}
count2(int rozmiar, int **tablica)
{
    FILE *file2;
    file2 = fopen("file2.txt", "a+");
    //smartopen();
    clock_t start = clock() ;
    //int count = 1;
    printf("Ilosc elementow: %d\n\n1",rozmiar*rozmiar);
    int i,j,rowsum,columnsum,rowindex,columnindex;
    i,j,rowsum,columnsum,rowindex,columnindex = 0;
    printf("Indeksy wierszy spelniajace warunek(liczymy od zera): ");
    for(i=0;i<rozmiar;i++)
    {
        rowsum = 0;
        columnsum = 0;
        for(j=0;j<rozmiar;j++)
        {
            rowsum += tablica[i][j]; //liczenie sumy elementow w wierszu np. tablica[0][0] + tablica[0][1] + ... + tablica[0][n] gdzie n to rozmiar - 1
            columnsum += tablica[j][i];	//liczenie sumy elementow w kolumnie np. tablica[1][0] + tablica[2][0] + .. + tablica[n][0] - = -
            rowindex = i;
            columnindex = i;
        }
        //if(rozmiar<=5) printf("Suma W[%d]: %d, Suma K[%d]: %d\n",i,rowsum,i,columnsum); //wypisanie sumy dla macierzy max 5 stopnia, aby spradzic ze dziala
        if(rowsum > columnsum) //glowny warunek, wypisanie indeksy spelniajacych go na ekranie oraz wpisanie do pliku
        {
            fprintf(file2,"%d ",i);
            printf("%d ",i);
           // write(i,count);
        }
    }
    fprintf(file2, "\n");
    fclose(file2);
    printf("\nCzas wykonywania: %lu ms\n", clock() - start ); // czas wykonania algorytmu tzn. obliczanie sum, porownanie ich oraz wypisanie na ekranie i zapis do pliku
    int czas = clock() - start;
    FILE *wyniki2;
    wyniki2 = fopen("wyniki2.txt","a+");
    fprintf(wyniki2,"\n   %d         %dms",rozmiar,czas); //zapis wynikow pomiarow do pliku
    fclose(wyniki2);
}
int main()
{
    srand(time(0));
    int value = welcome();
    if (value == 1) los();
    if (value == 2) yours();
    return 0;
}




