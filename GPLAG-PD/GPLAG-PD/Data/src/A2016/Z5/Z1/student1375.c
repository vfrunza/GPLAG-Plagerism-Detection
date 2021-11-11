#include <stdio.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float Daj_prosjek(struct Student s)
{
	int suma=0; int i;
	
	for(i=0; i<s.br_ocjena; i++)
	{
		if(s.ocjene[i]==5 || s.br_ocjena==0) return 5.0;
		else suma+=s.ocjene[i];
	}
	return (float)suma/s.br_ocjena;
}

int funkcija(struct Student S1, struct Student S2)
{    
    if(Daj_prosjek(S1)>Daj_prosjek(S2)) return -1;
    if(Daj_prosjek(S1)<Daj_prosjek(S2)) return 1;
   
    char* s=S1.prezime;
    char* p=S2.prezime;
    char* q=S1.ime;
    char* k=S2.ime;
    
    
    while (*s!='\0' && *p!='\0') {
    	
    	if(*s>*p) return -1;
    	else if(*p>*s) return 1;
    	s++;
    	p++;
    }
    if(*s=='\0' && *p!='\0') return -1;
    else if(*s!='\0' && *p=='\0') return 1;
    else {
    	 while (*q!='\0' && *k!='\0') {
    	
    	if(*q>*k) return -1;
    	else if(*q>*k) return 1;
    	q++;
    	k++;
    }
    if(*q=='\0' && *k!='\0') return -1;
    else if(*q!='\0' && *k=='\0') return 1;
    }
    return 0;
}


int genijalci(struct Student niz[], int vel, float prosjek)
{
	int i, j; 
	int index1=0, index2=0, index3=0;
    float maxx;
    struct Student niz2[3];
	for(i=0; i<vel; i++)
	{    
		if(Daj_prosjek(niz[i])<prosjek)
		{
			for(j=i; j<vel-1; j++){
			niz[j]=niz[j+1];
		} vel--;
		  i--;} }
	     return vel;
	     
	     
	    maxx=0;
	    for(i=0; i<vel; i++)
	    {
	    	if(Daj_prosjek(niz[i])>maxx) {
	    		maxx=Daj_prosjek(niz[i]); 
	    		index1=i;
	    	
	    }}
	    
	    maxx=0;
	    for(i=0; i<vel; i++)
	    {
	    	if(Daj_prosjek(niz[i])>maxx && i!=index1) {
	    		maxx=Daj_prosjek(niz[i]);
	    		index2=i;
	    	
	    } }
	    maxx=0;
	   
	    for(i=0; i<vel; i++)
	    {
	    	if(Daj_prosjek(niz[i])>maxx && i!=index1 && i!=index2) {
	    		maxx=Daj_prosjek(niz[i]);
	    		index3=i;
	    	}
	    }
	    
	   niz2[0]=niz[index1];
	   niz2[1]=niz[index2];
	   niz2[2]=niz[index3];
	   
	    for(i=0; i<vel; i++)
	    {
	    	for(j=0; j<2-i; j++)
	    	{
	    		if(funkcija(niz2[i],niz2[j+1])==1){
	    			struct Student temp=niz[i];
	    			niz[i]=niz[j+1];
	    			niz[j+1]=temp;
	    		}
	    	}
	    }


	printf("%s %s\n", niz2[0].ime, niz2[0].prezime);
	printf("%s %s\n", niz2[1].ime, niz2[1].prezime);
	printf("%s %s", niz2[2].ime, niz2[2].prezime);
    
	
   }



int main() {
	
	
	
	
	
	return 0;
}
