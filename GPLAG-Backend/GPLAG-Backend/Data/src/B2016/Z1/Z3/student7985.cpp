/*B 2016/2017, Zadaća 1, Zadatak 3*/
#include <iostream>
#include <vector>

typedef std::vector<double> Vektor;
typedef std::vector<Vektor> Matrica;

Matrica RastuciPodnizovi(Vektor v){
    Matrica m;
    if (v.size() == 0 || v.size() == 1) return m;
    int brElem{1};
    int j; 
    int i{1};
    while(1){
        for(; i < v.size(); i++){
            if(v.at(i) < v.at(i-1)) {
                i++; 
                break; //ako ne raste
            }
            brElem++; 
            if (brElem == 2) j = i-1; //treba mi samo prvi indeks od kojeg kreće rast. podniz
        }
        
        Vektor vNovi; //u novi vektor veličine br_elem ću da šaljem elemente koji su rastuće poredani iz vektora v
        while (brElem > 1){
            vNovi.push_back(v[j]);
            j++;
            brElem--;
            if(brElem == 1) vNovi.push_back(v[j]); //da bi se ubacio "krajnji" element niza
        }
       
        if (vNovi.size() != 0){ // ako je nula nema se šta slati u matricu, uslov nije ispunjen, štedimo vrijeme ?
            m.push_back(vNovi); //dodajemo vektor vNovi u matricu m
            Vektor vPrazni;     //kreiram novi vektor pod nazivom Vprazni samo da bih
            vNovi = vPrazni;    //vNovom dodjelila taj prazan vektor
        }
        if(i == v.size() ) break;
    }
    return m;
}

Matrica OpadajuciPodnizovi(Vektor v){
    Matrica m; 
    if (v.size() == 0 || v.size() == 1) return m;
    int brElem{1}, i{1}, j;
    while(1){
        for(; i < v.size(); i++){
            if(v[i] > v[i-1]){
                i++; 
                break;
            }
            brElem++;
            if(brElem == 2) j = i-1;
        }
        Vektor vNovi;
        while(brElem > 1){
            vNovi.push_back(v[j]);
            j++;
            brElem--;
            if (brElem == 1) vNovi.push_back(v[j]);
        }
        if(vNovi.size() != 0){
            m.push_back(vNovi);
            Vektor vPrazni;
            vNovi = vPrazni;
        }
        if(i==v.size()) break;
    }
    return m;
}
int main (){   using std::cout; using std::cin;
    cout << "Unesite broj elemenata vektora: ";
    int n;
    cin >> n; 
    Vektor v;
    double elem;
    cout << "Unesite elemente vektora: ";
    while(n != 0){
        cin >> elem;
        v.push_back(elem);
        n--;
    }
    
    
    cout << "Maksimalni rastuci podnizovi: " << std::endl;
    Matrica m(RastuciPodnizovi(v));
    // i ispis na ekran :novi red na kraju i razmak izmeđi elem podnizova
    for(Vektor red : m){
        for(double x : red)
            cout << x << " ";
        cout << std::endl;
    }
    
    cout << "Maksimalni opadajuci podnizovi: " << std::endl;
    m = OpadajuciPodnizovi(v);
    for(Vektor red : m){
        for(double x : red)
            cout << x << " ";
        cout << std::endl;
    }
    
	return 0;
}