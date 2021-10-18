/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <initializer_list>
using namespace std;
template<typename TipEl>
class GMatrica{

    int redovi, kolone;
    
    TipEl elementi[4][4];
public:

    GMatrica(){}
    GMatrica(int red, int kol, TipEl vrijednost=0): redovi(red), kolone(kol)
    {
        if(redovi>4 || kolone>4) throw logic_error("Ilegalan format matrice");
    for(int i=0;i<redovi;i++)
        for(int j=0;j<kolone;j++)
        elementi[i][j]=vrijednost; 
    }   
    template<typename TipEl1>
    GMatrica(const GMatrica<TipEl1> &mat):redovi(mat.redovi), kolone(mat.kolone)
    {
        for(int i=0;i<mat.redovi;i++)
            for(int j=0;j<mat.kolone;j++)
                elementi[i][j]=mat.elementi[i][j];
    }
    GMatrica(const vector<vector<TipEl>> &v)
    {
        redovi=v.size();
        kolone=v[0].size();
        bool br_se_ne_slaze=false;
        for(int i=1;i<v.size();i++)
        if(v[i].size()!=v[0].size())br_se_ne_slaze=true;
        if(v.size()>4 || v[0].size()>4 || br_se_ne_slaze)throw logic_error("Ilegalan format matrice");

        for(int i=0;i<v.size();i++)
            for(int j=0;j<v[0].size();j++)
                elementi[i][j]=v[i][j];
    }
    template<typename TipEl1>
    GMatrica(TipEl1 **a)
    {
        cout<<"hamo";
        redovi=4;
        kolone=4;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                elementi[i][j]=a[i][j];
        
        
    }
    int DajBrojRedova()const {return redovi;}
    int DajBrojKolona()const {return kolone;}
 template<typename TipEl1>
 friend GMatrica<TipEl1> operator +(const  GMatrica<TipEl1> &mat1 ,const  GMatrica<TipEl1> &mat2);
 template<typename TipEl1>
 friend GMatrica<TipEl1> operator -(const  GMatrica<TipEl1> &mat1 ,const GMatrica<TipEl1> &mat2);
 template<typename TipEl1>
 friend GMatrica<TipEl1> operator *(const GMatrica<TipEl1> &mat1,const GMatrica<TipEl1> &mat2);
 template<typename TipEl1, typename TipEl2>
 friend GMatrica<TipEl1> operator *(const GMatrica<TipEl1> &mat, TipEl2 a);
 template<typename TipEl1, typename TipEl2>
 friend GMatrica<TipEl1> operator *(TipEl2 a,const GMatrica<TipEl1> &mat);
 template<typename TipEl1,typename TipEl2>
 friend GMatrica<TipEl1> operator *(TipEl2 a,const GMatrica<TipEl1> &mat);
 template<typename TipEl1,typename TipEl2>
 friend GMatrica<TipEl1> operator *(TipEl2 a,const GMatrica<TipEl1> &mat);
 
 GMatrica<TipEl> &operator +=(const GMatrica<TipEl> &mat);

 GMatrica<TipEl> &operator -=(const GMatrica<TipEl> &mat);

 GMatrica<TipEl> &operator *=(TipEl a);

GMatrica<TipEl> operator *=(const GMatrica<TipEl> &mat);

 
 template<typename TipEl1>
 friend ostream &operator<<(ostream &cout, const GMatrica<TipEl1> &mat1);
 template<typename TipEl1>
 friend istream &operator>>(istream &cin, GMatrica<TipEl1> &mat1);
 template<typename TipEl1>
 friend bool operator ==(const GMatrica<TipEl1> &mat1,const GMatrica<TipEl1> &mat2);
 template<typename TipEl1>
 friend bool operator !=(const GMatrica<TipEl1> &mat1,const GMatrica<TipEl1> &mat2);
double operator ()(int red,int k)
{
    if(red>4 || k>4)throw range_error("Nedozvoljeni indexi");
    redovi=red; kolone=k;
    return elementi[red-1][k-1];
}
template<typename TipEl1>
double* operator [](int a) 
{  return elementi[a];
}
//}
/*template<typename TipEl1>
auto operator[](int a)->vector<decltype (a)> 
{return elementi[a];}
*/
};

 template<typename TipEl1>
GMatrica<TipEl1> operator +(const GMatrica<TipEl1> &mat1 , const GMatrica<TipEl1> &mat2)
 {
     if(mat1.redovi!=mat2.redovi || mat1.kolone!=mat2.kolone) throw domain_error("Nedozvoljena operacija");
     GMatrica<TipEl1>mat3(mat1.redovi, mat1.kolone);
     for(int i=0;i<mat1.redovi;i++)
        for(int j=0;j<mat1.kolone;j++)
            mat3.elementi[i][j]=mat1.elementi[i][j]+mat2.elementi[i][j];
            return mat3;
 }
 
  template<typename TipEl1>
