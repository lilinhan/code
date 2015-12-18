#include<iostream>
#define N 1000
using namespace std;

int n,m,d,cp=0,cw=0,sum=0;
int c[N][N],w[N][N];

void backtrack(int i){
     if(i>n){
       if(cw<sum)
         sum = cw;
       return ;
     }
     for(int j=1;j<=m;j++){
         cw+=w[i][j];
         cp+=c[i][j];
         if(cw<sum && cp<=d)
           backtrack(i+1);
         cw-=w[i][j];
         cp-=c[i][j];
     }
}

int main(){
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++)
        cin>>c[i][j];
      sum+=c[i][1];
    }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cin>>w[i][j];
    backtrack(1);
    cout<<sum<<endl;
    system("pause");
    return 0;
}


