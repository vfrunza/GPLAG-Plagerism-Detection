#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

int main()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    switch(opcija)
    {
        case 1:
        {
            int br_cvor;
            std::cout<<"Unesite broj cvorova: ";
            std::cin>>br_cvor;
            std::vector<std::pair<int,int>> par_cvor;
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0;i<br_cvor;i++)
                std::cin>>par_cvor.first>>par_cvor.second;
            int interpol;
            std::cout<<"Unesite red interpolacije: ";
            std::cin>>interpol;
            std::string input;
            do
            {
                std::cout<<"Unesite argument (ili ""kraj"" za kraj): ";
                std::getline(std::cin,input);
                //funkcija
            }while(input!=std::string{"kraj"});
        }
        case 2:
        {
            std::pair<int,int> interval;
            float korak;
            std::cout<<"Unesite krajeve intervala i korak: ";
            std::cin>>interval.first>>interval.second>>korak;
            int interpol;
            std::cout<<"Unesite red interpolacije: ";
            std::cin>>interpol;
            
        }
    }
    return 0;
}