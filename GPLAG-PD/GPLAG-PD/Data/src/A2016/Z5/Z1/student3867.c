#include <stdio.h>
#include <string.h>

struct Student
{
    char ime[20],prezime[20];
    int ocjene[50];
    int br_ocjena;
};

int genijalci(struct Student stud[100], int arr, float pr)
{
    float prosjek[1000],flop=0,max[3]={0};
    int i,j=0,next=0,compare=0,hist[3]={0},comparenext=0;
/*eliminacija studenata koji ne zadovoljavaju prolaz*/
    do
    {
        flop=0;
    /*provjera da li ima ijednu ocjenu*/
        if(stud[next].br_ocjena==0)
        {
            prosjek[next]=5.0;
            flop=5.0;
            i=1;
            goto volimGoTo;
        }
    /*racuna prosjek, i studente sa barem jednom peticom odmah odbacuje i stavlja 5.0 prosjek*/
        for(i=0;i<stud[next].br_ocjena;i++)
        {
            if(stud[next].ocjene[i]==5)
            {
                prosjek[next]=5.0;
                flop=5.0;
                i=1;
                break;
            }
            flop=flop+stud[next].ocjene[i];
        }
volimGoTo:
        prosjek[next]=flop/(float)i;
    /*izbacuje iz niza studente koji ne zadovoljavaju*/
        if(pr>prosjek[next])
        {
            for(i=next;i<arr-1;i++)
            {
                stud[i]=stud[i+1];
                prosjek[i]=prosjek[i+1];
            }
            arr--;
            next--;
        }
        next++;
    }while(next!=arr);
/*pregled najboljih prosjeka*/    
    for(i=0;i<arr;i++)
    {
        for(j=0;j<3;j++)
        {
            if(prosjek[i]>max[j])
            {   
                if(j==0)
                {
                    max[j+2]=max[j+1];
                    max[j+1]=max[j];
                    hist[j+2]=hist[j+1];
                    hist[j+1]=hist[j];
                }
                if(j==1)
                {
                    max[j+2]=max[j+1];
                    hist[j+2]=hist[j+1];
                }
                max[j]=prosjek[i];
                hist[j]=i;
                break;
            }
            if(prosjek[i]==max[j])
            {
                if(j==0)
                {
                    max[j+2]=max[j+1];
                    max[j+1]=max[j];
                    hist[j+2]=hist[j+1];
                    hist[j+1]=hist[j];
                }
                if(j==1)
                {
                    max[j+2]=max[j+1];
                    hist[j+2]=hist[j+1];
                }
                compare=strcmp(stud[i].prezime,stud[hist[j]].prezime);
                if(compare==0)
                {
                    comparenext=strcmp(stud[i].ime,stud[hist[j]].ime);
                    if(comparenext<=0)
                    {
                        max[j]=prosjek[i];
                        hist[j]=i;
                    }
                    else if(comparenext<0)
                        max[j]=prosjek[hist[j]];
                }
                else if(compare<0)
                {
                    max[j]=prosjek[i];
                    hist[j]=i;
                }
                else if(compare>0)
                    max[j]=prosjek[hist[j]];
                break;
            }
        }
    }
/*ispis najboljih prosjeka*/
    for(i=0;i<arr;i++)
    {
        if(i>2)
            break;
        if(prosjek[hist[i]]>=pr)
            printf("%s %s\n",stud[hist[i]].prezime,stud[hist[i]].ime);
    }
    return arr;
}

int main()
{
    struct Student studenti[100];
    return 0;
}