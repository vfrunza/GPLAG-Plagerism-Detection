#include <stdio.h>
#define PI 3.1415926

int main() {
	double niz[500], sec[500], m[500], st[500], sekunda[500], c;
	long int i, n, j, stepen, minuta, s1;
	
do{	printf("Unesite broj uglova: ");
	scanf("%ld", &n);
}
	while(n<0 || n>500);
	
	for(i=0; i<n; i++){
		scanf("%lf", &niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0; i<n; i++){
		c=niz[i];
		if(c<0){
			c=(-1)*c;
		}
		         	stepen=(int)(c*(180./PI));
                    st[i]=c*(180./PI)-stepen;
                    m[i]=st[i]*60;
                    minuta=(int)m[i];
                    sec[i]=m[i]-minuta;
                    sekunda[i]=sec[i]*60;
                    s1=(int)((sekunda[i] + 0.5));
                    if(s1>30 && s1!=60){
                    	for(j=i; j<n-1; j++){
                    		niz[j]=niz[j+1];
                    	}
                    	n--;
                    	i--;}
	}
              
	for(i=0; i<n; i++){
		c=niz[i];
		if(c<0){
			c=(-1)*c;
		}
		            stepen=(int)(c*(180./PI));
                    st[i]=c*(180./PI)-stepen;
                    m[i]=st[i]*60;
                    minuta=(int)m[i];
                    sec[i]=m[i]-minuta;
                    sekunda[i]=sec[i]*60;
                    s1=(int)((sekunda[i] + 0.5));
                    if(s1<0){
                    	s1=(-1)*s1;
                    }
                    if(minuta<0){
                    	minuta=(-1)*minuta;
                    }
                    if(s1==60){
                    	minuta++;
                    	s1=0;
                    }
if(minuta==60){
	stepen++;
	minuta=0;
}
	if(niz[i]<0){
       printf("-%ld stepeni %ld minuta %ld sekundi\n", stepen, minuta, s1);}
else{
	    printf("%ld stepeni %ld minuta %ld sekundi\n", stepen, minuta, s1);
}	

	}		
	
	return 0;
}
