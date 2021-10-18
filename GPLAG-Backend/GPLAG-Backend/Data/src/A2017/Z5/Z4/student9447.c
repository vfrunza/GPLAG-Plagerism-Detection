#include <stdio.h>
#include <stdlib.h>


struct Prodavnica{
	char naziv[100];
	int ID;
};

struct Artikal{
	char naziv[100];
	double cijena;
	int prodavnica;
};

int ucitaj_prodavnice(struct Prodavnica *niz, int kap){
	
	FILE *dat=fopen("prodavnice.txt","r");
	if(!dat) exit(1);
	
	int i,j;
	for(i=0; i<kap; i++){
		j=-1;
		
		do{
			if(j<99) {
				j++;
			}
			niz[i].naziv[j]=fgetc(dat);
		} while(niz[i].naziv[j]!=',' && niz[i].naziv[j]!=EOF);
		
		niz[i].naziv[j]='\0';
		if(fscanf(dat,"%d\n",&niz[i].ID)!=1) break;
	}
	fclose(dat);
	return i;
}

int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a, int na){
	
	float prosjecnaCijenaSvihArtikala=0, prosjecnaCijenaSvihProdavnica;
	float sumaSvihArtikala=0, sumaSvihProdavnica;
	
	int i=0, brojartikala=0;
	int brojartikalaprodavnice, j;
	
	for(i=0; i<na; i++){
		sumaSvihArtikala+=a[i].cijena;
		brojartikala++;
	}
	
	if(brojartikala>0) prosjecnaCijenaSvihArtikala=sumaSvihArtikala/brojartikala;
	
	for(i=0; i<np; i++){
		sumaSvihProdavnica=0;
		brojartikalaprodavnice=0;
		prosjecnaCijenaSvihProdavnica=0;
		
		for(j=0; j<na; j++){
			
			//uslov za prosjecnu cijenu isti ID
			if(p[i].ID==a[j].prodavnica){
				sumaSvihProdavnica+=a[j].cijena;
				brojartikalaprodavnice++;
			}
		}
		
		if(brojartikalaprodavnice>0){
			prosjecnaCijenaSvihProdavnica=sumaSvihProdavnica/brojartikalaprodavnice;
		}
		int k=0;
		if(prosjecnaCijenaSvihProdavnica>prosjecnaCijenaSvihArtikala){
			for(k=i; k<np-1; k++){
				p[k]=p[k+1];
			}
			np--;
			i--;
		}
	}
	
	return np;
	
}

int sacuvaj(struct Prodavnica *p, int n, const char *ime_datoteke){
	
	FILE* dat=fopen(ime_datoteke,"wb");
	if(dat==NULL) return 0;
	int i=0;
	for(i=0; i<n; ++i){
		fwrite(&p[i],sizeof(struct Prodavnica),1,dat);
		if(ferror(dat)) return 0;
	}
	fclose(dat);
	return 1;
}

int ucitaj_artikle(struct Artikal *niz, int kap){
	
	FILE *dat=fopen("artikli.bin", "rb");
	if(!dat) exit(1);
	int ucitano=fread(niz, sizeof(struct Artikal),kap,dat);
	fclose(dat);
	return ucitano; 
}



int main() {
	//at8
	
	struct Prodavnica p[]={{"Amko",1}, {"Bingo",2}, {"Konzum", 3}};
	struct Artikal a[]={{"Kiseli kupus", 10,4}, {"Bickl", 1000,5}, {"Krastavci",2,4}};
	
	int i=izbaci_skupe(p,3,a,3), j;
	
	for(j=0; j<i; j++){
		printf("%s, ID: %d\n", p[j].naziv, p[j].ID);
	}




	return 0;
}
