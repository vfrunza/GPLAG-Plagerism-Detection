#include <stdio.h>
int jel_ista_cifra(int *niz1,int vel,int b)
{
	int *q=niz1;
	int pom=0;
	while(q<niz1+vel) {
		if(*q==b) pom=1;
		q++;
	}
	return pom;
}

int izbaci_cifre(int *niz,int vel1,int *cifra,int vel2)
{
	int *p=niz;
	int *q=cifra;
	int *q1=cifra;
	int jel=1,k=1,a=0,temp=0,s=0,temp1=0,temp2=0;
	if(vel2==0) return jel;
	while(q<cifra+vel2) {
		temp1=*q;
		if(temp1<0 || temp1>9) jel=0;
		q++;
	}
	if(jel==0) return jel;
	q=cifra;
	q1++;
	jel=1;
	while(q<cifra+vel2) {
		while(q1<cifra+vel2) {
			if(*q==*q1) jel=0;
			q1++;
		}
		q++;
	}
	if(jel==0) return jel;

	while(p<niz+vel1) {
		temp=*p;
		if(temp<0) {
			temp*=(-1);
			s=1;
		}
		while(temp!=0) {
			a=temp%10;
			temp1=jel_ista_cifra(cifra,vel2,a);
			if(temp1==0) {
				temp2=k*a+temp2;
				k=k*10;
				temp=temp/10;
			}
			if(temp1) {
				temp/=10;
			}
		}
		if(s) {
			temp2*=(-1);
		}
		*p=temp2;
		temp2=0;
		p++;
		k=1;
		s=0;
	}
	return jel;
}


int main()
{
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
