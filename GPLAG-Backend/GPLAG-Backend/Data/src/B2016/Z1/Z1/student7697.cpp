#include <iostream>
#include <vector>


std::vector<int> Ternarni(int n )  /*Pretvorimo unesenu cifru iz dekadnog u ternarni*/
{
    std::vector<int> rez;

    while(n != 0) {
        rez.push_back(n%3);
        n/=3;
    }
    return rez;
}

int Prebroji(std::vector<int> v) /*Prebrojavanje cifara 0 1 2*/
{
    int rez=0;
    int niz[3]= {0,0,0};

    for(auto x:v) {

        if (abs(x)==0) niz[0] ++;
        else if (abs(x)==1) niz[1]++;
        else if (abs(x)==2) niz[2]++;
    }

    if(niz[0] % 2 == 0 && niz[1] % 2 == 0 && niz[2] % 2 == 0) rez = 0;

    else if(niz[0] % 2 != 0 && niz[1] % 2 != 0 && niz[2] % 2 != 0)  rez = 1;

    else if((niz[0] == 0 && niz[1] % 2 != 0 && niz[2] % 2 != 0) || (niz[0] % 2 !=0 && niz[1] == 0 && niz[2] % 2!= 0) || (niz[0] % 2 !=0 && niz[1] % 2 !=0 && niz[2] == 0)) rez = 1; /*Uslov ako se jedna cifra uopste ne pojavljuje u ternarnom zapisu*/
    else if((niz[0] == 0 && niz[1] == 0 && niz[2] % 2 != 0) || (niz[0] % 2 !=0 && niz[1] == 0 && niz[2] == 0) || (niz[0] == 0 && niz[1] % 2 !=0 && niz[2] == 0)) rez = 1; /*Uslov ako se dvije cifre ne pojavljuju u ternarnom zapisu*/

    else rez = 2;

    return rez;
}


std::vector<int> IzdvojiGadne (std::vector<int> v, bool parno)
{
    std::vector<int> rezultat;

    if(parno) {  /*Izdvaja one sa parnim brojem cifara*/
        for(auto x:v) {

            if(Prebroji(Ternarni(x)) == 0)  {

                bool j = true;/*Izbacuje duplikate*/
                for(auto y:rezultat) {
                    if(y == x) j = false;
                }
                if(j==true) rezultat.push_back(x);

            }
        }
    } else { /*Izdvaja one sa naparnim brojem cifara*/
        for(auto x:v) {

            if(Prebroji(Ternarni(x)) == 1) {

                bool j = true; /*Izbacuje duplikate*/
                for(auto y:rezultat) {
                    if(y == x) j = false;
                }
                if(j==true) rezultat.push_back(x);

            }
        }
    }

    return rezultat;
}

int main ()
{

    std::cout << "Unesite brojeve (0 za prekid unosa): ";
    std::vector<int> A(0);

    while(true) { /*Dio unosa*/
        int x=0;
        std::cin>>x;
        if(x==0) break;
        A.push_back(x);
    }

    std::vector<int> B(0),C(0) ;
    B=IzdvojiGadne(A,true);
    C=IzdvojiGadne(A,false);

    std::cout<<"Opaki:"<< " ";
    for(auto x:B)
        std::cout << x << " ";

    std::cout<<"\nOdvratni:"<<" ";
    for(auto x:C)
        std::cout<< x <<" ";

    return 0;
}