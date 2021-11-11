#include <stdio.h>

int dva_od_tri (int niz1[],int vel1,int niz2[],int vel2,int niz3[],int vel3){
 int brojac=0,i,j,k,pomocni1[1000],pomocni2[1000],pomocni3[1000],s=0,l=0;
 for(i=0;i<vel1;i++){
 	for(j=0;j<vel2;j++){
 		if(niz1[i]==niz2[j]){
 			pomocni1[s]=niz1[i];
 			for(l=0;l<s;l++){
 				if(pomocni1[l]==niz1[i]) break;
 			}
 			
 			if(l==s){
 			for(k=0;k<vel3;k++){
 				if(niz1[i]==niz3[k]) break;
 			}
 			if(k==vel3) brojac++;
 		}
 		s++;
 		}
 	}
 }

 s=0;
 l=0;
 for(i=0;i<vel2;i++){
 	for(j=0;j<vel3;j++){
 		if(niz2[i]==niz3[j]){
 		 pomocni2[s]=niz2[i];
 		 for(l=0;l<s;l++){
 		  if(pomocni2[l]==niz2[i]) break;
 		 }
 		 
 		 if(l==s){
 			for(k=0;k<vel1;k++){
 				if(niz2[i]==niz1[k]) break;
 			}
 			if(k==vel1) brojac++;
 		}
 		s++;
 		}
 	}
 }
 s=0;
 l=0;
 for(i=0;i<vel1;i++){
 	for(j=0;j<vel3;j++){
 		if(niz1[i]==niz3[j]){
 		 pomocni3[s]=niz1[i];
 		 for(l=0;l<s;l++){
 		  if(pomocni3[l]==niz1[i]) break;
 		 }
 		 
 		 if(l==s){
 			for(k=0;k<vel2;k++){
 				if(niz1[i]==niz2[k]) break;
 			}
 			if(k==vel2) brojac++;
 		}
 		s++;
 		}
 	}
 }
	return brojac;
}
int main()
{
int niz1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
int niz2[] = {3, 3, 3, 2, 2};
int niz3[] = {1, 3, 4};
int rez = dva_od_tri(niz1, 11, niz2, 5, niz3, 3);
printf("%d ", rez);
rez = dva_od_tri(niz1, 11, niz1, 11, niz1, 3);
printf("%d ", rez);
rez = dva_od_tri(niz1, 11, niz1, 11, niz1, 11);
printf("%d ", rez);
	return 0;
}
