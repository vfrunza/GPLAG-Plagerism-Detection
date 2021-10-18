/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include<iomanip>
#include<stdexcept>
#include<vector>
#include<new>
using namespace std; 

template <typename tip>
struct Matrica
{
    int red, kolona; 
    tip **pok=nullptr; 
}; 
template <typename tip>
void DealocirajM(Matrica<tip>mat)
{
    if(!mat.pok) return; 
    for(int i=0; i<mat.red; i++) 
    delete[] mat.pok[i]; 
    delete []mat.pok; 
    mat.pok =nullptr; 
}
template <typename tip>
Matrica<tip>StvoriMatricu(int red, int kolona) 
{
    Matrica<tip>mat; 
    mat.red=red; 
    mat.kolona=kolona;
     mat.pok=nullptr; 
    try{
    mat.pok=new tip*[red]; 
    for(int i=0; i<red; i++)  mat.pok[i]=nullptr; 
    try{
    for(int i=0; i<red; i++)  mat.pok[i]=new tip[kolona]; 
     for(int i=0; i<red; i++) 
      { for(int j=0; j<kolona; j++) 
        {mat.pok[i][j]=0; 
        }}}
        catch(...) { throw; }
    }
    catch(...)  {
        DealocirajM<tip>(mat);
        throw; }
      return mat; 
    }
    
template <typename tip>
void UnesiMatricu(char ime_matrice, Matrica<tip>&mat) 
{
    for(int i=0; i<mat.red; i++)
     for(int j=0; j<mat.kolona; j++) 
     {cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
     cin>>mat.pok[i][j]; 
}
 }
 
 template <typename tip>
void Pomocna( Matrica<tip>&b, Matrica<tip> a)
{
    DealocirajM<tip>(b); 
    try{
    b=Napravikopiju(a);
    }
   catch(...) {throw; }
}
 template <typename tip>
 void IspisiMatricu(const Matrica<tip>&mat, int sirina_ispisa=10, int preciznost=6,bool treba_brisati=false)
 {
  for(int i=0; i<mat.red; i++)
    { for(int j=0; j<mat.kolona; j++) 
      cout<<setw(sirina_ispisa)<<setprecision(preciznost)<<mat.pok[i][j]; 
      cout<<endl; 
    }
    if(treba_brisati){
        DealocirajM(mat); 
    }
 }
  template <typename tip>
Matrica<tip> ZbirMatrica(const Matrica<tip> &a, const Matrica<tip> &b)
{
    if(a.red!=b.red || a.kolona!=b.kolona)
    throw domain_error ("Matrice nemaju jednake dimenzije!"); 
    auto c(StvoriMatricu<tip>(a.red, a.kolona));
    for(int i=0; i<c.red; i++)
     for(int j=0; j<c.kolona; j++)
     c.pok[i][j]=a.pok[i][j]+b.pok[i][j];  
     return c; 
    
}

