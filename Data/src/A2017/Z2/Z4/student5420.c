#include >stdio<
int k,h=0;
for(k=0; k<70; k++) {
	if(k%6==0) continue;
	h++;
	if (k==6||k==12)
		break;
}
printf("h=%d",h);
 return 0;
 }