#include <stdio.h>
#include <stdlib.h>
    /* Provjeravanje na sta pokazuje pokazivac p2 */ 
int znak(char *slovo){
	if ((*slovo>='A'&&*slovo<='Z')||(*slovo>='a'&&*slovo<='z')||*slovo=='-'||*slovo=='.') return 0;
	else return 1;
}
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char *p1=tekst,*poc=tekst;
	int duzina=0,duzina1=0,duzina2=0,i,l,m,j;
	for (i=0;i<broj_rijeci;i++){
		j=0;
		duzina1=0;
		duzina2=0;
		/* Odredivanje duzine rijeci */ 
		while(rijeci[i][j]!='\0'){
			duzina1++;
			j++;
		}
		m=0;
		while (zamjene[i][m]!='\0'){
			duzina2++;
			m++;
		}
		duzina=duzina2-duzina1;
		p1=tekst;
		/* Trazenje rijeci */
		while (*p1!='\0'){
			char *p2=p1;
			char *p=rijeci[i];
			while (*p2==*p){
				if (*p=='\0') break;
				p2++;p++;
			}
			int provjera2=znak(p2);
			/* Uslovi za jednakost rijeci, zatim zamjena */
			if (*p=='\0'&& (p1==poc||*(p1-1)==' ')&&(*p2=='\0'||*p2==' '||provjera2)){
				if (duzina==0){
					for(l=0;l<duzina1;l++){
						*p1++=zamjene[i][l];
					}
				}
				else if(duzina1<duzina2){
					char *kraj=p1;
				    while (*kraj != '\0') kraj++;
				    while (kraj > p1) {
   				    *(kraj+duzina) = *kraj;
   				    kraj--;
   			        }
   			        for (l=0;l<duzina2;l++){
   			    	*p1++=zamjene[i][l];
   			        }
					
				}
			
				else if(duzina1>duzina2){
					char *pocetak=p1;
				    while (*pocetak!='\0') {
   				    *pocetak=*(pocetak-duzina);
   				    if (*pocetak=='\0') break;
   				    pocetak++;
   			        }
   			        for (l=0;l<duzina2;l++){
   			    	*p1++=zamjene[i][l];
				    }
				 
   			    }
   			    
   			    p1--;
   			   
   			    
   			    
			}
                
   			    
   		
			p1++;	
			}
			
			
		}
		

      
	
	return poc;
}
int main() {
char* rijeci[2] = {"test", "testiranje"};
char* zamjene[2] = {"swap", "zamjena" };
char tekst[] = "test testiranje test";
printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 1));

return 0;

}