template <typename tip>
Matrica<tip> ProduktMatrica(const Matrica<tip> &a, const Matrica<tip> &b) 
{
     if(a.red !=b.kolona)  throw domain_error("Matrica nisu saglasne za mnozenje");
    try{
    Matrica<tip>c=StvoriMatricu<tip>(a.red, b.kolona); 
    for(int i=0;i<a.red;i++)
        for(int j=0;j<a.kolona;j++)
            c.pok[i][j]=0;
     

    for(int i=0; i<c.red; i++) 
    { for(int j=0; j<c.kolona; j++) 
      {for(int k=0; k<c.red; k++)
       { c.pok[i][j]+=a.pok[i][k]*b.pok[k][j];
      }
    }
    }
      return c; 
}
catch(...) { throw; }
}
template <typename tip>
Matrica <tip>StepenMatrice (Matrica<tip> a, int broj)
{  
    try{ 
        
    for(int i=0; i<a.red ; i++) 
       for(int j=0; j<a.kolona; j++)  a.pok[i][j]=0; 
    Matrica<tip>c=Napravikopiju(a); 
    
    if(broj>=2) {
        for(int i=2; i<=broj; i++) {
        Pomocna<tip>(c, ProduktMatrica<tip>(c,a)); 
        }
        return c; 
    }
    if(broj==1) return c; 
    if(broj==0)
    {
        for(int i=0; i<c.red; i++) 
         for(int j=0; j<c.kolona; j++) 
           if(i==j) c.pok[i][j]=1; 
        else c.pok[i][j]=0; 
        return c; 
         }
    }
        catch(...) {throw;} 

}
template <typename tip>
Matrica<tip> ProizvodSaPolinomom( Matrica<tip> a, double broj) 
{ try{
    Matrica<tip> c=StvoriMatricu<tip>(a.red,a.kolona); 
    for(int i=0; i<a.red; i++) {
     for(int j=0; j<a.kolona; j++) {
         c.pok[i][j]=broj*a.pok[i][j]; 
     }
    }
     return c; 
}
catch(...) { throw; }
}
template <typename tip>
Matrica<tip> Napravikopiju(Matrica<tip> a) 
{
    Matrica<tip>c; 
    c.red=a.red; c.kolona=a.kolona; 
    try{
    c.pok=new tip *[c.red]; 
    try{
    for(int i=0; i<c.red; i++) {
      c.pok[i]=new tip[c.kolona]; 
    }
    for(int i=0; i<c.red; i++) 
      {for(int j=0; j<c.kolona; j++) 
        { c.pok[i][j]=a.pok[i][j]; 
    }
}
    return c; 
}
catch(...) {
    throw; 
}}
catch(...) {
    DealocirajM<tip>(c); throw; 
}
}


template <typename tip>
Matrica<tip> MatricniPolinom(Matrica<tip> &a, vector<double>v )
{/* if(v.size()==0)
{    Matrica<tip> c;  
    for(int i=0; i<c.red; i++) 
     for(int j=0; j<c.red; j++) a.pok[i][j]==0; 
    return c; 
} // STA AKO JE PRAZAN VEKTOR*/
if(a.red != a.kolona) throw domain_error("Matrica mora biti kvadratna"); 
bool nula=true; 
try{
    
    Matrica<tip> sum=StvoriMatricu<tip>(a.red, a.kolona); 
for(int i=0; i<v.size(); i++) 
      {
          if(v[0]!=0) nula=false; 
      }
      
      if(nula) return sum; 
    for(int i=0; i<v.size(); i++) 
      {
        Matrica<tip> d=StepenMatrice<tip>(a, i); 
        Matrica<tip> e=ProizvodSaPolinomom<tip>(d, v[i]); 
        Pomocna<tip>(sum, ZbirMatrica<tip>(sum, e)); 
        DealocirajM(d); DealocirajM(e); 
        DealocirajM(a); 
    }
 return sum;    
}
catch(...) {
throw; }
}

int main ()
{
    Matrica<double>a,b,c; 
    int m; 
    cout<<"Unesite dimenziju kvadratne matrice: "; 
    cin>>m;
    
    try{
        Matrica<double>a=StvoriMatricu<double>(m,m); 
        //Matrica<double>b=StvoriMatricu<double>(m,m);
        cout<<"Unesite elemente matrice A: "; 
        UnesiMatricu('A', a);
        cout<<"Unesite red polinoma: ";
        int redpol; 
        cin>>redpol; 
        cout<<"Unesite koeficijente polinoma: ";
        vector<double>v(redpol+1); 
        for(int i=0; i<v.size(); i++) cin>>v[i]; 
        IspisiMatricu<double>(MatricniPolinom<double>(a,v),10, 6);
    }
    
    catch(bad_alloc)
    {
        cout<<"Nema dovoljno memorije!\n"; 
        
    }
    DealocirajM(a); DealocirajM(b); DealocirajM(c);  
	return 0;
}