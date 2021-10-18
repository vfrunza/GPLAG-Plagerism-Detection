/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <iterator>
#include <set>
#include <stdexcept>
int DuzinaImena(const std::string &ime)
{
	int n(0);
	for(int i=0; i<ime.length(); i++)
		if((ime[i]>='A' && ime[i]<='Z') || (ime[i]>='a' && ime[i]<='z') || (ime[i]>='0' && ime[i]<='9'))
			n++;
	return n;
}
typedef std::vector<std::set<std::string>> SetoviStringova;
SetoviStringova Razvrstavanje(std::vector<std::string> imena, int br_timova)
{
	if(br_timova<1 || br_timova>imena.size())	throw std::logic_error("Razvrstavanje nemoguce");
    SetoviStringova timovi(br_timova);
    std::list<std::string> lista_imena;
    int br_plus1(imena.size()%br_timova);    //broj ostalih je br_timova-br_plus1;
    int clanovi1=(imena.size()/br_timova+1);  //clanovi ostalih su za jedan manji
    
    for(auto it=imena.begin(); it!=imena.end(); it++)   lista_imena.push_back(*it);
    for(auto it=lista_imena.begin(); it!=lista_imena.end(); it++)
    {
        int duz(DuzinaImena(*it));
        for(int i=0; i<br_timova; i++)
        {
            if((i<br_plus1 && std::distance(timovi[i].begin(), timovi[i].end())<clanovi1) ||
                (i>=br_plus1 && std::distance(timovi[i].begin(), timovi[i].end())<clanovi1-1))
                {
                    timovi[i].insert(*it);
                    break;
                }
        }
        it=lista_imena.erase(it);
        if(it==lista_imena.end())   it=lista_imena.begin();
        for(int i=0; i<duz-1; i++)    if(++it==lista_imena.end()) it=lista_imena.begin();
        it--;
    }
    return timovi;
}
int main ()
{
	int n;
	std::cout<<"Unesite broj djece: ";
	std::cin>>n;
	std::cin.ignore(10000,'\n');
	std::cin.clear();
	std::vector<std::string> djeca;
	std::cout<<"Unesite imena djece: "<<std::endl;
	for(int i=0; i<n; i++)
	{
	    std::string ime;
	    std::getline(std::cin, ime);
	    djeca.push_back(ime);
	    
	}
	std::cout<<"Unesite broj timova: ";
	std::cin>>n;
	try
	{
		auto timovi(Razvrstavanje(djeca, n));
		for(int i=0; i<timovi.size(); i++)
		{
		    std::cout<<"Tim "<<i+1<<": ";
		    for(auto it=timovi[i].begin(); it!=timovi[i].end(); it++)
		    {
		        if(++it==timovi[i].end()) std::cout<<*(--it);
		        else std::cout<<*(--it)<<", ";
		    }
		    std::cout<<std::endl;
		}
	}
	catch(std::logic_error izuzetak)
	{
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	
}