#include<iostream>
#include<vector>

using namespace std;


vector<int> ternarneCifre(int broj){
	vector<int> brojaci(3,0);
	
	while(broj!=0){
		brojaci[broj%3]++;
		broj/=3;
	}
	return brojaci;
}


bool postoji(vector<int> v, int broj){
	for(int el:v){
		if(el==broj) return true;
	}
	return false;
}


vector<int>IzdvojiGadne(vector<int>brojevi,bool opaki){//opaki ili odvratni u zavisnosti od bool parametra
	vector<int>gadni;
	
	for(int el:brojevi){
		vector<int> brojaciCifara = ternarneCifre(abs(el));
		if(opaki){
			bool opak=true;
			for(int brojacCifre:brojaciCifara){
				if(brojacCifre!=0 && brojacCifre%2!=0){
					opak=false;
					break;
				}
			}
			if(opak){
				if(!postoji(gadni,el)){
					gadni.push_back(el);
				}
			}
		}
		else{
			bool odvratan=true;
			for(int brojacCifre:brojaciCifara){
				if(brojacCifre!=0 && brojacCifre%2==0){
					odvratan=false;
					break;
				}
			}
			if(odvratan){
				if(!postoji(gadni,el)){
					gadni.push_back(el);
				}
			}
		}
	}
	
	return gadni;
}


int main ()
{
	vector<int>brojevi;
	cout<<"Unesite brojeve (0 za prekid unosa):";
	int temp;
	
	do{
		cin>>temp;
		if(temp==0)break;
		brojevi.push_back(temp);
	}while(true);
	
	
	cout<<" Opaki: ";
	vector<int>opaki=IzdvojiGadne(brojevi,true);
	for(int el:opaki)cout<<el<<" ";
	cout<<endl<<"Odvratni: ";
	vector<int>odvratni=IzdvojiGadne(brojevi,false);
	for(int el:odvratni)cout<<el<<" ";
	
	return 0;
}