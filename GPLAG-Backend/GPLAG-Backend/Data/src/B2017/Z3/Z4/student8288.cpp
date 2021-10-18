/B2017/2018: Zadaaa 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <queue>
#include <stdexcept>

enum class Boje {Pik, Tref, Herc, Karo};

std::list<std::pair<Boje,std::string>> KreirajSpil() {

    std::list<std::pair<Boje,std::string>> pocetnalista;
    std::vector<std::string> Vrijednosti = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(int i{0};i<=3;i++)
        for(int j{0};j<13;j++) {
          if     (i == 0) pocetnalista.push_back(std::make_pair(Boje::Pik,Vrijednosti[j]));
          else if(i == 1) pocetnalista.push_back(std::make_pair(Boje::Tref,Vrijednosti[j]));
          else if(i == 2) pocetnalista.push_back(std::make_pair(Boje::Herc,Vrijednosti[j]));
          else if(i == 3) pocetnalista.push_back(std::make_pair(Boje::Karo,Vrijednosti[j]));
                                }
    return pocetnalista;
}

void IzbaciKarte(std::list<std::pair<Boje,std::string>> &lista,std::multimap<Boje, std::string> ovotrebaizbaciti){

    if(lista.size()>52 || lista.size()<0) throw std::logic_error("Neispravna lista!");
    auto drugi(lista.begin());
    drugi++;
    for(auto iteratorpolisti=lista.begin();iteratorpolisti!=lista.end();iteratorpolisti++) {
        if(!(drugi!=lista.end() && drugi->first > iteratorpolisti->first && drugi->second > iteratorpolisti->second))
         throw std::logic_error("Neispravna lista!");

    }
    std::vector<std::string> Vrijednosti = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(auto iteratorpolisti=lista.begin();iteratorpolisti!=lista.end();iteratorpolisti++) {

        if(!(iteratorpolisti->first==Boje::Tref ||iteratorpolisti->first==Boje::Herc || iteratorpolisti->first==Boje::Pik || iteratorpolisti->first==Boje::Karo))
        throw std::logic_error("Neispravna lista!");
        int brojac{0};
        for(auto it=Vrijednosti.begin();it!=Vrijednosti.end();it++) {
            if(iteratorpolisti->second == *it) brojac++;

        }
        if(brojac=0) throw std::logic_error("Neispravna lista!");
    }
    for(auto it(lista.begin());it!=lista.end();it++) {
        for(auto it2(ovotrebaizbaciti.begin());it2!=ovotrebaizbaciti.end();it2++) {

            if(it2->first==it->first)

            if(it2->second==it->second){

        lista.erase(it);
        ovotrebaizbaciti.erase(it2);
        it--;
        it2--;/* treba provjeriti brisanje*/
        }
      }
    }

}

