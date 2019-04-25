#include <iostream>
#include <string.h>
using namespace std;
char ar[100]="a*b+z-e/f*g*h";
void chpos(char a, char b, char c, char d, int si){
    cout<<d<<":="<<a<<b<<c;
    for(int i=0;i<si;i++){
        if(ar[i]==a && ar[i+1]==b && ar[i+2]==c){
            ar[i]=d;
            for(int j=i+1;j<si-2;j++){
                ar[j]=ar[j+2];
            }
            cout<<"\t";
            for(int j=0;j<si-2;j++){
                cout<<ar[j];
            }
            cout<<"\n";
            break;
        }
    }
}
int main()
{
    int alen=strlen(ar), var=110;
    cout<<"The input String is : "<<ar<<"\n\n";
    ch:for(int i=0;i<alen;i++){
        if(ar[i]=='*'){
            chpos(ar[i-1],ar[i],ar[i+1],(char)var, alen);
            var++;
            alen=alen-2;
            goto ch;
        }
    }
    ch1:for(int i=0;i<alen;i++){
        if(ar[i]=='/'){
            chpos(ar[i-1],ar[i],ar[i+1],(char)var, alen);
            var++;
            alen=alen-2;
            goto ch1;
        }
    }
    ch2:for(int i=0;i<alen;i++){
        if(ar[i]=='+'){
            chpos(ar[i-1],ar[i],ar[i+1],(char)var, alen);
            var++;
            alen=alen-2;
            goto ch2;
        }
    }
    ch3:for(int i=0;i<alen;i++){
        if(ar[i]=='-'){
            chpos(ar[i-1],ar[i],ar[i+1],(char)var, alen);
            var++;
            alen=alen-2;
            goto ch3;
        }
    }
    return 0;
}
