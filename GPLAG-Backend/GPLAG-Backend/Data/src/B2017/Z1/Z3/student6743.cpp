#include <iostream>
#include<deque>
#include<vector>
#include<cmath>


enum Smjer {Rastuci,Opadajuci};



 bool DaLiJeStepenDvojke(int n){
 
  for(int i(0);i<n;i++)
    
    if(pow(2,i)==n) return true;
    
    return false;
 	
 }



  std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v,Smjer s){
  	
  	std::deque<std::vector<int>> D;
  	int br(0);
  	
  	if(s==Rastuci){
  		while(br<v.size()){
  		std::vector<int> vektor;
  		
  		int i(0);
  		
  		while(v.at(i)<v.at(i+1)){
  		br++;	
  		vektor.push_back(v.at(i));
  		i++;
  		if(i+1==v.size()) break;
  		}
  		
  		D.push_back(vektor);
  	   
  			br++;
  		}
  	
  	}
  	
  	
  		if(s==Opadajuci){
  		while(br<v.size()){
  		std::vector<int> vektor;
  		
  		int i(0);
  		
  		while(v.at(i)>v.at(i+1)){
  		br++;	
  		vektor.push_back(v.at(i));
  		i++;
  		if(i+1==v.size()) break;
  		}
  		
  		D.push_back(vektor);
  	   
  			br++;
  		}
  	
  	}
  	
  	
  	return D;
  }
 

int main ()
{
	std::deque<std::vector>> D;
	
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	
	std::vector<int> V;
	
	std::cout<<"Unesite elemente vektora: ";
	
	for(int i(0);i<n;i++){

        int x;
        std::cin>>x;
        V.push_back(x);
	}
      
      std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
      int x;
      std::cin>>x;
      
      if(x==1)
      
      std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
      else
       std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
       
       D=MaksimalniPodnizoviStepenaDvojke(v,Smjer(x));
       
       for(int i(0);i<D.size();i++){
       	for(int j(0);D.at(i).size();j++){
       		
       		if(j==0)
       		 std::cout<<D.at(i).at(j);
       		 else 
       		 std::cout<<" "<<D.at(i).at(j);
       	}
       	std::cout<<std::endl;
       }
       	
       
	
	
	
	return 0;
}