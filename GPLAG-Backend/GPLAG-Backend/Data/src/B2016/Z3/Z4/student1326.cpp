/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int k) {
    std::vector<std::set<std::string>> rez;
    std::list<std::string> lista;
    auto it(lista.begin());
    
    int n=v.size();
    if (k<1 || k>n) throw std::logic_error ("Izuzetak: Razvrstavanje nemoguce");
    for(auto x:v) {
        lista.insert(it, x);
    }
    
    auto iter=lista.begin();
    //std::cout << *iter << std::endl;
    //for (auto x:lista) std::cout<<x<<" ";
    std::vector<std::set<std::string>> v1 (n%k); //prvi timovi
    std::vector<std::set<std::string>> v2 (k-(n%k)); //preostali timovi
    
    for (int i=0; i<v1.size(); i++) {
        std::set<std::string> tim;
        
        //std::cout<<n/k+1;
        //std::cout << k-(n%k);
        for (int j=0; j<n/k+1; j++) {
            int koraci((*iter).length()); //koliko ima slova u imenu djeteta koje izbacujemo
            //std::cout <<koraci;
            tim.insert(*iter);
            //std::cout << *iter << std::endl;
            iter=lista.erase(iter);
            //std::cout << *iter << std::endl;
            for (int k=1; k<koraci; k++) {
                iter++;                                           //iter pokazuje na sljedeće dijete koje izbacujemo
                if (iter==lista.end()) iter=lista.begin();
            }
       
        } //tim je kreiran
        v1[i]=tim;
    }
    
  //  return v1;
    
    
 for (int p=0; p<v2.size(); p++) {
        std::set<std::string> tim;
        
        //std::cout << (n/k);
        for (int q=0; q<n/k; q++) {
            int koraci((*iter).length()); //koliko ima slova u imenu djeteta koje izbacujemo
            //std::cout <<koraci;
            tim.insert(*iter);
            //std::cout << *iter << std::endl;
            iter=lista.erase(iter);
            if (iter==lista.end()) iter=lista.begin();
            //std::cout << *iter << std::endl;
            for (int r=1; r<koraci; r++) {
                iter++;                                           //iter pokazuje na sljedeće dijete koje izbacujemo
                if (iter==lista.end()) iter=lista.begin();
            }
       //     if (iter==lista.end()) iter=lista.begin();
        } //tim je kreiran
        v2[p]=tim;
    }
//return v2;

    std::vector<std::set<std::string>> vektor;
        vektor.insert (std::end(vektor), std::begin(v1), std::end(v1));
        vektor.insert (std::end(vektor), std::begin(v2), std::end(v2));
        return vektor; 
 

}
    
int main () {
    int n_djece, n_timova;
    std::string imena;
    std::vector<std::string> djeca;
    
    std::cout<<"Unesite broj djece: ";
    std::cin>>n_djece;
    std::cin.ignore (1000, '\n');
    
    std::cout<<"Unesite imena djece: "<<std::endl;
    for (int i=0; i<n_djece; i++) {
    std::getline (std::cin, imena);
        djeca.push_back (imena);
    }
    
    std::cout<<"Unesite broj timova: ";
    std::cin>>n_timova;
    
    try {

    auto vektor=Razvrstavanje (djeca, n_timova);
        for (int i=0; i<vektor.size(); i++) {
            std::cout<<"Tim " <<i+1<<":";
            
            for (auto it=vektor[i].begin(); it!=vektor[i].end(); it++ ) {
                it++;
                auto pom=it;
                it--;
                if (pom==vektor[i].end()) std::cout<<" "<<*it<<std::endl;
                else std::cout<<" "<<*it<<",";
            }
            
        }
    }
        catch (std::logic_error izuzetak) {
            std::cout<<izuzetak.what();
        }
    
   /*
    
   std::vector<std::string> vektor { "Damir", "Ana", "Muhamed", "Marko", "Ivan", "Mirsad", "Nikolina", "Alen", "Jasmina", "Merima" };
    auto rez (Razvrstavanje(vektor,3));
    std::set<std::string> tim(rez[]);
    for (auto x:tim) std::cout<<x<<std::endl; */
    
	return 0;
	
}