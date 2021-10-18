/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
enum Smjer {Rastuci=1, Opadajuci};

int StepenDvojke(int w){
    int k=1,pamti{w};
	   while(w>1){
	   	  w/=2;
	   	  k*=2;
	   	 }
	   w=pamti;
	   if(w==k){
	   return 1;
	   }
   return 0;
}
deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v, Smjer s){
	deque<vector<int>> d;
	int vel{0};
	vector<int> pom;
	if(s==Rastuci){
		for(int i=0;i<(v.size());i++){
			if(i<(v.size()-1) && (v.size()>1)){
		    	if(((StepenDvojke(v.at(i)))==1) && ((StepenDvojke(v.at(i+1)))==1)){
		        	while(v.at(i+1)>v.at(i)){
				      pom.push_back(v.at(i));
			  	      i++;
			  	      if((i==v.size()-1) || (StepenDvojke(v.at(i+1))==0)) break;
			        }
			        pom.push_back(v.at(i));
			        if(pom.size()>1){
				      vel++;
				      d.resize(vel);
				      d.at(vel-1)=pom;
			        }
			        pom.resize(0);
	                }
			      }
		        }
		   return d;
	}
	else{
		   for(int i=0;i<v.size();i++){
		   	if(i<(v.size()-1) && (v.size()>1)){
		    	if(((StepenDvojke(v.at(i)))==1) && ((StepenDvojke(v.at(i+1)))==1)){
		        	while((v.at(i))>(v.at(i+1))){
			          pom.push_back(v.at(i));
			    	  i++;
			    	  if((i==v.size()-1) || (StepenDvojke(v.at(i+1))==0)) break;
		         	}
			       if(i>0){
			       if((v.at(i-1)>v.at(i))){
		           pom.push_back(v.at(i));
		        	}
			       }
		           if(pom.size()>1){
				     vel++;
				     d.resize(vel);
				     d.at(vel-1)=pom;
		  	      }
			      pom.resize(0);
	             }
		   	   }
		     }
		   return d;
	}
}
int main (){
	int n,p;
	deque<vector<int>> W;
	vector<int> q;
	int S;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		cin>>p;
		q.push_back(p);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin>>S;
	if(S==1){
    	W=MaksimalniPodnizoviStepenaDvojke(q,Rastuci);
	    cout<<"Maksimalni rastuci podnizovi: ";
	    cout<<endl;
	    for(int i=0;i<W.size();i++){
	    	for(int j=0;j<(W.at(i).size());j++){
		     cout<<W.at(i).at(j)<<" ";
		   }
		cout<<endl;
	   }
	}
	if(S==2){
	   W=MaksimalniPodnizoviStepenaDvojke(q,Opadajuci);
	   cout<<"Maksimalni opadajuci podnizovi: ";
	   cout<<endl;
	   for(int i=0;i<W.size();i++){
		   for(int j=0;j<(W.at(i).size());j++){
	    	cout<<W.at(i).at(j)<<" ";
		   }
		cout<<endl;
	   }
	}
	return 0;
}