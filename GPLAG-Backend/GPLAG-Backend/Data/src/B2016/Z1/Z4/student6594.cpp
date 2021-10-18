#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
typedef std::vector<std::string> vstring;

std::string ObrniFraze(std::string a, vstring b){
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<a.size(); j++){
			if(b[i]==a.substr(j,b[i].size())){
				for(int k=j; k<j+(b[i].size());k++){
					a.insert(a.begin()+(j+b[i].size()),a[k]);
					
					
				}
			}
		}
	}
	return a;
}
std::string ObrniFraze2(std::string a, vstring b){
	int l;
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<a.size(); j++){
			if(b[i]==a.substr(j,b[i].size())){
				if((b[i].size())%2!=0) {
					a.erase(j+b[i].size()/2);
				}
				for(int k=j; k<j+(b[i].size())/2;k++){
					a.insert(a.begin()+(j+b[i].size()/2),a[k]);
						}
			}
		} 
	}
	return a;
}



int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	vstring fraze;
	for(int i=0;;i++){
		if(std::cin.peek()=='\n')
			break;
		else{
			std::string fraza;
			std::getline(std::cin,fraza);
			fraze.push_back(fraza);
		}
	}
	
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,fraze);
		std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze2(recenica,fraze);

	return 0;
}