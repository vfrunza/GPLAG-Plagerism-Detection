/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>


std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>v,int broj_timova) {
    if(broj_timova<1 || broj_timova>v.size()) {
        throw std::logic_error("Razvrstavanje nemoguce");
    }
    std::vector<std::set<std::string>> v1;
    std::list<std::string> lista;
    for(int i=0;i<v.size();i++) {
        lista.push_back(v[i]);
    }
    /*for(auto it=lista.begin();it!=lista.end();it++) {
        std::cout<<*it<<" ";
    }*/
    //std::cout<<std::endl<<std::endl;
    std::vector<int>vzb;
    if(v.size()%broj_timova!=0) {
        int broj=v.size()%broj_timova;
        for(int i=0;i<broj;i++) {
            int broj2=(v.size()/broj_timova)+1;
            vzb.push_back(broj2);
        }
        for(int i=broj;i<broj_timova;i++) {
            int broj3=v.size()/broj_timova;
            vzb.push_back(broj3);
        }
    }
    else {
        for(int i=0;i<broj_timova;i++) {
            vzb.push_back(v.size()/broj_timova);
            
            
        }
    }
        int velicina_vzb(0);
        for(int i=0;i<vzb.size();i++) {
            velicina_vzb+=vzb[i];

        }
        //std::cout<<"Ovo je velicina vzb: "<<velicina_vzb<<std::endl;
        int j(0);
        int brojac(0),brojac1(0);
        //int brojac_neki(0);
        std::set<std::string>pomocni;
        auto pomocni_neki=lista.begin();
        auto it=lista.begin();
        //for(auto it(lista.begin());it!=lista.end();it++) 
            while(brojac<=velicina_vzb) {
                if(brojac==velicina_vzb) {
                    break;
                }
            //std::cout<<"Ovo je it "<<*it<<std::endl;
            pomocni.insert(*it);
            brojac++;
            brojac1++;
            //std::cout<<"Brojac je "<<brojac<<std::endl;
            //std::cout<<"brojac1 je "<<brojac1<<std::endl;
            pomocni_neki=it;
            //std::cout<<"Ovo je pomocni: "<<*pomocni_neki<<std::endl;
            //int velicina=(*it).length();           ////ovdjee!!!!!!!!!!
            std::string s=*it;
            int velicina(0);
            for(int i=0;i<s.length();i++) {
                if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ||(s[i]>='0' && s[i]<='9')) {
                    velicina++;
                }
                
            }
            it=lista.erase(it);
            //std::cout<<"Ovo je velicina: "<<velicina<<std::endl;
            int i(1);
            while(i!=velicina) {
                if(it!=lista.end()) {
                it++;
                i++;
                if(it==lista.end()) {
                    it=lista.begin();
                }

            }
            else if(it==lista.end() && i!=velicina-2) {
                it=++lista.begin();
                i++;
                //i=velicina;
                
                
            }
            else { 
                it=++lista.begin();
                i=velicina;
            }
            }
            if(brojac1==vzb[j]) {
                j++;
                brojac1=0;
                v1.push_back(pomocni);
                 /*for(auto x: pomocni) {
            std::cout<<x<<" ";
        }*/
        //std::cout<<std::endl;
                pomocni.clear();
            }


            /*if(it==lista.end()) {
                it=lista.begin();
            }*/

        }
        //std::cout<<"Brojac je: "<<brojac;
        //v1.push_back(pomocni);
        //std::cout<<"Ovo je lista: "<<std::endl;
        //for(auto it=lista.begin();it!=lista.end();it++) {
        //std::cout<<*it<<" ";
        //}




    return v1;
}
int main ()
{ 
    //std::string s("Albus Percival Wulfric Brian");
    /*std::string s;
    std::getline(std::cin,s);
    std::cout<<s;
    std::vector<std::string>v;
    v.push_back(s);
    std::cout<<v.size();
    return 0;*/
    try {
    int broj_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    std::cin.ignore(10000,'\n');
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::vector<std::string>v;
    for(int i=0;i<broj_djece;i++) {
        std::string s;
        std::getline(std::cin,s);
        v.push_back(s);
    }
    int broj_timova;
    std::cout<<"Unesite broj timova: ";
    std::cin>>broj_timova;
    std::vector<std::set<std::string>>v1=Razvrstavanje(v,broj_timova);
    for(int i=0;i<v1.size();i++) {
        std::cout<<"Tim "<<i+1<<": ";
        int brojac(0);
       for(auto it(v1[i].begin());it!=v1[i].end();it++,brojac++) {
           std::cout<<*it;
           if(brojac!=v1[i].size()-1) {
               std::cout<<", ";
           }
       }
       std::cout<<std::endl;
    }
}
catch(std::logic_error izuzetak) {
    std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
}


	return 0;
}