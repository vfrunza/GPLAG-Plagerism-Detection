#include <stdio.h>
//Duz izracunava duzinu stringa.
int duz(char* s){
	
	int len=0;
	while(s[len]!=0)
		len++;
	return len;
}
//Provjera je funkcija koja vraca 1 ako su 2 stringa jednaka, u suprotnom vraca -1.
int provjera(char *s, char *t){
	if(duz(s)!=duz(t))
		return -1;
	int i;
	while(*s!=0)
	{
		if(*s!=*t)
			return -1;
		s++;
		t++;
	}
	return 1;
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char pom[1000];
	//pom je pomocna varijabla koja nam sluzi za "vadjenje" rijeci iz stringa. 
	int i,j,k,m,p=0,z=0,s,temp=0;
	for(i=0;i<duz(tekst);i++)
	{
		if(i==0||(tekst[i]!=' '&&tekst[i-1]==' '))
		{
			p=0;
			//Ova petlja nam sluzi za vadjenje rijec po rijec iz stringa.
			for(j=i;j<duz(tekst);j++)
			{
				if(tekst[j]==' ')
					break;
				pom[p]=tekst[j];
				p++;
			}
			pom[p]=0;//Oznacava kraj stringa.
			/*Ova petlja ispituje da li je data rijec koja je izvadjena iz stringa ona koja se treba mijenjati. 
			Ukoliko jest, onda provjerava da li je data duzina rijeci veca od zamjene ili ne.*/
			for(m=0;m<broj_rijeci;m++)
			{
				if(provjera(pom,rijeci[m])==1){
					if(duz(zamjene[m])>duz(rijeci[m])){
						//K je varijabla koja predstavlja razliku u duzine zamjenske rijeci od one rijeci koje se mijenja.
						k=duz(zamjene[m])-duz(rijeci[m]);
						s=duz(tekst);
						tekst[s+k+1]=0;//Oznacava kraj stringa.
						//Ovdje pravimo slobodan prostor za rijec koju cemo ubaciti.
						for(z=s;z>=j;z--){
							tekst[z+k]=tekst[z];
						}
					}
					else if(duz(zamjene[m])<duz(rijeci[m])){
						//Sve isto kao od linije 49 do 56. 
						k=duz(zamjene[m])-duz(rijeci[m]);
						//Ovdje je k negativan, zato se mnozi sa -1 da bi bio pozitivan. 
						k*=-1;
						s=duz(tekst);
						for(z=j;z<s;z++)
						{
							tekst[z-k]=tekst[z];
						}
						tekst[z-k]=0;
					}
					temp=0;//Temp je pomocna varijabla koja pokazuje na poziciju chara u nizu stringova zamjene.
					for(z=i;z<i+duz(zamjene[m]);z++)
					{
						tekst[z]=zamjene[m][temp];
						temp++;
					}
					//Na i se dodaje duzina rijeci koje smo umetnuli zato da petlja ne bi opet isla, nego da nastavi gdje je stala. Odnosno da ide od sljedece rijeci
					i=i+duz(zamjene[m]);
					break;
				}
			}
				//Ovdje se string pom "prazni" :).
				for(j=0;j<duz(pom);j++)
				pom[j]=0;
			
		}
		
		
	}
	return tekst;	
}






int main() {
	//Kraci program za provjeravanje tacnosti zadatka. 
	char* rijeci[2] = { "beli", "sneg" };
	char* zamjene[2] = { "bijeli", "snijeg" };
	char tekst[1000] = "beli sneg je pokrio beli breg";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));

}
