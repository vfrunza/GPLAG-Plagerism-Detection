/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>
using std::initializer_list;
using std::vector;
using std::cout;
using std::cin;
/*template <typename Tip>
class Niz
{
    private:
    vector<Tip> niz;
    int broj_redova;
    public:
    Niz():broj_redova(0){}
    Niz(Tip nniz[2]){niz.push_back(nniz[0]); niz.push_back(nniz[1]); broj_redova=2;}
    Tip &operator [](int broj) {return niz[broj];}
};*/
template <typename Tip>
class GMatrica
{
    private:
    Tip matrica[4][4];
    int broj_redova;
    int broj_kolona;
    template <typename Tip1,typename Tip2>
    static bool SaglasneZaMnozenje(GMatrica<Tip1> mat1,GMatrica<Tip2> mat2);
    template <typename Tip1,typename Tip2>
    static bool SaglasneZaSabiranje(GMatrica<Tip1> mat1,GMatrica<Tip2> mat2);
    public:
    GMatrica();
    GMatrica(int broj_r,int broj_k,Tip vrijednost=Tip());
    template <typename Tip1>
    GMatrica(const GMatrica<Tip1> &mat);
    GMatrica(Tip niz[4][4]);
    GMatrica(vector<vector<Tip>> vektor);
    GMatrica(initializer_list<initializer_list<Tip>> lista);
    int DajBrojRedova() const {return broj_redova;}
    int DajBrojKolona() const {return broj_kolona;}
    template <typename Tip1,typename Tip2>
    friend bool operator ==(GMatrica<Tip1> mat1,GMatrica<Tip2> mat2);
    template <typename Tip1,typename Tip2>
    friend bool operator !=(GMatrica<Tip1> mat1,GMatrica<Tip2> mat2);
    Tip &operator ()(int broj_reda,int broj_kolone);
    Tip operator ()(int broj_reda,int broj_kolone) const;
   // Niz<Tip> &operator [](int broj) const;
    vector<Tip> operator [](int broj) const;
    template<typename Tip1>
    friend std::istream &operator >>(std::istream &tok,GMatrica<Tip1> &mat);
    template<typename Tip1>
    friend std::ostream &operator <<(std::ostream &tok,const GMatrica<Tip1> &mat);
    
