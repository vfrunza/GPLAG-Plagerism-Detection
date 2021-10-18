#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <string>
#include <stdexcept>
enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };
template <typename Tip1>
auto IzdvojiDijagonale3D (Tip1 kont, SmjerKretanja a) -> typename std::remove_reference<decltype(kont.at(0))>::type
{
    int test;
    if(kont.size() > 0 && kont.at(0).size() > 0)
        test = kont.at(0).at(0).size();
    for(int i = 0; i < kont.size(); i++)
    {
        for(int j = 0; j < kont.at(i).size(); j++)
            if(kont.at(i).at(j).size() != test)
                throw std::domain_error("Redovi nemaju isti broj elemenata");
    }
    int test2;
    if(kont.size() > 0)
        test2 = kont.at(0).size();
    for(int i = 0; i < kont.size(); i++)
    {
        if(kont.at(i).size() != test2) 
            throw std::domain_error("Plohe nemaju isti broj redova");
    }
    int p(0);
    typename std::remove_reference<decltype(kont.at(0))>::type mat;
    typedef typename std::remove_reference<decltype(mat.at(0))>::type tipx;
    tipx elem;    
    switch(int(a))
    {
        case 0:
            for(int i = 0; i < kont.size(); i++)
                mat.push_back(elem);
            for(int i = 0; i < kont.size(); i++)
            {
                for(int j = 0; j < kont.at(i).size(); j++)
                {
                    for(int k = 0; k < kont.at(i).at(j).size(); k++)
                    {
                        if(j == k)
                        {
                            mat.at(p).push_back(kont.at(i).at(j).at(k));
                        }
                    }
                } p++;
            } break;
        case 1:
            for(int i = 0; i < kont.size(); i++)
                mat.push_back(elem);
            for(int i = kont.size()-1; i >= 0; i--)
            {
                for(int j = 0; j < kont.at(i).size(); j++)
                {
                    for(int k = 0; k < kont.at(i).at(j).size(); k++)
                    {
                        if(j + k ==  3)

                            mat.at(p).push_back(kont.at(i).at(j).at(k));
                    }
                } p++;
            } break;
        case 2:
            for(int i = 0; i < kont.at(0).size(); i++)
                mat.push_back(elem);
            for(int i = kont.size()-1; i >= 0; i--)
            {
                p = 0;
                for(int j = 0; j < kont.at(i).size(); j++)
                {
                    for(int k = 0; k < kont.at(i).at(j).size(); k++)
                    {
                        if(std::abs(i-k) == 1 && (i != kont.size() && k != kont.size()))
                        {
                            mat.at(p).push_back(kont.at(i).at(j).at(k));
                        }
                    } p++;
                }
            } break;
        
        case 3:
            for(int i = 0; i < kont.at(0).size(); i++)
                mat.push_back(elem);
            for(int i = kont.size()-1; i >= 0; i--)
            {
                p = 0;
                for(int j = kont.at(i).size()-1; j >= 0; j--)
                {
                    for(int k = kont.at(i).at(j).size()-1; k >= 0; k--)
                    {
                        if((kont.size() == kont.at(i).at(j).size() && i == k) || k - i == kont.size())
                            mat.at(p).push_back(kont.at(i).at(j).at(k));
                    } p++;
                }
            } break;
        case 4:
            for(int i = 0; i < kont.at(0).at(0).size(); i++)
                mat.push_back(elem);
            for(int i = kont.size()-1; i >= 0; i--)
            {
                for(int j = 0; j < kont.at(i).size(); j++)
                {
                    for(int k = 0; k < kont.at(i).at(j).size(); k++)
                    {
                        if(i + j == kont.size() - 1)
                        {
                            mat.at(p).push_back(kont.at(i).at(j).at(k));
                            p++;
                        }
                    } p = 0;
                }
            } break;
        case 5:
            for(int i = 0; i < kont.at(0).at(0).size(); i++)
                mat.push_back(elem);
            for(int i = 0; i < kont.size(); i++)
            {
                for(int j = 0; j < kont.at(i).size(); j++)
                {
                    for(int k = kont.at(i).at(j).size()-1; k >= 0; k--)
                    {
                        if(i == j)
                        {
                            mat.at(p).push_back(kont.at(i).at(j).at(k));
                            p++;
                        }
                    } p = 0;
                }
            } break;
    } return mat;
}

int main  ()
{
    try {
    std::cout<<"Unesite dimenzije (x y z): ";
    int x, y, z;
    std::cin>>x>>y>>z;
    if(x <= 0 || y <= 0 || z <= 0) 
    {
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::cout<<"Unesite elemente kontejnera: ";
    std::vector<std::deque<std::deque<int>>> kont(x, std::deque<std::deque<int>>(y, std::deque<int> (z))); //dimenzije?
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            for(int k = 0; k < z; k++)
                std::cin>>kont[i][j][k];
        }
    }
    std::cout<<"\nUnesite smjer kretanja [0 - 5]: ";
    int smjer;
    std::cin>>smjer;
    if(smjer < 0  || smjer > 5) 
    {
        std::cout<<"Smjer kretanja nije ispravan!\n";
        return 0;
    }
    std::vector<std::string> s {"NaprijedNazad", "NazadNaprijed", "GoreDolje", "DoljeGore", "LijevoDesno", "DesnoLijevo"};
    std::cout<<s[smjer]<<": "<<std::endl;
    auto mat = IzdvojiDijagonale3D(kont, SmjerKretanja(smjer));
    for(int i = 0; i < mat.size(); i++)
    {    for(int j = 0; j < mat[i].size(); j++)
            std::cout<<std::setw(4)<<mat[i][j];
        std::cout<<std::endl;
    } 
    } catch(std::domain_error err) {
        std::cout<<err.what();
    }
	return 0;
}