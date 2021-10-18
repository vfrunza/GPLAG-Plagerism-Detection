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

std::string ObrniFraze(std::string s, std::vector<std::string> v){
	std::vector<std::string> v2;
	v2.resize(v.size());
	for(int i=0;i<v.size();i++){
		for(int j=v[i].size()-1;j>=0;j--){
			v2[i].push_back(v[i][j]);
		}
	}
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<s.size()-v[i].size()+1;j++)
		{
			if(s.substr(j,v[i].size())==v[i])
				s=s.substr(0,j)+v2[i]+s.substr(j+v2[i].size(), s.size()-v2[i].size()-j);
		}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v){
	if(v.size()==0){
		int br=0;
		for(int i=0;i<s.size();i++){
			while(!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) && i<s.size()){
				i++; 
				br=i;
			}
			while(((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z')) && i<s.size())
				i++;
			s=s.substr(0,br)+s.substr(br+1,i-br-1)+s.substr(br,1)+"ay"+s.substr(i,s.size()-i);
			i+=3;
			br=i;
		}
	}
	else {
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].size();j++){
				if(!((v[i][j]>='a' && v[i][j]<='z') ||(v[i][j]>='A' && v[i][j]<='Z')))
				throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
			}
		}
		std::vector<std::string> v2;
		for(int i=0;i<v.size();i++)
		{
			v2.push_back(v[i].substr(1,v[i].size()-1) + v[i].substr(0,1)+"ay");
			
	}
	
	int j(0), br(0);
	for(int i=0;i<v.size();i++){
		while(j<s.size()){
			while( ( !( (s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j] <= 'z') ) ) && j<s.size() )
			{j++; br++;}
			
			while( ( (s[j]>='A' && s[j]<='Z') || (s[j]>='a'&&s[j]<='z') ) && j<s.size())
			j++;
			if(s.substr(br,j-br) == v[i])
			s=s.substr(0,br)+v2[i]+s.substr(j, s.size()-j);
			j++;
			br=j;
		}
		j=br=0;
	}
	
	
	}
	return s;
}
int main ()
{
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::string s2;
	std::vector<std::string> v;
	std::cout<<"Unesite fraze: ";
	while(true){
		std::getline(std::cin,s2);
		if(s2.size()==0) break;
		else v.push_back(s2);
	}
	
	try{
		std::string s3;
		s3=IzmijeniUPigLatin(s,v);
		std::cout<<"Recenica nakon PigLatin transformacije: ";
		std::cout<<s3<<std::endl;
	}
	catch (std::domain_error t){
		std::cout<<t.what()<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::string s4=ObrniFraze(s,v);
	std::cout<<s4<<std::endl;
	return 0;
}