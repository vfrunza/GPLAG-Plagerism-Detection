/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;
Matrica UnesiMatricu(int red, int kolona)
{
    Matrica mat(red, std::vector<double>(kolona));
    for(int i=0; i<red; i++)
        for(int j=0; j<kolona; j++)
            std::cin>>mat[i][j];
    return mat;
}
Matrica h(Matrica mat)
{
    Matrica m(mat.size(), std::vector<double>(mat[0].size()));
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat[i].size(); j++)
            m[i][j]=mat[i][mat[i].size()-1-j];
    return m;
}
Matrica v(Matrica mat)
{
    Matrica m(mat.size(), std::vector<double>(mat[0].size()));
    for(int i=0; i<mat.size(); i++)
        m[i]=mat[mat.size()-1-i];
    return m;
}
Matrica OgledaloMatrica(Matrica mat)
{
    for(int i=1; i<mat.size(); i++)
        if(mat[0].size()!=mat[i].size())  throw std::domain_error("Matrica nije korektna");
    
    
    Matrica ogledalo;
    for(int i=0; i<mat.size(); i++)
    {
        std::vector<double> temp;
        for(int j=0; j<mat[i].size(); j++)
            temp.push_back(h(v(mat))[i][j]);
        for(int j=0; j<mat[i].size(); j++)
            temp.push_back(v(mat)[i][j]);
        for(int j=0; j<mat[i].size(); j++)
            temp.push_back(h(v(mat))[i][j]);
        ogledalo.push_back(temp);
    }
    for(int i=0; i<mat.size(); i++)
    {
        std::vector<double> temp;
        for(int j=0; j<mat[i].size(); j++)
            temp.push_back(h(mat)[i][j]);
        for(int j=0; j<mat[i].size(); j++)
            temp.push_back(mat[i][j]);
        for(int j=0; j<mat[i].size(); j++)
            temp.push_back(h(mat)[i][j]);
        ogledalo.push_back(temp);
    }
    for(int i=0; i<mat.size(); i++)
    {
        std::vector<double> temp;
        for(int j=0; j<mat[i].size(); j++)
            temp.push_back(h(v(mat))[i][j]);
        for(int j=0; j<mat[i].size(); j++)
            temp.push_back(v(mat)[i][j]);
        for(int j=0; j<mat[i].size(); j++)
            temp.push_back(h(v(mat))[i][j]);
        ogledalo.push_back(temp);
    }
    
    return ogledalo;
    
}
int main ()
{
    int m, n;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>m>>n;
    if(m<0 || n<0)
    {
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    std::cout<<"Unesite elemente matrice: "<<std::endl;
    Matrica mat((UnesiMatricu(m, n)));
    try
    {
        std::cout<<"Rezultantna matrica: "<<std::endl;
    
        for(int i=0; i<OgledaloMatrica(mat).size(); i++)
        {
            for(int j=0; j<OgledaloMatrica(mat)[i].size(); j++)
                std::cout<<std::setw(4)<<OgledaloMatrica(mat)[i][j];
            std::cout<<std::endl;
        }
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<izuzetak.what();
    }
    return 0;
}