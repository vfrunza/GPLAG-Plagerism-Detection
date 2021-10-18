#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

bool g(int A, int B){
    int suma1 = 0;
    int suma2 = 0;
    int i = 1;
    while(i < A){
        if(A % i == 0) suma1++;
        i++;
    }
    i = 1;
    while(i < B){
        if(B % i == 0) suma2++;
        i++;
    }
    if(suma1 == suma2) return A>B;
    return suma1 > suma2;
}


int f(int x, int y){
    int rezultat;
    x *=2;
    rezultat = y - x;
    return rezultat;
}

template<typename IterTip1, typename IterTip2, typename IterTip3>
void SortirajPodrucjevrijednosti(IterTip1 S1pocetak, IterTip1 S1kraj, IterTip2 S2pocetak, IterTip3 S3pocetak, typename std::remove_reference<decltype(*S2pocetak)>::type f(typename std::remove_reference<decltype(*S1pocetak)>::type, 
typename std::remove_reference<decltype(*S1pocetak)>::type), bool g(typename std::remove_reference<decltype(*S1pocetak)>::type, typename std::remove_reference<decltype(*S1pocetak)>::type)){
    int n = S1kraj - S1pocetak;
    std::sort(S1pocetak, S1kraj, g);
    std::sort(S2pocetak, S2pocetak + n, g);
    auto ItZaS1 = S1pocetak;
    auto ItZaS2 = S2pocetak;
    while(ItZaS1 != S1kraj){
        auto vrijednost = f(*ItZaS1, *ItZaS2);
        auto GdjeJe = std::find(S3pocetak, S3pocetak + n, vrijednost);
        if(GdjeJe == (S3pocetak + n)) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
        else{
            auto GdjeTrebaBiti = S3pocetak + (ItZaS1 - S1pocetak);
            auto temp(*GdjeJe);
            *GdjeJe = *GdjeTrebaBiti;
            *GdjeTrebaBiti = temp;
        }
        ItZaS1++;
        ItZaS2++;
    }
    
}    

int main (){
    cout<<"Unesite broj elemenata: ";
    int n;
    cin>>n;
    cout<<"Unesite elemente prvog vektora: ";
    vector<int> S1;
    for(int i = 0; i < n; i++){
        int k;
        cin>>k;
        bool nema = true;
        for(int x : S1){
            if(x == k) nema = false;
        }
        if(nema)S1.push_back(k); 
        else i--;
    }
    cout<<"Unesite elemente drugog vektora: ";
    vector<int> S2;
    for(int i = 0; i < n; i++){
        int k;
        cin>>k;
        bool nema = true;
        for(int x : S2){
            if(x == k) nema = false;
        }
        if(nema) S2.push_back(k);
        else i--;
    }
    cout<<"Unesite elemente treceg vektora: ";
    vector<int> S3;
    for(int i = 0; i < n; i++){
        int k;
        cin>>k;
        bool nema = true;
        for(int x : S3){
            if(x == k) nema = false;
        }
        if(nema) S3.push_back(k);
        else i--;
    }
    try{
        SortirajPodrucjevrijednosti(S1.begin(), S1.end(), S2.begin(), S3.begin(), f, g);
        cout<<"\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke: \n";
        for(int i = 0; i < n; i++){
            cout<<"f("<<S1.at(i)<<", "<<S2.at(i)<<") = "<<S3.at(i)<<std::endl;
        }
    }
    catch(std::logic_error e){
        cout<<"\nIzuzetak: "<<e.what();
    }
	return 0;
}