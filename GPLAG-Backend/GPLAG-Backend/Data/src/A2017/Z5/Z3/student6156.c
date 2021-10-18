#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Oblik
{
	char naziv[20];
	int br_stranica;
	double stranice[300];
};
void myb_empty(void);
double obim(int n,double* niz);
void dodaj_oblik(struct Oblik o);
void izbaci_duple(void);
struct Oblik daj_najveci(void);

int main()
{

	return 0;
}

void dodaj_oblik(struct Oblik o)
{
	/* oblici.dat - > treba dodati na kraj datoteke */
	myb_empty();
	FILE* registar;
	registar=fopen("oblici.dat","ab");

	if(registar==NULL)
	{
		printf("\nGreska pri otvaranju datoteke!");
		exit(1);
	}

	int i=0;
	char ime[20]="";
	char* p=o.naziv;
	char x;
	float sides[300];
	while(i<20)
	{
		ime[i]=*p;
		p++;
		i++;
	}
	for(i=0;i<o.br_stranica;i++)
	{
		sides[i]=o.stranice[i];
	}
	/* dodajem ime*/
	fwrite(ime,sizeof(char),20,registar);
	if(ferror(registar))exit(1);
	i=o.br_stranica;
	x=i;
	/* dodajem broj stranica */
	fwrite(&x,sizeof(char),1,registar);
	if(ferror(registar))exit(1);
	/* dodajem duzine stranica */
	fwrite(sides,sizeof(float),x,registar);
	if(ferror(registar))exit(1);
	
	if(ferror(registar))
	{
		printf("Greska prilikom pisanja datoteke!\n");
		printf("Nije zapisan oblik!\n");
	}
	fclose(registar);
	/* treba povecati prvi broj, prvo ga ucitam */
	unsigned short a=0;

	registar=fopen("oblici.dat","rb");
	if(registar==NULL)
	{
		printf("\nGreska pri otvaranju datoteke!");
		exit(1);
	}
	fread(&a,sizeof(unsigned short),1,registar);
	fclose(registar);
	/* povecam ga i upisem u datoteku */
	a++;
	registar=fopen("oblici.dat","rb+");
	if(registar==NULL)
	{
		printf("\nGreska pri otvaranju datoteke!");
		exit(1);
	}
	fwrite(&a,sizeof(unsigned short),1,registar);
	if(ferror(registar))exit(1);
	fclose(registar);
}

void izbaci_duple(void)
{
	float sides[300];
	int i,j,k;
	unsigned short a=0;
 //   struct Oblik niz[300];
    char x;
	FILE* registar;
	for(i=0;i<100;i++)
	{
		sides[i]=sides[i+100]=sides[i+200]=0;
	}
	registar=fopen("oblici.dat","rb");
	if(registar==NULL)
	{
		printf("\nGreska pri otvaranju datoteke!");
		exit(1);
	}

	/* ucitam broj oblika*/

	fread(&a,sizeof(unsigned short),1,registar);


	/* napravim sebi niz struktura */
	struct Oblik* niz=(struct Oblik*)malloc(sizeof(struct Oblik)*a);

	for(i=0; i<a; i++)
	{
		fread(niz[i].naziv,sizeof(char),20,registar);

		fread(&x,sizeof(char),1,registar);
		(niz[i].br_stranica)=x;
		fread(sides,sizeof(float),x,registar);
		
		for(j=0;j<x;j++)
		{
			niz[i].stranice[j]=sides[j];
		}
		
	}
	
	fclose(registar);
	

	
	// nalazenje i izbacivanje dulpih
ponovi:
	for(i=0; i<a-1; i++)
	{
		for(j=i+1; j<a; j++)
		{
			if(strcmp(niz[i].naziv,niz[j].naziv)==0)
			{
				for(k=j; k<a-1; k++)
				{
					niz[k]=niz[k+1];
				}
				a--;

				goto ponovi;			
				break;
			}
		}
	}   
	//po svemu sudeci dobro proslo

	registar=fopen("oblici.dat","wb");
	if(registar==NULL)
	{
		printf("\nGreska pri otvaranju datoteke oblici.dat!");
		exit(1);
	}
//slijedi upisivanje u datoteku iz strukture
	fwrite(&a,sizeof(unsigned short),1,registar);
	if(ferror(registar))exit(1);

	for(i=0; i<a; i++)
	{
		fwrite(niz[i].naziv,sizeof(char),20,registar);
		if(ferror(registar))exit(1);
		
		fwrite(&(niz[i].br_stranica),sizeof(char),1,registar);
		if(ferror(registar))exit(1);
		
		for(j=0;j<niz[i].br_stranica;j++)
		{
			sides[j]=niz[i].stranice[j];
		}
		fwrite(sides,sizeof(float),niz[i].br_stranica,registar);
		if(ferror(registar))exit(1);
		
	}
	
	fclose(registar);
	free(niz);
}

struct Oblik daj_najveci()
{
	unsigned short a=0;
	int i,j;
	char x;
	struct Oblik max;
//	struct Oblik niz[300];
	float sides[300];

	FILE* registar;
	registar=fopen("oblici.dat","rb");
	if(registar==NULL)
	{
		printf("\nGreska pri otvaranju datoteke oblici.dat!");
		exit(1);
	}

	fread(&a,sizeof(unsigned short),1,registar);

	struct Oblik* niz=(struct Oblik*)malloc(sizeof(struct Oblik)*a);
	for(i=0; i<a; i++)
	{
		fread(niz[i].naziv,sizeof(char),20,registar);
		fread(&x,sizeof(char),1,registar);
		niz[i].br_stranica=x;
		fread(sides,sizeof(float),x,registar);
		for(j=0;j<x;j++)
		{
			niz[i].stranice[j]=sides[j];
		}
	}
	fclose(registar);

	//potraznja za najvecim obimom

	
	max=niz[0];
	for(i=1; i<a; i++)
	{
		if(obim(niz[i].br_stranica,niz[i].stranice)>obim(max.br_stranica,max.stranice))max=niz[i];
	}
    free(niz);
	return max;
}

double obim(int n,double* niz)
{
	int i;
	double rez=0;
	for(i=0; i<n; i++)
	{
		rez+=niz[i];
	}
	return rez;
}

void myb_empty(void)
{
	//mozda nekad dodje prazna
	unsigned short a=0;
	FILE* registar;
	registar=fopen("oblici.dat","rb");
	if(registar==NULL)
	{
		exit(1);
	}
	if(fread(&a,sizeof(unsigned short),1,registar)==0)
	{
		a=0;
		fclose(registar);
		registar=fopen("oblici.dat","wb");
		if(registar==NULL)
		{
			exit(1);
		}
		fwrite(&a,sizeof(unsigned short),1,registar);
		if(ferror(registar))exit(1);
		fclose(registar);
		return ;
	}
	
	
	fclose(registar);
	
}