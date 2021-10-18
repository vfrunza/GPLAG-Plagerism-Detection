#include <stdio.h>

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


char* ubaci_broj(char* string, int broj){
    
    int x,y;
	int  nula=0,razmak2=1,razmak=1,broj_rijeci=0,max_broj_rijeci=0,brojac=0,povecaj,cifra=0,osigurac=0;
	char *s,*t,*k,*p,*q,*r,*o;
	int i,tmp;
	

/*Brojimo nule i stepen broja*/ 	
	if (broj <= 0)brojac++;
	x=broj;
	
	while(x!=0){
		brojac++;
		if(x%10==0)nula++;
		x=x/10;
	}
	
/*Obrcemo broj naopacke*/	
	tmp=broj;
	broj=0;
	while(tmp!=0){
		broj=broj*10 +tmp%10;
		tmp=tmp/10;
	}
	
	
	y=broj;
	
	s=t=k=o=p=string;
	
/*Brojimo ukupan broj rijeci*/	
	while(*k!='\0'){
	    if(*k==' ' && max_broj_rijeci>0)razmak++;
	 	if(*k!=' ' && razmak>0){
	    max_broj_rijeci++;
	    razmak=0;
	  }   
	  k++;
	}
	
	razmak2=razmak;
	if(max_broj_rijeci==1)return t;
	razmak=1;
	
	while(*p!='\0'){
/*Brojimo rijeci*/	    
	 	if(*p==' ' && broj_rijeci>0)razmak++;
	 	if(*p!=' ' && razmak>0){
	     broj_rijeci++;
	    razmak=0;
	  }   
/*Stavljamo pokazivac na kraj stringa*/	 
	if(broj_rijeci>0 && razmak==1){
		q=p;
		while(*q!='\0')q++;
	     
	   	povecaj=brojac+1;

	   	if(razmak2>povecaj*(max_broj_rijeci-1)){
	   		q--;
	   		osigurac=1;
	   		
	   	}
/*Zadnji clan je ne-slovo; povecavamo string i na njegov kraj takodjer stavljamo ne-slovo*/	 
	    *q='|';
	   	for(i=0;i<povecaj;i++){
	   		*q='|';
	   		q++;
	   	}
	   	*q='\0';
	   
		q--;
	   	r=q;
	
/*Dok je zadnji clan ne-slovo pomjeramo elemente stringa za jedan*/	   
	   	while(*r=='|'){
	   		q=r;
	   		while(q!=p){
	   			*q=*(q-1);
	   			q--;
	  		}
	   }
	   
	}
	 
	 p++;
	}
    
    
    
    razmak=1,broj_rijeci=0;
    
    while(*o!='\0'){
    	
    if(*o==' ' && broj_rijeci>0)razmak++;
	 
	 if(*o!=' ' && razmak>0){
	     
	    broj_rijeci++;
	    razmak=0;
	  }   
/*Ako je broj negativan stavljamo minus*/    	
    	if(broj_rijeci>0 && razmak==2 && broj_rijeci!=max_broj_rijeci){
    		
    		if (broj < 0) {
			broj = -broj;
			*o++ = '-';
    		}
/*Pretvaramo int u char*/    		
    		while (broj != 0){
				cifra = broj % 10;
				*o = cifra + '0';
				o++;
				broj /= 10;
			}
			if(nula>0){
				*o = 0 + '0';
				o++;
				
			}
			broj=y;

    	}
    	
    	o++;
    }
	
	 while (*s != '\0') {
       
        s++;
    }
    
    if(razmak2>povecaj && osigurac==0){
    	s=s-2;
    	*s='\0';
    }

    return t;
}

int main() {
    char niz[100];
    int broj;
    unesi(niz, 100);
    scanf("%d",&broj);
	
	
	printf("%s",ubaci_broj(niz,broj));
	
	return 0;
}
