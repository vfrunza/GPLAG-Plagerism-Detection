#include <iostream>
#include <vector>

bool jeLiOpak(int x) {
	 std::vector<int> ternarno;
	 while(x!=0){
	 	ternarno.push_back(x%3);
	 	x/=3;
	 }
	 std::vector<int>freq={0,0,0};
	 for(int i=0; i<ternarno.size(); i++){
	 	freq[ternarno[i]]++;
	 }
	 if (freq[0]%2==0 && freq[1]%2==0 && freq[2]%2==0){
	 	return true;
	 }
	 return false;
}

bool jeLiOdvratan(int x){
	std::vector<int> ternarno;
	while(x!=0){
		ternarno.push_back(x%3);
		x/=3;
	}
	std::vector<int> freq={0,0,0};
	for(int i=0; i<ternarno.size(); i++){
		freq[ternarno[i]]++;
	}
	if ((freq[0]%2!=0 || freq[0]==0) && (freq[1]%2!=0 || freq[1]==0) && (freq[2]%2!=0 || freq[2]==0)){
		return true;
	}
	return false;
}

std::vector<int> izdvojiGadne(std::vector<int>v, bool b){
	std::vector<int> novi;
	
	for(int i=0; i<v.size(); i++){
		int x=v[i];
		if(x<0){
			x*=(-1);
		}
		if(b){
			if(jeLiOpak(x)){
				novi.push_back(v[i]);
			}
		} else {
			if(jeLiOdvratan(x)){
				novi.push_back(v[i]);
			}
		}
	}
	for(int i=0; i<novi.size(); i++){
		for(int j=i+1; j<novi.size(); j++){
			if(novi[i]==novi[j]){
				novi.erase(novi.begin()+j);
				j--;
			}
		}
	}
	return novi;
}

int main () {
	int n;
	std::vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin>>n;
		if(n!=0) {
			v.push_back(n);
		}
	} while(n!=0);
	std::vector<int> opaki;
	std::vector<int> odvratni;
	opaki=izdvojiGadne(v, 1);
	odvratni=izdvojiGadne(v, 0);
	std::cout<<"Opaki: ";
	for(int i=0; i<opaki.size(); i++){
		std::cout<<opaki[i]<<" ";
	} std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i=0; i<odvratni.size(); i++){
		std::cout<<odvratni[i]<<" ";
	} std::cout<<std::endl;
	return 0;
}