#include <stdio.h>

void unesi(char* s, int velicina){
	char znak = getchar();
	int i;
	if(znak == '\n') znak=getchar();
	i=0;
	while(i<velicina && znak != '\n'){
		s[i] = znak;
		znak=getchar();
		i++;
	}
	s[i] = '\0';
}

char* kodiraj(char* s, char* p){
	char* pocetak=s;
	int brojaci[130]={0}, i, niz[130], j=0, temp, max, n, niz1[130], k, niz2[130];
	while(*s != '\0'){
		brojaci[*s]++;
		s++;
	}
	for(i=32; i<127; i++){
		if(brojaci[i]>0){
			niz[j] = brojaci[i];
			niz1[j] = i;
			j++;
		}
	}
	n=j;
	for(i=0; i<n; i++){
	    max=i;
	    for(j=i+1; j<n; j++){
	    	if(niz[j]>niz[max]){
	    		max=j;
	    	}else if(niz[j]==niz[max]){
	    		if(niz1[j]<niz1[max]){
	    			max=j;
	    		}
	    	}
	    }
	   	temp=niz[i];
	   	niz[i]=niz[max];
	    niz[max]= temp;
	    
		temp = niz1[i];
 		niz1[i] = niz1[max];
 		niz1[max] = temp;
	}
	j=32;
	for(i=0; j<127; i++){
		if(i<n){
			*p = niz1[i];
		}else{
			for(k=0; k<n; k++){
				if(niz1[k]==j) break;
			}
			if(n==k){
				*p=j;
			}else{
				p--;
			}
			j++;
		}
		p++;
	}
	*p = '\0';
	p--;
	j=126;
	for(i=0; i<n; i++){
		niz2[i]=j;
		j--;
	}
	s=pocetak;
	while(*s != '\0'){
		for(i=0; i<n; i++){
			if(niz1[i] == *s){
				*s = niz2[i];
				break;
			} 
		}
		s++;
	}
	return pocetak;
}

char* dekodiraj(char* s, char* p){
	char* pocetak=s;
	char* poc=p;
	int brojaci[130]={0}, max, niz[130], j, niz1[130], n, temp, i, niz2[130];
	while(*s != '\0'){
		brojaci[*s]++;
		s++;
	}
	j=0;
	for(i=126; 32<=i ; i--){
		if(brojaci[i]>0){
			niz[j]=brojaci[i];
			niz1[j]=i;
			j++;
		}
	}
	n=j;
	for(i=0; i<n; i++){
		max=i;
		for(j=i+1; j<n; j++){
			if(niz[j]>niz[max]){
				max=j;
			}else if(niz[j]==niz[max]){
				if(niz1[j]<niz[max]){
					max=j;
				}
			}
		}
		temp = niz[i];
		niz[i]=niz[max];
		niz[max]=temp;
	
		temp = niz1[i];
		niz1[i] = niz1[max];
		niz1[max] = temp;
	}
	for(i=0; i<n; i++){
		niz2[i]= *p;
		p++;
	}
	p=poc;
	s=pocetak;
	while(*s != '\0'){
		i=0;
		for(i=0; i<n; i++){
			if(*s == niz1[i]){
				*s = niz2[i];
				break;
			}
		}
		s++;
	}
	return pocetak;
}

int main() {
	char niz1[200], niz2[200];
	printf("Unesite tekst: ");
	unesi(niz1, 200);
	printf("%s\n", kodiraj(niz1, niz2));
	printf("%s\n", dekodiraj(niz1, niz2));
	return 0;
}
