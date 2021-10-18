#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> matrica)
{   if(matrica.size()==0) return matrica;
    std::vector<std::vector<double>> ogledalo(3*matrica.size(),std::vector<double>(3*matrica[0].size()));
    int br_redova=matrica.size(), br_kolona=matrica[0].size();
    std::vector<std::vector<double>> h(br_redova,std::vector<double>(br_kolona));
    std::vector<std::vector<double>> v(h);
    std::vector<std::vector<double>> hv(h);
    for(int i=0;i<br_redova-1;i++)
    {
        if(matrica[i].size()!=matrica[i+1].size()) throw std::domain_error("Matrica nije korektna");
    }
    for(int i=0;i<br_redova;i++)
    {
         int j1=0, j2=br_kolona-1;
         while(j2>=0)
         {
             h[i][j1]=matrica[i][j2];
             j1++; j2--;
             
         }
    }
    int i2=0;
    for(int i=br_redova-1;i>=0;i--)
    {
        for(int j=0;j<br_kolona;j++)
        {
            v[i2][j]=matrica[i][j];
        }
        i2++;
    }
    i2=0;
    for(int i=br_redova-1;i>=0;i--)
    {
        int j1=0, j2=br_kolona-1;
        while(j2>=0)
        {
            hv[i2][j1]=matrica[i][j2];
            j1++; j2--;
        }
        i2++;
    }
    
    int i3=0,j3=0;
    for(int i=0;i<br_redova;i++)
    {
         j3=0;
        for(int j=0;j<br_kolona;j++)
        {
            ogledalo[i][j]=hv[i3][j3];
            j3++;
        }
        j3=0;
        
        for(int j=br_kolona;j<2*br_kolona;j++)
        {
            ogledalo[i][j]=v[i3][j3];
            j3++;
        }
        j3=0;
        
        for(int j=2*br_kolona;j<3*br_kolona;j++)
        {
            ogledalo[i][j]=hv[i3][j3];
            j3++;
        }
        j3=0;
        i3++;
    }
    
    i3=0;

    for(int i=br_redova;i<2*br_redova;i++)
    {   j3=0;
        for(int j=0;j<br_kolona;j++)
        {
            ogledalo[i][j]=h[i3][j3];
            j3++;
        }
        j3=0;
        for(int j=br_kolona;j<2*br_kolona;j++)
         {
             ogledalo[i][j]=matrica[i3][j3];
             j3++;
         }
         j3=0;
         for(int j=2*br_kolona;j<3*br_kolona;j++)
        {
            ogledalo[i][j]=h[i3][j3];
            j3++;
        }
        i3++;
    }
    i3=0;
    
    
    for(int i=2*br_redova;i<3*br_redova;i++)
    {
        j3=0;
        for(int j=0;j<br_kolona;j++)
        {
            ogledalo[i][j]=hv[i3][j3];
            j3++;
        }
        j3=0;
        for(int j=br_kolona;j<2*br_kolona;j++)
        {
            ogledalo[i][j]=v[i3][j3];
            j3++;
        }
        j3=0;
        for(int j=2*br_kolona;j<3*br_kolona;j++)
        {
            ogledalo[i][j]=hv[i3][j3];
            j3++;
        }
        i3++;
    }
    i3=0;
    
    return ogledalo;
}



int main ()
{   
    std::cout<<"Unesite dimenzije matrice (m n): ";
    int m,n;
    std::cin>>m>>n;
    if(m<0 || n<0)
    {
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    
    std::vector<std::vector<double>> matrica(m,std::vector<double>(n));
    std::cout<<"Unesite elemente matrice: ";
    if(m!=0 && n!=0) {
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cin>>matrica[i][j];
        }
    }
    }
    std::cout<<std::endl;
    std::vector<std::vector<double>> h=OgledaloMatrica(matrica);
    std::cout<<"Rezultantna matrica: "<<std::endl;
    for(std::vector<double> red: h)
    {
        for(double x: red) std::cout<<std::setw(4)<<x;
        std::cout<<std::endl;
    }
    
	return 0;
}