#include <stdio.h>

int main() 
{ int N=0, red=0, kolona=0;

	do 
	{ printf ("\nUnesite broj N: ");
		scanf("%d",&N);
		if ((N%4==0) && N>=8)	break;
		else printf ("Neispravno N! ");
	} while (N%4!=0 || N<=7);
	printf ("\n");
	
	for (red=0; red<=N/2-1; red++)
	  {	for (kolona=0; kolona<N/2; kolona++)
			{
				if (red==0 && kolona==0) printf ("\\");
				else if (red!=0 && kolona!=0 && red==kolona) printf ("\\");
				else if (kolona == N/2 - red - 1) printf ("/");
				else  printf (" ");
			}
	  
	  
	  	if (red==0) 
	  	 {for (kolona=N/2; kolona<N; kolona++)
			{ if (kolona == N/2 || kolona == N-1) printf ("+");
				else  printf ("-");
			}
	  	 }	
		 if (red!=0 && red!=N/2-1) 
			{for (kolona=N/2; kolona<N; kolona++)
				{if (kolona==N/2) printf ("|");
				 if (kolona != N/2 && kolona != N-1) printf (" ");
				 if (kolona==N-1) printf ("|");		
				}
				
			}
			
		if (red==(N/2)-1) 
	  	 {for (kolona=N/2; kolona<N; kolona++)
			{  if (kolona == N/2 || kolona == N-1) printf ("+");
				else  printf ("-");
			
			}
	  	 }
			printf ("\n");
	  }
	  	
	  
  for (red=N/2; red<=N-1; red++)
	  {
	     	
	     	if (red==N/2) 
	  	 {for (kolona=0; kolona<N/2; kolona++)
			{ if (kolona == 0 || kolona == N/2-1) printf ("+");
				else  printf ("-");
			}
	  	 }
	     	
	     if (red!=N/2 && red!=N-1) 
			{for (kolona=0; kolona<N/2; kolona++)
				{if (kolona==0) printf ("|");
				 if (kolona != 0 && kolona != N/2-1) printf (" ");
				 if (kolona==N/2-1) printf ("|");		
				}
				
			}	
	     	
	     	if (red==N-1) 
	     	{for (kolona=0; kolona<N/2; kolona++)
			{ if (kolona == 0 || kolona == N/2-1) printf ("+");
				else  printf ("-");
			}
	  	 }
	     
	     
	     if ((red==N/2+N/4) || (red==N/2+(N/4)-1))
	     { for (kolona=N/2; kolona<N; kolona++)
	     	{if (kolona==N/2+N/4 || kolona==N/2+(N/4)-1) printf ("+");
	     	  else printf ("-");
	     	}
	     }	
	     
	     else 
	     { for (kolona=N/2; kolona<N; kolona++)
	     	{if (kolona==N/2+N/4 || kolona==N/2+(N/4)-1) printf ("|");
	     	  else printf (" ");
	     	}
	     }	
	     
	     
	     
	     printf ("\n");	
	     	
	  }
	   
	  
	return 0;
}
