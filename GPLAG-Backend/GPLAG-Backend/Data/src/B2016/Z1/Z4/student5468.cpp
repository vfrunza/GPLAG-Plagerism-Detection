#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
typedef std::vector<std::string> vstring;

std::string ObrniFraze(std::string a, vstring b){
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<a.size(); j++){
			if(b[i]==a.substr(j,b[i].size())){
				for(int k=j; k<j+(b[i].size()/2);k++){
					char temp=a[k];
					a[k]=a[2*j+b[i].size()-k-1];
					a[2*j+b[i].size()-k-1]=temp;
				}
			}
		}
	}
	return a;
}

std::string IzmijeniUPigLatin(std::string a, vstring b){
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<b[i].size(); j++){
			if((b[i][j]<'A' or b[i][j]>'Z')and(b[i][j]<'a' or b[i][j]>'z'))
				throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	if(b.size()==0){
		for(int j=0; j<a.size(); j++){
			if((a[j]<'A' or a[j]>'Z')and(a[j]<'a' or a[j]>'z')){   //ako nije slovo continue
				continue;
			}
	
			int k(j);      //uzmi pocetak rijeci

			while((j<a.size()) and ((a[j]>='A' and a[j]<='Z')or(a[j]>='a' and a[j]<='z'))){
				j++;
			}
			j--; // j je posljednje slovo rijeci
			char temp(a[k]);
					a.erase(a.begin()+k);
					a.insert(a.begin()+j, temp);
					j++;
					a.insert(a.begin()+j , 'a');
					j++;
					a.insert(a.begin() +j , 'y');    
		}	
	}
	else
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<a.size(); j++){
			if(b[i]==a.substr(j,b[i].size())and((j+b[i].size()==a.size())or(((a[b[i].size()+j]<'A' or a[b[i].size()+j]>'Z')and(a[b[i].size()+j]<'a' or a[b[i].size()+j]>'z')) and (j==0 or ((a[j-1]<'A' or a[j-1]>'Z')and(a[j-1]<'a' or a[j-1]>'z')))))){
				char temp(a[j]);
				for(int k=j; k<j+(b[i].size())-1;k++)
					a[k]=a[k+1];
					a[j+(b[i].size())-1]=temp;
					a.insert(a.begin() +(j+(b[i].size())) , 'a');
					a.insert(a.begin() +(j+(b[i].size())+1) , 'y');
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
	try{
	std::string s(IzmijeniUPigLatin(recenica,fraze));
	std::cout<<"Recenica nakon PigLatin transformacije: "<<s<<std::endl;
	}
	catch(std::domain_error izuzetak) {
 		std::cout<<"Izuzetak: " << izuzetak.what() << std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,fraze);
	return 0;
}