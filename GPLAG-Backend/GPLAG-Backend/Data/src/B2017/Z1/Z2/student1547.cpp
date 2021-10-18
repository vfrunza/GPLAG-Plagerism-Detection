#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica NajvecaPlaninaMatrice(const Matrica m)
{
    Matrica M(0);
    if(m.size()>1)
    {
        int prethodni=m.at(0).size();
        for (auto v : m)
        {
            int br_kolona=v.size();
            if(br_kolona!=prethodni) throw std::domain_error("Matrica nije korektna");
        }
    }
    if(m.size()==0 || m.at(0).size()==0) return M;
    double max(m.at(0).at(0));
    int xmax(0),ymax(0),kmax(0);
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<m.at(i).size();j++)
        {
            double broj=m.at(i).at(j);
            if(broj>max && kmax==0)
            {
                max=broj;
                xmax=i;
                ymax=j;
            }
           
            if(i==0 || i==m.size()-1 || j==0 || j==m.at(i).size()-1) continue; //rubovi vec rijeseni iznad
                
                
            int k(1);
            double prethodna(broj);
            while(1)
            {
                
                double suma(0);
                for(int l=i-k;l<=i+k;l++)
                {
                    for(int n=j-k;n<=j+k;n++)
                    {
                        if(l==i-k) suma+=m.at(l).at(n);
                        else if(l==i+k) suma+=m.at(l).at(n);
                        else if(n==j-k) suma+=m.at(l).at(n);
                        else if(n==j+k) suma+=m.at(l).at(n);
                    }
                }
                if(k>kmax)
                {
                    if(suma<prethodna)
                    {
                        kmax=k;
                        xmax=i;
                        ymax=j;
                        max=broj;
                    }
                    else break;
                }
                else if(k==kmax)
                {
                    
                        
                    if(broj>max && suma<prethodna)
                    {
                        kmax=k;
                        xmax=i;
                        ymax=j;
                        max=broj;
                    }
                    else if(suma>prethodna) break;
                }
                else
                {
                    if(suma>prethodna) break;
                }
                k++;
                if(i-k<0 || j-k<0 || i+k>=m.size() || j+k>=m.at(i).size()) break;
                prethodna=suma;
            }
        }
    }
    M.resize(2*kmax+1);
    int o(0),p(0);
    //std::cout<<std::endl<<"k: "<<max<<", y: "<<ymax<<", x: "<<xmax<<", clan: "<<m.at(xmax).at(ymax)<<std::endl;
    for(int i=xmax-kmax;i<=xmax+kmax;i++)
    {
        M.at(o).resize(2*kmax+1);
        for(int j=ymax-kmax;j<=ymax+kmax;j++)
        {
            M.at(o).at(p++)=m.at(i).at(j);
        }
        p=0;
        o++;
    }
    return M;
}

int main ()
{
    try
    {
        std::cout<<"Unesite dimenzije matrice (m i n): ";
        int m;
        std::cin>>m;
        int n;
        std::cin>>n;
        if(m<0 || n<0)
        {
            std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        }
        else
        {   
            std::cout<<"Unesite elemente matrice: "<<std::endl;
            Matrica mat;
            for(int i=0;i<m;i++)
            {
                mat.push_back(std::vector<double>());
                for(int j=0;j<n;j++)
                {
                    double unos;
                    std::cin>>unos;
                    mat.at(i).push_back(unos);
                }
            }
            Matrica p=NajvecaPlaninaMatrice(mat);
            std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
            
            for(auto v : p)
            {
                for(auto x : v)
                {
                    std::cout<<" "<<std::setw(5)<<x;
                }
                std::cout<<std::endl;
            }
        }
        
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<"IZUZETAK: "<<izuzetak.what();
    }
	return 0;
}