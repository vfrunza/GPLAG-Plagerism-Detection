#include <stdio.h>
#include <math.h>
#define eps 0.0001

int je_li_broj(char c)
{
	if(c<='9' && c>='0') return 1;
	else return 0;
}

/*Da li su ispunjeni uslovi za otvorenu zagradu (*/
int test_o_zagrada(char *pokazivac)
{
	if(je_li_broj(*(pokazivac+1)) && *(pokazivac-1)==',')
	return 1;
	else return 0;
}
/*Da li su ispunjeni uslovi za zatvorenu zagradu )*/
int test_z_zagrada(char *pokazivac)
{
	if((je_li_broj(*(pokazivac-1)) || *(pokazivac-1)=='.') && *(pokazivac+1)==',')
	return 1;
	else return 0;
}
/*Da li su ispunjeni uslovi za zarez , izmedju zagrada*/
int test_zarez_1(char *pokazivac)
{
	if(*(pokazivac-1)=='(' && *(pokazivac+1)==')')
	return 1;
	else return 0;
}
/*Da li su ispunjeni uslovi za zarez , izmedju brojeva*/
int test_zarez_2(char *pokazivac)
{
	if(*(pokazivac-1)=='.' || je_li_broj(*(pokazivac-1)))
	{
		if(je_li_broj(*(pokazivac+1))) return 1;
		else return 0;
	}
	else return 0;
}
/*Da li su ispunjeni uslovi za tacku .*/
int test_tacka(char *pokazivac)
{
	if(je_li_broj(*(pokazivac-1)))
	{
		if(je_li_broj(*(pokazivac+1))) return 1;
		else if(*(pokazivac+1)==',') return 1;
		else if(*(pokazivac+1)==')') return 1;
		else return 0;
	}
	else return 0;
	
}
/*Da li su ispunjeni uslovi za broj*/
int test_broj(char *pokazivac)
{
	if(je_li_broj(*(pokazivac-1)) || *(pokazivac-1)=='(' || *(pokazivac-1)==',' || *(pokazivac-1)=='.')
	{
		if(je_li_broj(*(pokazivac+1)) || *(pokazivac+1)==')' || *(pokazivac+1)==',' || *(pokazivac+1)=='.') return 1;
	}
	else return 0;
}
/*testira je li ispravno formatiran string koji se nalazi izmedju 2 zagrade, pocetak pokazuje na otvorenu zagradu, kraj pokazuje na zatvorenu zagradu*/
int testiraj_zagradu(char *pocetak, char *kraj)
{
	int broj_tacki=0,broj_zareza=0, broj_brojeva=0,broj_elemenata=1;
	char *pom1=pocetak, *pom2=kraj;
	while (pom1!=pom2)
	{
		pom1++;
		broj_elemenata++;
	}
	pom1=pocetak+1; pom2=kraj;
	if(je_li_broj(*(pocetak+1)) && je_li_broj(*(kraj-1)) && broj_elemenata-2>=3) /*Uslovi za pocetak i kraj zagrade*/
	{
		while(pom1!=pom2)
		{
			if(*pom1=='.' && test_tacka(pom1)) broj_tacki++;
			else if(*pom1==',' && test_zarez_2(pom1)) broj_zareza++;
			else if(je_li_broj(*pom1) && test_broj(pom1)) broj_brojeva++;
			else return 0;
			pom1++;
		}
		if(broj_tacki<=2 && broj_tacki>=0 && broj_zareza==1) return 1;
		else return 0;
	}
	else return 0;
}
/*provjerava da li je ispravno formatiran string*/
int testiraj_string(char *string)
{
	char *pom1=NULL, *pom2=NULL,*pocetak=string;
	int broj_elemenata=0;
	while(*string!='\0')
	{
		string++;
		broj_elemenata++;
	}
	string =pocetak;
	if(*(string)!='(' || *(string+broj_elemenata-1)!=')') return 0; /*Nesigurno*/
	else
	{
		string=pocetak;
		while(*(string+1)!='\0')
		{
			if(*string=='(') 
			{
				if(pom2!=NULL) return 0;
				pom1=string;
			}
			else if(*string == ')')
			{
				if(*pom1!='(') return 0;
				else 
				{
					pom2=string;
					if(!testiraj_zagradu(pom1,pom2)) return 0;
					pom1=NULL;
					pom2=NULL;
				}
			}
			string++;
		}
	}
	return 1;
}

