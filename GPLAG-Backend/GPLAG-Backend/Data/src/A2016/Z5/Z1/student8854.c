#include <stdio.h>
#include <math.h>
#define eps 0.001
struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student studenti[],int vel,float prosjek)
{

	int kec=0,dvica=0,trica=0;
	float max1,max2,max3;
	int i=0,j=0,k=0,l=0;
	float pros=5;
	int suma=0;
	int t;
char* p;
char* q;
char* r;
int logik;
	for(i=0; i<vel; i++) 
	{
		pros=0;
		suma=0;
		j=0;
		while(j<studenti[i].br_ocjena) 
		{
			if(studenti[i].ocjene[j]==5) 
			{
				pros=5;
				break;
			}


			suma=suma+studenti[i].ocjene[j];
			j++;

		}

		if(j==0)
			pros=5;

		if(pros==0 && j!=0)
			pros=(float)suma/j;
		if(prosjek-pros>eps)
		{

			for(k=i; k<vel-1; k++)
			{
				studenti[k]=studenti[k+1];

			}
			vel--;
			i--;


		} 
		else
		{
			if(i==0)
			{
				max1=pros;
				max2=pros;
				max3=pros;
				
			}
			
			if(pros>max1)
			{
				trica=dvica;
				dvica=kec;
				kec=i;
				max3=max2;
				max2=max1;
				max1=pros;
				continue;
			} else
			{
				if(pros>max2 && pros<max1) 
				{
					trica=dvica;
					dvica=i;
					max3=max2;
					max2=pros;
					continue;

				} else 
				{
					if(pros>max3 && pros<max2) 
					{
						trica=i;
						max3=pros;
						continue;
					}
					else
					{
						if(pros==max1)
						{
							trica=dvica;
							max3=max2;
							t=0;
							while(studenti[kec].prezime[t]==studenti[i].prezime[t] && studenti[kec].prezime[t]!='\0' && studenti[i].prezime[t]!='\0' )
							{
								t++;
							}
							if(studenti[kec].prezime[t]=='\0' && studenti[i].prezime[t]=='\0')
							{
								t=0;
								while(studenti[kec].ime[t]==studenti[i].ime[t] && studenti[kec].ime[t]!='\0' && studenti[i].ime[t]!='\0')
							{
								t++;
							}
							
								if(studenti[i].ime[t]=='\0' && ((studenti[kec].ime[t]>='a' && studenti[kec].ime[t]<='z') || (studenti[kec].ime[t]>='A' && studenti[kec].ime[t]<='Z')))          
							{
							dvica=kec;
							kec=i;
							max2=max1;
							max1=pros;
								
								
							}	
							if(studenti[i].ime[t]<studenti[kec].ime[t] && studenti[kec].ime[t]!='\0' && studenti[i].ime[t]!='\0')
							{
							dvica=kec;
							kec=i;
							max2=max1;
							max1=pros;
									
							}		
								
							}
							if(studenti[kec].prezime[t]=='\0' && ((studenti[i].prezime[t]>='a' && studenti[i].prezime[t]<='z') || (studenti[i].prezime[t]>='A' && studenti[i].prezime[t]<='Z')))          
							{
								
								
								
							}
							if(studenti[i].prezime[t]=='\0' && ((studenti[kec].prezime[t]>='a' && studenti[kec].prezime[t]<='z') || (studenti[kec].prezime[t]>='A' && studenti[kec].prezime[t]<='Z')))          
							{
							dvica=kec;
							kec=i;
							max2=max1;
							max1=pros;
								
								
							}
							if(studenti[i].prezime[t]<studenti[kec].prezime[t] && studenti[kec].prezime[t]!='\0' && studenti[i].prezime[t]!='\0')
							{
							dvica=kec;
							kec=i;
							max2=max1;
							max1=pros;
									
							}
							
							
						continue;	
						}
						else
						{
							if(pros==max2)
						{
							
							t=0;
							while(studenti[dvica].prezime[t]==studenti[i].prezime[t] && studenti[kec].prezime[t]!='\0' && studenti[i].prezime[t]!='\0')
							{
								t++;
							}
							if(studenti[dvica].prezime[t]=='\0' && studenti[i].prezime[t]=='\0')
							{
								t=0;
								while(studenti[dvica].ime[t]==studenti[i].ime[t] && studenti[dvica].ime[t]!='\0' && studenti[i].ime[t]!='\0')
							{
								t++;
							}
							
								if(studenti[i].ime[t]=='\0' && ((studenti[dvica].ime[t]>='a' && studenti[dvica].ime[t]<='z') || (studenti[dvica].ime[t]>='A' && studenti[dvica].ime[t]<='Z')))          
							{
							trica=dvica;
							max3=max2;
							dvica=i;
							max2=pros;
								
								
							}	
							if(studenti[i].ime[t]<studenti[dvica].ime[t] && studenti[dvica].ime[t]!='\0' && studenti[i].ime[t]!='\0')
							{
							trica=dvica;
							max3=max2;
							dvica=i;
							max2=pros;
									
							}		
								
							}
							if(studenti[dvica].prezime[t]=='\0' && ((studenti[i].prezime[t]>='a' && studenti[i].prezime[t]<='z') || (studenti[i].prezime[t]>='A' && studenti[i].prezime[t]<='Z')))          
							{
								
								
								
							}
							if(studenti[i].prezime[t]=='\0' && ((studenti[dvica].prezime[t]>='a' && studenti[dvica].prezime[t]<='z') || (studenti[dvica].prezime[t]>='A' && studenti[dvica].prezime[t]<='Z')))          
							{
							trica=dvica;
							max3=max2;
							dvica=i;
							max2=pros;
								
								
							}
							if(studenti[i].prezime[t]<studenti[dvica].prezime[t] && studenti[dvica].prezime[t]!='\0' && studenti[i].prezime[t]!='\0')
							{
							trica=dvica;
							max3=max2;
							dvica=i;
							max2=pros;
									
							}
							
							
							
						continue;	
						}
						else
						{
							if(pros==max3)
						{
							
							t=0;
							while(studenti[trica].prezime[t]==studenti[i].prezime[t] && studenti[trica].prezime[t]!='\0' && studenti[i].prezime[t]!='\0')
							{
								t++;
							}
							if(studenti[trica].prezime[t]=='\0' && studenti[i].prezime[t]=='\0')
							{
								t=0;
								while(studenti[trica].ime[t]==studenti[i].ime[t] && studenti[trica].ime[t]!='\0' && studenti[i].ime[t]!='\0')
							{
								t++;
							}
							
								if(studenti[i].ime[t]=='\0' && ((studenti[trica].ime[t]>='a' && studenti[trica].ime[t]<='z') || (studenti[trica].ime[t]>='A' && studenti[trica].ime[t]<='Z')))          
							{
							trica=i;
							max3=pros;
							
								
								
							}	
							if(studenti[i].ime[t]<studenti[trica].ime[t] && studenti[trica].ime[t]!='\0' && studenti[i].ime[t]!='\0')
							{
							trica=i;
							max3=pros;
									
							}		
								
							}
							if(studenti[trica].prezime[t]=='\0' && ((studenti[i].prezime[t]>='a' && studenti[i].prezime[t]<='z') || (studenti[i].prezime[t]>='A' && studenti[i].prezime[t]<='Z')))          
							{
								
								
								
							}
							if(studenti[i].prezime[t]=='\0' && ((studenti[trica].prezime[t]>='a' && studenti[trica].prezime[t]<='z') || (studenti[trica].prezime[t]>='A' && studenti[trica].prezime[t]<='Z')))          
							{
							trica=dvica;
							max3=max2;
							
								
							}
							if(studenti[i].prezime[t]<studenti[trica].prezime[t] && studenti[trica].prezime[t]!='\0' && studenti[i].prezime[t]!='\0')
							{
							trica=i;
							max3=pros;
									
							}
							
							
							
						continue;	
						}
						}
						}
					}
				










				}
			}
		}










	}










if(vel>=1)
printf("%s %s\n",studenti[kec].prezime,studenti[kec].ime);
if(vel>=2)
	printf("%s %s\n",studenti[dvica].prezime,studenti[dvica].ime);
if(vel>=3)
	printf("%s %s\n",studenti[trica].prezime,studenti[trica].ime);
	

	return vel;
}


int main()
{


	struct Student studenti[20];


	return 0;
}





