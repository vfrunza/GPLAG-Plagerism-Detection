#include<stdio.h>
int main(){
	int n,i=0,b=0,c,d=0,a=0;
	int niz[1000];
	int nizt[1000];
	int A[1000];
	
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
    printf("Unesite clanove niza: ");
 for(i=0;i<n;i++){
		scanf("%d",&niz[i]);
	}
	for(i=0;i<n;i++){
		if (i==0)a=0;
		else a=b;
		nizt[i]=niz[i];
		do{
			nizt[i]=nizt[i]/10;
			b++;
		}while(nizt[i]!=0);
		c=b-1;
		do{
		A[c]=niz[i]%10;
		niz[i]=niz[i]/10;
		c--;
		
		}	while(c>=a);
		
	}
	printf("Finalni niz glasi:\n");
	for(i=0;i<b;i++){
		printf("%d ",A[i]);
		d=1;
		if(i==b-1);
		else
		{
			while(A[i]==A[i+1]){
				d++;
				i++;
				if (i+1>=b)break;
			}
		}
		if (i==b-1)printf("%d",d);
		else printf("%d ",d);
		

	}

return 0;
}

