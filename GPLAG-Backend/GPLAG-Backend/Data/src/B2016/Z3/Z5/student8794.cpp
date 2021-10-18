/B2016/2017: Zadaća 3, Zadatak 5
/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<set>
#include<list>
#include<vector>
#include<iomanip>
#include<stdexcept>

//definisanje strukture dijete
struct Dijete
{
    std::string ime;
    Dijete *sljedeci;
};



std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> m1, int brojTimova)
{
    int ukupanBrojDjece=m1.size();
    std::vector<std::set<std::string>> pom;
    std::set<std::string> tim;
    if(brojTimova<1 || brojTimova>ukupanBrojDjece) throw std::logic_error("Razvrstavanje nemoguce");
    
    //kreiramo prvo dijete
    Dijete* prvo;
    Dijete* prethodni;
    for(int i=0;i<ukupanBrojDjece;i++)
    {
        //ako je prvo dijete onda nema prethodnog
        Dijete* dijete=new Dijete();
        if(i==0)
        {
        prvo=dijete;
        prethodni=prvo;
        }
        else
        {
            prethodni->sljedeci=dijete;
            prethodni=dijete;
        }
        dijete->ime=m1[i];
        
    }
    prethodni->sljedeci=prvo;
   
    //ovim smo dobili kružnu listu, valjda je sve ok
    
    int brojac=0;
    int brojClanovaTima=ukupanBrojDjece/brojTimova;
    int nesvrstani=ukupanBrojDjece-brojClanovaTima*brojTimova;
    //prvo Dijete
    auto it=prvo;
    //zadnje dijete, treba da preusmjerimo pokazivač je prethodni
    int trenutniBrojDjeceUTimu=0;
    //prolaz kroz svako dijete
    while(brojac!=ukupanBrojDjece)
    {
        brojac++;
        tim.insert(it->ime);
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
        for(int i=0;i<(it->ime).size();i++)
        {
            if((it->ime)[i]==' ' || (it->ime)[i]=='-') continue;
            brojSlovaImena++;
        }
        //sad brisi to dijete;
        //specijalan slučaj kad je ostalo dvoje djece, ili jedno
        //ako je dvoje djece ostalo, prebaci prethodni sljedeći na samog sebe, to je ok
        //ako je jedno dijete, opet prebaci na samog sebe, ok
        prethodni->sljedeci=it->sljedeci;
        delete it;
        if(brojac==ukupanBrojDjece) break;
        it=prethodni->sljedeci;
        for(int j=1;j<brojSlovaImena;j++)
        {   
            prethodni=prethodni->sljedeci;
            it=it->sljedeci;
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