#include <stdio.h>

int main() {
	
	int  N;
	do {
		printf("Unesite broj N: ");
	     scanf("%d", &N);
		if (N % 4 != 0 || N < 8) printf("Neispravno N! \n");
		else printf ("\n");
     	} while(N % 4 != 0 || N < 8);
     	
     // vanjska petlja
     int i, j, k;
     for(i = 0; i < N/2; i++)
     	{
     		for ( j = 0; j < N; j++)
			{
				if (i == j) printf ("%c", 92);


				else if (j == N / 2 - 1 - i) printf ("/");
				else if ( (j == N / 2 || j == N - 1) && i != 0 && i != N/2 - 1) printf ("|");
				else if ( (i == 0 || i == N/2 - 1 ) && j > N/2 - 1)
				{
				for (k = 0; k < N / 2; k++)
					{
						if (k == 0 || k == N/2 - 1) printf ("+");
						else printf ("-");
					}
				break;
				}
				else printf (" ");
				
			}
			printf ("\n");
     	}

   for (i = N/2; i < N; i++)
     	{
     		for ( j = 0; j < N; j++)
			{
				if (i == N/2 || i == N - 1)
					{
						if (j == 0 || j == N / 2 - 1) printf ("+");
						else if (j > 0 && j < N / 2 - 1) printf ("-");
						else if (j == (N/2 + N/4 - 1) || j == (N/2 + N/4)) printf ("|");
						else printf(" ");
					}
				else if(i== N/2+N/4-1 || i == N/2 + N/4) {
				    if (j == 0 || j == N/2 - 1) printf ("|");
				    //else if(j == N/2  || j == N-1 || j== N/2 + 1 || j == N/2 + N/4 + 1 || j== N/2 - 1 ) printf("-");
				    else if (j == (N/2 + N/4 - 1) || j == (N/2 + N/4)) printf ("+");
				    else if((i== N/2+N/4-1 || i == N/2 + N/4) && j >= N / 2) printf("-"); 
				    else printf (" ");
				}
				else if((i!= N/2+N/4-1) && (i != N/2 + N/4)) {
				    if (j == 0 || j == N/2 - 1 || j == (N/2 + N/4 - 1) || j == (N/2 + N/4)) printf ("|");
				    else printf(" ");
				}
	/*for(i = N / 2 + 1; i < N-1 ; i++) {
	    for(j = N/2; j < N ; j++) {
	        if(i== N/2+N/4-1 || i == N/2 + N/4) {
	            if(j==)
	        }
	    }
	}
				else if (i > N / 2 || i < N - 1)
					{
						if (j == 0 || j == N/2 - 1) printf ("|");
						else if (j == (N/2 + N/4 - 1) || j == (N/2 + N/4)) printf ("+");
						//|| j == N/2 + N/4 || j == N/2 + N/4 - 1) printf ("|");
						else if(j == N/2  || j == N-1) printf("-");
						else printf (" ");
					}
				/*else if (j > N/2 - 1 && (i == N/4 || i == N/4 - 1))
					{
						if (j == N - 1) printf ("-");
						if (j > N/2 - 1 && j < N/2 + N/4 - 1 || j > N/2 + N/4 + 1 ) printf ("-");
						else if (j == N/2 + N/4 || j == N/2 + N/4 + 1) printf ("+");
						//else if (j > N/2 + N/4) printf ("-");
					}*/
				else printf (" ");
			}
			printf ("\n");
     	}
    
  
	return 0;
}