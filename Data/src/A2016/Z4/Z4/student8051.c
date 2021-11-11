#include <stdio.h>
#include<math.h>
#define eps 0.0001
//Duz je funkcija koja vraca duzinu ispitanog stringa.
int duz(char *s){
	int l=0;
	while(*s++!=0)
		l++;
	return l;
}
//Ispitaj funkcija nam govori da li je dati izraz ispravan ili ne. Ukoliko jest vraca 1, u suprotnom vraca 0.
int ispitaj(char *s){
	int logik=0,brz=0,bro=0,brm=0,brt=0,brzt=0;
	//brz je broj zareza, bro je broj otvorenih zagrada, brm je broj minunsa, brt je broj tacaka, brzt je broj zatvorenih zagrada.
	char *y;
	y=s; //y je pokazivac koji pokazuje na pocetak stringa s.
	while(*s!=0)
	{
		//Ukoliko se pojavljuje neki drugi znak osim zagrada, brojeva, tacke, minusa, zareza. 
		if(*s>='0'&&*s<='9'||*s=='-'||*s=='('||*s==')'||*s==','||*s=='.')
			logik=0;
		else
		 	logik=1;
		//logik je logicka funkcija koja govori da li je znak zadovoljava gore navede uslove. Ukoliko zadovoljava onda je 0, a u suprotnom je 1.
		if(logik==1)
			return 0;
		s++;
	}
	s=y; //Vraca na pocetak stringa.
	int i,p=0,j;
	//Ova petlja provjerava unutar zagrada da li je sve OK.
	for(i=0;i<duz(s);i++)
	{
		//Ukoliko se poslije otvorene zagrade nalazi , ili . da funkcija odmah vraca 0.
		if(s[i]=='('&&(s[i+1]==','||s[i+1]=='.'))
				return 0;
		//Provjera unutar zagrada.
		if(s[i]=='(')
		{
			brz=0;
			brt=0;
			brm=0;
		
			for(j=i+1;j<duz(s);j++)
			{
				if(s[j]=='.')
					brt++;
				else if(s[j]==',')
					brz++;
				else if(s[j]=='-')
					brm++;
				if(s[j]==','&&(s[j+1]==')'||s[j+1]=='.'))
					return 0;
				if(s[j]==')')
					break;
			}
			//Ukoliko je broj minusa veca od 2, ili je broj zareza razlicita od 1, ili je broj decimalnih tacaka veca od 2, funkcija vraca 0, odnosno string s je neispravan.
			if(brm>2||brz!=1||brt>2)
				return 0;
			i=j+1; //Petlja nastavlja od sljdece otvorene zagrade.
		}
		else
			return 0;
	}
	bro=0;
	brz=0;
	brzt=0;
	brm=0;
	brt=0;
	for(i=0;i<duz(s);i++)
	{
		if(s[i]=='(')
			bro++;
		else if(s[i]==')')
			brzt++;
		else if(s[i]==',')
			brz++;
		else if(s[i]=='-')
			brm++;
		else if(s[i]=='.')
			brt++;
	}
	//Ispituje broj otvorenih, zatvorenih zagrada, decimalnih tacaka, minusa u stringu. 
	if(bro!=brzt||brt>2*bro||brz!=2*bro-1||brm>2*bro)
		return 0;
		
	return 1;
}
//Ova funkcija "vadi" broj iz datog stringa. Razlika izmedju funkcija izvadi1 i izvadi2 je ta sto izvadi1 uzima prvu koordinatu iz zagrada, a izvadi2 drugu. 
float izvadi1(char *s,int i){
	float a=0,k=1;
	int pred=1,t=0;
	for(i;i<duz(s);i++)
	{
		if(s[i]==',')
			break;
		else if(s[i]=='-')
			pred=-1;
		else if(s[i]=='.'&&s[i+1]==',')
			break;
		else if(s[i]=='.')
			t=1;
		else if(s[i]>='0'&&s[i]<='9'&&t==0)
		{
			a=a*10+s[i]-48;
		}
		else if(s[i]>='0'&&s[i]<='9'&&t==1){
			k*=10;
			a+=(float)((s[i]-48)/k);
		}
	}
	a*=pred;
	return a;
}

float izvadi2(char *s,int i){
	float a=0,k=1;
	int pred=1,t=0;
	for(i;i<duz(s);i++)
	{
		if(s[i]==')')
			break;
		else if(s[i]=='-')
			pred=-1;
		else if(s[i]=='.'&&s[i+1]==')')
			break;
		else if(s[i]=='.')
			t=1;
		else if(s[i]>='0'&&s[i]<='9'&&t==0)
		{
			a=a*10+s[i]-48;
		}
		else if(s[i]>='0'&&s[i]<='9'&&t==1){
			k*=10;
			a+=(float)((s[i]-48)/(k));
		}
	}
	a*=pred;
	return a;
}

char *obuhvat(char *s, float x1,float y1, float x2,float y2){
	int len=duz(s),i, a[10000],b[10000],t=0,j,z=0;
	//a je niz koji nam oznacava prvu koordinatu iz zagrade, a b kraj te zagrade.
	char q[10000];
	//q je pomocni string iz kojeg cemo kasnije prepisati ono sto nam je potrebno za pocetni string s.
	float p,l;
	// p i l su pomocne varijable koje nam sluze za "vadjenje" prve i druge koordinate neke tacke u stringu.
	if(ispitaj(s)==0)
		return 0;

	for(i=0;i<len;i++)
	{	
		//Ovdje oznacavamo 1. koordinatu 
		if(s[i]=='(')
		{
			//p je vrijednost 1. koordinate tacke.
			p=izvadi1(s,i);
			a[t]=i;
		}
		//A ovdje 2.koordinatu.
		if(s[i]==','&&s[i+1]!='(')
		{
			//A l je vrijednost  2. koordinate tacke.
			l=izvadi2(s,i);
			for(j=i;j<duz(s);j++)
				if(s[j]==')') break;
			
			b[t]=j;
			//Uporedjivanje pomocu epsilona.
			if((p-x1>0||fabs(p-x1)<eps)&&(p-x2<0||fabs(p-x2)<eps)&&(l-y1>0||fabs(l-y1)<eps)&&(l-y2<0||fabs(l-y2)<eps)){
				t++;
			//t je brojac koji nam produzuje niz a i niz b, odnosno one koordinate koje odgovaraju datom opsegu.
			//Ukoliko 171. linija ne zadovoljava uslov, onda se preko tih neodgovarajucih clanova ispisuju drugi. Odnosno pozicije drugih tacaka...
			}
		}
		
	}
	//Ovdje se prepisuju odredjene tacke u string q.
	for(i=0;i<t;i++)
	{
		// z je brojac koji nam pomaze pri ispisivanju zareza u stringu.
		for(j=a[i];j<=b[i];j++)
		{
			//Ovdje dodajemo zarez izmedju tacaka.
			if(z!=0&&j==a[i])
			{
				q[z]=',';
				z++;
			}
			q[z]=s[j];
			z++;
		}
	}
	//String s postaje prazan.
	for(i=0;i<len;i++)
		s[i]=0;
	//Prepisujemo iz q u s.	
	for(i=0;i<z;i++)
		s[i]=q[i];
	return s;
}




int main() {
	//Kraci program za ispitivanje tacnosti funkcije obuhvat.
	char s[] = "(0,-3.12),(-15.09,4.12),(2.,2),(-1.1,217)";
	char* rez = obuhvat(s, -3, -3, 3, 3);
	printf("%s %s", rez, s);
}
