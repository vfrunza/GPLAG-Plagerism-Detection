/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
//#include "TestCurenja.h"

using namespace std;

template <typename TipElemenata>
 struct Matrica 
 {
    int br_redova, br_kolona; 
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
 };
 
 template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) 
 {
    for(int i = 0; i < mat.br_redova; i++) 
    {
        for(int j = 0; j < mat.br_kolona; j++)
        cout<<setw(sirina_ispisa)<<setprecision(preciznost)<<mat.elementi[i][j];
        cout<<endl;
    }
    if(treba_brisati)
        UnistiMatricu(mat);
 }
 
template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) 
 {
     //cout<<"Unistavam matricu: "<<endl; IspisiMatricu(mat, 10);
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) 
        delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
 }
 
template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) 
 {
    //cout<<"STVORI MATRICU"<<endl;
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++)
        mat.elementi[i]=nullptr;
    try 
    {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...) 
    {
        UnistiMatricu(mat);
        throw;
    }
 return mat;
 }
 
template <typename TipElemenata>
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) 
 {
    for(int i = 0; i < mat.br_redova; i++)
    for(int j = 0; j < mat.br_kolona; j++) 
    {
        cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
        cin >> mat.elementi[i][j];
    }
 }

 
 
 template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) 
 {
    //cout<<"ZBIR MATRICA"<<endl;
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw domain_error("Matrice nemaju jednake dimenzije!");
    auto pom(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            pom.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return pom;
    
 }

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> m1, const Matrica<TipElemenata> &m2)
{
    //cout<<"PRODUKT MATRICA"<<endl;
    if(m1.br_kolona != m2.br_redova)
        throw domain_error("Matrice nisu saglasne za mnozenje");
        
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
    {
        int suma=0;
        for(int j=0; j<m2.br_kolona; j++)
        {
            suma=0;
            for(int k=0; k<m2.br_redova; k++)
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}


template <typename TipElemenata>
Matrica<TipElemenata> StepenujMatricu(Matrica<TipElemenata> &m, int stepen)
{
    //cout<<"STEPENUJ"<<endl;
    auto mat(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    auto pom(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++)
        {
            mat.elementi[i][j]=m.elementi[i][j];
            pom.elementi[i][j]=m.elementi[i][j];
        }
    if(stepen==0)
        for(int i=0; i<m.br_redova; i++)
            for(int j=0; j<m.br_kolona; j++)
                {
                    if(i==j)
                        mat.elementi[i][j]=1;
                    else
                        mat.elementi[i][j]=0;
                }
    else
        for(int i=1; i<stepen; i++)
        {    
            Matrica<TipElemenata>pom2=ProduktMatrica(mat, pom);
            for(int i=0; i<m.br_redova; i++)
                for(int j=0; j<m.br_kolona; j++)
                    mat.elementi[i][j]=pom2.elementi[i][j];
            UnistiMatricu(pom2);
            
        }
    UnistiMatricu(pom);
    return mat;
}


template <typename TipElemenata1, typename TipElemenata2>
Matrica<TipElemenata1> PomnoziSkalarom(const Matrica<TipElemenata1> &m1, TipElemenata2 a)
{
    //cout<<"POMNOZI SA SKALAROM"<<endl;
    auto pom(StvoriMatricu<TipElemenata1>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            pom.elementi[i][j]=m1.elementi[i][j]*a;
    return pom;
}


template <typename TipElemenata, typename TipElemenata2>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, vector<TipElemenata2> koef)
{
    //cout<<"MATRICNI POLINOM"<<endl;
    if(mat.br_kolona!=mat.br_redova)
        throw domain_error("Matrica mora biti kvadratna");
        
    auto pom(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++)
            pom.elementi[i][j]=0;
    
    if(koef.size()==0)
        return pom;
        
    auto salji(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    
    for(int f=0; f<koef.size(); f++)
    {
        for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++)
                salji.elementi[i][j]=mat.elementi[i][j];
        Matrica<TipElemenata> pom1=StepenujMatricu(salji, f);
        Matrica<TipElemenata> pom2=PomnoziSkalarom(pom1, koef[f]);
        Matrica<TipElemenata> pom3=ZbirMatrica(pom, pom2);
        
        for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++)
                pom.elementi[i][j]=pom3.elementi[i][j];
        UnistiMatricu(pom3); UnistiMatricu(pom2); UnistiMatricu(pom1);
        /*cout<<endl<<"Prije stepenovanja: "<<endl;
        IspisiMatricu(mat, 7);
        cout<<endl<<"Nakon stepenovanja: "<<endl;
        IspisiMatricu(StepenujMatricu(mat, i),7);
        cout<<endl<<"Nakon mnozenja skalarom: "<<endl;
        IspisiMatricu(PomnoziSkalarom(StepenujMatricu(mat, i), koef[i]),7);
        cout<<endl<<"-------------------"<<endl;
        IspisiMatricu(pom, 7);
        cout<<endl;*/
    }
    UnistiMatricu(salji);
    return pom;
}


int main()
{
    //UKLJUCI_OBAVJESTAVANJE;
    
     int dim;
     cout<<"Unesite dimenziju kvadratne matrice: ";
     cin >>dim;
     Matrica<double> a;
     try {
         a = StvoriMatricu<double>(dim, dim);
         //b = StvoriMatricu<double>(m, n);
         cout << "Unesite elemente matrice A: "<<endl;
         UnesiMatricu('A', a);
         //cout << "Unesi matricu B:\n";
         //UnesiMatricu('B', b);
         //cout << "Produkt ove dvije matrice je:\n";
         //IspisiMatricu(c = ProduktMatrica(a, b), 7);
         //cout<<endl<<"Stepenovana prva na 3 iznosi: "<<endl;
         //IspisiMatricu(c=StepenujMatricu(a, 3), 7);
         cout<<"Unesite red polinoma: ";
         int red;
         cin>>red;
         cout<<"Unesite koeficijente polinoma: ";
         vector<double> koef; int br=0; 
         if(red!=0)
         {
            for(int i=0; i<=red; i++)
            {
                cin>>br;
                koef.push_back(br);
            }
         }
        Matrica<double>c=MatricniPolinom(a, koef);
         IspisiMatricu(c,10);
         UnistiMatricu(c);UnistiMatricu(a); 
     }
     catch(domain_error dom)
     {
         cout<<dom.what();
         UnistiMatricu(a);
     }
     catch(bad_alloc) 
     {
        cout << "Nema dovoljno memorije!\n";
     }
     
     return 0;
}