#include <stdio.h>
#include <math.h>
struct Student{
    char ime[20], prezime[20];
    int ocjene[50];
    int br_ocjena;
};
int genijalci(struct Student *studendi, int vel, float prosjekat)
{
    int i, j, prvi, drugi=0, treci=0, i1, i2, i3, padavica=0;
    float suma_ocjena=0;
    float prosjek_studenta=0;
    float prosjeci[10];
    float max1=0, max2=0, max3=0;
    const float omlda=0.0001;
    for(i=0;i<vel;i++)
    {
        suma_ocjena=0;
        prvi=0;
        if(studendi[i].br_ocjena==0)
        {
            for(j=i;j<vel-1;j++)
            {
                studendi[j]=studendi[j+1];
                prosjeci[j]=prosjeci[j+1];
            }
            i--;
            if(i==-1)i=0;
            vel--;
        }
        for(j=0;j<studendi[i].br_ocjena;j++)
        {
            padavica=0;
            if(studendi[i].ocjene[j]==5)
            {
                prosjek_studenta=5;
                prosjeci[i]=5;
                padavica=1;
                break;
            }
            suma_ocjena+=studendi[i].ocjene[j];
        }
        if(padavica)
        {
            prosjeci[i]=5;
        }else
        {
            prosjek_studenta=suma_ocjena/studendi[i].br_ocjena;
            prosjeci[i]=prosjek_studenta;
        }
        if(prosjek_studenta<prosjekat)
        {
            for(j=i;j<vel-1;j++)
            {
                studendi[j]=studendi[j+1];
                prosjeci[j]=prosjeci[j+1];
            }
            i--;
            vel--;
        }
    }
    for(i=0;i<vel;i++)
    {
        if(prosjeci[i]>max1)
        {
            prvi=1;
            i1=i;
            max1=prosjeci[i];
        }
    }
    for(i=0;i<vel;i++)
    {   
        if(prosjeci[i]>max2 && prosjeci[i]<max1)
        {
            drugi=1;
            i2=i;
            max2=prosjeci[i];
        }
    }
    for(i=0;i<vel;i++)
    {
        
        if(prosjeci[i]>max3 && prosjeci[i]<max2)
        {
            treci=1;
            i3=i;
            max3=prosjeci[i];
        }
    }
    if(prvi==0)
    {
        return vel;
    }
    else if(prvi==1 && drugi==1 && treci==1)
    {
        printf("%s %s\n", studendi[i1].prezime, studendi[i1].ime);
        printf("%s %s\n", studendi[i2].prezime, studendi[i2].ime);
        printf("%s %s\n", studendi[i3].prezime, studendi[i3].ime);
        return vel;
    }
    else if(prvi==1 && drugi==1 && treci==0)
    {
        printf("%s %s\n", studendi[i1].prezime, studendi[i1].ime);
        printf("%s %s", studendi[i2].prezime, studendi[i2].ime);
        return vel;
    }
    else if(prvi==1 && drugi==0 && treci==0)
    {
        printf("%s %s", studendi[i1].prezime, studendi[i1].ime);
        return vel;
    }
    return vel;
}



int main() {
	
	
	struct Student studenti[5] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,8,8}, 5}, 
    };
    genijalci(studenti, 5, 6.5);

	return 0;
}
