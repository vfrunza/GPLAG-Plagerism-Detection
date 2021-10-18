#include <stdio.h>
#include <stdio.h>
int suma_cifara(float d){
	d=d*10;
    int a=(int)d;
    int br=0;
    while(a!=0){
        br+=a%10;
        a/=10;
    }
    return br;
}
float* zaokruzi1(float niz[],int vel){
    int *pom=niz;
    int i;
    for(i=0;i<vel;i++){
    	if(niz[i]>0){
        niz[i]=(int)((niz[i]+0.05)*10);
    	}
    	if(niz[i]<0){
    		niz[i]=(int)((niz[i]-0.05)*10);
    	}
        niz[i]=niz[i]/10;
    }
    return pom;
}
void preslozi(float niz[],int vel,int k){
    int i=0,j=0;
    float pom[100];
    niz=zaokruzi1(niz,vel);
    for(i=0;i<vel;i++){
        if(suma_cifara(niz[i])>=k){
            pom[j]=niz[i];
            j++;
        }
    }
    for(i=0;i<vel;i++){
        if(suma_cifara(niz[i])<k){
            pom[j]=niz[i];
            j++;
        }
    }
    for(i=0;i<vel;i++){
    	niz[i]=pom[i];
    }
}
/*
void zaokruzi1(float niz[],int br_clanova)
{
	int i;
	for(i=0;i<br_clanova;i++)
	{
		if(niz[i]>0)
	niz[i]=(int)(niz[i]*10+0.5)/10.;
		if(niz[i]<0)
	niz[i]=(int)(niz[i]*10-0.5)/10.;
	}
	
}
int zbir_cifara(float broj)
{
        int zbir_cifara;
		int novi_broj=(int)broj*10;
		while(novi_broj!=0)
		{
			zbir_cifara+=novi_broj%10;
			novi_broj/=10;
		}
	return novi_broj;
}
void preslozi(float niz[],int br_clanova,int k)
{
	int i,brojac=0;
	float novi_niz[100];
	for(i=0;i<br_clanova;i++)
	{
	 if(zbir_cifara(niz[i])>=k)
	 {
	 	novi_niz[brojac]=niz[i];
	 	brojac++;
	 }
	 else brojac++;
	}
    for(i=0;i<br_clanova;i++)
    {
     if(zbir_cifara(niz[i])<k)
     {
     	novi_niz[brojac]=niz[i];
	 	brojac++;
     }
     else brojac++;
    }
}*/
int main() {
	int br_clanova=4,k,i;
	float niz[100];
    printf("Unesi clanove niza: ");
    for(i=0;i<br_clanova;i++)
    scanf("%f",&niz[i]);
    printf("Unesi k: ");
    scanf("%d",&k);
    preslozi(niz,br_clanova,k);
    for (i=0; i<br_clanova; i++)
        printf("%g ", niz[i]);
	return 0;
}
