#include <stdio.h>


int main() {  
	int a,i,tacx[10],tacy[10],y,x,s,b,j,k,f,y1,x1,c,d,temp;
	lul:
	printf("Unesite broj tacaka: ");                                                                  
	scanf("%d", &a);
	if (a>10 || a<=0){
	printf("Pogresan unos\n");
	goto lul;
		
	}
for(i = 0; i < a; i++)
	{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d", &tacx[i],&tacy[i]);
		if(tacx[i]<0 || tacx[i]>=20 || tacy[i]<0 || tacy[i]>=20){
		printf("Pogresan unos\n");
		i--;
		}
	}
//deleting duplicates
for (b=0;b<a-1;b++)
{
	if (tacx[b]==tacx[b+1] && tacy[b]==tacy[b+1])
	{
		for (j=b;j<a-1;j++){
			tacx[j] = tacx[j+1];
			tacy[j] = tacy[j+1];
		}
		b--;
		a--;
	}
}
for(f=0;f<a-1;f++)
	for(k=a-1;k>f;k--)
	{
		if(tacx[f]==tacx[k] && tacy[f]==tacy[k])
		a--;
	}
//end of deleting duplicates

//sorting (gachi) (gachiGASM)
for(c=0;c<a;c++)
	for(d=a-1;d>c;d--)
{
	if(tacy[c]==tacy[d] && tacx[c]>tacx[d])
	{
		temp=tacx[c];
		tacx[c]=tacx[d];
		tacx[d]=temp;
	}
	
}
//end of sorting

//drawing
for(y=0;y<20;y++){
	x=0;
		for(s=0;s<a;s++)
		{
			
			if(y==tacy[s])
			{
				
				for(;x<tacx[s];x++){
				printf(" ");
				}
				x+=1;
				printf("*");
				
			}
		}
		printf("\n");
}
	
	return 0;
}