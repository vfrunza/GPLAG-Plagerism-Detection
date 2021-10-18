/B2017/2018: Zadaća 3, Zadatak 3
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
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) 
        delete[] mat.elementi[i];
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
    for(int i = 0; i < br_redova; i++) 
        mat.elementi[i] = nullptr;
    try {
        
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
         for(int i = 0; i < br_redova; i++)
         {
             for(int j = 0; j < br_kolona; j++)
             mat.elementi[i][j]=0;
         
         }
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
            std::cout << std::setprecision(preciznost)<<std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati)
        UnistiMatricu(mat);
}



template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> m1, Matrica<TipElemenata>m2)
{
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    Matrica<TipElemenata> matrica;
    
    //try{ - ako dodje do bacanja izuzetka pri stvaranju matrice sama funckija bi se za to trebala pobrinuti
        matrica = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    //}
    //catch(...)
    //{
      //  UnistiMatricu(matrica);
    //    throw;
    //}
    for(int i=0; i<matrica.br_redova; i++)
    {
        for(int j=0; j<matrica.br_kolona;j++)
        {
            double tmp =0;
            for(int k=0;k<m1.br_kolona;k++)
                tmp += m1.elementi[i][k] * m2.elementi[k][j];
            matrica.elementi[i][j] = tmp;
        }
    }
         return matrica;
}


template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipElemenata>m3;
    //try{
        m3=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
    //}
    //catch(...)
    //{
      //  UnistiMatricu(m3);
        //throw;
    //}
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> MnozenjeSaKoef(Matrica<TipElemenata> a, int koef)
{
     Matrica<TipElemenata>pomnozena;
    //try {
        pomnozena=StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);
    //}
    //catch(...)
    //{
       // UnistiMatricu(pomnozena);
        //throw;
    //}
    for(int i=0; i<a.br_redova; i++)
    {
        for(int j=0; j<a.br_kolona; j++)
        {
            pomnozena.elementi[i][j]=koef*a.elementi[i][j];
        }
    }
    return pomnozena;
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> a, std::vector<double> koef)
{
    if(a.br_kolona!=a.br_redova)
        throw std:: domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> matrica;  
    //try {
         matrica=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
    //}
    //catch(...)
    //{
      //  UnistiMatricu(matrica);
        //throw;
    //}
   Matrica<TipElemenata> pomocna;
   //try
   //{
       pomocna=StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);
   //}
   //catch(std::bad_alloc)
   //{
     //  UnistiMatricu(pomocna);
       //throw;
   //}
  
    for(int i=0;i<a.br_redova;i++)
    {
        for(int j=0;j<a.br_kolona;j++)
        {
                matrica.elementi[i][j] = 0;
        }
    }
    
    if(koef.size()==0)  return matrica;
    
    for(int i=0;i<a.br_redova;i++)
        matrica.elementi[i][i] = koef[0];
    for(int i=0; i<a.br_redova; i++)
    {
        for( int j=0; j<a.br_kolona; j++)
        {
            pomocna.elementi[i][j]=a.elementi[i][j];
        }
    }
         
    Matrica<TipElemenata>najnovija;
    /*try
    {
        najnovija=StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);
    }
    catch(...)
    {
        UnistiMatricu(najnovija);
        throw;
    }*/
    
    for(int i=1;i<koef.size();i++)
    {
        if(i==1) 
        {
            najnovija=MnozenjeSaKoef(pomocna,koef[1]);
            auto b(ZbirMatrica(matrica, najnovija));
            UnistiMatricu<TipElemenata>(matrica);
            matrica=b;
        }
        if(i>1)
        {
            auto b(ProduktMatrica(a,pomocna));
            auto c(MnozenjeSaKoef(b,koef[i]));
            auto d(ZbirMatrica(matrica, c));
            UnistiMatricu<TipElemenata>(matrica);
            matrica=d;
            UnistiMatricu<TipElemenata>(a);
            a=b;
            UnistiMatricu<TipElemenata>(c);
        }
    }
    UnistiMatricu<TipElemenata>(a);
    UnistiMatricu<TipElemenata>(najnovija);
    UnistiMatricu<TipElemenata>(pomocna);
    return matrica;
}


int main()
{
     Matrica<double>matrica, a;
   
        std::cout<<"Unesite dimenziju kvadratne matrice: ";
        int n;
        std::cin>> n;
     try{
        a = StvoriMatricu<double>(n,n);
        std::cout<<"Unesite elemente matrice A:"<<std::endl;
        UnesiMatricu<double>('A', a);
        std::cout<<"Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> k(red+1,0);
        for(int i=0;i<k.size();i++)
            std::cin>>k[i];
       
    //try{
        matrica=MatricniPolinom<double>(a,k);
        IspisiMatricu<double>(matrica, 10,6,true);
        UnistiMatricu(a);
        UnistiMatricu(matrica);
    
      }
    catch(std:: domain_error izuzetak)
    {
        //UnistiMatricu<double>(a);
        std:: cout<<izuzetak.what();
    }
        
    //}
   
    catch(...)
    {
        //UnistiMatricu<double>(a);
       std:: cout<<"Problemi s memorijom!";
    }
    return 0;
}
