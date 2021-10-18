/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
std::string Promjena(std::string a){
	std::string b{a[0],'a','y'};
	a=a+b;
	a.erase(a.begin());
	return a;
}
std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> c){
	std::string pomocni;
	for(int i=0; i<c.size(); i++){
		for(int j=0; j<c[i].size(); j++){
			if((c[i][j]>='a' && c[i][j]<='z')||(c[i][j]>='A' && c[i][j]<='Z'))continue;
			else throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	if(c.size()==0){
		for(int i=0; i<s.size(); i++){
			if((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&& s[i]<='Z')){
				int poc=i;
				while((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))i++;
				s.insert(s.begin()+i,' ');
				s.insert(s.begin()+i,' ');
				i--;
				int kraj=i,temp;
				for(int j=poc; j<kraj; j++){
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
				}
				s[kraj+1]='a';
				s[kraj+2]='y';
				i+=2;
			}
		}
		return s;
	}
	for(int i=0; i<c.size(); i++){
		for(int k=0; k<s.size(); k++){
			int j=0,z=k;
			if((k==0 && s[k]==c[i][0] )||(s[k]==c[i][0] && !((s[k-1] >='A' && s[k-1]<='Z') || (s[k-1] >= 'a' && s[k-1]<='z')))){
			while(z<s.size() && j<c[i].size() && s[z]==c[i][j]){
				z++; j++;
			}
			if(j==c[i].size() &&  !((s[z] >= 'A' && s[z] <= 'Z') || (s[z] >= 'a' && s[z] <= 'z'))){
				pomocni=Promjena(c[i]);
				s.insert(s.begin()+z,' ');
				s.insert(s.begin()+z,' ');
				z=k;j=0;
				while(j<pomocni.size()){s[z]=pomocni[j];j++;z++;}
			}
			}
		}
		
	}
	return s;
}
std::string Obrci(std::string a){
	char temp;
	for(int i=0; i<a.size(); i++){
		if(i>=a.size()/2)break;
		temp=a[i];
		a[i]=a[a.size()-i-1];
		a[a.size()-i-1]=temp;
	}
	return a;
}
std::string ObrniFraze(std::string s, std::vector<std::string> c){
	std::string pomocni;
	for(int i=0; i<c.size(); i++){
		for(int k=0; k<s.size(); k++){
			int j=0,z=k;
			while(z<s.size() && j<c[i].size() && s[z]==c[i][j]){
				z++; j++;
			}
			if(j==c[i].size()){
				pomocni=Obrci(c[i]);
				z=k;j=0;
				while(j<pomocni.size()){s[z]=pomocni[j];j++;z++;}
			}
		}
	}
	return s;
}
int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string s;
	std::getline(std::cin,s);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string>v;
	while(1){
		std::string c;
		std::getline(std::cin,c);
		if(c.size()==0)break;
		v.push_back(c);
	}
	std::string m;
	try{
		m=(IzmijeniUPigLatin(s,v));
		std::cout<<"Recenica nakon PigLatin transformacije: ";
		std::cout<<m;
	}catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	m=ObrniFraze(s,v);
	std::cout<<std::endl<<"Recenica nakon obrtanja fraza: ";
	std::cout<<m<<std::endl;
	return 0;
}