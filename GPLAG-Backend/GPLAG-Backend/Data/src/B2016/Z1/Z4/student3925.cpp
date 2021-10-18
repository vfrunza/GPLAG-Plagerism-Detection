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

bool dalijeslovo (char a){
	
	if((a>='A' && a<='Z') || (a>='a' && a<='z')) return true;
	else return false;
}

std::string IzmijeniUPigLatin (std::string s, std::vector<std::string>vs){
	for(int i(0);i<vs.size();i++){
		for(int j(0);j<vs[i].length();j++){
			if(!(dalijeslovo(vs[i][j]))) throw std::domain_error ("Nekorektan izbor rijeci");
		}
	}
	std::string a=s;
	int ds=s.length();
	if(vs.size()==0){
		for(int i(0);i<a.length();i++){
			ds = a.length();
			if(dalijeslovo(a[i])){
				int p=i;
			while((i+1)<ds && (dalijeslovo(a[i+1]))==true) i++;
			char pom=a[p];
			a.insert(a.begin()+i+1,pom);
			a.insert(a.begin()+i+2,'a');
			a.insert(a.begin()+i+3,'y');
			a.erase(a.begin()+p);
			i+=3;
			}
		}
	
	}

	else{
		for(int i(0);i<vs.size();i++){
			int d=vs[i].size();
			for(int j(0);j<a.length();j++){
				ds=a.length();
				if(a[j]==vs[i][0] && (ds-j+1)>=d){
					bool t=true;
					int p=j;
					for(int k(1);k<d;k++){
						if(a[p+k]!=vs[i][k]) t=false;
										 }
					if(t){
						if((p==0 || (dalijeslovo(a[p-1]))==false) && ( (p+d)==a.length() || (dalijeslovo(a[p+d])==false))){
							char pom=a[p];
							a.insert(a.begin()+p+d,pom);
							a.insert(a.begin()+p+d+1,'a');
							a.insert(a.begin()+p+d+2,'y');
							a.erase(a.begin()+p);
							j+=d+2;
										}
									}
					
					
							}
			
		}
	}
	}
	
	return a;
	}

std::string ObrniFraze (std::string s, std::vector<std::string> vs){
	std::string a(s);
	int ds=s.length();
	for(int i(0);i<vs.size();i++){
		int d=vs[i].length();
		for(int j(0);j<ds;j++){
			if(a[j]==vs[i][0] && (ds-j+1)>=d) {
				int p=j;
				bool t(true);
				for(int k(1);k<d;k++){
					if(a[p+k]!=vs[i][k]) t=false;
					}
			if(t){
				int q=j+d-1;
				for(int l(0);l<d/2;l++){
							char b=a[j+l];
							a[j+l]=a[q-l];
							a[q-l]=b;
										}
					}
			
				}
			}
		}
	return a;
}
	


int main ()
{	
	std::cout << "Unesite recenicu: ";
	std::string s;
	std::getline(std::cin,s);
	
	std::cout << "Unesite fraze: ";
	std::vector<std::string> f;
	std::string r;
	do{
		std::getline(std::cin, r);
		if(r.length()!=0) f.push_back(r);
	} while(r.length()!=0);
	
	
	
	std::string s2,s1;
	s1=ObrniFraze(s,f);
	try{
	s2=IzmijeniUPigLatin(s,f);
	std::cout << "Recenica nakon PigLatin transformacije: ";
	for(int i(0);i<s2.length();i++){
		std::cout << s2[i];
	}
	
	std::cout <<  std::endl<<"Recenica nakon obrtanja fraza: ";
	for(int i(0);i<s1.length();i++){
		std::cout << s1[i];
	
			}}
catch(std::domain_error izuzetak){
	std::cout <<"Izuzetak: "<< izuzetak.what() << std::endl;
	std::cout << "Recenica nakon obrtanja fraza: ";
	for(int i(0);i<s1.length();i++){
		std::cout << s1[i];
	}
}
	return 0;
}