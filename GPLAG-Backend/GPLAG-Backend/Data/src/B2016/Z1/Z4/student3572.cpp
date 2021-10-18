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

typedef std::vector<std::string> vektor;

std::string ObrniFraze(std::string a,vektor b){
	for(int i=0;i<b.size();i++){
		for(int j=0;j<a.length();j++){
	if(a[j]==b[i][0]){
	std::string x= a.substr(j,b[i].length());
	if(x==b[i]){
		int m=b[i].length();
		for(int k=0;k<b[i].length()/2;k++){
			auto y=a[j+m-1+k];
			a[j+m-1+k]=a[j+k];
			a[j+k]= y;
			m=m-2;
		}
	}
	}
	}
	}
			

	return a;
}

std::string IzmijeniUPigLatin (std::string a, vektor b){
	for(int i=0;i<b.size();i++){
		for(int j=0;j<b[i].length();j++){
			if((!(b[i][j]>='a'&& b[i][j]<='z')&&!(b[i][j]>='A'&& b[i][j]<='Z')) || b[i][j]==' ') throw std::domain_error ("Nekorektan izbor rijeci");
		}
	}

	vektor f;
	std::string g;
	for(int i=0; i<a.size();i++){
	
		if(a[i]!=' ') g.push_back(a[i]);
		if((a[i]==' ')||(i==a.size()-1)){
			f.push_back(g);
			for(int j=(g.size()-1);j>=0;j--){
			g.erase(g.begin()+j);
		}
			
		}
	
	}
//for(int i=0;i<f.size();i++)
//std::cout<<f[i]<<" ";
		
	for(int i=0;i<f.size();i++){
		if(b.size()==0){
			std::string h;
			h.push_back(f[i][0]);
			std::string k{"ay"};
			f[i]=f[i]+h+k;
		
			f[i].erase(f[i].begin()+ 0);
		
            
			for(int i=(h.size()-1);i>=0;i--){
			h.erase(h.begin()+i);
		}	
		}
	else{	for(int j=0;j<b.size();j++){

			if (f[i]==b[j]){
			std::string h;
			h.push_back(f[i][0]);
			std::string k{"ay"};
			f[i]=f[i]+h+k;
		
			f[i].erase(f[i].begin()+ 0);
		
            
			for(int i=(h.size()-1);i>=0;i--){
			h.erase(h.begin()+i);
		}
		}
		}
		}
		}

	        std::string m;
			for(auto i:f) m=m+i+" ";
		
			
		
	return m;
}

int main (){
	
	std::string a;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,a);
	std::cout<<"Unesite fraze: ";
	vektor b;
	std::string c;
	std::getline(std::cin,c);
	while(c.length()!=0){
	b.push_back(c);
		std::getline(std::cin,c);
	}
	try{
	std::string d=IzmijeniUPigLatin(a,b);
	std::cout<<"Recenica nakon PigLatin transformacije: "<<d<<std::endl;
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
	}

	std::string e=ObrniFraze(a,b);
	std::cout<<"Recenica nakon obrtanja fraza: "<<e;
	
	return 0;
}