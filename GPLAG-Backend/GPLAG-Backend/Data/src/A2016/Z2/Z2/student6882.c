#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1415926


int main()
{
    int n;
    double niz[500];
    double ugao;
    int stepeni,minute,sekunde;
    double a,b,c,d;

    printf ("Unesite broj uglova: ");
    scanf("%d",&n);
    int i;
    if( n>0 && n<500)
    {
        for (i=0; i<n; i++)
        {
            scanf ("%lf",&niz[i]);

        }

    }
    printf ("Uglovi su: \n");
    for (i=0; i<n; i++)
    {
        ugao=(niz[i]*(180.0/PI));
        if(ugao<0) ugao= -ugao;
        stepeni=(int)(ugao);
        a=ugao-stepeni;
        b=a*60;
        minute=(int)(b);
        c=b-minute;
        d=c*60;
        if ((d-(int)(d))>=0.5)
            sekunde=(int)(d+0.5);
            else
                sekunde=(int)(d);
                if (sekunde>=59.5)
                {
                sekunde =0;
                minute++;
                 }
                if (minute==60)
                {
                stepeni++;
                minute=0;
                }
                
            //printf("%d %d %d",stepeni,minute,sekunde);
	     if(abs(sekunde)>30 && sekunde!=0) 
		{
		    int j;
			for(j=i;j<n-1;j++)
			{
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}

    }
    
    //ispis
    for (i=0; i<n; i++)
    {
    	int uslov=1;
 		if (niz[i]<0)
    	{
    		uslov=0;
    		niz[i]*=-1;
    	}

        ugao=(niz[i]*(180.0/PI));
        stepeni=(int)(ugao);
        a=ugao-stepeni;
        b=a*60;
        minute=(int)(b);
        c=b-minute;
        d=c*60;
         if ((d-(int)(d))>=0.5)
            sekunde=(int)(d+0.5);
        else
                sekunde=(int)(d);
                if (sekunde>=59.5)
                    {
                    sekunde =0;
                    minute++;
                     }
                if (minute==60)
                {
                stepeni++;
                minute=0;
                }
        if (uslov==1){
        	printf ("%d ",stepeni);
        	printf ("stepeni ");
        	printf ("%d ",minute);
        	printf ("minuta ");
        	printf ("%d ",sekunde);
        	printf ("sekundi\n");
			}
        else if (uslov==0)
        {
        	printf ("-%d ",abs(stepeni));
        printf ("stepeni ");
        printf ("%d ",abs(minute));
        printf ("minuta ");
        printf ("%d ",abs(sekunde));
        printf ("sekundi\n");
        } 


    }


return 0;


}