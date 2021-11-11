#include <stdio.h>

int main() {
	int i,j,m,n,k, da_li_ima, brojac, broj, duzina1,duzina2, duzina3,DA, duzina;
	int A [100][100], B[100][100], C[100][100];
	int a[10000],b[10000], c[10000], niz1[10000], niz2[10000], niz3[10000];
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &n,&m);
	}while(m<0 || m>100 || n<0 || n>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		scanf("%d", &A[i][j]);
	}
	
		printf("Unesite clanove matrice B: ");
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		scanf("%d", &B[i][j]);
	}
	
		printf("Unesite clanove matrice C: ");
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		scanf("%d", &C[i][j]);
	}
	
	
	
	
	k=0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			a[k]=A[i][j];
			b[k]=B[i][j];
			c[k]=C[i][j];
			k++;
		}
	}
	duzina=k;
	k=0;
	
	
/*	printf("\n\n");
	for(i=0; i<duzina; i++) printf("%d", a[i]);
	printf("\n\n");
*/	
	
	
	duzina1=0;
	for(i=0; i<duzina; i++)
	{
		broj=a[i]; brojac=0; da_li_ima=0;
		if(i!=0)
		{
		j=0;
		while(j<duzina1)
		{
			if(broj==niz1[j]) da_li_ima=1;
			j=j+2;
		}
			
		
		/*	for(j=0; j<duzina1; j+2)
			{
				printf("%d jjjjjj  ", j);
			//	printf("\n\n%d\n\n" , niz1[j]);
				if(broj==niz1[j]) da_li_ima=1;
			}*/
		}
		
		if(da_li_ima==0)
		{
			for(j=i; j<duzina; j++) {if(broj==a[j]) brojac++;}
			niz1[k]=broj; niz1[k+1]=brojac; k=k+2; duzina1=duzina1+2;
			
		}
	}
	

	
	duzina2=0; k=0;
	for(i=0; i<n*m; i++)
	{
		broj=b[i]; brojac=0; da_li_ima=0;
		if(i!=0)
		{
			j=0;
			while(j<duzina2)
			{
				if(broj==niz2[j]) da_li_ima=1;
				j=j+2;
			}
		/*	for(j=0; j<duzina2; j+2)
			{
				if(broj==niz2[j]) da_li_ima=1;
			}*/
		}
		if(da_li_ima==0)
		{
			for(j=i; j<duzina; j++) {if(broj==b[j]) brojac++;}
			niz2[k]=broj; niz2[k+1]=brojac; k=k+2; duzina2=duzina2+2;
			
		}
	}
	
	duzina3=0; k=0;
	for(i=0; i<n*m; i++)
	{
		broj=c[i]; brojac=0; da_li_ima=0;
		if(i!=0)
		{
			j=0;
			while(j<duzina3)
			{
				if(broj==niz3[j]) da_li_ima=1;
				j=j+2;
			}
		/*	for(j=0; j<duzina3; j+2)
			{
				if(broj==niz3[j]) da_li_ima=1;
			}*/
		}
		if(da_li_ima==0)
		{
			for(j=i; j<duzina; j++) {if(broj==c[j]) brojac++;}
			niz3[k]=broj; niz3[k+1]=brojac; k=k+2; duzina3=duzina3+2;
			
		}
	}

/*	printf("Duzine %d %d %d \n", duzina1, duzina2, duzina3);
		for(j=0; j<duzina3; j++)
			{
				printf("%d ", niz3[j]);
			
			}*/
	
	if(duzina1!=duzina2 || duzina1!=duzina3) DA=0;
	else
	{
		DA=1;
		
		for(i=0; i<duzina1; i++)
		{
			da_li_ima=0;
			for(j=0; j<duzina1; j++)
			{
				if(niz1[i]==niz2[j])
				{
					da_li_ima=1; 
					if(niz1[i+1]!=niz2[j+1]) DA=0;
				}
				j++;
			}
			
			if(da_li_ima==0 || DA==0) {DA=0; break;}
			i++;
		}
		 
		 
		 if(DA==1)
		 {
		 	for(i=0; i<duzina1; i++) 
			{
				da_li_ima=0;
				for(j=0; j<duzina1; j++) 
				{
					if(niz1[i]==niz3[j])
					{
						da_li_ima=1; 
						if(niz1[i+1]!=niz3[j+1]) DA=0;
					}
					j++;
				}
			
				if(da_li_ima==0 || DA==0) {DA=0; break;}
				i++;
			}
		 }
	} 
	 if(DA==1) printf("DA");
	 else printf("NE");
	
	
	
	return 0;
}
