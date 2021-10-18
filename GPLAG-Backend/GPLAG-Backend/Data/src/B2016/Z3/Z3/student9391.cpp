/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat) {
        if(!mat.elementi) return;
        for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova; mat.br_kolona=br_kolona;
        mat.elementi=new TipElemenata*[br_redova];
        for (int i=0; i< br_redova; i++) mat.elementi[i]=nullptr;
        try {
            for (int i=0; i< br_redova; i++)
            mat.elementi[i]=new TipElemenata[br_kolona];
        }
        catch(...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
template<typename TipElemenata>
    void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat) {
        for (int i=0; i<mat.br_redova; i++)
            for (int j=0; j<mat.br_kolona; j++) {
                std::cout<< ime_matrice << "(" <<i+1 << "," << j+1 << ") = ";
                std::cin >>mat.elementi[i][j];
            }
    }
    
template<typename TipElemenata>
    void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
        for (int i=0; i<mat.br_redova; i++) {
            for (int j=0; j<mat.br_kolona; j++) 
                std::cout<< std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
                std::cout << std::endl;
            }
                if (treba_brisati)
                UnistiMatricu(mat);

    }

template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));

        for (int i=0; i<m1.br_redova; i++)
            for (int j=0; j<m2.br_kolona; j++) 
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
                UnistiMatricu(m1);
                UnistiMatricu(m2);
                return m3;
        }

template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m5, const Matrica<TipElemenata> &m6) {
    if (m5.br_kolona!=m6.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m5.br_redova,m6.br_kolona));

        for (int i=0; i<m5.br_redova; i++) {
            for (int j=0; j<m6.br_kolona; j++) {
                auto suma(0);
                for (int k=0; k<m6.br_redova; k++) suma+=m5.elementi[i][k]*m6.elementi[k][j];
                //m3[i][j]+=m1[i][k]*m2[k][j];
                m3.elementi[i][j]=suma;
            }
        }
                //UnistiMatricu(m1);
                //UnistiMatricu(m2); //Ne brisati
                return m3;
        }

template <typename TipElemenata>
    Matrica<TipElemenata> MnozenjeMatriceKonstantom(const Matrica<TipElemenata> &m4, double konstanta) {
        auto m3(StvoriMatricu<TipElemenata>(m4.br_redova,m4.br_kolona));
        
            for (int i=0; i<m3.br_redova; i++) {
                for (int j=0; j<m3.br_kolona; j++) m3.elementi[i][j]=0;
            }

        for (int i=0; i<m4.br_redova; i++) {
            for (int j=0; j<m4.br_kolona; j++) 
                m3.elementi[i][j]=m4.elementi[i][j]*konstanta;
            }
        
                //UnistiMatricu(m4);
                return m3;
        }

template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1, const std::vector<TipElemenata> &v) {
    if (m1.br_redova!=m1.br_redova)
        throw std::domain_error("Matrica nije kvadratna");
    auto m_stepen(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    auto m_suma(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    auto jedinicna(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    //auto zbir(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    
    for (int i=0; i<jedinicna.br_redova; i++) {
            for (int j=0; j<jedinicna.br_kolona; j++) {
                if (i==j)
                jedinicna.elementi[i][j]=1;
                else 
                jedinicna.elementi[i][j]=0;
            }
    }
    
    for (int i=0; i<m_suma.br_redova; i++){
            for (int j=0; j<m_suma.br_kolona; j++) {
                m_suma.elementi[i][j]=0;
                m_stepen.elementi[i][j]=0;
            }
    }
    /*std::cout<< "matrica m_1" <<std::endl;
    IspisiMatricu(m1,10,6);*/
    
    for(int i = 0; i < v.size(); i++) {
    if (i==0) {
        m_stepen=ProduktMatrica(jedinicna,jedinicna); 
        //IspisiMatricu(m_stepen,10,6);
        
    }
    else {
        //std::cout<<"Provjera"<<std::endl;
        //IspisiMatricu(m_stepen,10,6);
        //IspisiMatricu(m1,10,6);
        m_stepen=ProduktMatrica(m1,m_stepen);
        //IspisiMatricu(m_stepen,7,6);
        //std::cout<<"Kraj provjere"<<std::endl;
    }
    //std::cout<< "matrica^"<< i << " koeficijent"<< v.at(i) << std::endl;
    //std::cout<< "zbir" <<std::endl;
    
    //IspisiMatricu(zbir,7,6);
    //std::cout<< "suma" <<std::endl;
    m_suma = ZbirMatrica(m_suma,MnozenjeMatriceKonstantom(m_stepen,v.at(i)));
    //IspisiMatricu(m_suma,7,6);
    
    }
    
    UnistiMatricu(m_stepen);
    //UnistiMatricu(zbir);
    UnistiMatricu(jedinicna);
    return m_suma;
}

int main () {
    Matrica<double> a,f;
    int m,n;
    double broj;
    std::vector<double> v;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a=StvoriMatricu<double>(m,m);
        //b=StvoriMatricu<double>(m,m);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A',a);
        /*std::cout << "Unesi Matricu B:\n";
        UnesiMatricu('B',b);
        std::cout << "Zbir ove dvije matrice je:\n";
        IspisiMatricu(c=ZbirMatrica(a,b),7);*/
        
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        
        /*std::cout << "Proizvod matrice sa konstantom je:\n";
        IspisiMatricu(e=MnozenjeMatriceKonstantom(a,n),7);*/

        
        std::cout << "Unesite koeficijente polinoma: ";
        for (int i=0; i<=n; i++) {
            std::cin >> broj;             
            v.push_back(broj);
        }
        
        /*std::cout << "Proizvod ove dvije matrice je:\n";
        IspisiMatricu(d=ProduktMatrica(a,b),7);*/
        
        //std::cout << "Matricni polinom je:\n";
        f=MatricniPolinom(a,v);
        IspisiMatricu(f,10);

    }
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!";
    }    
    UnistiMatricu(a); 
    UnistiMatricu(f);
	return 0;
}