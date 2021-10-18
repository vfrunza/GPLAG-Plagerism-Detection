/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <string>

std::string NapraviPalindrom(std::string s,std::vector<std::string> vekt_str){
int j(0),k(0),i(0);
	for(i=0;i<vekt_str.size();i++){
           for(k=0;k<s.length();k++){
     	      if(s.at(k)==vekt_str.at(i).at(0)){
    		    int duzina=s.length()-1;
    		    j=0;
    	 	    while(vekt_str.at(i).at(j)==s.at(k) && k<s.length()-1 && j<vekt_str.at(i).size()-1){
    			     j++;
    			     k++;
    			}
    			if(vekt_str.at(i).at(j)==s.at(k) && k<s.length() && j<vekt_str.at(i).size()) {
    				j++;
    				k++;
    			}
    			if(j==vekt_str.at(i).size()){
    				if(k==s.length() || !((s.at(k)>='A' && s.at(k)<='Z') ||(s.at(k)>='a' && s.at(k)<='z'))){
    				int temp1=k;
    				s.resize(s.length()+vekt_str.at(i).length());
    				while(duzina>=temp1){
    					s.at(duzina+vekt_str.at(i).length())=s.at(duzina);
    				if(duzina==temp1) break;	
    				     duzina--;
    					}
    					temp1=vekt_str.at(i).length()-1;
    					while(temp1>=0 && k<s.length()){
    						s.at(k)=vekt_str.at(i).at(temp1);
    						if(k==s.length()) break;
    						k++;
    					if(temp1==0) break;
    						temp1--;
    					}
    				}
    			}
     	      
	}
     	      
     	      }
}
return s;	
	
}
std::string NapraviPoluPalindrom(std::string s1,std::vector<std::string> v){
	int j(0);
	
	for(int i=0; i<v.size();i++){
		for(int k=0;k<s1.length();k++){
			if(s1.at(k)==v.at(i).at(0)){
				j=0;
				int pomocna=k;
				while(s1.at(k)==v.at(i).at(j) && k<s1.length()-1 && j<v.at(i).size()-1){
					j++;
					k++;
				}
				if(s1.at(k)==v.at(i).at(j) && j<v.at(i).size() && k<s1.length()){
					k++;
					j++;
				}
				if(j==v.at(i).size()){
					if(k==s1.length() || !((s1.at(k)>='A' && s1.at(k)<='Z') || (s1.at(k)>='a' && s1.at(k)<='z'))){
					int z=0;
				    while(z<v.at(i).size()/2) z++;
				     pomocna+=z;
					int temp1=v.at(i).size()-1;
					temp1/=2;
					while(temp1>=0 && pomocna<s1.length()){
						s1.at(pomocna)=v.at(i).at(temp1);
						if(temp1==0) break;
						pomocna++;
						temp1--;
					}
				}
			}
		}
		}
	}
	
	
	return s1;
}

int main ()
{   
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	//std::cin.ignore(1000,'\n');
	std::vector<std::string> v_str;
	for(;;){
		std::string fraze;
		std::getline(std::cin,fraze);
		if(!fraze.empty()) v_str.push_back(fraze);
		else break;
	}
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,v_str)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,v_str);
	return 0;
}