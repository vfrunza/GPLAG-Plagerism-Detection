#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> vekaz) {
    
    bool a;
    for (int i(0); i < vekaz.size(); i++) {
        for(int j(0); j < s.length(); j++) {
            if(vekaz[i][0] == s[j]) { 
                a=true;
                for(int k(0); k < vekaz[i].length(); k++) {
                    if(j+k>=s.length()) {
                        a=false;
                        break;
                    }
                    
                    if(vekaz[i][k] != s[j+k]) {
                        a=false;
                    }
                    
                    if(k == vekaz[i].length()-1){
                        if(j+k+1 > s.length() ) a=false;
                    }
                    
                }
                if(a == true) {
                    for(int k=vekaz[i].length()-1; k >= 0; k--) {
                        
                        s[j] = vekaz[i][k];
                        j++;
                        
                    }
                }
            }
            
            
        }
    }
	return s;
	
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> vekaz) {
    
    if(vekaz.size()!=0) {
        
     for(int i(0); i<vekaz.size(); i++) {
        for(int j(0); j<vekaz[i].size(); j++) {
            if(vekaz[i][j]<65 || (vekaz[i][j]>90 && vekaz[i][j]<97) || vekaz[i][j]>122) throw std::domain_error("Nekorektan izbor rijeci");
        }
    }
    char prvoslovo;
    bool a;
    for (int i(0); i < vekaz.size(); i++) {
        for(int j(0); j < s.length(); j++) {
            
            if(vekaz[i][0] == s[j] && (s[j-1] == ' ' || s[j-1] == ',' || s[j-1] == '.' || s[j-1] == '!' || s[j-1] == '?' || j==0)) {
                a=true;
                for(int k(0); k < vekaz[i].length(); k++) {
                    if(j+k>=s.length()) {
                        a=false;
                        break;
                    }
                 
                    if(vekaz[i][k] != s[j+k]) {
                        a=false;
                    }
                    
                    
                    
                    if(k == vekaz[i].length()-1){
                    
                        if(s[j+k+1] != ' ' && s[j+k+1] != ',' && s[j+k+1] != '.' && s[j+k+1] != '!' && s[j+k+1] != '?' && j+k+1 != s.length() ) a=false;
                    }
                    
                    
                }
                if(a == true) {
                    int p;
                    prvoslovo=vekaz[i][0];
                    
                    for( p=j; p<j+vekaz[i].size(); p++) {
                        s[p]=s[p+1];
                    }
                    p--;
                    
                    s[p]=prvoslovo;
                    
                    s=s.substr(0, p+1) + "ay" + s.substr(p+1, s.length());
                    }
                }
            }
            
            
        }
        return s;
    }
    else {
        int prvoslovo;
        std::string ns;
    
        for(int i=0; i<s.length(); i++) {
            
            while(s[i]==' ' || s[i]==',' || s[i]=='.' || s[i]=='?' || s[i]=='!') {
                ns.push_back(s[i]);
                i++;
            }
            if(i==s.length()) break;
            prvoslovo=i;
            i++;
            while(s[i]!=' ' && s[i]!=',' && i!=s.length() && s[i]!='!' && s[i]!='?' && s[i]!='.') {
            ns.push_back(s[i]);
            i++;
            }
            ns.push_back(s[prvoslovo]);
            ns.push_back('a');
            ns.push_back('y');
            i--;
            }
            return ns;
    }
}
        
        
    
int main ()
{
    
    std::string s;
    std::cout << "Unesite recenicu: ";
    
    std::getline(std::cin, s);
    std::vector<std::string> fraze;
    std::string rijec;
    std::cout << "Unesite fraze: ";
    std::getline(std::cin, rijec);
    
    while(rijec.length()!=0) {
        fraze.push_back(rijec);
        std::getline(std::cin, rijec);
    }
   
    
    std::string novis, novis2;
    try {
    novis=IzmijeniUPigLatin(s, fraze);
    std::cout << "Recenica nakon PigLatin transformacije: ";
    
    for(int i(0); i<novis.length(); i++) {
        std::cout << novis[i];
    }
    std::cout << std::endl;
    }
    catch (std::domain_error izuzetak) {
		std::cout <<"Izuzetak: "<< izuzetak.what() << std::endl;
	}
    novis2=ObrniFraze(s, fraze);
    std::cout << "Recenica nakon obrtanja fraza: ";
    
    for(int i(0); i<novis2.length(); i++) {
        std::cout << novis2[i];
    }
	return 0;
    
    
}