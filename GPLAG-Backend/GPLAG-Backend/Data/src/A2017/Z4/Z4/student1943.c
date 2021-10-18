#include <stdio.h>

int jelSlovo(char znak){
	if (znak>=65 && znak<=90) return 1;
	else if (znak>=97 && znak<=122) return 1;
	else return 0;
}


int uporediTagove (char* tag1, char*tag2, char *imeTaga1, char* imeTaga2, int razmak){
	if (razmak%2==0) return 0; /*preklapanje*/
	if (*(tag2+1)!='/') return 0;/*u drugom tagu ne smije biti nista osim /, poslije < */
	if (!jelSlovo(*(tag2+2))) return 0; /* u drugpm tagu poslije / mora biti slovo, ne smije biti nista drugo pa cak ni razmak */
	if (!jelSlovo(*(tag1+1))) return 0; /*u prvom tagu prvi karakter poslije < mora biti slovo */
	
	return 1;
	
}

int uporediStringove (char *str1, char*str2){
	char a, b;
	
	while (*str1 !='\0' && *str2!='\0'){
		
		if (*str1>96 && *str1<123) a=*str1-32;
		else a=*str1;
		
		if (*str2>96 && *str2<123) b=*str2-32;
		else b=*str2;
		
		if (a!=b) return 0;
		
		str1++;
		str2++;
	}
	if (*str1!='\0' || *str2!='\0') return 0;
	
	return 1;
}

int provjeri(char* string){
	int i=0, j=0, velicina, provjereni[100]={0};
	char*pok=string;
	char matricaTagova[100][100]={' '}, matricaImenaTagova[100][100]={' '};
	
	while (*string!='\0'){
		if (*string=='<'){ 
			while (*string!=' ' && *string!='>'){ 
				matricaTagova[i][j]=*string;
				string++;
				j++; 
			}
			matricaTagova[i][j]='>';
			matricaTagova[i][j+1]='\0';
			j=0; /*da se vrati na pocetak*/
			i++; /*prelazak u novi red matrice*/
     	}
	    string++;
	}

	i=0; j=0;


	while (*pok!='\0'){
		if (*pok=='<'){
			pok++;
			if(*pok=='/') pok++;
			while (*pok!=' ' && *pok!='>'){
				matricaImenaTagova[i][j]=*pok;
				pok++;
				j++;
			}
			matricaImenaTagova[i][j]='\0';
			j=0; i++;
		}
		pok++;
	}

	velicina=i;
	for (i=0; i<velicina; i++){
		/*uziam kao fiksan i-ti tag*/
		for (j=i+1; j<velicina; j++){
			/*provjeravam da li je u matrici imenatagova i-ti tag jednak nekom od ostalih tagova*/
			
			if (uporediStringove(matricaImenaTagova[i], matricaImenaTagova[j]) && provjereni[i]==0 && provjereni[j]==0){
				/*ako je pronaslo 2 ista imena taga, njegovi indeksi su "i" i "j" i sad provjeravam da li su ta dva taga skupa sa svojim imenima ispravni */
				if (uporediTagove(matricaTagova[i], matricaTagova[j], matricaImenaTagova[i], matricaImenaTagova[j], j-i) == 0) return 0;
				/*ako sam nasla 2 taga koji su ispravni oznacavam da sam ih provjerila u nizu pod njihovim indeksima*/
                   provjereni[i]=1;
                   provjereni[j]=1;
			}
		}
	}
   /*provjeravam da li postoji neki tag koji nije provjeren tj, neki tag koji nema svoj par, odnsno tag viska */
	for (i=0; i<velicina; i++){
		if (provjereni[i]!=1) return 0;
	}
	return 1;
}

int main() {
	char tekst1[100];
	
	printf ("%d", provjeri(tekst1));
	return 0;
}
