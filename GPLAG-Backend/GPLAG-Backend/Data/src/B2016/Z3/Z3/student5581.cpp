/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>

template <typename Tip>
struct Matrica {
    int redovi, kolone;
    Tip **elementi = nullptr;
};

template <typename Tip>
void UnistiMatricu(Matrica<Tip> matrica){
    if(!matrica.elementi){
        return;
    }
    for(int i=0 ; i<matrica.redovi ; i++){
        delete[] matrica.elementi[i];
    }
    delete[] matrica.elementi;
    matrica.elementi = nullptr;
}

template <typename Tip>
Matrica<Tip> StvoriMatricu(int redovi, int kolone){
    Matrica<Tip> matrica;
    matrica.redovi=redovi;
    matrica.kolone=kolone;
    matrica.elementi = new Tip* [redovi];
    for(int i=0 ; i<redovi ; i++){
        matrica.elementi[i] = nullptr;
    }
    try{
        for(int i=0 ; i<redovi ; i++){
            matrica.elementi[i] = new Tip[kolone];
        }
    }
    catch(...){
        UnistiMatricu(matrica);
        throw;
    }
    return matrica;
}

template <typename Tip>
void UnesiMatricu (char ime_matrice, Matrica<Tip> &matrica) {
    
    for(int i=0 ; i<matrica.redovi ; i++){
        for(int j=0 ; j<matrica.kolone ; j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>matrica.elementi[i][j];
            }
    }
}

template <typename Tip>
void IspisiMatricu (const Matrica<Tip> &matrica, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0 ; i<matrica.redovi ; i++){
        for(int j=0 ; j<matrica.kolone ; j++){
            std::cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<<matrica.elementi[i][j];
        }
    std::cout<<std::endl;
    }
    if(treba_brisati){
        UnistiMatricu(matrica);
    }
}

template <typename Tip>
Matrica<Tip> ZbirMatrica (const Matrica<Tip> &mat1,const Matrica<Tip> &mat2) {
    if(mat1.redovi != mat2.redovi || mat1.kolone != mat2.kolone){
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    }
    auto mat3(StvoriMatricu<Tip>(mat1.redovi, mat1.kolone));
    for(int i=0 ; i<mat1.redovi ; i++){
        for(int j=0 ; j<mat1.kolone ; j++){
            mat3.elementi[i][j] = mat1.elementi[i][j] + mat2.elementi[i][j];
        }
    }
    return mat3;
}

template <typename Tip>
Matrica<Tip> ProduktMatrica (const Matrica<Tip> mat1,const Matrica<Tip> mat2){
    
    if(mat1.kolone!=mat2.redovi){
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    Matrica<Tip> mat3=StvoriMatricu<Tip>(mat1.redovi, mat2.kolone);
    
    for(int i=0 ; i<mat3.redovi ; i++){
        for(int j=0 ; j<mat3.kolone ; j++){
            Tip suma(0);
            for(int k=0 ; k<mat2.redovi ; k++){
                suma+=mat1.elementi[i][k]*mat2.elementi[k][j];
            }
            mat3.elementi[i][j]=suma;
        }
    }
    
    return mat3;
}

template <typename Tip>
void NapraviJedinicnu(Matrica<Tip> &mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.redovi;i++){
        for(int j=0;j<mat.kolone;j++){
            if(i==j) mat.elementi[i][j]=1;
            else mat.elementi[i][j]=0;
        }
    }
}

template <typename Tip>
void NapraviNull(Matrica<Tip> &mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.redovi;i++){
        for(int j=0;j<mat.kolone;j++){
            mat.elementi[i][j]=0;
        }
    }
}
    
template <typename Tip>
void PomnoziSaKoeficijentom(Matrica<Tip> &matrica, double k){
    if(!matrica.elementi) return;
    for(int i=0;i<matrica.redovi;i++){
        for(int j=0;j<matrica.kolone;j++){
            matrica.elementi[i][j]*=k;
        }
    }
}

template <typename Tip>
Matrica<Tip> MatricniPolinom (Matrica<Tip> matrica, std::vector<double> koeficijenti){
    
    Matrica<Tip> polinom;
    
    if(matrica.redovi != matrica.kolone){
        throw std::domain_error("Matrica mora biti kvadratna");
    }
    
    if(koeficijenti.size()==0){
        auto mat=StvoriMatricu<Tip>(matrica.redovi, matrica.kolone);
        for(int i=0;i<matrica.redovi;i++){
            for(int j=0;j<matrica.kolone;j++){
                mat.elementi[i][j]=0;
            }
        }
        return mat;
    }
    
    Matrica<Tip> rezultat=StvoriMatricu<Tip>(matrica.redovi, matrica.kolone);
    NapraviNull(rezultat);
    
    for(int i=0;i<koeficijenti.size();i++){
        Matrica<Tip> sabirak=StvoriMatricu<Tip>(matrica.redovi,matrica.kolone);
        NapraviJedinicnu(sabirak);
        for(int j=0 ; j<i ; j++){
            Matrica<Tip> pomocna=ProduktMatrica(sabirak,matrica);
            UnistiMatricu(sabirak);
            sabirak=pomocna;
        }
        PomnoziSaKoeficijentom(sabirak,koeficijenti[i]);
        Matrica<Tip> pomocna2=ZbirMatrica(rezultat,sabirak);
        UnistiMatricu(rezultat);
        rezultat=pomocna2;
        UnistiMatricu(sabirak);
    }
    return rezultat;
}

int main (){
    
    Matrica<double> a,b;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int x;
    std::cin>>x;
    try{
        a=StvoriMatricu<double>(x,x);
        std::cout<<"Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::vector<double> v;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<=red;i++){
            double koef;
            std::cin>>koef;
            v.push_back(koef);
        }
    
    b=MatricniPolinom(a,v);
    
    IspisiMatricu(b,10,6,false);}
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
    
    UnistiMatricu(a);
    UnistiMatricu(b);
    
	return 0;
}