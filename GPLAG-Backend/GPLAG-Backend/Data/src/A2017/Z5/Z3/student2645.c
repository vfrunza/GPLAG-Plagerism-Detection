#include <stdio.h>
	
	struct Oblik {
		char naziv[20];
		int broj_stranica;
		double stranice[300];
	};
	
	struct Oblik daj_najveci(){ /*Najveci oblik*/
		FILE *dat = fopen("oblici.dat","rb");
		if(!dat) printf("Greska");
		int N=0;
		int x=0;
		struct Oblik o[50];
		char znak;
		znak=fgetc(dat);
		N=(int)znak;
		N*=10;
		int p;
		znak=fgetc(dat);
		N+=(int) znak;
		printf("%d",N);
		char pom[5];
		int i;
		for(i=0;i<N;i++){
			int ucitano = fread (o,sizeof(struct Oblik),N,dat);
			printf("%d",ucitano);
		}	
		fclose(dat);
		return o[0];
		
	}
int main() {
	struct Oblik *o;
	o=daj_najveci();
	return 0;
}
