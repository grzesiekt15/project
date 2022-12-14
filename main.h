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
//funkcja smartopen otwiera plik nic do niego nie wpisujac, czyniac go w ten sposob pustym
// po to aby wyniki nie mieszaly sie
smartopen()
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
