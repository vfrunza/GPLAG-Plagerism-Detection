#include <stdio.h>
int prebroji(int matrica[100][100], int visina, int sirina,int broj)
{
    int brojac=0,i,j;
    for(i=0;i<visina;i++)
    {
    for(j=0;j<sirina;j++)                       // funkcija broji koliko se puta broj ponovio u matrici
    {
        if(matrica[i][j]==broj)
        brojac++;
            
        }}
  return brojac;      
}



int max(int matrica[100][100], int visina, int sirina)
{
    int i,j;
    int indeks=0;
    int indeks1=0;
    int brojac=0;
    int brojacmax=0;
    for(i=0;i<visina;i++)
    {
    for(j=0;j<sirina;j++)
    {
     
    
           brojac=prebroji(matrica,visina,sirina,matrica[i][j]);
            if(brojac>brojacmax)
            {
                brojacmax=brojac;                                         
                indeks=i;                                              // funkcija trazi maksimalni brojac i vraca odgovarajuci element 
                indeks1=j;
                
            }
            if(brojac==brojacmax && matrica[i][j]<matrica[indeks][indeks1])
            {
               indeks=i;
                indeks1=j; 
                
            }    
    }
    }
    
       
  return matrica[indeks][indeks1];  
}



void preslozi(int matrica[100][100], int visina, int sirina,int a,int b)
{
	int i,j;
	for(i=a;i<visina;i++)
	{
		for(j=b;j<sirina-1;j++)                             //pomocna funkcija koja prepisuje elemente kolona
		{
			matrica[i][j]=matrica[i][j+1];      
			
		}
		
		
	}
	
	
}



int izbaci_kolone(int matrica[100][100], int visina, int sirina,int n)
{
	int i,j;
	for(i=0;i<visina;i++)
	{
		for(j=0;j<sirina;j++)
		{                                                  
		if(matrica[i][j]==n)                                   //funkcija poziva pomocnu fukciju preslozi i smanjuje broj kolona 
		{
		preslozi(matrica,visina,sirina,i,j);
		sirina--;
		j--;
			
		}
		
			
		}
		
		
	}
	
	
	
	
	
	
	
return sirina;	
}
void ispisi( int matrica[100][100],int visina,int sirina)
{
    int i,j;
    for(i=0;i<visina;i++)
    {
       for(j=0;j<sirina;j++){                      //pomocna funkcija za ispis matrice 
        printf("%5d",matrica[i][j]);
       }
    
    printf("\n");
    }

    
}


int main()
{
    int matrica[100][100];
    int brojac=0;
 int sirina,visina,i,j,k;   
printf("Unesite sirinu i visinu matrice: "); 
scanf("%d%d",&sirina,&visina);

for(i=0;i<visina;i++)
{
printf("Unesite elemente %d. reda: ",i+1);
for(j=0;j<sirina;j++)
{
scanf("%d",&matrica[i][j]);

}
} 
k=sirina;
k=izbaci_kolone(matrica,visina,k,max(matrica,visina,k));
printf("\n");
while(k!=0){
printf("Nakon %d. prolaza matrica glasi:\n",brojac+1);
ispisi(matrica,visina,k);
k=izbaci_kolone(matrica,visina,k,max(matrica,visina,k));
 brojac++;
} 
printf("Nakon %d. prolaza matrica je prazna!",brojac+1);
 
    
    return 0;
}






















    
    
    
    






