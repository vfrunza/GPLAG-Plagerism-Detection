/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <utility>

bool SlovoIliBroj(char s){
    if((std::tolower(s)>='a' && std::tolower(s)<='z') || (s>='0' && s<='9')) return true;
    else return false;
}

void IsprazniSet(std::set<int> &skup){
    auto it=skup.begin();
    while(skup.begin()!=skup.end()){
        it=skup.erase(it);
        
    }
}

typedef std::map <std::string,std::set<int>> indexpojmova;

std::map <std::string,std::set<int>>KreirajIndeksPojmova(std::string s)
{
    std::map <std::string,std::set<int>> mapa{};
    std::set<int> skup;
    std::string pomocni;
    int br(0);
    char kraj=s.size();
    for(int i=0;i<kraj;i++){
        if(SlovoIliBroj(s[i])) br++;
        s[i]=std::tolower(s[i]);
    }
    if(br==0) return mapa;
    for(int i=0;i<s.size();i++){
      //pomocni.resize(0);
      if(i==kraj)break;

       if(!SlovoIliBroj(s[i])){
            while(!SlovoIliBroj(s[i]))i++;
            if(i==kraj)break;
        }
      if(SlovoIliBroj(s[i])){
          IsprazniSet(skup);
          pomocni.resize(0);
        while(SlovoIliBroj(s[i])) {
            if(i==kraj)break;
            pomocni+=std::tolower(s[i]);
            i++;
        }
        //std::set<int> skup;
        for(int j=0; j<s.size(); j++)
            if(s.substr(j, pomocni.size())==pomocni && ((j==0 || !SlovoIliBroj(s[j-1])) && (j==s.size()-1 || !SlovoIliBroj(s[j+pomocni.size()])))) 
            skup.insert(j);
      
        mapa.insert(make_pair(pomocni,skup));
      }
    }
    return mapa;
}

std::set<int>PretraziIndeksPojmova(std::string s, indexpojmova mapa )
{
    for(int i=0;i<s.size();i++)
    s[i]=std::tolower(s[i]);
    std::set<int> m;
    auto it=mapa.find(s);
    if(it==mapa.end())throw std::logic_error("Unesena rijec nije nadjena!");
    for(auto it=mapa.begin();it!=mapa.end();it++){
       if(s==it->first) m= it->second;
    }
    return m;
}

void IspisiIndeksPojmova(const indexpojmova &mapa)
{
    for(auto it=mapa.begin();it!=mapa.end();it++){
    std::cout<<it->first<<": ";
    auto najveci=max_element(it->second.begin(),it->second.end());
    for(auto it1=it->second.begin(); it1!=it->second.end();it1++){
        if(*it1== *najveci){
                std::cout<<*it1;
            }
            else{
                std::cout<<*it1<<",";
            }
    }
    std::cout<<std::endl;
    }
}


int main ()
{

    std::map <std::string,std::set<int>> mapa;
    std::string n;
    std::cout<<"Unesite tekst: ";
    std::string s;
    getline(std::cin,s);
    mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    for(;;){
        std::cout<<"\nUnesite rijec: ";
        std::cin>>n;
        std::cin.ignore(1000,'\n');
        if(n==".") return 0;
        std::set<int> m;
        try{
        m=PretraziIndeksPojmova(n,mapa);
        //auto najveci=max_element(m.begin(),m.end());
        for(auto it=m.begin();it!=m.end();it++){
                std::cout<<*it<<" ";
        }
        std::cout<<std::endl;
        }
        catch(std::logic_error e){
            std::cout<<e.what();
        }
        
    }/*
    //AT16 (zamger): random stuff 
    auto m = KreirajIndeksPojmova("cvbkn34m5.n,34r67fgudbsc$%&/I()HVBNBn/&/&n///z&asdb23rgf87baew bfcQN3RCG3BR83O4NZTH");
    IspisiIndeksPojmova(m);
    auto skup = PretraziIndeksPojmova("n", m);
    for (const auto &c : skup) std::cout << c << " ";
*/
	return 0;
}