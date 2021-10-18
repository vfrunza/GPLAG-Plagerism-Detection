#include <iostream>
#include <vector>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;
Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica final;
	for(int i=0;i<v.size();i++){
		if(i+1==v.size()) break;
	    if(v[i]<=v[i+1]){  // nasli smo rastuci podniz
	    	int j{i};
	    	while (v[j]<=v[j+1]){
	    	    j++;
	    		if(j+1==v.size()) break;
	    	}
	    	if(j==v.size()) j--;
	    	std::vector<double> tmp;
	    	for (int l=i;l<=j;l++){
	    		tmp.push_back(v[l]);
	    	}
	    	final.push_back(tmp);
	    	i=j;
	    }
	}
	return final;
}
Matrica OpadajuciPodnizovi(std::vector<double> v){
	Matrica final;
	for(int i=0;i<v.size();i++){
		if(i+1==v.size()) break;
	    if(v[i]>=v[i+1]){  // nasli smo opadajuci podniz
	    	int j{i};
	    	while (v[j]>=v[j+1]){
	    		j++;
	    		if(j+1==v.size()) break;
	    		
	    	}
	    	if(j==v.size()) j--;
	    	std::vector<double> tmp;
	    	// sada ga upisimo u matricu
	    	for (int l=i;l<=j;l++){
	    		tmp.push_back(v[l]);
	    	}
	    	final.push_back(tmp);
	    	i=j;
	    }
	}
	return final;
}

int main ()
{
    std::cout<<"Unesite broj elemenata vektora: ";
    int n;
    std::cin>>n;
    if(n<0){
    	return 0;
    }
    std::cout<<"Unesite elemente vektora: ";
    std::vector<double> v(n);
    for (int i=0;i<n;i++){
    	std::cin>>v[i];
    }
    Matrica v2,v3;
    v2=OpadajuciPodnizovi(v);
    v3=RastuciPodnizovi(v);
    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    for(int i=0;i< v3.size();i++){
    	for(int j=0;j<v3[i].size();j++) std::cout<<std::setprecision(12)<<v3[i][j]<<" ";
    	std::cout<<std::endl;
    }
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    for(int i=0;i< v2.size();i++){
    	for(int j=0;j<v2[i].size();j++) std::cout<<std::setprecision(12)<<v2[i][j]<<" ";
    	std::cout<<std::endl;
    }
    
    
	return 0;
}