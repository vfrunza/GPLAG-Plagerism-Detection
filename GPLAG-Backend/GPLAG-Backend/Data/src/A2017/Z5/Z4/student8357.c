#include<stdio.h>
#include<stdlib.h>
struct Prodavnica {
	char naziv[100];
	int ID;
};
struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;
};
int ucitaj_artikle(struct Artikal* niz, int kap) {
	int br_ucitanih;
	FILE* dat=fopen("artikli.bin","rb");
	if(dat==NULL) {
		printf("Greska pri otvaranju datoteke!\n");
		return 0;
	}
	br_ucitanih= fread(niz,sizeof(struct Artikal),kap,dat);
	fclose(dat);
	return br_ucitanih;
}
int ucitaj_prodavnice(struct Prodavnica *niz, int kap) {
	int i=0,vel,znak,j,id;
	FILE*ulaz=fopen("prodavnice.txt","r");
	if(ulaz==NULL) {
		printf("Greska pri otvaranju datoteke!\n");
		return 0;
	}
	for(;;) {
		j=0;
		znak=fgetc(ulaz);
		if(znak=='\n') znak=fgetc(ulaz);
		while(znak!=',' && znak!=EOF) {
			niz[i].naziv[j]=znak;
			j++;
			if(j==99) break;
			znak=fgetc(ulaz);
		}
		if(znak==EOF) break;
		if(znak!=',') {
			while (znak!=',' && znak!=EOF) znak=fgetc(ulaz);
		}
		if(znak==',') niz[i].naziv[j]='\0';
		znak=fgetc(ulaz);
		id=0;
		if(znak>='0' && znak<='9') {
			while(znak>='0' && znak<='9' && znak!=EOF){
			   id=id*10+(znak-'0');
			   znak=fgetc(ulaz);
			}
		}
		niz[i].ID=id;
		i++;
		if(i==kap) break;
		if(znak==EOF) break;
		
	} 
	fclose(ulaz);
	vel=i;
	return vel;
}
int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a, int na) {
	double svi_artikli_c=0,suma_artik_p=0,projecna_u,prosjecna_p;
	int i,j,k,broj_artik=0;
	for(i=0;i<na;i++) {
		svi_artikli_c+=a[i].cijena;
	}
	projecna_u=svi_artikli_c/na;
	for(i=0;i<np;i++) {
		suma_artik_p=0;
		broj_artik=0;
		for(j=0;j<na;j++) {
			if(a[j].prodavnica==p[i].ID) {
				suma_artik_p+=a[j].cijena;
				broj_artik++;
			}
		}
		prosjecna_p=suma_artik_p/broj_artik;
		if(prosjecna_p>projecna_u) {
			for(k=i;k<np-1;k++) p[k]=p[k+1];
			np--;
			i--;
		}
	}
	return np;
}
int sacuvaj(struct Prodavnica *p, int n, const char *ime_datoteke) {
	int upisano;
	FILE* upisi=fopen(ime_datoteke,"wb");
	if(upisi==NULL) {
		return 0;
	}
	upisano=fwrite(p,sizeof(struct Prodavnica),n,upisi);
	fclose(upisi);
	if(upisano!=n) return 0;
	return 1;
	
}
int main() {
	int pr,i;
	struct Prodavnica prod[4];
	FILE *ulaz=fopen("prodavnice.txt","w");
	if(ulaz==NULL) {
		printf("Greska pri otvaranju datoteke!\n");
		return 1;
	}
	fprintf(ulaz,"Zara,1\nOrsay,2\nTom Tailor,3\nAzel France,4\nBerska,5\nStradivarius,6");
	fclose(ulaz);
	pr=ucitaj_prodavnice(prod,4);
	for(i=0;i<pr;i++) {
		printf("%s, ID: %d\n",prod[i].naziv,prod[i].ID);
	}
	return 0;
}