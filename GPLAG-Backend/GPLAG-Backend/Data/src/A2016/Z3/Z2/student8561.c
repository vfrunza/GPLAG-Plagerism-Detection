#include <stdio.h>

	int fibonacijev_niz(int p){
		int fniz[46]={1,1},a,b,c,r,i;
		a=1;
		b=1;
		i=0;
		r=0;
		for(i=2;i<46;i++){
			c=a+b;
			a=b;
			b=c;
			fniz[i]=c;
		}
		for(i=0;i<46;i++){
			if(p==fniz[i]){
				r=1;
				break;
			}
			else r=0;
		}
		return r;
	}
	
	int izbaci(int* niz, int v){
		int t1,t2,i,j,x;
		t1=v;
		t2=v-1;
		for(j=0;j<t1;j++){
			x=fibonacijev_niz(*niz);
			if(x==1){
				if(j==t1-1){
					v--;
					return v;
				}
				for(i=0;i<t2;i++){
					*niz=*(niz+1);
					niz++;
				}
				v--;
				niz=niz-t2;
			} else{
				if(j==t1-1)
				niz--;
				niz++;
			}
			t2--;
		}
		return v;
	}	
	
	
		int Suma(int br){
		int c,suma=0;
		if(br<0) br*=-1;
		while(br>0){
			c=br%10;
			suma+=c;
			br/=10;
		}
		return suma;
	}
	
	void ubaci(int* p, int v){
		int p1,i,j,t1,t2,suma=0;;
		t1=v;
		t2=v;
		for(i=0;i<t1;i++){
			if(i=t1-1){
				p1=*p;
				suma=Suma(p1);
				*(p+1)=suma;
				return;
			}
			p1=*p;
			suma=Suma(p1);
			for(j=0;j<t1-1;j++){
				while(v>0){
					*(p+v)=*(p+v-1);
					v--;
				}
			}
			*(p+1)=suma;
			p=p+2;
			t2--;
			v=t2;
		}
	}

int main() {
	int niz[20],i=0,v;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	scanf("%d",&niz[i]);
	
	ubaci(niz,10);
	v=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	if(v>0){
		for(i=0;i<v-1;i++)
		printf("%d, ",niz[i]);
		printf("%d.",niz[v-1]);
	}
	else printf(" ");
	return 0;
}
