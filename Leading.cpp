#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of production : ";
    cin>>n;
    char ar[n][10],ars[n][10],arsc[n][10];
    int arl[n],arsl[n],arscl[n];
    for(int i=0;i<6;i++){
        cin>>ar[i];
        arl[i]=strlen(ar[i]);
    }
    for(int i=n-1;i>=0;i--){
        for(int j=3;j<arl[i];j++){
            if((ar[i][3]>='a' && ar[i][3]<='z') || ar[i][3]=='+' || ar[i][3]=='*' || ar[i][3]=='i' || ar[i][3]=='('){
                ars[i][0]=ar[i][0];
                ars[i][1]=ar[i][3];
                arsl[i]=2;
                break;
            }
            else if(((ar[i][j+1]>='a' && ar[i][j+1]<='z') || ar[i][j+1]=='+' || ar[i][j+1]=='*' || ar[i][j+1]=='i' || ar[i][j+1]=='(') && (ar[i][j]>='A' && ar[i][j]<='Z')){
                ars[i][0]=ar[i][0];
                ars[i][1]=ar[i][4];
                ars[i][2]=ar[i][3];
                arsl[i]=3;
                break;
            }else{
                ars[i][0]=ar[i][0];
                ars[i][1]=ar[i][3];
                arsl[i]=2;
                break;
            }
        }
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=1;j<arsl[i];j++){
            if((ars[i][j]>='A' && ars[i][j]<='Z') && ars[i][j]==ars[i][0]){
                ars[i][j]=' ';
                arsl[i]--;
            }
        }
    }
    R:
    for(int i=0;i<n;i++){
        int le=1;
        for(int j=1;j<arsl[i];j++){
            if((ars[i][j]>='A' && ars[i][j]<='Z')){
                le=le+j;
                for(int x=0;x<n;x++){
                    if(ars[i][j]==ars[x][0]){
                        for(int y=1;y<arsl[x];y++){
                            ars[i][le++]=ars[x][y];
                        }
                    }
                }
            }
        }
        if(le!=1){
            arsl[i]=le;
        }
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<"LEAD ("<<ar[i][0]<<") = ";
        for(int j=1;j<arsl[i];j++){
            cout<<ars[i][j]<<" ";
        }
        cout<<"\n";
    }
    int u;
    cout<<"Enter(1) want to continue filteration : ";
    cin>>u;
    if(u==1){
        goto R;
    }
    for(int i=0;i<n;i++){
        int z=1;
        arscl[i]=1;
        arsc[i][0]=ars[i][0];
        for(int j=1;j<arsl[i];j++){
            if(ars[i][j]=='+' || ars[i][j]=='*' || ars[i][j]=='i' || ars[i][j]=='('){
                int f=0;
                for(int x=1;x<arscl[i];x++){
                    if(arsc[i][x]==ars[i][j]){
                        f=1;
                        break;
                    }
                }
                if(f==0){
                    arsc[i][z++]=ars[i][j];
                    arscl[i]=z;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<"LEAD ("<<arsc[i][0]<<") = ";
        for(int j=1;j<arscl[i];j++){
            cout<<arsc[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
