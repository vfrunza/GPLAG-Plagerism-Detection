/B2016/2017: Zadaća 3, Zadatak 5
/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <set>
#include <stdexcept>
struct Dijete
{
    std::string ime;
    Dijete *sljedeci;
};
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
    int br_plus1(imena.size()%br_timova);    //broj ostalih je br_timova-br_plus1;
    int clanovi1=(imena.size()/br_timova+1);  //clanovi ostalih su za jedan manji
    
    Dijete *pocetak(nullptr), *prethodni(nullptr);
    try
    {
        for(int i=0; i<imena.size(); i++)
        {
            Dijete *novi(new Dijete);
            novi->ime=imena[i]; novi->sljedeci=nullptr;
            if(!pocetak) pocetak=novi;
            else
            {
                novi->sljedeci=pocetak;
                prethodni->sljedeci=novi;
            }
            prethodni=novi;
        }
    }
    catch(std::bad_alloc)
    {
        for(auto p=pocetak; p!=prethodni; p=p->sljedeci)
            delete p;
        throw;
    }
    for(auto *p=pocetak;; p=p->sljedeci)
    {
        int duz(DuzinaImena(p->ime));
        for(int i=0; i<br_timova; i++)
        {
            if((i<br_plus1 && std::distance(timovi[i].begin(), timovi[i].end())<clanovi1) ||
                (i>=br_plus1 && std::distance(timovi[i].begin(), timovi[i].end())<clanovi1-1))
                {
                    timovi[i].insert(p->ime);
                    break;
                }
        }
        if(p==prethodni)
        {
            delete p;
            break;
        }
        prethodni->sljedeci=p->sljedeci;
        delete p;
        p=prethodni->sljedeci;
        for(int i=0; i<duz-2; i++)
        {
            p=p->sljedeci;
            prethodni=prethodni->sljedeci;
        }
        prethodni=prethodni->sljedeci;
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