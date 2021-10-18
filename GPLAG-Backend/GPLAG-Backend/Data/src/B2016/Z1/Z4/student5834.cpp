#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
std::string ObrniFraze(std::string s,std::vector<std::string> v){
	if(v.size()==0) return s;
	int poc;
	for(int i=0;i<v.size();i++){
		std::string pom=v[i];
		int b=0;
		for(int a=0;a<pom.length();a++){
			if((pom[a]>='A' && pom[a]<='Z') || (pom[a]>='a' && pom[a]<='z') || pom[a]==' ') continue;
			else {b=1; break;}
		}
		if(b) continue;
		for(int j=0;j<s.length();j++){
			int k=0;
			if(s[j]==pom[k]){
				poc=j;
				while(s[j]==pom[k]){
					j++;k++;
				
					if(k==int(pom.length()) ) {
					int la=pom.length();
						for(int l=0;l<(pom.length()/2);l++){
							char x=s[poc+l];
							s[poc+l]=s[poc+la-1-l];
							s[poc+la-1-l]=x;
						}
						
					} 
					
				}
			}
			if(j==s.length()) j--;
		}
		
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s,std::vector<std::string> v){
	for(int i=0;i<v.size();i++){
		std::string s1=v[i];
		for(int j=0;j<s1.length();j++){
			if((s1[j]>='A' && s1[j]<='Z') || (s1[j]>='a' && s1[j]<='z')) continue;
			else throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	if(v.size()!=0){
	int poc;
	for(int i=0;i<v.size();i++){
		std::string pom=v[i];
		for(int j=0;j<s.length();j++){
			int k=0;
			if(s[j]==pom[k] ){
				poc=j;
				while(s[j]==pom[k] && j!=s.length()){
					j++;k++;}
					if(k==int(pom.length()) && j==s.length() && poc==0){
						char x=s[poc];
						s.erase(s.begin()+poc);
						s.insert(s.begin()+poc+k-1,x);
						s.insert(s.begin()+poc+k,'a');
						k++;
						s.insert(s.begin()+poc+k,'y');

					}
					if(k==int(pom.length()) && s[j]==' ' && s[poc-1]==' ' && j!=s.length()  && poc!=0) {
						char x=s[poc];
						s.erase(s.begin()+poc);
						s.insert(s.begin()+poc+k-1,x);
						s.insert(s.begin()+poc+k,'a');
						k++;
						s.insert(s.begin()+poc+k,'y');
					
					}
					if(k==int(pom.length()) && j==s.length() && s[poc-1]==' '){
						char x=s[poc];
						s.erase(s.begin()+poc);
						s.insert(s.begin()+poc+k-1,x);
						s.insert(s.begin()+poc+k,'a');
						k++;
						s.insert(s.begin()+poc+k,'y');
					
					}
					if(k==int(pom.length()) && s[j]==' '  && poc==0) {
						char x=s[poc];
						s.erase(s.begin()+poc);
						s.insert(s.begin()+poc+k-1,x);
						s.insert(s.begin()+poc+k,'a');
						k++;
						s.insert(s.begin()+poc+k,'y');
					
					}
						
				
				if(j>=s.length()) j--;	
				}
				
			}
		}
	}
	if(int(v.size())==0){
		int poc,k,kraj;
		for(int i=0;i<int(s.length());i++){
			poc=i; k=0;
			while(s[i]!=' ' && i!=s.length() ){
				i++; k++;
			
				}
				kraj=i-1;
				if( (s[poc]>='0' && s[poc]<='9') && (s[kraj]>='0' && s[kraj]<='9'))
				continue;
				char x=s[poc];
						s.erase(s.begin()+poc);
						s.insert(s.begin()+poc+k-1,x);
						s.insert(s.begin()+poc+k,'a');
						k++;
						s.insert(s.begin()+poc+k,'y');
				
				i+=2;
					
				

			if(i>=s.length()) i--;
		}
		
	}
	return s;
}
int main ()
{
	
	std::cout<<"Unesite recenicu: ";
	std::string s;
	std::getline(std::cin,s);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> v;
	std::string pom;
	do{
		std::getline(std::cin,pom);
	//	if(pom=='\n') break;
		if(pom.length()!=0 )
		v.push_back(pom);
	}while(pom.length()!=0);

	try{
	std::string rez1=IzmijeniUPigLatin(s,v);
	std::cout<<"Recenica nakon PigLatin transformacije: "<<rez1;
	std::cout<<std::endl;
	std::string rez2=ObrniFraze(s,v);
	std::cout<<"Recenica nakon obrtanja fraza: "<<rez2;
	}
	catch (std::domain_error x){
		std::cout <<"Izuzetak: "<< x.what() << std::endl;
		std::string rez2=ObrniFraze(s,v);
		std::cout<<"Recenica nakon obrtanja fraza: "<<rez2;
	}
	return 0;
}