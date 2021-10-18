/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stdexcept>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

std::list<std::pair<Boje, std::string>> KreirajSpil()
{

}

void IzbaciKarte (std::list<std::pair<Boje, std::string>> &lista, std::multimap<Boje, std::string> &multimapa)
{
    if(lista.size()>52)
        throw std::logic_error ("Izuzetak: Neispravna lista!");
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem (std::list<std::pair<Boje, std::string>> &lista, const short int &korak_razbrajanja, const int &br_karata)
{
    if(korak_razbrajanja<1 || korak_razbrajanja>52 || br_karata<1)
        throw std::logic_error ("Izuzetak: Neispravni elementi za izbacivanje!");

    if(lista.size()>52)
        throw std::logic_error ("Izuzetak: Neispravna lista!");
}

std::list<std::list<std::pair<Boje, std::string>>> VratiPrvihNKarata (std::list<std::pair<Boje, std::string>> &lista, std::queue<std::pair<std::string, std::string>> &red, int n)
{
    if(n>red.size())
        throw std::range_error ("Izuzetak: Nedovoljno karata u redu!");

    if(n!=(int)n || n<0)
        throw std::domain_error ("Izuzetak: Broj n je besmislen!");

    if(lista.size()>52)
        throw std::logic_error ("Izuzetak: Neispravna lista!");
}

int main ()
{
    try {
        int korak, br_karata;
        std::cout<<"Unesite korak razbrajanja: ";
        std::cin>>korak;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>br_karata;

        if(korak<1 || korak>52 || br_karata<1)
            throw std::logic_error ("Izuzetak: Neispravni elementi za izbacivanje!");

    } catch(std::domain_error izuzetak1) {
        std::cout<<izuzetak1.what()<<std::endl;
    } catch(std::range_error izuzetak2) {
        std::cout<<izuzetak2.what()<<std::endl;
    } catch(std::logic_error izuzetak3) {
        std::cout<<izuzetak3.what()<<std::endl;
    } catch(...) {

    }
    return 0;
}
