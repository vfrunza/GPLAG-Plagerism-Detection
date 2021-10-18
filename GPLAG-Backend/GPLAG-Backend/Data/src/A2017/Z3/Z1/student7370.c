#include <stdio.h>

int dva_od_tri(int niz1[], int v1, int niz2[], int v2, int niz3[], int v3)
{
	int i,j,k,c,l,br,rez ,da,niz33, niz22;
	int n[100];
	l=0; rez=0; k=0; da=0; i=0; j=0;
	niz33=0; niz22=0; c=0; br=0;
	do
	{
		da=0;
		while(j<l)
		{
			if(n[j]==niz1[i])
			da=1;
			j++;
		}
		j=0;
		if(da==0 && v1>0)
		{
			n[k]=niz1[i];
			k++;
			l++;
		}
		
		if(niz22==0)
		{
			niz22=1;
			while(c<v2)
			{
				da=0; 
				while(j<l)
				{
					if(n[j]==niz2[c])
					da=1;
					j++;
				}
				j=0;
				if(da==0 && v2>0)
				{
					n[k]=niz2[c];
					k++;
					l++;
				}
				c++;
			}
		}
		
		c=0;
		if(niz33==0)
		{
			niz33=1;
			while(c<v3)
			{
				da=0;
				while(j<l)
				{
					if(n[j]==niz3[c])
					da=1;
					j++;
				}
				j=0;
				if(da==0 && v3>0)
				{
					n[k]=niz3[c];
					k++;
					l++;
				}
				c++;
			}
		}
		
		
		i++;
		j=0;
	}while(i<v1 );
	
	
	i=0;
	
	while(i<l)
	{
		br=0; j=0;
		
		while(j<v1)
		{
			if(n[i]==niz1[j])
			{
				br++; 
				break;
			}
			j++;
			
		}
		j=0;
		
		while(j<v2)
		{
			if(n[i]==niz2[j])
			{
				br++; 
				break;
			}
			j++;
		}
		j=0;
		
		while(j<v3)
		{
			if(n[i]==niz3[j])
			{
				br++; 
				break;
			}
			j++;
		}
		
		if(br==2) rez++;
	i++;	
	}
	return rez;
	
}



/*
int dva_od_tri(int niz1[], int v1, int niz2[], int v2, int niz3[], int v3)
{
	int rez;
	int i,j,k,c;
	int br[300]={0};
	int brojevi[300];
	k=v1;
	
	v1=sizeof(niz1)/sizeof(int);
	v2=sizeof(niz2)/sizeof(int);
	v3=sizeof(niz3)/sizeof(int);
	



	

	int ima=0;
	if(v1>=v2 && v1>=v3) {
	for(j=0; j<v1; j++)
	{
		
	
		
		for(i=0; i<v2;i++)
		{
			for(k=0; k<v3; k++)
			{
				
				if(niz1[j]==niz2[i] && niz1[j]!=niz3[k] && ima==0) {rez++;br[i]==niz1[j]; break;}
				else if (niz1[j]==niz3[k] && niz1[j]!=niz2[i]) {rez++;br[i]==niz1[j]; break;}
			}
		}
	}
	}
		rez=0;
	for(i=0; i<v1; i++) {
		if(br[i]==2)
			rez++;
	}





	if(v2>=v1 && v2>=v3){
	for(i=0; i<v2; i++)
	{
		
		
		
		for(j=0; j<v1;j++)
		{
			for(k=0; k<v3; k++)
			{
				
				if(niz2[i]==niz1[j] && niz2[i]!=niz3[k] && ima==0) {rez++;br[i]==niz2[i]; break;}
				else if (niz2[i]==niz3[k] && niz2[i]!=niz1[j]) {rez++;br[i]==niz2[i]; break;}
			}
		}
	}
	}
		rez=0;
	for(i=0; i<v2; i++) {
		if(br[i]==2)
			rez++;
	}


	

	
	if(v3>=v2 && v3>=v1) {
	for(k=0; k<v3; k++)
	{
		
		
		
		for(i=0; i<v2;i++)
		{
			for(j=0; j<v1; j++)
			{
			
				if(niz3[k]==niz2[i] && niz3[k]!=niz1[j] && ima==0) {rez++;br[i]==niz3[k]; break;}
				else if (niz3[k]==niz1[j] && niz3[k]!=niz2[i]) {rez++;br[i]==niz3[k]; break;}
			}
		}
	}
	}
	
	
	rez=0;
	for(k=0; k<v3; k++) {
		if(br[i]==2)
			rez++;
	}


	return rez;
}
*/
int main()
{
	
	
int niz1[] = {1, 2, 3, 4};
int niz2[] = {2, 3, 4, 5};
int niz3[] = {3, 4, 5, 6};
int niz4[1];
int rez = dva_od_tri(niz1, 4, niz2, 4, niz4, 0);
printf("%d ", rez);
rez = dva_od_tri(niz1, 4, niz4, 0, niz3, 4);
printf("%d ", rez);
rez = dva_od_tri(niz4, 0, niz2, 4, niz3, 4);
printf("%d ", rez);
rez = dva_od_tri(niz1, 4, niz2, 4, niz3, 4);
printf("%d ", rez);
	
	
	return 0;
}



