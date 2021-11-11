#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define vel 100
void unesi(char niz[], int velicina){
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
void swap(char*p, char*q){
	char temp[vel];
	strcpy(temp,p);
	strcpy(p,q);
	strcpy(q,temp);
}
int slovo(int a){
	if(a>='A' && a<='Z' || a<='z' && a>='a')
	return 1;
	
	return 0;
}
void kompresuj(char* naziv, char*naziv1){
	char rijeci[1000][1000]={0};
	int duzina;
	char znak;
	int i, broj_rijeci=0;
	int brojac[1000]={0};
	FILE* ulaz;
	FILE* ulaz1;
	FILE* izlaz;
	char rijec[1000];
	ulaz=fopen(naziv,"r");
	if(ulaz==NULL){
		printf("Greska\n");
		exit(1);
	}
	ulaz1=fopen(naziv, "r");
	if(ulaz1==NULL){
		printf("Greska\n");
		fclose(ulaz);
		exit(1);
	}
	izlaz=fopen(naziv1,"w");
	if(izlaz==NULL){
		printf("Greska\n");
		fclose(ulaz);
		fclose(ulaz1);
		exit(1);
	}
	znak=fgetc(ulaz);
	while(znak!=EOF){
		duzina=0;
		while(slovo(znak)==1){
			rijec[duzina]=znak;
				znak=fgetc(ulaz);
				duzina++;
		}
		
		rijec[duzina] = '\0';
		
		if(duzina!=0 && duzina<=9){
			int j, ima;
			ima=0;
			
			for(j=0; j<broj_rijeci; j++){
				if(strcmp(rijeci[j], rijec)==0){
					ima=1;
					brojac[j]++;
					
					break;
				}
			}
			
			if(ima!=1){
				strcpy(rijeci[broj_rijeci], rijec);
				
				brojac[broj_rijeci++] = 1;
			}
		}
		
		znak=fgetc(ulaz);
		
		
	}
	
	int k;
	
	for(i=0; i<broj_rijeci; i++){
		for(k=i+1; k<broj_rijeci; k++){
			if((strcmp(rijeci[i], rijeci[k])==1 && brojac[k]==brojac[i]) || brojac[i]<brojac[k]){
				int temp;
				temp=brojac[k];
				brojac[k]=brojac[i];
				brojac[i]=temp;
				swap(rijeci[i], rijeci[k]);
			}
		}
	}
	
	char novi_red; int kraj;
	kraj=10;
	novi_red='\n';
	
	if(broj_rijeci<10) kraj=broj_rijeci;
	for(i=0; i<kraj; i++){
		fputs(rijeci[i],izlaz);
		fputc(novi_red, izlaz);
	}
	
	char c;
	c=fgetc(ulaz1);
	
	while(c!=EOF){
		duzina=0;
		while(slovo(c)==1){
			rijec[duzina]=c;
			duzina++;
			c=fgetc(ulaz1);
		}
		rijec[duzina] = '\0';
		
		int kont;
		kont=0;
		int j;
		if(duzina!=0 && duzina<10){
			for(j=0;j<kraj;j++){
				if(strcmp(rijeci[j], rijec)==0){
					char z;
					kont=1;
					z=j+20;
					fputc(z,izlaz);
					fputc(c, izlaz);
					break;
					
				}
			}
		}
		
		
		if(kont==0){
			char*r=rijec;
			
			while(*r !='\0'){
				fputc(*r,izlaz);
				r++;
			}
			fputc(c,izlaz);
		}
		
		c=fgetc(ulaz1);
	}
	
	
	printf("Datoteka kompresovana.\n");
	
	fclose(izlaz);
	fclose(ulaz);
	fclose(ulaz1);
}

void dekompresuj(char*naziv, char* naziv1){
	int broj_rijeci=0, brojac_krajeva=0, kontr=0;
	int duzina =0;
	char rijeci[1000][1000]={0};
	char rijec[1000];
	FILE* ulaz;
	FILE* ulaz1;
	FILE* izlaz;
	
	ulaz=fopen(naziv,"r");
	
	
	ulaz1=fopen(naziv, "r"); 

	
	izlaz=fopen(naziv1, "w");

	int n=0;
	char znak;
	znak=fgetc(ulaz);
	int j;
	
	while(znak!=EOF){
		duzina=0;
		kontr=0;
		while(slovo(znak)==1){
			rijec[duzina++]=znak;
			znak=fgetc(ulaz);
		}
		
		rijec[duzina] = '\0';
		
		if(duzina!=0 && duzina<=9){
			strcpy(rijeci[broj_rijeci], rijec);
		for(j=0; j<broj_rijeci; j++){
			if(strcmp(rijeci[j], rijec)==0){
				kontr=1;
				
				break;
			}
		}
		
		if(kontr==1) break;
		
		broj_rijeci++;
		}
		
		znak=fgetc(ulaz);
	}
	brojac_krajeva=0;
	char c=fgetc(ulaz1);
	
	while(c!=EOF){
	
		if(c=='\n') 
		brojac_krajeva++;
		if(broj_rijeci==brojac_krajeva) break;
		c=fgetc(ulaz1);
	}
	
	c=fgetc(ulaz1);
	
	while(c!=EOF){
		n=0;
		if(c<31 && c>19){
			n=1;
			char*p=rijeci[c-20];
			
			
			while(*p != '\0'){
				fputc(*p, izlaz);
				p++;
			}
		}
		
		if(n==0)
		fputc(c,izlaz);
		
		c=fgetc(ulaz1);
	}
	
	printf("Datoteka dekompresovana.\n");
	
	fclose(ulaz);
	fclose(ulaz1);
	fclose(izlaz);
	
}


int main() {
	char p[vel];
	char s[vel];
	int opcija;
	
	do{
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &opcija);
		
		switch(opcija){
			case 1:
			printf("Unesite ime ulazne datoteke: ");
			unesi(s,40);
			printf("Unesite ime izlazne datoteke: ");
			unesi(p,40);
			kompresuj(s,p);
			break;
			case 2:
			printf("Unesite ime ulazne datoteke: ");
			unesi(s,40);
			printf("Unesite ime izlazne datoteke: ");
			unesi(p,40);
			dekompresuj(s,p);
			
		} 
	} while(opcija!=0);
	
	return 0;
}
