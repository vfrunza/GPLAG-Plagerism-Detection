#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>

struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>

void UnistiMatricu(Matrica<TipElemenata> mat){
   if(!mat.elementi) return;
    for(int i(0);i<mat.br_redova;i++) {delete[] mat.elementi[i]; /*mat.elementi[i]=nullptr;*/}
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>

Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    try{
        mat.elementi=new TipElemenata *[br_redova];
    for(int i(0);i<br_redova;i++) mat.elementi[i]=nullptr;
   
        for(int i(0);i<br_redova;i++)
        mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>

void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>

void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6, bool treba_brisati=false){
   if(treba_brisati==true){ 
       for(int i(0);i<mat.br_redova;i++){
           for(int j(0);j<mat.br_kolona;j++){
               std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
           }
           std::cout<<std::endl;
       }
       UnistiMatricu(mat); return; }
   
     for(int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++){
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    
}

template <typename TipElemenata>

Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipElemenata> m3;
    try{
    m3=StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);
    for(int i(0);i<m1.br_redova;i++){
        for(int j(0);j<m1.br_kolona;j++){
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }}
    catch(...){
        UnistiMatricu(m3);
        throw;
    }
    return m3;
}

template <typename TipElemenata>

Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> m1,Matrica<TipElemenata> m2){
  
    if(m2.br_redova!=m1.br_kolona) {UnistiMatricu(m1); UnistiMatricu(m2);throw std::domain_error("Matrice nisu saglasne za mnozenje");}
    Matrica<TipElemenata> mat;
    Matrica<TipElemenata> mat2;
    try{
    mat=StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
    mat2=StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
    for(int i(0);i<m1.br_redova;i++){
        for(int j(0);j<m2.br_kolona;j++){
            int suma(0);
            for(int k(0);k<m1.br_kolona;k++){
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            mat.elementi[i][j]=suma;
        }
    }}
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    for(int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++){
            mat2.elementi[i][j]=mat.elementi[i][j];
        }
    }
    UnistiMatricu(mat);
    return mat2;
}

