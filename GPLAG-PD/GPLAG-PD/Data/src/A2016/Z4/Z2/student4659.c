#include <stdio.h>

void unesi(char niz[],int velicina){
	char znak=getchar();
	int i=0;
	if(znak=='\n')znak=getchar();
	while(i<velicina -1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

char *kodiraj(char *s1,char *s2){
    char *q1=s1,*q2=s2;
    char *k=s2;
    char i;
	char *p=s1,*p1=s2,*p2=s1;
    int ASCII[96]={0},max,t,n,br;
            
            /*dodajemo ASCII tabelu u niz s2*/
            
            for(i=32;i<=126;i++){
            	*p1=i;
            	p1++;
            }
            *p1='\0';
            
            
            /*koliko se koji clan ASCII tabele sadrzi u s1*/
	           while(*p!='\0'){
	           	t=*p-32;
	           	ASCII[t]++;
	           	p++;
	           }
	           
	           /*element sa najvecim brojem ponavljanja*/
	           
	           max=0;
	           for(t=0;t<96;t++){
	           	if(ASCII[t]>max)max=ASCII[t];
	           }
	           
	           
	           /*stavimo odredjene elemente na odgovarajuca mjesta u s2*/
	           
	           for(n=max;n>=0;n--){
	             for(t=0;t<96;t++){
	             	if(ASCII[t]==n){
	             		if(*s2=='\0')break;
	             		i=t+32;
	             		*s2=i;
	             		s2++;
	             		
	             		
	             	}
	             }
	           }
	           
	           /*mijenjamo s1 po s2*/
	           
	           while(*q1!='\0'){
	           	br=0;
	           	q2=k;
	           	while(*q2!='\0'){
	           		if(*q2==*q1){
	           			*q1=126-br;
	           			break;
	           		}
	           		br++;
	           		q2++;
	           	}
	           	q1++;
	           }	
	          
return p2;}

char *dekodiraj(char *s1,char *s2){
	 char *poc=s2,*p=s1;
	 int br;
	   while(*s2!='\0')s2++;

	    /*vracanje teksta u prvobitno stanje*/
	
	 while(*s1!='\0'){
	 	br=0;
	 	while(*poc!='\0'){
	 		if(*s1==126-br){
	 			*s1=*(poc+br);
	 			break;
	 		}
	 		br++;
	 	}

	 	s1++;   
	 }
	
return p;	 
}

int main() {
	
	char tekst[100000];
	char tekst2[100];
	
	printf("Unesite tekst: ");
	unesi(tekst,100000);
	printf("%s\n",kodiraj(tekst,tekst2));
	printf("%s\n",dekodiraj(tekst,tekst2));
	
	
	return 0;
}
