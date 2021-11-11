#include <stdio.h>

char*  obuhvat(char*c, float x1, float y1, float x2, float y2){
	char* reset=c, *pocetak=c, *kraj;
	float x, xd, y, yd; 
	int i, brx,bry, predznak;
	while(*c!='\0'){
	if(*c=='(') {
		       if(c==reset)
			       pocetak=c;
				x=0;
			    y=0;
			    xd=0; yd=0;
			    brx=0; bry=0;
			    predznak=1;
			    c++;
			}
			else return NULL;
		
				if(*c=='-'){
				predznak=-1;
				c++;
				}
				if (*c<'0'|| *c>'9') return NULL;
			while(*c>='0'&& *c<='9'){
					x=x*10 + predznak*(*c-'0');
					c++;
				}
				
		if(*c=='.'){
			c++;
			if (*c==' ') return NULL;
			while(*c>='0'&& *c<='9'){
				xd= xd*10 + (*c-'0');
				brx++;
				c++;
				if(*c==','){
					for(i=0; i<brx; i++)
					xd=xd/10;
					x= x+ predznak*xd;
					predznak=1;
					
				}
				
			}
		}
		predznak=1;
		
				if(*c==',') c++; else return NULL;
				if(*c=='-')	{predznak=-1; c++;}
				if (*c<'0'|| *c>'9') return NULL;
				while(*c>='0'&& *c<='9'){
					y=y*10 + predznak*(*c-'0');
					c++;
				}
				
				/*Racunanje decimala broja ako je broj decimalan*/
			if(*c=='.')
			{ c++;
		    if (*c==' ') return NULL;
			while(*c>='0'&& *c<='9'){
				yd= yd*10 + (*c-'0');
				bry++;
				
				c++;
				if(*c==')'){
					for(i=0; i<bry; i++)
					yd=yd/10;
					y= y+ predznak*yd;
			
				}
			}
			}
			if (*c==')') {
	             c++;
				kraj= c;
			}
			else return NULL;
			
			/*Izbacivanje onih tacaka koje se ne nalaze unutar pavougaonika*/
			if( x<x1 || x> x2 || y<y1 || y> y2)
			{
				while(*kraj!='\0')
				{
					*pocetak=*kraj;
					pocetak++;
					kraj++;
				}
				*pocetak=*kraj;
				c= c-(kraj-pocetak);
			}
			if(*c==',') {
			pocetak=c;
			c++;
				x=0;
			    y=0;
			    xd=0; yd=0;
			    brx=0; bry=0;
			    predznak=1;
			    if(*c=='\0') return NULL;
			}
			
	
		
	
	
	}
	/*Izbacivanje zareza ako se nalazi na pocetku stringa*/
	c=reset;
	if(*c==','){
		while(*c!='\0'){
			*c=*(c+1);
			c++;
		}
		*c=*(c+1);
	}
	c=reset;
	return c;
}


int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}
