#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
 
 
 // PITATI  ! DA LI JE BILO DOZVOLJENO KOPIRANJE ZADATKA S PREDAVANJA 8B ?!?!?
template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
  if (!mat.elementi) return;
   for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
  
   delete[] mat.elementi; 
   mat.elementi=nullptr;  
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    try{
        mat.elementi = new TipElemenata*[br_redova]; // curenje memorije 
    } catch(...){throw;}
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
void IspisiMatricu( Matrica<TipElemenata> mat, int sirina_ispisa,int preciznost=6, bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
        {    
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) <<  mat.elementi[i][j];  // pristup neinicijaliziranoj vrijednosti ?
        }  
        std::cout << std::endl;
    }
    
    if (treba_brisati)
    {
        UnistiMatricu(mat);
    }
}

template <typename TipElemenata>
void Prebaci (Matrica<TipElemenata> a,Matrica<TipElemenata> b)
{
    for (int i=0;i<a.br_redova;i++)
    {
         for (int j=0;j<a.br_kolona;j++)
         {
            a.elementi[i][j]=b.elementi[i][j];
             
         }
    }
    
}
//Stvara novu
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");

    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));


    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

//Stvara novu
template <typename TipElemenata>
Matrica <TipElemenata> ProduktMatrica ( Matrica<TipElemenata> m1, Matrica<TipElemenata> m2)
{
    if (m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> m3(StvoriMatricu<TipElemenata>((int)m1.br_redova,(int)m2.br_kolona));
    int i(0),j(0),k(0),l(0);
   
    while (l<m1.br_redova)
    {
        while (k<m2.br_kolona)
        {
            int suma(0);
            while (i<m1.br_kolona && j<m2.br_redova)
            {
                suma+=m1.elementi[l][i] *m2.elementi[j][k];
                i++;
                j++;
            }
            m3.elementi[l][k]=suma;
            i=0;
            j=0;
            k++;
            
        }
        k=0;
        l++;
    }
    return m3;
}

//Stvara novu
template <typename TipElemenata>
Matrica <TipElemenata> MnozenjeMatriceSkalarom (const Matrica<TipElemenata> &A,double skalar)
{
    Matrica<TipElemenata> matrica (StvoriMatricu<TipElemenata>(A.br_kolona,A.br_kolona));
    for (int i=0; i<A.br_redova; i++)
        for (int j=0; j<A.br_kolona; j++)
            matrica.elementi[i][j]=skalar*A.elementi[i][j];

    return matrica;
}

//Stvara novu
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &A, std::vector<double> koeficijenti)
{

    if (A.br_kolona!=A.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    if (koeficijenti.size()==0) {
        for (int i=0; i<A.br_redova; i++)
            for (int j=0; j<A.br_kolona; j++)
                A.elementi[i][j]=0;

        return A;
    }

    auto jedinicna_matrica (StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    for (int i=0; i<A.br_redova; i++)
        for (int j=0; j<A.br_kolona; j++)
            if (i==j) 
                jedinicna_matrica.elementi[i][j]=1;
            else 
                jedinicna_matrica.elementi[i][j]=0;
 
    
 

    int n(koeficijenti.size());
    auto suma (StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    auto Pomocna (StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    for (int i=0; i<A.br_redova; i++)
        for (int j=0; j<A.br_kolona; j++)
            suma.elementi[i][j]=0;

    for (int k=0; k<n; k++) 
    {
        if (k==0) 
        {
            auto pomMnozenje = MnozenjeMatriceSkalarom<TipElemenata>(jedinicna_matrica,koeficijenti[k]);
            auto pomZbir = ZbirMatrica<TipElemenata>(pomMnozenje,suma);
            //Zato sto ove funkcije prave nove matrice mora se brisati odmah
            UnistiMatricu(pomMnozenje);
            UnistiMatricu(suma);
            suma = pomZbir;
            //AT2 (c9) - funkcija produkt matricama);
        }
        else
        {
            if (k==1)
            {
                auto pomMnozenje = MnozenjeMatriceSkalarom<TipElemenata>(A,koeficijenti[k]);
                auto pomZbir = ZbirMatrica<TipElemenata>(pomMnozenje,suma);
                UnistiMatricu(pomMnozenje);
                UnistiMatricu(suma);
                suma = pomZbir;
                Prebaci(Pomocna,A);
            }
           else  
           {
                auto pomProdukt = ProduktMatrica<TipElemenata>(A,Pomocna);
                Prebaci<TipElemenata>(A,pomProdukt);
                UnistiMatricu((pomProdukt));
                auto pomMnozenje = MnozenjeMatriceSkalarom<TipElemenata>(A,koeficijenti[k]);
                auto pomZbir = ZbirMatrica<TipElemenata>(pomMnozenje,suma);
                UnistiMatricu(pomMnozenje);
                UnistiMatricu(suma);
                suma = pomZbir;
           }
        }
    }
    
    UnistiMatricu(jedinicna_matrica);
    UnistiMatricu(Pomocna);
    return suma;

}

int main()
{
    Matrica<double> a, b, c; // AUTOMATSKA INICIJALIZACIJA!!!
    int m, n;
    int red_polinoma;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m ;
    n=m;
    try {
        a = StvoriMatricu<double>(m, n);
        
        std::cout << "Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A', a);
        
        std::cout << "Unesite red polinoma: ";
        std::cin >> red_polinoma;
        
        std::cout << "Unesite koeficijente polinoma: ";
        
        std::vector<double> koeficijenti;
        double koeficijent;
        
        for (int i=0;i<m*m;i++)
        {
            std::cin >> koeficijent;
            koeficijenti.push_back(koeficijent);
        }
        
        
        auto pomPolinom = MatricniPolinom<double>(a,koeficijenti);
        UnistiMatricu(a);
        a = pomPolinom;
        IspisiMatricu(a,10);
       
       
       
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
   
    return 0;
}