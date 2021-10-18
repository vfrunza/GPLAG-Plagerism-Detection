//B 2017/2018, Zadaća 1, Zadatak 3
#include <iostream>
#include <vector>
#include <deque>

typedef std::vector<int> Vektor;
typedef std::deque<Vektor> Dek;
enum Smjer {Rastuci, Opadajuci} smjer;
//Funkcija koja provjerava da li je broj stepen dvojke
bool StepenDvojke (int n)
{   
//Broj je stepen dvojke ako njegovim kontinuiranim dijeljenjem sa brojem dva ne dobijemo neparan broj veci od jedan
    if(n==1)return true;
    if(n<=0)return false;
    while(n>0 && n!=1)
    {
        if(n%2!=0)return false;
        n=n/2;
    }
    return true;
}
//Funkcija koja prima vektor cijelih brojeva i parametar pobrojanog tipa, a vraca dek vektôrā ciji su elementi vektori koji predstavljaju maksimalne monotono rastuce odnosno monotono opadajuce podnizove zavisno od vrijednosti parametra pobrojanog tipa
Dek MaksimalniPodnizoviStepenaDvojke (Vektor v, Smjer SmjerPodniza)
{
    Dek dek;
    int k(0), l(0), br(0), n=v.size();
    bool NoviRed=false;
    for(int i=0; i<n-1; i++)
    {
//Ako su dva susjedna broja clanovi rastuceg/opadajuceg podniza i ako su oba stepen dvojke onda ih smijestamo u taj podniz        
        if((SmjerPodniza==Smjer(0) && v.at(i)<=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))) || (SmjerPodniza==Smjer(1) && v.at(i)>=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))))
        {
//Prvobitno povecavamo broj redova deka vektôrā za jedan; on se dodatno povecava za jedan svaki put kada predjemo u novi red          
            dek.resize(k+1);
//Prije smijestanja brojeva u vektor povecavamo broj kolona deka vektôrā
            dek.at(k).resize(l+2);
            dek.at(k).at(l++)=v.at(i);
            dek.at(k).at(l)=v.at(i+1);
            NoviRed=false;
            br=0;
        }
//Ako dva susjedna broja nisu clanovi rastuceg/opadajuceg maksimalnog podniza ili ako jedan ili oba nisu stepen dvojke onda prelazimo u novi red        
        else 
        {
            NoviRed=true;
            br++;
        }
//U novi red prelazimo ako i samo ako trenutni red sadrzi neki maksimalni podniz         
        if(NoviRed==true && br==1)
        {
            NoviRed=false;
            k++;
//Vracamo drugi indeks na nulu da bi smijestanje elemenata u dek bilo od pocetka novog reda            
            l=0;
        }
    }
    return dek;
}

int main ()
{
    std::cout << "Unesite broj elemenata vektora: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite elemente vektora: ";
    Vektor v;
    int x;
    for(int i=0; i<n; i++)
    {
        std::cin >> x;
        v.push_back(x);
    }
    
    std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    std::cin >> n;
    if(n==1)
    {
        smjer=Smjer(0);
        std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
    }
    else if(n==2)
    {
        smjer=Smjer(1);
        std::cout << "Maksimalni opadajuci podnizovi: " <<std::endl;
    }
    
    Dek dek(MaksimalniPodnizoviStepenaDvojke(v,smjer));
    for(int i=0; i<dek.size(); i++) 
    {
        for(int j=0; j<dek.at(i).size(); j++)
        {
            std::cout << dek.at(i).at(j) << " ";
        } 
        std::cout << std::endl;
    }
    return 0;
}