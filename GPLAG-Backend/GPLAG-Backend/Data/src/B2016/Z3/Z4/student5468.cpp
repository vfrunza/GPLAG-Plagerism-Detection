#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int br_timova){
    if((br_timova<1) or (br_timova>djeca.size())){
        throw std::logic_error ("Razvrstavanje nemoguce");
    }
    std::vector<int> brojaci(br_timova);
    for(int i=0; i<brojaci.size(); i++){
        brojaci[i]=djeca.size()/br_timova;
        if(i<djeca.size()%br_timova)
            brojaci[i]++;
    }
    
    std::list<std::string> pom;

    for(int i=0; i<djeca.size(); i++){
        pom.push_back(djeca[i]);
    }

    std::vector<std::set<std::string>> timovi(br_timova);  
    int i(0);
        for(auto it(pom.begin()); ; ){
      //      std::cout<<*it<< "  ";
            int br_slova((*it).size());
            if(brojaci[i]!=0){
                timovi[i].insert(*it);
                brojaci[i]--;
                for(auto x : *it){
                    if(  (x==' ')  or  (((((x<'0')or(x>'9'))and(x<'a'))or(x>'z'))and((x<'A')or(x>'Z')))   )
                        br_slova--;
                }
                it=pom.erase(it);
                if(pom.empty()) break;
                if(it==pom.end())
                        it=pom.begin();
                
             //   std::cout<<*it<<br_slova<< " <-> ";
                
          //      std::cout<<br_slova<<" ";
                for(int j(1); j<br_slova; j++){
                    it++;
                    if(it==pom.end())
                        it=pom.begin();
                }
                
            }else i++;
        }
        return timovi;
}

int main ()
{
    std::cout<<"Unesite broj djece: ";
    
    int br;
    std::cin>>br;
    std::cin.ignore(1000,'\n');
    std::vector<std::string> a(br);
    std::cout<<"Unesite imena djece: ";
    for(int i=0; i<br; i++){
        std::getline(std::cin, a[i]);
    }
    int b;
    std::cout<<std::endl<<"Unesite broj timova: ";
    std::cin>>b;
    try{
    auto c(Razvrstavanje(a,b));
    for(int i=0; i<c.size(); i++){
        std::cout<<"Tim "<<i+1<<": ";
        for(auto it(c[i].begin()); it!=c[i].end(); it++){
            if(++it==c[i].end()){
                it--;
                std::cout<<*it;
            }else{
                it--;
                std::cout<<*it<<", ";
            }
        }
        std::cout<<std::endl;
    }
    }catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}