std::queue<std::pair<std::string,std::string>>IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &spil,const short int &r,const int &b) {
      std::vector<std::string> boje{"Pik","Tref","Herc","Karo"};
      std::queue<std::pair<std::string,std::string>> red;

      std::vector<std::string> Vrijednosti = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
if(spil.size()>52 || spil.size()<0) throw std::logic_error("Neispravna lista!");
for(auto iteratorpolisti=spil.begin();iteratorpolisti!=spil.end();iteratorpolisti++) {
if(!( iteratorpolisti->first==Boje::Tref ||iteratorpolisti->first==Boje::Herc
     || iteratorpolisti->first==Boje::Pik || iteratorpolisti->first==Boje::Karo))
        throw std::logic_error("Neispravna lista!");
        int brojac{0};
        for(auto it=Vrijednosti.begin();it!=Vrijednosti.end();it++) {
            if(iteratorpolisti->second == *it) brojac++;

        }
        if(brojac=0) throw std::logic_error("Neispravna lista!");
    }
      if(r>52 || r<1 || b<1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
      auto it(spil.begin());
      int brojac {1},brojac2{0};

      int pocetnavelicinaspila(spil.size());
      while(brojac2!=b){
          if(brojac==r){
          std::string pom2;
          if(it->first==Boje::Pik)   pom2=boje[0];
          else if(it->first==Boje::Tref)  pom2 =boje[1];
          else if(it->first==Boje::Herc)  pom2=boje[2];
          else if(it->first==Boje::Karo)  pom2=boje[3];
          std::string pom(it->second);
          red.push(std::make_pair(pom2,pom));
          auto pomocni(it);
          pomocni--;
          spil.erase(it);
          it = pomocni;
          brojac2++;
          if(brojac2==pocetnavelicinaspila) break ;
          brojac=0;
          }
          brojac++;
          it++;
          if(it==spil.end()) it=spil.begin();
      }
      return red ;
  }




 void VratiPrvihNKarata(std::list<std::pair<Boje,std::string>> &spil,std::queue<std::pair<std::string,std::string>> &red,int n) {
     if(n<0)  throw std::domain_error("Broj n je besmislen!");
std::vector<std::string> Vrijednosti = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
     if(n>52-spil.size()) throw std::range_error("Nedovoljno karata u redu!");
     
     for(auto iteratorpolisti=spil.begin();iteratorpolisti!=spil.end();iteratorpolisti++) {
     if(!(iteratorpolisti->first==Boje::Tref ||iteratorpolisti->first==Boje::Herc ||
          iteratorpolisti->first==Boje::Pik || iteratorpolisti->first==Boje::Karo))
        throw std::logic_error("Neispravna lista!");

     int brojac{0};

        for(auto it=Vrijednosti.begin();it!=Vrijednosti.end();it++) {
            if(iteratorpolisti->second == *it) brojac++;


        }
        if(brojac=0) throw std::logic_error("Neispravna lista!");
     }
        while(n!=0){
      auto itk(spil.begin());
      bool nadjena=false ;
      Boje boja;
      if(red.front().first=="Pik")  boja=Boje::Pik;
      else if(red.front().first=="Tref") boja=Boje::Tref;
      else if(red.front().first=="Herc") boja=Boje::Herc;
      else if(red.front().first=="Karo") boja=Boje::Karo;
      for(auto it=itk;it!=spil.end();it++) {
          if(it->first==boja && it->second==red.front().second) {nadjena=true ;break ;}
         }

         if(!(nadjena)) {

            while(boja>itk->first){ if(itk == spil.end()) itk = spil.begin(); itk++; }

              int pombr(0);
              auto pomitk(itk);
              while(pomitk->first == boja) {pomitk++; pombr++;}

              int i (0);
              for(;i<Vrijednosti.size();i++){ if(Vrijednosti[i]==red.front().second) break ; }
              i = i - (Vrijednosti.size() - pombr - 1);
              while(i-->0) { if(itk == spil.end()) itk = spil.begin(); itk++; }


               std::pair<Boje,std::string> pomocni(std::make_pair(boja,red.front().second));
               spil.insert(itk,pomocni);
         }
        n--;
        red.pop();
      }


 }

 void IspisiSpil(const std::list<std::pair<Boje,std::string>> &spil) {
     
     //auto iter(spil.begin());
     //iter++;
     auto it(spil.begin());
     if(it->first==Boje::Pik) std::cout<<"Pik: "; while((it->first==Boje::Pik))
     {
         /*if(iter++!=spil.end()) */std::cout<<it->second<<" " ;
         //else if(iter++==spil.end()) std::cout<<it->second;
         if(it != spil.end()) it++;
     }
     std::cout<<std::endl;
     if(it->first==Boje::Tref) std::cout<<"Tref: "; while(it->first==Boje::Tref)
        {
            /*if(iter++!=spil.end())*/ std::cout<<it->second<<" " ;
            //else if(iter++==spil.end())*/ std::cout<<it->second;
            if(it != spil.end()) it++;
        }
     std::cout<<std::endl;
     if(it->first==Boje::Herc) std::cout<<"Herc: "; while(it->first==Boje::Herc)
        {
            /*if(iter++!=spil.end())*/ std::cout<<it->second<<" " ;
            //else if(iter++==spil.end()) */std::cout<<it->second;
            if(it != spil.end()) it++;
        }
     std::cout<<std::endl;
     if(it->first==Boje::Karo) std::cout<<"Karo: "; while(it->first==Boje::Karo)
        {
            /*if(iter++!=spil.end())*/ std::cout<<it->second<<" " ;
            //else if(iter++==spil.end())*/ std::cout<<it->second;
            if(it != spil.end()) it++;
        }
     std::cout<<std::endl;
 }
int main ()
{   int n,k;

    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>> n;
    
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    std::cin>> k;
     
    
    int s(52-k);
   
    try{
    
    auto a=KreirajSpil();
    auto red=IzbaciKarteRazbrajanjem(a,n,k);
    std::cout<<"U spilu trenutno ima "<<s<< " karata, i to:\n";
    IspisiSpil(a);
     
  std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
  int bttj;
  std::cin>>bttj;
  VratiPrvihNKarata(a,red,bttj);
  std::cout<<"U spilu trenutno ima "<<s+bttj<< " karata, i to:\n";
    
    IspisiSpil(a);
    }
    catch(std::logic_error s) {

    std::cout<<"Izuzetak: "<<s.what();

    }
    catch(std::domain_error k) {

    std::cout<<"Izuzetak: "<<k.what();
    }
    catch(std::range_error s) {

    std::cout<<"Izuzetak: "<<s.what();
    }
	return 0;
}



