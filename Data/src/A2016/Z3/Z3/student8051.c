#include <stdio.h>



int main() {
    int a[200][200],m,n,i,j;
    //Preko do-while petlje osiguravam unos brojeva u trazenom opsegu...
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&m,&n);
        if(n<=0||n>200||m<=0||m>200)
        {
            printf("Brojevi nisu u trazenom opsegu.\n");
        }
    }while(n<=0||n>200||m<=0||m>200);
    
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	    for(j=0;j<n;j++)
	        scanf("%d",&a[i][j]);
	
	int logik=0,k,q;
	//logik je ustvari logicka varijabla koja nam govori da li su uporedjeni elementi jednaki. Ona ce biti 1 ukoliko nisu, a 0 ukoliko jesu.
	for(i=1;i<m;i++)
	{
	    for(k=0;k<i;k++)
	   {
	   		//Ovdje i petlja ide od 1 do m-1 (ubrajajuci i m-1), dok k ide od 0 do i-1 (ubrajajuci i-1). 
	   		//Odnosno, ovdje se uporedjuju donji redovi sa gornjim. Ukoliko su jednaki, taj "donji" red se izbacuje.
	        logik=0;
	        for(j=0;j<n;j++)
	        {
	           if(a[i][j]!=a[k][j])
	           {
	               logik=1;
	               break;
	           }
	        }
	        //Ukoliko logicka varijabla je jednaka 0, to znaci da su uporedjivani elementi isti, odnosno da je red "i" i red "k" jednaki.
	        if(logik==0){
	        	//Izbacivanje tog "duplikata" iz matrice...
	            for(q=i;q<m-1;q++)
	            {
	                for(j=0;j<n;j++)
	                {
	                    a[q][j]=a[q+1][j];
	                }
	            }
	            m--;
	            i--;
	        }
	   }
	
	}
	//Naime, ovdje se koristi potpuna ista taktika kao u kodu iznad za provjeravanje redova, samo su ovdje kolone.
	//I ukoliko su 2 kolone jednake, ona koja je "desnija", ta se izbacuje.
	for(j=1;j<n;j++)
	{
		for(k=0;k<j;k++)
		{
			logik=0;
			for(i=0;i<m;i++)
			{
				if(a[i][j]!=a[i][k])
				{
					logik=1;
					break;
				}
			}
			if(logik==0)
			{
				for(q=j;q<n-1;q++)
				{
					for(i=0;i<m;i++)
						a[i][q]=a[i][q+1];
				}
				j--;
				n--;
			}
			
		}
	}
	
	//I na kraj ispisivanje krajnje matrice i to je to :)
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<m;i++){
		printf(" ");
	    for(j=0;j<n;j++)
	        {
	            printf("%4d ",a[i][j]);
	        }
	        printf("\n");
	}
	return 0;
}
