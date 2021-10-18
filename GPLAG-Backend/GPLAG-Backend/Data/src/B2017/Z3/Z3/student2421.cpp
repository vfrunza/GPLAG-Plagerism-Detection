/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>
using namespace std;

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return; //ako je nullptr ne radimo nista
    for (int i=0; i<mat.br_redova; i++) delete [] mat.elementi[i]; //brisemo redove
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica <TipElemenata> StvoriMatricu (int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    try{
        mat.elementi=new TipElemenata*[br_redova]; //dinamicki alociramo matricu
    }
    catch(...){
        throw;
    }
    for (int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try{
        for (int i=0; i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for (int i=0; i<mat.br_redova; i++)
    for(int j=0; j<mat.br_kolona; j++){
        cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
        cin>>mat.elementi[i][j];
    }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for (int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            cout<<setprecision(preciznost)<<setw(sirina_ispisa)<<mat.elementi[i][j];
        }
        cout<<endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template<typename TipElemenata>
Matrica <TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++){
        for (int j=0; j<m1.br_kolona; j++) m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    }
    return m3;
}

template <typename TipElemenata>
Matrica <TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw domain_error ("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for (int i=0; i<m1.br_redova; i++){
        for (int j=0; j<m2.br_kolona; j++){
            m3.elementi[i][j]=0;
            for (int k=0; k<m1.br_kolona; k++){
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata>MatricniPolinom (const Matrica<TipElemenata> &m, const vector<double> &v){
    if(m.br_redova!=m.br_kolona) throw domain_error ("Matrica mora biti kvadratna");
    if(v.size()==0){
        auto mat=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
        for (int i=0; i<m.br_redova; i++){
            for (int j=0; j<m.br_kolona; j++){
                mat.elementi[i][j]=0;
            }
        }
        return mat; //ako je prazan vektor vracamo nul-matricu
    }
    auto m_r(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona)); //prvi sabirak: prvi koef puta jedinicna matrica
    for(int i=0; i<m.br_redova; i++){
        for (int j=0; j<m.br_kolona; j++){
            if(i==j)m_r.elementi[i][j]=1*v[0];
            else m_r.elementi[i][j]=0;
        }
    }
    for (int i=1; i<v.size(); i++){
        auto mat=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
        for (int i=0; i<m.br_redova; i++){
            for (int j=0; j<m.br_kolona; j++){
                mat.elementi[i][j]=m.elementi[i][j];
            }
        }
        for (int j=1; j<i; j++){ //formirajmo trazenu matricu koju mnozimo sa odg. koeficijentom
            auto produkt=ProduktMatrica(mat, m);
            for (int i=0; i<m.br_redova; i++){
                for (int j=0; j<m.br_kolona; j++){
                    mat.elementi[i][j]=produkt.elementi[i][j];
                }
            }
            UnistiMatricu(produkt);
        }
        for (int k=0; k<m_r.br_redova; k++){
            for (int l=0; l<m_r.br_kolona; l++){
                m_r.elementi[k][l]+=v[i]*mat.elementi[k][l];
            }
        }
        UnistiMatricu(mat);
    }
    return m_r;
}


int main ()
{
    Matrica<double> a;
    int m;
    cout<<"Unesite dimenziju kvadratne matrice: ";
    cin>>m;
    a=StvoriMatricu<double>(m, m);
    cout<<"Unesite elemente matrice A: "<<endl;
    UnesiMatricu('A', a);
    cout<<"Unesite red polinoma: ";
    int red;
    cin>>red;
    cout<<"Unesite koeficijente polinoma: ";
    vector<double> vk;
    for (int i=0; i<=red; i++){
        double koef;
        cin>>koef;
        vk.push_back(koef);
    }
    auto b=MatricniPolinom(a, vk);
    IspisiMatricu(b, 10);
    UnistiMatricu(a);
    UnistiMatricu(b);
	return 0;
}
