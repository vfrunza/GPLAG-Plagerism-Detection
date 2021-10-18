#include <iostream>
#include <string>
#include <set>
#include <list>
#include <stdexcept>
#include <vector>

int Koliko(std::string s){
    int br(0);
    for(int i=0;i<s.length(); i++)
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) 
            br++;
    return br;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int n){
    if(n<1 || n>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    for(int i=0; i<v.size(); i++){
        lista.push_back(v[i]);
    }
    auto it(lista.begin());
    std::vector<std::set<std::string>> a(n);
    for(int i=0; i<n; i++)    
    {    
        int max_vel=v.size()/n; 
        if(v.size()%n>i) max_vel+=1;
        int v_size=max_vel;
        while (v_size--!=0) 
        {
            a[i].insert(*it);
            int potez(Koliko(*it));
            it=lista.erase(it);
            if(it==lista.end()) it=lista.begin();
            //std::cout << i+1<<"prolaz "<< potez <<"duzina" <<a[i].size() <<std::endl;
            int w(1);
            while(w!=potez){
                it++;w++;
                if(it==lista.end()) it=lista.begin();
            }
        }
    }
    return a;
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int br_osoba; std::cin >> br_osoba;
    std::vector<std::string> w(br_osoba);
    std::cout <<"Unesite imena djece:";
    std::cin.ignore(10000, '\n');
    {
        std::string pomocni;
        for(int i=0; i<br_osoba;i++){
            std::getline(std::cin, pomocni);
            w[i]=pomocni;
        }
    }
    std::cout << "\nUnesite broj timova: "; int k; std::cin >> k;
    try {
        auto a(Razvrstavanje(w,k));
        for(int i=0; i<a.size(); i++){
            std::cout << "Tim " <<i+1<<": ";
            int brojac(0);
            for(auto x(a[i].begin()); x!=a[i].end();x++){
                if(brojac==a[i].size()-1)
                    std::cout << *x;
                else
                    std::cout << *x<<", ";
                brojac++;
            }        
            std::cout  << std::endl; 
        }
    }
    catch (std::logic_error error) {
        std::cout <<"Izuzetak: " <<error.what() << std::endl;
    }
    
    /*try{
        std::vector<std::string> v={ "Damir", "Ana", "Muhamed", "Marko",  "Ivan", "Mirsad", "Nikolina", "Alen", "Jasmina", "Merima" };
        auto a(Razvrstavanje(v,3));
        for(int i=0; i<a.size(); i++){
            std::cout << "Tim " <<i+1<<":";
            for(auto x:a[i])
                std::cout <<x<<" ";
            std::cout  << std::endl;    
        }
    }
    catch (std::logic_error error) {
        std::cout << error.what() << std::endl;
    }*/
	return 0;
}