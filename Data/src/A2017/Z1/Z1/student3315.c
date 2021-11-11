// SVE BITNE STVARI VEZANO ZA ISPIT

                       --------------------> NIZOVI <----------------------

prva cifra nekog broja poslatog u funkciju

int prva_cifra(int broj){
	int cifra;
	while(broj!=0){
		cifra=broj%10;
		broj/=10;
	}
	return cifra;
}

ako trebamo ispitati da li se do nekog elementa pojavljivao drugi element-da li se ponavljao!
u fju cemo slati velicinu koja je odredjena tako da ide petlja do broja do kojeg zelimo provjeru

int bio_vec(int niz[],int velicina,int broj){
 int i;
 for(i=0;i<velicina;i++){
  if(niz[i]==broj){
   return 1;
  }
 }
 return 0;
}

za slucaj kada zelimo znati ponavljanja elemenata u nizu, koristimo OBAVEZNO FJU:

int broj_ponavljanja(int broj,int niz[],int velicina){
	int i;
	int brojac=0;
	for(i=0;i<velicina;i++){
		if(niz[i]==broj){
			brojac++;
		}
	}
	return brojac;
}



algoritam prost-broj

for(i=2;i<n;i++){
	if(broj%i==0){
		printf("Nije prost");
	}
}
  printf("Prost broj!");
  
  
  
algoritam sortiranja niza(nadjemo minimalan indeks i onda zamijenimo varijable)

for(i=0;i<n;i++){
	min=i;
	for(j=i+1;j<n;j++){
		if(niz[j]<niz[min]){
			min=j;
		}
	}
	temp=niz[i];
	niz[i]=niz[min];
	niz[min]=temp;
}



algoritam ubacivanja u niz

for(i=0;i<n;i++){
	if(uslov izbacivanja){
		for(j=n;j>i;j--){
			niz[j]=niz[j-1];
		}
		n++;
		niz[i]=element_koji_ubacujemo;
	}
	
}




algoritam izbacivanja bez ocuvanja redoslijeda

for(i=0;i<n;i++){
	if(uslov_izbacivanja){
		niz[i]=niz[n-1];
		n--;
		i--;
	}
}




algoritam izbacivanja sa ocuvanim redoslijedom

for(i=0;i<n;i++){
	if(uslov_izbacivanja){
		for(j=i;j<n-1;j++){
			niz[j]=niz[j+1];
		}
		n--;
		i--;
	}
}


algoritam ispitivanja da li je broj stepen dvojke

int funkcija(int n){
	int stepen_dvojke=1;
	int ostatak;
	while(!(n==1)){
		if(n%2!=0){
			stepen_dvojke=0;
			return stepen_dvojke;
		}
		else{
			n/=2;
		}
	}
	
	return stepen_dvojke;
	
	
}



fja koja vraca stepen nekog broja-bez koristenja funkcije pow

int stepen(int broj,int eksponent){
    int kontrolna=1;
    int rezultat=1;
    while(kontrolna<=eksponent){
        rezultat*=broj;
        kontrolna++;
    }
    
    return rezultat;
}



fja koja ispituje da li je broj potpun kvadrat

int potpun_kvadrat(int n){
	double korijen;
	korijen=sqrt(n);
	int pomocna=korijen;
	double decimalni_dio;
	decimalni_dio=korijen-pomocna;
	if(decimalni_dio!=0){
		return 0;
	}
	else{
		return 1;
	}

}



algoritam za pronalazak prvog i drugog najmanjeg elementa u nizu

// pronadjemo standardno prvi minimum
int min=niz[0];
	for(j=0;j<i;j++){
		if(niz[j]<min){
			min=niz[j];
		}
	}
	
// pronalazimo drugi minimum ali pri tome izbjegavamo pojavu prvog	
	int k;
	int min2;
	int brojac=0;
	int kontrolna=0;
	for(k=0;k<i;k++){
		if(niz[k]==min){
			continue;
		}
		else{
			kontrolna=1;
			brojac++;
			if(brojac==1){
				min2=niz[k];
				brojac++;
				continue;
				}
			
			if(niz[k]<min2){
				min2=niz[k];
				}	
				
		}
		
	}
	
	if(kontrolna==0){
		min2=min;
	}
	


	
