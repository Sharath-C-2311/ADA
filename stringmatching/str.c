#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int count=0;

int strmat(char *text, char *pat, int n, int m)
{
    for(int i=0;i<=n-m;i++){
        int j=0;
        while(j<m){
            count++;
            if(pat[j] != text[i+j]){
                break;;
            }
            j++;
        }
        if(j==m){
            return i;  
        }
    }
    return -1;
}



void tester(){
    int n,m;
    char text[40],pat[40];
    printf("enter size of pt : ");
    scanf("%d",&m);
    printf("enter pattern : ");
    getchar();
    fgets(pat,sizeof(pat),stdin);
    pat[strcspn(pat,"\n")] = '\0';
    printf("enter size of text : ");
    scanf("%d",&n);
    printf("enter text : ");
    getchar();
    fgets(text,sizeof(text),stdin);
    text[strcspn(text,"\n")] = '\0';

    int i = strmat(text,pat,n,m);
    if(i==-1){
        printf("not found");
    }
    else{
        printf("found at %d count = %d\n",i,count);
    }
}


void plotter(){
    FILE *f1,*f2,*f3;
    f1 = fopen("b.txt","a");
    f2 = fopen("w.txt","a");
    f3 = fopen("a.txt","a");
    int n=10;
    char text[1000],*pat;
    for(int i=0;i<1000;i++){
        text[i] = 'a';
    }
    while(n<=1000){
        pat = (char *)malloc(sizeof(char)*n);

        //best 
        count=0;
        for(int i=0;i<n;i++){
            pat[i]= 'a';
        }
        strmat(text,pat,1000,n);
        fprintf(f1,"%d\t%d\n",n,count);

        //worst
        count=0;
        pat[n-1] = 'b';
        strmat(text,pat,1000,n);
        fprintf(f2,"%d\t%d\n",n,count);

        //avg
        count=0;
        for(int i=0;i<n;i++){
            pat[i] = 97+rand()%3;
        }
        strmat(text,pat,1000,n);
        fprintf(f3,"%d\t%d\n",n,count);

        if(n<100){
            n+=10;
        }
        else{
            n+=100;
        }
        free(pat);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}


int main(){
    plotter();
}