/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>
using namespace std;
template<typename TipElemenata> struct Matrica {
int br_redova, br_kolona;
TipElemenata**elementi= nullptr; };


template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) {
 if(!mat.elementi) return;
 for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
 delete[] mat.elementi;
 mat.elementi = nullptr;
 }

template<typename TipElemenata> 
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
Matrica<TipElemenata> mat;
mat.br_redova = br_redova;
mat.br_kolona = br_kolona;
mat.elementi = new TipElemenata*[br_redova];
for(int i = 0; i < br_redova; i++)
mat.elementi[i] = nullptr;
try
{
for(int i = 0; i < br_redova; i++) 
mat.elementi[i] = new TipElemenata[br_kolona];  
}
catch
(...) {
UnistiMatricu(mat);
throw ;
}
return mat;
}
template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
for(int i = 0; i < mat.br_redova; i++)
for(int j = 0; j < mat.br_kolona; j++) {
cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
cin >> mat.elementi[i][j];
}
}
template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata>&mat, int sirina_ispisa,int preciznost = 6,bool treba_brisati=false){
    if(treba_brisati==true) UnistiMatricu(mat);
for(int i = 0; i < mat.br_redova; i++) {
for(int j = 0; j < mat.br_kolona; j++) 
cout << setw(sirina_ispisa)<<setprecision(preciznost) << mat.elementi[i][j];
cout << endl;
if(treba_brisati) UnistiMatricu(mat);
}
}
template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)throw domain_error("Matrice nemaju jednake dimenzije!");
auto m3 (StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
for(int i = 0; i < m1.br_redova; i++)
for( int j = 0; j < m1.br_kolona; j++)
m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata>ProduktMatrica(const Matrica<TipElemenata>&m1,const Matrica<TipElemenata>&m2){
    if(m1.br_kolona!=m2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
     Matrica<TipElemenata>x;
    auto m3=(x=StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
    for(int j=0;j<m2.br_kolona;j++)
    for(int k=0;k<m2.br_kolona;k++)
    m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
    UnistiMatricu(x);
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, vector<double> &v){
    if(m.br_redova!=m.br_kolona) throw domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata>a,b,c,d,e,f,g;
    auto Jed (a=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i=0;i<Jed.br_redova;i++){
        for(int j=0;j<Jed.br_kolona;j++){
            Jed.elementi[i][j]=0;
        }
    }
    for(int i=0;i<Jed.br_redova;i++)
    Jed.elementi[i][i]=1;
    auto Null(b=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i=0;i<Null.br_redova;i++)
    for(int j=0;j<Null.br_kolona;j++)
    Null.elementi[i][j]=0;
  
   if(v.size()==0) return Null;
    auto Nova(c=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    auto Zavrsna(d=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int j=0;j<Nova.br_redova;j++)
            for(int k=0;k<Nova.br_kolona;k++)
            Nova.elementi[j][k]=m.elementi[j][k];
    auto Nova2(e=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    auto Pomocna(f=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i=0;i<v.size();i++){
        if(i==0){
            for(int j=0;j<Jed.br_redova;j++)
            for(int k=0;k<Jed.br_kolona;k++)
            Jed.elementi[j][k]=Jed.elementi[j][k]*v[0];
        
        //Ispis prve
  /*     cout<<"Matrica za i="<<i<<": "<<endl;
        for(int j=0;j<Jed.br_redova;j++){
            for(int k=0;k<Jed.br_kolona;k++)
            cout<<Jed.elementi[j][k]<<"  ";
            cout<<endl;
        } */
        
        }
        else if(i==1){
            for(int j=0;j<m.br_redova;j++)
            for(int k=0;k<m.br_kolona;k++)
            Pomocna.elementi[j][k]=m.elementi[j][k];
            for(int j=0;j<m.br_redova;j++)
            for(int k=0;k<m.br_kolona;k++)
            Pomocna.elementi[j][k]=Pomocna.elementi[j][k]*v[1];
     /*          cout<<"Matrica za i="<<i<<": "<<endl;
        for(int j=0;j<Pomocna.br_redova;j++){
            for(int k=0;k<Pomocna.br_kolona;k++)
            cout<<Pomocna.elementi[j][k]<<"  ";
            cout<<endl;
        }*/ 
        }
        else{
            Nova=(g=ProduktMatrica(Nova,m));
            for(int j=0;j<m.br_redova;j++)
                for(int k=0;k<m.br_kolona;k++)
                    Nova2.elementi[j][k]=Nova.elementi[j][k]*v[i];
     /*       cout<<"Matrica za i="<<i<<": "<<endl;
            for(int j=0;j<Nova.br_redova;j++){
            for(int k=0;k<Nova.br_kolona;k++)
           cout<<Nova.elementi[j][k]<<" ";
           cout<<endl;
            } */
        }
       
}
for(int i=0;i<m.br_redova;i++)
for(int j=0;j<m.br_kolona;j++)
Zavrsna.elementi[i][j]=Jed.elementi[i][j]+Pomocna.elementi[i][j]+Nova.elementi[i][j];
        
/*    for(int i=0;i<m.br_redova;i++){
for(int j=0;j<m.br_kolona;j++)
    cout<<Zavrsna.elementi[i][j]<<" ";
cout<<endl;
} */
UnistiMatricu(a);UnistiMatricu(b);UnistiMatricu(c);UnistiMatricu(d);UnistiMatricu(e);UnistiMatricu(f);UnistiMatricu(g);
return Zavrsna;
    
    }
    
   



int main() {
Matrica<double> a, b, c,d;
int m;
cout << "Unesite dimenziju kvadratne matrice: ";
cin>>m;
vector<double>v;
int dim;
int x;
try
{
a = StvoriMatricu<double>(m,m); 
cout << "Unesite elemente matrice A:"<<endl;;
UnesiMatricu('A', a);
cout<<"Unesite red polinoma: ";
cin>>dim;
cout<<"Unesite koeficijente polinoma: ";
for(int i=0;i<dim+1;i++){
cin>>x;
v.push_back(x);
}

d=MatricniPolinom(a,v);
IspisiMatricu(d,10,6,true);

}
catch(bad_alloc) {
cout << "Nema dovoljno memorije!\n";
}
UnistiMatricu(a);UnistiMatricu(d);
return 0;
}