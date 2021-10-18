/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> f){
	
	for(int j=0;j<f.size();j++){
		for(int i=0;i<s.length();i++){
			if(s.substr(i,f[j].size())==f[j]){
				int k=i, r=i+f[j].length()-1;
				while(k<r){
					char temp=s[k];
					s[k]=s[r];
					s[r]=temp;
					k++;
					r--;
				}
			}
		}
	}
	return s;
}

bool DaLiJeBroj (std::string broj) {
	for (int i = 0; i < broj.length(); i++) {
		if (broj[i] >= '1' && broj[i] <= '9') {
			return true;
		}
	}
	return false;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> f){
	bool g(true);

		for(int i=0;i<f.size();i++){
			if(f[i]!="") {g=false;break;}
		}
		
		if(g==true){  //ako jest potrebno je sve
			std::vector<std::string> rijeci;
			for(int q=0;q<s.length();q++){
				std::string pomocni="";
				while(s[q]!=' ' && q<s.length()){
					
					//if((s[q]>='a' && s[q]<='z' )||(s[q]>='A' && s[q]>='Z') )
						pomocni+=s[q];
					q++;
				}
				if (!DaLiJeBroj(pomocni))
					rijeci.push_back(pomocni);
				
		    }
		    f=rijeci;
		}
	    
			for(int i=0;i<s.length();i++){
				for(int j=0;j<f.size();j++){
					if(i==0 && s.substr(i,f[j].size())==f[j] && ((s[f[j].size()+i]<'A' || s[f[j].size()+i]>'Z') && (s[f[j].size()+i]<'a' || s[f[j].size()+i]>'z')) ){
						char temp=s[i];
						s=s.substr(0,i)+s.substr(i+1,f[j].length()-1)+temp+"ay"+s.substr(i+f[j].length(),s.length());
					}
					else if(s.substr(i,f[j].size())==f[j] && ((s[f[j].size()+i]<'A' || s[f[j].size()+i]>'Z') && (s[f[j].size()+i]<'a' || s[f[j].size()+i]>'z' )) && ((s[i-1]<'A' || s[i-1]>'Z') && (s[i-1]<'a' || s[i-1]>'z'))  ){
						char temp=s[i];
						s=s.substr(0,i)+s.substr(i+1,f[j].length()-1)+temp+"ay"+s.substr(i+f[j].length(),s.length());
					}
				}
			}
	return s;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica, f;
	std::getline(std::cin,recenica);
	bool b(true);
	
		std::cout<<"Unesite fraze: ";
		
		std::vector<std::string> fraze;
	try{
		do{
			std::getline(std::cin,f);
			if(f=="\n") break;
			for(int i=0;i<f.length();i++){
				if((f[i]<'A'|| f[i]>'Z') && (f[i]<'a' || f[i]>'z')) b=false;
			}
			fraze.push_back(f);
		}
		while(f!="");
		fraze.resize(fraze.size()-1);
	    if(!b) throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica, fraze)<<std::endl;
		
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
		
		std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, fraze)<<std::endl;
	
	return 0;
}