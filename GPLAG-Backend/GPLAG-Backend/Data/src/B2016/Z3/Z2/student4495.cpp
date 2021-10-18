#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stdexcept>
#include <utility>

bool Uslov(char s){
    if(  (s>='a' && s<='z') || (s>='A' && s<='Z') || (s>='0' && s<='9') )
        return true;
    return false;    
}


void Mala(std::string &s){
    for(int i=0; i<s.length();i++)
        if((s[i]>='A' && s[i]<='Z'))
            s[i]+=32;
}
std::map<std::string,std::set<int>> KreirajIndeksPojmova (std::string s){
    std::map<std::string,std::set<int>> a;
    for(int i=0; i<s.length(); i++){
        bool prvi(false), drugi(false);
        std::string pomocni;
        std::set<int> p;
        while(Uslov(s[i])){
            prvi=true;
            pomocni.push_back(s[i]);
            i++;
        }
        for(int j=0; j<s.length();j++){
            unsigned int w=j;
            unsigned int k=0;
            while(j<s.length() && k<pomocni.length() && (s[j]==pomocni[k] || s[j]==pomocni[k]+32 || s[j]==pomocni[k]-32)){
                j++;k++;
                if( k==pomocni.length() && (w==0 || !Uslov(s[w-1])) &&  (j==s.length()|| !Uslov(s[j]))  ){
                    drugi=true;
                    p.insert(w);
                }
            }
        }
        if(prvi&&drugi){
            Mala(pomocni);
            a.insert(std::make_pair(pomocni,p));
        }
        
    }
    return a;
}
std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> m){
    auto p=m.find(s);
    if(p!=m.end())
        return (*p).second;
    throw std::logic_error("Unesena rijec nije nadjena!");    
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> m){
    for(auto p=m.begin(); p!=m.end(); p++){
        std::cout <<(*p).first<<": ";
        int br=0;
        for(auto i=(*p).second.begin(); i!=(*p).second.end(); i++){
            if(br++==(*p).second.size()-1)
                std::cout<<*i;
            else
                std::cout<<*i<<",";
        }        
        std::cout<<std::endl;        
    }
}

int main ()
{   
    std::string s;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin,s);
    auto a(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(a);
    while(true){
        std::string rijec;
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        try {
            auto lol =PretraziIndeksPojmova(rijec,a);
            for(auto i=lol.begin(); i!=lol.end(); i++)
                std::cout<<*i<<" ";
            std::cout <<std::endl;    
        }
        catch (std::logic_error error) {
            std::cout << error.what() << std::endl;
        }
        
    }
	return 0;
}