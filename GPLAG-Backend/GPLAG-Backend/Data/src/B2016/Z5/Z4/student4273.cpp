/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cin; using std::cout; using std::endl;

template <typename NekiTip>
class GMatrica {
    NekiTip gmat[4][4];
    int br_redova, br_kolona;
    public:
    //Konstruktori
    GMatrica(); 
    GMatrica(int br_redova, int br_kolona, int inic_vr=NekiTip()); 
    /*template <typename Tip1>
    GMatrica(GMatrica<Tip1> mat);
    template <typename Tip2>
    GMatrica(Tip2 niz); */
    GMatrica(std::vector<std::vector<NekiTip>> vek); 
    //Sekvencijski konstruktor
    int DajBrojRedova() { return br_redova; };
    int DajBrojKolona() { return br_kolona; };
    //Operatori
    template <typename Tip>
    friend GMatrica<Tip> operator+(const GMatrica &m1, const GMatrica &m2);
    template <typename Tip>
    friend GMatrica<Tip> operator-(const GMatrica &m1, const GMatrica &m2);
    template <typename Tip>
    friend GMatrica<Tip> operator*(const GMatrica &m1, const GMatrica &m2);
    template <typename Tip>
    friend GMatrica<Tip> operator*(const GMatrica &m, int broj);
    template <typename Tip>
    friend GMatrica<Tip> operator*(int broj, const GMatrica &m);
    //Operator “*” također treba da podržava množenje broja sa matricom odnosno matrice sa brojem
    //Odgovarajuće operatorske funkcije ne treba da budu funkcije članice i obavezno ih treba implementirati izvan deklaracije klase
};

//Konstruktori
template <typename NekiTip>
GMatrica<NekiTip>::GMatrica() : br_redova(0), br_kolona(0) { 
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            gmat[i][j]=NekiTip();
        }
    }
}
template <typename NekiTip>
GMatrica<NekiTip>::GMatrica(int br_redova, int br_kolona, int inic_vr) {
    if (br_redova<0 || br_redova >4 || br_kolona<0 || br_kolona>4) throw std::logic_error ("Ilegalan format matrice");
    GMatrica::br_redova(br_redova), GMatrica::br_kolona(br_kolona);
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            gmat[i][j]=NekiTip(inic_vr);
        }
    }
}
/*
template <typename Tip, typename Tip1> //, typename Tip1>
GMatrica<Tip>::GMatrica(GMatrica<Tip1> mat) {}

template <typename NekiTip, typename Tip2>
GMatrica<NekiTip>::GMatrica(Tip2 niz) {
    br_kolona=4; br_redova=4;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            gmat[i][j]=NekiTip(niz[i][j]); //niz pok?
        }
    }
}*/

template <typename NekiTip>
GMatrica<NekiTip>::GMatrica(std::vector<std::vector<NekiTip>> vek) {
     //Provjeri je li prazan!
    if (vek.size()<0 || vek.size()>4 || vek[0].size()<0 || vek[0].size()>4) throw std::logic_error ("Ilegalan format matrice");
    br_redova=vek.size();
    br_kolona=vek[0].size(); 
    for (int i=0; i<br_redova; i++) {
        for (int j=0; j<br_kolona; j++) {
            gmat[i][j]=vek[i][j];
        }
    }
}
 
template <typename NekiTip>
GMatrica<NekiTip> operator+(const GMatrica<NekiTip> &m1, const GMatrica<NekiTip> &m2) {
    if (m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona()) throw std::domain_error ("Nedozvoljena operacija");
    
    return m1;
}
template <typename NekiTip>
GMatrica<NekiTip> operator-(const GMatrica<NekiTip> &m1, const GMatrica<NekiTip> &m2) {
    if (m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona()) throw std::domain_error ("Nedozvoljena operacija");

    return m1;
}
template <typename NekiTip>
GMatrica<NekiTip> operator*(const GMatrica<NekiTip> &m1, const GMatrica<NekiTip> &m2) {
    if (m1.DajBrojRedova()!=m2.DajBrojKolona() || m1.DajBrojKolona()!=m2.DajBrojRedova()) throw std::domain_error ("Nedozvoljena operacija");
    
    return m1;
}

 template <typename NekiTip>
GMatrica<NekiTip> operator*(const GMatrica<NekiTip> &m, int broj) {
    return m;
}
template <typename NekiTip>
GMatrica<NekiTip> operator*(int broj, const GMatrica<NekiTip> &m) {
    return m;
}

int main ()
{
    cout << "Sto nece da se kompajlira?" << endl;
    GMatrica<int> mat;
    cout << mat.DajBrojRedova() << " " << mat.DajBrojKolona() << endl;
	return 0;
}