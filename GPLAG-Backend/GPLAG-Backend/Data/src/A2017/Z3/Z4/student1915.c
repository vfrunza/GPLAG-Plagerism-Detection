#include <stdio.h>

int max(int matrica[100][100],int visina,int sirina)
{
int ogranicenje=0,k,niz1[100],niz2[100],maximus=0,p=0,i,j,pogodak,prekidac=1;
for(i=0;i<visina;i++){
 for(j=0;j<sirina;j++){
  if(prekidac){
   prekidac=0;
   niz1[ogranicenje]=matrica[i][j];
   niz2[ogranicenje]=1;
   ogranicenje++;
  }else{
   pogodak=0;
   for(k=0;k<ogranicenje;k++){
    if(niz1[k]==matrica[i][j]){
     niz2[k]++;
     pogodak=1;
     break;
    }
   }
   if(!pogodak){
    niz1[ogranicenje]=matrica[i][j];
    niz2[ogranicenje]=1;
    ogranicenje++;
   }
  }
 }
}
maximus=niz2[0];
for(i=0;i<ogranicenje;i++){
 if(niz2[i]>maximus){maximus=niz2[i];p=i;}
}
prekidac=0;
for(i=0;i<ogranicenje;i++){
 if(maximus==niz2[i] && p!=i && niz1[i]<niz1[p]){prekidac=1;maximus=niz2[i];p=i;}
}
if(prekidac)return niz1[p];
return niz1[p];
}

int izbaci_kolone(int matrica[100][100],int visina,int sirina,int N){
 int i,j,k,l,p;
 for(i=0;i<visina;i++){
  for(j=0;j<sirina;j++){
 
   if(matrica[i][j]==N){
    for(k=0;k<visina;k++){
     for(l=j+1,p=j;l<sirina;l++,p++)
      matrica[k][p]=matrica[k][l];
    }
    sirina--;
    j--;
   }
   
  }
 }
 return sirina;
}

int main(){
 int i,j,mat[100][100],visina,sirina,n,t;
printf("Unesite sirinu i visinu matrice: ");
scanf("%d %d",&sirina,&visina);
for(i=0;i<visina;i++){
 printf("Unesite elemente %d. reda: ",i+1);
 for(j=0;j<sirina;j++)
  scanf("%d",&mat[i][j]);
}
t=1;
printf("\n");
n=sirina;
while(1){
 n=izbaci_kolone(mat,visina,n,max(mat,visina,n));
 if(n==0){printf("Nakon %d. prolaza matrica je prazna!",t);break;}
 printf("Nakon %d. prolaza matrica glasi:\n",t);
for(i=0;i<visina;i++){
 for(j=0;j<n;j++){
 printf("%5d",mat[i][j]);
 }
 printf("\n");
}
t++;
}
return 0;
}