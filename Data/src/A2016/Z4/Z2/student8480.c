#include <stdio.h>

int poz(char slovo, char s[]){
	//vraca int, indeks naseg slova u datom nizu
	int i;
	for(i=0;i<=94;i++) {
	if(slovo==s[i]) return i;
	}
}


void prekopiraj(char *tablica, char slova[]){ //u tabelu spasimo nas niz slova koji su sortirani
	int i;
	for(i=0;i<=94;i++) {             //nas niz slova uvijek ima 94 elementa, i on je sortiran i prebacimo ga u tablicu
	*(tablica+i)=slova[i];
	}
	
	*(tablica+i)='\0';      //posto se nas niz ne zavrsava sa \0, moramo naknadno dodati
}

void zasvaki(char *tekst,char* I){ //za svaki znak iz naseg teksta zamijeni, od 126 oduzimamo njegovu poziciju
	while(*tekst!='\0'){
		*tekst=126-poz(*tekst,I);
		tekst++;
	}
}

void zamijeniint(int *poknap, int *poknad){  //mora primiti pokazivace, jer joj se u mainu salje adresa
	int temp=*poknap;
	*poknap=*poknad;
	*poknad=temp;
}

void zamijenichar(int *poknap, int* poknad){  // isto kao u funkciji zamijeniint,samo sa charovima
	char temp=*poknap;
	*poknap=*poknad;
	*poknad=temp;
	
}

char* kodiraj(char* tekst, char* tablica){
	
char* pok=tekst; char *pozav=tekst, *I=tablica, *m=tekst;
int i,j;
int histogram[200]={0};  //mora sve biti na 0
char slova[200];
	
	for(i=32;i<=126;i++)  //popunimo niz slova charovima  redom u ascii tabeli
		slova[i-32]=i;
		
	while(*pok!='\0'){ //pok pokazuje na tekst, i ide kroz njega, i svaki broj ponavljanja slova spasava u niz 
		int pozicija= (int)* pok;
		histogram[pozicija-32]++;
		pok++;
	}
	
	for(i=0;i<=94;i++){ //prolazimo kroz 2 niza, slova i histogram
		for(j=i+1;j<=94;j++){
			if(histogram[j]>histogram[i] || (histogram[j]==histogram[i] && slova[j]<slova[i])){
		//sortiramo ako je u histogramu veca vrijednost, a ako je jednaka sortiramo po ascii	
			zamijeniint(&histogram[i],&histogram[j]); //poziv funkcije kojom mijenjamo
			
			char temp1=slova[i];
			slova[i]=slova[j];
			slova[j]=temp1;
			
			}
		}
		
	}
	prekopiraj(tablica,slova); //nas niz slova je sortiran, pa ih prebacujemo u tablicu koja je prazna
	zasvaki(tekst,I); //mijenjamo svaki elemenat teksta
	return pozav;
}


char *dekodiraj(char *tekst, char *tabela){
	char pomtekst[2000], pomtabela[200]; //pomocni tekst i pomocna tabela u koju spasavamo
	char *poc=tekst, *p=pomtekst, *pok=pomtekst;
	int i,j;
	while(*tekst!='\0'){ //p pokazuje na pomocni tekst i u pomocni tekst smo upisali svoj zadani tekst
		*p=*tekst;
	 	 p++;tekst++;
	
		} *p='\0';
		
		int histogram[200]={0};
		char slova[200];
		
		for(i=32;i<=126;i++) //ispunili ascii vrijednostima
			slova[i-32]=i;
		
		
		while(*pok!='\0'){ //ispunili niz po broju ponavljanja
			int pozicija=(int)* pok;
			histogram[pozicija-32]++;
			pok++;
		}
		
		
		for(i=0;i<=94;i++){ //prolazak kroz pomocne nizove i sortiranje
			for(j=i+1;j<=94;j++){
				if(histogram[j]>histogram[i] || (histogram[j]==histogram[i] && slova[j]>slova[i])){ //isto kao u funkciji kodiraj samo je uslov drugaciji
				
				zamijeniint(&histogram[i],&histogram[j]);
			
				char temp1=slova[i];
				slova[i]=slova[j];
				slova[j]=temp1;
				}
			}
		}
		
		prekopiraj(pomtabela,slova); //slova niz je sortiran i prebacimo ga u pomocnu tabelu po kojoj kodiramo
		zasvaki(pomtekst,pomtabela); //svaki elemenat kodiramo po poziciji u pomocnoj tabeli
	
		tekst=poc;
		
		while(*tekst!='\0'){ //konacno nas tekst zadani, modifikujemo
			i=poz(*tekst,pomtabela); //i je adresa naseg elementa u pomocnoj tabeli
			*tekst=*(tabela+i); //nas elemenat ostane elemenat u datoj tabeli na indeksu i
			tekst++;
		}
		return poc;
}

int main(){
	
	char tekst[]="LLMLNLNMONM";
	char sifrarnik[100]="";
	int i;
	
	kodiraj(tekst,sifrarnik);
	printf("%s",tekst);
	
	for(i=0;i<10;i++) 
		printf("%c", sifrarnik[i]);
	
	return 0;
}