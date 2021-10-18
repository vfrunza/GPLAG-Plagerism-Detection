#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)

{
	
int brmatp[1000]={}, brmatn[1000]={};
int pom[1000]={},pomi[1000]={};
int broj, maxbr, p,n,br,in;
int i,j;

for(i=0;i<visina;i++)
{
	for(j=0;j<sirina;j++)
	{
		if (matrica[i][j]>=0)
                	brmatp[matrica[i][j]]++;
                else
                    brmatn[(matrica[i][j]*(-1))]++;
    }
	
}
maxbr=brmatp[0];
broj=0;
br=0;

for(p=1;p<1000;p++)
{
	
if(maxbr<brmatp[p])
{
maxbr=brmatp[p];
broj=p;
	
}

if(maxbr==brmatp[p]){
	
	pomi[in]=broj;

pomi[in+1]=p;
in=in+2;
 }

if(in>1)
{
	for(prolaz=0;prolaz<in;in++)
	
}
	
}


}


int main() {
	printf("Zadaća 3, Zadatak 4");
	return 0;
}
