#include<iostream>
#include<iomanip>
#include<stdexcept>
#include<vector>
#include<string>
std::string ObrniFraze(std::string s,std::vector<std::string>popis){
	std::string prethodni="0";
	for(int k=0;k<popis.size();k++){
	for(int i=0;i<s.size()-1;i++){
			for(int j=i+1;j<s.size();j++){
				if(s.substr(i,j-i+1)==popis[k]){
					int t1(i),t2(j);
						while(t1!=t2){
							char pomocni;
							pomocni=std::move(s[t1]);
							s[t1]=std::move(s[t2]);
							s[t2]=std::move(pomocni);
							if(t1+1==t2)break;
							t1++;t2--;
						}
						i++;break;
				}
			}
		}}
		return s;
	}
	std::string IzmijeniUPigLatin(std::string s,std::vector<std::string>popis){
		int d=1;
		for(int i=0;i<s.size();i++){
			if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')){
				d=0;
			break;}
		}
		if(d)return s;
		if(popis.size()==0){
			int logicka=0;
				for(int i=0;i<s.size()-1;i++){
					logicka=0;
			for(int j=i+1;j<s.size();j++){
				if((((s[i-1]<'A'||s[i-1]>'Z')&&(s[i-1]<'a'||s[i-1]>'z'))&&((s[j+1]<'A'||s[j+1]>'Z')&&(s[j+1]<'a'||s[j+1]>'z')&&((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))&&((s[j]>='A'&&s[j]<='Z')||(s[j]>='a'&&s[j]<='z'))))||(i==0&&((s[j+1]<'A'||s[j+1]>'Z')&&(s[j+1]<'a'||s[j+1]>'z'))&&((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))&&((s[j]>='A'&&s[i]<='Z')||(s[j]>='a'&&s[j]<='z')))||(j==s.size()-1&&((s[i-1]<'A'||s[i-1]>'Z')&&(s[i-1]<'a'||s[i-1]>'z')&&((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))&&((s[j]>='A'&&s[j]<='Z')||(s[j]>='a'&&s[j]<='z'))))){
					int t1(i),t2(j);
					logicka=1;
					while(t1<t2){
							char pomocni;
							pomocni=s[t1];
							s[t1]=s[t1+1];
							s[t1+1]=pomocni;
					t1++;}
					s.push_back('a');
					s.push_back('y');
					for(int l=s.size()-2;l>t2+1;l--){
						int pomocni;
						pomocni=std::move(s[l]);
						s[l]=std::move(s[l-1]);
						s[l-1]=std::move(pomocni);
					}
						for(int r=s.size()-1;r>t2+2;r--){
						int pomocni;
						pomocni=std::move(s[r]);
						s[r]=std::move(s[r-1]);
						s[r-1]=std::move(pomocni);
					}
				}
				if(logicka)break;
			}
		}
		return s;	
		}
		for(int i=0;i<popis.size();i++){
			for(int j=0;j<popis[i].size();j++){
			if((popis[i][j]<'A'||popis[i][j]>'Z')&&(popis[i][j]<'a'||popis[i][j]>'z'))
			throw std::domain_error("Nekorektan izbor rijeci");
			}
		}
		for(int k=0;k<popis.size();k++){
	for(int i=0;i<s.size()-1;i++){
			for(int j=i+1;j<s.size();j++){
				if((s.substr(i,j-i+1)==popis[k]&&((s[i-1]<'A'||s[i-1]>'Z')&&(s[i-1]<'a'||s[i-1]>'z'))&&((s[j+1]<'A'||s[j+1]>'Z')&&(s[j+1]<'a'||s[j+1]>'z')))||(i==0&&s.substr(i,j-i+1)==popis[k]&&((s[j+1]<'A'||s[j+1]>'Z')&&(s[j+1]<'a'||s[j+1]>'z')))||(j==s.size()-1&&s.substr(i,j-i+1)==popis[k]&&((s[i-1]<'A'||s[i-1]>'Z')&&(s[i-1]<'a'||s[i-1]>'z')))){
					int t1(i),t2(j);
					while(t1<t2){
							char pomocni;
							pomocni=s[t1];
							s[t1]=s[t1+1];
							s[t1+1]=pomocni;
					t1++;}
					s.push_back('a');
					s.push_back('y');
					for(int l=s.size()-2;l>t2+1;l--){
						int pomocni;
						pomocni=std::move(s[l]);
						s[l]=std::move(s[l-1]);
						s[l-1]=std::move(pomocni);
					}
						for(int r=s.size()-1;r>t2+2;r--){
						int pomocni;
						pomocni=std::move(s[r]);
						s[r]=std::move(s[r-1]);
						s[r-1]=std::move(pomocni);
					}
				}
			}
		}}
		return s;
	}
	
	
	

int main ()
{
	std::string s;
	std::string s1;
	std::string s2;
	std::vector<std::string>a;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::cout<<"Unesite fraze: ";
	while(std::cin.peek()!='\n'){
		std::getline(std::cin,s1);
		a.push_back(s1);
	}
	s2=ObrniFraze( s,a);
	try{
	s1=IzmijeniUPigLatin(s,a);
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	std::cout<<s1<<"\n";
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
		std::cout<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::cout<<s2;
 

   
	return 0;
}