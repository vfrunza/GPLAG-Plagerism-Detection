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
#include <cstring>
#include <stdexcept>

std::string ObrniFraze(std::string s,std::vector<std::string> v){
	int broj(0);
	int pomocni(0);
	int rijec(0);
	int pamti(0);
	if(v.size()==0)return s;
	for(int i=pomocni;i<s.length();i++){
		do{
			if(s[i]==' ')break;
			broj++;
		}while(s[i]==' ');
		if(s[i]==' '){
			rijec++;
		}
	    if(i==s.length()-1){
	    	broj+=0;
	    	rijec++;
	    }
	char temp;
	int a(1);
	for(int i=0;i<v.size();i++){
		if(pomocni==0){
		if(s.substr(pomocni,broj)==v[i]){
			for(int i=pomocni;i<pomocni+broj;i++){
			for(int j=pomocni+broj-i-1;j>0;j--){
				if(i!=j){
				temp=s[j];
				s[j]=s[i];
				s[i]=temp;
				}
				if(i==j || i==j-1){
					a=0;
					break;
				}
				j=0;
				}
				if(a==0)break;
			}
			break;
		}	
	} 
	if(pomocni!=0){
		int broj2(1);
		int b(1);
		if(s.substr(pomocni,broj)==v[i]){
		for(int i=pomocni;i<(pomocni+broj+1);i++){
			for(int j=pomocni+broj-broj2;j>0;j--){
				if(i!=j){
				temp=s[j];
				s[j]=s[i];
				s[i]=temp;
				}
				if(i==j || i==j-1){
					b=0;
					break;
				}
				j=0;
				}
				if(b==0)break;
				broj2++;
			}
		}
	}
	}
	if(s[i]!=' ' && s[i]!='.')continue;
	if(rijec==1){
		pamti=broj;
		broj+=1;
	}
	if(i==s.length()-1 && rijec==2){
		broj=broj-pamti;
		i=i-broj+1;
		pomocni=pomocni+pamti+1;
		rijec=0;
		broj=0;
	}
	if(s[i]==' ' && rijec==2){
		broj=(broj-pamti);
		i=i-broj;
		pomocni=pomocni+pamti+1;
		rijec=0;
		broj=0;
		}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s,std::vector<std::string> v){
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
		if(!((v[i][j]>='a' && v[i][j]<='z') || (v[i][j]>='A' && v[i][j]<='Z')))throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	int broj(0);
	int pomocni(0);
	for(int i=pomocni;i<s.length();i++){
		do{
			if(s[i]==' ')break;
			broj++;
		}while(s[i]==' ' || s[i]=='\0');
	    if(i==s.length()-1)broj+=0;
		else if(s[i]!=' ')continue;
	for(int i=0;i<v.size();i++){
		if(pomocni==0){
		if(s.substr(pomocni,broj)==v[i]){
			for(int i=pomocni;i<pomocni+broj;i++){
			for(int j=pomocni+broj-i-1;j>0;j--){
				if(i!=j){
				s.insert(s.begin()+j+1,s[i]);
				s.erase(s.begin()+i);
				s.insert(s.begin()+j+1,'a');
				s.insert(s.begin()+j+2,'y');
				}
				break;
				}
				break;
				}
			}
			
		}	
	if(pomocni!=0){
		if(s.substr(pomocni+1,broj)==v[i]){
		for(int i=pomocni+1;i<(pomocni+broj+1);i++){
			for(int j=pomocni+broj;j>0;j--){
				if(i!=j){
				s.insert(s.begin()+j+1,s[i]);
				s.erase(s.begin()+i);
				s.insert(s.begin()+j+1,'a');
				s.insert(s.begin()+j+2,'y');
				}
				break;
				}
				break;
			}
		}
	}
	}
	
	if(s[i]==' '){
		pomocni=i;
		broj=0;
		}
	}
	return s;
	
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string s;
	std::getline(std::cin,s);
	std::vector<std::string> v;
	std::cout << "Unesite fraze: ";
	std::string v1;
	do{
		std::getline(std::cin,v1);
		if(v1.length()==0) break;
		v.push_back(v1);
	}while(v1.length()!=0);
	try{
		std::string a;
		std::string b;
		a=IzmijeniUPigLatin(s,v);
		std::cout << "Recenica nakon PigLatin transformacije: ";
		for(int i=0;i<a.length();i++){
		std::cout <<a[i];
		}
		b=ObrniFraze(s,v);
		std::cout <<std::endl<< "Recenica nakon obrtanja fraza: ";
		for(int i=0;i<b.length();i++){
		std::cout <<b[i];
		}
	}
	catch(std::domain_error n){
		std::cout << "Izuzetak: "<<n.what() << std::endl;
		std::cout <<std::endl<< "Recenica nakon obrtanja fraza: ";
		std::string b;
		b=ObrniFraze(s,v);
		for(int i=0;i<b.length();i++){
		std::cout <<b[i];
		}
	}
	
	return 0;
}