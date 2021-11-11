#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int x,pc=0,dc=0,tc=0,cc=0,ppc=0,sc=0,sec=0,oc=0,dec=0,jc=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0,brojac=0,n=0;
	printf("Unesite broj: ");
	scanf("%d",&x);
	n=n+x;
	while(n!=0){
		n/=10;
		++brojac;
	}
	while(x!=0){
		pc=x%10; x=x/10;
		dc=x%10; x=x/10;
		tc=x%10; x=x/10;
		cc=x%10; x=x/10;
		ppc=x%10; x=x/10;
		sc=x%10; x=x/10;
		sec=x%10; x=x/10;
		oc=x%10; x=x/10;
		dec=x%10; x=x/10;
		jc=x%10; x=x/10;
		break;
	}
	c1=pc-dc;
	c2=dc-tc;
	c3=tc-cc;
	c4=cc-ppc;
	c5=ppc-sc;
	c6=sc-sec;
	c7=sec-oc;
	c8=oc-dec;
	c9=dec-jc;

	if(c1<=0) c1=c1/(-1);
	if(c2<=0) c2=c2/(-1);
	if(c3<=0) c3=c3/(-1);
	if(c4<=0) c4=c4/(-1);
	if(c5<=0) c5=c5/(-1);
	if(c6<=0) c6=c6/(-1);
	if(c7<=0) c7=c7/(-1);
	if(c8<=0) c8=c8/(-1);
	if(c9<=0) c9=c9/(-1);
	if(brojac==1) printf("0");
    else	if(brojac==2) printf("%d",c1);
	else    if(brojac==3 && c1>=0 && c2==0) printf("%d",c1); 
	else    if(brojac==3) printf("%d%d",c2,c1);
	else 	if(brojac==4 && c1>=0 && c2==0 && c3==0) printf("%d",c1); 
	else    if(brojac==4) printf("%d%d%d",c3,c2,c1);
	else 	if(brojac==5 && c1>=0 && c2==0 && c3==0 && c4==0) printf("%d",c1); 
	else    if(brojac==5) printf("%d%d%d%d",c4,c3,c2,c1);
	else 	if(brojac==6 && c1>=0 && c2==0 && c3==0 && c4==0 && c5==0) printf("%d",c1); 
	else    if(brojac==6) printf("%d%d%d%d%d",c5,c4,c3,c2,c1);
	else	if(brojac==7 && c1>=0 && c2==0 && c3==0 && c4==0 && c5==0 && c6==0) printf("%d",c1);
	else    if(brojac==7) printf("%d%d%d%d%d%d",c6,c5,c4,c3,c2,c1);
	else 	if(brojac==8 && c1>=0 && c2==0 && c3==0 && c4==0 && c5==0 && c6==0 && c7==0) printf("%d",c1); 
	else    if(brojac==8) printf("%d%d%d%d%d%d%d",c7,c6,c5,c4,c3,c2,c1);
	else    if(brojac==9 && c1>=0 && c2==0 && c3==0 && c4==0 && c5==0 && c6==0 && c7==0 && c8==0) printf("%d",c1); 
	else    if(brojac==9) printf("%d%d%d%d%d%d%d%d",c8,c7,c6,c5,c4,c3,c2,c1);
	else    if(brojac==10 && c1>=0 && c2==0 && c3==0 && c4==0 && c5==0 && c6==0 && c7==0 && c8==0 && c9==0) printf("%d",c1); 
	else    if(brojac==10) printf("%d%d%d%d%d%d%d%d%d",c9,c8,c7,c6,c5,c4,c3,c2,c1);
	
	return 0;
}
