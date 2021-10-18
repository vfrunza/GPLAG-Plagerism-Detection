/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <stdexcept>
#include <iterator>
int brojslova(std::string rijeci){
    int brojac(0);
    for(int i=0;i<rijeci.size();i++){
        while(rijeci[i]==' '|| rijeci[i]=='-')i++;
        while(i<rijeci.size() && rijeci[i]!=' '&& rijeci[i]!='-'){
            brojac++;
            i++;
        }
    }
    return brojac;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int timovi){
    if(timovi<1 || timovi>djeca.size())throw std::domain_error("Razvrstavanje nemoguce");
    std::list<std::string> listadjece;
    for(auto i=djeca.begin();i!=djeca.end();i++){
        listadjece.push_back(*i);
    }
    bool prviput(true);
    std::vector<std::set<std::string>>lista;
    int brojclanova=listadjece.size()/timovi +1;
    int brojtim=listadjece.size()%timovi;
    int broj2=timovi-brojclanova-1;
  ///  for(int i=0;i<broj-1;i++)lista[i].resize(broj);
  //  for(int i=broj-1;i<timovi;i++)lista[i].resize(broj2);
  
    auto i=listadjece.begin();
    auto novi=i;
    int a=0;
     while(i!=listadjece.end()){
            std::set<std::string> tim;
            for(int k=0;k<brojclanova;k++){
                    if(prviput==true){
                    tim.insert(*i);
                    int brojac(brojslova(*i));
                    i = listadjece.erase(i);
                    //auto spasi=i;
                    std::advance(i, brojac-1);
                    prviput=false;
                }
                else if(prviput==false){
                    tim.insert(*i);
                    int brojac(brojslova(*i));
                    //auto spasi=i;
                    auto kraj=listadjece.end();
                    if(std::distance(kraj,i)>brojac){ i=listadjece.erase(i); std::advance(i, brojac-1);}
                    else if(std::distance(kraj,i)<brojac){
                        i=listadjece.erase(i);
                        int broj=std::distance(kraj, i);
                        broj=brojac-broj;
                        auto neki=listadjece.begin();
                        std::advance(neki, broj+1);
                    }
                    else if(std::distance(kraj,i)==brojac){auto spasi=listadjece.erase(i); i=listadjece.begin();}
                    //spasi=listadjece.erase(spasi);
                    if(listadjece.size()==0)return lista;
                    //if(i!=listadjece.end())i++;
                    //else i=listadjece.begin();
            
        }
      // if(i==listadjece.end())i=listadjece.begin();
    }
    lista.push_back(tim);
    a++;
    if(a=brojtim){ novi=i;break;} 
}

/*}
for(int j=0;j<timovi-brojtim;j++){
            std::set<std::string> tim;
            for(int k=0;k<brojclanova;k++){
                 while(i!=listadjece.end()){
                    if(prviput==true){
                    tim.insert(*i);
                    int brojac(brojslova(*i));
                    i = listadjece.erase(i);
                    std::advance(i, brojac-1);
                    prviput=false;
                    if(i!=listadjece.end())i++;
                }
                else if(prviput==false){
                    tim.insert(*i);
                    int brojac(brojslova(*i));
                    //auto spasi=i;
                    auto kraj=listadjece.end();
                    if(std::distance(kraj,i)>brojac){ i=listadjece.erase(i); std::advance(i, brojac);}
                    else if(std::distance(kraj,i)<brojac){
                        i=listadjece.erase(i);
                        int broj=std::distance(kraj, i);
                        broj=brojac-broj;
                        auto neki=listadjece.begin();
                        std::advance(neki, broj);
                    }
                    else if(std::distance(kraj,i)==brojac){auto spasi=listadjece.erase(i); i=listadjece.begin();}
                    //spasi=listadjece.erase(spasi);
                    if(listadjece.size()==0)return lista;
                    if(i!=listadjece.end())i++;
            
        }
       if(i==listadjece.end())i=listadjece.begin();
    }
}
lista.push_back(tim);
}*/
    return lista;
}
int main ()
{
     
    try{
        int n;
        std::cout<<"Unesite broj djece: ";
        std::cin>>n;
        std::cin.ignore(10000,'\n');
        std::vector<std::string>djeca(n);
        std::cout<<"Unesite imena djece: ";
        for(int i=0;i<djeca.size();i++){
            std::string djete;
            std::getline(std::cin, djeca[i]);
        }
        std::cout<<"\nUnesite broj timova: ";
        int timovi;
        std::cin>>timovi;
        std::vector<std::set<std::string>>djecica(Razvrstavanje(djeca, timovi));
        int broj(0);
        for(int i=0;i<djecica.size();i++){
            std::cout<<"Tim "<<broj+1<<": ";
            broj++;
            for(auto x:djecica[i])std::cout<<" "<<x;
        
        std::cout<<std::endl;
        }
    }catch(std::domain_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}