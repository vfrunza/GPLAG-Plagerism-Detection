/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <string>

template <typename Tip>

std::vector<Tip> Presjek(std::vector<Tip> &v1, std::vector<Tip> &v2){
    std::vector<Tip> v3;
    bool jednaki(false);
    
    for(int i=0; i<v1.size(); i++)
    {
        for(int j=0; j<v2.size(); j++)
        {
            if(v1.at(i) == v2.at(j))
            {
                for(int k=0; k<v3.size(); k++)
                    if(v3.at(k) == v1.at(i))
                    {
                        jednaki = true; break;
                    }
                    if(!jednaki) v3.push_back(v1.at(i));
            }
            jednaki = false;
            
        }
    }
    return v3;
    
}
int main ()
{
    std::cout << "Test za realne brojeve..." << std::endl;
    std::cout << "Unesite broj elemenata prvog vektora: ";
    
    int n1;
    std::cin >> n1;
    
    std::cout << "Unesite elemente prvog vektora: ";
    std::vector<double> v1(n1);
    for(double &element : v1) std::cin >> element;
    
    std::cout << "Unesite broj elemenata drugog vektora: ";
    
    int n2;
    std::cin >> n2;
    
    std::cout << "Unesite elemente drugog vektora: ";
    std::vector<double> v2(n2);
    for(double &element : v2) std::cin >> element;
    
    std::vector<double> v3(Presjek(v1,v2));
    
    std::cout << "Zajednicki elementi su: ";
    int i;
    for( i=0; i<v3.size()-1; i++) std::cout << v3.at(i) << " ";
    if(i == v3.size()-1) std::cout << v3.at(i);
    
    std::cout << std::endl << std::endl << "Test za stringove..." << std::endl;
    
    std::cout << "Unesite broj elemenata prvog vektora: ";
    int n3;
    std::cin >> n3;
    std::cout << "Unesite elemente prvog vektora (ENTER nakon svakog unosa): ";
    std::vector<std::string> vs1(n3);
    std::cin.ignore(1000,'\n');
    for(std::string &linija : vs1) std::getline(std::cin,linija);
    
    std::cout << "Unesite broj elemenata drugog vektora: ";
    int n4;
    std::cin >> n4;
    std::cout << "Unesite elemente drugog vektora (ENTER nakon svakog unosa): ";
    std::vector<std::string> vs2(n4);
    std::cin.ignore(1000,'\n');
    for(std::string &linija : vs2) std::getline(std::cin,linija);
    
    std::cout << "Zajednicki elementi su: " << std::endl;
    std::vector<std::string> vs3(Presjek(vs1,vs2));
    
    for(int i=0; i<vs3.size(); i++) std::cout << vs3.at(i) << std::endl;
    
    
	return 0;
}
