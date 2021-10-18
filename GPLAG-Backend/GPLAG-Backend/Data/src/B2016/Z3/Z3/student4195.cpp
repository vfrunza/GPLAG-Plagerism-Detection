#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

//KOPIRAN JE SAMO ONAJ DIO PROGRAMA ZADAN NA PREDAVANJU, NA KOJI TREBA DOPUNITI ONO STO SE TRAZI U ZADATKU 
//( U  SLUCAJU DA BUDE OZNACEN ZADATAK KAO "PREPISAN" RADI TOG JEDINOG PASTE-A)

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];

    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;

    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona](); //Stavi na podrazumijevanu vrijednost
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<< mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati)
        UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m2.br_kolona; j++){
            TipElemenata suma{};
            for(int k=0; k<m1.br_kolona; k++){
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> PomnoziSaRealnim(const Matrica<TipElemenata> &mat, double koef){
    auto rez(StvoriMatricu<TipElemenata>(mat.br_kolona,mat.br_kolona));
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            rez.elementi[i][j]=mat.elementi[i][j]*koef;
        }
    }
    return rez;
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, std::vector<double> koeficijenti){
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    auto rezultat(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    auto kopija_mat(StvoriMatricu<TipElemenata>(mat.br_kolona,mat.br_kolona)); 
    for(int i=0; i<mat.br_kolona; i++){
        for(int j=0; j<mat.br_kolona; j++)
            kopija_mat.elementi[i][j]=mat.elementi[i][j];
    }
    bool nije_vise_pocetna(false);
    for(int i=0; i<koeficijenti.size(); i++){
        if(i==0) {
            for(int i=0; i<rezultat.br_redova; i++){
                for(int j=0; j<rezultat.br_kolona; j++){
                    if(i==j) rezultat.elementi[i][j]=1;
                     else rezultat.elementi[i][j]=0;
                }
            }
            auto plitka(rezultat);
            rezultat=PomnoziSaRealnim(rezultat,koeficijenti.at(0));  //Prvi sabirak
            UnistiMatricu(plitka);
            continue;
        }
        //Kreiranje sabirka uz vodjenje racuna o curenju memorije
        if(nije_vise_pocetna){
            auto plitka_kop_proizvoda(kopija_mat);
            kopija_mat=ProduktMatrica(kopija_mat,mat);
            UnistiMatricu(plitka_kop_proizvoda);
        }
        else 
            nije_vise_pocetna=true;
        
        auto pomnozena(PomnoziSaRealnim(kopija_mat,koeficijenti.at(i))); 
        
        auto plitka_kop(rezultat); 
        rezultat=ZbirMatrica(rezultat,pomnozena); 
        
        UnistiMatricu(plitka_kop); //Brisemo matricu koja je bila samo "faza" sabiranja a ne konacni rezultat
        UnistiMatricu(pomnozena);
    }
    UnistiMatricu(kopija_mat); //Ostala nam je na kraju zadnja faza mnozenja koju moramo izbrisati
    return rezultat;
}

int main()
{
    Matrica<double> a,mat_pol; // AUTOMATSKA INICIJALIZACIJA!!!
    int n,red_pol;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>red_pol;
        std::vector<double> koeficijenti(red_pol+1);
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<=red_pol; i++) std::cin >> koeficijenti.at(i);
        mat_pol= MatricniPolinom(a,koeficijenti);
        IspisiMatricu(mat_pol,10);
        
    } 
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(mat_pol);
    UnistiMatricu(a);
    return 0;
}
