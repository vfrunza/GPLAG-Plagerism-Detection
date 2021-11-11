#include <stdio.h>
#include <math.h>
#define be 500
#define eps 0.0001
#define Pi 3.1415926
int main()
{
	int n, i, j;
	double a[be], deg, min, sec, u, min1, sec1;
	printf("Unesite broj uglova: ");
	scanf("%i", &n);

	while(n<be) {
		printf("Uglovi su: \n");

		for(i=0; i<n; i++) {
			scanf("%lf", &a[i]);
		}

		for(i=0; i<n; i++)

		{
			if(a[i]>=0) {

				sec1=a[i]*(180/Pi)*3600;
				min1=sec1/60;
				u=sec1/3600;
				deg=(int)u;
				min1=min1-(int)u*60;
				min=fabs((int)min1);
				sec1=sec1-min*60-(int)u*3600;
				sec=fabs((int)(sec1+0.5));
				if(deg>0) {
					if(sec>=60) {
						sec=sec-60;
						min=min+1;
					}

					if(min>=60) {
						min=min-60;
						deg=deg+1;

					}
				}


				if(sec>30) {
					for(j=0; j<n; j++) {
						a[j]=a[j+1];
					}
					i--;
					n--;
				} else
					printf("%.0f stepeni %.0f minuta %.0f sekundi\n", deg, min, sec);
			}

			/*Dio ispod je kopirani dio iznad jer je algoritam u sustini isti, pa zbog ustede vremena, lakse ga je kopirati i modificirati odredjene dijelove */
			else if(a[i]<0) {
				a[i]=-a[i];
				sec1=a[i]*(180/Pi)*3600;
				min1=sec1/60;
				u=sec1/3600;
				deg=(int)u;
				min1=min1-(int)u*60;
				min=fabs((int)min1);
				sec1=sec1-min*60-(int)u*3600;
				sec=fabs((int)(sec1+0.5));
				if(deg>0) {
					if(sec>=60) {
						sec=sec-60;
						min=min+1;
					}

					if(min>=60) {
						min=min-60;
						deg=deg+1;

					}
				}

				if(sec>30) {
					for(j=0; j<n; j++) {
						a[j]=a[j+1];
					}
					i--;
					n--;
				} else
					printf("%.0f stepeni %.0f minuta %.0f sekundi\n", -deg, min, sec);
			}



		}
		break;

	}


	return 0;
}