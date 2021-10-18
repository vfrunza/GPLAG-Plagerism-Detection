#include <stdio.h>

int dva_od_tri(int* niz1,int d1,int* niz2,int d2,int* niz3,int d3)
	{   
	    int i,j;
	    int novi[1000];
	    int brojac=0;
	    int jedanodtri=0;
		int dvaodtri=0;
	    
	    for(i=0;i<d1;i++)
	    {
	        for(j=0;j<brojac;j++)
	            if(niz1[i]==novi[j]) break;
	        if(j==brojac) novi[brojac++]=niz1[i];
	     }
	     for(i=0;i<d2;i++)
	    {
	        for(j=0;j<brojac;j++)
	            if(niz2[i]==novi[j]) break;
	        if(j==brojac) novi[brojac++]=niz2[i];
	     }
	      for(i=0;i<d3;i++)
	    {
	        for(j=0;j<brojac;j++)
	            if(niz3[i]==novi[j]) break;
	        if(j==brojac) novi[brojac++]=niz3[i];
	     }
	     
	     for(i=0;i<brojac;i++)
            { jedanodtri=0;
            	for(j=0;j<d1;j++)
            		{
            			if(niz1[j]==novi[i]){jedanodtri++;break;}
            		}
            		for(j=0;j<d2;j++)
            		{
            			if(niz2[j]==novi[i]){jedanodtri++;break;}
            		}
            			for(j=0;j<d3;j++)
            		{
            			if(niz3[j]==novi[i]){jedanodtri++;break;}
            		}
            		if(jedanodtri==2)dvaodtri++;
            		 
            		}
      	return dvaodtri;
           	     
	 }
	   
int main()
{

return 0;
}















