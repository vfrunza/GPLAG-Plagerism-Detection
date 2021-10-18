ZADACI SA ISPITA (O.U)

#include <stdio.h>
#include <stdlib.h>


printf("Unesite datum rodjenja %d. studenta: ", i+1);
        scanf("%d,%d,%d", &dan[i], &mjesec[i], &god[i]);
        if ((god[i] % 4 == 0 && god[i] % 100 != 0) || god[i] % 400 == 0)
            p = 1;
        else
            p = 0;
        if (god[i] > 2014)
            c = 0;
        else if (mjesec[i] < 1 || mjesec[i] > 12)
            c = 0;
        else if(
                (dan[i] < 1 || dan[i] > 31)
                 &&
                (mjesec[i] == 1 ||
                 mjesec[i] == 3 ||
                 mjesec[i] == 5 ||
                 mjesec[i] == 7 ||
                 mjesec[i] == 8 ||
                 mjesec[i] == 10 ||
                 mjesec[i] == 12)
                )
            c = 0;
        else if(
                (dan[i] < 1 || dan[i] > 30)
                 &&
                 (mjesec[i] == 4 ||
                  mjesec[i] == 6 ||
                  mjesec[i] == 9 ||
                  mjesec[i] == 11)
                )
            c = 0;
            else if ((dan[i] < 1 || ((dan[i] > 28 && p == 0) || (dan[i] > 29 && p == 1))) && mjesec[i] == 2)
                c = 0;
            else
                c = 1;

        if (c == 0)
        {
            printf("Neispravan datum\n");
            i--;
        }

