#include <stdio.h>


int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3) {
	
    int i, brojac=0, j, k, p[100], clan=0, e;
    
          for(i=0;i<vel1;i++) {
            for(j=0;j<vel2;j++) {
               	for(k=0;k<vel3;k++) {
               		  if(niz1[i]==niz3[k] && niz2[j]==niz3[k]) {
               		    p[clan]=niz2[i];
               		    clan++;
               	    	}
               		  }
               	}
               }
         for(e=0;e<clan;e++) {
            for(i=0;i<vel1;i++) {
               if(niz1[i]==p[e]) {
               		 niz1[i]=niz1[vel1-1];
               			vel1--;
               			i--;
               		}
               	}
               }
         for(e=0;e<clan;e++) {
            for(j=0;j<vel2;j++) {
               if(niz2[j]==p[e]) {
               	 	niz2[j]=niz2[vel2-1];
               			vel2--;
               			j--;
               		}
               	}
               }
         for(e=0;e<clan;e++) {
             for(k=0;k<vel3;k++) {
               	if(niz3[k]==p[e]) {
               		 niz3[k]=niz3[vel3-1];
               			vel3--;
               			k--;
               		}
               	}
               } 
               
         for(i=0;i<vel1;i++) {
            for(j=0;j<vel2;j++) {
               if(niz1[i]==niz2[j] && niz1[i]!=niz3[i])
               		 brojac++;
               	}
               }
         for(i=0;i<vel2;i++) {
            for(j=0;j<vel3;j++) {
               if(niz2[i]==niz3[j] && niz2[i]!=niz1[i])
               		brojac++;
               	}
               }
         for(i=0;i<vel1;i++) {
             for(j=0;j<vel3;j++) {
               		if(niz1[i]==niz3[j] && niz1[i]!=niz2[i])
               		   brojac++;
               	}
               }
            return brojac;
}

int main() {
int niz1[100], niz2[100], niz3[100], i, n1, n2, n3;

printf("velicina prvog:");
scanf("%d", &n1);
printf("niz1:");
for(i=0;i<n1;i++) {
scanf("%d", &niz1[i]);
}
printf("velicina drugog:");
scanf("%d", &n2);
printf("niz2:");
for(i=0;i<n2;i++) {
scanf("%d", &niz2[i]);
}
printf("velicina treceg:");
scanf("%d", &n3);
printf("niz3:");
for(i=0;i<n3;i++) {
scanf("%d", &niz3[i]);
}

dva_od_tri(niz1,n1,niz2,n2,niz3,n3);
	
return 0;
}
