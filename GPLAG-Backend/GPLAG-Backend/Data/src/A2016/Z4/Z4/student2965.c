#include <stdio.h>
#define EPSILON 0.0001
#include <math.h>
char* obuhvat(char *s,float x1,float y1,float x2, float y2) {
	char* pocetak, *kraj;
	char *pocetno=s;
	float x,xdecimalno,y,ydecimalno;
	int brojx,brojy,predznak,i;
	while(*s!='\0') {
		if(*s=='(') {
			if(s==pocetno) pocetak=s;
			x=0;y=0;xdecimalno=0;ydecimalno=0;brojx=0;brojy=0;predznak=1;
			s++;
		}
		else return NULL;
		if(*s=='-') {
			predznak=-1;
			s++;
		}
		if(*s<'0' || *s>'9') return NULL;
		while (*s>='0' && *s<='9') {
			x=x*10+predznak*(*s-'0');
			s++;
		}
		if(*s=='.') {
			s++;
			if(*s==' ') return NULL;
			while(*s>='0' && *s<='9') {
				xdecimalno=xdecimalno + 10 + (*s-'0');
				brojx++;
				s++;
				if(*s==',') {
					for(i=0;i<brojx;i++) xdecimalno=xdecimalno/10;
					x=x+predznak*xdecimalno;
					predznak=1;
				}
			}
		}
		predznak=1;
		if(*s==',')	s++;
		else return NULL;
		if(*s=='-') {
			predznak=-1;
			s++;
		}
		if(*s<'0' || *s>'9') return NULL;
		while(*s>='0' && *s<='9') {
			y=y*10+ predznak*(*s-'0');
			s++;
		}
		if(*s=='.') {
			s++;
			if(*s==' ') return NULL;
			while(*s>='0' && *s<='9') {
				ydecimalno=ydecimalno+10+(*s-'0');
				brojy++;
				s++;
				if(*s==')') {
					for(i=0;i<brojy;i++) ydecimalno=ydecimalno/10;
					y=y+predznak*ydecimalno;
				}
			}
		}
		if(*s==')') {
			s++;
			kraj=s;
		}
		else return NULL;
		if(x<x1 || x>x2 || y<y1 || y>y2) {
			while(*kraj!='0') {
				*pocetak=*kraj;
				pocetak++;
				kraj++;
			}
			*pocetak=*kraj;
			s=s-(kraj-pocetak);
		}
		if(*s==',') {
			pocetak=s;
			s++;
			x=0;
			y=0;
			xdecimalno=0;
			ydecimalno=0;
			brojy=0;
			brojx=0;
			predznak=1;
			if(*s=='\0') return NULL;
		}
	}
	s=pocetno;
	if(*s==',') {
		while(*s!='\0') {
			*s=(*s+1);
			s++;
		}
		*s=(*s+1);
	}
	s=pocetno;
	return s;
}
			
			
		
						
		
			
			
			

int main() {
	return 0;
}
