/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template<typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi = nullptr;
};
template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata>mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_kolona];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0; i<br_redova; i++) mat.elementi[i] = new TipElemenata[br_kolona];
    }catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
//produkt matrica
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje!");
        Matrica<TipElemenata> produkt;
        produkt=StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);     //provjeriti                     //uradjeno
        for(int i=0; i<produkt.br_redova;i++){
            for(int j=0; j<produkt.br_kolona; j++){
                produkt.elementi[i][j]=0;
                for(int k=0; k<m2.br_kolona; k++){
                    produkt.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
                }
            }
        }
    return produkt;
}
//pretvori
template<typename TipElemenata>
Matrica<TipElemenata> PrebaciUDruguMatricu(const Matrica<TipElemenata>&mat){
    Matrica<TipElemenata>nova;
    nova=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            nova.elementi[i][j]=mat.elementi[i][j];
        }
    }
    return nova;
}
//napuni nulama
template<typename TipElemenata>
Matrica<TipElemenata> NapuniNulama(const Matrica<TipElemenata> &m){
    Matrica<TipElemenata>povratna;
    povratna=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);                          //uradnjeno
    for(int i=0; i<povratna.br_redova; i++){
                for(int j=0; j<povratna.br_kolona; j++){
                   povratna.elementi[i][j]=0; 
                }
            }
            return povratna;
}
//jedinicna
template<typename TipElemenata>
Matrica<TipElemenata> JedinicnaMatrica(int br_redova, int br_kolona){
    Matrica<TipElemenata>jedinicna;
    jedinicna=StvoriMatricu<TipElemenata>(br_redova, br_kolona);                                //uradjeno
    
    for(int i=0; i<jedinicna.br_redova; i++){
            for(int j=0; j<jedinicna.br_kolona; j++){
                if(i==j) jedinicna.elementi[i][j]=1;
                else jedinicna.elementi[i][j]=0;
            }
    }
        return jedinicna;
}
template<typename TipElemenata>
Matrica<TipElemenata> MnoziSaSkalarom(const Matrica<TipElemenata> &mat,int v){
    Matrica<TipElemenata>mnozi;
    mnozi=StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
    for(int i=0; i<mat.br_redova; i++){  
            for(int j=0; j<mat.br_kolona; j++){
                mnozi.elementi[i][j]=v*mat.elementi[i][j];    
            }
        }
        return mnozi;
}

//matricni polinom
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat,const std::vector<double> &v){
if(mat.br_kolona!=mat.br_redova) throw std::domain_error("Matrica mora biti kvadratna!");
        Matrica<TipElemenata>povratna;
        Matrica<TipElemenata>jedinicna;
        Matrica<TipElemenata>nula_matrica;
        Matrica<TipElemenata>pomocna;
        Matrica<TipElemenata>suma;
        Matrica<TipElemenata>pomocna1;
        
        jedinicna=JedinicnaMatrica<TipElemenata>(mat.br_redova, mat.br_kolona);
        pomocna=StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
        pomocna1=PrebaciUDruguMatricu(mat);
        
        if(v.size()==0) return NapuniNulama(povratna);
        
        for(int i=0; i<v.size(); i++){
            if(i==0){
                nula_matrica=MnoziSaSkalarom(jedinicna,v[i]);
                suma=PrebaciUDruguMatricu(nula_matrica);
            }
            else if(i==1){
                UnistiMatricu(pomocna);
                pomocna=MnoziSaSkalarom(mat,v[i]);
                UnistiMatricu(suma);
                suma =ZbirMatrica(nula_matrica,pomocna);
                
            }else{
                auto g=pomocna1;
            pomocna1 =ProduktMatrica(pomocna1,mat);
            UnistiMatricu(g);
            auto s1=MnoziSaSkalarom(pomocna1,v[i]), s2=suma;
            suma =ZbirMatrica(s1,suma);
            UnistiMatricu(s1);
            UnistiMatricu(s2);
            }
        }
            UnistiMatricu(jedinicna);
            UnistiMatricu(pomocna1);
            UnistiMatricu(nula_matrica);
            UnistiMatricu(pomocna);        
        
        return suma;
}//curenje na sve strane
template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata>mat){
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat){
    for(int i=0; i<mat.br_redova; i++){
    for(int j=0; j<mat.br_kolona; j++){
        std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
        std::cin>>mat.elementi[i][j];
        }
    }
}
template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template<typename TipElemenata>
Matrica<TipElemenata>ZbirMatrica(const Matrica<TipElemenata>&m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
            return m3;
}
int main (){
    Matrica<double>A;
    int dimenzija,red_polinoma;
    std::vector<double>v;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dimenzija;
    try{
        A=StvoriMatricu<double>(dimenzija,dimenzija);
        std::cout<<"Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A',A);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>red_polinoma;
        std::cout<<"Unesite koeficijente polinoma: ";
        int k(red_polinoma),broj;
        if(red_polinoma==0) v.resize(0);
        else{
     while(k+1>0){
            std::cin>>broj;
            v.push_back(broj);
            k--;
        }
        }
        IspisiMatricu(MatricniPolinom(A,v),10,6,true);
    }catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(A);
	return 0;
}