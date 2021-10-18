/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename Tip>
class GMatrica {
    Tip mat[4][4];
    int s_kolone, s_redovi;
    public:
    GMatrica() { s_kolone=0; s_redovi=0;}
    GMatrica(int redovi, int kolone, Tip a);
    template <typename TipM>
    GMatrica(GMatrica<TipM> m);
    template <typename Tip1>
    GMatrica(Tip1 m[4][4]);
    template <typename Tip1>
    GMatrica(std::vector<std::vector<Tip1>> v);
    GMatrica(std::initializer_list<Tip> l);
    int DajBrojRedova() const { return s_redovi; }
    int DajBrojKolona() const { return s_kolone; }
    template <typename T>
//nisu funkcije clanice
    friend GMatrica operator + (GMatrica<Tip> a, GMatrica<T> b);//decltype ce trebati
    template <typename T>
    friend GMatrica operator - (GMatrica<Tip> a, GMatrica<T> b);
    template <typename T>
    friend GMatrica operator * (GMatrica<Tip> a, GMatrica<T> b);
//jesu funkcije clanice
    template <typename T>
    friend GMatrica operator += (GMatrica<Tip> a, GMatrica<T> b);
    template <typename T>
    friend GMatrica operator -= (GMatrica<Tip> a, GMatrica<T> b);
    template <typename T>
    friend GMatrica operator *= (GMatrica<Tip> a, GMatrica<T> b);
    friend GMatrica operator == (GMatrica<Tip> a, GMatrica<Tip> b);
    friend GMatrica operator != (GMatrica<Tip> a, GMatrica<Tip> b);
    GMatrica operator ()(GMatrica<Tip> a);
    GMatrica operator [](GMatrica<Tip> a);
    friend std::ostream &operator << (std::ostream &ispisi, GMatrica<Tip> a);
    friend std::istream &operator >> (std::istream &upisi, GMatrica<Tip> a);
};
template <typename Tip>
GMatrica<Tip>::GMatrica(int redovi, int kolone, Tip a) { 
    if (redovi<0 || redovi>4 || kolone<0 || kolone>4) throw std::logic_error("Ilegalan format matrice");
    s_kolone=kolone; s_redovi=redovi;  
    for (int i=0; i<redovi; i++)
        for (int j=0; j<kolone; j++)
            mat[i][j]=a;
}/*
template <typename Tip, typename TipM>
GMatrica<Tip>::GMatrica(GMatrica<TipM> m) {
    
}*/

/*
template <typename Tip, typename T>
GMatrica<Tip>::GMatrica operator * (GMatrica<Tip> a, GMatrica<T> b) {
    if () throw std::domain_error ("Nedozvoljena operacija");
}*/

int main ()
{
	return 0;
}