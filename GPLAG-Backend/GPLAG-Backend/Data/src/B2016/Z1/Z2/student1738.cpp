//1 od 10 testova nije prošlo
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> matrica;
typedef std::vector<double> vektor;

bool DaLiJeGrbava (matrica m)
{
    if (m.size()==0) return 0;
    for (int i=0;i<int(m.size());i++)
    {
        for (int j=0;j<int(m.size());j++)
        {
           if (int(m[i].size())!=int(m[j].size())) return 1;
        }
    }
    return 0;
}



matrica HorizontalnoOgledalo (matrica m)
{
    matrica m1(m.size());
    for (int i=int(m.size()-1);i>=0;i--)
    {
        for (int j=int(m[0].size()-1);j>=0;j--)
        {
            m1[i].push_back(m[i][j]);
        }
    }
    return m1;
}

matrica VertikalnoOgledalo(matrica m)
{
    matrica m1(m.size());
    int k(0),l(0);
    for (int i=int(m.size()-1);i>=0;i--)
    {
        for (int j=0;j<int(m[0].size());j++)
        {
           
             m1[k].push_back(m[i][j]);
        }
        k++;l++;
    }
    return m1;
}

matrica KombinovanoOgledalo (matrica m)
{
    matrica m1(VertikalnoOgledalo(m));
    m1=HorizontalnoOgledalo(m1);
    return m1;
    
}

matrica OgledaloMatrica (matrica m)
{
    if (DaLiJeGrbava(m)) throw std::domain_error ("Matrica nije korektna!");
    
    if (m.size()==0) 
    {
        return matrica {};
    }
    matrica m1(3*m.size(),vektor(3*m[0].size()));
    matrica hm(HorizontalnoOgledalo(m)),vm(VertikalnoOgledalo(m)),hvm(KombinovanoOgledalo(m));
    for (int i=0;i<int(m.size());i++)
    {
        for (int j=0;j<int(m[0].size());j++)
        {
            m1[i][j]=hvm[i][j];
        }
    }
    
    for (int i=0;i<int(m.size());i++)
    {
        int pj(0);
        for (int j=int(m[0].size());j<(2*int(m[0].size()));j++)
        {
            m1[i][j]=vm[i][pj];
            pj++;
        }
    }
    
    for (int i=0;i<int(m.size());i++)
    {
        int pj(0);
        for (int j=int(2*m[0].size());j<int(3*m[0].size());j++)
        {
            m1[i][j]=hvm[i][pj];
            pj++;
        }
    }
    
    int pi(0);
    for (int i=int(m.size());i<int(2*m.size());i++)
    {
        for (int j=0;j<int(m[0].size());j++)
        {
            m1[i][j]=hm[pi][j];
        }
        pi++;
        
    }
    pi=0;
    for (int i=int(m.size());i<int(2*m.size());i++)
    {
        int pj(0);
        for (int j=int(m[0].size());j<int(2*m[0].size());j++)
        {
            m1[i][j]=m[pi][pj];
            pj++;
        }
        pi++;
    }
    pi=0;
    for (int i=int(m.size());i<int(2*m.size());i++)
    {
        int pj(0);
        for (int j=int(2*m[0].size());j<int(3*m[0].size());j++)
        {
            m1[i][j]=hm[pi][pj];
            pj++;
        }
        pi++;
    }
    pi=0;
    for (int i=int(2*m.size());i<int(3*m.size());i++)
    {
        for (int j=0;j<int(m[0].size());j++)
        {
            m1[i][j]=hvm[pi][j];
        }
        pi++;
    }
    pi=0;
    for (int i=int(2*m.size());i<int(3*m.size());i++)
    {
        int pj(0);
        for (int j=int(m[0].size());j<int(2*m[0].size());j++)
        {
            m1[i][j]=vm[pi][pj];
            pj++;
        }
        pi++;
    }
    pi=0;
    for (int i=int(2*m.size());i<int(3*m.size());i++)
    {
        int pj(0);
        for (int j=int(2*m[0].size());j<int(3*m[0].size());j++)
        {
            m1[i][j]=hvm[pi][pj];
            pj++;
        }
        pi++;
    }
    return m1;
}

int main ()
{
    try 
    {
        std::cout << "Unesite dimenzije matrice (m n): ";
        int m,n;
        std::cin>>m>>n;
        if (!(std::cin)) return 0;
        if (m<0 || n<0) 
        {
            std::cout << "Dimenzije matrice moraju biti nenegativne!";
            return 0;
        }
        std::cout << "Unesite elemente matrice: ";
        matrica mat(m,vektor(n));
        
        for (int i=0;i<m;i++)
        {
            int br;
            for (int j=0;j<n;j++)
            {
                std::cin>>br;
                mat[i][j]=br;
            }
        }
        
        std::cout << std::endl<< "Rezultantna matrica: ";
        mat=OgledaloMatrica(mat);
        if (mat.size()==0 ) return 0;
        for (vektor x:mat)
        {
            std::cout << std::endl;
            for (double y:x)
            {
                std::cout << std::setw(4)<<y;
            }
        }
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<< izuzetak.what()<<std::endl;
    }
    return 0;
}