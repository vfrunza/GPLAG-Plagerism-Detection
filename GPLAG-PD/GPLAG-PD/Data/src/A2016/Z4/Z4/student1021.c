#include <stdio.h>

/* Funkcija koja izbacuje tacke koje se ne nalaze unutar pravougaonika */
char *obuhvat (char *s, double xprvo, double yprvo, double xdrugo, double ydrugo) {
	char *p=s, *pisi, *citaj, *pocetak_trenutne, *kraj_trenutne;
	int znakx, znaky;
	double k, x1, x2, y1, y2, x, y;
	while (*p!='\0') {
	    if (*p!='(')  {
	        return 0;
	    }
	    if (*p=='(') {
	        pocetak_trenutne=p;
	        p++;
	        znakx=1;
	        x=0;
	        if (*p=='-') {
	            p++; znakx=-1;
	        }
	        else if (*p<0 || *p>'9') {
	            return 0;
	        }
	        while (*p>='0' && *p<='9') {
	            x=x*10+*p-'0'; p++;
	        }
	        if (*p=='.') {
	            x2=0;
	            p++;
	            k=10;
	            while (*p>='0' && *p<=9) {
	                x2=x2+(*p-'0')/k;
	                p++;
	                k*=10;
	            }
	            x=x+x2;
	        }
	        else if (*p!=',') {
	            return 0;
	        }
	        if (*p==',') {
	            p++;
	            znaky=1;
	            y=0;
	            if (*p=='-') {
	                p++;
	                znaky=-1;
	            }
	            else if (*p<'0' || *p>'9') { 
	                return 0;
	            }
	            while (*p>='0' && *p<='9') {
	                y=y*10+*p-'0'; p++; }
	                kraj_trenutne=p+1;
	                if (*p=='.') {
	                    y2=0;
	                    p++;
	                    k=10;
	                    while (*p>='0' && *p<='9') {
	                        y2=y2+(*p-'0')/k;
	                        p++;
	                        k*=10;
	                    }
	                    y=y+y2;
	                    
	                    kraj_trenutne=p+1;
	                } else if (*p!=')') {
	                    return 0;
	                }
	        }
	        y=y*znaky;
	        x=x*znakx;
	        if (x<xprvo || x>xdrugo || y<yprvo || y>ydrugo) {
	            if (*kraj_trenutne==',') kraj_trenutne++;
	            pisi=pocetak_trenutne, citaj=kraj_trenutne;
	            while (*citaj!=-'\0') {
	                *pisi++=*citaj++;
	            }
	            *pisi='\0';
	            p=pocetak_trenutne-1;
	        }
	    }
	    p++;
	}
	p=s;
	while (*p!='\0') p++;
	if (*p!=s && *(p-1)==',') {
	    *(p-1)='\0';
	    
	}
	return s;
}

int main () {
    char s[100]="(0,-3,1),(-15.09,4),(2.,3),(-1.1,217)";
    obuhvat(s,0,0,0,0);
    printf ("%s", s);
    return 0;
}
	            
	        
	              