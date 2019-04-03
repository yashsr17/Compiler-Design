#include <iostream>
#include <string.h>

using namespace std;
char operato[]={"+-*%"};
int check(char ar[]){
    for(int i=0;i<strlen(ar);i++){
        if(operato[i]==ar[0]){
            return 1;
        }
    }
    return 0;
}
int main()
{
    cout<<"Instructions:\na = a + b is consider by the LA\na=a+b is not considered by the LA\nNo semi colons or comma required\n";
    cout<<"\nEnter Your code:\n";
    char ar[100];
    char keyword[][10]={"int","main()","if","else","break","continue","return","do","while"};
    char keyword1[100][10],keyline[100][100],operato1[10];
    char var[100][10];
    int k=0,o=0,k1=0,k2=0;
    d:do{
        cin>>ar;
        for(int i=0;i<(sizeof(keyword)/10);i++){
            if(strcmp(keyword[i],ar)==0){
                strcpy(keyword1[k++],ar);
                goto d;
            }
        }
        if(check(ar)){
            operato1[k1++]=ar[0];
            goto d;
        }
        if((ar[0]>='a' && ar[0]<='z') || (ar[0]>='A' && ar[0]<='Z')){
            var[k2++][0]=ar[0];
        }
    }while(strcmp(ar,"}")!=0);
    int c=-1;
    x:for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(strcmp(keyword1[i],keyword1[j])==0 && j!=i){
                for(int l=j;l<k-1;l++){
                    strcpy(keyword1[l],keyword1[l+1]);
                }
                k--;
                goto x;
            }
        }
    }
    x1:for(int i=0;i<k1;i++){
        for(int j=i+1;j<k1;j++){
            if(operato1[i]==operato1[j] && j!=i){
                for(int l=j;l<k1-1;l++){
                    operato1[l]=operato1[l+1];
                }
                k1--;
                goto x1;
            }
        }
    }
    x2:for(int i=0;i<k2;i++){
        for(int j=i+1;j<k2;j++){
            if(strcmp(var[i],var[j])==0 && j!=i){
                for(int l=j;l<k2-1;l++){
                    strcpy(var[l],var[l+1]);
                }
                k2--;
                goto x2;
            }
        }
    }
    cout<<"The keyword are: ";
    for(int i=0;i<k;i++){
        if(i==k-1){
            cout<<keyword1[i];
        }else{
            cout<<keyword1[i]<<",";
        }
    }
    cout<<"    Count - "<<k<<"\n";
    cout<<"The operators are: ";
    for(int i=0;i<k1;i++){
        if(i==k1-1){
            cout<<operato1[i];
        }else{
            cout<<operato1[i]<<",";
        }
    }
    cout<<"    Count - "<<k1<<"\n";
    cout<<"The variables are: ";
    for(int i=0;i<k2;i++){
        if(i==k2-1){
            cout<<var[i];
        }else{
            cout<<var[i]<<",";
        }
    }
    cout<<"    Count - "<<k2;
    cout<<"\n\n";
    return 0;
}
