#include <iostream>
#include <vector>
#include <cmath>
using std::cout;
using std::cin;
using std::vector;


vector<int> IzdvojiGadne(vector<int> ulaz,bool x){
	vector<int> opaki,odvratni,pomocni;
	
	for(int i=0;i<ulaz.size();i++){
		int temp(abs(ulaz[i])),ter;
		//Pretvaramo u ternarni brojni sistem i stavljamo mu cifre u pomocni vektor
		do{
			ter=temp%3;
			pomocni.push_back(ter);
			temp/=3;
		   }while(temp!=0);
		   
		//Brojimo cifre
	    int brojac0(0),brojac1(0),brojac2(0);
	    for(int j=0;j<pomocni.size();j++){
	    	if(pomocni[j]==0) brojac0++;
	    	else if(pomocni[j]==1) brojac1++;
	    	else brojac2++;
	    }
	    pomocni.resize(0);
	    bool jeli_upisan(false);
	    for(int s=0;s<opaki.size();s++){
	    	if(opaki[s]==ulaz[i]){
	    		jeli_upisan=true;
	    		break;
	    	}
	    }
	    //Ispitujemo dali je broj vec upisan, ako ne upisujemo
	    if(jeli_upisan==false){
	    if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0) opaki.push_back(ulaz[i]);
	    }
	    jeli_upisan=false;
	    for(int l=0;l<odvratni.size();l++){
	    	if(odvratni[l]==ulaz[i]){
	    		jeli_upisan=true;
	    		break;
	    	}
	    }
	    if(jeli_upisan==false){
	    if(brojac0==0 && brojac1%2==1 && brojac2%2==1) odvratni.push_back(ulaz[i]);
	    else if(brojac1==0 && brojac0%2==1 && brojac2%2==1) odvratni.push_back(ulaz[i]);
	    else if(brojac2==0 && brojac0%2==1 && brojac1%2==1) odvratni.push_back(ulaz[i]);
	    else if(brojac0==0 && brojac1==0 && brojac2%2==1) odvratni.push_back(ulaz[i]);
	    else if(brojac0==0 && brojac1%2==1 && brojac2==0) odvratni.push_back(ulaz[i]);
	    else if(brojac0%2==1 && brojac1==0 && brojac2==0) odvratni.push_back(ulaz[i]);
	    else if(brojac0%2==1 && brojac1%2==1 && brojac2%2==1) odvratni.push_back(ulaz[i]);
		}
	}
	if(x) return opaki;
	else return odvratni;
}

int main ()
{
	vector<int> ulaz;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	int n;
	do{
		cin>>n;
		if(n==0) break;
		ulaz.push_back(n);
	}while(n!=0);
	vector<int> opaki,odvratni;
	opaki=IzdvojiGadne(ulaz,true);
	odvratni=IzdvojiGadne(ulaz,false);
	cout<<"Opaki:";
	for(int i=0;i<opaki.size();i++){
		cout<<" "<<opaki[i];
	}
	cout<<std::endl<<"Odvratni:";
	for(int i=0;i<odvratni.size();i++){
		cout<<" "<<odvratni[i];
	}
	return 0;
}