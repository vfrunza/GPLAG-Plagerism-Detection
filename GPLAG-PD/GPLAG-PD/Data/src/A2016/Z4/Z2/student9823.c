#include <stdio.h>

char *kodiraj(char *s, char *tablica)
{
    int vedranovozovehistrogram_upitnik[100]= {0};
    char *reset = s;
    char *pomocni = s;
    char *reset2 = tablica;

    while(*pomocni!='\0') {
        // ovo vazi uz pretpostavku da se unosi string od 32-127 po ASCII-u
        // smanjuje sve vrijednost karaktera za 32 da ih poreda po redu od 0-95
        // histogram nam omogucava da zapamtimo broj puta koliko neki karakter se nalazi u stringu
        vedranovozovehistrogram_upitnik[*pomocni-32]++; // ukoliko nadje neki isti karakter vrijednost na kojoj je vec bio karakter povecava za 1
        pomocni++;
    }

    int i=0, j=0;
    int max, maxindex=0; // treba nam max i maxindex da bi našli index na koji se najvise puta ponavlja karakter i upisali u tablicu


    for(i=0; i<95; i++) {
        max = -1;

        for(j=0; j<95; j++) {

            if(vedranovozovehistrogram_upitnik[j]>max) {
                max = vedranovozovehistrogram_upitnik[j];
                maxindex=j;
            }

        }

        vedranovozovehistrogram_upitnik[maxindex] = -1; // vrijednost gdje se nalazi maxindex postavljamo na -1 da se ne bi opet gledalo
        *tablica = maxindex + 32; // u tablicu upisujemo maxindex + 32, jer smo gore vec smanjili za 32
        tablica++;

    }
    tablica = reset2;

    char *pomocni2 = tablica;
    int k=0;


    while(*s!='\0') {


        while(k<95) {
            if(*s==*pomocni2) { // ukoliko je u stringu ASCII vrijednost karaktera jednaka ASCII vrijednosti nekog karaktera iz tablice onda 'kodiramo' taj karakter
                *s = 126-k;
                break;
            }

            k++;
            pomocni2++; // povecavamo i trazimo taj karakter ako ga ima
            if(*pomocni2=='\0') break;
        }

        k=0;
        pomocni2 = reset2;
        s++;
    }

    return reset;
}

int duzinaneceg(char *tablica)
{
    //obicna strlen funkcija
    int brojac=0;
    while(*tablica!='\0') {
        brojac++;
        tablica++;
    }
    return brojac;
}

char *dekodiraj(char *s, char *tablica)
{
    char *reset = s;
    char *reset2 = tablica;
    char *pomocni = tablica;

    // treba nam duzina tablice
    int duzinatablice = duzinaneceg(tablica);

    int i=0;
    while(*s!='\0') {

        while(i<duzinatablice) { // ista je ideja kao kodiraj samo sad gleda ukoliko je znak = 126-i u ASCII tabeli

            if(*s==126-i) { // ukoliko jeste zamjeni ga i break-a

                *s = *pomocni;
                break;
            }

            pomocni++; // kako gledamo je li karakter == 126-i moramo ici i kroz tablicu i onda uzimamo index gdje je karakter = 126-i
            if(*pomocni=='\0') break;
            i++;
        }

        pomocni = reset2; // obicni reset za tablicu
        s++;
        i=0;
    }

    return reset;
}


int main()
{
    char tekst[] = "Ovo je neki testni tekst";
    char sifrarnik[100] = "";
    int i;
    kodiraj(tekst, sifrarnik);
    printf("%s", tekst);
    printf("\n");
    for (i=0; i<100; i++) printf("%c", sifrarnik[i]);
    printf("\n");
    dekodiraj(tekst, sifrarnik);
    printf("%s", tekst);

    return 0;
}