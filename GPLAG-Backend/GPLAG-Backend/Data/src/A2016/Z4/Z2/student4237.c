#include <stdio.h>

/*fukcija za dekodiranje*/
char*dekodiraj(char*s, char*tabela){
	int i=0;
	while(*(s+i)!='\0'){
		*(s+i)=*(tabela+126-*(s+i));
		i++;}
	return s;
}
/*funkcija koja broji karaktere u stringu*/
int f_ponavljanje(char*s,int a){
	int brojac=0;
	int i=0;
	while(*(s+i)!='\0'){
		if(*(s+i)==a)
			brojac++;
		i++;
	}
	return brojac;
}
/*funkcija za kodiranje texta*/
char* kodiraj(char*text, char*tabela){
	char*s=text;
	char ASSCI[95];
	int ucestalost[95];
	int temp, j=0,i=0;
	j=0;
    while(j<95){
		ASSCI[j]=(char)(j+32);
        j++; 	
    }ASSCI[j]='\0';
	while (i<95){
	ucestalost[i]=f_ponavljanje(s, (i+32));
	i++;
	}
	
	for(i=0;i<95;i++){
	
		for(j=i;j<95;j++){
			
			if(ucestalost[i]<ucestalost[j]){
				temp=ucestalost[i];
				ucestalost[i]=ucestalost[j];
				ucestalost[j]=temp;
				temp=ASSCI[i];
				ASSCI[i]=ASSCI[j];
				ASSCI[j]=temp;
			}
		
			if(ucestalost[i]==ucestalost[j]){
		
				if(ASSCI[j]<ASSCI[i]){
					temp=ucestalost[i];
				    ucestalost[i]=ucestalost[j];
					ucestalost[j]=temp;
					temp=ASSCI[i];
					ASSCI[i]=ASSCI[j];
					ASSCI[j]=temp;
			   }
		   }	
		}
	}
	
	i=0;
	while(i<95){
		tabela[i]=ASSCI[i];
		i++;
	}
	tabela[i]='\0';

	while(*s!='\0'){
	      for(i=0;i<95;i++){
	      	if(*s==*(tabela+i)){
	      	    *s=126-i;
	      	    break;}
	      }	
	   s++;   
	}
	return text;
} 
int main() {
	char s[100]={"LLMLNLNMONM"};
	char tablica[96]={""};
	printf("\nKodirano: %s", kodiraj(s,tablica));
	printf("\nKodirano: %s", dekodiraj(s,tablica));
	return 0;
}
