#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Prodavnica{
	char naziv[100];
	int ID;
};

struct Artikal{
	char naziv[100];
	double cijena;
	int prodavnica;
};

int jeLiBroj(char c){
	if(c>='0' && c<='9')return 1;
	return 0;
}

int ucitaj_artikle(struct Artikal *niz,int kap){
	int ucitanih;
	FILE *binar=fopen("artikli.bin","rb");
	if(binar==NULL){
		return 0;
	}
	ucitanih=fread(niz,sizeof(struct Artikal),kap,binar);
	fclose(binar);
	return ucitanih;
}

int ucitaj_prodavnice(struct Prodavnica *niz,int kap){
	int counter=0,i=0,j,brojacCifri;
	char tmp[100],*p,*t;
	FILE *text=fopen("prodavnice.txt","r");
	if(text==NULL)return 0;
	while(i<kap){
		p=fgets(tmp,100,text);
		if(p==NULL)break;
		counter++;
		j=0;
		while(*p!=',' && *p!='\0'){
			niz[i].naziv[j]=*p;
			p++;
			j++;
		}
		niz[i].naziv[j]='\0';
		if(*p==',' || (*p=='\0' && jeLiBroj(*(p-1))));
		else {
			p=fgets(tmp,100,text);
			while(*p!=',')p++;
		}
		p++;
		t=p;
		brojacCifri=0;
		while(*t!='\0' && *t!='\n'){
			brojacCifri++;
			t++;
		}
		niz[i].ID=0;
		while(*p!='\0' && *p!='\n'){
			niz[i].ID+=(*p-'0')*pow(10,brojacCifri-1);
			brojacCifri--;
			p++;
		}
		i++;	
	}
	fclose(text);
	return counter;
}

int izbaci_skupe(struct Prodavnica *p,int np,struct Artikal *a,int na){
	int i,j,k,counter,t;
	double suma1=0,suma2=0;
	for(i=0;i<na;i++){
		suma1+=a[i].cijena;
	}
	suma1/=na;
	for(i=0;i<np;i++){
		suma2=0;
		counter=0;
		for(j=0;j<na;j++){
			if(p[i].ID==a[j].prodavnica){suma2+=a[j].cijena;counter++;}
		}
		if(suma1<suma2/counter){
			t=i;
			for(k=t+1;k<np;k++,t++)
				p[t]=p[k];
			np--;	
		}
	}
	return np;
}

int sacuvaj(struct Prodavnica *p,int n,const char *ime_datoteke){
	int ucitanih;
	FILE* dat=fopen(ime_datoteke,"ab");
	if(dat==NULL)return 0;
	ucitanih=fwrite(p,sizeof(struct Prodavnica),n,dat);
	if(ferror(dat))return 0;
	fclose(dat);
	return 1;
}

int main() {
struct Prodavnica p[] = {
	{"Konzum", 2}, //Konzum ima vece cijene!
	{"Amko", 1}, //jedino on ostaje
	{"Bingo", 3}, //i Bingo ima vece cijene zbog Graha (5KM)
};
struct Artikal n[] = {
	{"Brasno", 5.2, 1},
	{"Ulje", 2, 1},
	{"Secer", 1.5, 1},
	{"Brasno", 5.2, 2},
	{"Ulje", 2.1, 2},
	{"Secer", 2.2, 2},
	{"Brasno", 5.2, 3},
	{"Ulje", 1.1, 3},
	{"Secer", 1.2, 3},
	{"Grah", 5, 3}
};
int nova_vel = izbaci_skupe(p, 3, n, 10), i;
printf ("Ostalo je %d prodavnica, i to: \n", nova_vel);
for (i = 0; i < nova_vel; ++i)
	printf ("'%s', ID: %d\n", p[i].naziv, p[i].ID);
	return 0;
}