    template <typename Tip1,typename Tip2>
    friend auto operator +(const GMatrica<Tip1> &mat1,const GMatrica<Tip2> &mat2)->GMatrica<decltype(mat1.matrica[0][0]*mat2.matrica[0][0])>;
    template <typename Tip1,typename Tip2>
    friend auto operator -(const GMatrica<Tip1> &mat1,const GMatrica<Tip2> &mat2)->GMatrica<decltype(mat1.matrica[0][0]*mat2.matrica[0][0])>;
    template <typename Tip1,typename Tip2>
    friend auto operator *(const GMatrica<Tip1> &mat1, const GMatrica<Tip2> &mat2)->GMatrica<decltype(mat1.matrica[0][0]*mat2.matrica[0][0])>;
    template <typename Tip1,typename Tip2>
    friend auto operator *(const GMatrica<Tip1> &mat,Tip2 a)->GMatrica<decltype(mat.matrica[0][0]*a)>;
    template <typename Tip1,typename Tip2>
    friend auto operator *(Tip1 a,GMatrica<Tip2> mat)->GMatrica<decltype(mat.matrica[0][0]*a)>;
    
    
    template <typename Tip1>
    GMatrica<Tip> &operator +=(const GMatrica<Tip1> &mat2);
    template <typename Tip1>
    GMatrica<Tip> &operator -=(const GMatrica<Tip1> &mat2);
    template <typename Tip1>
    GMatrica<Tip> &operator *=(const GMatrica<Tip1> &mat2);
    template <typename Tip1>
    GMatrica<Tip> &operator *=(Tip1 a);
};
template <typename Tip>
GMatrica<Tip>::GMatrica ()
{
    broj_redova=0;
    broj_kolona=0;
}
template <typename Tip>
GMatrica<Tip>::GMatrica(int broj_r,int broj_k,Tip vrijednost)
{
    if(broj_r<0 || broj_r>4 || broj_k<0 || broj_k>4) throw std::logic_error("Ilegalan format matrice");
    broj_redova=broj_r;
    broj_kolona=broj_k;
    for(int i=0;i<broj_redova;i++)
    for(int j=0;j<broj_kolona;j++)
    {
    GMatrica::matrica[i][j]=vrijednost;
    }
}
template <typename Tip>
template <typename Tip1>
GMatrica<Tip>::GMatrica(const GMatrica<Tip1> &mat)
{
    broj_redova=mat.DajBrojRedova();
    broj_kolona=mat.DajBrojKolona();
    for(int i=0;i<mat.DajBrojRedova();i++)
    for(int j=0;j<mat.DajBrojKolona();j++)
    matrica[i][j]=(mat[i][j]);
}
template <typename Tip>
GMatrica<Tip>::GMatrica(Tip niz[4][4])
{
    broj_redova=4;
    broj_kolona=4;
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    matrica[i][j]=niz[i][j];
}
template <typename Tip>
GMatrica<Tip>::GMatrica(vector<vector<Tip>> vektor)
{
    if(vektor.size()<0 || vektor.size()>4) throw std::logic_error("Ilegalan format matrice");
    bool provjera(false);
    if(vektor.size()!=0)
    for(int i=0;i<vektor.size();i++)
    {
        if(vektor[i].size()!=vektor[0].size() || vektor[i].size()>4)
        provjera=true;
    }
    if(provjera) throw std::logic_error("Ilegalan format matrice");
    broj_redova=vektor.size();
    if(vektor.size()!=0)
    broj_kolona=vektor[0].size();
    else
    broj_kolona=0;
    for(int i=0;i<vektor.size();i++)
    for(int j=0;j<vektor[0].size();j++)
    matrica[i][j]=vektor[i][j];
}
template <typename Tip>
GMatrica<Tip>::GMatrica(initializer_list<initializer_list<Tip>> lista)
{
    if(lista.size()<0 || lista.size()>4) throw std::logic_error("Ilegalan format matrice");
    bool provjera(false);
    if(lista.size()!=0)
    {
        for(auto it=lista.begin();it!=lista.end();it++)
        if(it->size()!=(lista.begin())->size() || it->size()>4)
        provjera=true;
    }
    if(provjera) throw std::logic_error("Ilegalan format matrice");
    broj_redova=lista.size();
    if(lista.size()!=0)
    broj_kolona=(lista.begin())->size();
    else
    broj_kolona=0;
    int i(0),j(0);
    for(auto it1=lista.begin();it1!=lista.end();it1++)
    {
        j=0;
        for(auto it2=it1->begin();it2!=it1->end();it2++)
        {
            matrica[i][j]=*it2;
            j++;
        }
        i++;
    }
}
template<typename Tip>
template<typename Tip1,typename Tip2>
bool GMatrica<Tip>::SaglasneZaSabiranje(GMatrica<Tip1> mat1,GMatrica<Tip2> mat2)
{
    if(mat1.DajBrojRedova()==mat2.DajBrojRedova() && mat1.DajBrojKolona()==mat2.DajBrojKolona()) return true;
    return false;
}
template<typename Tip>
template<typename Tip1,typename Tip2>
bool GMatrica<Tip>::SaglasneZaMnozenje(GMatrica<Tip1> mat1,GMatrica<Tip2> mat2)
{
    if(mat1.DajBrojKolona()==mat2.DajBrojRedova()) return true;
    return false;
}
template <typename Tip1,typename Tip2>
bool operator ==(GMatrica<Tip1> mat1,GMatrica<Tip2> mat2)
{
    if(!GMatrica<Tip1>::SaglasneZaSabiranje(mat1,mat2)) return false;
    for(int i=0;i<mat1.broj_redova;i++)
    for(int j=0;j<mat1.broj_kolona;j++)
    {
        if(mat1.matrica[i][j]!=mat2.matrica[i][j])
        return false;
    }
    return true;
}
template <typename Tip1,typename Tip2>
inline bool operator !=(GMatrica<Tip1> mat1,GMatrica<Tip2> mat2)
{
    return(!(mat1==mat2));
}
template <typename Tip>
Tip &GMatrica<Tip>::operator ()(int broj_reda,int broj_kolone)
{
    broj_reda--;
    broj_kolone--;
    if(broj_reda<0 || broj_reda>=broj_redova || broj_kolone<0 || broj_kolone>=broj_kolona)
    throw std::range_error("Nedozvoljen indeks");
    return matrica[broj_reda][broj_kolone];
}
template <typename Tip>
Tip GMatrica<Tip>::operator ()(int broj_reda,int broj_kolone) const
{
    broj_reda--;
    broj_kolone--;
    if(broj_reda<0 || broj_reda>=broj_redova || broj_kolone<0 || broj_kolone>=broj_kolona)
    throw std::range_error("Nedozvoljen indeks");
    return matrica[broj_reda][broj_kolone];
}
template <typename Tip>
vector<Tip> GMatrica<Tip>::operator [] (int broj) const
{
    vector<Tip> vek;
    for(int i=0;i<(this->broj_kolona);i++)
    vek.push_back(matrica[broj][i]);
    return vek;
}
/*template <typename Tip>
Niz<Tip> &GMatrica<Tip>::operator [] (int broj) const
{
    return matrica[broj];
}*/
template <typename Tip1,typename Tip2>
auto operator +(const GMatrica<Tip1> &mat1,const GMatrica<Tip2> &mat2)->GMatrica<decltype(mat1.matrica[0][0]*mat2.matrica[0][0])>
{
    if(!(GMatrica<Tip1>::SaglasneZaSabiranje(mat1,mat2))) throw std::domain_error("Nedozvoljena operacija");
    if(mat1.broj_redova==0 || mat1.broj_kolona==0)
    return mat1;
    GMatrica<decltype(mat1.matrica[0][0]*mat2.matrica[0][0])> mat3(mat1);
    for(int i=0;i<mat1.broj_redova;i++)
    for(int j=0;j<mat1.broj_kolona;j++)
    {
        mat3.matrica[i][j]+=mat2.matrica[i][j];
    }
    return mat3;
}
template <typename Tip1,typename Tip2>
auto operator -(const GMatrica<Tip1> &mat1,const GMatrica<Tip2> &mat2)->GMatrica<decltype(mat1.matrica[0][0]*mat2.matrica[0][0])>
{
    if(!(GMatrica<Tip1>::SaglasneZaSabiranje(mat1,mat2))) throw std::domain_error("Nedozvoljena operacija");
    if(mat1.broj_redova==0 || mat1.broj_kolona==0)
    return mat1;
    GMatrica<decltype(mat1.matrica[0][0]*mat2.matrica[0][0])> mat3(mat1);
    for(int i=0;i<mat1.broj_redova;i++)
    for(int j=0;j<mat1.broj_kolona;j++)
    {
        mat3.matrica[i][j]-=mat2.matrica[i][j];
    }
    return mat3;
}
template <typename Tip1,typename Tip2>
auto operator *(const GMatrica<Tip1> &mat1,const GMatrica<Tip2> &mat2)->GMatrica<decltype(mat1.matrica[0][0]*mat2.matrica[0][0])>
{
   if(!(GMatrica<Tip1>::SaglasneZaMnozenje(mat1,mat2))) throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(mat1.matrica[0][0]*mat2.matrica[0][0])> mat3(mat1.broj_redova,mat2.broj_kolona,0);
    for(int i=0;i<mat1.broj_redova;i++)
    {
        for(int j=0;j<mat2.broj_kolona;j++)
        {
            decltype(mat1.matrica[0][0]*mat2.matrica[0][0]) suma=decltype(mat1.matrica[0][0]*mat2.matrica[0][0])();
            for(int k=0;k<mat2.broj_redova;k++)
            {
                suma+=(mat1.matrica[i][k]*mat2.matrica[k][j]);
                mat3.matrica[i][j]=suma;
            }
        }
    }
    return mat3;
}
template <typename Tip1,typename Tip2>
auto operator *(const GMatrica<Tip1> &mat,Tip2 a)->GMatrica<decltype(mat.matrica[0][0]*a)>
{
    if(mat.broj_redova==0 || mat.broj_kolona==0) return mat;
    GMatrica<decltype(mat.matrica[0][0]*a)> mat2(mat);
    for(int i=0;i<mat.broj_redova;i++)
    {
        for(int j=0;j<mat.broj_kolona;j++)
        mat2.matrica[i][j]*=a;
    }
    return mat2;
}
template <typename Tip1,typename Tip2>
auto operator *(Tip1 a,GMatrica<Tip2> mat)->GMatrica<decltype(mat.matrica[0][0]*a)>
{
    if(mat.broj_redova==0 || mat.broj_kolona==0) return mat;
    GMatrica<decltype(mat.matrica[0][0]*a)> mat2(mat);
    for(int i=0;i<mat.broj_redova;i++)
    {
        for(int j=0;j<mat.broj_kolona;j++)
        mat2.matrica[i][j]*=a;
    }
    return mat2;
}

