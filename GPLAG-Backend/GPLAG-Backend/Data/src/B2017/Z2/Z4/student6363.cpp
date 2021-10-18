#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <cmath>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
bool Prost(int n){
    if(n<0) return false;
    for(int i=2; i<=int(std::sqrt(abs(n))); i++)
        if(abs(n)%i==0) return false;
    return true;
}
int F1(int a, int b){
    return (-2*a)+b;
}
int prostiFaktori(int a){
    int brojac {0};
    if(Prost(a) || a<0) return 0;
    while (a%2 == 0) {
        brojac++;
        a/=2;
    }
    for (int i = 3; i <= std::sqrt(a); i = i+2)
        while (a%i == 0) {
            a/=i;
            brojac++;
        }
    if (a>2) brojac++;
    return brojac;
}
bool F2(int a,int b){
    int broj1 {prostiFaktori(a)}, broj2 {prostiFaktori(b)};
    return (broj1>broj2 || (broj1==broj2 && a>b));
}
template <typename Tip1, typename Tip2, typename Tip3>
void SortirajPodrucjeVrijednosti(Tip1 x1, Tip1 x2, Tip2 y1, Tip3 z1,
decltype(*z1+*z1) f1(decltype(*x1+*x1), decltype(*x1+*x1)), bool f2(decltype(*x1+*x1), decltype(*x1+*x1))){
    int duzina {0};
    Tip1 x3 {x1};
    while(x3!=x2) {
        duzina++;
        x3++;
    }
    std::sort(x1,x2,f2);
    std::sort(y1,y1+duzina,f2);

    x3=x1;
    Tip2 y3 {y1};
    std::sort(z1,z1+duzina);
    while(x3!=x2) {
        decltype(*z1+*z1) a {f1(*x3,*y3)};
        if(!std::binary_search(z1,z1+duzina,a)) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
        x3++;
        y3++;
    }

    for(int i=0; i<duzina; i++,x1++,y1++,z1++) {
        decltype(*z1+*z1) a {f1(*x1,*y1)};
        std::swap(*z1,*std::find(z1,z1+duzina,a));
    }
}
template <typename Tip,typename Tip2>
bool Sadrzan(Tip x, int n,Tip2 y){
    for(int i=0; i<n; i++)
        if(x[i]==y) return true;
    return false;
}

template <typename Tip>
void Unos(Tip &x,int n){
    for(int i=0; i<n; i++) {
        decltype(x[0]+x[0]) a;
        cin>>a;
        if(!Sadrzan(x,i,a)) x[i]=a;
        else i--;
    }
}

int main (){
    int n;
    cout << "Unesite broj elemenata: ";
    cin >> n;
    try {
        vector<int> x(n), y(n), z(n);
        cout << "Unesite elemente prvog vektora: ";
        Unos(x,n);
        cout << "Unesite elemente drugog vektora: ";
        Unos(y,n);
        cout << "Unesite elemente treceg vektora: ";
        Unos(z,n);
        cout << endl;
        SortirajPodrucjeVrijednosti(x.begin(),x.end(),y.begin(),z.begin(),F1, F2);

        cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << endl;
        for(int i=0; i<n; i++)
            cout << "f(" << x.at(i) << ", " << y.at(i) << ") = " << z.at(i) << endl;
    } catch(std::exception &ex) {
        cout << "Izuzetak: " << ex.what();
    }
    return 0;
}
