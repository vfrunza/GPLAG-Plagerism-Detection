/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stdexcept>

std::string ObrniRijec (std::string r){
    int vel=r.size();
    std::string obrnuto(r);
    int j=0;
    for (int i=vel-1; i>=0; i--){
    	
        obrnuto[j]=r[i];
        j++;
    }
    return obrnuto;
}

std::string Piglatin (std::string s){
	s.push_back(s[0]);

	for (int i=0; i<s.size()-1; i++)
	s[i]=s[i+1];
	s.erase(s.begin() + s.size()-1);
	return s;
}

std::string ObrniFraze (std::string s, std::vector<std::string> v){



	bool razmak=1;
	int p;
	int k;
	for (int i=0; i<s.size(); i++){
	if(s[i]==' ') razmak=1;
	else if(razmak==1)
	{
		razmak=0;

		p=i;

		while(s[i]!=' '&& i<s.size()){
			i++;
		}

		k=i;

		std::string rijec;
		if (s[k-1]!='.'){
			rijec=s.substr(p,k-p);
		}
		
		else rijec=s.substr(p,k-p-1);

		for (int j=0; j<v.size(); j++){
			if (v[j]==rijec){
				rijec=ObrniRijec(rijec);
				int d(0);
				if (s[k-1]!='.'){
				for(int l=p; l<k;l++){
					s[l]=rijec[d];
					d++;

				}}
				else {
					for (int l=p; l<k-1; l++){
						s[l]=rijec[d];
						d++;
					}
				}
				
			}
		}
		
	i--;
    
	}

}
return s;

}


std::string IzmijeniUPigLatin (std::string s, std::vector<std::string> v){
	for (int i=0; i<v.size(); i++){
		for (int j=0; j<v[i].size(); j++)
		if (!(v[i][j]>='a' && v[i][j]<='z' || v[i][j]>='A' && v[i][j]<='Z'|| v[i][j]==' ')) throw std::domain_error("Nekorektan izbor rijeci");
	}
	bool razmak=1;
	int p, k;
	for (int i=0; i<s.size(); i++){
		if (s[i]==' ') razmak=1;
		else if (razmak==1){
			razmak=0;
			p=i;
			
			while (s[i]!=' ' && i<s.size()){
				i++;
			}
			 
			 k=i;
			std::string rijec;
			
			if(s[k-1]!='.') rijec=s.substr(p,k-p);
			else rijec=s.substr(p,k-p-1);
			
		if (s[k-1]!='.'){
			for (int j=0; j<v.size(); j++){
				if (v[j]==rijec){
					rijec=Piglatin(rijec);
					s.insert(s.begin()+k, 'a');
					s.insert(s.begin()+k+1, 'y');
					int d(0);
					for(int l=p; l<k;l++){
						s[l]=rijec[d];
						d++;
						
					}
				}
			}}

			else {
				for (int j=0; j<v.size(); j++){
				if (v[j]==rijec){
					rijec=Piglatin(rijec);
					s.insert(s.begin()+k-1, 'a');
					s.insert(s.begin()+k, 'y');
					int d(0);
					for(int l=p; l<k-1;l++){
						s[l]=rijec[d];
						d++;
						
					}
				}
			}
			
		
		}
		i--;
	
	}}
	return s;
}

int main ()
{
	
	std::string s, temp, pig, fraz;
	std::vector <std::string> v;
	
	std::cout << "Unesite recenicu: ";
	getline(std::cin, s);
	std::cout<< "Unesite fraze: ";
	do{
	getline(std::cin, temp);
	
		v.push_back(temp);
		
	}
while((std::cin.peek()) != '\n');

try{
std::cout << "Recenica nakon PigLatin transformacije: ";
		pig=IzmijeniUPigLatin(s,v);
	std::cout << pig;}
	
	catch (std::domain_error izuzetak){
		std::cout<< izuzetak.what();
	}
        fraz=ObrniFraze(s,v);
std::cout << std::endl << "Recenica nakon obrtanja fraza: " <<  fraz;




	return 0;
}
