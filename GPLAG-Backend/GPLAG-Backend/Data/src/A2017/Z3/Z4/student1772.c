#include <stdio.h>

int linear_search(int *pointer, int n, int find)
{
   int c;

   for (c = 0; c < n; c++) {
      if (*(pointer+c) == find)
         return c;
   }

   return -1;
}

int max(int matrica[100][100], int visina, int sirina){
	int i=0;
	int j=0;
	int k=0;
	int members[100]={0};
	int brojaci[100]={0};
	int index_membera=0;
	int index_najveceg_brojaca=0;
	int broj_membera=0;
	int max_brojac=0;
	int broj_najvecih_brojaca=0;
	int broj_za_ispisat=0;
	for (i=0;i<visina;i++){
		for (j=0;j<sirina;j++){
			index_membera=linear_search(members,broj_membera,matrica[i][j]);
			if (index_membera==-1) {
				members[k]=matrica[i][j];
				broj_membera++;
				brojaci[k]++;
				k++;
			} else {
				brojaci[index_membera]++;
			}
		}
	}
	/*printf ("Clanovi: ");
	for (i=0;i<broj_membera;i++){
		printf (" %d,",members[i]);
	}
	printf ("Brojaci: ");
	for (i=0;i<broj_membera;i++){
		printf ("%d,",brojaci[i]);
	}*/
	max_brojac=brojaci[0];
	for (i=0;i<broj_membera;i++){
		if (max_brojac<brojaci[i]) {
			index_najveceg_brojaca=i;
			max_brojac=brojaci[i];
		}
	}

	for (i=0;i<broj_membera;i++){
		if (max_brojac==brojaci[i]) broj_najvecih_brojaca++;
	}
	//printf ("broj najvecih brojaca=%d\n",broj_najvecih_brojaca);
	if (broj_najvecih_brojaca>1) {
		for (i=0;i<broj_membera;i++){
				if (brojaci[index_najveceg_brojaca]==brojaci[i] ){
                        if (members[index_najveceg_brojaca]>members[i]){
                                broj_za_ispisat=members[i];
                                //i=0;
                        }
                else broj_za_ispisat=members[index_najveceg_brojaca];
			}
		}
	}

	//printf ("Broj za ispisat %d",broj_za_ispisat);
	if (broj_najvecih_brojaca>1)  return broj_za_ispisat;
	else return members[index_najveceg_brojaca];
}

int izbaci_kolone(int matrica[100][100],int visina,int sirina,int n){
	int i=0;
	int j=0;
	int k=0;
	int a=0;
	int brojac=0;
	for (i=0;i<sirina;i++){
		for (j=0;j<visina;j++){
			if (matrica[j][i]==n){
				for(k=0;k<visina;k++){
					for (a=i;a<sirina;a++){
						matrica[k][a]=matrica[k][a+1];
					}
				}
				brojac++;
				if (i>0) i--;
				sirina--;
			}
		}
	}
	if (sirina==1){
		for (i=0;i<visina;i++) if (matrica[i][0]==n) return 0;
	}
	return sirina;
}

int main() {
	 int i=0;
    int j=0;
    int visina=0;
    int sirina=0;
    int matrica[100][100];
    int broj=1;
    printf ("Unesite sirinu i visinu matrice: ");
    scanf("%d %d",&sirina,&visina);
    for (i=0;i<visina;i++){
        printf ("Unesite elemente %d. reda: ",i+1);
        for (j=0;j<sirina;j++){
            scanf("%d",&matrica[i][j]);
        }
    }
    printf ("\n");
    while(sirina>0){
    	 
        sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));
        if (sirina==0) break;
        printf ("Nakon %d. prolaza matrica glasi: \n",broj);
        for (i=0;i<visina;i++){
            for (j=0;j<sirina;j++){
            	printf ("%5d",matrica[i][j]);
            }
            printf("\n");
        }
        broj++;
        printf("\n");
    }
    printf("Nakon %d. prolaza matrica je prazna!",broj);
	return 0;
}