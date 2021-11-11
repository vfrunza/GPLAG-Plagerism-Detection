#include <stdio.h>
 
int main()
{
   int koordinate[20],broj,i=0,j=0,k,temp,temp2=0;
   do {
   	if(i>0) printf("Pogresan unos\n");
   	printf("Unesite broj tacaka: ");
   	scanf("%d",&broj);
   	i++;
   }while(broj<=0||broj>10);
   i=0;
   while(i<broj){
   	printf("Unesite %d. tacku: ",i+1);
   	scanf("%d %d",&koordinate[j],&koordinate[j+1]);
   	if (koordinate[j+1] > 19 || koordinate[j] < 0 || koordinate[j+1] < 0 || koordinate[j] > 19)
   	{
   		printf("Pogresan unos\n");
   		j-=2;
   		i--;
   	}
   	j+=2;
   	i++;
   }
   i=0;
   while(i<20){
   	j=0;
   	while(j<20){
   		temp=0;
   		temp2=0;
   		k=0;
   		while(k<broj){
   			if(koordinate[temp]==j && koordinate[temp+1]==i)
   			{
   				printf("*");
   				temp2++;
   				break;
   			}
   		temp+=2;
   		k++;
   		}
   		if(temp2==0) printf(" ");
   		j++;
   	}
   	printf("\n");
   	i++;
   }
    return 0;
}