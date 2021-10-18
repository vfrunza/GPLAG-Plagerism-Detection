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
using std::cin;
using std::cout;

std::string ObrniFraze(std::string s, std::vector<std::string> v){
	std::string novi(s);
	for(int i=0;i<v.size();i++){
		std::string pomocni=v[i];
		for(int j=0; j<novi.size(); j++){
			int k=0;
			while(k<pomocni.size() && j<novi.size() && pomocni[k]==novi[j]){
				k++;
				j++;
			}
			if(j<novi.size() && k==pomocni.size() ){
				j--;
				int l=0;
				while(l<j) l++;
				while(l!=j-pomocni.size()) l--;
				l++;
				while(l<j){
					char tmp=novi[l];
					novi[l]=novi[j];
					novi[j]=tmp;
					l++;
					j--;
				}
				while(j<novi.size() && novi[j]!=' ') j++;
			}
		}
	}
	return novi;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v){
	std::string novi(s);
	if(v.size()==0){
		int i=0;
		while(i<novi.size()){
			while(i<novi.size() && !((novi[i]>='A'&&novi[i]<='Z')||(novi[i]>='a'&& novi[i]<='z'))) i++;
			novi.resize(novi.size()+2);
			char c=novi[i];
			while(i<novi.size()-1 && novi[i]!=' '){
				novi[i]=novi[i+1];
				i++;
			}
			i--;
			novi[i]=c;
			i++;
			novi.insert(novi.begin()+i,'a');
			i++;
			novi.insert(novi.begin()+i,'y');
			i++;
		}	
		return novi;
	}
	else{
		std::vector<std::string> provjera(v);
		for(int i=0; i<provjera.size();i++){
			std::string s1=provjera[i];
			for(int j=0; j<s1.size(); j++){
				if(!((s1[j]>='A' && s1[j]<='Z') || (s1[j]>='a' && s1[j]<='z')))
					throw std::domain_error("Nekorektan izbor rijeci");
			}
		}
		for(int i=0;i<v.size();i++){
		std::string pomocni=v[i];
		for(int j=0; j<novi.size(); j++){
			int k=0;
			if(k<pomocni.size() && j<novi.size() && pomocni[k]==novi[j] &&  j>=0 && novi[j-1]==' '){
				while(k<pomocni.size() && j<novi.size() && pomocni[k]==novi[j]){
					k++;
					j++;
				}
			}
			char c;
			if(j<novi.size() && novi[j]==' ' && k==pomocni.size()){
				j--;
				int l=0;
				while(l<j) l++;
				while(l>=0 && novi[l]!=' ') l--;
				l++;
				c=novi[l];
				while(l<novi.size()-1 && novi[l]!=' '){
				novi[l]=novi[l+1];
				l++;
				}
			l--;
			novi[l]=c;
			l++;
			novi.insert(novi.begin()+l,'a');
			l++;
			novi.insert(novi.begin()+l,'y');
			}
			k++;
		}
		}
	return novi;
	}
}




int main ()
{	
	cout<<"Unesite recenicu: ";
	std::string s;
	std::getline(std::cin,s);
	cout<<"Unesite fraze: ";
	std::vector<std::string> v;
	while(std::cin.peek()!='\n'){
		std::string s1;
		std::getline(cin,s1);
		v.push_back(s1);
	}
	try{
		cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,v)<<std::endl;
	}
	catch(std::domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s,v);
	return 0;
}