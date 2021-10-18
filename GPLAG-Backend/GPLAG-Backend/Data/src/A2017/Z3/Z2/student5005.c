#include <stdio.h>
#include <math.h>

void zaokruzi1(float P[],int m)
{
	int i;
	for(i=0; i<m; i++)
	P[i]= round(P[i]*10)/10;
}
	void preslozi(float niz[],int m, int k)
	{
		int i,suma=0,f=0,z=0;
		float nizP[1000]= {0},nizR[1000]= {0}, P[1000]= {0};
		if(m==0) return;
		else{
			zaokruzi1(niz,m);
			for(i=0; i<m; i++)
			P[i]=niz[i];
			for(i=0; i<m; i++)
			niz[i]=fabs(niz[i]*10);
			for(i=0; i<m; i++){
				while (niz[i]>0) {
					suma+= ((int)niz[i]%10);
					niz[i]/=10;
				}
					if(suma>k || suma==k){
						nizP[f]=P[i];
						f++;
						
					}
						else{
							nizR[z]=P[i];
							z++;
						}
						suma=0;
					}
				for(i=0; i<f; i++) niz[i]=nizP[i];
				for(i=k; i<(f+z); i++){
					niz[i]=nizR[i-f];
				}
	return ;
		}
}
int main(void)
{ 
	return 0;
	
}  
