#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>


template <typename tip>
class GMatrica
{
    tip matrix [4][4];
    int a,b;
    public:
   
    GMatrica ();
    GMatrica (int a, int b, tip c=tip());
    
    template <typename tip1>
    GMatrica(const GMatrica<tip1> & matrixp);
    
    template <typename tip2>
    GMatrica (tip2 mat[4][4]);
    GMatrica (std::vector<std::vector<tip>> vek);
    GMatrica (std::initializer_list<tip> lista);
};


template <typename tip>
GMatrica::GMatrica (std::vector<std::vector<tip>> vek)
    {
        if (vek.size()>4 || vek[0].size()>4)
        {
            throw std::logic_error ("Ilegalan format matrice");
        }
        
        for (int i=0; i<vek.size(); i++)
        {
            for (int j=0; j<vek[0].size(); j++)
            {
                matrix[i][j]=vek[i][j];
            }
        }
        
    }
    
    
    
    GMatrica (std::initializer_list<tip> lista)
    {
        if (lista.size()>16)
        {
            throw std::logic_error ("Ilegalan format matrice");
        }
        
        for (int i=0; i<lista.size();i++)
        {
            int j=0;
            matrix[i][j]=lista[i];
            j++;
        }
        
    }

GMatrica ():
a(0),b(0)
{
   
}

GMatrica (int a, int b, tip c=tip())
{
    if (a>4 || a<0 || b>4 || b<0)
    {
        throw std::logic_error ("Ilegalan format matrice");
    }
    for (int i=0; i<a; i++)
    {
        for (int j=0; j<b; j++)
        {
            matrix[i][j]=c;
        }
    }
}


template <typename tip1>
GMatrica(const GMatrica<tip1> & matrixp):
a(matrixp.a),b(matrixp.b)
{
    
    for (int i=0; i<a; i++)
    {
        for (int j=0; j<b; j++)
        {
            matrix[i][j]=matrixp[i][j];
        }
    }
}


template <typename tip2>
GMatrica (tip2 mat[4][4]):
a(4),b(4)
{
    for (int i=0; i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            matrix[i][j]=mat[i][j];
        }
    }
}


int main ()
{
    return 0;
}