#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

bool DaLiJeProst(int a)
{
    a=std::abs(a);
    for(unsigned int i=2; i*i<=a; i++) {
        if(a%i==0)

            return false;
    }
    return true;
}
bool Simetricni(int temp)
{
    int okrenut=0,cifra2=0,temp2;
    temp2=temp;
    if(temp2<0)
        temp2*=(-1);
    do {
        cifra2=temp2%10;
        okrenut=okrenut*10+cifra2;
        temp2/=10;
    } while(temp2>0);
    if(okrenut==temp)
        return true;
    else return false;
}



std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v1,bool t)
{
    std::vector<int> v2;
    int cifra=0;

    if(t==0) {
        for(int i=0; i<v1.size(); i++) {
            int TernarniBroj=0;
            int temp;
            temp=v1.at(i);
            int minus=0;
            if(temp<0) {
                temp*=-1;
                minus=1;
            }

            for(int k=2; k<temp; k++) {

                if(temp%k==0) {
                    int brojac(0);
                    do {
                        cifra=temp%3;
                        TernarniBroj+=cifra*pow(10,brojac);
                        temp/=3;
                        brojac++;

                    } while(temp>0);

                    bool n=Simetricni(TernarniBroj);

                    if(n==1) {
                        v2.push_back(v1.at(i));
                        break;
                    }

                }
            }
        }
    }
    if(t==1) {
        for(int i=0; i<v1.size(); i++) {
            int TernarniBroj=0;
            int temp;
            temp=v1.at(i);
            int minus=0;
            if(temp<0) {
                temp*=-1;
                minus=1;
            }
            int a=DaLiJeProst(temp);

            if(a==1) {
                int brojac(0);
                do {
                    cifra=temp%3;
                    TernarniBroj+=cifra*pow(10,brojac);
                    temp/=3;
                    brojac++;

                } while(temp>0);

                bool n=Simetricni(TernarniBroj);

                if(n==1) {
                    v2.push_back(v1.at(i));
                    //break;
                }

            }
        }
    }

    return v2;
}
int main ()
{
    int a;
    std::vector<int> v1;
    std::cout<<"Unesite elemente vektora (-1 za kraj): ";
    do {
        std::cin>>a;
        if(a==-1)
            break;
        v1.push_back(a);
    } while(1);
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    int P;
    bool ProstSlozen;
    do {
        std::cin>>P;
        if(P!=1 && P!=0)
            std::cout<<"Neispravan unos! Unesite ponovo: ";
    } while(P!=1 && P!=0);

    if(P==1)
        ProstSlozen=true;
    else if(P==0)
        ProstSlozen=false;

    std::vector<int> v3=IzdvojiSimetricneTernarne(v1,ProstSlozen);
    if(ProstSlozen==1 && v3.size()>0)
        std::cout<<"Prosti simetricni brojevi iz vektora su: ";
    else if(ProstSlozen==0  && v3.size()>0)	std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
    if(ProstSlozen==1 && v3.size()==0)
        std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
    else if(ProstSlozen==0 && v3.size()==0)
        std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";

    for(int i=0; i<v3.size(); i++) {
        if(i!=v3.size()-1) std::cout<<v3.at(i)<<", ";
        else if (i==v3.size()-1)
            std::cout<<v3.at(i)<<".";
    }

    return 0;
}