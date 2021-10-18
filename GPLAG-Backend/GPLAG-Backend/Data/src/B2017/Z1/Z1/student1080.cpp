/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
bool DaLiJeProst(int n) { // Testiranje prostog
    for(int i = 2; i <= n / 2; ++i) {
      if(n % i == 0) {
          return false;
          break;}}
    return true;}
bool TKTS (int broj) { // Tercijarni konverter i Test Simetricnosti
    long long Unaprijed = 0;
    long long Unazad = 0;
    long long test =0;
    int remainder, i = 1;
    while (broj!=0)
    { remainder = broj%3;
        broj /= 3;
        Unaprijed += remainder*i;
        i *= 10; 
        test=Unaprijed; }
    while(test != 0){   remainder = test%10;
        Unazad = Unazad*10 + remainder;
        test /= 10; }
    if(Unaprijed==Unazad) return true;
    else return false;}
std::vector <int> IzdvojiSimetricneTernare (std::vector <int> vektor, bool izbor) { // Glavna Funkcija 
    std::vector <int> FinalniVektor;
    for(int i=0;i<vektor.size()-1;i++){
        if((izbor==true)&&(DaLiJeProst(vektor.at(i))==true) && (TKTS(vektor.at(i))==true)) {
                    FinalniVektor.push_back(vektor.at(i)); }
        else if((izbor==false)&&(DaLiJeProst(vektor.at(i))==false) && (TKTS(vektor.at(i))==true)) {
                FinalniVektor.push_back(vektor.at(i));
             }}  return FinalniVektor; }
void UkloniDuple(std::vector<int> &v){ // UklanjanjeDuplikata
    auto end = v.end();
    for (auto i = v.begin(); i != end; ++i) {
        end = std::remove(i + 1, end, *i);}
    v.erase(end, v.end());}
int main (){ // Main
    std::cout << "Unesite elemente vektora (-1 za kraj): ";
    std::vector <int> vektor;
    int broj;
    do { std::cin >> broj;
        vektor.push_back(broj); }
    while (broj != -1);
    std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    int izbor;
    do{
    std::cin >> izbor;
    if(izbor==1) break;
    if(izbor==0) break;
    std::cout << "Neispravan unos! Unesite ponovo: ";
    } while(izbor !=0);
    std::vector <int> Rezultat;
    Rezultat=IzdvojiSimetricneTernare(vektor,bool(izbor));
    UkloniDuple(Rezultat);
    if (izbor==true && Rezultat.size() !=0){
    std::cout << "Prosti simetricni brojevi iz vektora su: ";
    for(int i=0;i<Rezultat.size();i++) 31
        if(i!=Rezultat.size()-1)
        std::cout << Rezultat.at(i) << ',' << ' ';
    else
        std::cout << Rezultat.at(i) << '.';} }
    else if (izbor==true && Rezultat.size()==0)  
       std::cout << "Nema prostih simetricnih brojeva u vektoru.";
    else if (izbor==false && Rezultat.size()!=0) {
        std::cout << "Slozeni simetricni brojevi iz vektora su: ";
    for(int i=0;i<Rezultat.size();i++){
        if(i!=Rezultat.size()-1)
        std::cout << Rezultat.at(i) << ',' << ' ';
    else
        std::cout << Rezultat.at(i) << '.'; } }
    else if (izbor==false && Rezultat.size() ==0)  
       std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	return 0;}