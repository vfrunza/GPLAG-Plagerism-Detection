#include <iostream>
#include <vector>

long long int Dec2Ter(long long int n){
	long long int pomocni(n);
	int dek(0);
	if(n<0) n*=-1;
	if(n==0) return 0;
	else{
	while(pomocni!=0){
		dek=dek*10+pomocni%3;
		pomocni/=3;
	}
    int obrnut(0);
	while(dek!=0){
		obrnut=obrnut*10+dek%10;
		dek/=10;
	}
	while(n%3==0){
		obrnut*=10;
		n/=3;
	}
	return obrnut;
}
}
bool TestOdvratnih(long long int n){
	if(n==0) return 1;
	std::vector<int>v;
	while(n!=0){
		v.push_back(n%10);
		n/=10;
	}
	int neparan(0);
	for(unsigned long int i=0; i<v.size(); i++){
		int br(0);
		for(unsigned long int j=0; j<v.size(); j++){
			if(v[i]==v[j]) br++;
		}
		if(br%2!=0) neparan=1;
		else {
			neparan=0;
			break;
	}
	}
	if(neparan) return 1;
	return 0;
}

bool TestOpakih(long long int n){
	std::vector<int>v;
	while(n!=0){
		v.push_back(n%10);
		n/=10;
	}
	int paran(0);
	for(unsigned long int i=0; i<v.size(); i++){
		int br(0);
		for(unsigned long int j=0; j<v.size(); j++){
			if(v[i]==v[j]) br++;
		}
		if(br%2==0) paran=1;
		else {
			paran=0;
			break;
	}
	}
	if(paran) return 1;
	return 0;
}
std::vector<int>IzdvojiGadne (std::vector<int>v, bool a){
	std::vector<int>v2;
	std::vector<int>v3;

	for(unsigned long int i=0; i<v.size(); i++) v2.push_back(Dec2Ter(v[i]));

    if(a==0){
    	for(unsigned long int i=0; i<v.size(); i++){
    	if(TestOdvratnih(v2[i])) v3.push_back(v[i]);
    	
    }
    }
    if(a==1){
    	for(unsigned long int i=0; i<v.size(); i++){
            if(TestOpakih(v2[i])) v3.push_back(v[i]);	
    }
    }
    
    for(int i=0; i<v3.size(); i++){
    	for(int j=i+1; j<v3.size(); j++){
    		 if(v3[i]==v3[j]) {v3.erase(v3.begin()+j);
    		 j--;}

    	}

    }
    
	return v3;
}

int main ()
{
	std::vector<int>v;
	std::vector<int>v2;
	std::cout<< "Unesite brojeve (0 za prekid unosa): ";
	int b;
	for(;;){
		std::cin>>b;
		if(b==0) break;
		v.push_back(b);
		v2.push_back(b);
	}
	std::cout<<"Opaki: ";
	v=IzdvojiGadne(v, 1);
	for(int i=0; i<v.size(); i++){
		std::cout<<v[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	v2=IzdvojiGadne(v2, 0);
	for(int i=0; i<v2.size(); i++){
		std::cout<<v2[i]<<" ";
	}
	return 0;
}