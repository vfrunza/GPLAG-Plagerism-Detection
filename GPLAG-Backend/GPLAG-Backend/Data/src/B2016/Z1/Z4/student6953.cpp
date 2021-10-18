#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
std::string ObrniFraze(std::string s, std::vector<std::string> v){
	int pos, pos1;
	int  pks; 
	int kraj=0;
	for(int i=0; i<v.size(); i++){
		kraj=0; 
		for(int j=0; j<v[i].length(); j++){
			for(int k=0; k<s.length(); k++){
				if(s[k]==v[i][j]){ 
				pos=k; pos1=k;
					while(s[k]==v[i][j]){
						if(k==s.length()-1 || j==v[i].length()-1) break;
						k++; 
						j++; 
					}
					if(j!=v[i].length()-1) j=0;
					else if(j==v[i].length()-1) {
						if(s[k]==v[i][j]){
						pks=k;
						while(pos<=pks){
							s[pos]=v[i][j]; 
							j--; 
							pos++; 
						}
						j++; k=pos1;
					}}j=0;k=pos1;
				}
			if(k==s.length()-1) {kraj=1; break;}  	 
			}
		if(kraj) break;  
		}
	}
	return s; 
}
std::string IzmijeniUPigLatin (std::string s, std::vector<std::string> v){
	if(v.size()==0){
		std::string q; 
		int k=0;
		for(int i=0; i<s.length(); i++){
			if((s[i]>='a'&& s[i]<='z') || (s[i]>='A' && s[i]<='Z') && (i==0 || !((s[i-1]>='a'&& s[i-1]<='z') || (s[i-1]>='A' && s[i-1]<='Z')))){
				k++;
			 	int j=0; q.resize(0);
				while((s[i]>='a'&& s[i]<='z') || (s[i]>='A' && s[i]<='Z')) { q.push_back(s[i]); j++; i++;}
				v.resize(k);
			 	std::string novi=q; 
			 	v.push_back(novi);
			}
		}
	}
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			if(!((v[i][j]>='a' && v[i][j]<='z')||(v[i][j]>='A' && v[i][j]<='Z'))) throw std::domain_error("Izuzetak: Nekorektan izbor rijeci"); 
		}
	}
	char *pos; 
	int kraj=0, adr;
	for(int i=0; i<v.size(); i++){
		kraj=0; 
		for(int j=0; j<v[i].length(); j++){
			for(int k=0; k<s.length(); k++){
				if(s[k]==v[i][j] && (k==0 || !((s[k-1]>='a'&& s[k-1]<='z') || (s[k-1]>='A' && s[k-1]<='Z')))){
					pos=&s[k]; 
					adr=k; 
					while(s[k]==v[i][j] ){
						if(k==s.length()-1 || j==v[i].length()-1) break;
						k++; 
						j++; 
					}
					if(j!=v[i].length()-1 ) j=0; 
						else if(j==v[i].length()-1 && (k==s.length()-1 || !((s[k+1]>='a'&& s[k+1]<='z') || (s[k+1]>='A' && s[k+1]<='Z'))) ){
							if(s[k]==v[i][j]){
							k++;
							s.insert(s.begin()+k, *pos);
							s.insert(s.begin()+k+1, 'a');
							s.insert(s.begin()+k+2, 'y'); 
							s.erase(s.begin()+adr); 
							j=0; 
						}}j=0;
					}
					if(k==s.length()-1) {kraj=1; break;}
				}
				if(kraj==1) break; 
			}
		}
	return s; 
 }
int main (){
 std::cout<<"Unesite recenicu: "; 
	std::string s; 
	std::getline((std::cin), s); 
	std::cout<<"Unesite fraze: "; 
	std::vector<std::string>a;
    std::string prazan; 
    std::string fraza;
     std::string c;
     std::string b;
    for(;;){
    	std::getline(std::cin, fraza);
		if(fraza==prazan)break;
		a.push_back(fraza);
   }	
	try{  b=IzmijeniUPigLatin(s,a); 
	 	std::cout<<"Recenica nakon PigLatin transformacije: "<<b<<"\n";
		c=ObrniFraze(s,a);
	    std::cout<<"Recenica nakon obrtanja fraza: "<<c;
	}
	catch(std::domain_error izuzetak) {
		 std::cout << izuzetak.what() << std::endl;
		 c=ObrniFraze(s,a);
	     std::cout<<"Recenica nakon obrtanja fraza: "<<c;
	}
	return 0;
}