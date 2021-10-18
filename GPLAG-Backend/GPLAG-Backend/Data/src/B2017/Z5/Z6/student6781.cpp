/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>

class Berza{
    int minimalna_cijena, maksimalna_cijena;
    std::vector<int> elementi;
    public:
    Berza(int min, int max){if(min<0 || max<0) throw std::range_error("Ilegalne granicne cijene"); minimalna_cijena=min; maksimalna_cijena=max;}
    explicit Berza(int max){if(max<0) throw std::range_error("Ilegalne granicne cijene"); minimalna_cijena=0; maksimalna_cijena=max;}
    void RegistrirajCijenu(int cijena){
        if(cijena<minimalna_cijena || cijena>maksimalna_cijena) throw std::range_error("Ilegalna cijena");
        elementi.push_back(cijena);
    }
    int DajBrojRegistriranihCijena() const {return elementi.size();}
    void BrisiSve() {elementi.resize(0);}
    int DajMinimalnuCijenu() const {
        if(elementi.size()==0) throw std::range_error ("Nema registriranih cijena"); 
        return *std::min_element(elementi.begin(), elementi.end());;}
    int DajMaksimalnuCijenu() const {
        if(elementi.size()==0) throw std::range_error ("Nema registriranih cijena"); 
        return *std::max_element(elementi.begin(), elementi.end());}
    friend bool operator!(Berza b); 
    int DajBrojCijenaVecihOd(int a) const;
    void Ispisi() const;
    int operator[](int indeks) const{
        if(indeks<1 || indeks>elementi.size()) throw std::range_error("Neispravan indeks");
        return elementi[indeks];
    }
    friend bool operator!=(const Berza &b1, const Berza &b2);
    friend bool operator==(const Berza &b1, const Berza &b2); 
    friend Berza operator-(Berza b);
    friend Berza operator-(Berza b, int n);
    friend Berza operator-(int n, Berza b);
    friend Berza operator+(Berza b, int n);
    friend Berza operator+(int n, Berza b);
    friend Berza operator+(Berza b1, Berza b2);
    friend Berza operator-(Berza b1, Berza b2);
    friend Berza &operator +=( Berza &b, int n);
    friend Berza &operator -=( Berza &b, int n);
    friend Berza &operator +=( Berza &b1, const Berza &b2){ b1=b1+b2; return b1;}
    friend Berza &operator -=( Berza &b1, const Berza &b2){ b1=b1-b2; return b1;}
    friend Berza &operator++(Berza &b);
    friend Berza operator++(Berza &b,int);
    friend Berza &operator--(Berza &b);
    friend Berza operator--(Berza &b,int);
};
    Berza &operator +=( Berza &b, int n){b= b+n; return b;}
    Berza &operator -=( Berza &b, int n){b= b-n; return b;}
    bool operator!(Berza b){
        return b.elementi.size()==0;
    }
    int Berza::DajBrojCijenaVecihOd(int a) const{
        if(elementi.size()==0) throw std::range_error ("Nema registriranih cijena");
        int br(0);
        br=std::count_if(elementi.begin(), elementi.end(), std::bind(std::greater<int>(),std::placeholders::_1,a));
        return br;
    }
    void Berza::Ispisi() const{
        std::vector<int> cijene;
        cijene=elementi;
        std::sort(cijene.begin(), cijene.end(), std::greater<int>());
        for(int i=0;i<cijene.size();i++){
            std::cout << std::setprecision(2)<<std::fixed<< cijene[i]/100. << std::endl;
        }
    }
    bool operator!=(const Berza &b1, const Berza &b2){
                return (!(b1.elementi.size()==b2.elementi.size() && b1.elementi==b2.elementi));
    }
    bool operator==(const Berza &b1, const Berza &b2){
                return (b1.elementi.size()==b2.elementi.size() && b1.elementi==b2.elementi);
    }
    Berza operator-(Berza b){
        Berza nova(b.minimalna_cijena, b.maksimalna_cijena);
        nova.elementi.resize(b.elementi.size());
        int zbir(b.minimalna_cijena+b.maksimalna_cijena);
        std::transform(b.elementi.begin(), b.elementi.end(), nova.elementi.begin(), std::bind(std::minus<int>(),zbir, std::placeholders::_1));
        return b;
    }
    Berza operator-(Berza b, int n){
        Berza nova(b.minimalna_cijena, b.maksimalna_cijena);
        nova.elementi.resize(b.elementi.size());
        std::transform(b.elementi.begin(), b.elementi.end(), nova.elementi.begin(), std::bind(std::minus<int>(),std::placeholders::_1,n));
         if(nova.DajBrojCijenaVecihOd(nova.maksimalna_cijena)>0 || nova.elementi.size()-nova.DajBrojCijenaVecihOd(nova.minimalna_cijena)>0)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return nova;
    }
    Berza operator-(int n, Berza b){
        Berza nova(b.minimalna_cijena, b.maksimalna_cijena);
        nova.elementi.resize(b.elementi.size());
        std::transform(b.elementi.begin(), b.elementi.end(), nova.elementi.begin(), std::bind(std::minus<int>(),n,std::placeholders::_1));
        if(nova.DajBrojCijenaVecihOd(nova.maksimalna_cijena)>0 || nova.elementi.size()-nova.DajBrojCijenaVecihOd(nova.minimalna_cijena)>0)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return nova;
    }
    Berza operator+(Berza b, int n){
        Berza nova(b.minimalna_cijena, b.maksimalna_cijena);
        nova.elementi.resize(b.elementi.size());
        std::transform(b.elementi.begin(), b.elementi.end(), nova.elementi.begin(), std::bind(std::plus<int>(),std::placeholders::_1,n));
         if(nova.DajBrojCijenaVecihOd(nova.maksimalna_cijena)>0 || nova.elementi.size()-nova.DajBrojCijenaVecihOd(nova.minimalna_cijena)>0)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return nova;
    }
    Berza operator+(int n, Berza b){
        return b+n;
    }
    Berza operator+(Berza b1, Berza b2){
    if(b1.minimalna_cijena!=b2.minimalna_cijena || b1.maksimalna_cijena!=b2.maksimalna_cijena || b1.elementi.size()!=b2.elementi.size())
        throw std::domain_error("Nesaglasni operandi");
        
     Berza nova(b1.minimalna_cijena, b1.maksimalna_cijena);
     nova.elementi.resize(b1.elementi.size());
     std::transform(b1.elementi.begin(), b1.elementi.end(), b2.elementi.begin(), nova.elementi.begin(), std::plus<int>());
     
     if(nova.DajBrojCijenaVecihOd(nova.maksimalna_cijena)>0 || nova.elementi.size()-nova.DajBrojCijenaVecihOd(nova.minimalna_cijena)>0)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
     return nova;
    }
    Berza operator-(Berza b1, Berza b2){
    if(b1.minimalna_cijena!=b2.minimalna_cijena || b1.maksimalna_cijena!=b2.maksimalna_cijena || b1.elementi.size()!=b2.elementi.size())
        throw std::domain_error("Nesaglasni operandi");
        
     Berza nova(b1.minimalna_cijena, b1.maksimalna_cijena);
     nova.elementi.resize(b1.elementi.size());
     std::transform(b1.elementi.begin(), b1.elementi.end(), b2.elementi.begin(), nova.elementi.begin(), std::minus<int>());
     
     if(nova.DajBrojCijenaVecihOd(nova.maksimalna_cijena)>0 || nova.elementi.size()-nova.DajBrojCijenaVecihOd(nova.minimalna_cijena)>0)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
     return nova;
    }
    Berza &operator++(Berza &b){
        b=b+1;
        if(b.DajBrojCijenaVecihOd(b.maksimalna_cijena)>0 || b.elementi.size()-b.DajBrojCijenaVecihOd(b.minimalna_cijena)>0)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return b;
    }
    Berza operator++(Berza &b, int){
        Berza pomocna(b.minimalna_cijena, b.maksimalna_cijena);
        pomocna.elementi=b.elementi;
        ++b;
        if(b.DajBrojCijenaVecihOd(b.maksimalna_cijena)>0 || b.elementi.size()-b.DajBrojCijenaVecihOd(b.minimalna_cijena)>0)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return pomocna;
    }
    Berza &operator--(Berza &b){
        b=b-1;
        if(b.DajBrojCijenaVecihOd(b.maksimalna_cijena)>0 || b.elementi.size()-b.DajBrojCijenaVecihOd(b.minimalna_cijena)>0)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return b;
    }
    Berza operator--(Berza &b, int){
        Berza pomocna(b.minimalna_cijena, b.maksimalna_cijena);
        pomocna.elementi=b.elementi;
        --b;
        if(b.DajBrojCijenaVecihOd(b.maksimalna_cijena)>0 || b.elementi.size()-b.DajBrojCijenaVecihOd(b.minimalna_cijena)>0)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return pomocna;
    }
int main ()
{
	return 0;
}
