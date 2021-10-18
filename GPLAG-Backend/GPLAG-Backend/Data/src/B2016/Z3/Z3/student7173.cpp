/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>

template<typename Tip_Elementa>
struct Matrica {
    int broj_redova, broj_kolona;
    Tip_Elementa **elementi = nullptr;
};

template<typename Tip_Elementa>
void UnistiMatricu(Matrica<Tip_Elementa>matrica) {
    if(!matrica.elementi) return;
    for(int i(0); i<matrica.broj_redova; i++) 
        delete[] matrica.elementi[i];
    delete[] matrica.elementi;
    matrica.elementi=nullptr;
}

template<typename Tip_Elementa>
Matrica<Tip_Elementa> StvoriMatricu(int broj_redova, int broj_kolona) {
    Matrica<Tip_Elementa> matrica;
    
}
template<typename tip>
Matrica<tip> ProduktMatrica(const Matrica<tip> &m1, const Matrica<tip> &m2) {
    if(m1.broj_redova!=m2.broj_kolona || m1.broj_kolona!=m2.broj_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
    
}
int main ()
{
    Matrica<double>a, b, c;
    int m;
    cout<<"Unesite dimenziju kvadratne matrice: ";
    cin>>a;
    try {
        a=StvoriMatricu<auto>(m, m);
        b=StvoriMatricu<auto>(m, m);
    }
	return 0;
}