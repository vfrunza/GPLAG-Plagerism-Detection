#include <stdio.h>
#define vel 100

int imaLiElemenatUNizu(int niz[], int br_el, int broj){
	int i;
	for(i=0; i<br_el; i++)
	{
		if(niz[i]==broj)
		return 1;
	} return 0;
}


int dva_od_tri(int prviNiz[], int br1, int drugiNiz[], int br2, int treciNiz[],int br3) {
   
	int i;
   int	broj_koji_se_ponavlja=0;
   int pomocni_niz[100];
   
	for(i=0; i<br1; i++) {
	    
		if(imaLiElemenatUNizu(drugiNiz,br2,prviNiz[i])==1)
		{
			if(imaLiElemenatUNizu(treciNiz,br3,prviNiz[i])==0)
		{
		    pomocni_niz[broj_koji_se_ponavlja]=prviNiz[i];
		broj_koji_se_ponavlja++;
	}
}
    else if(imaLiElemenatUNizu(treciNiz,br3,prviNiz[i])==1)
       {
           pomocni_niz[broj_koji_se_ponavlja]=prviNiz[i];
          broj_koji_se_ponavlja++;
}
	}
	
for(i=0; i<br2; i++)
{
    if(imaLiElemenatUNizu(treciNiz,br3,drugiNiz[i])==1 && imaLiElemenatUNizu(prviNiz, br1, drugiNiz[i])==0)
     {
    pomocni_niz[broj_koji_se_ponavlja]=drugiNiz[i];
     broj_koji_se_ponavlja++;
    
}
 }
 int konacan_broj=0;
 for(i=0;i<broj_koji_se_ponavlja; i++){
     int ima_dupli=0, j;
     for(j=i+1; j<broj_koji_se_ponavlja; j++){
         
         if(pomocni_niz[i]==pomocni_niz[j])
         {
             ima_dupli=1;
             break;
         }
     }
     if(ima_dupli==0) {
         konacan_broj++;
     }
     
 } return konacan_broj; 
    
}


int main() {
	
 int i,j, k, rez;
 int br1,br2,br3;
 int prviNiz[100], drugiNiz[100], treciNiz[100];
 
    for (i = 0; i < vel; i++) {
        scanf("%d ", &prviNiz[i]);
        if(prviNiz[i]==-1)
        break;
        br1=i;
    }
 
    for (j = 0; j < vel; j++){
        scanf ("%d ", &drugiNiz[j]);
         if(drugiNiz[j]==-1) break;
          br2=j;
    }
    
    for (k = 0; k < vel; k++){
        scanf ("%d ", &treciNiz[k]);
        if(treciNiz[k]==-1) break;
        br3=k;
    }
    
    rez=dva_od_tri(prviNiz, br1, drugiNiz, br2, treciNiz, br3);
    printf("%d", rez);
	return 0;
}
