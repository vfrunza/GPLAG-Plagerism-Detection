// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include<iostream>
#include<deque>
#include<vector>
#include<iomanip>
#include<stdexcept>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename kont1>

auto IzdvojiDijagonale3D(kont1 kont,SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type
{
    for(int i(0);i<kont.size();i++)
    {
        for(int j(0);j<kont.at(0).size();j++)
        if(kont.at(0).at(0).size()!=kont.at(i).at(j).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
    }
    for(int i(0);i<kont.size();i++)
    {
        if(kont.at(0).size()!=kont.at(i).size()) throw std::domain_error("Plohe nemaju isti broj redova");
    }
    
    typename std::remove_reference<decltype(kont.at(0))>::type mat;
    typedef typename std::remove_reference<decltype(kont.at(0).at(0))>::type Tipkont;
    
    if(smjer==SmjerKretanja::NaprijedNazad)
    {
        for(int i(0);i<kont.size();i++)
        {
            mat.push_back(Tipkont());
            for(int j(0);j<kont.at(0).size();j++)
            {
                for(int k(0);k<kont.at(0).at(0).size();k++)
                {
                    if(j==k) mat.at(i).push_back(kont.at(i).at(j).at(k));
                }
            }
        }
    }
    else if(smjer==SmjerKretanja::NazadNaprijed)
    {
        int brojac(0);
        for(int i(kont.size()-1);i>=0;i--)
        {
            mat.push_back(Tipkont());
            int taj(kont.at(0).at(0).size()-1);
            for(int j(0);j<kont.at(0).size();j++)
            {
                for(int k(kont.at(0).at(0).size()-1);k>=0;k--)
                {
                    if(k==taj) mat.at(brojac).push_back(kont.at(i).at(j).at(k));
                }
                taj--;
            }
            brojac++;
        }
    }
    else if(smjer==SmjerKretanja::GoreDolje)
    {
        int brojac(0);
        for(int j(0);j<kont.at(0).size();j++)
        {
            mat.push_back(Tipkont());
            for(int i(kont.size()-1);i>=0;i--)
            {
                for(int k(0);k<kont.at(0).at(0).size();k++)
                {
                    if(kont.size()-1-i==k) mat.at(brojac).push_back(kont.at(i).at(j).at(k));
                }
            }
            brojac++;
        }
    }
    else if(smjer==SmjerKretanja::DoljeGore)
    {
        int brojac(0);
        for(int j(kont.at(0).size()-1);j>=0;j--)
        {
            mat.push_back(Tipkont());
            int taj(kont.at(0).at(0).size()-1);
            for(int i(kont.size()-1);i>=0;i--)
            {
                for(int k(0);k<kont.at(0).at(0).size();k++)
                {
                    if(k==taj) mat.at(brojac).push_back(kont.at(i).at(j).at(k));
                }
                taj--;
            }
            brojac++;
        }
    }
    else if(smjer==SmjerKretanja::LijevoDesno)
    {
        int brojac(0);
        for(int k(0);k<kont.at(0).at(0).size();k++)
        {
            mat.push_back(Tipkont());
            int taj(kont.size()-1);
            for(int j(0);j<kont.at(0).size();j++)
            {
                for(int i(0);i<kont.size();i++)
                {
                    if(i==taj) mat.at(brojac).push_back(kont.at(i).at(j).at(k));
                }
                taj--;
            }
            brojac++;
        }
    }
    else if(smjer==SmjerKretanja::DesnoLijevo)
    {
        int brojac(0);
        for(int k(kont.at(0).at(0).size()-1);k>=0;k--)
        {
            mat.push_back(Tipkont());
            for(int j(0);j<kont.at(0).size();j++)
            {
                for(int i(0);i<kont.size();i++)
                {
                    if(i==j) mat.at(brojac).push_back(kont.at(i).at(j).at(k));
                }
            }
            brojac++;
        }
    }
    return mat;
}

int main ()
{
  try
  {
    std::cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    std::cin>>x>>y>>z;
    if(x<=0 || y<=0 || z<=0) {std::cout<<"Neispravne dimenzije kontejnera!"; return 0;}
    std::cout<<"Unesite elemente kontejnera: "<<std::endl;
    std::vector<std::deque<std::deque<int>>> v(x,std::deque<std::deque<int>>(y,std::deque<int>(z)));
    
    for(int i(0);i<v.size();i++)
        for(int j(0);j<v[0].size();j++)
            for(int k(0);k<v[0][0].size();k++)
                std::cin>>v[i][j][k];
    
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    int br;
    std::cin>>br;
    if(!(br==0 || br==1 || br==2 || br==3 || br==4 || br==5)){ std::cout<<"Smjer kretanja nije ispravan!"<<std::endl; return 0; }
    if(br==0)
    {
        auto mat(IzdvojiDijagonale3D(v,SmjerKretanja::NaprijedNazad));
        std::cout<<"NaprijedNazad: "<<std::endl;
        for(int i(0);i<mat.size();i++)
        {
            for(int j(0);j<mat[0].size();j++)
            {
                std::cout<<std::setw(4)<<mat[i][j];
            }
            std::cout<<std::endl;
        }
    }
    else if(br==1)
    {
        auto mat(IzdvojiDijagonale3D(v,SmjerKretanja::NazadNaprijed));
        std::cout<<"NazadNaprijed: "<<std::endl;
        for(int i(0);i<mat.size();i++)
        {
            for(int j(0);j<mat[0].size();j++)
            {
                std::cout<<std::setw(4)<<mat[i][j];
            }
            std::cout<<std::endl;
        }
    }
    else if(br==2)
    {
        auto mat(IzdvojiDijagonale3D(v,SmjerKretanja::GoreDolje));
        std::cout<<"GoreDolje: "<<std::endl;
        for(int i(0);i<mat.size();i++)
        {
            for(int j(0);j<mat[0].size();j++)
            {
                std::cout<<std::setw(4)<<mat[i][j];
            }
            std::cout<<std::endl;
        }
    }
    else if(br==3)
    {
        auto mat(IzdvojiDijagonale3D(v,SmjerKretanja::DoljeGore));
        std::cout<<"DoljeGore: "<<std::endl;
        for(int i(0);i<mat.size();i++)
        {
            for(int j(0);j<mat[0].size();j++)
            {
                std::cout<<std::setw(4)<<mat[i][j];
            }
            std::cout<<std::endl;
        }
    }
    else if(br==4)
    {
        auto mat(IzdvojiDijagonale3D(v,SmjerKretanja::LijevoDesno));
        std::cout<<"LijevoDesno: "<<std::endl;
        for(int i(0);i<mat.size();i++)
        {
            for(int j(0);j<mat[0].size();j++)
            {
                std::cout<<std::setw(4)<<mat[i][j];
            }
            std::cout<<std::endl;
        }
    }
    else if(br==5)
    {
        auto mat(IzdvojiDijagonale3D(v,SmjerKretanja::DesnoLijevo));
        std::cout<<"DesnoLijevo: "<<std::endl;
        for(int i(0);i<mat.size();i++)
        {
            for(int j(0);j<mat[0].size();j++)
            {
                std::cout<<std::setw(4)<<mat[i][j];
            }
            std::cout<<std::endl;
        }
    }
  }
  catch(std::domain_error izuzetak)
  {
      std::cout<<izuzetak.what();
  }
	return 0;
}