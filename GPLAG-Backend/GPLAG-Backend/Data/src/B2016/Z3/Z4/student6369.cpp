/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<vector>
#include<stdexcept>
#include<list>
#include<set>


bool IsCharOrDigit(char x)
{
    return (x >= 'a' && x <='z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x<= '9');
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int brojTimova)
{
    if(brojTimova <1 || brojTimova>imena.size())
    throw std::logic_error("Razvrstavanje nemoguce");
    int kolikoClanova=imena.size()/brojTimova;
    int kolikoVise=imena.size()%brojTimova;
    int kojiTim=1;
    std::vector<std::set<std::string>>timovi;
    std::list<std::string>lista;
    for(int i=0;i<imena.size();i++)
    lista.push_back(imena[i]);
    int brDjece=imena.size();
    int k=0;
    auto iter=lista.begin();
    std::set<std::string>trenutniTim;
    while(brDjece>0){
        std::string dijete = *iter;
        iter = lista.erase(iter);
        iter--;
        trenutniTim.insert(dijete);
        for(int i(0); i < dijete.length(); i++)
            if(IsCharOrDigit(dijete[i]))
                k++;
        for(int i(0); i < k; i++){
            iter++;
            if(iter == lista.end())
                iter = lista.begin();
    }
    k = 0;
    
    if((kojiTim <= kolikoVise && trenutniTim.size() == kolikoClanova +1) || (kojiTim > kolikoVise && trenutniTim.size() == kolikoClanova))
    {
        timovi.push_back(trenutniTim);
        kojiTim++;
        trenutniTim.clear();
    }
    brDjece--;
    }
    return timovi;
}


int main ()
{
    std::vector<std::string> imena;
    int n;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::string x = "";
    std::cin.ignore(10000,'\n');
    for(int i(0); i < n; i++)
    {
        std::getline(std::cin,x);
        imena.push_back(x);
    }
    std::cout<<"Unesite broj timova: ";
    int p;
    std::cin>>p;
    auto timovi = Razvrstavanje(imena,p);
    for(int i(0); i < p; i++)
    {
        std::cout<<"Tim "<<i+1<<": ";
        for(auto it = timovi[i].begin(); it != timovi[i].end(); it++)
        {
            auto tmp = it;
            tmp++;
            if(tmp == timovi[i].end())
                std::cout<<*it;
            else std::cout<<*it<<", ";
        }
        std::cout<<std::endl;
    }
	return 0;
}