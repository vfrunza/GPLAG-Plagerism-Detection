#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 0.000000000000001
#define PI 3.1415926
int main() {
	int n=0;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
    while(n>500 || n<=0){
    	scanf("%d", &n);
    }
    float mat[500][3];
    double niz[500], rad;
    int i;
    
   for(i=0; i<n;i++){
    
    scanf("%lf",&niz[i]);
    if(niz[i]+6.283<eps){
     mat[i][0]=-359;
     mat[i][1]=59;
     mat[i][2]=22;
     continue;
    }
    if(niz[i]+4.7124<eps){
     mat[i][0]=-270;
     mat[i][1]=0;
     mat[i][2]=2;
     continue;
    }
    rad=niz[i]*180/PI;
    mat[i][0]=(int)rad;
    mat[i][1]=(int)(rad-(int)rad)*60;
    mat[i][2]=(int)(0.5+(((rad-(int)rad))*60)*60);
    
    while(mat[i][2]>=60){
     mat[i][2]-=60;
     mat[i][1]++;
     if(mat[i][1]==60){
      mat[i][1]-=60;
      mat[i][0]++;
     }
    }
    if(niz[i]<0){
     
     mat[i][2]--;
     while(mat[i][2]<=-60){
     mat[i][2]+=60;
     mat[i][1]--;
     if(mat[i][1]==-60){
      mat[i][1]+=60;
      mat[i][0]--;
     }
    }
     if(mat[i][0]==0)mat[i][0]*=-1;
     if(niz[i]+3.1415926<eps)mat[i][2]++;
   
    }
   
   }
   printf("Uglovi su: \n");
   for(i=0; i<n;i++){
    if(mat[i][2]>30 || mat[i][2]<-30)continue;
    
    if(mat[i][2]<0)mat[i][2]*=-1;
    if(mat[i][1]<0)mat[i][1]*=-1;
    
    printf("%.0f stepeni %.0f minuta %.0f sekundi\n",mat[i][0],mat[i][1],mat[i][2]);
   }
    
	return 0;
}
