#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main(){
    int broj_uglova,i,j,s,m,k,sek;
    int znak=0;
    float x,temp,niz[500],min,sekk,novo;
	printf("Unesite broj uglova: ") ;
	scanf("%d",&broj_uglova) ;
	for(i=0 ;i<broj_uglova ;i++) {
	    scanf("%f",&niz[i]) ;
	    }
	
	for(i=0 ; i< broj_uglova ; i++) {
	    // pretvaranje iz radijana u stepene
	    x=(niz[i]*180)/ PI ;
	    if(x<0) x= -x;
	    s=(int)x ;
	    min=(x-s)*60 ;
	    m= (int) min;
	    sekk=(min-m)*60 ;
	    sek=(int)sekk;
	    novo=sekk-sek;
	    if(novo>=0.5) sek++ ;
	    if(sek==60) {
	    	sek=0;
	    	m++;
	    }
	    if(m==60){
	    	s++;
	    	m=0;
	    }
	     
	     if(sek>30) {
	     	//k=i;
	     	for(j=i;j<broj_uglova-1;j++){
	     	//for(j=i;j<broj_uglova-1;j++){
	     	temp=niz[j+1];
	     	//printf("%f", temp);
	     	niz[j+1]=niz[j]; 
	     	niz[j]=temp;
	     	//printf("%f %f \n",niz[j],niz[j+1]);
	     //	k++;
	     }
	     	broj_uglova--;
	     	i--;
	    //printf(	"iteracija" );
	    //for(k=0 ;k<broj_uglova ;k++) {
	    //printf("%f",niz[k]) ;
	    //}
	    }
	}
	//ispis
	printf("Uglovi su:\n") ;
	for(i=0 ;i<broj_uglova ;i++) {
	    x=(niz[i]*180)/ PI ;
	    if(x<0){
	    	x= -x;
	    	znak=1;
	    }
	    s=(int)x ;
	    min=(x-s)*60 ;
	    m= (int) min;
	    sekk=(min-m)*60 ;
	    sek=(int)sekk;
	    novo=sekk-sek;
	    if(novo>=0.5) sek++ ;
	     if(sek==60) {
	    	sek=0;
	    	m++;
	    }
	    if(m==60){
	    	s++;
	    	m=0;
	    }
	    if(znak==1) s= -s;
    	if(s==0 && znak==1) printf("-");
    	
	    printf("%d stepeni %d minuta %d sekundi\n",s,m,sek) ;
	    znak=0;
	}
	
	return 0;
}