GMatrica<TipEl1> operator -(const GMatrica<TipEl1> &mat1 , const GMatrica<TipEl1> &mat2)
 {
     
     if(mat1.redovi!=mat2.redovi || mat1.kolone!=mat2.kolone)throw domain_error("Nedozvoljena operacija");
     GMatrica<TipEl1>mat3(mat1.redovi, mat1.kolone);
     for(int i=0;i<mat1.redovi;i++)
        for(int j=0;j<mat1.kolone;j++)
            mat3.elementi[i][j]=mat1.elementi[i][j]-mat2.elementi[i][j];
            return mat3;
 }
 template<typename TipEl1>
 GMatrica<TipEl1> operator *(const GMatrica<TipEl1> &mat1,const GMatrica<TipEl1> &mat2)
 {
    if(mat1.kolone!=mat2.redovi)throw domain_error("Nedozvoljena operacija");
     GMatrica<TipEl1>mat(mat1.redovi, mat2.kolone);
     for(int i=0;i<mat1.redovi;i++)
         for(int j=0;j<mat2.kolone;j++)
            for(int k=0;k<mat2.redovi;k++)
            mat.elementi[i][j]=mat.elementi[i][j]+(mat1.elementi[i][k]*mat2.elementi[k][j]);
            return mat;
 }
 template<typename TipEl1, typename TipEl2>
 GMatrica<TipEl1> operator *(const GMatrica<TipEl1> &mat, TipEl2 a)
 {
      
     GMatrica<TipEl1>mat3(mat.redovi, mat.kolone);
     for(int i=0;i<mat.redovi;i++)
         for(int j=0;j<mat.kolone;j++)
            mat3.elementi[i][j]=mat.elementi[i][j]*a;
            return mat3;
 }
 template<typename TipEl1, typename TipEl2>
 GMatrica<TipEl1> operator *(TipEl2 a,const GMatrica<TipEl1> &mat)
 {
     GMatrica<TipEl1>mat3(mat.redovi, mat.kolone);
     for(int i=0;i<mat.redovi;i++)
         for(int j=0;j<mat.kolone;j++)
            mat3.elementi[i][j]=mat.elementi[i][j]*a;
            return mat3;
 }
 template<typename TipEl>
 GMatrica<TipEl> &GMatrica<TipEl>::operator +=(const GMatrica<TipEl> &mat)
 {
     for(int i=0;i<mat.redovi;i++)
        for(int j=0;j<mat.kolone;j++)
            elementi[i][j]+=mat.elementi[i][j];
    return *this;
 }
 
 template<typename TipEl>
 GMatrica<TipEl> &GMatrica<TipEl>::operator-=(const GMatrica<TipEl> &mat)
 {
     for(int i=0;i<mat.redovi;i++)
        for(int j=0;j<mat.kolone;j++)
            elementi[i][j]-=mat.elementi[i][j];
    return *this;
 }
template<typename TipEl>
GMatrica<TipEl> &GMatrica<TipEl>::operator *=(TipEl a)
{
     for(int i=0;i<redovi;i++)
        for(int j=0;j<kolone;j++)
            elementi[i][j]*=a;
    return *this;
 }
 template<typename TipEl>
GMatrica<TipEl> GMatrica<TipEl>::operator *=(const GMatrica<TipEl> &mat)
 {
     
    if(kolone!=mat.redovi)throw domain_error("Nedozvoljena operacija");
     GMatrica<TipEl>mat1(redovi, mat.kolone);
     for(int i=0;i<redovi;i++)
         for(int j=0;j<mat.kolone;j++)
            for(int k=0;k<mat.redovi;k++)
            mat1.elementi[i][j]+=elementi[i][k]*mat.elementi[k][j];
            
            for(int i=0;i<redovi;i++)
                for(int j=0;j<mat.kolone;j++)
                    elementi[i][j]=mat1.elementi[i][j];
            
            
            return *this;
 }


 
 template<typename TipEl1>
ostream &operator<<(ostream &cout, const GMatrica<TipEl1> &mat1)
 {
     for(int i = 0; i < mat1.redovi; i++) {
        for(int j = 0; j < mat1.kolone; j++)
            cout<<setw(6)<<mat1.elementi[i][j];
            cout<<endl;
            }
            return cout;
 }
 template<typename TipEl1>
 istream &operator>>(istream &cin, GMatrica<TipEl1> &mat1)
 {
     char znak;
     bool kraj=false;
     cin>>znak;
     if(znak=='[')
     {
         for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cin>>mat1.elementi[i][j]>>znak;
                if(znak==',')continue;
                if(znak==';'){mat1.kolone=j+1;break;}
                if(znak==']'){break;}
            }
          if(znak==']'){ mat1.redovi=i+1;kraj=true;break;}
         }
     }
    
            if(kraj) return cin;
            else throw;
     
 }
 template<typename TipEl1>
 bool operator ==(const GMatrica<TipEl1> &mat1,const GMatrica<TipEl1> &mat2)
 {
     if(mat1.redovi != mat2.redovi || mat1.kolone!=mat2.kolone) { return false;}
     for(int i=0;i<mat1.redovi;i++)
        for(int j=0;j<mat1.kolone;j++)
            if(mat1.elementi[i][j]!=mat2.elementi[i][j])return false;
            return true;
 }
 template<typename TipEl1>
 bool operator !=(const GMatrica<TipEl1> &mat1,const GMatrica<TipEl1> &mat2)
 {
     if(mat1.redovi != mat2.redovi || mat1.kolone!=mat2.kolone) { return true;}
     for(int i=0;i<mat1.redovi;i++)
        for(int j=0;j<mat1.kolone;j++)
            if(mat1.elementi[i][j]!=mat2.elementi[i][j])return true;
            return false;
 }
 
int main ()
{
    
   GMatrica<int> m1({{1, 2}, {3, 4}});
std::cout << m1[1][1] << std::endl;
	return 0;
}