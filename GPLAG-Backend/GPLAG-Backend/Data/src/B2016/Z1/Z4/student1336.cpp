/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>





std::string ObrniFraze (std::string s, std::vector<std::string> v){
	
	
	
	for(int i(0); i<int(v.size()); i++){
		
		for(int j(0); j<int(s.length()); j++ ){
		
			if(s.at(j)==v.at(i).at(0)) {
				
				int n(j);
				std::string sub;
				
				for(int k(0); k<int(v.at(i).length()); k++, n++ ){
					if(s.at(n)!=v.at(i).at(k)) break;
					else sub.push_back(v.at(i).at(k));
					if( (n+1)==int(s.length()) ) break;
					
				}
				
				
				if(sub==v.at(i)){
					for(int k(int(v.at(i).length())-1); k>=0; k-- ){
						s.at(j)=v.at(i).at(k);
						if(k-1>=0){
							j++;
						}
					}
				}
				
			}
		}
	}
	return s;
}



std::string IzmijeniUPigLatin (std::string s, std::vector<std::string> v){
	
	for(int i(0); i<int(v.size()); i++){
		for(int j(0); j<int(v.at(i).length()); j++){
			if(v.at(i).at(j)<'A' || (v.at(i).at(j)>'Z' &&  v.at(i).at(j)<'a') || v.at(i).at(j)>'z'     ) throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	
	std::string povratni;
	
	if(int(v.size())==0){
		
		for(int i(0); i<int(s.length()); i++ ){
			
			bool doseg(false);
			
			while((s.at(i)>='A' && s.at(i)<='Z') || (s.at(i)>='a' && s.at(i)<='z')==false){
				povratni.push_back(s.at(i));
				if((i+1)==int(s.length())) {
					doseg=true;
					break;
				}
				i++;
			}
			
			if(doseg) break;
			
			int n(i+1); 
			bool nijezadnji(true);
			if(n==int(s.length())) nijezadnji=false;
			
			while( nijezadnji && ((s.at(n)>='a' && s.at(n)<='z') || (s.at(n)>='A' && s.at(n)<='Z' ))){
				povratni.push_back(s.at(n));
				if((n+1)==int(s.length())) {
					nijezadnji=false;
					break;
				}
				n++;
			}
			
			povratni+=s.at(i);
			povratni+="ay";
			i=n;
			if(nijezadnji){
				povratni+=s.at(i);
			}
		}
	}
	
	else{
		for(int i(0); i<int(s.length()); i++ ){
			
			
			bool nijebilokonverzije(true);
			for(int j(0); j<int(v.size()); j++ ){
				if(s.at(i)==v.at(j).at(0) && (i+int(v.at(j).length())-1<int(s.length()) ) ) {
					
					int n(int(v.at(j).length()));
					
					if(s.substr(i, n)==v.at(j)  && (i==0 || (i!=0 && ( s.at(i-1)<'A' || (s.at(i-1)>'Z' && s.at(i-1)<'a' ) || s.at(i-1)>'z' )  ) ) ){
						
						int k(i);
						std::string sub;
						
						while((s.at(k)>='a' && s.at(k)<='z') || ( s.at(k)>='A' && s.at(k)<='Z' )){
							sub+=s.at(k);
							if(k+1==int(s.length())) break;
							k++;
						}
					  
					  	if(sub==v.at(j)){
							povratni+=s.substr(i+1,n-1);
							povratni+=s.at(i);
							povratni+="ay";
							i=i+int(v.at(j).length())-1;
							nijebilokonverzije=false;
							break;
					  	}
					}
					
				}
			}
			if(nijebilokonverzije) povratni+=s.at(i);
			
		}
	}
	
	return povratni;
}

int main ()
{
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> v;
	
	for(;;){
		std::string temp;
		std::getline(std::cin, temp);
		if(int(temp.length())==0) break;
		v.push_back(temp);
	}
	
	try{
		std::string pig(IzmijeniUPigLatin(s,v));
		std::cout<<"Recenica nakon PigLatin transformacije: "<<pig<<std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s,v)<<std::endl;
	
	
	return 0;
}