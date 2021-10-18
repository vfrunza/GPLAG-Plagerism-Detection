// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <deque>
#include <vector>
#include <iomanip>
#include <stdexcept>
enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename Mojtip>
auto IzdvojiDijagonale3D (Mojtip kvadar,SmjerKretanja smjer) -> typename std::remove_reference<decltype(kvadar.at(0))>::type
{
    using Tip1=typename std::remove_reference<decltype(kvadar.at(0).at(0).at(0))>::type;
    using Tip2=typename std::remove_reference<decltype(kvadar.at(0).at(0))>::type;
    using Tip3=typename std::remove_reference<decltype(kvadar.at(0))>::type;
    using Tip4=typename std::remove_reference<decltype(kvadar)>::type;
    
    for(int i=0;i<kvadar.size();i++)
    {
    	if(kvadar.at(i).size()!=kvadar.at(0).size())
    	throw std::domain_error("Plohe nemaju isti broj redova");
    	
    	for(int j=0;j<kvadar.at(i).size();j++)
    	{
    		if(kvadar.at(i).at(j).size()!=kvadar.at(i).at(0).size())
    		throw std::domain_error("Redovi nemaju isti broj elemenata");
    	}
    }
    
    
    if(smjer==SmjerKretanja::NaprijedNazad)
    {
    	Tip3 izlaz;
    	/*Tip3 izlaz(kvadar.size());*/
    	
    	for(int i=0;i<kvadar.size();i++)
    	{
    		Tip2 trenutni;
    		for(int j=0;j<kvadar.at(i).size() && j<kvadar.at(i).at(0).size();j++)                
    		{
    			trenutni.push_back(kvadar.at(i).at(j).at(j));
    		}
    		izlaz.push_back(trenutni);
    		
    	}
    	
    	
    	return izlaz;
    }
     /**************************************************************************/
    
     if(smjer==SmjerKretanja::NazadNaprijed)
    {
    	Tip3 izlaz;
    	/*Tip3 izlaz(kvadar.size());*/
    	
    	for(int i=int(kvadar.size())-1;i>=0;i--)
    	{
    		Tip2 trenutni;
    		for(int j=0;j<kvadar.at(i).size() && j<kvadar.at(i).at(0).size();j++)
    		{
    			trenutni.push_back(kvadar.at(i).at(j).at(kvadar.at(i).at(0).size()-j-1));          
    		}
    		izlaz.push_back(trenutni);
    		
    	}
    	
    	
    	return izlaz;
    }
    /******************************************************************************/
     if(smjer==SmjerKretanja::GoreDolje)
    {
    	Tip3 izlaz;
    	
    	for(int i=0;i<kvadar.at(0).size();i++)
    	{
    		Tip2 trenutni;
    		int k;
    		for(int j=0;j<kvadar.size() && j<kvadar.at(0).at(0).size();j++)
    		{
    		    k=kvadar.size()-j-1;
    			trenutni.push_back(kvadar.at(k).at(i).at(j));                     
    		}
    		izlaz.push_back(trenutni);
    		
    	}
    	
    	
    	return izlaz;
    }
    
     if(smjer==SmjerKretanja::DoljeGore)
    {
    	Tip3 izlaz;
    	/*Tip3 izlaz(kvadar.at(0).size());*/
    	for(int i=int(kvadar.at(0).size())-1;i>=0;i--)
       	{
    		Tip2 trenutni;
    		for(int j=0;j<kvadar.size() && j<kvadar.at(0).at(0).size();j++)
    		{
    			trenutni.push_back(kvadar.at(kvadar.size()-1-j).at(i).at(kvadar.at(0).at(0).size()-1-j));
    		}
    		izlaz.push_back(trenutni);
    		
    	}
    	
    	
    	return izlaz;
    }
    
     if(smjer==SmjerKretanja::LijevoDesno)
    {
    	Tip3 izlaz;
    	/*Tip3 izlaz(kvadar.at(0).at(0).size());*/
    	for(int i=0;i<kvadar.at(0).at(0).size();i++)
    	{
    		Tip2 trenutni;
    		for(int j=0;j<kvadar.at(0).size() && j<kvadar.size();j++)
    		{
    			int k=kvadar.size()-1-j;
    			trenutni.push_back(kvadar.at(k).at(j).at(i));
    		}
    		izlaz.push_back(trenutni);
    		
    	}
    	
    	
    	return izlaz;
    }
    
     if(smjer==SmjerKretanja::DesnoLijevo)
    {
    	Tip3 izlaz;
    	/*Tip3 izlaz(kvadar.size());*/
    	for(int i=int(kvadar.at(0).at(0).size())-1;i>=0;i--)
    	{
    		Tip2 trenutni;
    		for(int j=0;j<kvadar.at(0).size() && j<kvadar.size();j++)
    		{
    			
    			trenutni.push_back(kvadar.at(j).at(j).at(i));
    			
    		}
    		izlaz.push_back(trenutni);
    		
    	}
    	
    	
    	return izlaz;
    }
  
    
    
    
    
    
    
    
    
    
    
    
    
    return kvadar.at(0);
    
}


int main ()
{

	std::cout<<"Unesite dimenzije (x y z): ";
	int x,y,z;
	std::cin>>x>>y>>z;
	try
	{
	if(x<=0 || y<=0 || z<=0)
	throw std::domain_error("Neispravne dimenzije kontejnera!");
    }
	catch(std::domain_error e)
	{
	    std::cout<<e.what()<<std::endl;
	    return 0;
	}
	std::vector<std::deque<std::deque<int>>>ulaz(x,std::deque<std::deque<int>>(y,std::deque<int>(z)));
	
	std::cout<<"Unesite elemente kontejnera: "<<std::endl;
	for(int i=0;i<ulaz.size();i++)
	{
	    for(int j=0;j<ulaz.at(i).size();j++)
	    {
	        for(int k=0;k<ulaz.at(i).at(j).size();k++)
	        {
	            int a;
	            std::cin>>a;
	            ulaz.at(i).at(j).at(k)=a;
	            
	        }
	        
	    }
	}
	
	std::cout<<"Unesite smjer kretanja [0 - 5]: ";
	int smjer;
	std::cin>>smjer;
	for(;;)
	{
		if(smjer==0)
		{std::cout<<"NaprijedNazad: "<<std::endl;break;}
		if(smjer==1)
		{std::cout<<"NazadNaprijed: "<<std::endl;break;}
		if(smjer==2)
		{std::cout<<"GoreDolje: "<<std::endl;break;}
		if(smjer==3)
		{std::cout<<"DoljeGore: "<<std::endl;break;}
		if(smjer==4)
		{std::cout<<"LijevoDesno: "<<std::endl;break;}
		if(smjer==5)
		{std::cout<<"DesnoLijevo: "<<std::endl;break;}
		std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
		return 0;
	}
	
	std::deque<std::deque<int>>izlaz;
	try
	{
	izlaz=IzdvojiDijagonale3D(ulaz,SmjerKretanja(smjer));
	}
	catch(std::domain_error e)
	{
	    std::cout<<e.what()<<std::endl;return 0;
	}
	
	
	for(int i=0;i<izlaz.size();i++)
	{
		for(int j=0;j<izlaz.at(i).size();j++)
		std::cout<<std::setw(4)<<std::setprecision(12)<<izlaz.at(i).at(j);
		std::cout<<std::endl;
	}
	
	
	
	
	
	
	
	return 0;
}

