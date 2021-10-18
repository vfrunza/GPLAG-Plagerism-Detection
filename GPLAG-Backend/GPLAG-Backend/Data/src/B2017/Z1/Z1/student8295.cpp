#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

bool Prosti_brojevi (int n)
{   

    int prost(true);
    if(n==1) return false;
    for (int i=2; i<=sqrt(abs(n)); i++) {
        if(n%i==0) {
            prost=false;
            break;
        }
    }
    if (prost) return true;
    else return false;
}


std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> a , bool prost)
{
    std::vector<int> v;

    if(prost==true) {
        for(int i=0; i<a.size(); i++) {
            if(Prosti_brojevi(a.at(i))) v.push_back(a.at(i));
        }
    } else if(prost==false) {
        for(int i=0; i<a.size(); i++) {
            if(Prosti_brojevi(a.at(i))==false) v.push_back(a.at(i));
        }
    }

    std::vector<int> t;
    for(int i=0; i<v.size(); i++) {
        int n=v.at(i);
        int broj(0);

        do {
            int cifra(abs(n%3));
            broj=broj*10+cifra;
            n/=3;
        } while(n!=0);

        int broj_naopako(0),br;
        while(broj!=0) {
            br=broj%10;
            broj_naopako=broj_naopako*10+br;
            broj=broj/10;
        }
        t.push_back(broj_naopako);
    }
    std::vector<int> l;
    for(int i=0; i<t.size(); i++) {
        int n=t.at(i);
        int rev(0);
        int p=n;

        do {

            int cifra=n%10;
            rev=(rev*10)+cifra;
            n=n/10;

        } while(n!=0);

        if(rev==p) {
            int k(0);
            int broj(0);
            do {
                int cifra=rev%10;
                broj+=cifra*pow(3,k);
                rev=rev/10;
                k++;
            } while(rev!=0);
            l.push_back(broj);
        }
    }
    return l;
}


int main ()
{
    std::vector<int> a;

    cout<<"Unesite elemente vektora (-1 za kraj): ";
    int broj;

    do {
        cin>>broj;
        
        if(broj!=-1) a.push_back(broj);
    } while(broj!=-1);

    int n;
    cout <<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    for(;;) {
        cin>>n;
        if(n==0 || n==1) break;
        cout<<"Neispravan unos! Unesite ponovo: ";
    }

    if (n==0) {
        std::vector<int> l {IzdvojiSimetricneTernarne(a,n)};
        if(l.size()==0) {
            cout<<"Nema slozenih simetricnih brojeva u vektoru.";
            return 0;
        }
        cout<<"Slozeni simetricni brojevi iz vektora su: ";
        for( int i=0; i<l.size(); i++) {
            if(i==l.size()-1) 	{
                cout<<l.at(i)<<"."<<endl;
            } else {
                cout<<l.at(i)<<", ";
            }
        }
    }

    else if(n==1) {
        std::vector<int> p {IzdvojiSimetricneTernarne(a,n)};
        if(p.size()==0) {
            cout<<"Nema prostih simetricnih brojeva u vektoru.";
            return 0;
        }
        cout<<"Prosti simetricni brojevi iz vektora su: ";
        for( int i=0; i<p.size(); i++) {
            if(i==p.size()-1) 	{
                cout<<p.at(i)<< ".";
            } else {
                cout<<p.at(i)<<", ";
            }
        }
    }
    return 0;
}