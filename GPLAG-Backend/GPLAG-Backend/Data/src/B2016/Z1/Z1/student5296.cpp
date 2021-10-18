#include<iostream>
#include<vector>
using namespace std;

vector<int> IzdvojiGadne(vector<int> a, bool t){
    vector<int> opaki;
    vector<int> odvratni;

    int x;
    for(int i=0; i<a.size();i++){
        x= a[i];
        int y,br0=0,br1=0,br2=0;
    
        while(x!=0){
            y=x%3;
            x=x/3;
            if(y==0) br0++;
            if(y==1) br1++;
            if(y==2) br2++;
        }
        if(br0%2==0 && br1%2==0 && br2%2==0){
        	int br=0;
        	for(int vrag:opaki){
        		if(vrag==a[i]) 
        		br++;
        	}
      
        	if(br==0)opaki.push_back(a[i]);
        } 
        else if((br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0|| br2==0)){
        	int br=0;
        	for(int vrag:odvratni){
        		if(vrag==a[i]) 
        		br++;
        	}
    		if(br==0)odvratni.push_back(a[i]);
        }
        else;
            
            
    }
    if(t==true) return opaki;
    return odvratni;
    

}
int main ()
{
	std::vector<int> a;
	int x;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	cin>>x;
	while (x!=0) {
		a.push_back(x);
		cin>>x;
		
	}
	std::vector<int>  opaki, odvratni;
	opaki=IzdvojiGadne(a,true);
	std::cout << "Opaki: ";
	for(int i=0;i<opaki.size();i++){
		std::cout << opaki[i]<<" ";
	}
	std::cout << std::endl;
	odvratni=IzdvojiGadne(a,false);
	std::cout << "Odvratni: ";
	for(int i=0;i<odvratni.size();i++){
		std::cout << odvratni[i]<<" ";
	}
	return 0;
}