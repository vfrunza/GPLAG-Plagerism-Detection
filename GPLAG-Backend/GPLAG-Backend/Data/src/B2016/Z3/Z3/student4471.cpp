/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <stdexcept>

template <typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi = nullptr;
};
    
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata>mat){
    if(!mat.elementi)return;
    for(int i=0;i<mat.br_redova;i++)delete []mat.elementi[i];
    delete []  mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata>mat;
    mat.br_redova = br_redova;mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++)mat.elementi[i] = nullptr;
    
    try{
        for(int i=0;i<br_redova;i++){
            mat.elementi[i] = new TipElemenata[br_kolona];
        }
    }catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }    
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost = 6,bool treba_brisati = false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout<<std::endl;
    } 
    
    if(treba_brisati)UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)throw std::domain_error("Matrice nemaju jednake dimenzije!");
    try{
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));                                                 //da li hvatati izueztak
     
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            m3.elementi[i][j] = m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
    }catch(...){
        throw;
       // return ;
    }
   
}

template <typename TipElemenata>
Matrica<TipElemenata> MojZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)throw std::domain_error("Matrice nemaju jednake dimenzije!");
    
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            m1.elementi[i][j] = m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m1;
   
   
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_kolona != m2.br_redova)throw std::domain_error("Matrice nisu saglasne za mnozenje");
    try{
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));                                          //da li hvatat izuzetak
     TipElemenata sum;
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            sum = TipElemenata();
            for(int k=0;k<m1.br_kolona;k++)sum+=(m1.elementi[i][k]*m2.elementi[k][j]);
            m3.elementi[i][j] = sum;
        }
    }
    return m3;
    }catch(...){
        throw;
       // return;
    }
   
}

template <typename TipElemenata>
Matrica<TipElemenata>PomnoziSa(const Matrica<TipElemenata> &m1,double x){
  //  Matrica<TipElemenata> m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
       for(int i=0;i<m1.br_redova;i++){
           for(int j=0;j<m1.br_kolona;j++)m1.elementi[i][j] *=x;
       
       
    }
    return m1;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1,const std::vector<double> &v){     
 
    
    if(m1.br_redova != m1.br_kolona)throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata>m3;
        try{
        m3 = StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);                       //OBRISATI 
       for(int i=0;i<m1.br_redova;i++){
           for(int j=0;j<m1.br_kolona;j++)m3.elementi[i][j] = 0;
       }
       
        }catch(...){
            throw;
            
        }
        
    
    if(v.size()==0)return m3;
    UnistiMatricu(m3);
    
    
    //ako se nije nista dessilo vracamo matricni polinom
    Matrica<TipElemenata>trenutna;
    try{
        trenutna = StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);              //obrisati
        for(int i=0;i<m1.br_redova;i++){
            for(int j=0;j<m1.br_kolona;j++){
                if(i==j){
                    trenutna.elementi[i][j] = 1;
               }else trenutna.elementi[i][j] = 0;
            }
        }
       
        
    }catch(...){
        
        throw;
    }
    
   
    int vel = v.size()-1;
    std::vector<Matrica<TipElemenata>*> m_pok(vel);
    for(int  i=0;i<vel;i++){
        m_pok[i] = nullptr;
    }
    
    //sada u m_pok trebam ubacit matrice p1A p2A ..... p3A
    //radit cemo nesto kao trenutna+=nova;
    
    for(int i=0;i<vel;i++){
        
        try{
            if(i==0){
                m_pok[0] = new Matrica<TipElemenata>;
               
                *m_pok[0] =ProduktMatrica(m1,trenutna);
                trenutna = PomnoziSa(trenutna,v[0]); 
            }else{
                m_pok[i] = new Matrica<TipElemenata>;
                
                *m_pok[i] = ProduktMatrica(m1,*m_pok[i-1]);
            }    
        }catch(...){
            for(int i=0;i<vel;i++)UnistiMatricu(*m_pok[i]);
            for(int i=0;i<vel;i++)delete  m_pok[i];
           
            UnistiMatricu(trenutna);
            throw;
        }
        
    }

    //sada ih izmnozimo i saberemo 
    for(int i=0;i<vel;i++){
        *m_pok[i] = PomnoziSa(*m_pok[i],v[i+1]);
       trenutna = MojZbirMatrica(trenutna,*m_pok[i]);
    }
    
   for(int i=0;i<vel;i++)UnistiMatricu(*m_pok[i]);
   for(int i=0;i<vel;i++)delete  m_pok[i];
   
   return trenutna;
    
    
    
}



int main ()
{
    
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int vel;
    std::cin>>vel;
    
    try{
        Matrica<double> A = StvoriMatricu<double>(vel,vel);
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A',A);
        std::cout<<"Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> k(red+1);
        for(int i=0;i<k.size();i++)std::cin>>k[i];
        
        try{
             Matrica<double> rez = MatricniPolinom<double>(A,k);  
             
             
            IspisiMatricu(rez,10);//ovdje je brisemo
            UnistiMatricu(rez);
            UnistiMatricu(A);
        }catch(...){
            UnistiMatricu(A);
            throw;
        }
        
    }catch(...){
        
        return 0;
    }
    
	return 0;
}
