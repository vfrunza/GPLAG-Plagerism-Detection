/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector> 
#include <stdexcept>
#include<string> 
std::string ObrniFraze(std::string recenica, std::vector<std::string> vektor){
	std::string promjenljiva;  
	promjenljiva=recenica;  
	std::string pomocni;
	for(int j(0); j<vektor.size(); j++){
		for(int i(0); i<recenica.length(); i++){ 
			pomocni=promjenljiva.substr(i, vektor[j].length());
			if(pomocni==vektor[j]){ 
				int temp=vektor[j].length(),dodaj=0;
				for(int k=0;k<temp/2;k++){
					dodaj++;
					char tmp=promjenljiva[i+k];
					promjenljiva[i+k]=promjenljiva[i+temp-k-1];
					promjenljiva[i+temp-k-1]=tmp;
				}
			}
		}
	} 
	return promjenljiva;
} 
std::string pomjeriUDesno(std::string hehic, int dokle){
	std::string temp;
	temp.resize(hehic.length()+2);
	for(int i=hehic.length()-1;i>=dokle;i--) temp[i+2]=hehic[i];
	return temp;
}
std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> vektor){
	for(auto fraza: vektor){
		for(auto slovo: fraza){
			if(slovo<'A' || (slovo>'Z' && slovo<'a') || slovo>'z' )
				throw std::domain_error ("Nekorektan izbor rijeci");
		}
	}
	std::string promjenljiva;    
	promjenljiva=recenica; 
	std::string pomocni;
	for(int j(0); j<vektor.size(); j++){
		for(int i(0); i<recenica.length(); i++){ 
			pomocni=recenica.substr(i, vektor[j].length());
			if(pomocni==vektor[j]){ 
				if(i==0 && recenica[i+pomocni.length()+1]==' '){
					char tmp=recenica[i];
					for(int k=0;k<pomocni.length()-1;k++) {
						recenica[k]=recenica[k+1];
						i++;
					}
					recenica[i]=tmp;
					recenica=pomjeriUDesno(recenica,i);
					recenica[++i]='a';
					recenica[++i]='y';
				}
				else if(i+pomocni.length()==recenica.length()-1 && recenica[i-1]==' '){
					char tmp=recenica[i];
					for(int k=0;k<pomocni.length()-1;k++)
						recenica[k+i]=recenica[k+1+i];
					i+=pomocni.length();
					recenica[i]=tmp;
					recenica=pomjeriUDesno(recenica,i);
					recenica[++i]='a';
					recenica[++i]='y';
				}
				else{
					char tmp=recenica[i];
					for(int k=0;k<pomocni.length()-1;k++) recenica[k+i]=recenica[k+i+1];
					i+=pomocni.length();
					recenica[i]=tmp;
					recenica=pomjeriUDesno(recenica,i);
					recenica[++i]='a';
					recenica[++i]='y';
				}
			}  
			
		}
	} 
	return recenica;
}
int main ()
{
	std::string recenica;
	std::vector<std::string> vektor;  
	std::string fraza;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: "; 
	char znak;
	while((znak=std::cin.peek())!='\n'){
		std::getline(std::cin, fraza); 
		vektor.push_back(fraza);
	} 
	std::string s1; 
	try{
		s1=IzmijeniUPigLatin(recenica, vektor);
		std::string s2;
		s2=ObrniFraze(recenica, vektor);
		std::cout << "Recenica nakon PigLatin transformacije: " << s1 << std::endl; 
		std::cout << "Recenica nakon obrtanja fraza: " << s2;
	}
	catch(std::domain_error uf){
		std::cout<<"Izuzetak: "<<uf.what()<<std::endl;
		std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,vektor);
	}
	return 0;
}