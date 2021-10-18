/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>

bool jeliNeslovo(char c){
    if( (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9'))return false;
    return true;
}

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string v){
    std::string s = v;
    for(auto &x : s)if(x>='A' && x<='Z')x+=32;
    //std::cout<<s;
    std::map<std::string,std::set<int>> mapa;
    
    for(int i=0;i<s.length();i++){
        
        while(jeliNeslovo(s[i])){
            if(i==s.length())break;
            i++;
        }
        
        int j = i;
        while(jeliNeslovo(s[i]) == false){
            if(i==s.length())break;
            i++;
        }
        
        
        std::string temp = s.substr(j,i-j);
        if(jeliNeslovo(temp[0]))continue; //kad je na kraju znak 
        //std::cout<<"|"<<temp<<"|"<<std::endl;
        int postoji = 0;
        for(auto it = mapa.begin();it != mapa.end();it++){
            if(temp == it->first){
                postoji = 1;
                (it->second).insert((it->second).begin(),j);
            }
        }
        if(postoji == 0){
        mapa.insert(mapa.begin(),std::pair<std::string,std::set<int>>(temp,{j}));
        }
        
    }
    
    
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>> mapa){
    
    for(auto it = mapa.begin();it != mapa.end();it++){
            if(s == it->first){
                return it->second;
            }
        }
        
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa){
    
    
    for(auto it=mapa.begin();it!=mapa.end();it++){
        std::cout<<it->first<<": ";
        int vel = (it->second).size();
        auto prijekraja = (it->second).begin();
        for(int i=0;i<vel-1;i++)prijekraja++;                                                  
        for(auto p = (it->second).begin();p!=(it->second).end() ;p++){
            if(p!=prijekraja)std::cout<<*p<<",";
            else std::cout<<*p;
        }
        std::cout<<std::endl;
    }
    
}


int main ()
{
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
    
    auto mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    
    std::string temp;
    while(true){
        std::cout<<"Unesite rijec: ";
        std::cin>>temp;
        if(temp == ".")break;
        
        try{
            auto skup = PretraziIndeksPojmova(temp,mapa);
            auto it = skup.begin();
            for(int i=0;i<skup.size()-1;i++)it++;
            for(auto t = skup.begin();t!=skup.end();t++){
            if(t != it)std::cout<<*t<<" ";
            else std::cout<<*t;
            }
            std::cout<<std::endl;
        }catch(...){
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
    
    
	return 0;
}








