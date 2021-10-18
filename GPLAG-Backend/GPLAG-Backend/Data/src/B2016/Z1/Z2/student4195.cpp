#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

typedef std::vector<double> Vektor;
typedef std::vector<std::vector<double>> Matrica;

Vektor ObrniVektor(Vektor ulazni){
    for(int i=0; i<ulazni.size()/2; i++){
        double pomocna=ulazni.at(i);
        ulazni.at(i)=ulazni.at(ulazni.size()-1-i);
        ulazni.at(ulazni.size()-1-i) = pomocna;
    }
    return ulazni;
}

Matrica OgledaloMatrica(Matrica ulazna_matrica){
    for(int i=0; i<int(ulazna_matrica.size())-1; i++){
        if(ulazna_matrica.at(i).size()!=ulazna_matrica.at(i+1).size())
            throw std::domain_error("Matrica nije korektna");
    }
    Matrica vertikalna(ulazna_matrica.size());
    int brojac(0);
    for(int i=int(ulazna_matrica.size())-1; i>=0; i--) //Vertikalna
        vertikalna.at(brojac++)=ulazna_matrica.at(i);
    Matrica horizontalna(ulazna_matrica.size());
    for(int i=0; i<ulazna_matrica.size(); i++) //Horizontalna
        horizontalna.at(i)= ObrniVektor(ulazna_matrica.at(i));
    Matrica horiz_vert(ulazna_matrica.size());
    for(int i=0; i<ulazna_matrica.size(); i++) //Horizontalno-Vertikalna
        horiz_vert.at(i)=ObrniVektor(vertikalna.at(i));
    Matrica rezultat(ulazna_matrica.size()*3);
    for(int i=0; i<ulazna_matrica.size(); i++){ //Prvi i zadnji "red" rezultat
        rezultat.at(i)=horiz_vert.at(i);
        for(int j=0; j<vertikalna.at(i).size(); j++)
            rezultat.at(i).push_back(vertikalna.at(i).at(j)); 
        for(int j=0; j<horiz_vert.at(i).size(); j++)
            rezultat.at(i).push_back(horiz_vert.at(i).at(j)); 
        rezultat.at(i+ulazna_matrica.size()*2)=rezultat.at(i);
    }
    brojac=0;
    for(int i=ulazna_matrica.size(); i<ulazna_matrica.size()*2; i++){ //Drugi "red" rezultata
        rezultat.at(i)=horizontalna.at(brojac);
        for(int j=0; j<ulazna_matrica.at(brojac).size(); j++)
            rezultat.at(i).push_back(ulazna_matrica.at(brojac).at(j));
        for(int j=0; j<horizontalna.at(brojac).size(); j++)
            rezultat.at(i).push_back(horizontalna.at(brojac).at(j));        
        brojac++;
    }
    return rezultat;
}

int main()
{
    int m,n;
    cout<<"Unesite dimenzije matrice (m n): ";
    cin>>m>>n;
    if(m<0 or n<0){
        cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    cout<<"Unesite elemente matrice: ";
    Matrica matrica(m,Vektor(n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++){
            cin>>matrica.at(i).at(j);
        }
    }
    Matrica ogledalo(OgledaloMatrica(matrica));
    cout<<"\nRezultantna matrica: "<<endl;
    for(auto red: ogledalo){
        for(auto clan: red)
            cout<<std::setw(4)<<clan;
        cout<<endl;
    }
    return 0;
}
