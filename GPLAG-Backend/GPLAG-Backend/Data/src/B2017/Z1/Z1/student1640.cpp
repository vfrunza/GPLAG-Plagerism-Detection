#include <iostream>
#include <vector>

bool JeLiProst (int n)
{
    if (n<=1) return false;
    for (int i=2; (unsigned int) (i*i)<=n; i++) {
        if (n%i==0) return false;
    }
    return true;
}

bool JeLiSimetrican(int n)
{
    std::vector<int>b;
    int brojicifre=0;
    int ostatak;
    while (n>0) {
        ostatak=n%3;
        b.push_back(ostatak);
        n=n/3;
    }

    int vel=b.size()/2;
    for (int i=0; i<vel; i++) {
        if (b.at(i)==b.at(b.size()-1-i))
            brojicifre++;
    }
    if(vel==brojicifre)
        return true;
    else
        return false;
}

std::vector<int>IzdvojiSimetricneTernarne (std::vector<int>vektor, bool uslov)
{
    std::vector <int> noviprosti;
    std::vector <int> novislozeni;
    for (int i=0; i<vektor.size(); i++) {
        if (JeLiProst(vektor.at(i)) && JeLiSimetrican(vektor.at(i)))
            noviprosti.push_back(vektor.at(i));
        else if(!JeLiProst(vektor.at(i))&&JeLiSimetrican(vektor.at(i)))
        novislozeni.push_back(vektor.at(i));
    }
    if(uslov==1)
        return noviprosti;
    if (uslov==0)
        return novislozeni;
}

int main()
{
    std::vector<int>finalni;
    int uslov;
    int temp;
    std::cout<<"Unesite elemente vektora (-1 za kraj): ";

    do {
        std::cin>>temp;
        if (temp!=-1)
            finalni.push_back(temp);
    } while (temp!=-1);

    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    do 
    {
        std::cin>>uslov;
        if (uslov!=1 && uslov !=0) std::cout<<"Neispravan unos! Unesite ponovo: ";
        else break;
        }while(1);
    
    std::vector <int>f;

    f=IzdvojiSimetricneTernarne(finalni, uslov);
    if (f.size()==0 &&uslov==1) {
        std::cout<<"Nema prostih simetricnih brojeva u vektoru.";

        return 0;
    }

    if(f.size()==0 && uslov==0) {
        std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";

        return 0;
    }

    if (f.size()>0 && uslov==1) {
        std::cout <<"Prosti simetricni brojevi iz vektora su: ";
        for (int i=0; i<f.size()-1; i++)
            std::cout<<f.at(i)<<", ";
        std::cout<<f.at(f.size()-1)<<".";

        return 0;
    }

    if (f.size()>0 && uslov==0) {
        std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
        for (int i=0; i<f.size()-1; i++)
            std::cout<<f.at(i)<<", ";
        std::cout<<f.at(f.size()-1)<<".";
    }
    return 0;
}

