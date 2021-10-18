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
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string>v){
	for(int i=0;i<v.size();i++){
		std::string x=v[i];
		for(int j=0;j<s.size();j++){
			int k=0;
			int r=j;
			while(s[r]==x[k]){
				if(r==s.size()) break;
				k++;
				r++;
			}
			if(k==x.size()){
				r--;
				for(int l=0;l<x.size();l++){
					s[r]=x[l];
					r--;
				}
				
			}
		}
	}
	return s;
}
	
std::string IzmijeniUPigLatin(std::string s,std::vector<std::string> v){
	if(v.size()==0){
		int pocetak;
		if((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z'))  pocetak=0;
		for(int i=0;i<s.size();i++){
			if((i==pocetak) || (((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) && !((s[i-1]>='a' && s[i-1]<='z') || (s[i-1]>='A' && s[i-1]<='Z')))){
				 int prvi=i;
				 char prvo_slovo=s[prvi];
				 while((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) {
				 	i++;
				 } 
				 if(i==s.size()){
				 	s.push_back(prvo_slovo);
				 	s.push_back('a');
				 	s.push_back('y');
				 }
				 else{
				 	s.insert(s.begin()+i, 'y');
				 	s.insert(s.begin()+i,'a');
				 	s.insert(s.begin()+i,prvo_slovo);
				 }
				 s.erase(s.begin()+prvi);
			}
		}
	}
	else{
		for(int i=0;i<v.size();i++){
			std::string x=v[i];
			for(int j=0;j<x.size();j++){
				if(!((x[j]>='a' && x[j]<='z') || (x[j]>='A' && x[j]<='Z'))) throw std::domain_error("Nekorektan izbor rijeci");
			}
			for(int j=0;j<s.size();j++){
				int k=0;
				int p=j;
				while(s[j]==x[k]){
					if(j==s.size()) break;
					k++;
					j++;
				}
				if((s[p]==s[0] || s[p-1]==' ') && k==x.size() && (j==s.size() || !((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z')))){
					if(j==s.size()){
						s.push_back(s[p]);
						s.push_back('a');
						s.push_back('y');
						s.erase(s.begin()+p);
					}
					else{
						s.insert(s.begin()+j,'y');
						s.insert(s.begin()+j,'a');
						s.insert(s.begin()+j,s[p]);
						s.erase(s.begin()+p);
					}
				}
			}
		}
	}
	return s;
}

int main ()
{
	std::string s;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,s);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> v ;
	int i=0;
	for(;;){
		std::string a;
		std::getline(std::cin,a);
		if(a.size()==0) break;
		v.resize(i+1);
		v[i]=a;
		i++;
	
	}
	try{
		std::string d= IzmijeniUPigLatin(s,v);
		std::cout << "Recenica nakon PigLatin transformacije: "<< d << std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	std::string m=ObrniFraze(s,v);
	std::cout<< "Recenica nakon obrtanja fraza: " << m << std::endl;
	return 0;
}