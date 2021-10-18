#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdexcept>

int fun(int x,int y)
{
    return  (-2)*x+y;
}

int BPF(int a)
{
    int b;
    int brojac=0;
    if(a<2) return 0;
    if(a==1) brojac=1;
    else {
        int k=a%2;
        while(k==0) {
            b=a/2;
            brojac++;
            a=b;
            k=a%2;
        }
        for(int j=3; j<=a; j+=2) {
            int k=a%j;
            while(k==0) {
                b=a/j;
                brojac++;
                a=b;
                k=a%j;
            }
        }
    }

    return brojac;
}

bool fun2(int x,int y)
{
    int e,k;
    e=BPF(x);
    k=BPF(y);
    if(e>k) return true;
    else if(k>e) return false;
    else  if( x>y && e==k) return true;
    else return false;

}

template <typename TIP1,typename TIP2,typename TIP3>
void SortirajPodrucjeVrijednosti(TIP1 p1,TIP1 p2,TIP2 p3,TIP3 p4,decltype(*p4+0) fun(decltype(*p1+0),decltype(*p3+0)),bool fun2(decltype(*p1+0),decltype(*p3+0)))
{
    auto duzina=p2-p1;
    std::sort(p1,p2,fun2);
    std::sort(p3,p3+(duzina),fun2);

    int d=0;
    auto pocetak3=p4;
    while(p1!=p2) {
        p4=pocetak3;
        bool b=false;

        while(p4!=pocetak3+(duzina)) {
            if(fun(*p1,*p3)==*p4) {
                b=true;
                auto temp=*(pocetak3+d);
                *(pocetak3+d)=*p4;
                *p4=temp;
                /* auto temp=*p4;
                *p4=*(pocetak3+d);
                *(pocetak3+d)=temp; */
                break;
            }
            p4++;
        }
        if(b==false) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
        p1++;
        p3++;
        d++;
    }

}


int main ()
{

    int n;
    std::cout <<"Unesite broj elemenata: ";
    std::cin >> n;
    std::vector<int> S1;
    std::vector<int> S2;
    std::vector<int> S3;
    int element;
    std::cout <<"Unesite elemente prvog vektora: ";
    for(int i=0; i<n; i++) {
        bool ima(false);
        std::cin >> element;
        //S1.push_back(element);
        for(int j=0; j<i; j++) {
            if(S1.at(j)==element) {
                ima=true;
                i--;
                break;
            }
        }
if(!ima) S1.push_back(element);
    }
    std::cout <<"Unesite elemente drugog vektora: ";
    for(int i=0; i<n; i++) {
        bool ima(false);
        std::cin >> element;
        //S2.push_back(element);
        for(int j=0; j<i; j++) {
            if(S2.at(j)==element) {
                ima=true;
                i--;
                break;
            }
        }
if(!ima) S2.push_back(element);
    }
    std::cout <<"Unesite elemente treceg vektora: ";
    for(int i=0; i<n; i++) {
        bool ima(false);
        std::cin >> element;
        //S1.push_back(element);
        for(int j=0; j<i; j++) {
            if(S3.at(j)==element) {
                ima=true;
                i--;
                break;
            }
        }
if(!ima) S3.push_back(element);
    }
    try {


        SortirajPodrucjeVrijednosti(S1.begin(),S1.end(),S2.begin(),S3.begin(),fun,fun2);
        std::cout <<"\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
        for(int i=0; i<n; i++) {
            std::cout <<"f("<<S1.at(i)<<", "<<S2.at(i)<<") = "<<S3.at(i)<<std::endl;

        }
    } catch(std::logic_error tekst) {
        std::cout << "\nIzuzetak: " <<tekst.what();
    }


    return 0;
}
