#include <stdio.h>

char* kodiraj(char* s, char* q){
	char* p=s;
	int i, j, tmp, ponavljanja[95]={0};
	/*Niz ponavljanja biljezi koliko se puta pojavljuje neka ASCII vrijednost*/
	while(*p!='\0'){
		i=(*p-32);
		ponavljanja[i]++;
		p++;
	}
	i=0;
	/*Ispunjavanje tablice sifrovanja znakovima ASCII kodova [32,126]*/
	while(i<96){
		if(i==95) *(q+i)='\0';
		else *(q+i)=(char)(i+32); 	
		i++;
	}
	/*Sortiranje znakova u tablici sifrovanja na osnovu ponavljanja*/
	for(i=1;i<95;i++){
		j=i;
		while(j>0 && ponavljanja[j]>ponavljanja[j-1]){
		    tmp=q[j];
		    q[j]=q[j-1];
		    q[j-1]=tmp;
		    tmp=ponavljanja[j];
		    ponavljanja[j]=ponavljanja[j-1];
		    ponavljanja[j-1]=tmp;
		    j--;
		}
	}
	p=s;
	/*Sifrovanje primljenog stringa*/
	while(*p!='\0'){
	    i=0;
	    while(1){
	        if(*(q+i)==*p){
	            *p=126-i;
	            break;
	        }
	        i++;
	    }
	    p++;
	}
	return s;
}
char* dekodiraj(char* s, char* q){
	char* p=s;
	char desifra[96]="";
	int i, j, tmp, ponavljanja[95]={0};
	/*Niz ponavljanja biljezi koliko se puta pojavljuje neka ASCII vrijednost */
	while(*p!='\0'){
		i=(*p-32);
		ponavljanja[i]++;
		p++;
	}
	i=0;
	/*U niz desifra koji predstavlja tablicu desifrovanja upisujem znakove*/
	while(i<96){
		if(i==95) *(desifra+i)='\0';
		else *(desifra+i)=(char)(i+32);
		i++;
	}
	/*U tablici desifriranja (niz desifra) sortiram znakove po ponavljanjima,
	u ovom slucaju od najmanje do najvise ponavljanja kako bi se znakovi sa isto
	ponavljanja pravilno desifrovali*/
	for(i=1;i<95;i++){
		j=i;
		while(j>0 && ponavljanja[j]<ponavljanja[j-1]){
		    tmp=desifra[j];
		    desifra[j]=desifra[j-1];
		    desifra[j-1]=tmp;
		    tmp=ponavljanja[j];
		    ponavljanja[j]=ponavljanja[j-1];
		    ponavljanja[j-1]=tmp;
		    j--;
		}
	}
	/*Desifrovanje na osnovu niza desifra (tablica desifriranja) i tablice sifriranja*/
	p=s;
	while(*p!='\0'){
		i=0;
		while(1){
			if(*(desifra+94-i)==*p){
				*p=*(q+i);
				break;
			}
			i++;
		}
		p++;
	}
	return s;
}
int main() {
	char q[96]="";
	char s[]="LLMLNLNMONM";
	printf(" %s", kodiraj(s, q));
	printf(" %s", dekodiraj(s, q));
	return 0;
}
