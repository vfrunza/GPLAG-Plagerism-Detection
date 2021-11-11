#include <stdio.h>
#include <math.h>
int main() {
	float uglovi[500];
	float PI = 4*atan(1.), min, sek;
	int n, i, j, step, minu, seku;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	if(n<0 || n>500)
	{
		return 0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%f", &uglovi[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++)
	{
		step=0;
		minu=0;
		seku=0;
	    if(uglovi[i]<0)
		{
			uglovi[i] *= 180/PI;
			uglovi[i]*=-1;
			step= (int) uglovi[i];
			min = (uglovi[i] - step)*60;
			minu = (int)min;
			sek = (min - minu)*60+0.52;
			seku=(int)sek;
			if(seku<0)seku*=-1;
			if(seku>59.5)
			{
				minu++;
				seku-=60;
			}
			if(min>59.5)
			{
				step++;
				minu-=60;
			}
			//printf("%d\n", step);
			//printf("%d\n", minu);
			//printf("%d\n", seku);
			step*=-1;
			if(seku>=31)
			{
				for(j=i;j<n-1;j++)
				{
					uglovi[j] = uglovi[j+1];
				}
				n--;
				i--;
				continue;
			}
			printf("%d stepeni %d minuta %d sekundi\n", step, minu, seku);
		} 
		else
		{
			uglovi[i] *= 180/PI;
		    step = (int) uglovi[i];
		    if(step<0) step*=-1;
		    min = (uglovi[i] - step)*60;
		    minu = (int)min;
		    if(minu<0)minu*=-1;
		    sek = (min - minu)*60+0.51;
		    seku = (int)sek;
		    if(seku<0)seku*=-1;
		    if(min>59.5)
		    {
			    step++;
			    minu-=60;
		    }
		    if(seku>59.5)
		    {
			    minu++;
			    seku-=60;
		    }
		    /*printf("%d\n", step);
			printf("%d\n", minu);
			printf("%d\n", seku);*/
		    if(seku>=31)
		    {
			    for(j=i;j<n-1;j++)
			    {
				    uglovi[j] = uglovi[j+1];
			    }
			    n--;
			    i--;
			    continue;
		    }
		    printf("%d stepeni %d minuta %d sekundi\n", step, minu, seku );
	    }
	}
	return 0;
}
