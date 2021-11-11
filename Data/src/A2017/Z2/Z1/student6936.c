#include <stdio.h>

int main() {
	int n;
	int i,j;
	int jp=0, ip=0;
	do
	{
		printf ("Unesite broj N: ");
		scanf ("%d", &n);
		if (n%4!=0 || n<8)
		printf ("Neispravno N!\n");
	}
	while (n%4!=0 || n<8);
	printf ("\n");
	for (i=0; i<(n/2); i++)
	{
		for (j=0; j<n; j++)
		{
			if (j<(n/2))
			{
				if (i==j) printf ("\\");
				else if (j+i==(n/2)-1)
				printf ("/");
				else printf (" ");
			}
			if (j>=(n/2))
			{
				jp=j-(n/2);
				if ((i==0 && jp==((n/2)-1)) || (i==0 && jp==0) || (i==((n/2)-1) && jp==0) || (i==((n/2)-1) && jp==((n/2)-1))) printf ("+");
				else if (i==0 || i==((n/2)-1)) printf ("-");
				else if (jp==0 || jp==((n/2)-1)) printf ("|");
				else printf (" ");
				
			}
		}
		printf ("\n");
		
	}
	for (i=0;i<(n/2);i++)
	{
		for (j=0;j<n; j++)
		{
			
			if (j<(n/2))
			{
				jp=j;
				if ((i==0 && jp==((n/2)-1)) || (i==0 && jp==0) || (i==((n/2)-1) && jp==0) || (i==((n/2)-1) && jp==((n/2)-1) )) printf ("+");
				else if (i==0 || i==((n/2)-1)) printf ("-");
				else if (jp==0 || jp==((n/2)-1)) printf ("|");
				else printf (" ");
			}
			if (j>=(n/2))
			{
				jp=j-(n/2);
				ip=i;
				if ((jp<((n/4)-1) || jp>(n/4)) && (ip<((n/4)-1) || ip>(n/4))) printf (" ");
				if ((jp==((n/4)-1) || jp== (n/4)) && (ip< ((n/4)-1) || ip >(n/4))) printf ("|");
				if ((jp<((n/4)-1) || jp>(n/4)) && (ip== ((n/4)-1) || ip == (n/4))) printf ("-");
				if ((jp== ((n/4)-1) || jp== (n/4)) && (ip==((n/4)-1) || ip==(n/4))) printf ("+");
				
			}
			}
			printf ("\n");
		}
		return 0;
	}
