
	
	
	
	
	
	
	
	
	
	#include <stdio.h>

void unesi (char niz[], int velicina) {
	char znak = getchar ();
	if (znak == '\n') getchar ();
	int i=0;
	while (i<velicina-1 && znak != '\n') {
		niz [i] = znak;
		i++;
		znak=getchar ();
	}
	niz[i]='\0';
	
}

char* ubaci_broj (char* tekst, int  broj){
	char* p;
	char* p1;
	char* p2;
	p=tekst;
	p1=tekst;
	p2=tekst;
	int brojac=0;
	int temp;
	temp=broj;
	
	while(temp!=0){
		temp/=10;
		brojac++;
	}
	
	while(*p!='\0'){
		
        if(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && (p!=tekst && *(p-1)==' ')){
        p1=p;
		p2=p;
		
        	  while(*p2!='\0') { p2++;
        	  	
        	  }
        	 
        	  
        	  while(p2!=p-1){
        	  	*(p2+brojac)=*p2;
        	  	p2--;
               }
               
               temp=broj;
        	  p1+=brojac-1;
        	  
        	  while(temp!=0){
        	  	
        	  	 *p1=temp%10+'0';
        	  	temp/=10;
        	  p1--;	
        	  }
        }
        
        
        if(*p!='\0') p++;
	}

		return tekst;
}
	
	int main(){
		char tekst [100];
		int n;
		
	
		
		
		printf("Unesite neki tekst: ");
		unesi(tekst,100);
		printf("Unesite neki broj: ");
		scanf("%d",&n);
		printf("%s",ubaci_broj(tekst,n));
	
	

		return 0;
		
		
	}
	
	
	
	
	
	
	
	
	