template <typename Tip>
template <typename Tip1>
GMatrica<Tip> &GMatrica<Tip>::operator +=(const GMatrica<Tip1> &mat2)
{
    if(!(GMatrica<Tip1>::SaglasneZaSabiranje(*this,mat2))) throw std::domain_error("Nedozvoljena operacija");
    if(this->broj_redova==0 || this->broj_kolona==0)
    return *this;
    for(int i=0;i<this->broj_redova;i++)
    for(int j=0;j<this->broj_kolona;j++)
    this->matrica[i][j]+=mat2.matrica[i][j];
    return *this;
}
template <typename Tip>
template <typename Tip1>
GMatrica<Tip> &GMatrica<Tip>::operator -=(const GMatrica<Tip1> &mat2)
{
    if(!(GMatrica<Tip1>::SaglasneZaSabiranje(*this,mat2))) throw std::domain_error("Nedozvoljena operacija");
    if(this->broj_redova==0 || this->broj_kolona==0)
    return *this;
    for(int i=0;i<this->broj_redova;i++)
    for(int j=0;j<this->broj_kolona;j++)
    this->matrica[i][j]-=mat2.matrica[i][j];
    return *this;
}
template <typename Tip>
template <typename Tip1>
GMatrica<Tip> &GMatrica<Tip>::operator *=(Tip1 a)
{
    if(this->broj_redova==0 || this->broj_kolona==0)
    return *this;
    for(int i=0;i<this->broj_redova;i++)
    for(int j=0;j<this->broj_kolona;j++)
    (this->matrica[i][j])*=a;
    return *this;
}
template <typename Tip>
template <typename Tip1>
GMatrica<Tip> &GMatrica<Tip>::operator *=(const GMatrica<Tip1> &mat2)
{
    if(!(GMatrica<Tip1>::SaglasneZaMnozenje(*this,mat2))) throw std::domain_error("Nedozvoljena operacija");
    if(this->broj_redova==0 || this->broj_kolona==0)
    return *this;
    GMatrica<Tip> mat3(this->broj_redova,mat2.broj_kolona);
    for(int i=0;i<this->broj_redova;i++)
    {
        for(int j=0;j<mat2.broj_kolona;j++)
        {
            Tip suma=Tip();
            for(int k=0;k<mat2.broj_redova;k++)
            {
                suma+=((this->matrica[i][k])*mat2.matrica[k][j]);
                mat3.matrica[i][j]=suma;
            }
        }
    }
    *this=mat3;
    return *this;
}
template<typename Tip>
std::ostream &operator <<(std::ostream &tok,const GMatrica<Tip> &mat)
{
    std::streamsize velicina(tok.width());
    if(velicina<6) velicina=6;
    for(int i=0;i<mat.broj_redova;i++)
    {
        for(int j=0;j<mat.broj_kolona;j++)
        {
            tok<<std::setw(velicina)<<mat.matrica[i][j];
        }
        tok<<'\n';
    }
    return tok;
}
template<typename Tip>
std::istream &operator >>(std::istream &tok,GMatrica<Tip> &mat1)
{
    tok>>std::ws;
    vector<vector<Tip>> mat;
    vector<Tip> vek;
    char znak='w';
    tok>>znak;
    if(znak!='[')
    {
    tok.setstate(std::ios::failbit);
    return tok;
    }
    else
    {
        Tip broj;
        while(tok.peek()!=']')
        {
            tok>>broj>>znak;
            if(znak!=',' && znak!=';' && znak!=']')
            {
            tok.setstate(std::ios::failbit);
            return tok;
            }
            vek.push_back(broj);
            if(znak==';' || znak==']')
            {
            mat.push_back(vek);
            vek.resize(0);
            }
            if(znak==']' || znak=='\n')
            break;
        }
    }
    try
    {
        GMatrica<Tip> nova(mat);
        mat1=nova;
    }
    catch(...)
    {
       tok.setstate(std::ios::failbit);
       return tok; 
    }
    return tok;
}
int main()
{
vector<vector<double>> vek{{1.1,1,3,4},{2,3,5.1,6},{2,5,5,5},{4,4,4,4}};
int mat[4][4]={{1,2},{6,7},{},{}};
try
{
GMatrica<int> mat2(mat);
GMatrica<double> mat1(vek);
cout<<"broj redova: "<<mat1.DajBrojRedova()<<" "<<mat1.DajBrojRedova()<<" broj kolona: "<<mat1.DajBrojKolona()<<" "<<mat2.DajBrojKolona()<<std::endl;
cout<<"mat1 i mat2: "<<std::endl;
cout<<mat1<<std::endl<<mat2;
}
catch(...)
{
    cout<<"izuzetak";
}
    return 0;
}