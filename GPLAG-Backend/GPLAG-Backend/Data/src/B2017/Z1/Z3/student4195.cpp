

#include <iostream>
#include <vector> 
#include <cstring>
#include <string>
#include <deque>


enum Smjer {Rastuci, Opadajuci};


bool Stepen(int n)
{
	if (n<=0) return false;
	
	while(n%2==0){
		n/=2;
		
	}
	return n==1;

}


std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer direction )
{

	std::deque<std::vector<int>> rez;
	std::vector<int> red;
	
	int pr;
	int n=v.size(); 
	
	pr = v.at(0);
	
	if (Stepen(v.at(0))) {
		red.push_back(v.at(0));
	}
	
	for(int i=1;i<n;i++){
		
		if (Stepen(v.at(i))
		   &&
		   (
		      (v.at(i)>=pr && direction==Rastuci)
		   || (v.at(i)<=pr && direction==Opadajuci)
		   || (red.size() == 0)
		   ))
		{    
		   red.push_back(v.at(i));
		}
		else // prekidas niz
		{
		   if (red.size() > 1) {
		   	  rez.push_back(red);
		   }
		   
		   if (red.size() > 0) {
		      red.clear();
		   }

	       if (Stepen(v.at(i))) {
		     red.push_back(v.at(i));
	       }
		}
		pr=v.at(i);
	}
	
	if (red.size() > 1) {
   	  rez.push_back(red);
	}

	return rez;
	
}

int main ()
{

//std::vector<int> v{3,1,2,4,2,8,16,2,4,3,3,2,4,4};
	std::vector<int> V;	
	
	int n;

	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		int clan;
		std::cin>>clan;
		V.push_back(clan);
	}
	
	
	int k;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove:";
	
	std::cin>>k;
	
	std::deque<std::vector<int>> rr;
	if(k==1){
   	  	std::cout<<" Maksimalni rastuci podnizovi: ";
	  	rr = MaksimalniPodnizoviStepenaDvojke(V,Rastuci);
	}
	else if(k==2){
		std::cout<<" Maksimalni opadajuci podnizovi: ";
    	rr = MaksimalniPodnizoviStepenaDvojke(V,Opadajuci);
	}	
	std::cout<<"\n";
	
	for(int i=0;i<rr.size();i++){
		for(int j=0;j<rr.at(i).size();j++){
		  std::cout<<rr.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}

	return 0;
}