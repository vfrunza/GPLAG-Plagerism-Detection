/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <initializer_list>
using namespace std;

template<typename t>
class GMatrica
{
    t mat[4][4];
    int r,k;
public:
    GMatrica() { mat[0][0]=0; r(0); k(0);}
    GMatrica(int red, int kolona, t v=0);
    GMatrica(GMatrica &m);
    GMatrica(const vector<vector<t>> &v);
    GMatrica(const initializer_list<initializer_list<t>> &l);
};

template<typename t1>
GMatrica<t1>::GMatrica(int red, int kolona, t1 v)
{
    if(red<0 || red>4 || kolona<0 || red>4) throw logic_error("Ilegalan format matrice");
    r=red; k=kolona;
    for(int i=0; i<red; i++)
        for(int j=0; j<kolona; j++) mat[i][j]=v;
}
template<typename t1>
GMatrica<t1>::GMatrica(GMatrica &m)
{
    k=m.k;
    r=m.r;
    for(int i=0; i<r; i++)
        for(int j=0; j<k; j++) mat[i][j]=m.mat[i][j];
}
template<typename t1>
GMatrica<t1>::GMatrica(const vector<vector<t1>> &v)
{
    r=v.size(); k=v[0].size();
    for(int i=0; i<r; i++)
        for(int j=0; j<k; j++) mat[i][j]=v[i][j];
}
template<typename t1>
GMatrica<t1>::GMatrica(const initializer_list<initializer_list<t1>> &l)
{
    r=l.size();
    k=l.begin()->size();
    int i=0, j=0;
    auto it=l.begin();
    for(auto x=l.begin(); x!=l.end(); x++)
    {
        j=0;
        for(auto y=x->begin(); y!=x->end(); y++)
        {
            mat[i][j]=*y; j++;
        }
        i++;
    }
}

int main ()
{
	return 0;
}