#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

typedef std::vector<int> Vektor;
typedef std::deque<Vektor> Dek;

enum Smjer {Rastuci,Opadajuci};

bool DaLiJeStepenDvojke(int n){
	double x;
	
	if (n<=0)return false; 
	
	x=log2(n);
	
	if(x==int(x))return true;
	return false;    
} 

Dek MaksimalniPodnizoviStepenaDvojke (Vektor v,Smjer b){
	
	if(b==Smjer(0)){
		//RASTUCI!!!
		
		Vektor VR;
		Dek DR;
		
		for(int i=0;i<v.size()-1;i++){
			if(DaLiJeStepenDvojke(v.at(i))){
				if(DaLiJeStepenDvojke(v.at(i+1))==1 && v.at(i+1)>=v.at(i)) {
					VR.push_back(v.at(i));
					if(i==v.size()-2) VR.push_back(v.at(i+1));
				}
				else {
					if((DaLiJeStepenDvojke(v.at(i+1))!=1  || v.at(i+1)<v.at(i) ) && VR.size()>=1)VR.push_back(v.at(i));
					DR.push_back(VR);
					VR.resize(0);
				}
			}
			else {
			if (VR.size()>0){
					DR.push_back(VR);
					VR.resize(0);
				}
			}
		}
		if (VR.size()>0){
			DR.push_back(VR);
			VR.resize(0);
		}
		return DR;
	}
	
	else if(b==Smjer(1)){
		//OPADAJUCI!!!
		Vektor VO;
		Dek DO;
		
		for(int i=0;i<v.size()-1;i++){
			
			if(DaLiJeStepenDvojke(v.at(i))){
				if(DaLiJeStepenDvojke(v.at(i+1))==1 && v.at(i+1)<=v.at(i)){
					VO.push_back(v.at(i));
					if(i==v.size()-2) VO.push_back(v.at(i+1));
				}
				
				else {
					if((DaLiJeStepenDvojke(v.at(i+1))!=1 || v.at(i+1)>=v.at(i)) && VO.size()>=1)VO.push_back(v.at(i));
					DO.push_back(VO);
					VO.resize(0);
				}
			}
			else { 
				if (VO.size()>0){
					DO.push_back(VO);
					VO.resize(0);
				}
			}
			
		}
		if (VO.size()>0){
			DO.push_back(VO);
			VO.resize(0);
		}
		
		return DO;
	}
	
}

int main ()
{
	int n;
	
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	
	Vektor v;
	cout<<"Unesite elemente vektora: ";
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	int br;
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";	
	cin>>br;
	
	Dek d;
	Smjer smjer;
	
	if(br==1)smjer=Smjer(0);
	else if(br==2)smjer=Smjer(1);
	
	d=MaksimalniPodnizoviStepenaDvojke(v,smjer);
	
	if(br==1 && d.size()>0){
		cout<<"Maksimalni rastuci podnizovi: "<<endl;
		for(int i=0;i<d.size();i++){
			for(int j=0;j<d.at(i).size();j++){
				cout<<d.at(i).at(j)<<" ";
			}
			cout<<endl;
		}
	}
	
	else 	if(br==2 && d.size()>0){
			cout<<"Maksimalni opadajuci podnizovi: "<<endl;
		for(int i=0;i<d.size();i++){
			if(d.at(i).size()!=0)
			{
			for(int j=0;j<d.at(i).size();j++){
				cout<<d.at(i).at(j)<<" ";
			}
			cout<<endl;
			}
		}
		
	}
	return 0;
}