#include<stdio.h>

int slovo(char x)
{
    if((x>='A' && x<='Z') || (x>='a' && x<='z'))
        return 1;

    return 0;
}

/* Da li se (od *a do *(b-1)), *b vec 'javio' */
int javlja(char *a,char *b)
{
    char*c;

    if(b==a)
        return 0;

    c=b-1;
    while(c>=a) {
        if(*c==*b || *c==*b+32 || *c==*b-32)
            return 1;
        c--;
    }

    return 0;
}

void najduzi_bp(char* s1, char* s2)
{
    char *p=s1;
    char *q=NULL,*r=NULL,*s=NULL,*t=NULL;
    int br_slova=0,tmp_br_slova=0;

    while(*p!='\0' && !slovo(*p))
        p++;

    if(*p=='\0')
        *s2='\0';

    while(*p!='\0') {
        tmp_br_slova=0;
        s=p;
        q=p;
        t=s2;
        if(slovo(*s)) {
            while(slovo(*q) && !javlja(s,q)) {
                q++;
                tmp_br_slova++;
            }

            if(tmp_br_slova>br_slova) {
                r=q;
                q=p;
                br_slova=tmp_br_slova;

                while(q<r)
                    *t++=*q++;

                *t='\0';
            }
        }
        p++;
    }
}

int main()
{
    char niz[20];

    najduzi_bp ("   \t  \n\t\n ..1.3!?=..", niz);
    printf ("Niz: '%s'\n", niz);

    najduzi_bp ("\t\n\t\n  Ignorant branched humanity led now marianne \n too strongly entrance."
                "Rose to shew    bore no ye of paid rent form. Old design are dinner better nearer silent excuse. "
                "She which are maid     boy uncopyrightable sense her shade."
                "Considered reasonable we affronting on expression in. "
                "So cordial anxious mr delight.     Shot his has must wish from sell nay. "
                "Remark fat     set why are sudden depend change entire wanted."
                "Performed remainder \n attending led fat residence far.....", niz);
    printf ("Niz: '%s'\n", niz);

    najduzi_bp ("Ignem ratio fingo istam etc11111 vix una velut veris deo. Teneri habeam perire putavi to cogito sentio me ac."
                "Ad potuisse in ne supponit !??loquendsia11 me. Sed vixque rei verbis dicunt dat jam."
                "Animal angeli sumpti animum.. cau exigui sim figura duo ita. Ad attingere objectiva pertinent an si abducerem."
                "Posuerunt stabilire ii ut detrahere de. Quo quandiu conabor iii degenda revolvo viribus ignorem.",niz);
    printf("Niz: '%s'\n",niz);

    return 0;
}
