#include <stdio.h>
#include <math.h>
int main() {
 int U[100], C[1000]={0}, S[1000], brojac[100]={0}, j=0, i, n, b, c, a, k=0, x=2, s=0;
 printf("Unesite velicinu niza: ");
 
 do{ 
 	scanf("%d", &n);
    if(n<0 || n>100) printf("Pogresan unos!");
  } while(n<0 || n>100); 
  
 printf("Unesite clanove niza: ");
 for(i=0; i<n; i++){
 	scanf("%d", &U[i]);
 	 do{
 	   a=U[i]/10.;
    	a=a*10;
 	   b=U[i]-a;
 	   S[j]=b;
 	   U[i]=a/10;
 	   a=a/10;
 	   j++;} while(a!=0);
 	   j--;
 	   b=j;
 	  c=j;
 	    for(s=k; s<(j+1); s++){
 	    C[c]=S[s];
 	    c--;
 	    k++;
 	   }j++;}
 	   j=0;
 	   b=0;
 	   c=k;
 for(i=0; i<c; i++){
  if(C[i]==C[i+1] && i!=(c-1)){ brojac[j]=x; x++; b++;}; 
   if(C[i]!=C[i+1] && i!=(c-1)){x=2;
   if(brojac[j]!=0) j++; else{ brojac[j]=1; j++;}}}
   if(brojac[c-b-1]==0) brojac[c-b-1]=1;
   j=0; s=0; n=0;
      for(i=0; i<c-b; i++){
       if(brojac[j]==1){
        S[s]=C[n]; S[s+1]=brojac[j];}
       else {S[s]=C[n+brojac[j]-1]; S[s+1]=brojac[j]; n=(i+brojac[j]-1);} s=s+2; n++; j++;}
       
       printf("Finalni niz glasi: \n");
       for(i=0; i<2*(k-b); i++)
       printf("%d ", S[i]);
      return 0;}
