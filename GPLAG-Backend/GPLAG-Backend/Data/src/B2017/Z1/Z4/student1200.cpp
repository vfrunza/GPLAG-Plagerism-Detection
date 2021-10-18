#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdexcept>

std::string NapraviRazmak(std::string s){
    std::string srazmakom(s);
    srazmakom.append(" ");
    return srazmakom;
}

std::string UkloniRazmak(std::string s){
    return s.substr(0,s.length()-1);
}

std::string Zadnja(std::string s) {
  auto index = s.find_last_of(' ');
  std::string last_word = s.substr(++index);
  return last_word;
}


std::string NapraviPalindrom(std::string p, std::vector<std::string> vs){
    if(vs.size()==0) throw p;
    std::string s=NapraviRazmak(p);
    for(int i=0; i<vs.size(); i++){
        std::string razmak=NapraviRazmak(vs.at(i));
            std::size_t f=s.find(razmak);
            if(f==std::string::npos) continue;
            std::string kopija(vs.at(i));
            std::reverse(kopija.begin(),kopija.end());
            s.insert(f+vs.at(i).size(),kopija);
            std::size_t f2=s.find(razmak,f+vs.at(i).size());
            if(f2!=f && f2!=std::string::npos){
            s.insert(f2+vs.at(i).size(),kopija);
            }
            std::size_t f3=s.rfind(razmak);
            if(f3!=f && f3!=f2 && f3!=std::string::npos){
            s.insert(f3+vs.at(i).size(),kopija);
            }
    }
    return UkloniRazmak(s);
}

std::string NapraviPoluPalindrom(std::string p, std::vector<std::string> vs){
    if(vs.size()==0) throw p;
    std::string s=NapraviRazmak(p);
    for(int i=0; i<vs.size(); i++){
            std::string razmak=NapraviRazmak(vs.at(i));
            std::size_t f=s.find(razmak);
            if(f==std::string::npos) continue;
            std::string pods=vs.at(i).substr(0,vs.at(i).length()/2);
            std::reverse(pods.begin(),pods.end());
            if(vs.at(i).length()%2==0){
            s.replace(f+vs.at(i).length()/2,vs.at(i).length()/2,pods);
            }else s.replace(f+vs.at(i).length()/2+1,vs.at(i).length()/2,pods);
            std::size_t f2=s.find(razmak,f+vs.at(i).size());
            if(f2!=f && f2!=std::string::npos){
            if(vs.at(i).length()%2==0){
            s.replace(f2+vs.at(i).length()/2,vs.at(i).length()/2,pods);
            }else s.replace(f2+vs.at(i).length()/2+1,vs.at(i).length()/2,pods);
            }
            std::size_t f3=s.rfind(razmak);
            if(f3!=f && f3!=f2 && f3!=std::string::npos){
            if(vs.at(i).length()%2==0){
            s.replace(f3+vs.at(i).length()/2,vs.at(i).length()/2,pods);
            }else s.replace(f3+vs.at(i).length()/2+1,vs.at(i).length()/2,pods);
            }
        
    }
    return UkloniRazmak(s);
}

int main ()
{
    
    std::string s,ss;
    std::vector<std::string> vs;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,s);
    std::cout<<"Unesite fraze: ";
    while(std::cin.peek()!='\n'){
    std::cin.peek();
    std::getline(std::cin,ss);
    vs.push_back(ss);
    }
    try{
    std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(s,vs)<<std::endl;
    std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(s,vs);
    }
    catch(std::string s){
    std::cout<<"Recenica nakon Palindrom transformacije: "<<s<<std::endl;
    std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<s;
    }
	return 0;
}