#include <stdio.h>
	
	struct Artikal {
		char naziv[100];
		double cijena;
		int prodavnica;
	};
	
	struct Prodavnica{
		char naziv[100];
		int ID;
	};
	
	int ucitaj_artikle(struct Artikal *niz,int kap){
		FILE *dat = fopen ("artikli.bin","rb");
		if(!dat) printf("Greska prilikom otvaranja datoteke.");
		int ucitano = fread (niz,sizeof(struct Artikal),kap,dat);
		if(ferror(dat)) printf("Greska prilikom citanja");
			fclose(dat);
		return ucitano;
	}
	
	int ucitaj_prodavnice(struct Prodavnica *niz, int kap){
		FILE *dat = fopen ("prodavnice.txt","r");
		if(dat==NULL) printf("Greska");
		char znak;
		int da=0;
		
		int j=0;
		
		
		while(j<kap){
			int i=-1;
			do{
				if(i<99) i++;
				niz[j].naziv[i]=fgetc(dat);
			}while(niz[j].naziv[i]!=',' && niz[j].naziv[i]!=EOF);
			niz[j].naziv[i]='\0';
			if(fscanf(dat,"%d\n",&niz[j].ID) != 1) break;
			j++;
		}
		return j;
	}
	
	int sacuvaj (struct Prodavnica *niz, int n, const char * ime_datoteke){
		
		FILE *dat = fopen (ime_datoteke,"w+b");
		if(!dat) printf("greska");
		
		int spr = fwrite(niz,sizeof(struct Prodavnica),n,dat);
		fclose(dat);
		if(spr==n) return 1;
			return 0;
	}
	
	int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a, int na){
		int i,j;
		int id_min;
		double min;
		int poredi=0;
		int index;
		double niz[5];
		for(i=0;i<5;i++){
			niz[i]=0;
		}
	
		for(i=0;i<np;i++){
		
			for(j=0;j<na;j++){
				if(p[i].ID==a[j].prodavnica){
					index=p[i].ID;
					niz[index]+=a[j].cijena;
					poredi=1;
				}
			}
		}
		if(poredi){
		min=niz[1]; id_min=1;
		for(i=2;i<5;i++){
			if(niz[i]<min && niz[i]!=0) { min=niz[i]; id_min=i; }
		}
		
		for(i=0;i<np;i++){
			if(p[i].ID!=id_min){
				for(j=i;j<np-1;j++){
					p[j]=p[j+1];
				}
				np--;
				i--;
			}
		}
		}
		
		return np;
		
	}

int main() {
struct Artikal a[50];
int n = ucitaj_artikle(a, 50), i;
for (i = 0; i < n; ++i)
	printf ("%s (cijena: %g, prodavnica: %d)\n", a[i].naziv, a[i].cijena, a[i].prodavnica);	
	return 0;
}
