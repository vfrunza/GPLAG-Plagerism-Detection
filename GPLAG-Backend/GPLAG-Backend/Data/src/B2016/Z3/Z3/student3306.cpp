/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <new>
#include <iomanip>
#include <vector>

template <typename TipElementa>
struct Matrica{
    int br_redova,br_kolona;
    TipElementa **elementi=nullptr;
};

template<typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> mat){
    if (!mat.elementi) return;
    for (int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template<typename TipElementa>
Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElementa> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi=new TipElementa *[br_redova];
    for (int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
    try{
        for (int i=0;i<br_redova;i++)
            mat.elementi[i]=new TipElementa[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElementa>
void UnesiMatricu (char ime_matrice, Matrica<TipElementa> &mat){
    for (int i=0;i<mat.br_redova;i++)
        for (int j=0;j<mat.br_kolona;j++){
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template<typename TipElementa>
void IspisiMatricu (const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost=6 , bool treba_brisati=false){
    for (int i=0; i<mat.br_redova; i++){
        for (int j=0; j<mat.br_kolona; j++){
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if (treba_brisati == true)
        UnistiMatricu(mat);
}

template<typename TipElementa>
void ZbirMatrica(Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2){
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for (int i=0;i<m1.br_redova;i++)
        for (int j=0;j<m1.br_kolona;j++)
            m1.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
}

template<typename TipElementa>
Matrica<TipElementa> ProduktMatrica(const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2){
    if (m1.br_kolona != m2.br_redova)
        throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElementa>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m1.br_redova; j++){
            m3.elementi[i][j] = 0;
        }
    }
    for (int i=0;i<m1.br_redova;i++)
        for (int j=0;j<m2.br_kolona;j++){
            int tmp=0;
            for (int k=0;k<m1.br_kolona;k++){
                tmp=tmp+(m1.elementi[i][k] * m2.elementi[k][j]);
            }
            m3.elementi[i][j]=tmp;
        }
    return m3;
}

template<typename TipElementa>
Matrica<TipElementa> KopijaMatrice(const Matrica<TipElementa> &a){
    Matrica<TipElementa> b;
    b = StvoriMatricu<TipElementa>(a.br_redova,a.br_kolona);
    for (int i=0;i<a.br_redova;i++)
        for (int j=0;j<a.br_kolona;j++)
            b.elementi[i][j] = a.elementi[i][j];
    return b;
}
template<typename TipElementa>
Matrica<TipElementa> ProizvodSkalara(const Matrica<TipElementa> &a, double skalar){
    Matrica<TipElementa> b;
    b = StvoriMatricu<TipElementa>(a.br_redova, a.br_kolona);
     for (int i=0;i<a.br_redova;i++)
        for (int j=0;j<a.br_kolona;j++)
            b.elementi[i][j] = a.elementi[i][j]*skalar;
    return b;
}

template<typename TipElementa>
void ProizvodSkalaraa (Matrica<TipElementa> &a, double skalar){
    for (int i=0; i<a.br_redova; i++)
        for (int j=0; j<a.br_kolona; j++)
            a.elementi[i][j] = a.elementi[i][j] * skalar;
}

template<typename TipElementa>
Matrica<TipElementa> MatricniPolinom(const Matrica<TipElementa> &m1, std::vector<double> koef){
    if (m1.br_redova != m1.br_kolona){
        UnistiMatricu(m1);
        throw std::domain_error("Matrica mora biti kvadratna");
    }
    auto m3(StvoriMatricu<TipElementa>(m1.br_redova,m1.br_kolona));
    auto pomoc=m3;
    
    for (int i=0;i<m1.br_redova;i++)
            for (int j=0;j<m1.br_kolona;j++)
                m3.elementi[i][j]=0;
    
    if (koef.size()==0){
        return m3;
    }
    auto jed_mat(StvoriMatricu<TipElementa>(m1.br_redova,m1.br_kolona));
    for (int i=0;i<m1.br_redova;i++){
        for (int j=0;j<m1.br_kolona;j++){
            if (i==j)
                jed_mat.elementi[i][j]=1;
            else
                jed_mat.elementi[i][j]=0;
        }
    }

    auto mat(KopijaMatrice(m1));
    try{
        for (int i=0; i<koef.size(); i++){
            if (i==0){
                ProizvodSkalaraa(jed_mat, koef[i]);
            }
            else if (i==1){
                m3=ProizvodSkalara(m1, koef[i]);
            }
            else if (i>1){
                auto tmp = mat;
                mat = ProduktMatrica(mat, m1);
                auto pom = ProizvodSkalara(mat, koef[i]);
                ZbirMatrica<TipElementa>(m3,pom);
                UnistiMatricu(tmp);
                UnistiMatricu(pom);
            }
        }
        UnistiMatricu(mat);
        ZbirMatrica<TipElementa>(m3, jed_mat);
        UnistiMatricu(jed_mat);
        UnistiMatricu(pomoc);
        return m3;
    } catch(...) {
        UnistiMatricu(mat);
        UnistiMatricu(m3);
        UnistiMatricu(jed_mat);
        throw;
    }
    
}

int main ()
{
    Matrica<int> a, b;
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try{
        a=StvoriMatricu<int>(n,n);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A',a);
        std::cout << "Unesite red polinoma: ";
        int red_polinoma;
        std::cin >> red_polinoma;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> koef;
        double k;
        for (int i=0;i<=red_polinoma;i++){
            std::cin >> k;
            koef.push_back(k);
        }
        b = MatricniPolinom(a, koef);
        IspisiMatricu(b, 10);
    }
    catch(std::bad_alloc){
        UnistiMatricu(a); UnistiMatricu(b);
        std::cout << "Nema dovoljno memorije\n";
    }
    UnistiMatricu(a); UnistiMatricu(b);
	return 0;
}