#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>


std::vector<int> IzdvojiGadne(std::vector<int> v,bool tacno) {
	if(tacno) {
		std::vector<int> f;
		int n(0),c;
		if(v.size()==0) return std::vector<int> (v.size());
		for(int i: v) {
	    std::vector<int> h;
			c=i;
			while(i!=0) {
				h.push_back(i%3);
				i/=3;
			}
			n=0;
			int j;
				for(j=0;j<=h.size()-1;j++) {
					for(int k=0;k<h.size();k++) {
						if(h[j]==h[k]) {
						n++;
					}
				}
				if(n%2==0) {
					continue;
				}
				else break;
			}
			if(j==h.size()) 
			f.push_back(c);
		}
			for(int t=0;t<f.size();t++) {
		for(int z=t+1;z<f.size();z++) {
			if(f[t]==f[z]) {
	for(int u=z;u<f.size()-1;u++) {
		f[u]=f[u+1];
	}
				f.resize(f.size()-1);
				z--;
			}
		}
}
		return f;
		
	}
	else {
		std::vector<int> d;
		int f(0),s;
		if(v.size()==0) return std::vector<int>(v.size());
		for(int z: v) {
			std::vector<int> r;
			s=z;
			while(z!=0) {
				r.push_back(z%3);
				z/=3;
			}
			f=0;
			int l;
			for(l=0;l<r.size();l++) {
				f=0;
				for(int m=0; m<=r.size()-1; m++) {
					if(r[l]==r[m]) {
						f++;
					}
				}
				if(f%2!= 0) {
					continue;
				}
				else  break;
			}
			if(l==r.size()) 
			d.push_back(s);
		}
				for(int r=0;r<d.size();r++) {
		      for(int p=r+1;p<d.size();p++) {
			if(d[r]==d[p]) {
				for(int x=p;x<d.size()-1;x++) {
					d[x]=d[x+1];
				}
				d.resize(d.size()-1);
				p--;
			}
		}
		}
		return d;
	}
}

int main ()
{
	int n;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
do {
	std::cin>>n;
	if(n!=0)
	v.push_back(n);
}while(n!=0);
	auto a(IzdvojiGadne(v,true));
	auto b(IzdvojiGadne(v,false));
    std::cout<<"Opaki: ";
    for(int j=0;j<a.size();j++) {
    	std::cout<<a[j]<<" ";
    }
std::cout<<std::endl;
		std::cout<<"Odvratni: ";
		for(int k=0;k<b.size();k++) {
			std::cout<<b[k]<<" ";
		}
	return 0;
}