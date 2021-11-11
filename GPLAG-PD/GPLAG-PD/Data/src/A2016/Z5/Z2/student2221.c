#include <stdio.h>
#include <ctype.h>

int JednakeSu(char rijec1[100], char rijec2[100])
{
    int i = 0;
    while(rijec1[i] != '\0')
    {
        if(rijec1[i] != rijec2[i]) return 0;
        i++;
    }
    if(rijec1[i] != '\0' || rijec2[i] != '\0') return 0;
    return 1;
}

long DajSljedecuRijec(char ulazna[100], char zaVratiti[100], long pos)
{
    FILE* f = fopen(ulazna, "r");
    fseek(f, 0, SEEK_END);
    if(ftell(f) == pos){ 
        fclose(f);
        return pos;
    }
    fseek(f, pos, SEEK_SET);
    char c = ' ';
    while(!feof(f) && !isalpha(c))
        c = fgetc(f);
    int brojac = 0;
    while(!feof(f) && isalpha(c))
    {
        zaVratiti[brojac] = c;
        brojac++;
        c = fgetc(f);
    }
    zaVratiti[brojac] = '\0';
    pos = ftell(f);
    fclose(f);
    return pos;
}

int BrojPonavljanjaRijeci(char ulazna[100], char rijec[100])
{
    FILE* f = fopen(ulazna, "r");
    fseek(f, 0, SEEK_END);
	long krajFajla = ftell(f);
	fclose(f);
	long brojac = 0;
	int brojRijeci = 0;
	while(brojac < krajFajla)
	{
	    char s[100] = {'\0'};
	    brojac = DajSljedecuRijec(ulazna, s, brojac);
	    if(JednakeSu(rijec, s)) brojRijeci++;
	}
	return brojRijeci;
}

int NalaziSe(char skup[10][11], char element[100])
{
    int i = 0;
    for(i; i<10; i++)
    {
        if(JednakeSu(skup[i], element)) return 1;
    }
    return 0;
}

int porediRijeci(char prvaRijec[20], char drugaRijec[20])
{
	int i = 0;
	while(prvaRijec[i] != '\0' && drugaRijec[i] != '\0')
	{
		if(prvaRijec[i] < drugaRijec[i]) return -1;
		else if(drugaRijec[i] < prvaRijec[i]) return 1;
		i++;
	}
	if(prvaRijec[i] != '\0') return 1;
	else if(drugaRijec[i] != '\0') return -1;
	else return 0;
}

void RijeciKojeSeNajvisePonavljaju(char ulazna[100], char zaVratiti[10][11])
{
    /*
    //1. Uzimam sljedecu rijec
    2. Provjerim da li se nalazi u var. zaVratiti
    3. Prebrojim koliko se nalazi u fajlu ta rijec
    4. Ako se nalazi vise od brojaPon, spustamo sve dole, i ubacujemo je
    */
    int brojPon[10] = {0};
    FILE* f = fopen(ulazna, "r");
    fseek(f, 0, SEEK_END);
	long krajFajla = ftell(f);
	fclose(f);
	long brojac = 0;
	while(brojac < krajFajla)
	{
	    char rijec[100] = {'\0'};
	    brojac = DajSljedecuRijec(ulazna, rijec, brojac);
	    int e = 0;
	    while(rijec[e] != '\0')
	        e++;
	    if(NalaziSe(zaVratiti, rijec) || e>=10) continue;
	    int brojPonavljanja = BrojPonavljanjaRijeci(ulazna, rijec);
	    int j = 0;
	    for(j; j<11; j++)
	    {
	        if(j < 10 && brojPon[j] < brojPonavljanja)
	        {
	            break;
	        }
	    }
	    if(j == 10) continue;
	    int k = 9;
	    for(k; k > j ; k--)
	    {
	        int m = 0;
	        brojPon[k] = brojPon[k-1];
	        while(zaVratiti[k-1][m] != '\0')
	        {
	            zaVratiti[k][m] = zaVratiti[k-1][m];
	            m++;
	        }
	        zaVratiti[k][m] = '\0';
	    }
	    
	    k = 0;
	    while(rijec[k] != '\0')
	    {
	        zaVratiti[j][k] = rijec[k];
	        k++;
	    }
	    brojPon[j] = brojPonavljanja;
	    zaVratiti[j][k] = '\0';
	}
    int i = 0, j = 0;    
    for(i = 0; i < 10; i++)
    {
        j = i+1;
        while(j < 10 && brojPon[i] == brojPon[j] && porediRijeci(zaVratiti[i], zaVratiti[j]) == 1)
        {
            char m[11] = {'\0'};
            int k = 0;
            while(zaVratiti[i][k] != '\0')
            {
                m[k] = zaVratiti[i][k]; k++;
            }
            k = 0;
            while(zaVratiti[j][k] != '\0')
            {
                zaVratiti[i][k] = zaVratiti[j][k]; k++;
            }
            zaVratiti[i][k] = '\0';
            k = 0;
            while(m[k] != '\0')
            {
                zaVratiti[j][k] = m[k]; k++;
            }
            zaVratiti[j][k] = '\0';
        }
    }
    
}

