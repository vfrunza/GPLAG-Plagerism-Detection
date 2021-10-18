#include <stdio.h>
#include <math.h>

void ubaci(int* p,int vel){
	int i,c,s=0;
	for(i=0;i<vel;i++){
		*(p+2*vel-2*i-2)=*(p+vel-i-1);
	}
	for(i=0;i<vel;i++){
		*(p+2*i+1)=*(p+2*i);
	}
	for(i=0;i<vel;i++){
		*(p+2*i+1)=fabs(*(p+2*i+1));
		do{
			c=(*(p+2*i+1))%10;
			s=s+c;
			*(p+2*i+1)=(*(p+2*i+1))/10;
		}
		while((*(p+2*i+1))!=0);
		*(p+2*i+1)=s;
		s=0;
	}
}

int izbaci(int* p,int br){
	int i,d[1000],j,k,l;
	d[0]=1;
	d[1]=1;
	for(i=2;i<1000;i++){
		d[i]=d[i-1]+d[i-2];
	}
	for(k=0;k<br;k++){
		if(*p==1){
			for(l=0;l<br-k-1;l++){
				*(p+l)=*(p+l+1);
			}
			k--;
			br--;
			p--;
		}
		else{
			for(j=0;j<1000;j++){
				if((*p)==d[j]){
					for(l=0;l<br-k-1;l++){
						*(p+l)=*(p+l+1);
					}
					k--;
					br--;
					p--;
					goto kraj;
				}
			}
		}
		kraj:
		p++;
	}
	return br;
}

int main() {
	int a[100],i,brojac;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	ubaci(a,10);
	brojac=izbaci(a,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<brojac;i++){
		if(i<brojac-1){
			printf("%d, ",a[i]);
		}
		else printf("%d.",a[i]);
	}
	return 0;
}