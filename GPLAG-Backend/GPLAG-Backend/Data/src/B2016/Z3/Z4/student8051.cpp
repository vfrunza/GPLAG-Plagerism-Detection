/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>
bool ws(char s){	        //  Funkcija koja nam salje true ukoliko je znak slovo ili broj, uostalom false.	
   if((s>='a'&&s<='z')||(s>='A'&&s<='Z')||(s>='0'&&s<='9'))
      return 1;
   else 
      return 0;
} 
int duzina(std::string s){      //  Funkcija racuna duzinu stringa (po zadanom kriteriju u zadatku).
    int p(0);
    for(int i=0;i<s.length();i++)
        if(ws(s[i]))    p++;
    return p;
}
std::vector<std::set<std::string>>Razvrstavanje(std::vector<std::string> d, int k){
    std::list<std::string> lista;
    for(int i=0;i<d.size();i++)
        lista.push_back(d[i]);      //  Kopiranje u listi.
    if(k<1||k>d.size())
        throw std::logic_error("Razvrstavanje nemoguce");   //  Bacanje izuzetka...
    std::vector<std::set<std::string>> v(k);
    std::vector<int> vel;       //  Vel je vektor cijelih brojeva pomocu kojeg odredjujemo koliko koji tim ima djece. 
    for(int i=0;i<k;i++){
        if(i<d.size()%k)
            vel.push_back(d.size()/k+1);
        else
            vel.push_back(d.size()/k);
    }
    auto it(lista.begin());     //  it je iterator pomocu kojeg prolazimo kroz listu.
    for(int i=0;i<vel.size();i++){
        for(int j=0;j<vel[i];j++){
            int idi(duzina(*it)-1); 
            v[i].insert(*it);   //  v je vektor skupova stringova u koji "trpamo" djecu u timove (grubo receno).
            it=lista.erase(it);
            if(it==lista.end())    it=lista.begin();    //  U slucaju ako it je dosao na kraj liste, nek' se vrati na pocetak.
            for(int p=0;p<idi;p++){
                it++;
                if(it==lista.end())  it=lista.begin();
            }
        }
    }
    return v;
    
}
int main ()
{
    std::cout<<"Unesite broj djece: ";
    int n;                              //  n je broj djece.
    std::vector<std::string> v;         //  v je vektor stringova, odnosno spisak djece koju razvrstavamo.
    std::cin>>n;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::cin.ignore(10000,'\n');
    for(int i=0;i<n;i++){
        std::string s;
        std::getline(std::cin,s);
        v.push_back(s);
    }
    std::cout<<"Unesite broj timova: ";
    int k;
    std::cin>>k;
    try{
        auto q(Razvrstavanje(v,k));         //  q je vektor skupova stringova kojeg smo dobili razvrstavanjem.
        for(int i=0;i<q.size();i++){
            std::cout<<"Tim "<<i+1<<": ";   //  Obicni ispis...
            for(auto it=q[i].begin();it!=q[i].end();it++)
            {
                if(it!=q[i].begin()) std::cout<<", "<<*it;
                else
                    std::cout<<*it;}
            std::cout<<std::endl;
        }
    }
    catch(std::logic_error izuzetak){   //  Hvatanje i ispisivanje poruke bacenog izuzetka.
        std::cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
	return 0;
}