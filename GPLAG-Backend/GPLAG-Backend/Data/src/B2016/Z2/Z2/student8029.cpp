// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque> 
#include <stdexcept>
#include <iomanip>
enum class SmjerKretanja{
NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo };
 
template <typename nekitip>
auto IzdvojiDijagonale3D(nekitip m,SmjerKretanja smijer)-> typename std::remove_reference<decltype (m[0])>::type
{
    bool izuzetak=false;
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<m[i].size();j++)
        {
            if(m[i][j].size()!=m[i][0].size())
            izuzetak=true;
        }
    }
    
    
    if(izuzetak==true)
    {
        throw std::domain_error("Redovi nemaju isti broj elemenata");
    }
    izuzetak=false;
    for(int i=0;i<m.size();i++)
    {
        if(m[i].size()!=m[0].size())
        izuzetak=true;
    }
    if(izuzetak==true)
    {
        throw std::domain_error("Plohe nemaju isti broj redova");
    }
    typename std::remove_reference<decltype (m[0])>::type vrati;
    if(smijer==SmjerKretanja(0))
    {
        for(int i=0;i<m.size();i++)
        {
            vrati.resize(i+1);
            
            for(int j=0;j<m[0].size();j++)
            {
                for(int k=0;k<m[0][0].size();k++)
                {
                    if(j==k)
                    {
                        vrati[i].push_back(m[i][j][k]);
                    }
                }
            }
        }
 
    }
    
    if(smijer==SmjerKretanja(1))
    {
        int l=0;
        for(int i=m.size()-1;i>=0;i--)
        {
                vrati.resize(l+1);
            for(int j=0;j<m[0].size();j++)
            {
                for(int k=0;k<m[0][0].size();k++)
                {
                    if(j+k==m[0][0].size()-1)
                    vrati[l].push_back(m[i][j][k]);
                }
            }
            l++;
        }
    }
    if(smijer==SmjerKretanja(2))
    {
        vrati.resize(m[0].size());
        for(int i=0;i<m[0].size();i++)
        vrati[i].resize(m.size());
        int j=0;
        for(int i=m.size()-1;i>=0;i--)
        {
            for(int k=0;k<m[0].size();k++)
            {
                vrati[k][j]=m[i][k][j];
            }
            j++;
        }
            
        return vrati;
            
     }
     
     if(smijer==SmjerKretanja(3))
     {
         vrati.resize(m[0].size());
         for(int i=0;i<m[0].size();i++)
         vrati[i].resize(m.size());
         
         for(int i=0;i<vrati.size();i++)
         {
             for(int j=0;j<vrati[i].size();j++)
             {
                 vrati[i][j]=m[m.size()-1-j][m[0].size()-1-i][m[0][0].size()-1-j];
             }
       
         }
         return vrati;
     }
        
    if(smijer==SmjerKretanja(4))
    {
    
        vrati.resize(m[0][0].size());
        for(int i=0;i<m[0][0].size();i++)
        vrati[i].resize(m.size());
        int l=0;
        
        for(int i=m.size()-1;i>=0;i--)
        {
          
          for(int j=0;j<m[0][0].size();j++)
          {
              vrati[j][l]=m[i][l][j];
          }
          l++;
        }
        return vrati;

    }
    if(smijer==SmjerKretanja(5))
    {
         vrati.resize(m[0][0].size());
         for(int i=0;i<m[0][0].size();i++)
         vrati[i].resize(m.size());
         int l=0;
         
        for(int i=0;i<m.size();i++)
        {   l=i;
            int p=0;
            for(int j=m[0][0].size()-1;j>=0;j--)
            {   
               vrati[p][i]=m[i][l][j];
                p++;
            }
        }
        return vrati;
    }

    return vrati;
 
}

void ispis(int n)
{
    if(n==0)
    std::cout<<"NaprijedNazad: ";
    if(n==1)
    std::cout<<"NazadNaprijed: ";
    if(n==2)
    std::cout<<"GoreDolje: ";
    if(n==3)
    std::cout<<"DoljeGore: ";
    if(n==4)
    std::cout<<"LijevoDesno: ";
    if(n==5)
    std::cout<<"DesnoLijevo: ";
}

int main ()
{
    std::cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    std::cin>>x;
    std::cin>>y;
    std::cin>>z;
    if(x<=0 || y<=0 || z<=0)
    {
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::cout<<"Unesite elemente kontejnera: ";
    std::vector<std::deque<std::deque<int>>> ulaz;
    ulaz.resize(x);
    for(int i=0;i<x;i++)
    {
        ulaz[i].resize(y);
    }
    for(int i=0;i<x;i++)
      for(int j=0;j<y;j++)
         ulaz[i][j].resize(z);
         
    for(int i=0;i<x;i++)
     for(int j=0;j<y;j++)
      for(int k=0;k<z;k++)
      {
           int temp;
           std::cin>>temp;
           ulaz[i][j][k]=temp;
      }
   
    std::cout<<"\nUnesite smjer kretanja [0 - 5]: ";
    int temp;
    std::cin>>temp;
    
    if(temp<0 || temp>5)
    {
        std::cout<<"Smjer kretanja nije ispravan!";
    }
    
    ispis(temp);
    SmjerKretanja smijer=SmjerKretanja(temp);
    try{
        
        auto ispis=IzdvojiDijagonale3D(ulaz,smijer);
        std::cout<<"\n";
        for(int i=0;i<ispis.size();i++)
        {
            for(int j=0;j<ispis[i].size();j++)
            std::cout<<std::setw(4)<<ispis[i][j];
            std::cout<<"\n";
        }
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    
    
    
    return 0;
}