#include <iostream>
#include <vector>
#include <cmath>

int OkreniBroj(int n){
    int suma=0, cifra;
    while(n!=0){
        cifra=n%10;
        suma=suma*10+cifra;
        n/=10;
    }
    return suma;
}

bool IspitajProsti(int n){
    if(n<2) return false;
    for(int i=2; i<=int(std::sqrt(n)); i++){
        if(n%i==0) return false;
    }
    return true;
}

int Ternarni(int n){
    int suma=0, cifra;
    while(n!=0){
        cifra=n%3;
        suma=suma*10+cifra;
        n/=3;
    }
    suma=OkreniBroj(suma);
    return suma;
}



bool IspitajPonavljanje(std::vector<int> v, int n){
    for(int i=0; i<v.size(); i++){
        if(n==v.at(i)) return true;
    }
    return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> vektor, bool prosti_slozeni){
    std::vector<int> vektor_izdvojenih;
    for(int i=0; i<vektor.size(); i++){
        if(IspitajPonavljanje(vektor_izdvojenih, vektor.at(i))) continue;
        int ternarni = Ternarni(abs(vektor.at(i)));
        if(ternarni == OkreniBroj(ternarni)){
            if(prosti_slozeni && IspitajProsti(abs(vektor.at(i)))) vektor_izdvojenih.push_back(vektor.at(i));
            else if(!prosti_slozeni && !IspitajProsti(abs(vektor.at(i)))) vektor_izdvojenih.push_back(vektor.at(i));
        }
    }
    return vektor_izdvojenih;
}

int main ()
{
    std::vector<int> vektor;
    int broj=0;
    std::cout << "Unesite elemente vektora (-1 za kraj): ";
    while(1){
        std::cin >> broj;
        if(broj==-1) break;
        vektor.push_back(broj);
    }
    int prosti_slozeni;
    std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    std::cin >> prosti_slozeni;
    while(prosti_slozeni!=1 && prosti_slozeni!=0){
        std::cout << "Neispravan unos! Unesite ponovo: ";
        std::cin >> prosti_slozeni;
        }
    
    std::vector<int> izdvojeni = IzdvojiSimetricneTernarne(vektor, prosti_slozeni);
    if(izdvojeni.size()!=0 && prosti_slozeni) std::cout << "Prosti simetricni brojevi iz vektora su: ";
    else if(izdvojeni.size()!=0 && !prosti_slozeni) std::cout << "Slozeni simetricni brojevi iz vektora su: ";
    for(int i=0; i<izdvojeni.size(); i++){
        if(i==izdvojeni.size()-1) std::cout << izdvojeni.at(i) << ".";
        else std::cout << izdvojeni.at(i) << ", ";
    }
    if(izdvojeni.size()==0){
        if(prosti_slozeni) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
        else if(!prosti_slozeni) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
    }
	return 0;
}