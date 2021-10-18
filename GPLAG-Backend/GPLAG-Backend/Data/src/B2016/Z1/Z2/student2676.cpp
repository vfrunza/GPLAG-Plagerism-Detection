#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using std::cin;
using std::cout;
using std::vector;

typedef vector<vector<double>> Matrica;

Matrica Kmat(int a, int b)
{
    return Matrica(a, vector<double>(b));
}

Matrica OgledaloMatrica(Matrica s)
{
    if(s.size()==0)
    {
        Matrica og;
        return og;
    }
    bool grbava=false;
    for(int i=1;i<s.size();i++)
    {
        if(s[i].size()!=s[0].size()) grbava=true;
    }
    if(grbava) throw std::domain_error("Matrica nije korektna");
    if(s[0].size()==0)
    {
        Matrica og=Kmat(s.size()*3, 0);
        return og;
    }
    Matrica og=Kmat(s.size()*3, s[0].size()*3);
    
    // Prva trecina redova matrice :
    
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s[0].size();j++)
        {
            og[i][j]=s[s.size()-1-i][s[0].size()-1-j];
        }
        for(int j=s[0].size();j<s[0].size()*2;j++)
        {
            og[i][j]=s[s.size()-1-i][j-s[0].size()];
        }
        for(int j=s[0].size()*2;j<s[0].size()*3;j++)
        {
            og[i][j]=s[s.size()-1-i][s[0].size()*3-1-j];
        }
    }
    
    // Druga trecina redova matrice :
    
    for(int i=s.size();i<s.size()*2;i++)
    {
        for(int j=0;j<s[0].size();j++)
        {
            og[i][j]=s[i-s.size()][s[0].size()-1-j];
        }
        for(int j=s[0].size();j<s[0].size()*2;j++)
        {
            og[i][j]=s[i-s.size()][j-s[0].size()];
        }
        for(int j=s[0].size()*2;j<s[0].size()*3;j++)
        {
            og[i][j]=s[i-s.size()][s[0].size()*3-1-j];
        }
    }
    
    // Treca trecina redova matrice :
    
    for(int i=s.size()*2;i<s.size()*3;i++)
    {
        for(int j=0;j<s[0].size();j++)
        {
            og[i][j]=s[3*s.size()-1-i][s[0].size()-1-j];
        }
        for(int j=s[0].size();j<s[0].size()*2;j++)
        {
            og[i][j]=s[3*s.size()-1-i][j-s[0].size()];
        }
        for(int j=s[0].size()*2;j<s[0].size()*3;j++)
        {
            og[i][j]=s[3*s.size()-1-i][s[0].size()*3-1-j];
        }
    }
    
    return og;
}

int main ()
{
    int m, n;
    cout << "Unesite dimenzije matrice (m n): ";
    cin >> m >> n;
    if(m<0 || n<0)
    {
        cout << "Dimenzije matrice moraju biti nenegativne!\n";
        return 0;
    }
    Matrica a=Kmat(m, n);
    cout << "Unesite elemente matrice: ";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "\nRezultantna matrica:\n";
    try
    {
        Matrica c=OgledaloMatrica(a);
        for(int i=0;i<c.size();i++)
        {
            for(int j=0;j<c[0].size();j++)
            {
                cout.width(4);
                cout << c[i][j];
            }
            cout << "\n";
        }
    }
    catch(std::domain_error ero)
    {
        cout << ero.what() << "\n";
    }
	return 0;
}