#include <stdio.h>
int znak(char *slovo){
	if ((*slovo>='A'&&*slovo<='Z')||(*slovo>='a'&&*slovo<='z')) return 0;
	else return 1;
}
char* izbaci_najcescu(char* s){
	char *poc=s;
	/* Prebrojavanje rijeci */
	char *brojac=s;
	int broj_rijeci=0,razmak=0;
	while (*brojac!='\0'){
		if (znak(brojac)) razmak=1;
		else if(razmak){
			broj_rijeci++;
			razmak=0;
		}
		brojac++;
	}
	int brojac1[100]={0};
	int i,razmak1=0,n=1,broj_rijeci1=0;
	char *p1=s,*p2=s;
	for (i=1;i<=broj_rijeci;i++){
		razmak1=0;
		char *p=s;
		/* Pomjeranje pokazivača na ntu riječ */
		while (*p!='\0'){
			if(znak(p)) razmak1=1;
			else if(razmak1){
				broj_rijeci1++;
				razmak1=0;
				if (broj_rijeci1==n){
				while(znak(p)) p++;
				p1=p;	
				} 
				if (broj_rijeci1==n+1) {
					p2=p;
					p2--;
					break;}
				
				
			}
			p++;
			
		}
		n++;
		int provjera333=0;
		provjera333=znak(p1);
		if(provjera333) p1++;
	    /*Poredenje podstringa sa ostalim. Racunanje ponavljanja */
	   char *p3=s;
	   while (*p3!='\0'){
	   	  char *p4=p3;
	   	  char *p5=p1;
	   	  char tmp1=*p4,tmp2=*p5;
	   	  
	   	  if (*p5>='a'&&*p5<='z') tmp2=*p5-32;
	   	  
	   	  while (tmp1==tmp2){
	   	  	if (znak(p4)&&znak(p5)) break;
	   	  	p4++;p5++;
	   	  	tmp1=*p4;tmp2=*p5;
	   	  
	   	  	if (*p5>='a'&&*p5<='z') tmp2=*p5-32;
	   	    
	   	  }
	   	  char tmp5=*p2;
	   	  if (*p2>='a'&&*p2<='z') tmp5=*p2-32;
	   	  if (tmp1==tmp5&&(p3==poc||znak(p3-1))&&(tmp1=='\0'|| tmp1==tmp5)){
	   	     brojac1[i]++;
	   	  } 
	   	  p3++;
	   	
	   }
	}
	    

		
		
		
		
		
	
	int max=0,indeks=0;
	for (i=0;i<=n;i++){
		if(brojac1[i]>max){
			max=brojac1[i];
			indeks=i;
		} 
	}
	
	/* Trazenje max rijeci i upisivanje nje u pomocni string */
	
	int broj_rijeci2=0,razmak2=0;
	char *pocetak=s, *tekst=poc,*kraj=s;
	while (*tekst!='\0'){
		if (znak(tekst)) razmak2=1;
		else if(razmak2){
			razmak2=0;
			broj_rijeci2++;
			if (broj_rijeci2==indeks) pocetak=tekst;
			if (broj_rijeci2==indeks+1){ 
				kraj=tekst;
				kraj--;
			    break;
			}
		
		}
		tekst++;
	}
	int provjera737=0;
	provjera737=znak(pocetak);
	if (provjera737) pocetak++;
	int provjera32=0;
	provjera32=znak(kraj-1);
	if (provjera32) kraj--;
	char rijec[50];
	int r=0;
	while (*pocetak!=*kraj){
		rijec[r]=*pocetak;
		pocetak++;
		r++;
	}
	rijec[r]='\0';
	int duzina=r;
	
	/* Izbacivanje podstringa */
	
	char *pok=s;
	while (*pok!='\0'){
		char *p6=pok;
		char *p7=rijec;
		char tmp3=*p6,tmp4=*p7;
		if (*p6>='a'&&*p6<='z') tmp3=*p6-32;
		if (*p7>='a'&&*p7<='z') tmp4=*p7-32;
		while (tmp3==tmp4){
			if (znak(p6)&&znak(p7)) break;
			p6++;p7++;
			tmp3=*p6;tmp4=*p7;
		    if (*p6>='a'&&*p6<='z') tmp3=*p6-32;
		    if (*p7>='a'&&*p7<='z') tmp4=*p7-32;
		}
		if (*p7=='\0'&&(pok==poc||znak(pok-1)&&znak(p6))){
			char *izbaci=pok;
			if (duzina==0) break;
			while (*(izbaci+duzina-1)!='\0'){
				*izbaci=*(izbaci+duzina);
				izbaci++;
			}
		}
		pok++;
		
		
	}
	
	

	
	return poc;
	
	
	
}


int main() {
char t[]=" Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";
printf("'%s'", izbaci_najcescu(t));
	return 0;
}
