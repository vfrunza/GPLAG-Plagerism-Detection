#include <stdio.h>
//Funkcija mjeri duzinu stringa.
int duz(char *s){
	int l=0;
	char *k;
	k=s;
	while(*k!=0)
	{	
		l++;
		k++;
	}
	return l;
}
//Uzima vrijednost najveceg clana u nizu.
int najveci(int a[]){
	int maxi=a[0],i;
	for(i=1;i<95;i++)
	{
		if(a[i]>maxi)
			maxi=a[i];
	}
	return maxi;
}

char *kodiraj (char *s,char *p){
	//Niz brojaca "a" koji nam govorio koliko se koji znak pojavljuje puta.
	int a[95]={0};
	char *k;
	k=s;
	int i=0,len,maxi=0,j;
	//len je duzina pocetnog stringa.
	//k je pokazivac koji pokazuje na pocetak stringa s.
	len=duz(s);
	//Petlja koja broji koji se znak pojavljuje koliko puta.
	for(i=0;i<len;i++)
	{
		a[s[i]-32]++;
	}
	j=0;
	//maxi je varijabla koja poprima vrijednost najveceg clana u nizu brojaca a.
	maxi=najveci(a);
	//While petlja ide sve dok je maxi >=0 (ili veca od  -1). 
	while(maxi>-1){
		for(i=0;i<95;i++)
		{
			//Ukoliko je brojac jednak varijabli maxi, taj znak koji se veze za brojacc a[i] se dodaje na string p.
			if(a[i]==maxi)
			{
				p[j]=i+32;
				j++;
			}
		}
		maxi--;
	}
	p[95]=0; //Obiljezava kraj stringa.
	for(i=0;i<len;i++)
	{
		for(j=0;j<95;j++)
		{
			//String s se mijenja tako sto se od 126 oduzima pozicija tog chara u stringu p.
			if(s[i]==p[j])
			{
				s[i]=126-j;
				break;
			}
		}
	}
	return k;
}


char *dekodiraj(char *s,char *p){
	int i,j;
	//Ovdje se radi inverzna funkcija od one prethodne. Naime, od one "sifre", string s se vraca u "normalu". 
	for(i=0;i<duz(s);i++)
	{
		//Veza izmedju s i p, je razlika 126 i vrijednost od chara s[i].
		s[i]=p[126-s[i]];
	}
	return s;
}
int main() {
	/* Kraci program za ispitivanje tacnosti funkcija kodiraj i dekordiraj. */ 
	char s[]="LLMLNLNMONM";
	char p[96];
	kodiraj(s,p);
	dekodiraj(s,p);
	
	return 0;
}
	
	