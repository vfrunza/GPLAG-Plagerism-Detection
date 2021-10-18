#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat);
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona);
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat);
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost = 6, bool treba_brisati = false);
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2);
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2);
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> m1, std::vector<double> v2);
template <typename TipElemenata>
Matrica<TipElemenata> Pomnozi(const Matrica<TipElemenata> m1, double br);


int main()
{
    Matrica<double> a,b;
    int m, n;
    std::vector<double> br;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A: ";
        std::cout<<std::endl;
        UnesiMatricu('A',a);

        std::cout << "Unesite red polinoma: ";
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i(0); i < n+1; i++){
            double koe;
            std::cin>>koe;
            br.push_back(koe);
        }
       IspisiMatricu(b = MatricniPolinom(a,br),10);
            
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    return 0;
}

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
            mat.elementi[i] = new TipElemenata[br_kolona];
    } catch(...) {
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
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost, bool treba_brisati)
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> treca;  //inicijalizuj trecu matricu
    try {
        //stvori trecu matricu
        treca = StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
        for(int i(0); i < m1.br_redova; i++)
            for(int j(0); j < m2.br_kolona; j++)
            treca.elementi[i][j] = 0; //postavi sve elemente na 0
        
        //izračunaj proizvod dvije matrice i dodijeli ga trećoj    
        for(int i(0); i < m1.br_redova; i++)
            for(int j(0); j < m2.br_kolona; j++)
                for(int k(0); k <m1.br_kolona; k++)
                    treca.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
    } catch(...) {
        //ako je bačen izuzetak unisti alociranu memoriju i proslijedi
        UnistiMatricu(treca);
        throw;
    }

    return treca;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> m1, std::vector<double> v2)
{
    if(m1.br_kolona != m1.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    //Inicijalizuj matrice koje nam trebaju
    Matrica<TipElemenata>  Polinom, m2(m1),m3,m4,m5;
    bool jednom(true);
    try {
        //Stvori potrebni matricu koja predstavlja polinom
        Polinom = StvoriMatricu<TipElemenata>(m1.br_kolona,m1.br_kolona);

        //prvi clan će uvjek biti jedinička matrica
        for(int i(0); i< m1.br_kolona; i++)
            for(int j(0); j< m1.br_kolona; j++)
                if(i != j)
                    Polinom.elementi[i][j] = 0;
                else
                    Polinom.elementi[i][i] = v2[0]; //odmah postavi elemente na glavnoj dijagonali na prvi koeficijent
        
        //kreni od drugog koeficijenta
        for(int i(1); i < v2.size(); i++) {
            if(i == 1){
                //m4 preuzima pokazivač na matricu koja se vrati kada se m1 pomnozi sa drugim koeficijentom
                m4 = Pomnozi(m1,v2[i]);
                //m5 preuzima pokazivač na Polinom
                m5 = Polinom;
                //Polinom sada pokazuje na drugi dinamički alocirani blok
                Polinom = ZbirMatrica(Polinom,m4);
                UnistiMatricu(m4); //obriši m4
                UnistiMatricu(m5); //obriši m5 (tj stari Polinom)
            }
            else{
                
                if(jednom){
                //postavi m4 na m1, da se ne bi dešavalo to više puta ima varijabla jednom    
                m4 = m1;
                jednom = false;
                }
                //s obzrom da m4 pokazuje na m1 nema potrebe da i pomocna m3 radi isto
                if(i != 2)
                    m3 = m4;
                
                //m4 pokazuje sada na novu matricu umjesto m1, m1 ostaje ista
                m4 = ProduktMatrica(m1,m4);
                //m5 pokazuje na Polinom
                m5 = Polinom;
                //Polinom pokazuje na novu matricu, m5 na stari Polinom, m2 pokazuje na matricu vraćenu iz funkcije Pomnozi
                Polinom = ZbirMatrica(Polinom ,m2 = Pomnozi(m4,v2[i]));
                
                //uništi matricu vraćenu iz Pomnozi, unisti staru matricu m4(na nju će pokazivati 3 ako ima više od 3 koeficijenta)
                UnistiMatricu(m2);
                UnistiMatricu(m3);
                //uništi m5 (stari Polinom)
                UnistiMatricu(m5);
            }
        }
    } catch(...) {
        //ako je bačen izuzetak prilikom alokacije, briši Polinom i proslijedi izuzetak
        UnistiMatricu(Polinom);
        throw;
    }

    //ostati će zadnji stepen matrice m1, ovdje ga uništavamo
    UnistiMatricu(m4);
    return Polinom;
}
template <typename TipElemenata>
Matrica<TipElemenata> Pomnozi(Matrica<TipElemenata> m1, double br)
{
    //kreiraj novu matricu
    Matrica<TipElemenata> m2(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    //prekopiraj elemente iz m1 u novu (nisam mogao direktno mnoziti m1 sa brojem jer zbog plitke kopije bi direktno mijenjalo m1 pa bi ga onda morao vraćati, lakše je ovako)
    for(int i(0); i < m1.br_kolona; i++)
        for(int j(0); j < m1.br_kolona; j++)
            m2.elementi[i][j] = m1.elementi[i][j];
    
    //pomnoži m2 sa koeficijentom        
    for(int i(0); i < m1.br_kolona; i++)
        for(int j(0); j < m1.br_kolona; j++)
            m2.elementi[i][j] *= br;
//vrati m2
    return m2;
}