algoritam pronalaska presjeka(zajednickih elemenata skupova), preko niza brojaca
   int brojaci[101]={0}; // ovako deklarisemo niz brojaca
   int m;
	for(k=0;k<i;k++){
		for(m=0;m<j;m++){
			if(niz1[k]==niz2[m]){
				brojaci[niz1[k]]++;
			}
		}
	}

	int p;
	int rezultat[50];
	//int velicina3=0;
	for(p=0;p<101;p++){
		if(brojaci[p]!=0){
			rezultat[p]=p;
			//velicina3++;
		}
	}

   int a;
   printf("Presjek unesenih nizova je: ");
   for(a=0;a<101;a++){
   	if(brojaci[a]!=0){
   		printf("%d ",a);
   	}
   }
   


koristenje fje bio_vec i broj_ponavljanja za neki niz koji ima vise elemenata i zanimaju nas ponavljanja svakog

int main() {
	int broj;
	int niz[11]={1,2,1,4,2,4,2,2,3,4,2};
	int i=0;
	int rez;
	while(i<11){
		if(i==0){
		broj=niz[i];
		rez=broj_ponavljanja(broj,niz,11);
		printf("%d ",rez);
		i++;
		continue;
		}
		else{
			broj=niz[i];
			if(bio_vec(niz,i,broj)==0){
				rez=broj_ponavljanja(broj,niz,11);
				printf("%d ",rez);
				i++;
			}
			else{
				i++;
				continue;
			}
		}

	}
	return 0;
	

}


napomena: amstrongov_broj-zsr-2, zadatak-7
napomena: zadatak-da li se broj proslijedjen fji kao drugi parametar,nalazi u broju koji je prvi parametar(ZSR2-ZAD10)

 
 
 
 
 
                  ------------------------> MATRICE <-------------------------
 
 algoritam za matricu, da na glavnoj dijag.budu nule, paralelno glavnoj iznad brojevi veci od nule 
 a paralelno ispod glavne dijag.budu brojevi manji od nule
 
    int pomocna1=1;
	int pomocna2=-1;
	int brojac1=1;
	int brojac2=1;
 
 	if(i==j){
		  mat[i][j]=0;
			}
			else if(j>i){
				int t;
				for(t=0;t<n-1;t++){
					mat[t][t+brojac1]=pomocna1;
				}
				
				brojac1++;
				pomocna1++;
				
			}
			else if(i>j){
				int a;
				for(a=0;a<n-1;a++){
					mat[a+brojac2][a]=pomocna2;
				}
				brojac2++;
				pomocna2--;
			
			}


sumiranje elemenata na rubovima matrice

float suma = 0;
 for (i = 0; i < A; i++)
 {
 for (j = 0; j < B; j++)
 {
 if ( i == 0 || i == A - 1 || j == 0 || j== B - 1)
suma += matrica[i][j];
 }
 }


			
algoritam izbacivanja glavne dijagonale ako je n neparno,ovdje onda na kraju samo smanjimo pri ispisu velicinu kolona

for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			int t;
			if(n%2!=0 && i==j){
			for(t=j;t<n-1;t++){
				mat[i][t]=mat[i][t+1];
			}
			}
		}
	}





  
            ----------------------------------> STRINGOVI <------------------------------------
	
SA PREDAVANJA:

fje za rad sa stringovima:

int strcmp(const char *string1,const char *string2)
— Poredi string1 i string2 u cilju određivanja alfabetskog poretka.

char *strcpy(const char *string1,const char *string2)
— Kopira string2 u string1.

int strlen(const char *string)
— Određuje dužinu stringa.

char *strncat(const char *string1, char *string2, size_t n)
— Dopisuje n karaktera iz string2 u string1.

int strncmp(const char *string1, char *string2, size_t n)
— Poredi prvih n karaktera dva stringa.

char *strncpy(const char *string1,const char *string2, size_t n)
— Kopira prvih n karaktera od string2 u string1.


fja unosa stringa sa tastature

void unesi(char niz[], int velicina) {
 char znak = getchar();
 if (znak == ’\n’) znak = getchar();
 int i = 0;
 while (i < velicina-1 && znak != '\n') {
 niz[i] = znak;
 i++;
 znak = getchar();
 }
 niz[i] = '\0';
 }
 
 
 
