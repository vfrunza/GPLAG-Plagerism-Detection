#include <stdio.h>
#include <math.h>
int main()

{  int niza[100]={0}, nizb[100]={0}, nizc[100]={0} ;
    int red,kolona;
		do {
			 printf ("Unesite brojeve M i N: ");
			 scanf("%d %d", &red, &kolona);
	       }while (red<0 || kolona<0 || red>100 || kolona>100);


int i,j,z,k,l,m;
	    printf ("Unesite clanove matrice A: ");

                 for (i=0; i<red*kolona; i++)
                 scanf ("%d", &niza[i]); 
        printf ("Unesite clanove matrice B: ");
                 for (i=0; i<red*kolona; i++)
                 scanf ("%d", &nizb[i]); 
	    printf ("Unesite clanove matrice C: ");
                 for (i=0; i<red*kolona; i++)
                    scanf ("%d", &nizc[i]); 

int memorija,najmanji;
int brojaci[100]={0};
        for (i=0; i<red*kolona; i++) 
        {
           najmanji=i;
        for (j=i+1; j<red*kolona; j++){
            if (niza[j] < niza[najmanji])
            najmanji = j;
            }
        memorija = niza[i];
        //memorija = niza[j];
        niza[i] = niza[najmanji];
        niza[najmanji] = memorija;
         }
for (i = 0; i<red*kolona;i++){
    for(j=0;j<red*kolona;j++){
        if(brojaci[i] == niza[j]){
            
            //brojaci[i];
            
            
            brojaci[i]++;
        }
    }
}
int najmanjii,meemorija,brojacii[100]={0};

      for (i=0; i<red*kolona; i++) {
           najmanjii=i;
        for (j=i+1; j<red*kolona; j++)
        {
            if (nizb[j] < nizb[najmanjii])
            najmanjii = j;
            }
        meemorija = nizb[i];
        nizb[i] = nizb[najmanjii];
        nizb[najmanjii] = meemorija;
         }

for (i = 0; i<red*kolona;i++){
    for(j=0;j<red*kolona;j++){
        if(brojaci[i] == nizb[j]){
            brojacii[i]++;
        }
    }
}
int najmanjiii,meeemorija,brojaciii[100]={0};
       for (i=0; i<red*kolona; i++) {
           najmanjiii=i;
        for (j=i+1; j<red*kolona; j++)
        {
            if (nizc[j] < nizc[najmanjiii])
            najmanjiii = j;
            }
        meeemorija = nizc[i];
        nizc[i] = nizc[najmanjiii];
        nizc[najmanjiii] = meeemorija;
         }

for (i = 0; i<red*kolona;i++){
    for(j=0;j<red*kolona;j++){
        if(brojaciii[i] == nizc[j]){
            brojaciii[i]++;
        }
    }
}


    if (red==0 && kolona==0) printf ("DA\n");
    else if (red!=0 && kolona!=0){
int da;
   { for (i=0; i<red*kolona; i++)

       {
           if (niza[i]==nizb[i] && niza[i]==nizc[i] ) da=1;
           else {da=0; break;}
       }
    if (da==1) printf ("DA\n");
     else if (da==0 )printf ("NE\n");
   }
    }
    return 0;
}