void kompresuj(char ulazna[100], char izlazna[100])
{
    char izdvojeneRijeci[10][11] = {{'\0'}};
    //naci 10 rijeci koje se najvise ponavljaju
    RijeciKojeSeNajvisePonavljaju(ulazna, izdvojeneRijeci);
    //upisujemo redom izdvojene rijeci
    FILE* f = fopen(izlazna, "w");
    int i = 0;
    while(i < 10 && izdvojeneRijeci[i][0] != '\0')
    {
        int j = 0;
        while(izdvojeneRijeci[i][j] != '\0')
        {
            fputc(izdvojeneRijeci[i][j], f);
            j++;
        }
        fputc('\n', f);
        i++;
    }
    fputc('\n', f);
    FILE* f1 = fopen(ulazna, "r");
    
    
    while(!feof(f1))
    {
        char c = '1';
        do
        {
            c = fgetc(f1);
            if(isalpha(c)) break;
            if(feof(f1)) break;
            fputc(c, f);
        }while(!feof(f1) && !isalpha(c));
        if(feof(f1)) break;
        char rijec[100] = {'\0'};
        int brojac = 0;
        do
        {
            rijec[brojac] = c;
            brojac++;
            if(feof(f1)) break;
            c = fgetc(f1);
        }while(!feof(f1) && isalpha(c));
        
        if(NalaziSe(izdvojeneRijeci, rijec))
        {
            for(i = 0; i<10; i++)
                if(JednakeSu(rijec, izdvojeneRijeci[i]))
                    break;
            fputc(20 + i, f);
        }else
        {
            for(i = 0; i<brojac; i++)
                fputc(rijec[i], f);
        }
        if(feof(f1)) break;
        else fputc(c, f);
    }
	
    fclose(f);
    fclose(f1);
    //zamijeniti te rijeci i upisati izlaznu
    printf("Datoteka kompresovana.\n");
}

void dekompresuj(char ulazna[100], char izlazna[100])
{
    char izdvojeneRijeci[10][11] = {{'\0'}};
    int brojac = 0;
    FILE* f = fopen(ulazna, "r");
    while(1)
    {
        char rijec[100] = {'\0'};
        fgets(rijec, 100, f);
        int i = 0;
        
        while(rijec[i] != '\n')
        {
            izdvojeneRijeci[brojac][i] = rijec[i];
            i++;
        }
        izdvojeneRijeci[brojac][i] = '\0';
        brojac++;
        if(izdvojeneRijeci[brojac - 1][0] == '\0')break;
    }
    FILE* f1 = fopen(izlazna, "w");
    
    while(!feof(f))
    {
        char c = fgetc(f);
        if(c == EOF) break;
        if(20 <= c && c<=29)
        {
            int i = 0;
            while(izdvojeneRijeci[c - 20][i] != '\0')
            {
                fputc(izdvojeneRijeci[c-20][i], f1);
                i++;
            }
        }else
            fputc(c, f1);
    }
    fclose(f);
    fclose(f1);
    printf("Datoteka dekompresovana.\n");
}

int main() {
    while(1){
        printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
        int c = -1;
        scanf("%i", &c);
        if(c == 0) break;
        char su[50] = {'\0'};
        char si[50] = {'\0'};
        printf("Unesite ime ulazne datoteke: ");
        scanf("%s", &su);
        printf("Unesite ime izlazne datoteke: ");
        scanf("%s", &si);
        if(c == 1)
            kompresuj(su, si);
        else
            dekompresuj(su, si);
    }
    return 0;
}
