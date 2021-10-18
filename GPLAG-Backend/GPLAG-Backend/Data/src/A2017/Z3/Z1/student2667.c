#include <stdio.h>
int dva_od_tri(int* niz1,int vel1,int* niz2, int vel2,  int *niz3,int vel3){
	int brojac=0,i,j,pomocni[100],k=0,m,h,puta,min3,temp3,niz1prim[100],niz2prim[100],niz3prim[100];
	 int duzina=0,duzina2=0,duzina3=0;
	 int novi1[100],novi2[100],novi3[100];
	 int temp2,min2,temp1,min1;
	 for(i=0;i<vel1;i++){
	     novi1[i]=niz1[i];
	 }
	 for(i=0;i<vel2;i++){
	     novi2[i]=niz2[i];
	 }
	 for(i=0;i<vel3;i++){
	     novi3[i]=niz3[i];
	 }
	 for(i=0;i<vel1;i++){
       min3=i;
       for(j=i+1;j<vel1;j++){
           if(novi1[j]<novi1[min3]) min3=j;}
       temp3=novi1[i];
       novi1[i]=novi1[min3];
       novi1[min3]=temp3;
   }
   for(i=0;i<vel2;i++){
       min2=i;
       for(j=i+1;j<vel2;j++){
           if(novi2[j]<novi2[min2]) min2=j;}
       temp2=novi2[i];
       novi2[i]=novi2[min2];
       novi2[min2]=temp2;
   }
   for(i=0;i<vel3;i++){
       min1=i;
       for(j=i+1;j<vel3;j++){
           if(novi3[j]<novi3[min1]) min1=j;}
       temp1=novi3[i];
       novi3[i]=novi3[min1];
       novi3[min1]=temp1;
   }
   for(i=0;i<vel1;i++){
       if(i==vel1-1) {
            niz1prim[duzina]=novi1[i];
           duzina++;
       }
       else if(novi1[i]==novi1[i+1]) continue;
       else
       {
           niz1prim[duzina]=novi1[i];
           duzina++;
   }}
   for(i=0;i<vel2;i++){
       if(i==vel2-1) {
           niz2prim[duzina2]=novi2[i];
           duzina2++;
       }
       else  if(novi2[i]==novi2[i+1]) continue;
       else
       {
           niz2prim[duzina2]=novi2[i];
           duzina2++;
   }}
   for(i=0;i<vel3;i++){
       if(i==vel3-1){
            niz3prim[duzina3]=novi3[i];
           duzina3++; }
       else if(novi3[i]==novi3[i+1]) continue;
       else
       {
           niz3prim[duzina3]=novi3[i];
           duzina3++;
   }}
    for(i=0;i<duzina;i++){
    	pomocni[k]=niz1prim[i];
    	k++;
    }
    m=k;
    for(i=0;i<duzina2;i++){
        pomocni[m]=niz2prim[i];
        m++;
    }
    h=m;
    for(i=0;i<duzina3;i++){
        pomocni[h]=niz3prim[i];
        h++;
    }
  for(i=0;i<h;i++){
       min3=i;
       for(j=i+1;j<h;j++){
           if(pomocni[j]<pomocni[min3]) min3=j;}
       temp3=pomocni[i];
       pomocni[i]=pomocni[min3];
       pomocni[min3]=temp3;
   }
   j=0;
   for(i=0;i<h;i++){
       i=j;
       puta=0;
       for(j=i;j<h;j++){
           if(pomocni[i]==pomocni[j]) puta++;
          else break;
       }
       if(puta==2 ) brojac++;
   }
	return brojac;
}
int main() {/*
	int i, rez,vel1,vel2,vel3,niz1[100],niz2[100],niz3[100];
	printf("Unesite duzinu prvog niza : ");
	scanf("%d",&vel1);
	for(i=0;i<vel1;i++){
	    scanf("%d", &niz1[i]);
	}
	printf("Unesite duzinu drugog niza : ");
	scanf("%d",&vel2);
	for(i=0;i<vel2;i++){
	    scanf("%d", &niz2[i]);
	}
	printf("Unesite duzinu treceg niza : ");
	scanf("%d",&vel3);
	for(i=0;i<vel3;i++){
	    scanf("%d", &niz3[i]);
	}
	rez=dva_od_tri(niz1,niz2,niz3,vel1,vel2,vel3);
	printf("%d", rez);
	return 0;
}
