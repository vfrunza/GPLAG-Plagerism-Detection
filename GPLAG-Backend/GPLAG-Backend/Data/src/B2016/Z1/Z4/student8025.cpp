#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
std::string ObrniFraze(std::string recenica, std::vector<std::string> v){
    int poc(0),h(0),kraj(0),g(0);
    std::string s;
    std::string zamjena[100];
    std::string zamjene[100];
   s=recenica;
    for(int i=0; i<v.size(); i++){
            zamjena[i]=v[i];
    }
    for(int i=0; i<v.size(); i++){
    for(int j=zamjena[i].size()-1; j>=0; j--){
        zamjene[i].push_back((zamjena[i])[j]);
    }
    }
   for(int z=0; z<v.size(); z++){
       for(int i=0; i<recenica.length(); i++){
           h=0;
       for(int j=0; j<zamjena[z].length(); j++ ){
           if(h!=0) break;
           if( s[i]==(zamjena[z])[j] ){
               poc=i;
               while(j<zamjena[z].length() && (zamjena[z])[j]==s[i] && i<recenica.length()){
                   i++;
                   if(j==zamjena[z].length()-1){
                       kraj=i;
                       g=0;
                       for(int i=poc; i<kraj; i++){
                        s[i]=(zamjene[z])[g];
                        g++;
                       }
                       i=poc;
                       break;
                   }
                   
                   j++;
                   if((zamjena[z])[j]!=s[i]){
                       i--;
                       h++;
                       break;
                   } 
               }
           } else if(s[i]!=(zamjena[z])[j]){
               break;
               
           }
       }
       }
    }
    return s;
}
std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v){
    int brojac(0),n(0);
    std::string recenica;
    std::string stari[100];
    std::vector<std::string>drugi;
    std::string novi[100];
    std::string zamjena[100];
    drugi=v;
    if(v.size()==0){
        
        for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            novi[brojac].push_back(s[i]);
            brojac++;
        }
        while(s[i]!=' ' && s[i]!=',' && s[i]!='.' && i<s.length()){
            novi[brojac].push_back(s[i]);
            i++;
            if(s[i]==' ' || s[i]==',' || s[i]=='.'){
                brojac++;
                novi[brojac].push_back(s[i]);
                brojac++;
            }
        }
    }
 
         for(int i=0; i<s.length(); i++){
        while(s[i]!=' ' && s[i]!=',' && s[i]!='.' && i<s.length()){
            stari[n].push_back(s[i]);
            i++;
            if(s[i]==' ' || s[i]==',' || s[i]=='.'){
                n++;
            }
        }
    }
       for(int i=0; i<=n; i++){
        for(int j=1; j<stari[i].size(); j++){
            zamjena[i].push_back((stari[i])[j]);
        }
        zamjena[i].push_back((stari[i])[0]);
        zamjena[i].push_back('a');
        zamjena[i].push_back('y');
    }  
        for(int i=0; i<=brojac; i++){
            for(int j=0; j<=n; j++){
                if(novi[i]==stari[j]){
                    novi[i]=zamjena[j];
                }
            }
        }
        for(int i=0; i<=brojac; i++){
            recenica+=novi[i];
        }
        
        return recenica;
        
    }
       for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].length(); j++){
            if( !( ((v[i])[j]>='a' && (v[i])[j]<='z') || ((v[i])[j]>='A' && (v[i])[j]<='Z') ) ){
                throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
            }
        }
    }
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            novi[brojac].push_back(s[i]);
            brojac++;
        }
        while(s[i]!=' ' && s[i]!=',' && s[i]!='.' && i<s.length()){
            novi[brojac].push_back(s[i]);
            i++;
            if(s[i]==' ' || s[i]==',' || s[i]=='.'){
                brojac++;
                novi[brojac].push_back(s[i]);
                brojac++;
            }
            
        }
        
        
        
        
    }
    for(int i=0; i<v.size(); i++){
        for(int j=1; j<v[i].size(); j++){
            zamjena[i].push_back((drugi[i])[j]);
        }
        zamjena[i].push_back((drugi[i])[0]);
        zamjena[i].push_back('a');
        zamjena[i].push_back('y');
    }
             
     for(int i=0; i<=brojac; i++){
         for(int j=0; j<v.size(); j++){
           if(novi[i]==v[j])  {
               novi[i]=zamjena[j];
           }
         }
     }
          for(int i=0; i<=brojac; i++){
              recenica+=novi[i];
          }  
          
             return recenica;
         }

int main ()
{
    int g(-1);
    std::vector<std::string>v(30);
    std::string recenica;
    std::string rijec;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,recenica);
    std::cout<<"Unesite fraze: ";
    do{
        g++;
        std::getline(std::cin,rijec);
        v[g]=rijec;
    }while(v[g].length()!=0);
    std::vector<std::string>a(g);
    for(int i=0; i<g; i++){
        a[i]=v[i];
    }
    std::string ispis;
   try{
    ispis=IzmijeniUPigLatin(recenica,a);
    std::cout<<"Recenica nakon PigLatin transformacije: ";
    std::cout<<ispis;
   }catch(std::domain_error izuzetak){
       std::cout<<izuzetak.what();
   }
    std::cout<<std::endl;
    std::cout<<"Recenica nakon obrtanja fraza: ";
    ispis=ObrniFraze(recenica,a);
    std::cout<<ispis;
	return 0;
}