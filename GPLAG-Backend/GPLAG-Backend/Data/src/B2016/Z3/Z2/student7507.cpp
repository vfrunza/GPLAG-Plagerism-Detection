/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
#include <cctype>
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> mapa;
    std::map<std::string,std::set<int>>::iterator it;
    int pozicija=-1;
    for(int i=0; i<s.length(); i++){
        std::string s1;
        s1.resize(0);
        std::set<int> skup;
        int poz,poz1;
        pozicija++;
        if((s[pozicija]>=32 && s[pozicija]<=47) || (s[pozicija]>=58 && s[pozicija]<=64) ||(s[pozicija]>=91 && s[pozicija]<=96) || (s[pozicija]>=123 && s[pozicija]<=126)){
            while(pozicija<s.length() && ((s[pozicija]>=32 && s[pozicija]<=47) || (s[pozicija]>=58 && s[pozicija]<=64) ||(s[pozicija]>=91 && s[pozicija]<=96) || (s[pozicija]>=123 && s[pozicija]<=126))){
                //std::cout<<"s= "<<s[pozicija]<<" i= "<<i<<std::endl;
                pozicija++;
                i++;
                
            }
        }
        if(pozicija < s.length() && ((s[pozicija]>='a' && s[pozicija]<='z') || (s[pozicija]>='A' && s[pozicija]<='Z') || (s[pozicija]>='0' && s[pozicija]<'9'))){
        //std::cout<<"pozicija: "<<pozicija<<" i= "<<i<<std::endl;
        poz1=pozicija;
        while(i<s.length() && ((s[i]>='A' && s[i]<='Z')|| (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))){
            if(s[i]>='A' && s[i]<='Z') s1.push_back(s[i]+32);
            else s1.push_back(s[i]);
            //std::cout<<"s1 u petlji: "<<s1;
            i++;
            pozicija++;
        }
        
        //std::cout<<"s1= "<< s1 <<std::endl;
        if((s[i]>=32 && s[i]<=47) || (s[i]>=58 && s[i]<=64) || (s[i]>=91 && s[i]<=96) || (s[i]>=123 && s[i]<=126) || i==s.length()){
            skup.insert(poz1);
            poz = pozicija;
            //std::cout<<"po: "<<poz<<std::endl;
            std::string p=s;
            int j=i;
            while(j<s.length()){
                    if(p[j]==' ' || (p[j]>=32 && p[j]<=47) || (p[j]>=58 && p[j]<=64) || (p[j]>=91 && p[j]<=96) || (p[j]>=123 && p[j]<=126)){
                        while(p[j]==' ' || (p[j]>=32 && p[j]<=47) || (p[j]>=58 && p[j]<=64) || (p[j]>=91 && p[j]<=96) || (p[j]>=123 && p[j]<=126)) { j++; poz++;}
                    }
                    //std::cout<<"poz= "<<poz<<std::endl;
                    int k=0;
                    if((std::toupper(p[j])==std::toupper(s1[k])) && (p[j-1]==' ' || (p[j-1]>=32 && p[j-1]<=47) || (p[j-1]>=58 && p[j-1]<=64) || (p[j-1]>=91 && p[j-1]<=96) || (p[j-1]>=122 && p[j-1]<=126))){
                        int poz2=poz;
                        while(j<s.length() && k<s1.length() && std::toupper(p[j])==std::toupper(s1[k])){
                            j++; k++; poz++;
                        }
                        if((j==s.length() || p[j]==' ' || (p[j]>=32 && p[j]<=47) || (p[j]>=58 && p[j]<=64) || (p[j]>=91 && p[j]<=96) || (p[j]>=123 && p[j]<=126)) && k==s1.length() ) skup.insert(poz2);
                    }
                    if(j<s.length()-1) {
                        j++;
                        poz++;
                    }
                    else break;
                }
            }
        }
        //std::cout<<"s1= "<<s1<<std::endl;
        if(mapa.count(s1)!=1){
            if(s1.size()!=0){
                mapa[s1]=skup;
            }
        }
        /*for(auto x: skup){
            std::cout<<"x: "<<x<<std::endl;
        }*/
    }
   /* for(auto it=mapa.begin(); it!=mapa.end(); it++){
                std::cout<<"skup: ";
                for(auto x: it->second){
                    std::cout<<" "<<x;
                }
                std::cout<<std::endl;
            }*/
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa){
    std::set<int> skup;
    auto it(mapa.find(s));
    if(it!=mapa.end()) skup=it->second;
    else if(it==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!\n");
    return skup;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        std::cout<<it->first<<": ";
        //auto it2=it->second.end();
        //it2--;
        int br=it->second.size();
        for(auto it1=it->second.begin(); it1!=it->second.end(); it1++){
            std::cout<<*it1;
            if(br>1) std::cout<<",";
            br--;
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin,s);
    std::map<std::string, std::set<int>> mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    std::string rijec;
    while(rijec!="."){
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec==".") break;
        try{
            std::set<int> skup=PretraziIndeksPojmova(rijec,mapa);
            for(auto x: skup){
                std::cout<<x<<" ";
            }
            std::cout<<std::endl;
        }
         catch(std::logic_error e){
            std::cout<<e.what();
        }
        
    }
   
	return 0;
}