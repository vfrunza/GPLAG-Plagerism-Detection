#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cmath>
#include <limits>


bool JesuLiJednaki(double x, double y, double Eps=1e-10)
{
    return std::fabs(x-y)<=Eps * (std::fabs(x) + std::fabs(y));
}

std::vector<std::vector<double>> Planina(int i, int j, std::vector<std::vector<double>>mat)
{
    int sirina(1);
    double sumaprethodnog(mat.at(i).at(j)), suma(0), sumareda(0);
    std::vector<std::vector<double>>nova;
    while(true)
    {

        if(i-sirina<0 || i+sirina>=mat.size() || j-sirina<0 || j+sirina>=mat.at(i).size())
        {
            return nova;
        }
        else
        {
            double sumasvih(0);
            for(int k=i-sirina;k<=i+sirina;k++){
                for(int l=j-sirina;l<=j+sirina;l++){
                    sumasvih+=mat.at(k).at(l);
                    
                }
            }
            sumareda=sumasvih-sumaprethodnog-suma;
            if(sumareda>sumaprethodnog && !JesuLiJednaki(sumareda,sumaprethodnog))return nova;
            if(sumaprethodnog>sumareda && !JesuLiJednaki(sumaprethodnog,sumareda))
            {
                int i1(i);
                int j1(j);
                i1-=sirina;
                j1-=sirina;
                nova.resize((2*sirina)+1);
                for(int a(0);a<nova.size();a++)
                {
                    nova.at(a).resize((2*sirina)+1);
                }
                
                for(int a(0);a<nova.size();a++)
                {
                    for(int e(0);e<nova.at(a).size();e++)
                    {
                        nova.at(a).at(e)=mat.at(i1).at(j1);
                        j1++;
                    }
                    j1=j-sirina;
                    if(i1!=mat.size()-1)i1++;
                    
                }
                
            }
            
        }
        suma+=sumaprethodnog;
        sumaprethodnog=sumareda;
        sirina++;
        
    }
}

std::vector<std::vector<double>>NajvecaPlaninaMatrice(std::vector<std::vector<double>>mat)
{
    std::vector<std::vector<double>>najveca;
    if(mat.size()==0)return najveca;
    for(int i(0);i<mat.size();i++)
    {
        if(mat.at(i).size()!=mat.at(0).size())throw std::domain_error("Matrica nije korektna");
    }
    
    if(mat.at(0).size()==0)return najveca;
    if(mat.size()<3 || mat.at(0).size()<3)
    {
        double max(std::numeric_limits<double>::lowest());
        for(int i(0);i<mat.size();i++)
        {
            for(int j(0);j<mat.at(i).size();j++)
            {
                if(mat.at(i).at(j)>max && !JesuLiJednaki(mat.at(i).at(j),max))max=mat.at(i).at(j);
            }
        }
        najveca.resize(1);
        najveca.at(0).resize(1);
        najveca.at(0).at(0)=max;
        return najveca;
    }
    int nii(0),nij(0);
    double vrh(0);
    for(int i(1);i<mat.size()-1;i++)
    {
        for(int j(1);j<mat.at(i).size()-1;j++)
        {
            std::vector<std::vector<double>>E;
            E=Planina(i,j,mat);
            if(E.size()>najveca.size())
            {
                najveca=E;
                nii=i;
                nij=j;
                vrh=mat.at(i).at(j);
            }
            else if(E.size()==najveca.size())
            {
                if(mat.at(i).at(j)>vrh && !JesuLiJednaki(mat.at(i).at(j),vrh))
                {
                    najveca=E;
                    vrh=mat.at(i).at(j);
                    nii=i;
                    nij=j;
                }
                else if(JesuLiJednaki(mat.at(i).at(j),vrh))
                {
                    if(i<nii)
                    {
                        najveca=E;
                        nii=i;
                        nij=j;
                    }
                    else if(i==nii){
                        if(j<nij)
                        {
                            najveca=E;
                            nij=j;
                            nii=i;
                        }
                    }
                }
            }
        }
    }


    if(najveca.size()==0)
    {
        double max1(std::numeric_limits<double>::lowest());
        for(int i(0);i<mat.size();i++)
        {
            for(int j(0);j<mat.at(i).size();j++)
            {
                if(mat.at(i).at(j)>max1 && !JesuLiJednaki(mat.at(i).at(j),max1))max1=mat.at(i).at(j);
            }
        }
        najveca.resize(1);
        najveca.at(0).resize(1);
        najveca.at(0).at(0)=max1;
        return najveca;
    }
    return najveca;
}

int main()
{
    try
    {
    std::cout<<"Unesite dimenzije matrice (m i n): ";
    int m,n;
    std::cin>>m>>n;
    if(m<0 || n<0)
    {
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    std::cout<<"Unesite elemente matrice:";
    std::vector<std::vector<double>> mat;
    mat.resize(m);
    for(int i(0);i<m;i++)
    {
        for(int j(0);j<n;j++)
        {
            double broj;
            std::cin>>broj;
            mat.at(i).push_back(broj);
            
        }
    }
   std::vector<std::vector<double>>Mat(NajvecaPlaninaMatrice(mat));
   std::cout<<std::endl;
   std::cout<<"Najveca planina unesene matrice je:";
   std::cout<<std::endl;
    for(int i(0);i<Mat.size();i++)
    {
        for(int j(0);j<Mat.at(i).size();j++)
        {
            std::cout<<std::setw(6)<<std::setprecision(12)<<Mat.at(i).at(j);
        }
        std::cout<<std::endl;
    
    }
    }
    catch(std::domain_error Izuzetak)
    {
        std::cout<<Izuzetak.what();
    }
    return 0;
}