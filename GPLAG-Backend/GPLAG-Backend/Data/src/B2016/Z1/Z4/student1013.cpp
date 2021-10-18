#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string okreni (std::string s,int poc, int vel) {
	int k=0;
	for(int i=poc;i<poc+vel;i++) {
		char pomocna=s[i];
		s[i]=s[poc+vel-1-k];
		s[poc+vel-1-k]=pomocna;
		k++;
		if(k==vel/2) break;
	}
	return s;
}

bool JelTUFraza(std::string s, int k, int vel, std::vector<std::string> fraze) {
	std::string rijec;
	for(int i=k;i<k+vel;i++) {
		if(i==s.length()) return false;
		rijec.push_back(s[i]);
	}
	for(int j=0;j<fraze.size();j++) {
		if(rijec==fraze[j]) return true;
	}
	return false;
}

bool JelTUFrazaPIG(std::string s, int k, int vel, std::vector<std::string> fraze) {
	std::string rijec;
	if(k+vel>s.length()) return false ;
	if(k!=0 and k+vel<=s.length()) {
		if(k+vel==s.length() and (s[k-1]>='A' and s[k-1]<='Z') or (s[k-1]>='a' and s[k-1]<='z') ) return false ;
		if( k+vel<s.length() and ( (s[k-1]>='A' and s[k-1]<='Z') or (s[k-1]>='a' and s[k-1]<='z') ) or ( (s[k+vel]>='A' and s[k+vel]<='Z') or (s[k+vel]>='a' and s[k+vel]<='z') ) ) return false ;
	}
	if(k==0 and k+vel<s.length()) {
		if( (s[k+vel]>='A' and s[k+vel]<='Z') or (s[k+vel]>='a' and s[k+vel]<='z') ) return false ;
	}
	for(int i=k;i<k+vel;i++) {
	 	if(i==s.length()) return false;
		rijec.push_back(s[i]);
	}
	for(int j=0;j<fraze.size();j++) {
		if(rijec==fraze[j]) return true;
	}
	return false;
}

std::string unkcijafunjo (std::string s, int poc, int vel) {
	s.resize(s.length()+2);
	char k=s[poc];
	for(int i=poc;i<poc+vel;i++) {
		if(i==poc+vel-1) s[i]=k;
		else s[i]=s[i+1];
	}
	for(int i=s.length();i>=poc+vel+2;i--) {
		s[i]=s[i-2];
	}
	s[poc+vel]='a';
	s[poc+vel+1]='y';
	return s;
}

std::string ObrniFraze (std::string s, std::vector<std::string> fraze ) {
	std::vector<int> duzine;
	if(fraze.size()==0) return s;
	for(int i=0;i<fraze.size();i++) {
		duzine.push_back(fraze[i].length());
	}
	int j=0;
	for(int i=0;i<s.length();i++) {
			if(JelTUFraza(s,i,duzine[j],fraze)==true) {
				s=okreni(s,i,duzine[j]);			
			}
			if(i==s.length()-1 and j!=duzine.size()-1) {
				i=0;
				j++;
		}
	}
	return s;
}

std::string IzmijeniUPigLatin (std::string s, std::vector<std::string> fraze) {
	std::vector<int> duzine;
	for(int i=0;i<fraze.size();i++) {
		duzine.push_back(fraze[i].length());
	}
	if(fraze.size()==0) {
		for(int i=0;i<s.length();i++) {
			if( (s[i]>='A' and s[i]<='Z') or (s[i]>='a' and s[i]<='z') ) {
				int brojac=0;
				while( (s[i]>='A' and s[i]<='Z') or (s[i]>='a' and s[i]<='z') ) {
					brojac++;
					i++;
					if(i==s.length()) break;
				}
				i=i-brojac;
				s=unkcijafunjo(s,i,brojac);
				i=i+brojac+2;
			}
		}	
	}
	else {
		for(int i=0;i<fraze.size();i++) {
			for(int j=0;j<fraze[i].length();j++) {
				if( !( (fraze[i][j]>='A' and fraze[i][j]<='Z') or (fraze[i][j]>='a' and fraze[i][j]<='z') )) throw std::domain_error ("Nekorektan izbor rijeci");
			}
		}
		for(int i=0;i<s.length();i++) {
			for(int j=0;j<duzine.size();j++) {
				if(JelTUFrazaPIG(s,i,duzine[j],fraze)==true) {
					s=unkcijafunjo(s,i,duzine[j]) ;
				}
			}
		}
	}
	return s;
}

int main () {
	std::cout << "Unesite recenicu: " ;
	std::string recenica;
	std::getline (std::cin, recenica) ;
	std::cout << "Unesite fraze: " ;
	std::string fraza ;
	std::vector<std::string> v;
	while(2) {
		std::getline(std::cin, fraza);
		if(!fraza.length()) break ;
		v.push_back(fraza);
	}
	try {
	std::cout << "Recenica nakon PigLatin transformacije: "<< IzmijeniUPigLatin(recenica,v) <<std::endl ; 
	}
	catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl ;
	}
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica,v) ;
	return 0;
}