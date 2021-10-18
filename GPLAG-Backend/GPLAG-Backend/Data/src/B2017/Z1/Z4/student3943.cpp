#include <iostream>
#include <vector>
#include <string>

std::string NapraviPalindrom(std::string s,const std::vector<std::string> &v)
{
	for(int i=0; i<v.size(); i++) {

		int j(0);
		int k(0);
		while(j<s.length()) {
			k=0;
			while(j<s.length() && k<v.at(i).length() && s.at(j)==v.at(i).at(k)) {
				
				j++;
				k++;
				if(k==v.at(i).length() && ( j==s.length() || ((s.at(j)<='A' && s.at(j)>='Z') && (s.at(j)<='a' && s.at(j)>='z') ))) {

					if(j==s.length()) {
						for(int m=v.at(i).length()-1; m>=0; m--) {
							s.push_back(v.at(i).at(m));
						}

					} else {

						for(int n=v.at(i).length()-1; n>=0; n--) {

							s.insert(s.begin()+j,v.at(i).at(n));
							j++;
						}


					}

				}
			}
			j++;
		}

	}

	return s;
}


std::string NapraviPoluPalindrom(std::string s,const std::vector<std::string> &v)
{

	for(int i=0; i<v.size(); i++) {

		int j(0);
		int k(0);
		while(j<s.length()) {
			k=0;
			while(j<s.length() && k<v.at(i).length() && s.at(j)==v.at(i).at(k)) {
				j++;
				k++;
				if(k==v.at(i).length() && ( j==s.length() || ((s.at(j)<='A' && s.at(j)>='Z') && (s.at(j)<='a' && s.at(j)>='z') ))) {

					int pomak=j-(v.at(i).length()/2);


					for(int m=(v.at(i).length()/2)-1; m>=0; m--) {
						
						s.erase(s.begin()+pomak);
						s.insert(s.begin()+pomak,v.at(i).at(m));
				
						pomak++;
					}


				}

			}

			j++;

		}

	}

	return s;
}


int main()
{
	std::string s;
	std::string s1;
	std::string s2;
	std::vector<std::string> v;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::cout<<"Unesite fraze: ";
	for(;;) {
		std::string prazni_string,s3;
		std::getline(std::cin,s3);
		if(s3==prazni_string)
			break;

		v.push_back(s3);




	}
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	s1=NapraviPalindrom(s,v);
	std::cout<<s1<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	s2=NapraviPoluPalindrom(s,v);
	std::cout<<s2;





	return 0;

}