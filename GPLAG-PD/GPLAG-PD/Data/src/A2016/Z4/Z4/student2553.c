#include <stdio.h>
#include <math.h>
int jelibroj(char c){
	if(c>='0' && c<='9')return 1;
	else return 0;
}
int jeliunutra(double x,double y,double x1,double y1,double x2,double y2){
		if(x>=x1  && x<=x2 && y>=y1 && y<=y2)return 1;
	return 0;
}
int znakucifru(char c){
	return c-'0';
}
char *obuhvat (char *tekst,double x1,double y1,double x2,double y2){
	char *temp=tekst,*pok;
	int znak=1,stepen=0;
	double x=0,y=0,decimale=0;
		while(*tekst!='\0'){
		if(*tekst!='(')return NULL;
		tekst++;
		if(*tekst=='-' && *tekst!='\0')tekst++;
		
		if(jelibroj(*tekst)==0)return NULL;
		
		while(*tekst!='\0' && *tekst!='.' && *tekst!=','){
			if(jelibroj(*tekst)==0)return NULL;
			tekst++;
		}
		
		if((*tekst!='.' && *tekst!=',') || *tekst=='\0')return NULL; /*prva koordinata pola ili cijela*/
		
		if(*tekst=='.'){
			tekst++;
			while(*tekst!='\0' && *tekst!=','){
				if(jelibroj(*tekst)==0)return NULL;
				tekst++;
			}
			if(*tekst!=',' || *tekst=='\0')return NULL;
		}
		if(*tekst!=',')return NULL;
		tekst++;
		/*kraj prve koordinate,*tekst iza zareza*/
		if(*tekst=='-' && *tekst!='\0')tekst++;
		if(jelibroj(*tekst)==0)return NULL;
		while(*tekst!='\0' && *tekst!='.' && *tekst!=')'){
			if(jelibroj(*tekst)==0)return NULL;
			tekst++;
		}
		if(*tekst=='.'){
			tekst++;
			while(*tekst!='\0' && *tekst!=')'){
				if(jelibroj(*tekst)==0)return NULL;
				tekst++;
			}
		}
	if(*tekst!=')')return NULL;
		tekst++;
		if(*tekst!='\0' && *tekst!=',')return NULL;
		else if(*tekst!='\0'){
			if(*tekst!=',')return NULL;
			tekst++;
			if(*tekst!='(')return NULL;
		}
	}
	tekst=temp;
	while(*tekst!='\0'){
		while(*tekst!='(')tekst++;
		if(tekst==temp){pok=tekst;}
		else pok=tekst-1;
		tekst++;
		if(*tekst=='-'){znak=-1; tekst++;}
		else {znak=1;}
		x=0;
		while(*tekst!='.' && *tekst!=','){
			x*=10;
			x+=znakucifru(*tekst);
			tekst++;
		}
		decimale=0;
		stepen=0;
		if(*tekst=='.'){
			tekst++;
			while(*tekst!=','){
				decimale*=10;
				decimale+=znakucifru(*tekst);
				stepen++;
				tekst++;
			}
		}
		tekst++;
		x=znak*(x+decimale/(pow(10,stepen)));

		
		/*tekst na prvom znaku druge koordinate*/
		
		if(*tekst=='-'){znak=-1; tekst++;}
		else {znak=1;}
		
		y=0;
		while(*tekst!=')' && *tekst!='.'){
			y*=10;
			y+=znakucifru(*tekst);
			tekst++;
		}
		decimale=0;
		stepen=0;

		if(*tekst=='.'){
			tekst++;
			while(*tekst!=')'){
				decimale*=10;
				decimale+=znakucifru(*tekst);
				stepen++;
				tekst++;
			}
		}
		tekst++;
		if(stepen!=0)y=znak*(y+decimale/(pow(10,stepen)));
		else y=znak*y;
		/*pokazuje na zarez izmedju dvije koord ili na kraj stringa*/
		if(jeliunutra(x,y,x1,y1,x2,y2)==0){
		
			/*izbacivanje striktno do znaka )*/
			tekst=pok;
			while(*tekst!=')'){
				tekst=pok;
				while(*tekst!='\0'){
					*tekst=*(tekst+1);
					tekst++;
				}
				tekst=pok;
			}
			tekst=pok;
			
			while(*tekst!='\0'){
				*tekst=*(tekst+1);
				tekst++;
			}
			tekst=pok;
			if(*tekst==',' && pok==temp){
				tekst=pok;
				while(*tekst!='\0'){
					*tekst=*(tekst+1);
					tekst++;
				}
			}
			tekst=pok;
		}
	}
	return temp;
}
int main() {
	char a[] = "(0,-3),(-15,4),(2,2),(-1,217)k(1,1)";
	printf("%s",obuhvat(a,0,0,5.90,5.90));
	return 0;
}