#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <vector>
template <typename Tip>
struct Matrica {
    int br_redova,br_kolona;
    Tip **elemenat=nullptr;
};
template <typename Tip>
void UnistiMatricu(Matrica<Tip>mat)
{
    if(!mat.elemenat) return;
    for(int i(0); i<mat.br_redova; i++)
        delete[] mat.elemenat[i];
    delete[] mat.elemenat;
    mat.elemenat=nullptr;
}
template <typename Tip>
Matrica<Tip>StvoriMatricu(int br_redova,int br_kolona)
{
    Matrica<Tip>m;
    m.br_kolona=br_kolona;
    m.br_redova=br_redova;
    m.elemenat=new Tip*[m. br_redova];
    for(int i(0); i<m. br_redova; i++) m.elemenat[i]=nullptr;
    try {
        for(int i(0); i<m. br_redova; i++)
            m.elemenat[i]=new Tip[m. br_kolona];
    } catch (...) {
        UnistiMatricu(m);
        throw;
    }
    for(int i(0); i<br_redova; i++)
        for(int j(0); j<br_kolona; j++)
            m.elemenat[i][j]=0;
    return m;
}
template <typename Tip>
void UnesiMatricu(char ime_matrice,Matrica<Tip> &m)
{
    for(int i(0); i<m.br_redova; i++)
        for(int j(0); j<m.br_kolona; j++) {
            std::cout << ime_matrice<< "("<<i+1<<","<<j+1<<") = ";
            std::cin >> m.elemenat[i][j];
        }
}
template <typename Tip>
void IspisiMatricu(const Matrica<Tip>&m,int sirina_ispisa,int preciznost,bool treba_brisati)
{
    for(int i(0); i<m.br_redova; i++) {
        for(int j(0); j<m.br_kolona; j++)
            std::cout << std::setw(10)<<std::setprecision(6)<<m.elemenat[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(m);
}
template <typename Tip>
Matrica <Tip> ZbirMatrica(const Matrica<Tip>&m1,const Matrica<Tip>&m2)
{
    if(m1.br_kolona!=m2.br_kolona||m1.br_redova!=m2.br_redova)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");

    auto m3(StvoriMatricu<Tip>(m1.br_redova,m1.br_kolona));
    for(int i(0); i<m1.br_redova; i++)
        for(int j(0); j<m1.br_kolona; j++) {
            m3.elemenat[i][j]=m1.elemenat[i][j]+m2.elemenat[i][j];
        }
    return m3;

}
template <typename Tip,typename PokTip>
Matrica<Tip> ProduktMatriceISkalara(const Matrica<Tip>&m,PokTip p)
{
    for(int i(0); i<m.br_redova; i++)
        for(int j(0); j<m.br_kolona; j++)
            m.elemenat[i][j]=m.elemenat[i][j]*(*p);
    return m;


}
template <typename Tip>
Matrica <Tip>ProduktMatrica(const Matrica<Tip>&m1,const Matrica<Tip>&m2)
{
    if(m1.br_kolona!=m2.br_redova)
        throw ("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<Tip>(m1.br_redova,m2.br_kolona));
    for(int i(0); i<m1.br_redova; i++) {
        for(int j(0); j<m2.br_kolona; j++) {
            double suma(0);
            for(int k(0); k<m2.br_redova; k++)
                suma+=m1.elemenat[i][k]*m2.elemenat[k][j];
            m3.elemenat[i][j]=suma;
        }
    }
    return m3;

}
template <typename Tip,typename PokTip>
Matrica<Tip>MatricniPolinom(const Matrica<Tip>m,int n,PokTip p)
{
    if (n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(m.br_kolona!=m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    auto rezultat(StvoriMatricu<Tip>(m.br_redova,m.br_kolona));
    rezultat. br_redova=m. br_redova;
    rezultat. br_kolona=m. br_kolona;
    for(int brojac(0); brojac<=n; brojac++) {
        try {
            auto jedinicna(StvoriMatricu<Tip>(m.br_redova,m.br_kolona));
            for(int i(0); i<m.br_redova; i++)
                for(int j(0); j<m.br_kolona; j++) {
                    if(i==j) jedinicna.elemenat[i][j]=1;
                    else jedinicna.elemenat[i][j]=0;
                }
            for(int j=0; j<brojac; j++) {
                auto pomocna=jedinicna;
                try {
                    jedinicna=ProduktMatrica(m,jedinicna);
                    UnistiMatricu(pomocna);
                } catch(...) {
                    UnistiMatricu(pomocna);
                    throw;
                }
            }
            jedinicna=ProduktMatriceISkalara(jedinicna,p);

            try {
                auto temp=rezultat;
                rezultat=ZbirMatrica(rezultat,jedinicna);
                UnistiMatricu(jedinicna);
                UnistiMatricu(temp);
            } catch(...) {
                UnistiMatricu(jedinicna);
                throw;

            }
        }


        catch(...) {
            UnistiMatricu(rezultat);
            throw;
        }
        p++;
    }
    return rezultat;

}
int main ()
{
    Matrica<double> a,e;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int m;
    std::cin >> m;

    try {
        a. br_kolona=m;
        a. br_redova=m;
        a=StvoriMatricu<double>(m,m);
        std::cout << "Unesite elemente matrice A:"<< std::endl;
        UnesiMatricu('A',a);

        std::cout << "Unesite red polinoma: ";
        int red;
        try {
            std::cin >> red;
            if(red<0) throw std::domain_error("Neispravan stepen polinoma");
        } catch(std::domain_error i) {
            UnistiMatricu(a);
            std::cout << "Izuzetak: "<<i.what() << std::endl;
            return 0;
        }
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<int>v(red+1);
        for(int i(0); i<=red; i++) {
            std::cin >> v.at(i);
        }
        try {
            IspisiMatricu(MatricniPolinom(a,red,v.begin()),10,6,true);
            UnistiMatricu(a);
        } catch(std::domain_error izuzetak) {
            std::cout << "Izuzetak: "<<izuzetak.what() << std::endl;
            UnistiMatricu(a);
        }
    } catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!"<< std::endl;
        UnistiMatricu(a);
    }
    return 0;
}
