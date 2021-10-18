#include <iostream>
#include <new>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <vector>
template <typename TipElemenata>        //  Funkcije (odnosno strukture) Matrica, UnistiMatricu, StvoriMatricu, UnesiMatricu, IspisiMatricu su "pokupljene" sa predavanja. 
 struct Matrica {                       //  Samo je IspisiMatricu malo modifikovana.
 int br_redova, br_kolona;
 TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
 };
template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) {
 if(!mat.elementi) return;
 for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
 delete[] mat.elementi;
 mat.elementi = nullptr;
 }

template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
 Matrica<TipElemenata> mat;
 mat.br_redova = br_redova; mat.br_kolona = br_kolona;
 mat.elementi = new TipElemenata*[br_redova];
 for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
 try {
 for(int i = 0; i < br_redova; i++)
 mat.elementi[i] = new TipElemenata[br_kolona];
 }
 catch(...) {
 UnistiMatricu(mat);
 throw;
 }
 return mat;
 }
 
 template <typename TipElemenata>
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
 for(int i = 0; i < mat.br_redova; i++)
 for(int j = 0; j < mat.br_kolona; j++) {
 std::cout << ime_matrice
 << "(" << i + 1 << "," << j + 1 << ") = ";
 std::cin >> mat.elementi[i][j];
 }
 }
 template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=8,bool treba_brisati=false) {
     for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) <<std::setprecision(preciznost)<< mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati)
        UnistiMatricu(mat);
 }
template <typename Tip>
Matrica<Tip> ProduktMatrica(Matrica<Tip> a, Matrica<Tip> b)     //  Funkcija koja racuna mnozenje matrica. Radi i za NEkvadratne matrice.
{
    if(a.br_kolona!=b.br_redova)    throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto c(StvoriMatricu<Tip>(a.br_redova,b.br_kolona));
    double s(0);
    for(int i=0;i<a.br_redova;i++){
        for(int j=0;j<b.br_kolona;j++){
            s=0;
            for(int k=0;k<a.br_kolona;k++)
                s+=a.elementi[i][k]*b.elementi[k][j];
            c.elementi[i][j]=s;
        }
    }
    return c;
}
template <typename Tip>     //  Funkcija koja mi govori da li je matrica kvadratna ili ne.
bool NijeKvadrat(Matrica<Tip> a)
{
    if(a.br_kolona!=a.br_redova) return true;
    return false;
}
template<typename Tip>
void Jedinica(Matrica<Tip> a){      //  Funkcija koja postavlja elemente poslane matrice na 1.
    for(int i=0;i<a.br_kolona;i++)
    {
        for(int j=0;j<a.br_redova;j++)
        {
            if(i==j)
                a.elementi[i][j]=1;
            else
                a.elementi[i][j]=0;
        }
    }
}
template<typename Tip, typename Tip2>          //  Funkcija koja poslanu matricu mnozi sa skalarom.
Matrica<Tip> Skalar (Matrica<Tip> a, Tip2 p){
    auto q(StvoriMatricu<Tip>(a.br_kolona,a.br_redova));
    for(int i=0;i<a.br_redova;i++)
        for(int j=0;j<a.br_kolona;j++)
            q.elementi[i][j]=a.elementi[i][j]*p;
    return q;
}
template<typename Tip>      //  Funkcija na prvoj matrici dodaje drugu matricu.
void Saberi(Matrica<Tip>a, Matrica<Tip> b){
    for(int i=0;i<a.br_redova;i++)
        for(int j=0;j<a.br_kolona;j++)
            a.elementi[i][j]+=b.elementi[i][j];
}
template<typename Tip>
void Preuzmi(Matrica<Tip> a, Matrica<Tip>b){    //  Funkcija radi tako sto 1. matrica poprima vrijednosti elemenata 2. matrice.
    for(int i=0;i<a.br_redova;i++)
        for(int j=0;j<a.br_kolona;j++)
            a.elementi[i][j]=b.elementi[i][j];
}
template <typename Tip>
Matrica<Tip> MatricniPolinom(Matrica<Tip> a,std::vector<double>v){
    if(NijeKvadrat(a))  throw std::domain_error("Matrica mora biti kvadratna");
    auto  b(StvoriMatricu<Tip>(a.br_redova,a.br_kolona));
    Jedinica(b);    //  Postavljamo je na jedinicnu matricu.
    if(v.empty())    return b;
    auto k(Skalar(b,v[0]));     //  k je krajnji rezultat.
    for(int i=1;i<v.size();i++)
    {
        auto p=ProduktMatrica(b,a);     //  Matrica p nam je cisti stepen neke matrice. 
        Preuzmi(b,p);                   //  Sad b ima iste vrijednosti kao i p.
        auto q=Skalar(b,v[i]);          //  q matrica je matrica koju dobijemo skalarnim mnozenjem b i koef. polinoma.
        Saberi(k,q);                    //  Sabira matricu k i q (odnosno na k dodajemo q). 
        UnistiMatricu(q);               //  Unistavamo matricu k i q.
        UnistiMatricu(p);
    }
    UnistiMatricu(b);                   //  I na kraju unistavamo matricu b.
    return k;
}
 
 
 int main(){    //  Obicni main za unos i ispis.
     std::cout<<"Unesite dimenziju kvadratne matrice: ";
     int n;
     std::cin>>n;
     auto a(StvoriMatricu<double>(n,n));
     std::cout<<"Unesite elemente matrice A: "<<std::endl;
     UnesiMatricu('A',a);
     std::cout<<"Unesite red polinoma: ";
     std::cin>>n;
     std::cout<<"Unesite koeficijente polinoma: ";
     std::vector<double> v(n+1);
     for(int i=0;i<=n;i++)
        std::cin>>v[i];
     auto p(MatricniPolinom(a,v));
     IspisiMatricu(p,10);
     UnistiMatricu(a);
     UnistiMatricu(p);
     return 0;
 }