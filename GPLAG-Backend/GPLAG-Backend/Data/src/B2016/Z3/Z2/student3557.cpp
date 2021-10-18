#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <utility>
#include <set>

std::string PretvoriSlova(std::string s) {
    for(int i=0; i<s.length(); i++) {
        if(s[i] >='A' && s[i] <='Z') s[i] +=32;
    }
    return s;
}

std::map <std::string, std::set<int>> KreirajIndeksPojmova (const std::string &s) {
    
    std::map <std::string, std::set<int>> mapa_rijeci;
    std::string rijec;
    
    int p(0), k(0), p1(0), k1(0);
   for(int i=0; i<s.length(); i++) {
       if (i<s.length() && ((s[i]>=32 && s[i]<=47) || (s[i]>=58 && s[i]<=64) ||(s[i]>=91 && s[i]<=96) || (s[i]>=123 && s[i]<=126))) {
           
     while (i <s.length() && ((s[i]>=32 && s[i]<=47) || (s[i]>=58 && s[i]<=64) ||(s[i]>=91 && s[i]<=96) || (s[i]>=123 && s[i]<=126))) {i++;}}
    
       if(i<s.length() && (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >='a' && s[i] <= 'z')) {
         p = i;
         rijec.resize(0);
           while( i<s.length() && ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >='a' && s[i] <= 'z'))) { rijec +=s[i]; i++; }
         k=i;     }

     
      std::set<int> skup;
      
     if(!mapa_rijeci.count(rijec)) {

         for(int j=0; j<s.length(); j++) {
             std::string rijec1{};
         
         if (j <s.length() && ((s[j]>=32 && s[j]<=47) || (s[j]>=58 && s[j]<=64) ||(s[j]>=91 && s[j]<=96) || (s[j]>=123 && s[j]<=126)))
          { 
              while (j <s.length() && ((s[j]>=32 && s[j]<=47) || (s[j]>=58 && s[j]<=64) ||(s[j]>=91 && s[j]<=96) || (s[j]>=123 && s[j]<=126))) j++; }

       if(j<s.length() && (s[j] >= '0' && s[j] <= '9') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >='a' && s[j] <= 'z')) {
         p1 = j;
 
       while (j<s.length() && ((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >='a' && s[j] <= 'z'))) { rijec1 += (s[j]); j++; }}
         k1 = j;    

    if(PretvoriSlova(rijec) == PretvoriSlova(rijec1)) {
        skup.insert(p1);
    }
    
     }
     if(rijec.size() > 0)
     mapa_rijeci.insert(std::make_pair(PretvoriSlova(rijec), skup));
}
   }
    return mapa_rijeci;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map <std::string, std::set<int>> mapa) {
    if(!mapa.count(rijec)) throw std::logic_error("Unesena rijec nije nadjena!\n");
    else 
        for(auto it = mapa.begin(); it != mapa.end(); it++)
            if(it->first == rijec) return it->second;
}

void IspisiIndeksPojmova(std::map <std::string, std::set<int>> mapa) {
   
    for(auto it = mapa.begin(); it != mapa.end(); it++) {
 std::cout << it->first << ": " ;
 auto pomocni = (it->second.end());
 pomocni--;

 for(auto it1 = (it->second.begin()); it1 != (it->second.end()); it1++){
     std::cout << *it1;
  if(it1 != pomocni)  std::cout  <<",";
 } 
 std::cout << std::endl;
}
}

int main ()
{
    std::string s, rijec;
    std::cout <<"Unesite tekst: ";
    std::getline(std::cin, s);
    
    auto mapa = (KreirajIndeksPojmova(s));
    
    IspisiIndeksPojmova(mapa);
    
    for(;;) {
        std::set<int> skup_indeksa;
        std::cout << "\nUnesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec == ".") break;
        try {
        skup_indeksa = (PretraziIndeksPojmova(rijec, mapa));
        } catch(std::logic_error izuzetak) {
        std::cout<< izuzetak.what();
    }
        for(auto x: skup_indeksa) std::cout << x << " ";
    }
   
	return 0;
}