fja prebrojavanja karaktera u stringu
 
int prebroji(char* s, char znak) {
int brojac = 0;
while (*s != '\0') {
 if (*s == znak) brojac++;
 s++;
 }
 return brojac;
 }

velika slova-pretvori u mala

if (*s >= 'A' && *s <= 'Z') *s += 32;

mala slova u velika

if (*s >= 'a' && *s <= 'z') *s -= 32;



leksikografsko poredjenje dva stringa

int uporedi(const char* s1, const char* s2) {
while (*s1 != '\0' && *s2 != '\0') {
 if (*s1 < *s2) return -1;
 if (*s1 > *s2) return 1;
 s1++; s2++;
}
 if (*s1 != '\0') return 1;
 if (*s2 != '\0') return -1;
return 0;
}


fja spajanja dva stringa

char* spoji(char* s1, const char* s2) {
 char* ret = s1;
 while (*s1++); // otjeramo pokazivac na iza kraja, vratimo na kraj i drugi nadovezemo
 s1--;
 while (*s1++ = *s2++); // ovo kopira i znak \0
 return ret;
}


fja za trazenje podstringa neke recenice, vracamo pocetak tog podstringa unutar recenice, pa na kraj

const char* podstring(const char* s1, const char* s2) {
while (*s1 != '\0') {
const char* p = s1;
const char* q = s2;
while (*p++ == *q++)
if (*q == '\0') return s1;

 s1++;
 }
 return NULL;


pretvaranje broja u string(iz int-a u string)

// za ubacivanje broja u string, ako je broj veci treba stvoriti mjesta da se on ubaci
petlja za pretvaranje inta u string glasi:

do{
	*slovo=broj%10+'0'; // dodajemo nulu jer su char-brojevi, nakon obicnih brojeva u ASCII tabeli
	 slovo--;
	broj/=10;
}while(broj!=0);


pretvaranje char-broja u int-broj iz stringa:

int temp=0;
while(*s>='0' && *s<='9'){
	temp=temp*10+*s-'0';  // oduzimamo nulu zato jer su obicni brojevi prije char-brojeva
	s++;
}


fja koja pronalazi rijec u stringu(n-tu po redu), i vrsi izbacivanje zadane rijeci
--> rijec je niz karaktera razdvojenih znakom razmaka <--

void izbaci_rijec(char* s, int n) {
 int razmak=1, broj_rijeci=0;
 char* pocetak;
 while (*s != '\0') {
 if (*s == ' ')
 razmak=1;
 else if (razmak == 1) {
 razmak=0;
 broj_rijeci++;
 if (broj_rijeci==n) pocetak=s;
 if (broj_rijeci==n+1) {
 while (*pocetak++ = *s++);
 return;
 }
 }
 s++;
 }
 }



izbacivanje n-te po redu rijeci ako je rijec neprekinuti niz velikih i malih slova

void izbaci_rijec2(char* s, int n) {
 int neslovo=1, broj_rijeci=0;
 char* pocetak;
 while (*s != ’\0’) {
 if ( !(*s >='A' && *s <= 'Z' || *s >= 'a' && *s <= 'z') )
 neslovo=1;
 else if (neslovo == 1) {
 neslovo=0;
 broj_rijeci++;
 if (broj_rijeci==n) pocetak=s;
 if (broj_rijeci==n+1) {
 while (*pocetak++ = *s++);
 return;
 }
 }
 s++;
 }
 if (broj_rijeci == n) *pocetak = '\0';
 }


ubacivanje podstringa

kada pronadjemo podstring, tj ono sto zelimo da ubbacimo, onda uradimo sljedece:
posaljemo pokazivac kraj na kraj stringa i uvecamo ga za broj novih mjesta koliko nam treba
zatim izjednacavamo sve iduci prema mjestu gdje zelimo ubaciti tj.smanjujemo pok-kraj

while (*kraj != '\0') kraj++;
while (kraj > s) {
*(kraj+4) = *kraj;
kraj--;
 }

izbacivanje:
potrebno je preci preko neke rijeci npr.do znaka razmaka i onda kopirati sve od tog mjesta do kraja stringa

