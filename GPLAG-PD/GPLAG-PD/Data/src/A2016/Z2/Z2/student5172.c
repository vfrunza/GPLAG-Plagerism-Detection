#include <stdio.h>
#define PI 3.1415926
#include <math.h>


int main()
{
	
	int i,j,intstepen,intminuta,intsekunda,n;
	double niz[500],stepen,minuta,sekunda;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	if(n>0 && n<501)
	{
    for (i=0; i<n; i++)
        {
	        scanf("%lf",&niz[i]);
        }
        printf("Uglovi su: \n");
        
    for(i=0; i<n; i++)
        {
        		stepen = niz[i]*180/PI;
        		intstepen = stepen;
        		minuta = (stepen - intstepen)*60;
        		intminuta = minuta;
        		sekunda = (minuta - intminuta)*60;
        		intsekunda = sekunda;
        		
        	    if(sekunda>0)
        		{
        	     	intsekunda = sekunda+0.5;
        		}
        		if(sekunda<0)
        		{
        		    intsekunda = sekunda-0.5;
        		}
        	    if(intsekunda>30)
        		 {
        		    if(intsekunda==60)
        	     	{
        	     	    intsekunda=0;
        		        intminuta++;
        		        
        		        if(intminuta==60)
        		            {
        		                   intminuta=0;
        		                   intstepen++;
        		                   printf("%d stepeni %d minuta %d sekundi\n",intstepen,intminuta,intsekunda);
        		            }
        		          else 
        		          {
        		              printf("%d stepeni %d minuta 0 sekundi\n",intstepen,intminuta,intsekunda);
        		          }
        	    	}
        	    	
        	    	else if(intsekunda!=60)
        	    	{
        		     for(j=i; j<n-1; j++)
        		     {
        		         niz[j] = niz[j+1];
        		     }
        		     	
        		     n--;
        		     i--;
        	    	}
        		}
         	   else	if(intsekunda<-30)
        		 {
        		    if(intsekunda==-60)
        	     	{
        	     	    intsekunda=0;
        		        intminuta--;
        		 
        		        
        		        if(intminuta==-60)
        		            {
        		                   intminuta=0;
        		                   intstepen--;
        		                   printf("%d stepeni %d minuta %d sekundi\n",intstepen,intminuta,intsekunda);
        		            }
        	    	}
        	    	
        	    	else if(intsekunda!=-60)
        	    	{
        		     for(j=i; j<n-1; j++)
        		     {
        		         niz[j] = niz[j+1];
        		     }
        		     	
        		     n--;
        		     i--;
        	    	}
        		}
        		else if (intsekunda>=-30 && intsekunda<=30)
        		{
        		    intsekunda = fabs(intsekunda);
        		    intminuta = fabs(intminuta);
                 	printf("%d stepeni %d minuta %d sekundi\n",intstepen,intminuta,intsekunda);
        		}
        }
	}    		
        		return 0;
}

