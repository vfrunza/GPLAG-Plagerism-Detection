#include <stdio.h>

int dva_od_tri(int *nizA,int velA,int *nizB,int velB,int *nizC,int velC)
{
	int i,j,brojaciAB[10]={0},brojaciAC[10]={0},brojaciBC[10]={0},nizAC[100]={0};
	for(i=0;i<velA;i++)
	{
		for(j=0;i<velC;j++)
		{
			if(nizA[i]==nizC[j])
			{
				brojaciAC[i]++;	
			}
		}
	}
	
	for(i=0;i<velA;i++)
	{
		for(j=0;j<velB;j++)
		{
			if(nizA[i]!=nizB[i])
			{
				brojaciAB[i]++;
			}
		}
	}
	
	for(i=0;i<velB;i++)
	{
		for(j=0;j<velC;j++)
		{
			if(nizB[i]!=nizC[i])
			{
				brojaciBC[i]++;
			}
		}
	}
}

int main() 
{
	return 0;
}
