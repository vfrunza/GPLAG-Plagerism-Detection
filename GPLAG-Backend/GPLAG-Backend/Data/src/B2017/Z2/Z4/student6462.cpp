#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename tip1,typename tip2,typename tip3,typename funkcija1,typename funkcija2>
void SortirajPodrucjeVrijednosi(tip1 prviStart,tip1 prviKraj,tip2 drugiStart,tip3 treciStart,funkcija1 f1,funkcija2 f2)
{
    sort(prviStart,prviKraj,f2);
    auto drugiKraj(drugiStart+(prviKraj-prviStart));
    auto treciKraj(treciStart+(prviKraj-prviStart))
    sort(drugiStart,drugiKraj,f2);
    while(prviStart++!=prviKraj){
        drugiStart++;
        f(prviStart,)
    }
}

int main ()
{
    cout<<"Unesite broj elemenata: ";
    int broj;
    cin>>broj;
    cout<<"Unesite elemente prvog vektora: ";
    vector<int> v1(broj);
    vector<int> provjera;
    for(int i(0); i<broj; i++) {
        cin>>v1[i];
        provjera.push_back(v1[i]);
        for(int j(0); j<i; j++) {
            if(v1[i]==provjera[j]) {
                v1.erase(v1.begin()+i);
                i--;
            }
        }
    }
    provjera.resize(0);
    cout<<"Unesite elemente drugog vektora: ";
    vector<int> v2(broj);
    for(int i(0); i<broj; i++) {
        cin>>v1[i];
        provjera.push_back(v1[i]);
        for(int j(0); j<i; j++) {
            if(v1[i]==provjera[j]) {
                v1.erase(v1.begin()+i);
                i--;
            }
        }
    }
    provjera.resize(0);
    cout<<"Unesite elemente treceg vektora: ";
    vector<int> v3(broj);
    for(int i(0); i<broj; i++) {
        cin>>v1[i];
        provjera.push_back(v1[i]);
        for(int j(0); j<i; j++) {
            if(v1[i]==provjera[j]) {
                v1.erase(v1.begin()+i);
                i--;
            }
        }
    }
    SortirajPodrucjeVrijednosi(v1.begin(),v1.end(),v2.begin(),v3.begin(),[](int x,int y) {
        return x+2*y;
    },[](int x,int y) {
        int suma1(0);
        while(x!=0){
            suma1+=(x%10);
            x/=10;
        }
        int suma2(0);
        while(x!=0){
            suma2+=(x%10);
            x/=10;
        }
        if(suma1==suma2)return x<y;
        else if(suma1>suma2)return x>y;
    });
    cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke";
        return 0;
}