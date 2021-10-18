/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <initializer_list>
using std::cout;
using std::cin;
using std::endl;
using std::logic_error;
using std::domain_error;
using std::initializer_list;
template<typename Tip>
class GMatrica{
    Tip matrica[4][4];
    int br_redova;
    int br_kolona;
    public:
    GMatrica<Tip>() : br_redova(0), br_kolona(0){};
    GMatrica<Tip>(int redovi, int kolone, Tip poc_vrijednost=Tip());
    template <typename DrugiTip>
    GMatrica<Tip> ( GMatrica<DrugiTip> &m);
    GMatrica<Tip> (Tip niz [4][4]);
    GMatrica<Tip> (std::vector<std::vector<Tip>> v);
    GMatrica<Tip> (std::initializer_list<std::initializer_list<Tip>> lista);
    int DajBrojRedova () const {return br_redova;};
    int DajBrojKolona () const {return br_kolona;};
    template <typename Tip1, typename NoviTip>
    friend auto operator +( const GMatrica<Tip1> &mat1, const GMatrica<NoviTip> &mat2)-> GMatrica<decltype(Tip1()+NoviTip())>;
    template <typename Tip1, typename NoviTip>
    friend auto operator -( const GMatrica<Tip1> &mat1, const GMatrica<NoviTip> &mat2)-> GMatrica<decltype(Tip1()+NoviTip())>;
    template <typename Tip1, typename NoviTip>
    friend auto operator *( const GMatrica<Tip1> &mat1, const GMatrica<NoviTip> &mat2)-> GMatrica<decltype(Tip1()+NoviTip())>;
    template <typename NoviTip, typename TipBroja>
    friend GMatrica<NoviTip> operator *(const GMatrica<NoviTip> &mat1, TipBroja broj);
    template <typename TipBroja,typename NoviTip>
    friend GMatrica<NoviTip> operator *(TipBroja broj, const GMatrica<NoviTip> &mat1);
    GMatrica<Tip> operator +=(const GMatrica &mat2);
    GMatrica<Tip> operator -=(const GMatrica &mat2);
    GMatrica<Tip> operator *=(const GMatrica &mat2);
    template <typename NoviTip>
    GMatrica<Tip> operator +=(NoviTip broj);
    template <typename NoviTip>
    GMatrica<Tip> operator -=(NoviTip broj);
    template <typename NoviTip>
    GMatrica<Tip> operator *=(NoviTip broj);
    template <typename NoviTip>
    friend bool operator ==(const GMatrica<NoviTip> &mat1, const GMatrica<NoviTip> &mat2);
    template <typename NoviTip>
    friend bool operator !=(const GMatrica<NoviTip> &mat1, const GMatrica<NoviTip> &mat2);
    Tip& operator () (int red, int kolona) ;
    Tip* operator [] (int index) ;
    template<typename NoviTip>
    friend std::ostream& operator <<(std::ostream &tok, const GMatrica<NoviTip> &mat);
    template<typename NoviTip>
    friend std::istream& operator >>(std::istream &tok, GMatrica<NoviTip> &mat);
};
template <typename Tip1, typename Tip2>
auto operator +(const GMatrica<Tip1> &mat1, const GMatrica<Tip2> &mat2)->GMatrica<decltype(Tip1()+Tip2())>
{
    if((mat1.br_redova != mat2.br_redova) || (mat1.br_kolona != mat2.br_kolona)) throw domain_error ("Nedozvoljena operacija");
    GMatrica<decltype(Tip1()+Tip2())> mat3 (mat1.br_redova,mat1.br_kolona);
    for(int i=0;i<mat1.br_redova;i++)
            for(int j=0;j<mat1.br_kolona;j++)
                mat3.matrica[i][j]=mat1.matrica[i][j]+mat2.matrica[i][j];
    return mat3;
}
template <typename Tip1, typename Tip2>
auto operator -(const GMatrica<Tip1> &mat1, const GMatrica<Tip2> &mat2)->GMatrica<decltype(Tip1()+Tip2())>
{
    if((mat1.br_redova != mat2.br_redova) || (mat1.br_kolona != mat2.br_kolona)) throw domain_error ("Nedozvoljena operacija");
    GMatrica<Tip1> mat3 (mat1.br_redova,mat1.br_kolona);
    for(int i=0;i<mat1.br_redova;i++)
            for(int j=0;j<mat1.br_kolona;j++)
                mat3.matrica[i][j]=mat1.matrica[i][j]-mat2.matrica[i][j];
    return mat3;
}
template <typename Tip1, typename Tip2>
auto operator *(const GMatrica<Tip1> &mat1, const GMatrica<Tip2> &mat2)->GMatrica<decltype(Tip1()+Tip2())>
{
    if((mat1.br_kolona != mat2.br_redova)) throw domain_error ("Nedozvoljena operacija");
    GMatrica<Tip1> mat3 (mat1.br_redova,mat2.br_kolona);
    for(int i=0;i<mat1.br_redova;i++)
            for(int j=0;j<mat2.br_kolona;j++)
                for(int k=0;k<mat1.br_kolona;k++)
                mat3.matrica[i][j]+=(mat1.matrica[i][k]*mat2.matrica[k][j]);
    return mat3;
}
template <typename Tip1, typename Tip2>
GMatrica<Tip1> operator *(const GMatrica<Tip1> &mat1, Tip2 broj){
    GMatrica<Tip1> mat3 (mat1.br_redova,mat1.br_kolona);
    for(int i=0;i<mat1.br_redova;i++)
            for(int j=0;j<mat1.br_kolona;j++)
                mat3.matrica[i][j]=mat1.matrica[i][j]*broj;
    return mat3;
}
template <typename Tip2, typename Tip1>
GMatrica<Tip1> operator *(Tip2 broj, const GMatrica<Tip1> &mat1){
    GMatrica<Tip1> mat3 (mat1.br_redova,mat1.br_kolona);
    for(int i=0;i<mat1.br_redova;i++)
            for(int j=0;j<mat1.br_kolona;j++)
                mat3.matrica[i][j]=mat1.matrica[i][j]*broj;
    return mat3;
}
template <typename Tip1>
GMatrica<Tip1> GMatrica<Tip1>:: operator +=(const GMatrica<Tip1> &mat2){
if((br_redova != mat2.br_redova) || (br_kolona != mat2.br_kolona)) throw domain_error ("Nedozvoljena operacija");
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
            matrica[i][j]+=mat2.matrica[i][j];
    return *this;
}
template <typename Tip1>
GMatrica<Tip1> GMatrica<Tip1>:: operator -=(const GMatrica<Tip1> &mat2){
    if((br_redova != mat2.br_redova) || (br_kolona != mat2.br_kolona)) throw domain_error ("Nedozvoljena operacija");
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
            matrica[i][j]-=mat2.matrica[i][j];
    return *this;
}
template <typename Tip1>
GMatrica<Tip1> GMatrica<Tip1>:: operator *=(const GMatrica<Tip1> &mat2){
    if((br_kolona != mat2.br_redova)) throw domain_error ("Nedozvoljena operacija");
    GMatrica<Tip1> mat3(br_redova,mat2.br_kolona);
    for(int i=0;i<br_redova;i++)
            for(int j=0;j<mat2.br_kolona;j++){
                for(int k=0;k<br_kolona;k++)
                mat3.matrica[i][j]+=(matrica[i][k]*mat2.matrica[k][j]);
            }
    *this=mat3;
    return *this;
}
template <typename Tip1>
bool operator == (const GMatrica<Tip1> &mat1, const GMatrica<Tip1> &mat2){
    if((mat1.br_redova != mat2.br_redova) || (mat1.br_kolona != mat2.br_kolona)) return false;
    for(int i=0;i<mat1.br_redova;i++){
        bool ima_razlicit(false);
        for(int j=0;j<mat1.br_kolona;j++){
            if(mat1.matrica[i][j]!=mat2.matrica[i][j]) {ima_razlicit=true; break;}
        }
        if(ima_razlicit) return false;
    }
    return true;
}
template <typename Tip1>
bool operator != (const GMatrica<Tip1> &mat1, const GMatrica<Tip1> &mat2){
    return !(mat1==mat2);
}
template<typename Tip1>
std::ostream& operator <<(std::ostream &tok, const GMatrica<Tip1> &mat){
    int sirina(tok.width());
    if(tok.width()<6) sirina=6;
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++)
            tok<<std::setw(sirina)<<mat.matrica[i][j];
            tok<<endl;
    }
    return tok;
}
template<typename Tip1>
std::istream& operator >>(std::istream &tok, GMatrica<Tip1> &mat){
    char znak;
    int brojredova(0),brojclanova(0);
    std::vector<Tip1> v ;
    cout<<"Unesi: ";
    tok>>znak;
    if(tok.peek()!='[') tok.setstate(std::ios::failbit);
    do{
        tok>>znak;
        if(tok.peek()>='0' && tok.peek()<='9') v.push_back(znak);
        else if (tok.peek()==',') {tok>>znak;continue;}
        else if(tok.peek()==';') {tok>>znak;brojredova++;}
        else if(tok.peek()==']') {tok>>znak;break;}
    }while (1);
    for(Tip1 x : v) cout<<x<<" ";
/*    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            tok >> mat.matrica[i][j];
    }
    }*/
    return tok;
}
template <typename Tip>
GMatrica<Tip>::GMatrica(int redovi, int kolone, Tip poc_vrijednost){
        if(redovi <0 || redovi>4 || kolone<0 || kolone>4) throw logic_error ("Ilegalan format matrice");
        br_kolona=kolone;br_redova=redovi;
        for(int i=0;i<redovi;i++)
            for(int j=0;j<kolone;j++)
                matrica[i][j]=poc_vrijednost;
}
template <typename Tip>
template <typename Tip1>
GMatrica<Tip>::GMatrica( GMatrica<Tip1> &m){
    br_kolona=m.DajBrojRedova();br_redova=m.DajBrojKolona();
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
        matrica[i][j]=m[i][j];
}
template<typename Tip>
GMatrica<Tip>::GMatrica (std::vector<std::vector<Tip>> v){
        if(v.size()>4) throw logic_error ("Ilegalan format matrice");
        for(int i=0;i<br_redova;i++)
            if(v[i].size()!=v[0].size()) throw logic_error ("Ilegalan format matrice");
        br_redova=v.size();
        br_kolona=v[0].size();
        for(int i=0;i<br_redova;i++)
            for(int j=0;j<br_kolona;j++)
            matrica[i][j]=v[i][j];
    }