void izbaci(char* s, char* p)
{
    char trenutna[100];
    int i;
    char *izbaciti, *ostaje;
    char* beze;
    char* pocetak = s;
    while(*s != '\0')
    {
        if((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
        {
            i = 0;
            izbaciti = s;
            while((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
            {
                trenutna[i] = *s;
                i++;
                s++;
            }
            trenutna[i] = '\0';
            beze = trenutna;
            if(iste(beze, p))
            {
                ostaje = ++s;
                while(*ostaje != '\0')
                {
                    *izbaciti = *ostaje;
                    izbaciti++;
                    ostaje++;
                }
                *izbaciti = '\0';
                s = pocetak;
                continue;
            }
            s--;
        }
        s++;
    }
}
char* najcesca1(int vel, char* string)
{
    int i, j, k, l;
    int max = 0;
    int brojac1 = 0, brojac2 = 0;
    char* vratiti;
    char *prva, *druga;
    for(i = 0; i < vel; i++)
    {
        brojac1 = 0;
        for(j = i+1; j < vel; j++)
        {
            prva = &string[i][0];
            druga = &string[j][0];
            if(iste(prva, druga))
                brojac1++;
        }
        if(brojac1 > brojac2)
            max = i;
        brojac2 = brojac1;
    }
    vratiti = &string[max][0];
    return vratiti;
}
int iste(char* s, char* p) // provjerava jesu li dvije rijeci iste
{
    while(*s != '\0' && *p != '\0')
    {
        if(*s != *p)
            return 0;

        s++;
        p++;
    }
    if(*s == '\0' && *p == '\0')
        return 1;
    else
        return 0;
}
void izbaci(char* s, char* p)
{
    char trenutna[100];
    int i;
    char *izbaciti, *ostaje;
    char* beze;
    char* pocetak = s;
    while(*s != '\0')
    {
        if((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
        {
            i = 0;
            izbaciti = s;
            while((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
            {
                trenutna[i] = *s;
                i++;
                s++;
            }
            trenutna[i] = '\0';
            beze = trenutna;
            if(iste(beze, p))
            {
                ostaje = ++s;
                while(*ostaje != '\0')
                {
                    *izbaciti = *ostaje;
                    izbaciti++;
                    ostaje++;
                }
                *izbaciti = '\0';
                s = pocetak;
                continue;
            }
            s--;
        }
        s++;
    }
}
void obrni(int* a, int *b)
{
    int temp;
    b--;
    while(a < b)
    {
        temp = *a;
        *a = *b;
        *b = temp;
        a++;
        b--;
    }
}

#include<stdio.h>
#include<math.h>
/* pretvaranje broja koji je char (string) u integer -> atoi */
int stob(char *s){
    int rez=0;
     int i=0;
    char *pocetak=s;
    while(*s != '\0') s++;
    s--;

    while(s>=pocetak){
        rez+=(*s-'0')*pow(10,i);
        i++;
        s--;
    }
    return rez;
}
/* vracanje recenice naopako */
char* naopako(char* s){
    char *pocetak=s;
    char *s2=s;
    char tmp;
    while(*s != '\0') s++;
    s--;
    while(s >= pocetak){
        tmp=*s;
        *s=*pocetak;
        *pocetak=tmp;
        pocetak++;
        s--;
    }

    return s2;
}

char *normalizacija(char* s){ // presveta normalizacija
    char *pocetak=s;
    char *pocetak2=s;
    char pomocni[100]={'\0'};
    int i=0;
    int slova=0;

while(*s != '\0'){
    if((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')){
        pomocni[i]=*s;
        i++;
    slova=1;
    }
    else{
        if(slova==1){ pomocni[i] = ' ';
        i++;
        slova=0;
        }
    }
    s++;
}
s=pocetak;
i=0;
while(pomocni[i] != '\0'){
*s=pomocni[i];
i++;
s++;
}
*s='\0';
return pocetak;
}

char *samoslova(char *s){ // izbacuje sve osim slova iz stringa
char *pocetak=s;
char pomocni[100]={'\0'};
int i=0;
char *pocetak2=pomocni;
while(*s != '\0'){
if((*s<='Z' && *s>='A') || (*s<='z' && *s>='a')){ // ako je slovo
pomocni[i] = *s;
i++;
}
s++;

}
s=pocetak;
i=0;

while(pomocni[i] != '\0'){
*s=pomocni[i];
i++;
s++;
}
*s='\0';
return pocetak;
}

int palindrom(char *s){ // provjerava jel string palindrom
char *pocetak=s;
char pomocni[100]={'\0'};
int i=0;
char *pocetak2=pomocni;
while(*s != '\0'){
if((*s<='Z' && *s>='A') || (*s<='z' && *s>='a')){ // ako je slovo
pomocni[i] = *s;
i++;
}
s++;
}
s=pocetak;
i=0;

while(pomocni[i] != '\0'){
*s=pomocni[i];
i++;
s++;
}
*s='\0';
s=pocetak;
while(*s!='\0'){
if((*s>='A' && *s<='Z')) *s=*s+32;
      s++;
}
s--;

while(s>=pocetak){
    if((*s>='a' && *s<='z') && (*pocetak>='a' && *pocetak<='z')){
    if(*s != *pocetak) return 0;
    s--;
    pocetak++;
}
}
return 1;
}

void hexadec(int a){ // vraca broj u hex obliku
printf("\n%x",a);
}

char *izbaci(char *s, char a){ // izbaci odredjeno slovo iz stringa
char *pocetak=s;
int i=0;
char pomocni[100]={'\0'};
while(*s != '\0'){
    if(*s != a) {
        pomocni[i]=*s;
        i++;
    }
    s++;
}
s=pocetak;
i=0;
while(pomocni[i] != '\0'){
*s=pomocni[i];
i++;
s++;
}
*s='\0';
return pocetak;
}

char najcesce(char *s){ // nadje najcesce slovo u stringu (case insensitive)
char *pocetak=s;
char *naj='0';
int max=0,novimax=0;
while(*s!='\0'){
if((*s>='A' && *s<='Z')) *s=*s+32;
      s++;
}
s=pocetak;
int i;
for(i=97;i<123;i++){
        char znak=i;
while(*s != '\0'){
    if(*s == i) novimax++;
    s++;
}
if(novimax>max) {
max=novimax;
naj=i;
}
s=pocetak;
novimax=0;
}
return naj;
}

int iste(char* s, char* p) // provjerava jesu li dvije rijeci iste
{
    while(*s != '\0' && *p != '\0')
    {
        if(*s != *p)
            return 0;

        s++;
        p++;
    }
    if(*s == '\0' && *p == '\0')
        return 1;
    else
        return 0;
}

char *najrijec(char *s, char *rijec){ // pronalazi najcescu rijec u stringu (NAPOMENA: MODIFIKOVATI normalizacija tako da doda jos 1 razmak prije \0 na kraju !)
s=normalizacija(s);
char *pocetak=s,*pom1=s,*pok2=s;
char *kraj=rijec;
char pom[100][100]={'\0'};
int i=0,j=0;
while(*pom1 != '\0'){
    if(*pom1 !=' '){
        pom[i][j]=*pom1;
        j++;
    }
    else{ i++; j=0; }
        pom1++;
}
int k=0,max=0,novimax=0,l=0,indeks=0;

for(k=0;k<i;k++){
for(l=k+1;l<i;l++){
    if(iste(pom[k],pom[l]) == 1) novimax++;
}

if(novimax>max){
        max=novimax;
indeks=k;
}
novimax=0;
}
j=0;
while(pom[indeks][j] != '\0'){
    *rijec=pom[indeks][j];
    rijec++;
    j++;
}
*rijec='\0';
return kraj;
}


void izbacirijec(char* s, char* p) // izbacuje odredjenu rijec iz stringa (ne radi ako je zadnja rijec ona koja se izbacuje)
{
    char trenutna[100];
    int i;
    char *izbaciti, *ostaje;
    char* beze;
    char* pocetak = s;
    while(*s != '\0')
    {
        if((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
        {
            i = 0;
            izbaciti = s;
            while((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
            {
                trenutna[i] = *s;
                i++;
                s++;
            }
            trenutna[i] = '\0';
            beze = trenutna;
            if(iste(beze, p))
            {
                ostaje = ++s;
                while(*ostaje != '\0')
                {
                    *izbaciti = *ostaje;
                    izbaciti++;
                    ostaje++;
                }
                *izbaciti = '\0';
                s = pocetak;
                continue;
            }
            s--;
        }
        s++;
    }
}
int povadi_rijeci (char* s)
{
    char *pok1 = s, *pok2;
    int i = 0, j;
    int rijec = 1;
    while(*pok1 != '\0')
    {
        if((*pok1 <= 'A' && *pok1 >= 'Z') || (*pok1 <= 'a' && *pok1 >= 'z'))
            rijec = 1;

        if((*pok1 >= 'A' && *pok1 <= 'Z') || (*pok1 >= 'a' && *pok1 <= 'z'))
        {
            rijec = 0;
            j = 0;
            while((*pok1 >= 'A' && *pok1 <= 'Z') || (*pok1 >= 'a' && *pok1 <= 'z'))
            {
                string [i][j] = *pok1;
                j++;
                pok1++;
            }
            string[i][j] = '\0';
            i++;
        }
        pok1++;
    }
    return i;
}


//ispitni
#include <stdio.h>

int ipow(int a, int b)
{
    int i;
    for(i = 1; i <= b; i++)
        a *= a;

    return a;
}
void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
int najveci(int* pok, vel)
{
    int i;
    int max = *pok;
    int *pok1 = pok;
    int *pok2 = pok;
    for(i = 0; i < vel; i++)
    {
        if(*(pok1+i) > max){
            max = *(pok1+i);
            pok2 = pok1;
        }
    }
    return pok2 - pok;
}
void izbaci(char *s, int index)
{
    int brojac = 0;
    char* pok1 = s, *pok2 = s;
    while(*s != '\0')
    {
        if(*s >= '0' && *s <= '9')
        {
            pok2 = *s
            while(*s >= '0' && *s <= '9')
                s++;
            brojac++;
        }
        if(brojac = index)
        {
            while(*s != '\0')
            {
                *pok2 = *s;
                s++;
                pok2++;
            }
        }

    }
}
char* izbaci_najduzu(char* s)
{
    int index;
    int negativan = 0;
    int broj[100];
    int faktor = 0;
    int i, j = 0;
    char* pok2 = s+1, *pok1 = s;
    while(*s != '\0')
    {
        if(*pok1 >= '0' && *pok1 <= '9')
        {
            if(*(pok2-1) == '-')
                negativan = 1;
            pok2 = pok1;
            while(*pok2 >= '0' && *pok2 <= '9')
                pok2++;
            faktor = pok1 - pok2;
            for(i = faktor; i > 0; i--)
            {
                while(pok2 <= pok1)
                    broj[j] = *pok2 * ipow(10, faktor);
            }
            if(negativan == 1)
            {
                broj[j] = -broj[j];
                negativan = 0;
            }
            j++;
        }
         pok1++;
    }
    index = najveci(broj, j);
    izbaci(s, index);
    return s;
}

int main() {
    char tekst[100];
    unesi(tekst,100);
    izbaci_najduzu(tekst);
    printf("Nakon izbacivanja: %s", tekst);
    return 0;
}

//ispitni

#include <stdio.h>
#include <stdlib.h>
void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
char* odakle(char* pok)
{
    while(*pok >= '0' && *pok <= '9' && *pok != '\0' || *pok == '-')
        pok++;

    return pok;
}
char* izbaci_maxbr(char* s)
{
    char *pok1 = s, *pok2 = s;
    int broj, brojac = 0;
    int max = 0, prvi_krug = 0;
    int negativni = 0;

    while(*pok1 != '\0')
    {
        if(*pok1 == '-' && *(pok1+1) >= '0' && *(pok1+1) <= '9')
            negativni = 1;

        if(*pok1 >= '0' && *pok1 <= '9')
        {
            broj = 0;
            brojac = 0;
            while(*pok1 >= '0' && *pok1 <= '9' && *pok1 != '\0')
            {
                broj *= 10;
                broj += *pok1 - '0';
                brojac++;
                pok1++;
            }
            if(negativni)
            {
                broj = -broj;
                negativni = 0;
            }
            prvi_krug++;
            if(max < broj || prvi_krug == 1)
            {
                max = broj;
                pok2 = pok1 - brojac;
                if(*(pok2-1) == '-')
                    pok2--;
            }

        }
        pok1++;
    }
    pok1 = odakle(pok2);
    while(*pok1 != '\0')
    {
        *pok2 = *pok1;
        pok1++;
        pok2++;
    }
    *(pok2++) = '\0';

    return s;
}
int main()
{
    char t[] = "Primjer-11negativnih-22brojeva-33";
    printf("%s", izbaci_maxbr(t));
    return 0;
}

//ispitni

#include <stdio.h>
#include <stdlib.h>
struct Radnik {
    char ime[20], prezime[20];
    int godina;
    float plata[12];
} radnici[1000];
int br_radnika=0;
void ucitaj() {
    int i=0;
    FILE* ulaz;
    ulaz=fopen("ulaz.txt", "r");
    if (ulaz == NULL) {
        printf ("Pogreska kod otvaranja datoteke ulaz.txt!\n\n");
        exit (1);
    }
    while((fscanf(ulaz, "%20s %20s %d", radnici[br_radnika].ime, radnici[br_radnika]. prezime, &radnici[br_radnika].godina)) == 3 && br_radnika < 1000)
    {
        for(i = 0; i < 12; i++)
            fscanf(ulaz, "%f", &(radnici[br_radnika].plata[i]));
        fscanf(ulaz, "\n");
        br_radnika++;
    }
    fclose(ulaz);
}
void zapisi() {
    int i=0,j=0;
    float suma=0, pr_plata=0;
    FILE* izlaz;
    izlaz=fopen("izlaz.txt", "w");
    if (izlaz == NULL) {
        printf ("Pogreska kod otvaranja datoteke izlaz.txt!\n\n");
        exit (2);
    }
    for (i=0; i<br_radnika; i++) {
        if (radnici[i].godina == 2010) {
            suma = 0;
            for (j=0; j<12; j++) suma+=radnici[i].plata[j];
            pr_plata=suma/12;
            if (pr_plata>1000) {
                fprintf(izlaz, "%-19s %-19s %-5.2f\n", radnici[i].ime, radnici[i].prezime, pr_plata);
            }
        }
    }
    fclose(izlaz);
}
int main() {
    ucitaj();
    zapisi();
    return 0;
}

//ispitni

#include <stdio.h>
char string[20][100];
void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
int iste(char* s, char* p)
{
    while(*s != '\0' && *p != '\0')
    {
        if(*s != *p)
            return 0;

        s++;
        p++;
    }
    if(*s == '\0' && *p == '\0')
        return 1;
    else
        return 0;
}

int povadi_rijeci (char* s)
{
    char *pok1 = s, *pok2;
    int i = 0, j;
    int rijec = 1;
    while(*pok1 != '\0')
    {
        if((*pok1 <= 'A' && *pok1 >= 'Z') || (*pok1 <= 'a' && *pok1 >= 'z'))
            rijec = 1;

        if((*pok1 >= 'A' && *pok1 <= 'Z') || (*pok1 >= 'a' && *pok1 <= 'z'))
        {
            rijec = 0;
            j = 0;
            while((*pok1 >= 'A' && *pok1 <= 'Z') || (*pok1 >= 'a' && *pok1 <= 'z'))
            {
                string [i][j] = *pok1;
                j++;
                pok1++;
            }
            string[i][j] = '\0';
            i++;
        }
        pok1++;
    }
    return i;
}
char* najcesca1(int vel)
{
    int i, j, k, l;
    int max = 0;
    int brojac1 = 0, brojac2 = 0;
    char* vratiti;
    char *prva, *druga;
    for(i = 0; i < vel; i++)
    {
        brojac1 = 0;
        for(j = i+1; j < vel; j++)
        {
            prva = &string[i][0];
            druga = &string[j][0];
            if(iste(prva, druga))
                brojac1++;
        }
        if(brojac1 > brojac2)
            max = i;
        brojac2 = brojac1;
    }
    vratiti = &string[max][0];
    return vratiti;
}
void izbaci(char* s, char* p)
{
    char trenutna[100];
    int i;
    char *izbaciti, *ostaje;
    char* beze;
    char* pocetak = s;
    while(*s != '\0')
    {
        if((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
        {
            i = 0;
            izbaciti = s;
            while((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
            {
                trenutna[i] = *s;
                i++;
                s++;
            }
            trenutna[i] = '\0';
            beze = trenutna;
            if(iste(beze, p))
            {
                ostaje = s;
                while(*ostaje != '\0')
                {
                    *izbaciti = *ostaje;
                    izbaciti++;
                    ostaje++;
                }
                *izbaciti = '\0';
                s = pocetak;
                continue;
            }
            s--;
        }
        s++;
    }
}
char* izbaci_najcescu(char* tekst)
{
    izbaci(tekst, najcesca1(povadi_rijeci(tekst)));

    return tekst;
}

int main() {
    char tekst[100];
    unesi(tekst, 100);
    printf("Nakon izbacivanja: %s", izbaci_najcescu(tekst));
    return 0;
}

//ispitni

#include <stdio.h>

int* istecifre(int* niz, int vel, int* p)
{
	int cifre1[10] = {0};
	int cifre2[10] = {0};
	int i = 0, j = 0, k = 0, r = 0;
	int trazeni1, trazeni2;


	trazeni1 = *p;
	while(trazeni1 > 0)
	{
		cifre1[trazeni1 % 10]++;
		trazeni1 /= 10;
	}
	/*for(i = 0; i < 10; i++)
		printf("%d ", cifre1[i]);*/

	for(i = p - niz+1; i < vel; i++)
	{
		for(r = 0; r < 10; r++)
			cifre2[r] = 0;
		trazeni2 = *(niz+i);
		while(trazeni2 > 0)
		{
			cifre2[trazeni2 % 10]++;
			trazeni2 /= 10;
		}
		for(j = 0; j < 10; j++)
			if(cifre1[j] != cifre2[j])
				break;

		if(j == 10){
			break;
		}
	}

	if(j != 10)
	{
		for(i = 0; i < p - niz; i++)
		{
			trazeni2 = *(niz+i);
			for(r = 0; r < 10; r++)
				cifre2[r] = 0;
			while(trazeni2 > 0)
			{
				cifre2[trazeni2 % 10]++;
				trazeni2 /= 10;
			}
			for(k = 0; k < 10; k++)
				if(cifre1[k] != cifre2[k]){
					break;
				}
			if(k == 10){
				break;
			}
		}
	}

	return niz + i;
}

int main() {
	int niz[] = {1, 114, 3,  321, 144, 4141, 441, 6};
	int*p = istecifre(niz, 10, niz+3);
	printf("Broj %d pozicija %d", *p, (int)(p-niz));
	return 0;
}


//ispitni

#include <stdio.h>

char max_slovo(char* s)
{
    char string[100] = {0};
    int i = 0, j = 0, k = 0;
    int max = 0;
    int br1 = 0, br2 = 0;
    while(*s != '\0')
    {
        if((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
        {
            string[i] = *s;
        }
        i++;
        s++;
    }
    for(j = 0; j < i; j++)
    {
        br2 = 0;
        for(k = j; k < i; k++)
        {
            if(string[j] >= 'A' && string[j] <= 'Z' && string[k] >= 'a' && string[k] <= 'z')
                if(string[j] + 32 == string[k])
                    br2++;
            else if(string[k] >= 'A' && string[k] <= 'Z' && string[j] >= 'a' && string[j] <= 'z')
                if(string[j] - 32 == string[k])
                    br2++;
            else if(string[j] == string[k] && string[j] == ' ')
                br2++;
        }
        if(br2 < br1)
            max = j;
        br1 = br2;
    }
    return string[max];
}
char* izbaci_max_slovo(char* s)
{
    char izbaci = max_slovo(s);
    char *pok = s;

    while(*s != '\0')
    {
        if(*s == izbaci || *s + 32 == izbaci || *s-32 == izbaci)
        {
            while(*s != '\0')
            {
                *s = *(s+1);
                s++;
            }
            s = pok;
            continue;
        }
        s++;
    }

    return pok;
}

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}


int main() {
	char tekst[] = "U ovom tekstu puno puta se ponavlja slovo O";
    printf("%s", izbaci_max_slovo(tekst));
}


//ispitni

#include <stdio.h>
#include <stdlib.h>
struct Planina
{
    char naziv[30];
    int visina;
};
int ucitaj(struct Planina* pok, int n)
{
    FILE* ulaz;
    int vel = 0;

    if((ulaz = fopen("ulaz.txt", "r")) == NULL)
    {
        printf("Greska pri otvaranju datoteke ulaz.txt\n");
        exit(1);
    }
    else
        while(fscanf(ulaz, "%s %d\n", &(pok+vel)->naziv, &(pok+vel)->visina) == 2 && vel < n)
            vel++;
    fclose(ulaz);
    return vel;
}
void zapisi(struct Planina* pok, int vel, int min_visina)
{
    int i;
    FILE* izlaz;
    if((izlaz = fopen("izlaz.txt", "w")) == NULL)
    {
        printf("Greska pri otvaranju datoteke izlaz.txt\n");
        exit(2);
    }
    else
        for(i = 0; i < vel; i++)
        {
            if((pok+i)->visina > min_visina)
               fprintf(izlaz, "%s\n", (pok+i)->naziv);
        }
    fclose(izlaz);
}

int main() {
    int i, br_planina;
struct Planina planine[10];
FILE* ulaz = fopen("ulaz.txt", "w");
fputs("Maglic 2386", ulaz);
fputc(10, ulaz);

char tekst[] = "APlanina 1999";
for (i=0; i<9; i++) {
   fputs(tekst, ulaz);
   fputc(10, ulaz);
   tekst[0]++;
}

fputs("Bjelasnica 2067", ulaz);
fclose(ulaz);

br_planina=ucitaj(planine, 10);
zapisi(planine, br_planina, 2001);

printf("%d", br_planina);
FILE* izlaz = fopen("izlaz.txt", "r");
while (!feof(izlaz))
    printf("%c", fgetc(izlaz));
fclose(izlaz);
}


//ispitni

#include <stdio.h>

struct Tacka {
    float x,y;
};

struct Pravougaonik {
    struct Tacka donji_lijevi, gornji_desni;
};

int obuhvat (struct Pravougaonik* np, int velp, struct Tacka* nt, int velt)
{
    int i, j;
    int brojac = 0;
    int max = 0;
    float gtx, gty, dtx, dty;
    float x, y;
    for(i = 0; i < velp; i++)
    {
        gtx = (np+i)->gornji_desni.x;
        gty = (np+i)->gornji_desni.y;
        dtx = (np+i)->donji_lijevi.x;
        dty = (np+i)->donji_lijevi.y;
        brojac = 0;
        for(j = 0; j < velt; j++)
        {
            x = (nt+j)->x;
            y = (nt+j)->y;
            if(x < dtx && x > gtx && y < dty && y > gty)
                break;
            else if(x >= dtx && x <= gtx && y >= dty && y <= gty)
                brojac++;
        }
        if(brojac == velt)
            max++;

    }
    return max;
}

int main() {
    struct Tacka tacke[10] = { {0,0}, {1,1}, {2,2}, {3,3} };
    struct Pravougaonik pravougaonici[10] = { {{0,0}, {3,3}}, {{1,1}, {2,2}} };
    int rezultat = obuhvat(pravougaonici, 2, tacke, 4);
    printf("Broj pravougaonika koji obuhvataju sve tacke: %d", rezultat);
    return 0;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
