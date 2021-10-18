#include <stdio.h>

#define EPS 0.0001


struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float DajProsjek(struct Student s)
{
 	float f=0;
 	int i;
 	    
 	    if(s.br_ocjena==0) return 5;
 	    
 		for(i=0;i<s.br_ocjena;i++)
 		{  
 			if (s.ocjene[i]!=5) f+=s.ocjene[i];
 			else return 5;
 		}
 		
 		
 		
 	return f/s.br_ocjena;
}


int IspitajString(char *x,char *y)
{
	char *p=x;
	char *q=y;
	
	
		while(*p!='\0' || *q!='\0')
		{
			if(*p++!=*q++) return p-x;
		}
		
	return -1;
}



int genijalci(struct Student *studenti,int vel,float prosjek)
{
	int i,j,b1,b2;
	int ind1=0,ind2=0,ind3=0;
	float max=DajProsjek(studenti[0]),max2=DajProsjek(studenti[0]);
	
	for(i=0;i<vel;i++)
	{
		if(DajProsjek(studenti[i])<prosjek)
		{
			for(j=i;j<vel-1;j++)
				studenti[j]=studenti[j+1];
			vel--;
			i--;
		}
	}

	max=DajProsjek(studenti[0]);
	max2=DajProsjek(studenti[0]);		
	
	for(i=1;i<vel;i++)
	{
		b1=IspitajString(studenti[i].ime,studenti[ind1].ime);
		b2=IspitajString(studenti[i].prezime,studenti[ind1].prezime);
		
		if(DajProsjek(studenti[i])>max){max=DajProsjek(studenti[i]);ind1=i;}
		else if(DajProsjek(studenti[i])==DajProsjek(studenti[ind1])&& b1!=-1 && studenti[i].ime[b1]<studenti[ind1].ime[b1]){ind1=i;}
		else if(DajProsjek(studenti[i])==DajProsjek(studenti[ind1])&& b2!=-1 && studenti[i].prezime[b2]<studenti[ind1].prezime[b2]){ind1=i;}
		else if(b1==-1 && b2==-1) ind1=i;
		
	}
	
	for(i=1;i<vel;i++)
	{   
		b1=IspitajString(studenti[i].ime,studenti[ind2].ime);
		b2=IspitajString(studenti[i].prezime,studenti[ind2].prezime);
	
		if(DajProsjek(studenti[i])<max && i!=ind1 ){max2=DajProsjek(studenti[i]);ind2=i;}
		else if(DajProsjek(studenti[i])==DajProsjek(studenti[ind2]) && i!=ind1 && b1!=-1 && studenti[i].ime[b1]<studenti[ind2].ime[b1]){ind2=i;}
		else if(DajProsjek(studenti[i])==DajProsjek(studenti[ind2]) && i!=ind1 && b2!=-1 && studenti[i].prezime[b2]<studenti[ind2].prezime[b2]){ind2=i;}
		else if(b1==-1 && b2==-1 && i!=ind1) ind2=i;
		
	}
	
	for(i=1;i<vel;i++)
	{   
		
			b1=IspitajString(studenti[i].ime,studenti[ind3].ime);
			b2=IspitajString(studenti[i].prezime,studenti[ind3].prezime);
		
			if(DajProsjek(studenti[i])<max2 && i!=ind2 && i!=ind1){ind3=i;}
			else if(DajProsjek(studenti[i])==DajProsjek(studenti[ind3]) && i!=ind2 && b1!=-1 &&  i!=ind1 && studenti[i].ime[b1]<studenti[ind3].ime[b1]){ind3=i;}
			else if(DajProsjek(studenti[i])==DajProsjek(studenti[ind3]) && i!=ind2 && b2!=-1 && i!=ind1 && studenti[i].prezime[b2]<studenti[ind3].prezime[b2]){ind3=i;}
			else if(b1==-1 && b2==-1 && i!=ind2) ind3=i;
	}

	
	if (vel!=0)
	{
		if(ind1!=ind2 && ind1!=ind3 && ind2!=ind3)
		{	
			printf("%s %s\n",studenti[ind1].prezime,studenti[ind1].ime);
			printf("%s %s\n",studenti[ind2].prezime,studenti[ind2].ime);
			printf("%s %s\n",studenti[ind3].prezime,studenti[ind3].ime);
		}
		else if(ind1==ind2 && ind2==ind3 && ind1==ind3)
		{
			printf("%s %s\n",studenti[ind1].prezime,studenti[ind1].ime);
		}
		else if(ind1!=ind2 && ind3==0)
		{
			printf("%s %s\n",studenti[ind1].prezime,studenti[ind1].ime);
			printf("%s %s\n",studenti[ind2].prezime,studenti[ind2].ime);
		}
		else return vel ;
	}	
	return vel;
}



int main() {
/* AT7: Test izbacivanja + samo dva studenta ispunjavaju uslov */
struct Student studenti[3] = {
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8}, 29}, 
	{ "Fata", "Fatic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, 29}, 
};
genijalci(studenti, 3, 7.0);
	return 0;
}
