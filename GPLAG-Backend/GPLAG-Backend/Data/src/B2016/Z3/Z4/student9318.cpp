/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <iterator>
#include <stdexcept>

std::vector<int>Napuni_velicinom(std::vector<std::string>vs, int timovi){
    std::vector<int>v;
    int n,k,prvi_timovi,cl_pt,ostali_timovi, cl_ost;
    k=timovi; n=vs.size();
    prvi_timovi=n%k; cl_pt=n/k + 1;
    ostali_timovi=k-prvi_timovi;  cl_ost=n/k;
    for(;;){
        if(prvi_timovi>0){
            while(prvi_timovi>0){
                v.push_back(cl_pt);
                prvi_timovi--;
            }
        }else{
            while(ostali_timovi>0){
             v.push_back(cl_ost);
             ostali_timovi--;
            }
        }
        if(prvi_timovi==0 && ostali_timovi==0) break;
    }
    return v;
}


std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vs,int timovi){
     std::list<std::string>lista;
     std::list<std::string>::iterator it;
     std::vector<std::set<std::string>> povratni;
     std::set<std::string> igraci;
     std::string pomocni;
     std::vector<int>v;
     v=Napuni_velicinom(vs,timovi);
    
    for(auto x: vs) lista.push_back(x); //prolazak kroz listu
    
     it=lista.begin();
     
     int br_v(0),brojac(0),br_slova(0),slova(0);
     
     for(;;){
         if(lista.size()==0) break;
         while(br_slova--){
             it++;
             if(it==lista.end()) it=lista.begin();
         }
         pomocni=(*it); 
         std::list<std::string>::iterator it1(it);
         it++;
         if(it==lista.end()) it=lista.begin();
         for(int i=0; i<pomocni.size(); i++){
         if((pomocni[i]>='a' && pomocni[i]<='z') || (pomocni[i]>='A' && pomocni[i]<='Z') || (pomocni[i]>='0' && pomocni[i]<='9')) slova++;
        } 
        br_slova=slova-1; //it se poveca za 1, ne zaboravi izbrisati
         lista.erase(it1);//povecanje
         brojac++;
         igraci.insert(pomocni); 
        
         if(v[br_v]==brojac){
             povratni.push_back(igraci);
             igraci.clear();
             br_v++;
             brojac=0;
         }
         slova=0;
         
     }
     return povratni;
}
void Ispisi(std::vector<std::set<std::string>> vektor){
    std::vector<std::set<std::string>>::iterator it;
    std::set<std::string>::iterator it1;
    std::set<std::string>::iterator it2;
    std::set<std::string> ite;
     it=vektor.begin();
    int brojac=0;
    for(auto i=it; i!=vektor.end(); i++){
        brojac++;
        ite=*i;
        it2=ite.end();
        it2--;
        std::cout<<"Tim "<<brojac<<": ";
    for(it1=ite.begin(); it1!=ite.end(); it1++){
        if(it1!=it2) std::cout<<*it1<<", ";
        else std::cout<<*it1<<std::endl;
        }
    }
}
int main (){
    try{
    std::vector<std::string>vs;
    int broj_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::string pomocni;
    int br(broj_djece);
    std::cin.ignore(10000,'\n');
    std::cin.clear();
    for(int i=0; i<br; i++){
        std::getline(std::cin,pomocni);
        vs.push_back(pomocni);
    }
     int broj_timova;
    std::cout<<"Unesite broj timova: ";
    std::cin>>broj_timova;
    if(broj_timova<1 || broj_timova>broj_djece) throw std::logic_error("Razvrstavanje nemoguce.");
    std::vector<std::set<std::string>> vektor;
    vektor=Razvrstavanje(vs,broj_timova);
    Ispisi(vektor);
}catch(std::logic_error e){
        std::cout<<e.what();
    }
	return 0;
}