/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include<stdexcept>
typedef std::vector<std::string> vektor;
 
std::string ObrniFraze(std::string s, vektor v) {
	

	

	for( int i=0 ; i<v.size(); i++){
		std::string f;
		f=v[i];
		int br(0), j(0), k(0);
	
		while(j<s.length() ){
		
			while(k<f.length()){
				
				if(s[j]==f[k]) { k++; br++; break; }
				if(s[j]!=f[k]) { k=0; br=0; break; }
				
			}
			
			if(br==f.length()){
				int i=0;
				for( int n=j-f.length()+1 ; n<j-(f.length()/2)+1; n++) {
					char x=s[n];
					s[n]=s[j-i];
					s[j-i]=x;
					i++;
				}
				br=0;
				k=0;
			}
			j++;
			
		}
	}
	return s;
}
std::string IzmijeniUPigLatin(std::string s, vektor v) {
	

	
int i=0;
	while(  i<v.size()  ){
		
		std::string f;
		f=v[i];
		for(int t=0 ; t<f.length() ; t++)
			if(f[t]<'A' || (f[t]>'Z' && f[t]<'a') || f[t]>'z') throw std::domain_error ("Nekorektan izbor rijeci");
		
	
		int br(0), j(0), k(0);
	
		while(j<s.length() ){
		
			while(k<f.length()){
				
				if(s[j]==f[k]) { k++; br++; break; }
				if(s[j]!=f[k]) { k=0; br=0; break; }
				
			}
			
			if(br==f.length()  ){
				char y=s[j-f.length()+1];
				
				for( int n=j-f.length()+1 ; n<j; n++) {
					s[n]=s[n+1];
				}
				s[j]=y;
				s.resize(s.length()+2);
				for( int m=s.length() ; m>j+2; m--)
					s[m]=s[m-2];
				s[j+1]='a';
				s[j+2]='y';
				
				br=0;
			}
			j++;
		}
		i++;
	}
	return s;
}

int main () 
{
	
	std::string s;
	vektor v(0);
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	while(1){
		std::string f;
		std::getline(std::cin, f);
		if(f=="") break;
		v.push_back(f);
		
	}
	try{
		std::cout<<"Recenica nakon PigLatin transformacije: ";
	std::string p=IzmijeniUPigLatin(s,v);
	 for( int i=0 ; i<p.size(); i++)
    std::cout<<p[i];
	}
		catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	std::cout<<std::endl<<"Recenica nakon obrtanja fraza: ";
	std::string o=ObrniFraze(s,v);
    for( int i=0 ; i<o.size(); i++)
    std::cout<<o[i];
	return 0;
}