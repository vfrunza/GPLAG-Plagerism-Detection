/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using namespace std;

template <typename TipElemenata>
struct Matrica {
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata >
void UnistiMatricu(Matrica<TipElemenata>mat){
    if(!mat.elementi)return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata >
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata>mat;
    mat.br_redova=br_redova;mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++)mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<br_redova;i++)mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata>&mat){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            cin>>mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata>&mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++)
            cout<<setw(sirina_ispisa)<<setprecision(preciznost)<<mat.elementi[i][j];
        cout<<endl;
    }
    if(treba_brisati==true)UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata>ZbirMatrica(const Matrica<TipElemenata>&m1, const Matrica<TipElemenata>&m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)throw domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++)
        m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata>ProduktMatrica ( Matrica<TipElemenata>&m1, Matrica<TipElemenata>&m2){
    if(m1.br_kolona!=m2.br_redova)throw domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            double suma(0);
            for(int k=0;k<m2.br_redova;k++)suma=suma+(m1.elementi[i][k]*m2.elementi[k][j]);
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata>&mat,vector<double>koeficijenti){
    if(mat.br_redova!=mat.br_kolona)throw domain_error("Matrica mora biti kvadratna");
    if(koeficijenti.size()==0){
        auto m3(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_kolona;j++)m3.elementi[i][j]=0;
        }
        return m3;
    }
    Matrica<TipElemenata>jedinicna=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_kolona;j++){
                if(i==j)jedinicna.elementi[i][j]=koeficijenti[0];
                else jedinicna.elementi[i][j]=0;
            }
        }
    try {
        Matrica<TipElemenata>pomocna=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_kolona;j++){
                pomocna.elementi[i][j]=koeficijenti[1]*mat.elementi[i][j];
                if(pomocna.elementi[i][j]==-0)pomocna.elementi[i][j]=0;
                //cout<<"***"<<pomocna.elementi[i][j];
            }
        }
        Matrica<TipElemenata>obrisi=jedinicna;
        //IspisiMatricu(pomocna,10,6,true);
        //cout<<endl;
        jedinicna=ZbirMatrica(jedinicna,pomocna);
        UnistiMatricu(obrisi);
        Matrica<TipElemenata>pomocna2=mat;
        //IspisiMatricu(jedinicna,10,6,true);
        //cout<<endl;
        for(int k=2;k<koeficijenti.size();k++){
        Matrica<TipElemenata>obrisi_pomocnu=pomocna2;
        pomocna2=ProduktMatrica(pomocna2,pomocna2);
        UnistiMatricu(obrisi_pomocnu);
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_kolona;j++){
                pomocna.elementi[i][j]=koeficijenti[k]*pomocna2.elementi[i][j];
                
            }
        }
        obrisi=jedinicna;
        jedinicna=ZbirMatrica(jedinicna,pomocna);
        UnistiMatricu(obrisi);
        //UnistiMatricu(pomocna);
    }   
}
    catch(...){
        throw;
    }
    return jedinicna;
}

int main ()
{
    cout<<"Unesite dimenziju kvadratne matrice: ";
    Matrica<double>A;
    int n;cin>>n;
    try {
    A=StvoriMatricu<double>(n,n);
    cout<<"Unesite elemente matrice A: ";
    cout<<endl;
    UnesiMatricu('A',A);
    cout<<"Unesite red polinoma: ";
    int m;cin>>m;
    cout<<"Unesite koeficijente polinoma: ";
    vector<double>vk;
    for(int i=0;i<m+1;i++){
        int koef;
        cin>>koef;
        vk.push_back(koef);
    }
    Matrica<double>rez=MatricniPolinom(A,vk);
    IspisiMatricu(rez,10,6,true);
    UnistiMatricu(A);
}
    catch(domain_error e){
        cout<<e.what();
    }
    catch(...){
        
    }
    //UnistiMatricu(A);
	return 0;
}