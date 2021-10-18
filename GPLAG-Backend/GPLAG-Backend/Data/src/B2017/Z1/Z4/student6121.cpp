#include <iostream>
#include <string>
#include <vector>

std::string NapraviPoluPalindrom (std::string s , std::vector<std::string>v) {
   for(int i=0; i<s.size(); i++) {
       for(int j=i+1; j<s.size(); j++) {
           std::string pomocni;
         int k=0;
           for( k=i; k<=j; k++) pomocni.push_back(s.at(k));
           for(int l=0; l<v.size(); l++){
               if(v.at(l)==pomocni) {
              if(k==s.size()|| (k<s.size() && (s.at(k)<'A' || (s.at(k)>'Z' && s.at(k)<'a') || s.at(k)>'z'))) {
                   int vel=pomocni.size();
                   int l=0;
                   for(int m=i+vel-1; m>=i+vel/2; m--) {
                       s.at(m)=s.at(i+l);
                       l++;
                   }
              }
               }
           }
       }
   }
    return s;
}

std::string  NapraviPalindrom (std::string s, std::vector<std::string> v)  {
 
 for(int i=0; i<v.size(); i++) {
  for(int j=0; j<s.length(); j++) {
   for(int k=i+1; k<s.length(); k++) {
    std::string pomocni;
    int l=j;
    for( l=j; l<=k; l++) pomocni.push_back(s.at(l));
    if(pomocni==v.at(i)) {
     
if(l==s.length() || (l<s.length() && (s.at(l)<'A' || (s.at(l)>'Z' && s.at(l)<'a') || s.at(l)>'z'))) {
     std::string zamjena;
     for(int m=0; m<pomocni.length(); m++) zamjena.push_back(pomocni.at(pomocni.length()-m-1));
     s.resize(s.length()+pomocni.length());
     for(l=s.length()-1; l>j+pomocni.length(); l--) s.at(l)=s.at(l-pomocni.length());
     int m=0;
     for(l=j+pomocni.length(); l<j+2*pomocni.length(); l++) {s.at(l)=zamjena.at(m); m++;}
}
    }
   } 
  }
 }
 
 return s;
}

int main () {
    
std::string recenica;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin, recenica);
    
    std::vector<std::string> fraze;
    std::cout<<"Unesite fraze: ";
    std::string pomocni;
    
    for(;;) {
     //   std::cin.ignore(1000,'\n');
        std::getline (std::cin, pomocni);
       if(pomocni.length()==0) break;
       fraze.push_back(pomocni);
} 
    
  std::string palindrom = NapraviPalindrom (recenica, fraze); 
    std::cout<<"Recenica nakon Palindrom transformacije: "<<palindrom;
    
    std::string polupalindrom = NapraviPoluPalindrom (recenica, fraze);
    std::cout<<"\nRecenica nakon PoluPalindrom transformacije: "<<polupalindrom; 
    return 0;
}