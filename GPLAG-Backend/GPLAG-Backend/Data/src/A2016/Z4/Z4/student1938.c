#include <stdio.h>
#include <math.h>
#define epsilon 0.0001


int power (int a, int c) {
	if(c==0)return 1;
	return a*power(a,c-1);
}


char *obuhvat(char *input,float ax,float ay,float bx,float by) {
	char *output=input,*tmpo,*tmp2;
	float vr1,vr2,tmp1;
	//provjeravamo input
	char *tmp=input,*izbacivac;
	int a=1,coeficient,doTacke,duzina,shift;
	int br,broj_z=0,broj_zrz=0;
	if(*tmp!='(')a=0;
	while(*tmp!='\0') {
		if(!(*tmp==',' || *tmp=='(' || *tmp ==')' || *tmp =='.' || *tmp=='-' || (*tmp >='0' && *tmp <='9')))a=0;
		if(*tmp=='.' || *tmp == ')') {
			if(*(tmp-1)<'0')a=0;
			if(*(tmp-1)>'9')a=0;

		}
		if(*tmp == '(')broj_z++;
		if(*tmp == ',') {
			broj_zrz++;
			if(broj_zrz%2 != 0) {
				if(tmp == input) a=0;
				else if((*(tmp-1)<'0' || *(tmp-1)>'9'))if(*(tmp-1)!='.')a=0;
				else if((*(tmp+1)<'0' || *(tmp+1)>'9') )if(*(tmp+1)!='-')a=0;

			} else {
				if(*(tmp-1)!=')' || *(tmp+1)!='(')a=0;
			}
		}
		tmp++;
	}
	if(tmp!=input && *tmp=='\0') if(*(tmp-1)!=')') a= 0;
	if(broj_z==1 && broj_zrz!=1)a=0;
	if(broj_z>1 && broj_zrz!=(2*broj_z-1))a=0;
	if(a==0)return NULL;
	while(*input!='\0') {
		tmpo = input;
		duzina = 0;
		while(*input!=',') {
			input++;
		}
		br=0;
		coeficient = 0;
		doTacke = 126;
		input--;
		a=0;
		while(*input!='(') {
			if(*input=='-') {
				br*=-1;
				break;
			}
			a++;
			if(*input=='.') {
				doTacke = a;
				input--;
				continue;
			}
			br+=(*input - '0') * pow (10,coeficient++);
			input--;
		}
		if(doTacke!=126)
			vr1 = br * pow(10,-doTacke +1) ;
		else vr1 = (float )br ;
		while(*input!=')') {
			duzina++;
			input++;
		}
		br=0;
		coeficient = 0;
		doTacke = 126;
		input--;
		a=0;
		while(*input!=',') {
			if(*input=='-') {
				br*=-1;
				break;
			}
			a++;
			if(*input=='.') {
				doTacke = a;
				input--;
				continue;
			}
			br+=((*input) - '0') * pow (10,coeficient++);
			input--;
		}
		if(doTacke!=126)
			vr2 = br * pow(10,-doTacke + 1) ;
		else vr2 = (float )br ;
		shift = 0;
		if(vr1 < ax || vr1 > bx || vr2<ay || vr2>by) {
			shift =1;
			*tmpo = '_';
			while(*tmpo!='(' && *tmpo!='\0') {
				tmp2 = tmpo ;
				while(*tmp2!='\0') {
					*(tmp2 )= *(tmp2 + 1);
					tmp2++;
				}
			}

		}
		if(shift) {
			while(input!=output) {
				input--;
			}
		} else
			while(*input!='(' && *input!='\0') {
				input++;
			}
	}
	tmpo = output;
	while(*tmpo!='\0')tmpo++;
	if((tmpo)!= output){
	if(*(tmpo-1)==',')*(tmpo-1)='\0';}
	return output;
}
int main() {
	char s[] = "(1.4,5.5)";
	
	obuhvat(s, 1.2, 5.499, 1.4, 5.501);
	printf("'%s' ", s);
	return 0;
}