template<typename Tip>
GMatrica<Tip>::GMatrica (Tip niz [4][4]) {
        br_kolona=4;br_redova=4;
        for(int i=0;i<br_redova;i++)
            for(int j=0;j<br_kolona;j++)
            matrica[i][j]=niz[i][j];
    }
template <typename Tip>
Tip& GMatrica<Tip> :: operator () (int red, int kolona) {
    if(red<0 || kolona<0 || red>br_redova || kolona>br_kolona) throw std::range_error ("Nedozvoljen indeks");
    return matrica[red-1][kolona-1];
}
template<typename Tip>
GMatrica<Tip>::GMatrica(std::initializer_list<std::initializer_list<Tip>> lista){
        if(lista.size()>4) throw logic_error ("Ilegalan format matrice");
        for(auto it(lista.begin());it!=lista.end();it++){
            if(it->size()!=lista.begin()->size()) throw logic_error ("Ilegalan format matrice");
        }
        br_redova=lista.size();
        br_kolona=lista.begin()->size();
        int i(0);
        for(auto it(lista.begin());it!=lista.end();it++){
            int j(0);
            for(auto it1(it->begin());it1!=it->end();it1++){
                matrica[i][j]=*it1;
                j++;
            }
            i++;
        }
    }
template <typename Tip>
Tip* GMatrica<Tip> :: operator [] (int index)  {
    return matrica[index];
}
template <typename Tip>
template <typename NoviTip>
GMatrica<Tip> GMatrica<Tip>::operator +=(NoviTip broj){
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++)
        matrica[i][j]+=broj;
    }
    return *this;
}
template <typename Tip>
template < typename NoviTip>
GMatrica<Tip> GMatrica<Tip>::operator -=(NoviTip broj){
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++)
        matrica[i][j]-=broj;
    }
    return *this;
}
template <typename Tip>
template <typename NoviTip>
GMatrica<Tip> GMatrica<Tip>::operator *=(NoviTip broj){
        for(int i=0;i<br_redova;i++){
            for(int j=0;j<br_kolona;j++)
            matrica[i][j]*=broj;
        }
    return *this;
}
int main ()
{
    GMatrica<int> m1;
    cin>>m1;
	return 0;
}