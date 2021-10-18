#include <iostream> 
#include <stdexcept>
#include <string>   
#include <iterator>
#include <vector> 
#include <set>
#include <list>
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> Djeca, int k){
	std::list<std::string> List; 
	std::vector<std::set<std::string>> povratna(k);
	for(int i(0); i<Djeca.size(); i++) List.push_back(Djeca.at(i));
	int a=Djeca.size()/k;
	int b=Djeca.size()%k; 
	std::list<std::string>::iterator  iter; 
	iter=List.begin(); 
	int br_pomjeraja(0), br1(1); 
	for(int i(0); i<k; i++){ 
		if(i==0) br1=0;
		if(i<b){ 
			int br2(0); 
			int k(0);
		    while(k!=1){  
			    if(iter==List.end()) iter=List.begin();
			    if(br1==br_pomjeraja){
				    povratna.at(i).insert(*iter);
				    br_pomjeraja=(*iter).size();
				    iter=List.erase(iter);  
				    br1=0;
				    br2++;
			    }   
			    else iter++; 
			    br1++;
			    if(br2==a+1) break;
		    }
	    } 
	    else{            
	    	int br2(0); 
	    	int k(0);
	    	while(k!=1){  
	    		if(iter==List.end()) iter=List.begin();
	    		if(br1==br_pomjeraja){
	    			povratna.at(i).insert(*iter);
	    			br_pomjeraja=(*iter).size();
	    			iter=List.erase(iter); 
	    			br1=0;
	    			br2++;
	    		} 
	    		else iter++; 
	    		br1++;
	    		if(br2==a) break;
	    	}
	    }
	}  
	return povratna;
}
int main()
{  
	try{
		int n, k;
	    std::cout << "Unesite broj djece: ";
	    std::cin >> n;  
	    std::cin.ignore(10000, '\n');
	    std::vector<std::string> Djeca(n); 
	    std::cout << "Unesite imena djece: ";
	    for(int i=0; i<n; i++){
	    	std::getline(std::cin, Djeca.at(i));    
	    } 
	    std::cout << std::endl << "Unesite broj timova: ";
	    std::cin >> k; 
	    if(k<1 || k>n) throw std::logic_error("Razvrstavanje nemoguce"); 
	    auto f(Razvrstavanje(Djeca, k));
	    for(int i=0; i<k; i++){
	    	std::cout << "Tim " << i+1 << ": ";   
	    	std::set<std::string>::iterator x(f.at(i).begin());
	    	while(x!=f.at(i).end()){ 
	    		if(x!=--f.at(i).end()) std::cout << *x << ", "; 
	    	    else std::cout << *x;
	    	    x++;
	    } 
	    std::cout << std::endl;
	} 
	}
	catch(std::logic_error izuzetak){
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	return 0;
}