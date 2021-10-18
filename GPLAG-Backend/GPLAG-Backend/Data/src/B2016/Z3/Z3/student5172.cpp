#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include<vector>
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
template<typename TipElemenata>
Matrica<TipElemenata>ProduktMatrica(const Matrica<TipElemenata> &a, const Matrica<TipElemenata> &b)
{
    if(a.br_kolona!=b.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto produkt(StvoriMatricu<TipElemenata>(a.br_redova, b.br_kolona));
    for(int i=0; i<a.br_redova; i++) {
        for(int j=0; j<b.br_kolona; j++) {
            int zbir=0;
            for(int k=0; k<a.br_kolona; k++) {
                zbir=zbir+a.elementi[i][k]*b.elementi[k][j];
            }
            produkt.elementi[i][j]=zbir;
        }
    }
    return produkt;
}
template<typename TipElemenata, typename TipElementa1>
void MnozenjeSaSkalarom(TipElementa1 broj, const Matrica<TipElemenata> &a)
{
    
    for(int i=0; i<a.br_redova; i++) {
        for(int j=0; j<a.br_kolona; j++) {
            a.elementi[i][j]=a.elementi[i][j]*broj;
        }
    }
   
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
                                  const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata>MatricniPolinom(const Matrica<TipElemenata> &a, std::vector<double>v)
{
    if(a.br_redova!=a.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata>rez(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    Matrica<TipElemenata>pom(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    Matrica<TipElemenata>jedinicna(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    for(int i=0; i<a.br_redova; i++) {
        for(int j=0; j<a.br_kolona; j++) {
            if(i==j)jedinicna.elementi[i][j]=1;
            else {
                jedinicna.elementi[i][j]=0;
            }
        }
    }
    for(int i=0; i<a.br_redova; i++) {
        for(int j=0; j<a.br_kolona; j++) {
           
                pom.elementi[i][j]=a.elementi[i][j];
            
        }
    } 
    Matrica<TipElemenata> h;    Matrica<TipElemenata> p;Matrica<TipElemenata> f;

    for(int i=0;  i<v.size(); i++) {
        if(i==0) {
            MnozenjeSaSkalarom(v[i], jedinicna);
            for(int i=0; i<a.br_redova; i++) {
        for(int j=0; j<a.br_kolona; j++) {
           
                rez.elementi[i][j]=jedinicna.elementi[i][j];
            
        }
    } 
        } else if(i==1) {
            MnozenjeSaSkalarom(v[i], pom);
            f=ZbirMatrica(rez,pom);
             for(int i=0; i<f.br_redova; i++) {
        for(int j=0; j<f.br_kolona; j++) {
           
                rez.elementi[i][j]=f.elementi[i][j];
            
        }
    } UnistiMatricu(f);
        } else {
            for(int i=0; i<a.br_redova; i++) {
        for(int j=0; j<a.br_kolona; j++) {
           
                pom.elementi[i][j]=a.elementi[i][j];
            
        }
    } 
            for(int k=1; k<i; k++) {
                p=ProduktMatrica(pom, a);
                for(int i=0; i<p.br_redova; i++) {
        for(int j=0; j<p.br_kolona; j++) {
           
               pom.elementi[i][j]=p.elementi[i][j];
            
        }
    } 
               UnistiMatricu(p); 
            }
            MnozenjeSaSkalarom(v[i], pom);
            h=ZbirMatrica(rez, pom); 
            for(int i=0; i<h.br_redova; i++) {
        for(int j=0; j<h.br_kolona; j++) {
           
                rez.elementi[i][j]=h.elementi[i][j];
            
        }
    } 
           UnistiMatricu(h); 
            
        }
    }
     UnistiMatricu(jedinicna); 
    UnistiMatricu(pom); 
    return rez; 
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,
                   int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) <<std::setprecision(preciznost)<< mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati==true){
       UnistiMatricu(mat); 
      
    }
}


int main()
{
    Matrica<double> a, b,c; // AUTOMATSKA INICIJALIZACIJA!!!
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    std::cin.ignore(1000, '\n');
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: "; 
        int n; 
        std::cin>>n; 
        std::cin.ignore(1000, '\n');
        std::vector<double>v(n+1);
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i=0; i<=n; i++) {
            double x; 
            std::cin>>x; 
            v[i]=x; 
        }
        try {
            IspisiMatricu(c=MatricniPolinom<double>(a, v), 10);
        } catch(std::domain_error iz) {
            std::cout << iz.what()<<"\n";
        }
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(c);
    UnistiMatricu(a);
    UnistiMatricu(b);
   
    return 0;
}
