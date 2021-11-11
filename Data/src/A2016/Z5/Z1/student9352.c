#include <stdio.h>
#include <string.h>

struct Student{
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student* pok, int velNiza, float prosjek)
{
	int novaVelNiza=velNiza,i=0,j=0,k=0, ocjenaNije5=6;
	float privProsjek=0, zbirOcjena=0;
	int ret=0;  //za strcmp
	float prviProsjek=5.,drugiProsjek=5.,treciProsjek=5.;
	int prviIndeks=0, drugiIndeks=0, treciIndeks=0;
	for(i=0;i<novaVelNiza;i++)
	{
		zbirOcjena=0.;
		privProsjek=0.;
		if(pok[i].br_ocjena==0)  privProsjek=5.;
		else 
		{
			for(j=0;j<pok[i].br_ocjena && (ocjenaNije5=pok[i].ocjene[j])!=5;j++)
				zbirOcjena+=pok[i].ocjene[j];
			if(j==pok[i].br_ocjena)
				privProsjek=zbirOcjena/pok[i].br_ocjena;
			else
				privProsjek=5.;
		}
		j=0;
		if(privProsjek<prosjek)  //poredimo sve elemente
		{
			novaVelNiza--;
			for(j=i;j<novaVelNiza;j++)
			{
				strcpy(pok[j].ime,pok[j+1].ime);
				strcpy(pok[j].prezime,pok[j+1].prezime);
				for(k=0;k<pok[j+1].br_ocjena;k++)
					pok[j].ocjene[k]=pok[j+1].ocjene[k];
				pok[j].br_ocjena=pok[j+1].br_ocjena;
			}
			i--;
		}
		else
		{
			if(privProsjek>prviProsjek)
			{
				treciProsjek=drugiProsjek;
				treciIndeks=drugiIndeks;
				drugiProsjek=prviProsjek;
				drugiIndeks=prviIndeks;
				prviProsjek=privProsjek;
				prviIndeks=i;
			}
			//ako je prosjek isti kao kod prijasnjeg
			else if(privProsjek==prviProsjek)
			{
				treciProsjek=drugiProsjek;
				treciIndeks=drugiIndeks;
				/* prvi student je onaj koji je prvi po leksikografskom poretku */
				ret=strcmp(pok[prviIndeks].prezime,pok[i].prezime);
				if(ret<0)  //ako je leksikografski prviIndeks abecedno prije
				{
					drugiIndeks=i;
					drugiProsjek=privProsjek;
					//prvi indeks ostaje prvi indeks
				}
				else if(ret>0)
				{
					drugiIndeks=prviIndeks;
					prviIndeks=i;
					drugiProsjek=prviProsjek;
					prviProsjek=privProsjek;
				}
				else //poredimo imena studenata
				{
					ret=strcmp(pok[prviIndeks].ime,pok[i].ime);
					if(ret<0)  //ako je leksikografski prvi indeks abecedno prije
					{
						drugiIndeks=i;
						drugiProsjek=privProsjek;
						//prviIndeks se ne mijenja
					}
					else
					{
						drugiIndeks=prviIndeks;
						prviIndeks=i;
						drugiProsjek=prviProsjek;
						prviProsjek=privProsjek;
					}
				}
			}
			else if(privProsjek<prviProsjek && privProsjek>drugiProsjek)
			{
				treciProsjek=drugiProsjek;
				treciIndeks=drugiIndeks;
				drugiProsjek=privProsjek;
				drugiIndeks=i;
			}
			else if(privProsjek==drugiProsjek)
			{
				//prvi student je onaj koji je ispred po leksikografskom poretku
				ret=strcmp(pok[drugiIndeks].prezime,pok[i].prezime);
				if(ret<0)
				{
					treciIndeks=i;
					treciProsjek=privProsjek;
				}
				else if(ret>0)
				{
					treciIndeks=drugiIndeks;
					drugiIndeks=i;
					treciProsjek=drugiProsjek;
					drugiProsjek=privProsjek;
				}
				else
				{
					ret=strcmp(pok[drugiIndeks].ime,pok[i].ime);
					if(ret<0)
					{
						treciIndeks=i;
						treciProsjek=privProsjek;
					}
					else
					{
						treciIndeks=drugiIndeks;
						drugiIndeks=i;
						treciProsjek=drugiProsjek;
						drugiProsjek=privProsjek;
					}
				}
			
			}
			else if(privProsjek<drugiProsjek && privProsjek>treciProsjek)
			{
				treciProsjek=privProsjek;
				treciIndeks=i;
			}
			
			else  //ako su prviProsjek i treciProsjek jednaki
			{
				//pednost ima onaj student koji je ispred po leksikografskom poretku
				ret=strcmp(pok[treciIndeks].prezime,pok[i].prezime);
				if(ret>0) //znaci da je abecedno treciIndeks manji
				{
					treciIndeks=i;
					treciProsjek=privProsjek;
				}
				else if(ret==0)  //poredimo imena studenata
				{
					ret=strcmp(pok[treciIndeks].ime,pok[i].ime);
					if(ret>=0)
					{
						treciIndeks=i;
						treciProsjek=privProsjek;
					}
				}
			}
		}
	}
	if(novaVelNiza>=1)  printf("%s %s\n",pok[prviIndeks].prezime,pok[prviIndeks].ime);
	if(novaVelNiza>=2) 	printf("%s %s\n",pok[drugiIndeks].prezime,pok[drugiIndeks].ime);
	if(novaVelNiza>=3) 	printf("%s %s\n",pok[treciIndeks].prezime,pok[treciIndeks].ime);
		
		return novaVelNiza;
	
}


int main() 
{
	return 0;
}