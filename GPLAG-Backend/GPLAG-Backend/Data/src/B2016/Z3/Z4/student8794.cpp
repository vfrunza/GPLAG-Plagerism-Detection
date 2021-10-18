/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<set>
#include<list>
#include<vector>
#include<iomanip>
#include<stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> m1, int brojTimova)
{
    std::vector<std::set<std::string>> pom;
    std::set<std::string> tim;
    std::list<std::string> djeca;
    for(int i=0;i<m1.size();i++)
    {
    djeca.push_back(m1[i]);
    }
    if(brojTimova<1 || brojTimova>m1.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int brojac=0;
    int brojClanovaTima=djeca.size()/brojTimova;
    int nesvrstani=djeca.size()-brojClanovaTima*brojTimova;
    std::list<std::string>::iterator it=djeca.begin();
    int trenutniBrojDjeceUTimu=0;
    //prolaz kroz svako dijete
    while(brojac!=djeca.size())
    {
        tim.insert(*it);
        trenutniBrojDjeceUTimu+=1;
        //provjera da li je skupljeno dovoljno za jedan tim
        int nesvrstani1=brojClanovaTima+1;
        if(nesvrstani<=0) nesvrstani1-=1;
        if(nesvrstani1==trenutniBrojDjeceUTimu)
        {
            //smanji ostatak za jedan
            nesvrstani--;
            //postavi broj elemenata tima na 0
            trenutniBrojDjeceUTimu=0;
            //dodaj u vektor trenutni tim
            pom.push_back(tim);
            //izbrisi sve iz tima za iduci tim
            tim.clear();
        }
        
        
        // izracunaj broj slova u imenu
        int brojSlovaImena=0;
        for(int i=0;i<(*it).size();i++)
        {
            if((*it)[i]==' ' || (*it)[i]=='-') continue;
            brojSlovaImena++;
        }
        it=djeca.erase(it);
        if(it==djeca.end()) it=djeca.begin();
        for(int j=1;j<brojSlovaImena;j++)
        {
            it++;
            if(it==djeca.end()) it=djeca.begin();
        }
    }
    return pom;
}
int main ()
{
    int brDjece,brTimova;
    std::vector<std::string> djeca;
    std::cout<<"Unesite broj djece: ";
    std::cin>>brDjece;
    std::cout<<"Unesite imena djece:";
    std::cin.ignore(4444, '\n');
    for(int i=0;i<brDjece;i++)
    {
        std::string imeDjeteta;
        getline(std::cin,imeDjeteta);
        djeca.push_back(imeDjeteta);
    }
    std::cout<<"\nUnesite broj timova: ";
    std::cin>>brTimova;
    try {
        /* code */
         std::vector<std::set<std::string>> rezultat=Razvrstavanje(djeca,brTimova);
    for(int i=0;i<rezultat.size();i++)
    {
        auto skup=rezultat[i];
        auto iter1=begin(skup);
        int brojElemenataSkupa=0;
        while(iter1!=end(skup)) {iter1++;brojElemenataSkupa++;}
        //vratimo ga opet na početak
        iter1=begin(skup);
        std::cout<<"Tim "<<i+1<<": ";
        for(int j=0;j<brojElemenataSkupa;j++)
        {
            if(j>=(brojElemenataSkupa-1)) std::cout<<*iter1;
            else std::cout<<*iter1++<<","<<" ";
        }
        std::cout<<"\n";
    }
        
        
    }
    catch (std::logic_error e) {
        std::cout <<"Izuzetak: "<< e.what() << std::endl;
    }
    
   
	return 0;
}