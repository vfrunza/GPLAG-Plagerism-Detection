/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector> 
#include <string>
#include <stdexcept>

std::string ObrniFraze (std::string str, std::vector<std::string> v){
	std::string s(str);
	for(int i=0; i<v.size(); i++){
		std::string trenutni(v[i]);
		for(int j=0; j<s.length(); j++){
		/*	bool moze(true);
			if(j!=0 && ((s[j-1]>='a' && s[j-1]<='z') || (s[j-1]>='A' && s[j-1]<='Z')))
			  moze = false;*/
			if(s[j]==trenutni[0] ){
				int k(0);
				int poc(j);
				while(j<s.length() && k<trenutni.length() && s[j]==trenutni[k]){
					j++;
					k++;
				}
		/*	bool moze_2(true);
			if(j!=s.length() && ((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z')))
			  moze_2 = false;*/
			if(k==trenutni.length()) {
				j--;
				int kraj(j);
				while(1){
					char temp(s[poc]);
					s[poc] = s[kraj];
					s[kraj] = temp;
					poc++;
					kraj--;
					if(poc==kraj || poc>kraj)
					 break;
				}
			}
			}
		}
	}
return s;
}


std::string IzmijeniUPigLatin (std::string str, std::vector<std::string> v){
	std::string s(str);
	for(int i=0; i<v.size(); i++){
		std::string trenutni(v[i]);
		for(int j=0; j<trenutni.length(); j++)
		  if(!((trenutni[j]>='a' && trenutni[j]<='z') || (trenutni[j]>='A' && trenutni[j]<='Z')))
		    throw std::domain_error("Nekorektan izbor rijeci");
	}
    if(v.size()==0){
    	for(int i=0; i<s.length(); i++){
    		bool moze(true);
    		if(i!=0 && ((s[i-1]>='a' && s[i-1]<='z') || (s[i-1]>='A' && s[i-1]<='Z')))
    		  moze = false;
    		if(moze && ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))){
    			int poc(i);
    			while((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) 
    			  i++;
    			if(i!=s.length()){
    			char sacuvaj(s[i]);
    		    s[i] = s[poc];
    		    s.insert(s.begin()+i+1, 'a');
    		    s.insert(s.begin()+i+2, 'y');
    		    s.insert(s.begin()+i+3, sacuvaj);
    		    s.erase(s.begin()+poc);
    			}
    			else if(i==s.length()){
    				char sacuvaj(s[i]);
    				s.insert(s.begin()+i, s[poc]);
    				s.insert(s.begin()+i+1, 'a');
    				s.insert(s.begin()+i+2, 'y');
    				s.insert(s.begin()+i+3, sacuvaj);
    				s.erase(s.begin() + poc);
    				
    			}
    		}
    	}
    }
    
   else{
   	for(int i=0; i<v.size(); i++){
   		std::string trenutni(v[i]);
   		for(int j=0; j<s.length(); j++){
   			bool moze(true);
   			if(j!=0 && ((s[j-1]>='a' && s[j-1]<='z') || (s[j-1]>='A' && s[j-1]<='Z')))
   			  moze = false;
   			 if(moze && s[j]==trenutni[0]){
   			 	int k(0);
   			 	int poc(j);
   			 	while(j<s.length() && k<trenutni.length() && s[j]==trenutni[k]){
   			 		j++;
   			 		k++;
   			 	}
   			 	if(k==trenutni.length() && j==s.length()){
   			 		s.insert(s.begin()+j, s[poc]);
   			 		s.insert(s.begin()+j+1, 'a');
   			 		s.insert(s.begin()+j+2, 'y');
   			 		s.erase(s.begin()+poc);
   			 		
   			 	}
   			 bool moze_2(false);
   			 if(j!=s.length() && !((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z')))
   			   moze_2 = true;
   			 if(k==trenutni.length() && moze_2 ){
   			 	char sacuvaj(s[j]);
   			 	s[j] = s[poc];
   			 	s.insert(s.begin()+j+1, 'a');
   			 	s.insert(s.begin()+j+2, 'y');
   			 	s.insert(s.begin()+j+3, sacuvaj);
   			 	s.erase(s.begin()+poc);
   			 }
   			 }
   		}
   	}
   }
  return s;
    
}








int main ()
{
	std::string recenica;
	
	
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::vector<std::string> v;
	std::string s;
	std::cout<<"Unesite fraze: ";
	while(1){
		std::getline(std::cin, s);
		if(s.length()==0)
		  break;
		v.push_back(s);
	}

	std::string s3(ObrniFraze(recenica,v));
	
	try{
		std::string s2(IzmijeniUPigLatin(recenica,v));
		std::cout<<"Recenica nakon PigLatin transformacije: "<<s2;
	}
	catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	std::cout<<"\nRecenica nakon obrtanja fraza: "<<s3;
	return 0;
}







