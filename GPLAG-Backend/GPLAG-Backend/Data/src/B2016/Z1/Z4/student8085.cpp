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
typedef std::vector<std::string> vector;

std::string ObrniFraze(std::string s, vector v){
	std::string s1,s2,s3;
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<s.size(); j++){
			if(s.substr(j,v[i].size())==v[i]){
				s1=v[i];
				s2=s.substr(0,j);
				s3=s.substr(j+v[i].size(),s.size()-(j+v[i].size()));
				for(int k=0; k<s1.size()/2; k++){
			   	 char temp;
				    temp=s1[k];
				   	s1[k]=s1[s1.size()-1-k];
					s1[s1.size()-1-k]=temp;
				}
				s=s2+s1+s3;
				j++;
			}
		}
	}
	
	return s;
}


std::string IzmijeniUPigLatin(std::string s, vector v){
	std::string pw,s1,s3;
	
	for(int i=0; i<v.size(); i++){
		std::string pomocni;
		pomocni=v[i];
		for(int j=0; j<pomocni.size(); j++){
		if(pomocni[j]==' ') throw std::domain_error("Nekorektan izbor riječi");
		}
	}

	if(v.size()==0){
		std::string v1;
		int brojac=0;
		for(int i(0); i<s.size(); i++){
			brojac=0;
			while(s[i]!=' ') brojac++;
			std::string pomocni;
			for(int j(0); j<brojac; j++){
			pomocni=s.substr(j, brojac);
			char temp;
			temp=pomocni[j];
			pomocni[j]=pomocni[j-1];
			pomocni[j+brojac]=temp;
			pomocni+="ay ";
			v1.push_back(pomocni[j]);
			
			}
		}return v1;
		
	}
else{
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<s.size()-v[i].size()+1; j++){
			if(s.substr(j,v[i].size())==v[i]){
				char temp;
				temp=s[j];
				s[j]=s[j-1];
				s[j+v[i].size()]=temp;
				
				s1=s.substr(0,j-1);
			    pw=s.substr(j,v[i].size()+1);
			    s3=s.substr(j+v[i].size()+1, s.size()-(j+v[i].size()+1));
			
		    	pw+="ay ";
		    	s=s1+pw+s3;
			
	      	}
        } 
    }
	return s;
}
}

int main ()
{
	std::string s;
	std::cout<<"Unesite recenicu: ";
	getline(std::cin,s);
	vector v;
	std::cout<<"Unesite fraze: ";
	for(;;){
		std::string s1;
		getline(std::cin,s1);
		if(s1=="") break;
		v.push_back(s1);
	}
	


	std::cout<<"Recenica nakon PigLatin transformacije: ";

	try {
		std::cout<<IzmijeniUPigLatin(s,v)<<std::endl;
	}
	catch (std::domain_error e) {
		std::cout<<"Izuzetak: "<<e.what();
		std::cout<<std::endl;
	}
	
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s,v);
	return 0;
}