/*
std::map <std::string, std::set<int>> KreirajIndeksPojmova (const std::string &s) {
    std::string rijec;
    std::map <std::string, std::set<int>> mapa_rijeci;
    
    int p, k, p1, k1;
   for(int i=0; i<s.length(); i++) {
      if(s[i] ==' ' || s[i] =='\t') { while(s[i] ==' ' || s[i] =='\t') i++; }
    
       if(s[i] !=' ' || s[i] !='\t') {
         p = i;
        
           while(s[i] !=' ' && i<s.length()) i++; 
         k=i;     }
    
     rijec = (s.substr(p, k-p));
      std::set<int> skup;
     if(!mapa_rijeci.count(rijec)) {
         for(int j=0; j<s.length(); j++) {
      if(s[j] ==' ' || s[j] =='\t') { while(s[j] ==' ' || s[j] =='\t') j++; }
       if(s[j] !=' ' || s[j] !='\t') {
         p1 = j;
           while(s[j] !=' ' && j<s.length()) j++; 
         k1=j;    
         }
       
    if(PretvoriSlova(rijec) == PretvoriSlova(s.substr(p1, k1-p1))) {
        skup.insert(p1);
    }
    
     }
     mapa_rijeci.insert(std::make_pair(PretvoriSlova(rijec), skup));
}
   }
    return mapa_rijeci;
}

*/

/*
std::map <std::string, std::set<int>> KreirajIndeksPojmova (const std::string &s) {
    std::string rijec;
    std::map <std::string, std::set<int>> mapa_rijeci;
    
    int p, k, p1, k1;
   for(int i=0; i<s.length(); i++) {
       if (i <s.size() && ((s[i]>=32 && s[i]<=47) || (s[i]>=58 && s[i]<=64) ||(s[i]>=91 && s[i]<=96) || (s[i]>=123 && s[i]<=126)))
  //    if(!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >='a' && s[i] <= 'z')))
  { while (i <s.size() && ((s[i]>=32 && s[i]<=47) || (s[i]>=58 && s[i]<=64) ||(s[i]>=91 && s[i]<=96) || (s[i]>=123 && s[i]<=126))) i++;}
//     { while(!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >='a' && s[i] <= 'z'))) i++; }
    
       if(i<s.length() && (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >='a' && s[i] <= 'z')) {
         p = i;
        
           while( i<s.length() && ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >='a' && s[i] <= 'z'))) i++; 
         k=i;     }
    
     rijec = (s.substr(p, k-p));
     
      std::set<int> skup;
      
     if(!mapa_rijeci.count(rijec)) {
         
         for(int j=0; j<s.length(); j++) {
         
        //  if(j < s.length() && !((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >='a' && s[j] <= 'z'))) 
         if (j <s.size() && ((s[j]>=32 && s[j]<=47) || (s[j]>=58 && s[j]<=64) ||(s[j]>=91 && s[j]<=96) || (s[j]>=123 && s[j]<=126)))
          { 
              while (!((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >='a' && s[j] <= 'z'))) j++; }
    
       if(j<s.length() && (s[j] >= '0' && s[j] <= '9') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >='a' && s[j] <= 'z')) {
         p1 = j;
        
       //    while(j<s.length() && (((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >='a' && s[j] <= 'z') ) )) j++; 
       while( j<s.length() && ((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >='a' && s[j] <= 'z'))) j++; 
         k1 = j;    }

   std::string rijec2 = (s.substr(p1, k-p1));    
    if(PretvoriSlova(rijec) == PretvoriSlova(s.substr(p1, k1-p1))) {
        skup.insert(p1);
    }
    
     }
     if(rijec.size() > 0)
     mapa_rijeci.insert(std::make_pair(PretvoriSlova(rijec), skup));
}
   }
    return mapa_rijeci;
}
*/