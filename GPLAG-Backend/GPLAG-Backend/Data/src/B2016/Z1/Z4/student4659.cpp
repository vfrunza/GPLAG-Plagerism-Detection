/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
typedef std::vector<std::string> Vektor;
std::string ObrniFraze(std::string s,Vektor a){
	
	for(int i=0;i<a.size();i++){
		for(int j=0;j<s.length();j++){
			int z(0);
			while(a[i][z]==s[j] && j<s.length()){
				z++;
				j++;
			}
			if(z==a[i].length()){
				z=0;
				while(z!=a[i].length()){
					j--;
					s[j]=a[i][z];
					z++;
				}
				j++;
			}
			
		}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s,Vektor a){
	
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			if(a[i][j]>='A' && a[i][j]<='Z' || a[i][j]>='a' && a[i][j]<='z') continue;
			else throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	if(a.empty()){
		int flag(0);
	    for(int i=0;i<s.length();i++){
	    	if(s[i]<'A' || (s[i]>'Z' && s[i]<'a') || s[i]>'z')flag=0;
			    else if(++flag==1){
	        	int j(i);
	        	while(j<s.length() && ((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z'))){
	        		j++;
	        	}
	        	char k(s[i]);
	        	s[i]=s[j-1];
	        	s[j-1]=k;
	        	s=s.substr(0,j)+"ay"+s.substr(j,s.length());
	        	while(i<j-2){
	        		k=s[i];
	        		s[i]=s[i+1];
	        		s[i+1]=k;
	        		i++;
	        	}
	        	i+=2;
	        }
	    }
	}	
	else{
		int flag(0);
	    for(int i=0;i<a.size();i++){
     	 	for(int j=0;j<s.length();j++){
     	 		if(s[j]<'A' || (s[j]>'Z' && s[j]<'a') || s[j]>'z')flag=0;
			    else if(++flag==1 && a[i][0]==s[j]){
	    		int z(0);
	    		while(a[i][z]==s[j] && j<s.length()){
		    		z++;
			    	j++;
			    }
			    if(z==a[i].length() && ((s[j]<'A' || (s[j]>'Z' && s[j]<'a') || s[j]>'z' || j==s.length()))){
				    j--;
				    s[j]=a[i][0];
				    s=s.substr(0,j+1)+"ay"+s.substr(j+1,s.length());
                    z--;
                    while(z>0){
                	    j--;
                	    s[j]=a[i][z];
                	    z--;
                    }
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
    std::cout << "Unesite recenicu: ";
	std::getline(std::cin,recenica);        Vektor a;
        std::cout << "Unesite fraze: ";
        std::string fraza;
        while(1){
         	std::getline(std::cin,fraza);
        	if(fraza.empty())break;
        	a.push_back(fraza);
        }
        try{
	        std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica,a) << std::endl;
        }
        catch(std::domain_error izuzetak){
        	std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
        }
	    std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica,a);
	return 0;
}