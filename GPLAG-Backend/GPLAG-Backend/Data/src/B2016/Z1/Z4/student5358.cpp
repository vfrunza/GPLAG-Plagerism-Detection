#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
std::string ObrniFraze(std::string str,std::vector<std::string> s){
	for(int v=0;v<s.size();v++){
		std::string g=s[v];
		int h=g.size();
		for(int i=0;i<str.size();i++){
			int p=i,j=0;
			if(g[j]==str[i]){
				while(g[j]==str[i]){
					j++;
					i++;
					if(i==str.size())break;
				}
				if(j==h){
					i--;
					for(int c=0;c<h/2;c++){
						char a=str[p];
						str[p]=str[i];
						str[i]=a;
						i--;
						p++;
					}
				}
			}
		}
	}
	return str;
}
std::string IzmijeniUPigLatin(std::string str,std::vector<std::string> s){
	for(int i=0;i<s.size();i++){
		std::string f=s[i];
		for(int j=0;j<f.length();j++){
			if((f[j]<'A' || f[j]>'z') || (f[j] >'Z' && f[j]<'a'))throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	/*if(s.size()==0){
		std::string pom;
		for(int i=0;i<str.size();i++){
			if(i==str.length()-1)
			s.push_back(pom);
			if(str[i]!=' ' || str[i]!=',')pom.push_back(str[i]);
			else{
				s.push_back(pom);
				pom.resize(0);
			}
			if(i==str.length()-1 //&& str[i]!='.'
			)
			s.push_back(pom);
		}
	}*/
	if(s.size()==0){
    std::string pom;
    bool j(true);
        for(int i=0;i<str.size();i++){
            //std::string pom;
            if(i==str.length()-1 && str.length()!=1)
                s.push_back(pom);
            if(str[i]!=' ' && str[i]!=',')pom.push_back(str[i]);
            else {s.push_back(pom);pom.resize(0);j=false;}
            //std::cout<<"to je: "<<pom<<std::endl;
            if(i==str.length()-1)
                s.push_back(pom);
                if(str.length()==1)
                str.push_back(' ');
        }
        if(j==false)
        str.push_back(' ');
    }
	for(int v=0;v<s.size();v++){
		std::string g=s[v];
		int h=g.size();
		for(int i=0;i<str.size();i++){
			int p=i,j=0;
			if(g[j]==str[i]){
				while(g[j]==str[i]){
					j++;
					i++;
					if(i==str.size())break;
				}
				if(j==h && (str[p-1]==' ' || p==0) && (str[i]==' ' || i==str.size() || str[i]==',' || str[i]=='.')){
					char a=str[p];
					if(p!=0 || i!=str.size()-1 || str[i]=='.' || str[i]==',')
					i--;
					str.erase(str.begin() + p);
					str.insert(str.begin() +i,a);i++;
					str.insert(str.begin() + i,'a');i++;
					str.insert(str.begin() + i,'y');
				}
			}
		}
	}
	return str;
}
int main ()
{
	
	std::cout<<"Unesite recenicu: ";
	std::string s;
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> znakovi;
	std::string e;
	for(int i=0;;i++){
		std::getline(std::cin,e);
		if(e=="")break;
		znakovi.push_back(e);
	}
	try{
	std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,znakovi);
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	std::cout<<std::endl<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s,znakovi);
	return 0;
}