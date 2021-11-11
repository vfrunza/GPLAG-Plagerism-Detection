#include <stdio.h>


int dva_od_tri(int A[], int a,int B[], int b, int C[], int c){
 int D[300],d,i,j,k,l,brojac,br=0;
   for (i = 0; i < a; i++) {
      for (j = i + 1; j < a;) {
         if (A[j] == A[i]) {
            for (k = j; k < a; k++) {
               A[k] = A[k + 1];
            }
            a--;
         } else
            j++;
      }
   }
   for (i = 0; i < b; i++) {
      for (j = i + 1; j < b;) {
         if (B[j] == B[i]) {
            for (k = j; k < b; k++) {
               B[k] = B[k + 1];
            }
            b--;
         } else
            j++;
      }
   }
       
   for (i = 0; i < c; i++) {
      for (j = i + 1; j < c;) {
         if (C[j] == C[i]) {
            for (k = j; k < c; k++) {
               C[k] = C[k + 1];
            }
            c--;
         } else
            j++;
      }
   }
 /*for(i=0;i<a;i++)
 printf(" %d ",A[i]);
 printf("\n");
 for(i=0;i<b;i++)
 printf(" %d ",B[i]);
 printf("\n");
 for(i=0;i<c;i++)
 printf(" %d ",C[i]);
 printf("\n");*/
 d=0;
 for(i=0;i<a;i++){
 D[i]=A[i];
 d++;
 }
 j=0;
 for(i=a;i<(a+b);i++){
 D[i]=B[j];
 j++;
 d++;
 }
 j=0;
 for(i=(a+b);i<(a+b+c);i++){
     D[i]=C[j];
     j++;
     d++;
 }
for (i = 0; i < d; i++) {
      for (j = i + 1; j < d;) {
         if (D[j] == D[i]) {
            for (k = j; k < d; k++) {
               D[k] = D[k + 1];
            }
            d--;
         } else
            j++;
      }
   }
   for(i=0;i<d;i++)
  /* printf(" %d ",D[i]);
   printf("\n");*/
   for(i=0;i<d;i++){
       brojac=0;
       for(j=0;j<a;j++){
           if(D[i]==A[j]) brojac++;
           /*printf("%d ",brojac);*/
       }
       for(k=0;k<b;k++){
           if(D[i]==B[k]) brojac++;
           /*printf("%d ",brojac);*/
       }
       for(l=0;l<c;l++){
           if(D[i]==C[l]) brojac++;
           /*printf("%d ",brojac);*/
       }
       if(brojac==2) br++;
   }
   return br;
}
int main() {

int a,b,c,A[100],B[100],C[100];
int i;
scanf("%d%d%d",&a,&b,&c);
for(i=0;i<a;i++)
scanf("%d",&A[i]);
for(i=0;i<b;i++)
scanf("%d",&B[i]);
for(i=0;i<c;i++)
scanf("%d",&C[i]);
printf("%d",dva_od_tri(A,a,B,b,C,c));
	return 0;
}