template <typename TipElemenata>

Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> mat, std::vector<double> vektor){
    if(mat.br_redova != mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    int velicina=vektor.size();
    if(velicina==0){
        for(int i(0);i<mat.br_redova;i++){
            for(int j(0);i<mat.br_kolona;i++){
                mat.elementi[i][j]=0;
            }
        }
        return mat;
    }
    Matrica<TipElemenata> I;
    try{
    I=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
    for(int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++){
            if(i==j){
                I.elementi[i][j]=1;
            }
            else I.elementi[i][j]=0;
        }
    }}
    catch(...){
        UnistiMatricu(I);
        throw;
    }
    Matrica<TipElemenata> mat1;
    Matrica<TipElemenata> pomocna;
    Matrica<TipElemenata> pomocna2;
    Matrica<TipElemenata> pomocna_ponavljajuca;
    Matrica<TipElemenata> ponavljajuca;
    Matrica<TipElemenata> ukupna;
    Matrica<TipElemenata> zbir;
    Matrica<TipElemenata> produkt;
    Matrica<TipElemenata> zbir1;
    try{
        pomocna = StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
        try{
            pomocna2= StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
                try{
                    pomocna_ponavljajuca=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
                        try{
                            ukupna=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
                                try{
                                    ponavljajuca=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
                                        try{
                                            mat1=StvoriMatricu<TipElemenata>(mat.br_kolona,mat.br_kolona);
                                        }
                                        catch(...){
                                            UnistiMatricu(mat1);
                                            throw;
                                        }
                                }
                                catch(...){
                                    UnistiMatricu(ponavljajuca);
                                    throw;
                                    }
                            }
                            catch(...){
                                UnistiMatricu(ukupna);
                                throw;
                            }
                    }
                    catch(...){
                        UnistiMatricu(pomocna_ponavljajuca);
                        throw;
                    }
        }
        catch(...){
            UnistiMatricu(pomocna2);
            throw;
        }
    }
    catch(...){
        UnistiMatricu(pomocna);
        throw;
    }
    for(int i(0); i<mat.br_redova; i++){
        for(int j(0); j<mat.br_kolona;j++){
            pomocna.elementi[i][j]=mat.elementi[i][j];
            pomocna2.elementi[i][j]= mat.elementi[i][j];
            pomocna_ponavljajuca.elementi[i][j]=mat.elementi[i][j];
            ponavljajuca.elementi[i][j]=mat.elementi[i][j];
            mat1.elementi[i][j]=mat.elementi[i][j];
        }
    }

   
    for(int k(0);k<vektor.size();k++){
        if(k==0){
            for(int i(0);i<mat.br_redova;i++){
                for(int j(0);j<mat.br_kolona;j++){
                    pomocna.elementi[i][j]=vektor[k]*I.elementi[i][j];
                  
                }
            }
            
            for(int i(0);i<mat.br_redova;i++){
                for(int j(0);j<mat.br_kolona;j++){
                    mat.elementi[i][j]=pomocna.elementi[i][j];
                }
            }
        }
        
        else if(k==1){
            for(int i(0);i<mat.br_redova;i++){
                for(int j(0);j<mat.br_kolona;j++){
                    pomocna2.elementi[i][j]=vektor[k]*pomocna2.elementi[i][j];
                }
            }
            
            zbir=ZbirMatrica(mat,pomocna2);
            for(int i(0);i<mat.br_redova;i++){
                for(int j(0);j<mat.br_kolona;j++){
                    mat.elementi[i][j]=zbir.elementi[i][j];
                }
            }
            UnistiMatricu(zbir);
        }
        
        else if(k>1){
            try{
                produkt=ProduktMatrica(ponavljajuca,pomocna_ponavljajuca);
                for(int i(0);i<produkt.br_redova;i++){
                    for(int j(0);j<produkt.br_kolona;j++){
                        ponavljajuca.elementi[i][j]=produkt.elementi[i][j];
                    }
                }
                
               
                for(int i(0);i<mat.br_redova;i++){ 
                    for(int j(0);j<mat.br_kolona;j++){
                        ukupna.elementi[i][j]=ponavljajuca.elementi[i][j];
                        ukupna.elementi[i][j]=vektor[k]*ukupna.elementi[i][j];
                    }
                }

                zbir1=ZbirMatrica(mat,ukupna);
                for(int i(0);i<zbir1.br_redova;i++){
                    for(int j(0);j<zbir1.br_kolona;j++){
                        mat.elementi[i][j]=zbir1.elementi[i][j];
                    }
                }
               UnistiMatricu(zbir1);
               UnistiMatricu(produkt);
            }
            catch(...){
                UnistiMatricu(mat);
            }
        }
       
    }
    for(int i(0);i<mat1.br_redova;i++){
        for(int j(0);j<mat1.br_kolona;j++){
            mat1.elementi[i][j]=mat.elementi[i][j];
        }
    }
    UnistiMatricu(pomocna2);
    UnistiMatricu(pomocna);
    UnistiMatricu(ukupna);
    UnistiMatricu(ponavljajuca);
    UnistiMatricu(pomocna_ponavljajuca);
    UnistiMatricu(I);
    return mat1;
}


int main ()
{
  
    Matrica<double> a,c;
    int m;
    int red_polinoma;
    std::vector<double> vektor;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try{
        a=StvoriMatricu<double>(m,m);
        std::cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>red_polinoma;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i(0);i<=red_polinoma;i++){
            double broj;
            std::cin>>broj;
            vektor.push_back(broj);
        }
        IspisiMatricu(c=MatricniPolinom(a,vektor),10);
    }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
    }
    catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    UnistiMatricu(a);
    UnistiMatricu(c);

	return 0;
}