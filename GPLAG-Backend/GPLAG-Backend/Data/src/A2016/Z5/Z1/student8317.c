#include <stdio.h>
#include<math.h>


struct Student 
{
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int uporedi(char* s1,char* s2)
{
	while(*s1!='\0' && *s2!='\0')
	{
		if(*s1<*s2) return -1;
		if(*s1>*s2) return 1;
		s1++;
		s2++;
	}
	return 0;
}

int genijalci(struct Student niz[],int velicina,float k)
{
	int i;
	float prosjek;
	for(i=0;i<velicina;i++)
	{
		prosjek=0;
		int j=0,suma=0,petica=0;
		for(j=0;j<niz[i].br_ocjena;j++)
		{
			if(niz[i].ocjene[j]==5)
			{
				petica==1;
			}
			suma=suma+niz[i].ocjene[j];
		}
		if(petica==1)
		{
			prosjek==5.0;
		}
		else if(niz[i].br_ocjena==0)
		{
			prosjek==5.0;
		}
		else
		{
			prosjek=suma/(float)niz[i].br_ocjena;
		}
		
		if(prosjek<k)
		{
			for(j=i;j<velicina-1;j++)
			{
				niz[j]=niz[j+1];
				
			}
			(velicina)--;
			i--;
		}
	}
	
	
	float maxprosjek=0;
	float nizprosjek[50] ;
	for(i=0;i<velicina;i++)
	{
		int j=0,suma=0,petica=0;
		prosjek=0;
	
		for(j=0;j<niz[i].br_ocjena;j++)
		{
			if(niz[i].ocjene[j]==5)
			{
				petica=1;
			}
			
			if(petica==5)
			{
				prosjek==5.0;
			}
			suma=suma+niz[i].ocjene[j];
		}
		
		if(petica==1)
		{
			prosjek==5.0;
		}
		else
		{
			prosjek=suma/(float)niz[i].br_ocjena;
		}
		
		nizprosjek[i]=prosjek;
	}
	
	
	int prvi=-1,drugi=-1,treci=-1;
	int brojac=0,m=0,mduplih=0;
	int dupli=0;
	i=0;
	while(brojac<3 && brojac<(velicina))
	{
		for(i=0;i<velicina;i++)
		{
			if(nizprosjek[i]>maxprosjek)
			{
				maxprosjek=nizprosjek[i];
				m=i;
			}
		}
		brojac++;
		if(brojac==1)
		prvi=m;
		else if(brojac==2)
		drugi=m;
		else if(brojac==3)
		treci=m;
		
		nizprosjek[m]==-1.0;
		for(i=0;i<velicina;i++)
		{
			if(fabs(nizprosjek[i]-maxprosjek)<0.00001)
			{
				dupli=1;
				mduplih=i;
			}
		}
		
		if(dupli==1)
		{
			if(uporedi(niz[m].prezime,niz[mduplih].prezime)==-1)
			{
				if(brojac==1)
				prvi=m;
				else if(brojac==2)
				drugi=m;
				else if(brojac==3)
				treci=m;
				brojac++;
				if(brojac==1)
				prvi=mduplih;
				else if(brojac==2)
				drugi=mduplih;
				else if(brojac==3)
				treci=mduplih;
				
			}
			
		else	if(uporedi(niz[m].prezime,niz[mduplih].prezime)==-1)
			{
				if(brojac==1)
				prvi=mduplih;
				else if(brojac==2)
				drugi=mduplih;
				else if(brojac==3)
				treci=mduplih;
				brojac++;
				if(brojac==1)
				prvi=m;
				else if(brojac==2)
				drugi=m;
				else if(brojac==3)
				treci=m;
				
			}
			
				else if(uporedi(niz[m].ime,niz[mduplih].ime)<=0)
			{
				if(brojac==1)
				prvi=m;
				else if(brojac==2)
				drugi=m;
				else if(brojac==3)
				treci=m;
				brojac++;
				if(brojac==1)
				prvi=mduplih;
				else if(brojac==2)
				drugi=mduplih;
				else if(brojac==3)
				treci=mduplih;
				
			}
			
				else
			{
				if(brojac==1)
				prvi=mduplih;
				else if(brojac==2)
				drugi=mduplih;
				else if(brojac==3)
				treci=mduplih;
				brojac++;
				if(brojac==1)
				prvi=m;
				else if(brojac==2)
				drugi=m;
				else if(brojac==3)
				treci=m;
				
			} nizprosjek[mduplih]=-1.0;
			dupli=0;
		}
		maxprosjek=0;
	}
	
	if(prvi!=-1)
	printf("%s %s\n",niz[prvi].prezime,niz[prvi].ime);
	if(drugi!=-1)
	printf("%s %s\n",niz[drugi].prezime,niz[drugi].ime);
	if(treci!=-1)
	printf("%s %s\n",niz[treci].prezime,niz[treci].ime);
	
	return velicina;
}



int main() {
struct Student niz[5]={{"Saric","Sara",{6,7,8,7},4}, {"Mujic","Mujo",{10,9,8,6},4},{"Hanic","Hana",{6,6,6},3},{"Ime","Prezime",{10,9,10,10,9},5},{"Dupli","Dupli",{10,9,10,10,9},5}};
int velicina=5;
genijalci(niz,velicina,8.00);
return 0;
}
