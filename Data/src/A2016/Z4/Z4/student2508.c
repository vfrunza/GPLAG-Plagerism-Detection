#include <stdio.h>
#define E 0.0001
#include <math.h>

char *stringcpy(char *s, char *r)
{
	char *pocs=s;
	int i;
	for(i=0; r[i]!='\0'; i++)
		s[i]=r[i];
	s[i]='\0';
	return pocs;
}

char *obuhvat(char* s,double x1,double y1,double x2,double y2)
{
	char *pocs=s,*temp,*pockor,*krajkor,*temp2;
	double x,y,dec;
	int minus,brzareza;
	/*Ispitivanje pravilnosti unosa*/

	if(s[0]!='(')
		return NULL;

	while(*s!='\0') {
		if(*s!='(' && *s!=')' && *s!='.' && *s!=',' && *s!='-' && !(*s>='0' && *s<='9'))
			return NULL;

		if(*(s+1)=='\0') {
			if(*s!=')')
				return NULL;
		}

		if(*s=='(') {
			temp2=s;
			brzareza=0;
			while(*temp2!=')' && *temp2!='\0') {
				if(*temp2==',')
					brzareza++;
				temp2++;
			}
			if(brzareza!=1)
				return NULL;

			if(*(s+1)!='-' && !(*(s+1)>='0' && *(s+1)<='9'))
				return NULL;
			if(s!=pocs) {
				if(*(s-1)!=',')
					return NULL;
			}
		}

		if(*s==')') {
			if(*(s+1)!=',' && *(s+1)!='\0')
				return NULL;

			if(s!=pocs) {
				if(*(s-1)!='.' && !(*(s-1)>='0' && *(s-1)<='9'))
					return NULL;
			}
		}

		if(*s=='.') {
			if(*(s+1)!=')' && *(s+1)!=',' && !(*(s+1)>='0' && *(s+1)<='9'))
				return NULL;

			if(s!=pocs) {
				if(!(*(s-1)>='0' && *(s-1)<='9'))
					return NULL;
			}
		}

		if(*s==',') {
			if(*(s+1)!='-' && *(s+1)!='(' && !(*(s+1)>='0' && *(s+1)<='9'))
				return NULL;

			if(s!=pocs) {
				if(*(s-1)!='.' && *(s-1)!=')' && !(*(s-1)>='0' && *(s-1)<='9'))
					return NULL;

				if(*(s-1)==')') {
					if(*(s+1)!='(')
						return NULL;
				}
			}

		}
		s++;
	}
	s=pocs;

	/*Trazenje brojeva*/

	while(*s!='\0') {

		if(*s>='0' && *s<='9') {
			pockor=s-1;
			if(*pockor=='-')
				pockor--;
			minus=0;
			x=0;
			y=0;
			temp=s;
			if(*(s-1)=='-')
				minus=1;
			while(*temp>='0' && *temp<='9') {
				x=(*temp-'0')+10*x;
				temp++;
			}
			
			if(*temp=='.') {
				temp++;
				dec=0;
				while(*temp>='0' && *temp<='9') {
					dec=dec+(double)(*temp-'0')/10;
					temp++;
				}
				x=(double)x+dec;

			}
			if(minus==1)
				x=-x;

			minus=0;

			if(*temp==',')
				temp++;

			if(*temp=='-') {
				minus=1;
				temp++;
			}

			while(*temp>='0' && *temp<='9') {
				y=(*temp-'0')+10*y;
				temp++;
			}
			if(*temp=='.') {
				temp++;
				dec=0;
				while(*temp>='0' && *temp<='9') {
					dec=dec+(double)(*temp-'0')/10;
					temp++;
				}
				y=(double)y+dec;
			}
			if(minus==1)
				y=-y;
			s=temp;

			/*Izbacivanje koordinata koje nisu unutar pravougaonika*/
			if(x<x1 || x>x2 || y<y1 || y>y2) {
				krajkor=temp;
				krajkor++;
				if(*krajkor=='\0') {
					if(*(pockor-1)==',')
						*(pockor-1)='\0';
					else
						*pockor='\0';

				} else if(*krajkor==',') {
					krajkor++;
					stringcpy(pockor,krajkor);
				}
				s=pocs;
				if(*s=='\0')
					return pocs;
			}

		}

		s++;
	}

	return pocs;
}

int main()
{
	char s[] = "(0,-3.1),(-15.09,4),(-1.1,217)";
	char* rez = obuhvat(s, -3, -3, 3, 3);
	printf("%s %s", rez, s);

	return 0;
}
