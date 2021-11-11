#include <stdio.h>
#include <math.h>
#define EPS 0.0001

char* obuhvat(char* s, float t1, float t2, float t3, float t4)
{
	char* reset= s;
	char* pok2;
	char* poc, *poc2, *nastavak;
	float tacka[1000][2]= {0}, temp, suma, suma2;
	int izbaci[100]= {0};
	float xmin, xmax, ymin, ymax;
	char* ptacke[4];
	int i=0, j=0, zag1=0, zag2=0, zarez=0, duzina, br_izbaci=0;
	int predznak=0;

	xmin=t1;
	xmax=t3;
	ymin=t2;
	ymax=t4;

	//provjera unosa
	while(*s != '\0') {
		if(*s=='(')
			zag1++;
		if(*s==')')
			zag2++;
		if(*s==',')
			zarez++;
		if((*s <'0' || *s >'9') && *s != '(' && *s!= '.' && *s!=',' && *s!=')' && *s!='-') //ako se pojavljuje nedozvoljena vrijednost
			return NULL;
		if(*s == '(' && (*(s+1) <'0' || *(s+1)>'9') && *(s+1) != '-')  //ako se poslije otvorene zagrade ne nalazi cifra ili predznak -
			return NULL;
		if(*s=='-' && (*(s+1) <'0' || *(s+1)>'9'))		//ako se poslije minusa ne nalazi cifra
			return NULL;
		if(*s=='.' && (*(s+1) <'0' || *(s+1)>'9') && *(s+1) !=',' && *(s+1) != ')')	// ako se poslije tacke ne nalazi cifra ili zarez ili zatvorena zagrada
			return NULL;
		if(*s==',' && (*(s+1) <'0' || *(s+1)>'9') && *(s+1) !='(' && *(s+1) != '-')  // ako se poslije zareza ne nalazi cifra ili otvorena zagrada ili zarez
			return NULL;
		if(*s==')' && *(s+1) != '\0' && *(s+1) != ',')	//ako poslije zatvorene zagrade nije zavrsetak stringa ili zarez
			return NULL;
		if(*s >='0' && *s <='9' && *(s+1) != '.' && *(s+1) != ',' && *(s+1) != ')' && !(*(s+1)>='0' && *(s+1) <= '9')) //ako se poslije cifre ne nalazi druga cifra ili tacka,zarez ili zatvorena zagrada
			return NULL;
		s++;
	} //provjerava odnos broja zagrada i zareza
	if(zag1+zag2-zarez!=1)
		return NULL;
	s=reset;

	duzina=4+fabs(zag1-4);

	//predznak=0 plus, predznak=1 minus
	//prebacivanje koordinata iz stringa u matricu, suma za cijeli dio broja, suma2 za decimalni
	while(*s != '\0') {
		suma=0;
		suma2=0;
		predznak=0;
		if(*s>= '0' && *s <= '9') {
			if(*(s-1) == '(' )
				*ptacke=s;
			suma=0;
			poc=s;
			if(*(s-1)=='-')
				predznak=1;

			while(*poc >= '0' && *poc <= '9') {
				temp=*poc-48;
				suma=suma*10 + temp;
				poc++;
			}
			nastavak=poc-1;
			if(*poc=='.') {
				suma2=0;
				poc2=poc+1;
				while(*poc2 >= '0' && *poc2 <= '9') {
					poc2++;
				}
				poc2--;
				nastavak=poc2;
				while(*poc2 != '.') {
					temp=*poc2-48;
					suma2=(float)suma2/10 +temp/10;
					poc2--;
				}
			}
			tacka[i][j]=suma+suma2;
			if(predznak)
				tacka[i][j]-=2*tacka[i][j];

			j++;
			s=nastavak;
		}
		if(j==2) {
			i++;
			j=0;
		}
		s++;
	}

	//provjeravamo koje tacke treba izbaciti iz stringa, ako je j==0 onda se provjerava x koordinata, ako je j==1 onda se provjerava y koordinata

	for(i=0; i<duzina; i++) {
		for(j=0; j<2; j++) {
			if((((tacka[i][j] <xmin && fabsf(tacka[i][j]-xmin)>EPS) || (tacka[i][j] > xmax) && fabsf(tacka[i][j]-xmax)>EPS) && j==0) || (((tacka[i][j]<ymin && fabsf(tacka[i][j]-ymin)>EPS) || (tacka[i][j]>ymax)&& fabsf(tacka[i][j]-ymax)>EPS) && j==1))
				izbaci[i]=1;

		}
	}

	//ako treba izbaciti sve tacke
	s=reset;
	for(i=0; i<zag1; i++) {
		if(izbaci[i]==0)
			break;
	}
	if(i==zag1) {
		*s='\0';
		return s;
	}

	//izbacivanje iz stringa
	s=reset;
	i=0;
	while(*s != '\0') {
		if(*s=='(') {

			if(izbaci[i]==1) {
				if(i==duzina-1) {
					*(s-1)='\0';
					return reset;
				}
				char* reset1=s;
				pok2=s;
				while(*pok2 != ')' && *pok2 != '\0')
					pok2++;
				pok2+=2;
				while(*reset1++ = *pok2++);
				s--;
			}
			i++;
		}
		if(i==duzina)
			return reset;
		s++;
	}
	s=reset;
	return reset;
}
int main()
{
	int rez;
	char i[] = "(5,1),(1,1),(5,1),(8,5),(5,1),(8,5)";
	obuhvat(i, -3, -3, 3, 3);
	return 0;
}
