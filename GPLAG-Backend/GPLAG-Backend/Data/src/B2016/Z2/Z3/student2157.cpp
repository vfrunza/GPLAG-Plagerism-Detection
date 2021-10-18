#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>

int SumaCifaraDjelilaca(int x){
    x=abs(x);
    if(x==0)return 0;
    int suma=0;
    for(unsigned int i=1;i<int(x);i++){

        if(x%i==0)suma+=i;
    }
    return suma;
}
template<typename Tip>
int SumaDjelilaca(Tip x){
    x=abs(x);
    if(x==0)return 0;
    int suma=x+1;
    if(x==1)suma=1;
    for(unsigned int i=2;i<(x/2)+1;i++){
        if(x%i==0)suma+=i;
    }

    return suma;
}
template<typename Tip>
int SumaCifara(Tip x){
    x=abs(x);
    if(x==0)return 0;
    int suma=0;
    while((x)!=0){
        suma+=x%10;
        x=x/10;
    }
    return suma;
}
template<typename Tip>
int BrojProstihFaktora(Tip x){
    x=abs(x);
    int suma=0;
    unsigned int i(2);
    if(x<2)return 0;
    while(i!=int(x)){
        if(x%i==0){
            suma++;
            x=x/i;
            i=2;if(i==x){suma++;break;}
            continue;
        }
        i++;
        if(i==x)suma++;
    }
    return suma;
}
template<typename Tip>
int BrojSavrsenihDjelilaca(Tip x){
    x=abs(x);
    if(x==0 || x==2)return 0;
    int suma=0;
    for(unsigned int i=2;i<=(x);i++){
        if(x%i==0){
            if(i==SumaCifaraDjelilaca(i))suma++;
        }
    }
    return suma;
}
template<typename IterTip1,typename IterTip2>
auto UvrnutiPresjek(IterTip1 pocetak1,IterTip1 kraj1,IterTip2 pocetak2,IterTip2 kraj2,decltype(*pocetak1+*pocetak1) (*p)(decltype(*pocetak1+*pocetak1))=0)->typename::std::vector<std::vector<decltype(*pocetak1+*pocetak1)>>{
    std::vector<std::vector<decltype(*pocetak1+*pocetak1)>> vrati;
    IterTip1 setac1=pocetak1;
    IterTip2 setac2=pocetak2;
    if(p==nullptr){
    int i(0);
            while(setac1!=kraj1){
                    setac2=pocetak2;
                while(setac2!=kraj2){
                    if(abs(*setac1-*setac2)<=0.000000001){
                        vrati.resize(i+1);
                        vrati[i].resize(3);
                        vrati[i][0]=*setac1;
                        vrati[i][1]=0;
                        vrati[i][2]=0;
                        i++;
                    break;
                    }
                    setac2++;
                }
                setac1++;
            }
    }
    else{
    int i=0;
    int najveciel=0;
    while(setac1!=kraj1){
        setac2=pocetak2;
        while(setac2!=kraj2){
            if(*setac1>najveciel)najveciel=*setac1;
            if(*setac2>najveciel)najveciel=*setac2;
            if(p(*setac1)==p(*setac2)){
                vrati.resize(i+1);
                vrati[i].resize(3);
                vrati[i][0]=*setac1;
                vrati[i][1]=*setac2;
                vrati[i][2]=p(*setac1);
                i++;
            }
        setac2++;
        }
        setac1++;
    }
    int broj_istih(0);
    for(int i=0;i<vrati.size()-1;i++){
        for(int j=i+1;j<vrati.size();j++){
            if(abs(vrati[i][0]-vrati[j][0])<=0.00000000001 && abs(vrati[i][1]-vrati[j][1])<=0.00000000001 && abs(vrati[i][2]-vrati[j][2])<=0.00000000001){
                vrati[i][0]=najveciel+1;vrati[i][1]=najveciel+1;vrati[i][2]=najveciel+1;
                broj_istih++;
            }
        }
    }
    std::sort(vrati.begin(),vrati.end());
    vrati.resize(vrati.size()-broj_istih);
    }

    sort(vrati.begin(),vrati.end(),[](std::vector<decltype(*pocetak1+*pocetak1)> x,std::vector<decltype(*pocetak1+*pocetak1)> y){
                                      if(x[2]<y[2])return true;
                                      if(x[2]==y[2]){
                                        if(x[0]<y[0])return true;
                                        if(x[0]==y[0]){
                                            if(x[1]<y[1])return true;
                                        }
                                      }
                                      return false;
                                      });

return vrati;
}
template<typename IterTip1,typename IterTip2>
auto UvrnutaRazlika(IterTip1 pocetak1,IterTip1 kraj1,IterTip2 pocetak2,IterTip2 kraj2,decltype(*pocetak1+*pocetak1) (*p)(decltype(*pocetak1+*pocetak1))=nullptr)->typename::std::vector<std::vector<decltype(*pocetak1+*pocetak1)>>{
    std::vector<std::vector<decltype(*pocetak1+*pocetak1)>> vrati;
    IterTip1 setac1=pocetak1;
    IterTip2 setac2=pocetak2;
    if(p==nullptr){
        int i=0;
        while(setac1!=kraj1){
            bool slucaj(true);
            setac2=pocetak2;
            while(setac2!=kraj2){
                if(*setac1==*setac2){
                    slucaj=false;
                    break;
                }
            setac2++;
            }
            if(slucaj==true){
                vrati.resize(i+1);
                vrati[i].resize(2);
                vrati[i][0]=*setac1;
                vrati[i][1]=0;
                i++;
            }
            setac1++;
        }
        setac1=pocetak1;
        setac2=pocetak2;
        while(setac2!=kraj2){
            bool slucaj(true);
            setac1=pocetak1;
            while(setac1!=kraj1){
                if(*setac1==*setac2){
                    slucaj=false;
                    break;
                }
            setac1++;
            }
            if(slucaj==true){
                vrati.resize(i+1);
                vrati[i].resize(2);
                vrati[i][0]=*setac2;
                vrati[i][1]=0;
                i++;
            }
            setac2++;
        }
    }
    else{
    setac1=pocetak1;
    setac2=pocetak2;
    int i(0);
    while(setac1!=kraj1){
        setac2=pocetak2;
        bool status(true);
        while(setac2!=kraj2){
            if(p(*setac1)==p(*setac2))status=false;
            setac2++;

        }
        if(status==true){
            vrati.resize(i+1);
            vrati[i].resize(2);
            vrati[i][0]=*setac1;
            vrati[i][1]=p(*setac1);
            i++;
        }
        setac1++;
    }
        setac1=pocetak1;
        setac2=pocetak2;
    while(setac2!=kraj2){
        setac1=pocetak1;
        bool status(true);
        while(setac1!=kraj1){
            if(p(*setac1)==p(*setac2))status=false;
            setac1++;
        }
        if(status==true){
            vrati.resize(i+1);
            vrati[i].resize(2);
            vrati[i][0]=*setac2;
            vrati[i][1]=p(*setac2);
            i++;
        }
        setac2++;
    }
    }
    std::sort(vrati.begin(),vrati.end(),[](std::vector<decltype(*pocetak1+*pocetak1)> x,std::vector<decltype(*pocetak1+*pocetak1)> y){
                                                    if(x[0]>y[0])return true;
                                                    if(x[0]==y[0]){
                                                        if(x[1]>y[1])return true;
                                                    }
                                                    return false;});
    return vrati;

}
int main()
{
    std::vector<int> a;
	std::vector<int> b;
	int a_1,b_1;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>a_1;
	a.resize(a_1);
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0;i<a_1;i++){
		bool status=false;
		int a_copy;
		std::cin>>a_copy;
		for(int j=0;j<i;j++){
			if(a_copy==a[j]){
                    status=true;
                    i--;
                    continue;
            }
		}
		if(status==false)a[i]=a_copy;
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>b_1;
	b.resize(b_1);
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<b_1;i++){
		bool status=false;
		int b_copy;
		std::cin>>b_copy;
		for(int j=0;j<i;j++){
			if(b_copy==b[j]){
            status=true;
            i--;
			continue;
			}
		}
		if(status==false)b[i]=b_copy;
	}
	std::vector<std::vector<int>> v1,v2;
	v1=UvrnutiPresjek(a.begin(),a.end(),b.begin(),b.end(),SumaCifara);
	v2=UvrnutaRazlika(a.begin(),a.end(),b.begin(),b.end(),BrojProstihFaktora);
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(auto i:v1){
		for(auto j:i){
			std::cout<<std::setw(6)<<j<<" ";
		}
	std::cout<<" "<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
    for(auto i:v2){
		for(auto j:i){
			std::cout<<std::setw(6)<<j<<" ";
		}std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!"<<std::endl;
    return 0;
}