/*Pretrvara char broj u int broj*/
int char_to_int(char c) 
{
	if(c=='0') return 0;
	if(c=='1') return 1;
	if(c=='2') return 2;
	if(c=='3') return 3;
	if(c=='4') return 4;
	if(c=='5') return 5;
	if(c=='6') return 6;
	if(c=='7') return 7;
	if(c=='8') return 8;
	if(c=='9') return 9;
}
/*Pretvara string koji je formatiran kao broj npr 12.213 u double broj*/
double pretvori_u_broj(char *string)
{
	double rez=0;
	char *pocetak=string,*pok_na_tacku=NULL;
	int  broj_clanova=0,broj_prije_tacke=0,broj_nakon_tacke=1;
	while(*string!='\0')
	{
		broj_clanova++;
		if(*string=='.') 
		{
			pok_na_tacku=string;
		}
		string++;
	}
	string=pocetak;
	if(pok_na_tacku==NULL)
	{
		while(*string!='\0')
		{
			rez+=char_to_int(*string)*pow(10,broj_clanova-1);
			broj_clanova--;
			string++;
		}
	}
	else
	{
		broj_prije_tacke=pok_na_tacku-string;
		while(string!=pok_na_tacku)
		{
			rez+=char_to_int(*string)*pow(10,broj_prije_tacke-1);
			broj_prije_tacke--;
			string++;
		}
		string++;
		while(*string!='\0')
		{
			rez+=char_to_int(*string)*pow(10,-broj_nakon_tacke);
			broj_nakon_tacke++;
			string++;
		}
		
	}
	return rez;
}

int treba_li_izbaciti(double x, double y, double x1, double y1, double x2, double y2)
{
	if(x<x2 && x>x1 && y<y2 && y>y1) return 1;
	else if((fabs(x-x1)<eps || fabs(x-x2)<eps) && y<y2 && y>y1) return 1;
	else if((fabs(x-x1)<eps || fabs(x-x2)<eps) && (fabs(y-y2)<eps || fabs(y-y1)<eps)) return 1;
	else if((fabs(y-y2)<eps || fabs(y-y1)<eps) && x<x2 && x>x1) return 1;
	else return 0;
}

void izbaci_elemente(char *string, char *pocetak, char *kraj)
{
	char *rez=string,*start=string;
	char *pomocni=string,*test,temp;
	char novi[500];
	char *pok_novi=novi;
	int razlika=kraj-pocetak+1,brojac=razlika,broj_elemenata=0;

	while(*pomocni!='\0')
	{
		broj_elemenata++;
		pomocni++;
	}
	pomocni=string;
	while(*pomocni!='\0')
	{
		if(pomocni==pocetak)
		{
			while(pomocni!=kraj)
				pomocni++;
		}
		*pok_novi=*pomocni;
		pok_novi++;
		pomocni++;
	}
	*pok_novi='\0';
	pok_novi=&novi[0];
	while(*pok_novi!='\0')
	{
		*rez=*pok_novi;
		rez++;
		pok_novi++;
	}
	*rez='\0';
	/*
	pomocni=string;
	while(brojac!=0)
	{
		pomocni=pocetak;
		if(pomocni==pocetak)
		{
			string=pocetak;
			if(brojac!=0)
			{
				while(*(string+1)!='\0')
				{
					temp=*string;
					*string=*(string+1);
					string++;
					*string=temp;
				}
				brojac--;
			}
			else
			{
				break;
			}
		}

	}
	*(rez+broj_elemenata-razlika)='\0';*/
}


char *obuhvat(char *string,double x1, double y1, double x2, double y2)
{
	double x=0, y=0;
	char broj[20];
	char *pocetak=string, *pocetak_pom=NULL, *kraj_pom=NULL,*pomocni=broj,*rez=string;
	if(testiraj_string(string)==0) return NULL;
	while(*string!='\0')
	{
		if(*string=='(')
		{
			pocetak_pom=string;
			string++; /*preskoci otvorenu zagradu*/
			while(*string!=',')
				{
					*pomocni=*string;
					pomocni++; 
					string ++;
				}
			*pomocni='\0';
			x=pretvori_u_broj(&broj);
			pomocni = &broj[0];
			string++;
			while(*string!=')')
				{
					*pomocni=*string;
					pomocni++;
					string++;
				}
			*pomocni='\0';
			y=pretvori_u_broj(&broj);
			pomocni=&broj[0];
			kraj_pom=string;
			if(!treba_li_izbaciti(x,y,x1,y1,x2,y2))
			{
				izbaci_elemente(pocetak,pocetak_pom,kraj_pom);
				pocetak_pom=NULL;
				kraj_pom=NULL;
				string=rez;
				if(*string='\0') return rez;
			}
		}
		string++;
	}
	return rez;
}

int main() 
{
char s[] = "(1.1,5.5),(1.2,5.5),(1.3,5.5),(1.4,5.5),(1.5,5.5)";
char* rez = obuhvat(s, 1.2, 5.499, 1.4, 5.501);
printf("%s", rez);
}
