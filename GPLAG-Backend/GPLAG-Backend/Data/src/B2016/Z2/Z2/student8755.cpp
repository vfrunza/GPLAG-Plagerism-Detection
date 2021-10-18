// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <type_traits>
#include <deque>
#include <vector>
#include <stdexcept>
#include <iomanip>
enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename Kontejner>
auto IzdvojiDijagonale3D(Kontejner kont, SmjerKretanja smjer)->typename std::remove_reference<decltype(kont.at(0))>::type
{
	int x(0),y(0),z(0);
    for(int i=0; i<kont.size();i++)
        for(int j=0; j<kont.at(i).size();j++)
                if(kont.at(i).at(j).size()!=kont.at(0).at(0).size())   throw std::domain_error("Redovi nemaju isti broj elemenata");
                else if(kont.at(i).size()!=kont.at(0).size())   throw std::domain_error ("Plohe nemaju isti broj redova");
    typename std::remove_reference<decltype(kont.at(0))>::type mat;
    //if(kont.size()==0 || kont.at(0).size()==0 || kont.at(0).at(0).size()==0)    return mat;
    for(int i=0; i<kont.size(); i++)
    	for(int j=0; j<kont.at(i).size(); j++)
    	{
				if(int(smjer)==0 || int(smjer)==1)		{z=kont.size(); x=kont.at(i).size(); y=kont.at(i).at(j).size();}
    			else if(int(smjer)==2 || int(smjer)==3) {z=kont.at(i).size(); x=kont.at(i).at(j).size(); y=kont.size();}
    			else if(int(smjer)==4 || int(smjer)==5) {z=kont.at(i).at(j).size(); x=kont.at(i).size(); y=kont.size();}
    	}
    
    for(int k=0; k<z; k++)
    {
        typename std::remove_reference<decltype(kont.at(0).at(0))>::type temp;
        for(int i=0; i<x; i++)
            for(int j=0; j<y; j++)
                if(i==j && int(smjer)==0)           temp.push_back(kont.at(k).at(i).at(j));
                else if(int(smjer)==1 && j==y-1-i)  temp.push_back(kont.at(z-1-k).at(i).at(j));
                else if(int(smjer)==2 && j==y-1-i)  temp.push_back(kont.at(j).at(k).at(i));
                else if(int(smjer)==3 && i==j)      temp.push_back(kont.at(y-1-j).at(z-1-k).at(x-1-i));
                else if(int(smjer)==4 && i==y-1-j)  temp.push_back(kont.at(j).at(i).at(k));
                else if(int(smjer)==5 && i==j)      temp.push_back(kont.at(j).at(i).at(z-1-k));
        if(temp.size()!=0)  mat.push_back(temp); 
    }
    return  mat;
}
int main ()
{
	int x, y, z;
	std::cout<<"Unesite dimenzije (x y z): ";
	std::cin>>x>>y>>z;
	if(x<0 || y<0 || z<0)
	{
	    std::cout<<"Neispravne dimenzije kontejnera!";
	    return 0;
	}
	std::cout<<"Unesite elemente kontejnera: "<<std::endl;
	std::vector<std::deque<std::deque<int>>> kont(x, std::deque<std::deque<int>>(y, std::deque<int>(z)));
	
	for(int k=0; k<x; k++)
	    for(int i=0; i<y; i++)
	        for(int j=0; j<z; j++)
	            std::cin>>kont[k][i][j];
	
	std::cin.ignore(10000,'\n');
	std::cin.clear();
	int n;
	std::cout<<"Unesite smjer kretanja [0 - 5]: ";
	std::cin>>n;
	if(n<0 || n>5 || !(std::cin)) 
	{
	    std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
	    return 0;
	}
	std::vector<std::string> lista{"NaprijedNazad","NazadNaprijed","GoreDolje","DoljeGore","LijevoDesno","DesnoLijevo"};
	std::cout<<lista[n]<<": "<<std::endl;
	
	auto mat(IzdvojiDijagonale3D(kont, SmjerKretanja(n)));
	
	for(auto &red : mat)
	{
	    for(auto &x : red)
	        std::cout<<std::setw(4)<<x;
	   std::cout<<std::endl;
	}
}