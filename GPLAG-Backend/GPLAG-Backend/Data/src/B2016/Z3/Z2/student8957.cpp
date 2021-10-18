/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <set>
#include <map>

bool DaLiJe (char c){
    if ((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')) 
        return false;
    return true;
}
std::string PretvoriUMala (std::string s){
    for (int i=0;i<s.length();i++){
        if (s[i]>='A' && s[i]<='Z')
            s[i]+='a'-'A';
    }
    return s;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s){
    std::map<std::string,std::set<int>> konacna;
    std::vector<std::string>v;
    std::string pomocni;
    s=PretvoriUMala(s);
    for (int i=0;i<s.length();i++){
        pomocni.resize(0);
        while (i<s.length() && ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))){
            pomocni.push_back(s[i]);
            i++;
        }
        if (pomocni.length()!=0) v.push_back(pomocni);
    }
    
    for (int i=0;i<v.size();i++){
        for (int j=i+1;j<v.size();j++){
            if(v[i]==v[j]){
                for (int k=j;k<v.size()-1;k++){
                    v[k]=v[k+1];
                }
                v.resize(v.size()-1);
                j--;
            }
        }
    }
    
    int k(0);
    std::string trenutna;
    
    for (int i=0;i<v.size();i++){
        trenutna=v[i];
        std::set<int> skup;
        for (int j=0;j<s.length();j++){
            k=0;
            while (j<s.length() && k<trenutna.length() && trenutna[k]==s[j]){
                k++;
                j++;
            }
            if ((k==trenutna.length() && j-k==0 && DaLiJe(s[j])) || (k==trenutna.length() && j==s.length() && DaLiJe(s[j-k-1])) || (k==trenutna.length() && DaLiJe(s[j]) && DaLiJe(s[j-k-1]))){
            skup.insert(j-k);
            }
        }
        konacna.insert(std::make_pair(trenutna,skup));
    }
    return konacna;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> mapa){
    std::set<int> skup;
    auto it(mapa.find(rijec));
    if (it==mapa.end()) throw std::logic_error ("Unesena rijec nije nadjena!");
    else skup=it->second;
    return skup;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa){
    int a(0);
    for (auto it=mapa.begin();it!=mapa.end();it++){
        std::cout<<it->first<<": ";
        a=0;
        for (auto it1=it->second.begin();it1!=it->second.end();it1++){
            if (a==0) 
                std::cout<<*it1;
            else 
                std::cout<<","<<*it1;
            a++;
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::string tekst;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, tekst);
    std::map<std::string, std::set<int>> mapa(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(mapa);
    std::string rijec;
    std::set<int> skup;
    do{
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if (rijec==".") break;
        try{
            skup=PretraziIndeksPojmova(rijec, mapa);
            for (auto it=skup.begin();it!=skup.end();it++)
                std::cout<<*it<<" ";
            std::cout<<std::endl;
        }
        catch (std::logic_error izuzetak){
            std::cout<<izuzetak.what()<<std::endl;
        }
        
    }while (rijec!=".");
	return 0;
}