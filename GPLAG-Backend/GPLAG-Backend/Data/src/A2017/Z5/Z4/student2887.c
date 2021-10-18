#include <stdio.h>

struct Prodavnica{
	char naziv[100];
	int ID;
};
struct Artikal{
	char naziv[100];
	double cijena;
	int prodavnica;
};
int ucitaj_artikle(struct Artikal* niz,int kap){
	int ucitano;
	FILE* dat=fopen("artikli.bin","rb");
	if(dat==NULL){
		printf("Greska pri otvaranju datoteke.\n");
		return 0;
	}
	//ucitaj podatke iz binarne datoteke
	ucitano=fread(niz,sizeof(struct Artikal),kap,dat);
	fclose(dat);
	return ucitano;
}

int ucitaj_prodavnice(struct Prodavnica* niz,int kap){
	int i=0;
	FILE* dat1=fopen("prodavnice.txt","r");
	if(dat1==NULL){
		printf("Greska pri otvaranju datoteke.\n");
		return 0;
	}
	while(i<kap && fscanf(dat1,"%s,%d\n",niz[i].naziv,&niz[i].ID)==2){
		i++;
	if(fscanf(dat1,"%s,%d\n",niz[i].naziv,&niz[i].ID)==0)break;
	}
	fclose(dat1);
	return i;
}
int izbaci_skupe(struct Prodavnica* p,int np,struct Artikal* a,int na){
	int i,j,k,pr_cijena,pr_cijena1,zbir,zbir1,brojac;
	//u slucaju da je niz p ili niz a prazan prekini program
	if(np==0 || na==0){
		return 0;
	}
	for(i=0;i<np;i++){
		zbir=0;
		zbir1=0;
		pr_cijena1=0;
		pr_cijena=0;
		brojac=0;
		for(j=0;j<na;j++){
			//ukoliko artikal odgovara posmatranoj prodavnici uzmi cijenu artikla 
			if(p[i].ID==a[j].prodavnica){
				zbir+=a[j].cijena;
				brojac+=1;
			}
			zbir1+=a[j].cijena;
		}if(brojac==0){
			pr_cijena=0;
		}else{
		pr_cijena=zbir/brojac;
		}
		pr_cijena1=zbir1/na;
		if(pr_cijena>pr_cijena1){
			for(k=i;k<np-1;k++){
				p[k]=p[k+1];
			}
			i--;
			np--;
		}
	}
	return np;
}
int sacuvaj(struct Prodavnica* p,int n,const char* ime_datoteke){
	FILE* dat2=fopen(ime_datoteke,"wb");
	if(dat2==NULL){
	  printf("Greska pri otvaranju datoteke");
	  return 0;
	}
	//upisi podatke u datoteku 
	fwrite(p,sizeof(struct Prodavnica),n,dat2);
	if(ferror(dat2)){
		printf("Greska prilikom pisanja datoteke");
		return 0;
	}
	fclose(dat2);
	return 1;
}
int main() {
	struct Prodavnica p[10];
	int n=ucitaj_prodavnice(p,10),i;
	for(i=0;i<n;i++){
		printf("'%s', id: %d\n",p[i].naziv,p[i].ID);
	}
	return 0;
}
