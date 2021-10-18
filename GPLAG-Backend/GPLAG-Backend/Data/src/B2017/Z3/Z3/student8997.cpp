/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <new>
#include <stdexcept>
#include <iomanip>
#include <vector>

template <typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) {
     
 if(!mat.elementi) return;
 
 for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
 delete[] mat.elementi;
 
 mat.elementi = nullptr;
 }
    
    
    
template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu (int br_redova,int br_kolona)
{
    
    Matrica<TipElemenata> mat;
    mat.br_kolona=br_kolona;
    mat.br_redova=br_redova;
    
    mat.elementi = new TipElemenata*[br_redova];
    
    for(int i=0;i<br_redova;i++){
        mat.elementi[i]=nullptr;
        
    }
    try {
        
        for(int i=0;i<br_redova;i++)
        {
            mat.elementi[i] = new TipElemenata[br_kolona];
        }
        
    }
     catch(...) {
     UnistiMatricu(mat);
         throw;
 }
 return mat;
 }
 
 
 template<typename TipElemenata>
 void UnesiMatricu (Matrica<TipElemenata> &m, char ime_matrice)
 {
     
     for(int i=0;i<m.br_redova;i++){
         for(int j=0;j<m.br_kolona;j++){
             std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
                std::cin >> m.elementi[i][j];

         }
     }
}
template <typename TipElemenata>
 void IspisiMatricu(Matrica<TipElemenata> mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
 {
    for(int i = 0; i < mat.br_redova; i++) {
                for(int j = 0; j < mat.br_kolona; j++){
                    std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];

                }
                std::cout << std::endl;
    }
            
    if(treba_brisati==true)  UnistiMatricu(mat);
                
     
 }

 

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
    {
        if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije!");

        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
        
        
        
        for(int i=0;i<m1.br_redova;i++) {
            for(int j=0;j<m1.br_kolona;j++){
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j]; 
            }
        }
        
        
        return m3;
    }
    
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{
    
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m2.br_kolona;j++) m3.elementi[i][j]=0;
    
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            for(int k=0;k<m1.br_kolona;k++){
                
                m3.elementi[i][j]+= m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
    return m3;
}




template<typename TipElemenata>
Matrica<TipElemenata>  PostaviJedinicnuMatricu(const Matrica<TipElemenata> &m)
{
    auto m3(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_kolona;j++){
            if(i==j){
                m3.elementi[i][j]=1;
            }
            else m3.elementi[i][j]=0;
        }
    }
    return m3;
    
}




template<typename TipElemenata>
Matrica<TipElemenata>  KopirajMatricu(const Matrica<TipElemenata> &m)
{
    auto m3(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_kolona;j++){
            m3.elementi[i][j]=m.elementi[i][j];
        }
    }
    return m3;
    
}

template<typename TipElemenata,typename Tip>
Matrica<TipElemenata>  MnozenjeBrojaSaMatricom (const Matrica<TipElemenata> &m, Tip b)
{
    auto m3(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_kolona;j++){
            
            m3.elementi[i][j]= m.elementi[i][j] * b;
            
            
        }
    }
    return m3;
    
}



template<typename TipElemenata,typename Tip>
Matrica<TipElemenata> MatricniPolinom ( Matrica<TipElemenata> mat, int k , Tip it)
{


    if(k<0) throw std::domain_error ("Neispravan stepen polinoma");
   
        
        auto matrez = PostaviJedinicnuMatricu(mat);
        auto matrez2 = MnozenjeBrojaSaMatricom(matrez, *it);
        UnistiMatricu(matrez);

        matrez = matrez2;
        
        auto matnan = KopirajMatricu(mat);

        
        it++;
        int ii = 1;

        auto matrez3 = mat;
        auto matnan2 = mat;
        
        for(; ii<=k; it++, ii++){
            

                           
           matrez3 = MnozenjeBrojaSaMatricom(matnan,*it);
           matrez2 = ZbirMatrica(matrez,matrez3);
           UnistiMatricu(matrez3);
           UnistiMatricu(matrez);
           matrez = matrez2;
           
           matnan2 = ProduktMatrica(matnan,mat);
           UnistiMatricu(matnan);
           matnan = matnan2;
        
        }
        
    UnistiMatricu(matnan);
    
    //matrez2 = nullptr;
    //matrez3 = nullptr;
    //matnan  = nullptr;
    //matnan2 = nullptr;

    return matrez;
    
    
}

    


int main ()
{
    
    Matrica<double> a,f;
    int preciznost;
    bool brisati=false;
    int r;
    std::vector<int> v;
    int n;
    int unos;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>r;
   
    try {
        
        a=StvoriMatricu<double>(r,r);
        
        
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu(a,'A');
    
        
        

        std::cout<<"Unesite red polinoma: ";
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<=n;i++){
            
            std::cin>>unos;
            v.push_back(unos);
        }
         IspisiMatricu(MatricniPolinom(a,n,v.begin()), 10 , 6 , true);
        
        
        
    }
     catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 catch(std::domain_error izuzetak){
     std::cout<<izuzetak.what()<<std::endl;
 }
 
  
 UnistiMatricu(a);
    
	return 0;
}
