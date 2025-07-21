#include<stdio.h>
#include<stdlib.h>

int w[50],v[50],n,m,table[50][50];

int max(int a,int b){
    if(a>b) return a;
    return b;
}

int knap(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                table[i][j]=0;
            }
            else if(j<w[i]){
                table[i][j] = table[i-1][j];
            }
            else{
                table[i][j] = max(table[i-1][j],v[i]+table[i-1][j-w[i]]);
            }
        }
    }
    return table[n][m];
}


int main(){
    printf("Enter number of items :");
    scanf("%d",&n);
    printf("Enter max weight");
    scanf("%d",&m);
    printf("Enter data :\nvalue weight");
    for(int i=1;i<=n;i++){
        scanf("%d%d",&v[i],&w[i]);
    }
    for(int i=1;i<=n;i++){
        printf("%d\t%d\n",v[i],w[i]);
    }
    printf("max value : %d\n",knap());
    printf("\ntable : \n");
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            printf("%d\t",table[i][j]);
        }
        printf("\n");
    }
    printf("Composition :\n");
    for(int i=n;i>0;i--){
        if(table[i][m]!=table[i-1][m]){
            printf("%d\t",i);
            m=m-w[i];
        }
    }

}
