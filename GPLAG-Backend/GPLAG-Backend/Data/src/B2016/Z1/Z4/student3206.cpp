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

using std::cin;
using std::cout;

std::string ObrniFraze(std::string s,std::vector<std::string> v){
	for(std::string fraza:v){
		for(int i=0;i<s.length();i++){
			if(s.substr(i,fraza.length())==fraza){
				int j;
				for(j=0;j<fraza.length();j++){
					s[i+j]=fraza[fraza.length()-1-j];
				}
			}
		}
	}
	return s;
}
std::string IzmijeniUPigLatin(std::string s,std::vector<std::string> v){
	if(v.size()==0){
		for(int i=0;i<s.length();i++){
			int brojac(0);
			if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
				int p=i;
				while((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
					brojac++;
					i++;
				}
				std::string x;
				x.insert(x.begin()+0,s[p]);
				x+=std::string("ay");
				s.erase(s.begin()+p);
				for(int j=0;j<3;j++)
				s.insert(s.begin()+p+brojac-1+j,x[j]);
				i++;
			}
		}
		return s;
	}
	for(std::string fraza:v){
		for(int k=0;k<fraza.length();k++){
			if((fraza[k]<'a' || fraza[k]>'z') && (fraza[k]<'A' || fraza[k]>'Z')){
				throw std::domain_error("Nekorektan izbor rijeci");
				break;
			}
		}
		for(int i=0;i<s.length();i++){
			if(s.substr(i,fraza.length())==fraza && (i==0 || (s[i-1]<'A' || s[i-1]>'Z')) && (i==0 || (s[i-1]<'a' || s[i-1]>'z')) && (i+fraza.length()==s.length() || (s[i+fraza.length()]<'A' || s[i+fraza.length()]>'Z')) && (i+fraza.length()==s.length() || (s[i+fraza.length()]<'a' || s[i+fraza.length()]>'z'))){
				std::string x;
				x.insert(x.begin()+0,s[i]);
				x+=std::string("ay");
				s.erase(s.begin()+i);
				for(int j=0;j<3;j++)
				s.insert(s.begin()+i+fraza.length()-1+j,x[j]);
			}
		}
	}
	return s;
}
int main ()
{
	cout<<"Unesite recenicu: ";
	std::string s;
	std::getline(cin,s);
	std::vector<std::string> v;
	std::string a;
	cout<<"Unesite fraze: ";
	do{
		std::getline(cin,a);
		if(a=="") break;
		v.push_back(a);
	}while(1);
	try{
	std::string y=IzmijeniUPigLatin(s,v);
	cout<<"Recenica nakon PigLatin transformacije: ";
	cout<<y;
	}
	catch(std::domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what();
	}
	cout<<"\n";
	cout<<"Recenica nakon obrtanja fraza: ";
	std::string x=ObrniFraze(s,v);
	cout<<x;
	return 0;
}