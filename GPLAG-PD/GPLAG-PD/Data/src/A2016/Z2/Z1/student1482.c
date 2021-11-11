#include <stdio.h>
#include<math.h>
int main() {
	int broj1,broj2,J,D,S,H,DH,SH,M,SM,DM;
	printf("Unesite broj: ");
	scanf("%d",&broj1);
if(broj1<=0)
broj1=fabs(broj1); 

	if (broj1<10) {
		broj2=0;
	}
	
	else if (broj1<100) {
			J=broj1%10;
	broj1/=10;
	D=broj1%10;
	broj2=fabs(J-D);
	}
	else if(broj1<1000) {
			J=broj1%10;
	broj1/=10;
	D=broj1%10;
	broj1/=10;
	S=broj1%10;
	broj2=fabs(J-D)+fabs(D-S)*10;
	}
	else if(broj1<10000) {
			J=broj1%10;
	broj1/=10;
	D=broj1%10;
	broj1/=10;
	S=broj1%10;
    broj1/=10;
    H=broj1%10;
    broj2=fabs(J-D)+fabs(D-S)*10+fabs(S-H)*100;
	}
	else if(broj1<100000){
		J=broj1%10;
	broj1/=10;
	D=broj1%10;
	broj1/=10;
	S=broj1%10;
    broj1/=10;
    H=broj1%10;
    broj1/=10;
    DH=broj1%10;
    broj2=fabs(J-D)+fabs(D-S)*10+fabs(S-H)*100+fabs(H-DH)*1000;
	}
		else if(broj1<1000000){
		J=broj1%10;
	broj1/=10;
	D=broj1%10;
	broj1/=10;
	S=broj1%10;
    broj1/=10;
    H=broj1%10;
    broj1/=10;
    DH=broj1%10;
    broj1/=10;
    SH=broj1%10;
    broj2=fabs(J-D)+fabs(D-S)*10+fabs(S-H)*100+fabs(H-DH)*1000+fabs(DH-SH)*10000;
	}
    else if(broj1<10000000){
		J=broj1%10;
	broj1/=10;
	D=broj1%10;
	broj1/=10;
	S=broj1%10;
    broj1/=10;
    H=broj1%10;
    broj1/=10;
    DH=broj1%10;
    broj1/=10;
    SH=broj1%10;
    broj1/=10;
    M=broj1%10;
    broj2=fabs(J-D)+fabs(D-S)*10+fabs(S-H)*100+fabs(H-DH)*1000+fabs(DH-SH)*10000+fabs(SH-M)*100000;
	}
	else if(broj1<100000000){
		J=broj1%10;
	broj1/=10;
	D=broj1%10;
	broj1/=10;
	S=broj1%10;
    broj1/=10;
    H=broj1%10;
    broj1/=10;
    DH=broj1%10;
    broj1/=10;
    SH=broj1%10;
    broj1/=10;
    M=broj1%10;
    broj1/=10;
    DM=broj1%10;
    broj2=fabs(J-D)+fabs(D-S)*10+fabs(S-H)*100+fabs(H-DH)*1000+fabs(DH-SH)*10000+fabs(SH-M)*100000+fabs(M-DM)*1000000;
	}
	 else {
		J=broj1%10;
	broj1/=10;
	D=broj1%10;
	broj1/=10;
	S=broj1%10;
    broj1/=10;
    H=broj1%10;
    broj1/=10;
    DH=broj1%10;
    broj1/=10;
    SH=broj1%10;
    broj1/=10;
    M=broj1%10;
    broj1/=10;
    DM=broj1%10;
    broj1/=10;
    SM=broj1%10;
    broj2=fabs(J-D)+fabs(D-S)*10+fabs(S-H)*100+fabs(H-DH)*1000+fabs(DH-SH)*10000+fabs(SH-M)*100000+fabs(M-DM)*1000000+fabs(DM-SM)*10000000;
	}
    printf("%d",broj2);
	return 0;
}
