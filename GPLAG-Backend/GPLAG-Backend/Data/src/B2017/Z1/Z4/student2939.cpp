
#include <iostream>
#include <string>

std::string Obrni (std::string s){
    std::string temp;
    for(int i=s.length()-1; i>=0; i--){
        temp.push_back(s.at(i));
    } return temp;
} 

 std::string  NapraviPalindrom (std::string s, std::vector<std::string> v){
    std::string s,s2;
  	for(int k=0; k<v.size(); k++){
  	    for(int i=0 i<s.length(); i++){
  	        if(v.at(i)==s.at(i)){
  	           s2.push_back(v.at(i))
  	        }
  	    }
  		
  	}
 }
int main () {

    std::string s;
    std::cout << "Unesi string: ";
    std::getline(std::cin, s);
    std::string temp=Obrni(s);
    std::cout << temp;
	return 0;
}