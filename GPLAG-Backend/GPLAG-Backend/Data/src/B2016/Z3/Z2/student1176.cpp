#include<iostream>
#include<map> 
#include<set>
#include<string>
#include<stdexcept> 

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string tekst){
    std::map<std::string, std::set<int>> povratna; 
    int i;
    for(i=0; i<tekst.length(); ++i){
        tekst[i]=std::tolower(tekst[i]);
    } 
    for(int i(0); i<tekst.length(); ++i){
        std::string zamjena; 
        while(((tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='0' || tekst[i]<='9')) && i!=tekst.length()){
            zamjena.push_back(tekst[i]);
            i++;
        } 
        auto iter=povratna.find(zamjena); 
        if(povratna.end()!=iter) continue;
        else{ 
            int a(0);
            std::set<int> t;
            while(a<tekst.length()){
                a=tekst.find(zamjena, a);
                if(a<tekst.length()){
                    t.insert(a);
                    a++;
                }
            } 
            povratna.insert(std::pair<std::string, std::set<int>>(zamjena, t));
        }
    }  
    return povratna;
}  
std::set<int> PretraziIndeksPojmova(std::string tekst, std::map<std::string, std::set<int>> Map){
    if(Map.find(tekst)==Map.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    else return Map.find(tekst)->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> Map){
    for(auto iter=Map.begin(); iter!=Map.end(); iter++){
        std::cout << iter->first << ":";
        std::set<int> a=iter->second;
        int br=0;
        for(auto iter=a.begin(); iter!=a.end(); iter++){
            br++;
            std::cout << *iter;
            if(br!=a.size()) std::cout << ",";
            else std::cout << std::endl;
        }
    }
}

int main ()
{
	std::string tekst;
	std::string a;
	std::cout << "Unesite tekst: ";
	std::getline(std::cin, tekst);
	std::map<std::string, std::set<int>> Map;
	Map=KreirajIndeksPojmova(tekst); 
	IspisiIndeksPojmova(Map); 
	for(;;){
	    std::cout << "Unesite rijec:";
	    std::getline(std::cin, a);
	    if(a==".") break; 
	    try{
	        std::set<int> b=PretraziIndeksPojmova(a, Map);
	        int br(0);
	        for(auto iter=b.begin(); iter!=b.end(); iter++){
	            br++;
	             std::cout << *iter;
	             if(br!=b.size()) std::cout << ","; 
	             else std::cout << std::endl;
	        }
	    } 
	    catch(std::logic_error izuzetak){
	        std::cout << izuzetak.what() << std::endl;
	    }
	} 
	return 0;
}