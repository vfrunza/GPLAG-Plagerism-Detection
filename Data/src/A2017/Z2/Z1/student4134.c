#include <stdio.h>

int main() {
	int i,j;
	int N=0;

	do {
	 printf("Unesite broj N: ");
	 scanf("%d",&N);
	 if(N<8 || N%4!=0){
	 printf("Neispravno N!");
	  printf("\n");
	 }
	} while (N<8|| N%4!=0);
		printf("\n");
		
for(i=0;i<N;i++){
if (i<(N/2)){
 for(j=0;j<N;j++){
  if(j<(N/2))
 
 {
  if(j==i) 
  printf("\\");
  else if (i!=(N/2-j-1)) printf(" ");
  else printf("/");
 }
 else 
 { if(i==0 || i==(N/2-1)) {
   if(j==N-1 || j==N/2) printf("+"); else printf("-");
 
 }
  else {if(j==N/2 || j==N-1) printf("|");
   else printf(" ");
  
  
  }}}} else {
 
 
  for(j=0;j<N;j++){
   if(j<(N/2)) {
    if(i==N/2 || i==N-1){
    if(j==0 || j==N/2-1) printf("+"); else printf("-");
   } else {
   if(j==0 || j==(N/2)-1){ printf("|");
   }else printf(" "); 
    
   }}else {
    if ((j==N/2+N/4 || j==N/2+N/4-1) && (i==N/2+N/4 || i==N/2+N/4-1)) printf("+");
    else if(j==N/2+N/4 || j==N/2+N/4 -1) printf("|");
    else if(i==N/2+N/4 || i==N/2+N/4-1) printf("-");
    else printf(" ");
   }}}
   printf("\n");
   }
    printf("\n");
   return 0;
   }