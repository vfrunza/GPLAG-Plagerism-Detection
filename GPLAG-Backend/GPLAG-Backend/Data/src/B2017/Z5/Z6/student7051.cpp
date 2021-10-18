/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
class Berza {
    std::vector<int> cijene; 
    int najmanja_cijena;
    int najveca_cijena;
public: 
    Berza (int najmanja_cijena, int najveca_cijena);
    Berza (int najveca_cijena);  
    void RegistrirajCijenu (int nova_cijena);
    int DajBrojRegistriranihCijena () const;
    void BrisiSve();
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    bool operator ! ();
    int&& operator[] (int indeks_trazene_cijene);
};
Berza::Berza(int najmanja_cijena, int najveca_cijena){
        if (najmanja_cijena<=0 || najveca_cijena<=0) throw std::range_error("Ilegalne granicne cijene");
        Berza::najmanja_cijena=najmanja_cijena;
        Berza::najveca_cijena=najveca_cijena;
    }
/*Konstruktor sa jednim parametrom ne smije se koristiti za automatsku konverziju cjelobrojnih
podataka u objekte tipa “Berza”.*/
Berza::Berza(int najveca_cijena){
        if (najveca_cijena<=0) throw std::range_error("Ilegalne granicne cijene");
        Berza::najveca_cijena=najveca_cijena;
        najmanja_cijena=0; 
    }
void Berza::RegistrirajCijenu (int nova_cijena){
        if (nova_cijena<najmanja_cijena || nova_cijena>najveca_cijena) throw std::range_error("Ilegalna cijena");
        cijene.push_back(nova_cijena);
    }
int Berza::DajBrojRegistriranihCijena () const{
        return cijene.size();
    }
void Berza::BrisiSve(){
        cijene.resize(0);
    }
int Berza::DajMinimalnuCijenu () const {
        if (cijene.empty()) throw std::range_error("Nema registriranih cijena");
        return *min_element(cijene.begin(), cijene.end());
    }
int Berza::DajMaksimalnuCijenu () const {
        if (cijene.empty()) throw std::range_error("Nema registriranih cijena");
       return *max_element(cijene.begin(), cijene.end());
    }
bool Berza::operator ! (){
        if (cijene.empty()) return true;
        else return false;
    }
int&& Berza::operator[] (int indeks_trazene_cijene){
    if (indeks_trazene_cijene>=cijene.size() || indeks_trazene_cijene<1) throw std::range_error("Neispravan indeks");
    return std::move(cijene[indeks_trazene_cijene-1]); /*jer vraca && move ne zaboravi*/
}

int main ()
{
	return 0;
}
