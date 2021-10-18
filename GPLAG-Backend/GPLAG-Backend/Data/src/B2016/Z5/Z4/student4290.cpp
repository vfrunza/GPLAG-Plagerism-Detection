#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>
template <typename TipEl>
class GMatrica{
    TipEl mat[4][4];
    int br_redova,br_kolona;
    public:
        GMatrica(){br_redova=br_kolona=0;}
        GMatrica(int brr,int brk,TipEl p=TipEl()){if(brr<0 || brk<0 || brr>4 || brk>4)throw std::logic_error("Ilegalan format matrice");br_redova=brr;br_kolona=brk;}
        template <typename Tip2>
            GMatrica(const GMatrica<Tip2> &m);
        GMatrica(TipEl (*m)[4],int n=4);
        GMatrica(std::vector<std::vector<TipEl>> v);
        GMatrica(std::initializer_list<std::initializer_list<TipEl>> l);
        int DajBrojRedova()const {return br_redova;}
        int DajBrojKolona()const {return br_kolona;}
        template <typename Tip2>
        friend GMatrica<decltype(Tip2()+TipEl())> operator+(const GMatrica<TipEl> &a,const GMatrica<Tip2> &b){
        
};
template <typename TipEl>
template <typename Tip2>
    GMatrica<TipEl>::GMatrica(const GMatrica<Tip2> &m){
        br_redova=m.br_redova;
        br_kolona=m.br_kolona;
        for(int i=0;i<br_redova;i++){
            for(int j=0;j<br_kolona;j++){
                mat[i][j]=m.mat[i][j];
            }
        }
    }
template <typename TipEl>
GMatrica<TipEl>::GMatrica(TipEl (*m)[4],int n){
    br_redova=4;
    br_kolona=4;
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++){
            mat[i][j]=m[i][j];
        }
    }
}
template <typename TipEl>
GMatrica<TipEl>::GMatrica(std::vector<std::vector<TipEl>> v){
    if(v.size()<0 || v.size()>4 || v[0].size()<0 || v[0].size()>4)throw std::logic_error("Ilegalan format matrice");
    for(int i=1;i<v.size();i++)if(v[i].size()!=v[0].size())throw std::logic_error("Ilegalan format matrice");
    br_redova=v.size();
    br_kolona=v[0].size();
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++)mat[i][j]=v[i][j];
    }
}
template <typename TipEl>
GMatrica<TipEl>::GMatrica(std::initializer_list<std::initializer_list<TipEl>> l){
    if(l.size()<0 || l.size()>4 || l.begin()->size()<0 || l.begin()->size()>4)throw std::logic_error("Ilegalan format matrice");
    for(auto i=l.begin();i!=l.end();i++)if(i->size()!=l.begin()->size())throw std::logic_error("Ilegalan format matrice");
    br_redova=l.size();
    br_kolona=l.begin()->size();
    int p(0),q(0);
    for(auto i=l.begin();i!=l.end;i++){
        for(auto j=i->begin();j!=i->end;j++){
            mat[p][q]=*j;
            q++;
        }
        p++;
    }
}
template <typename TipEl,typename Tip2>
GMatrica<decltype(TipEl()+Tip2())> operator+(const GMatrica<TipEl> &a,const GMatrica<Tip2> &b){
    if(a.DajBrojRedova()!=b.DajBrojRedova() || a.DajBrojKolona()!=b.DajBrojKolona())throw std::domain_error("Nedozvoljena operacija");
    GMatrica<decltype(TipEl()+Tip2())> mat(a.DajBrojRedova(),a.DajBrojKolona());
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;i++)mat.mat[i][j]=a.mat[i][j]+b.mat[i][j];
    }
    return mat;
}
int main ()
{
	return 0;
}