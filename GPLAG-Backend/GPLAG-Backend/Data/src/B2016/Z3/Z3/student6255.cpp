/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <cmath>
#include<vector>
using namespace std;

template<typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr; 
};
    
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
    
template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata>mat;
    mat.br_redova=br_redova; 
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova;i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova;i++) 
        mat.elementi[i]=new TipElemenata[br_kolona];
        }
    catch(...) {
        UnistiMatricu(mat);
        throw;
        }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0; i<mat.br_redova; i++)
    for(int j=0; j<mat.br_kolona; j++) {
        cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
        cin>>mat.elementi[i][j];
    }
}

//vraca broj redova zadane matrice
template<typename TipElemenata>
int BrojRedova(Matrica<TipElemenata>m){
    return m.size();
}
//vraca broj kolona zadane matrice
template<typename TipElemenata>
int BrojKolona(Matrica<TipElemenata>m){
    return m[0].size();
}

//prosiriti ovu funkciju //DORADITI
template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    //PRECIZION, broj koji odredjuje preciznost ispisa (broj tacnih cifara pri ispisu), njega treba proslijediti funkciji cout.precision ili setprecizion
    //TREBA_BRISATI, ukoliko ova funkcija ima vrijednost true treba da po obavljenom ispisu oslobodi prostor zauzet matricom koja joj je proslijedjena kao parametar
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
        cout<<setw(sirina_ispisa)<<mat.elementi[i][j];
        cout<<endl;
    }
}
template <typename TipElemenata>Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
    throw domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
    for(int j=0; j<m1.br_kolona; j++)
    m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}
//funkcija koja racuna proizvod dvije matrice, dinamicki alocirati!!!
template<typename TipElemenata>
Matrica<TipElemenata>ProduktMatrica(Matrica<TipElemenata>a,Matrica<TipElemenata>b){
    if(BrojRedova(a)!=BrojKolona(b)) throw domain_error("Matrice nisu saglasne za mnozenje"); //UHVATITI OVAJ IZUZETAK!!! 
    Matrica<TipElemenata>c;
    for(int i=0;i<a.br_redova;i++){
        for(int j=0;j<b.br_kolona;j++){
            int suma=0;
            for(int k=0;k<a.br_redova;k++){
                suma=suma+a[i][k]*b[k][j];
            }
            c[i][j]=suma;
        }
    }
    return c;
}

//funkcija koja racuna matricni polinom 
template<typename TipElemenata>
Matrica<TipElemenata>MatricniPolinom(Matrica<TipElemenata>A,vector<int>Pk){
Matrica<TipElemenata>mat;
Matrica<TipElemenata>matrica2;
StvoriMatricu(mat);

if(Pk.size()==0) { //ako je Pk prazan vektor funkcija treba kao rez da vrati nul matricu istog formata kao matrica A
	for(int i=0;i<A.br_redova;i++){
		for(int j=0;j<A.br_kolona;j++){
			mat[i][j]=0;
		}
	}
}
else{
for(int i=0;i<mat.br_redova;i++){
    for(int j=0;j<mat.br_kolona;j++){
        mat[i][j]=Pk[0]*mat[i][j];
    }
}
for(int i=1;i<Pk.size();i++){
    for(int k=0;k<A.br_kolona;k++){
        for(int k1=0;k1<A[i].size();k++){
            matrica2[k][k1]=A[k][k1];  
        }
    } 
    for(int j=1;j<i;j++){
     matrica2=ProduktMatrica(matrica2,A);
}
}
for(int i=0;i<matrica2.br_redova;i++){
    for(int j=0;j<matrica2.br_kolona;j++){
        matrica2[i][j]=matrica2[i][j]*Pk[i];
        mat=ZbirMatrica(mat,matrica2);
    }
}
}

if(BrojRedova(mat)!=BrojKolona(mat))domain_error("Matrica nije kvadratna");  //UHVATITI OVAJ IZUZETAK!!
    return mat;
}
    
//DORATITI main, uhvatiti sve izuzetke, paziti da ne dodje do curenja memorije (delete)!!
int main() {
    Matrica<double>a,c; 
    int n;
    cout<<"Unesite dimenziju kvadratne matrice: ";
    cin>>n;
    try {
        a=StvoriMatricu<double>(n,n);
        cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        int red_polinoma;
        cout<<"Unesite red polinoma: ";
        cin>>red_polinoma;
        vector<double>koeficijenti_polinoma(red_polinoma);
        cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<koeficijenti_polinoma.size();i++) cin>>koeficijenti_polinoma[i];
        //IspisiMatricu(MatricniPolinom(a,koeficijenti_polinoma));
    }
    catch(bad_alloc) {
        cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);  UnistiMatricu(c);
    return 0;
}