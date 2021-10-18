#include<iostream>
#include<string>
#include<map>
#include<set>
#include<stdexcept>
#include<utility>
#include<vector>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    
    std::map<std::string, std::set<int>> TempMap;
    std::set<int> Set;
    std::string TempStr;  
    std::vector<std::string> Vektor;
    
    for(int i=0; i<s.length(); i++){                                              //Petlja cije je svrha da potencijalnu pojavu velikih slova pretvori u mala slova
        if(s[i]>='A' && s[i]<='Z') 
            s[i]+=32;
    }
    
    for(int i=0; i<s.length(); i++){  
    int br(0);
       if(s[i]!=' '){                                                             //string koji pamti rijec
           TempStr.push_back(s[i]);
       }
       
       if(TempStr.size()>0 && (s[i]==' ' || i==int(s.length())-1)){            
           
           for(int j=0; j<s.length(); j++){                                       //Oformisati skup brojeva koji ukazuju na mjesta pojavljivanja rijeci
              int p(j);
              
              if(s[j]==TempStr[0]){
                  bool X(true);
                  
                  if(p!=0){
                      if(s[p-1]!=' ') X=false;
                  }
                  for(int k=1; k<int(TempStr.length()); k++){
                      p++;
                      if(s[p]!=TempStr[k] || s[p]==int(s.length())-1){
                          X=false;
                          break;
                      } 
                  }
                  
                  if(X==true) 
                      Set.insert(br);
                }
               
              br++;
           }
           
           if(TempMap.count(TempStr)==0)                                          //Ukoliko se pronadjena rijec prethodno vec ne nalazi u mapi, smjesti u mapu tu rijec zajedno sa skupom brojeva koji sadrzi pozicije pojavljivanja te rijeci u pocetnom stringu
                TempMap.insert(std::make_pair(TempStr, Set));
           
           TempStr.resize(0);                                                     //Isprazni pomocni string za pamcenje jedne rijeci
           while(!Set.empty()){                                                   //Isprazni skup 
               Set.erase(Set.begin());
           }
       }
    }
    
    return TempMap;                                                               //Vrati mapu
}

std::set<int> PretraziIndeksPojmova (std::string s, std::map<std::string, std::set<int>> indekspojmova){
    if (indekspojmova.count(s)!=1) throw std::logic_error("Unesena rijec nije nadjena!");
    else return indekspojmova.find(s)->second;
    
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> MapaPojmova){
    
    for(auto x: MapaPojmova){
        auto MaxEl(0);
        std::cout<<x.first<<": ";
        for(auto y: x.second) if(y>MaxEl) MaxEl=y;
            
            for(auto y: x.second){
                if(y==MaxEl) std::cout<<y;
                else std::cout<<y<<",";
            }
            
        std::cout<<std::endl;
    }
}

int main ()
{
    std::string S;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, S);
    
    auto PovratnaMapa(KreirajIndeksPojmova(S));
    IspisiIndeksPojmova(PovratnaMapa);
    std::string pom;
    
    for(;;){
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, pom);
        
        if(pom[0]=='.' && pom.length()==1) break;
        
        try{
            auto pomocno(PretraziIndeksPojmova(pom, PovratnaMapa));
            for(auto a: pomocno){
                std::cout<<a<<" ";
            }
            std::cout<<std::endl;
        }
        catch(std::logic_error uhvati){
            std::cout<<uhvati.what()<<std::endl;
        }
        pom.clear();  
    }
	return 0;
}