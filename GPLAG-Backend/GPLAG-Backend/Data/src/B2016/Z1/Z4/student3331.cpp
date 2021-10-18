/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<string>
#include<vector> 
#include<stdexcept>
#include<iomanip>

std::string recenica;
std::vector<std::string> fraze;

std::string OkreniRijec(std::string s){
   std::string novi = "";
   
   for(int i= s.length()-1; i>=0; --i)
   novi += s[i];
	
	return novi;
}


std::string ObrniFraze(std::string s, std::vector<std::string> v){
   bool prvi =false;
  
	 std::string novi(s);
        for (auto x : v) {
        	std::string okrenuti = OkreniRijec(x);
        	int i=0;
        	while( i < novi.length()) {
              prvi = false;
              
                if (novi[i] == x[0]) {
                   
                   int j(0), k(i), l(i);
                   while ( novi[i] == x[j]  ) {
                         i++; 
                         j++;
                         prvi = true;
                         if (j == x.length()) {
                         	int m=0;
                         	while ( m < okrenuti.length() && k != novi.length() ) {
                         		novi[k] = okrenuti[m];
                         		k++;
                         		m++;
                         	}
                         	if(m != 0) i=l+1;
                         }
                   }
                }
              if(prvi == false)  i++;
                
            }
        }

	return novi;
}

bool nisuEngSlova(std::vector<std::string> v){
	bool imalSta = false;
	for(std::string s : v){
		for(char slovo : s)
			if(!((slovo >= 'a' && slovo <= 'z') || (slovo >= 'A' && slovo <= 'Z'))) imalSta = true;
	}
	
	if(imalSta) return true;
	return false;
}



std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v){
	if(nisuEngSlova(v)) throw std::domain_error("Nekorektan izbor rijeci");
	std::string novi(s);
	if(int(v.size()) != 0){
        for (auto x : v) {
            for (int i = 0; i < novi.length(); i++) {
                if (novi[i]==x[0]) {
                   int j(0), k(i);
                   while (novi[i] == x[j]) { 
                         i++; j++;
                         if (j == x.length()  && ((   !((novi[i] >= 'a' && novi[i] <='z') || (novi[i] >= 'A' && novi[i] <='Z'))  || i== novi.length())   && ( k==0 || !((novi[k-1] >= 'a' && novi[k-1] <='z') || (novi[k-1] >= 'A' && novi[k-1] <='Z') )) )) {
                         	std::string slovo;
                         	slovo.push_back(novi[k]);
                         	novi.erase(novi.begin()+k);
                         	novi.insert(i-1,slovo+std::string("ay"));
                           
                         }
                   }
                }
            }
        }
	}
	else{
	    for(int i=0; i< novi.length(); i++){
	        if(((novi[i] >= 'a' && novi[i] <='z') || (novi[i] >= 'A' && novi[i] <='Z'))){
	            int j(i);
	            while ( ((novi[i] >= 'a' && novi[i] <='z') || (novi[i] >= 'A' && novi[i] <='Z'))  && i < novi.length() )
	                i++;
	            if(!((novi[i] >= 'a' && novi[i] <='z') || (novi[i] >= 'A' && novi[i] <='Z')) || i == novi.length()){
	                        std::string slovo;
                         	slovo.push_back(novi[j]);
                         	novi.erase(novi.begin()+j);
                         	novi.insert(i-1,slovo+std::string("ay"));
                        if( i+1 < novi.length()) i+=1;
                         	
	            }
	            
	        }
	    }
	}

	return novi;
	
}


int main ()
{
	try{
 
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, recenica);
  
    std::string s;
    std::cout << "Unesite fraze: ";
    for (;;) {
        std::getline(std::cin, s);
        if (!s.length()) break;
        fraze.push_back(s);
      
    }
    std::string sa = IzmijeniUPigLatin(recenica, fraze);
    
    std::cout << "Recenica nakon PigLatin transformacije: ";
    std::cout << sa << std::endl;
    
	}catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	
	}
		 std::cout << "Recenica nakon obrtanja fraza: ";
		std::cout << ObrniFraze(recenica,fraze); 
	
 

	
	
    return 0;
}

	
