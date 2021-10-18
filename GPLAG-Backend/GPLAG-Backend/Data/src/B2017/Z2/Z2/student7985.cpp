/*B 2017/2018, Zadaća 2, Zadatak 2 */
#include <iostream>
#include <stdexcept>
#include <deque>
#include <vector>
#include <type_traits>
#include <iomanip>
enum class SmjerKretanja{NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};
enum class Provjera{Kocka, NeparneDimenzije};
using std::domain_error;
using std::length_error;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::deque;
using std::remove_reference;
using std::setw;

template <typename Tip>
bool ProvjeraDim(const Tip &kont, Provjera provjera){
    int dimenzija(kont.size());
    for(int i=0; i<kont.size(); i++){
        if(provjera == Provjera::Kocka && kont.at(i).size() != dimenzija) return false;
        else if(provjera == Provjera::NeparneDimenzije && kont.at(i).size() % 2 == 0) return false;
        for(int j=0; j<kont.at(i).size(); j++)
            if(provjera == Provjera::Kocka && kont.at(i).at(j).size() != dimenzija) return false;
            else if(provjera == Provjera::NeparneDimenzije && kont.at(i).at(j).size() % 2 == 0) return false;
    }
    return true;
}

template <typename TipElem>
void RazmjenaElem(TipElem &a, TipElem &b){
    TipElem pom(a);
    a = b;
    b = pom;
}

template <typename Tip>
void RazmjenaRedova(Tip &a, Tip &b){
    for(int j=0; j<a.size(); j++)
        RazmjenaElem(a.at(j), b.at(j));
}

template <typename Tip>
Tip ObrniRedove(const Tip &kont){
    Tip novi(kont);
    for(int i=0; i<novi.size(); i++){
        int n(novi.at(i).size());
        for(int j=0; j<n/2; j++)
            RazmjenaRedova(novi.at(i).at(j), novi.at(i).at(n-1-j));
    }
    return novi;
}

template <typename Tip>
Tip TransformRedoveUKolone(Tip kont){
    Tip novi(kont);
    int n(kont.size());
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                novi.at(i).at(j).at(k) = kont.at(i).at(k).at(j);
    
    return novi;
}

template <typename Tip>
Tip TransformNaprijedNazad(Tip kont){
    Tip novi(kont);
    int n(kont.size());
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                novi.at(i).at(j).at(k) = kont.at(i).at(i).at(k);
            }
        }
    }
    return novi;
}


template <typename Tip>
Tip PjescaniSat(Tip kont, SmjerKretanja smjer){
	if(!ProvjeraDim(kont, Provjera::Kocka)) throw domain_error("3D matrica nema oblik kocke");
	if(!ProvjeraDim(kont, Provjera::NeparneDimenzije)) throw length_error("3D kontejner ne zadovoljava uvjet neparnosti");
    
    int n(kont.size());
    Tip novi;
    
    if(SmjerKretanja::LijevoDesno == smjer || SmjerKretanja::DesnoLijevo == smjer) kont = TransformRedoveUKolone(kont);
    if(smjer == SmjerKretanja::DesnoLijevo) kont = ObrniRedove(kont);
    
    if(smjer == SmjerKretanja::NaprijedNazad) kont = TransformNaprijedNazad(kont);
    
    for(int i=0; i<n; i++){
        typename remove_reference<decltype(kont.at(i))>::type tabla;
        for(int j=0; j<n; j++){
            typename remove_reference<decltype(kont.at(i).at(j))>::type red_table;
            for(int k=0; k<n; k++){
                if(j==k || k == -j+n-1 || (j<n/2 && j<k && k<-j+n-1) || (j>n/2 && j>k && k>-j+n-1)){
                    auto element(kont.at(i).at(j).at(k));
                    red_table.push_back(element);
                }
            }
            tabla.push_back(red_table);
        }
        novi.push_back(tabla);
    }
    
    if(smjer == SmjerKretanja::DoljeGore) return ObrniRedove(novi);
    
    return novi; 
}


int main (){
    cout << "Unesite dimenziju (x/y/z): ";
    int n(1);
    do{
        cin >> n;
        if(n <= 0) cout << "Dimenzija nije ispravna, unesite opet: ";
        else break;
    }while(1);
    cout << "Unesite elemente kontejnera: ";
    vector<deque<deque<int>>> kontejner(n, deque<deque<int>> (n, deque<int>(n)));
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                cin >> kontejner.at(i).at(j).at(k);
    
    
    cout << "Unesite smjer kretanja [0 - 5]: ";
    int sm;
    do{
        cin >> sm;
        if(sm < 0 || sm > 5) cout << "Smjer nije ispravan, unesite opet: ";
        else break;
    }while(1);
    SmjerKretanja niz[6]{SmjerKretanja::NaprijedNazad, SmjerKretanja::NazadNaprijed, SmjerKretanja::GoreDolje, SmjerKretanja::DoljeGore, SmjerKretanja::LijevoDesno, SmjerKretanja::DesnoLijevo};
    SmjerKretanja smjer(niz[sm]);
    
    try{
        auto novi(PjescaniSat(kontejner, smjer));
        cout << "\nPjescani sat unesene matrice je:\n\n";
        int n(novi.size());
        for(int i=0; i<n; i++){
            int nn(novi.at(i).size());
            for(int j=0, br=0; j<nn; j++){
                int nnn(novi.at(i).at(j).size());
                for(int z=0; z<br; z++) cout << "    ";
                for(int k=0; k<nnn; k++)
                    cout << setw(4) << novi.at(i).at(j).at(k);
                cout << endl;
                if(br < n/2) br++;
                else br--;
            }
            cout << endl;
        }
        cout << endl;
    }
    catch(length_error er){
        cout << "\nIzuzetak: " << er.what() << endl;
    }
	catch(domain_error er){
	    cout << "\nIzuzetak: " << er.what() << endl;
	}
	return 0;
}