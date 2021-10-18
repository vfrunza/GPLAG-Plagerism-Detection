#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>


using namespace std;


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


template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,
                   int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) <<setprecision(preciznost)<< mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati)
    UnistiMatricu(mat);
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




template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,
                                     const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_redova )
        throw std::domain_error("Matrice nisu saglasne za mnozenje");

    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));


    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m2.br_kolona; j++) {
            TipElemenata s=TipElemenata();
            for (int k = 0; k < m1.br_kolona; k++) {
                s+=m1.elementi[i][k] * m2.elementi[k][j];
            }
            m3.elementi[i][j]=s;
        }
    }
    return m3;
}



template <typename TipElemenata>
Matrica<TipElemenata> ProduktKoeficijentaIMatrice(const Matrica<TipElemenata> &m1,
        const double& k)
{

    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));


    for(int i = 0; i < m3.br_redova; i++) {
        for(int j = 0; j < m3.br_kolona; j++) {
            m3.elementi[i][j]= m1.elementi[i][j]*k;
        }
    }
    return m3;
}




template <typename TipElemenata, typename pokTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, int n,
                                     pokTip pok)
{
    if(n<0) throw domain_error("Neispravan stepen polinoma");
    if(A.br_redova != A.br_kolona) throw domain_error("Matrica mora biti kvadratna");


    auto rez(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    for(int i = 0; i < A.br_redova; i++) {
        for(int j = 0; j < A.br_kolona; j++) {
            rez.elementi[i][j]=0;
        }
    }

    auto I(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    for(int i = 0; i < A.br_redova; i++) {
        for(int j = 0; j < A.br_kolona; j++) {
            if(i==j) {
                I.elementi[i][j]=1;
            } else {
                I.elementi[i][j]=0;
            }
        }
    }

    auto X = I;
    
    for (int i = 0; i < n; i++) {
        auto pr = ProduktKoeficijentaIMatrice<TipElemenata>(X,*pok++);
        auto zb = ZbirMatrica<TipElemenata>(rez,pr);
        UnistiMatricu(rez);
        UnistiMatricu(pr);
        rez =zb;
        
        auto p = ProduktMatrica<TipElemenata>(X,A);
        UnistiMatricu(X);
        X = p;
    }
    UnistiMatricu(X);
    return rez;
}



int main()
{
   cout<<"Unesite dimenziju kvadratne matrice: ";
   int dimenzija;
   cin>>dimenzija;
   
   
   try{
        cout<<"Unesite elemente matrice A: "<<endl;
        Matrica<int>A  = StvoriMatricu<int>(dimenzija,dimenzija);
        UnesiMatricu('A',A);
        
        cout<<"Unesite red polinoma: ";
        int redPolinoma;
        cin>>redPolinoma;
        
        cout<<"Unesite koeficijente polinoma: ";
        vector<double>koeficijenti(redPolinoma+1);
        for (int i = 0; i < koeficijenti.size(); i++) {
            cin>>koeficijenti[i];            
        }
        
        
        Matrica<int>M = MatricniPolinom<int>(A,koeficijenti.size(), koeficijenti.begin());
        IspisiMatricu(M,10); //  IspisiMatricu(M,10,6,true);
        UnistiMatricu(M);
        UnistiMatricu(A);
   }
   catch(bad_alloc){
       cout<<"Nema memorije!";
   }
    return 0;
}