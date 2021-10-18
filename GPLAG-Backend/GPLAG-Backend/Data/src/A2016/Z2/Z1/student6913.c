#include <stdio.h>
#include <math.h>

int main() {
      int m,m1,bc=0,p,d,nb=0,ubc,raz=0,i;
      printf("Unesite broj: ");
      scanf("%d",&m);
      if(m>-9 && m<9){
      	printf("0");
      	return 0;
      }
      if(m<0){
      	m=m+m*(-2);
      }
      m1=m;
      while(m1!=0){
      	m1=m1/10;
      	bc++;
      }
              ubc=bc-1;
        for(i=0;i<ubc;i++){
      	p=m%10;
        d=(m%100)/10;
        raz=p-d;
        if(raz<0){
        	raz=raz+raz*(-2);
        }
        nb=nb+raz*pow(10,i);
        m=m/10;
        }
        printf("%d",nb);
	return 0;
}
