#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
using std::cin;
using std::cout;
using std::setw;
using std::vector;
using std::endl;

vector<int> IzdvojiGadne(vector<int> v, bool tilin){
	vector<int>  v2,v3;
	
	for(int i=0;i<v.size();i++){
			vector<int> brojaci(3);
			
		long long int a=v[i];
	
		do{
			int b=abs(a%3); brojaci[b]++;
			a=a/3;
		}while(a!=0);
		
	if(brojaci[0]%2==0 && brojaci[1]%2==0 && brojaci[2]%2==0) {
		bool ima(0);
			for(int j=0;j<v2.size();j++){
				if(v[i]==v2[j]) ima=1;
			}
			if(ima==0) v2.push_back(v[i]);
		
	}
	if((brojaci[0]%2!=0 || brojaci[0]==0 ) && (brojaci[1]%2!=0 || brojaci[1]==0) && (brojaci[2]%2!=0  || brojaci[2]==0)){
		bool ima=0;
			for(int j=0;j<v3.size();j++){
				if(v[i]==v3[j]) ima=1;
			}
			if(ima==0) v3.push_back(v[i]);
		
	}
	
		
	}
	
	if(tilin==1) return v2;
	else if(tilin==0) return v3;
	
}

int main (){	 
	vector<int> a,b,c;
	 int broj;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
        do{
           
            cin>>broj;
            if(broj!=0) a.push_back(broj);
        }while(broj!=0);
        c=IzdvojiGadne(a,1);
        b=IzdvojiGadne(a,0);
    cout<<"Opaki: ";
    for(int i=0;i<c.size();i++) cout<<c[i]<<" ";
    cout<<endl<<"Odvratni: ";
    for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
    
	return 0;
}
