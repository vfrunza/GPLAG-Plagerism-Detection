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
#include <cctype>
std::string ObrniFraze(std::string s, std::vector<std::string> v){
	int pt,kt;
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<s.length(); j++){
			if(v[i][0]==s[j]){
				if((j!=0 && s[j-1]==' ') || j==0){
					pt=j;
					int k=0;
					while(k<v[i].size() && j<s.length() && v[i][k]==s[j]){
						k++;
						j++;
					}
					if(k==v[i].size() && (s[j]==' ' || s[j]=='.' || s[j]==',' || j==s.length())){
						kt=j;
					} 
					int kraj=kt-1;
					int vel=((kt-pt)/2);
					for(int l=0; l<vel; l++){
						char temp=s[pt];
						s[pt]=s[kraj];
						s[kraj]=temp;
						kraj--;
						pt++;
					}
				}
			}
		}
	}
	return s;
}

int main ()
{
	std::string s,s2;
	std::vector<std::string> v;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s2);
	std::cout<<"Unesite fraze: ";
	do{
		std::getline(std::cin,s);
		v.push_back(s);
		
	}while(s!="");
	/*std::cout<<"vektor: ";
	for(int i=0; i<v.size(); i++){
		std::cout<<v[i];
		std::cout<<std::endl;
	}*/
	std::cout<<"\nRecenica nakon obrtanja fraza: ";
	std::string s1=ObrniFraze(s2,v);
	for(int i=0; i<s1.size(); i++){
		std::cout<<s1[i];
	}
	return 0;
}