#include <iostream>
#include <string.h>
#include <stdbool.h>
using namespace std;

struct nfa{                                               // NFA STRUCTURE
    char arn[10];
};
struct dfa{                                               // DFA STRUCTURE
    char ard[10];
};
struct nfa nf[100][100];
struct dfa df[100][100];
int g=0,b=2,c=1,x,y,t=1,u=0;
char arr[100][100],arr1[100][100],arc[100][100];
/*<--TO CHECK THE OCCURANCE FROM STATE ARRAY USING THE GIVEN ARRAY-->*/
int check(char dar[],int n,int m){
    for(int j=1;j<m;j++){
        c=0;
        for(int i=0;i<n;i++){
            if(strcmp(arr[i],dar)!=0){
                c++;
            }
            if(strcmp(arr[i],dar)==0 && strcmp(arr[i],arr1[0])==0){
                break;
            }
            if(strcmp(arr[i],dar)==0 && strcmp(arr[i],arr1[0])!=0){
                break;
            }
        }
        if(c==n){
            return 1;
        }else{
            return 0;
        }
    }
    return 0;
}
/*<--THE END OF CHECK-->*/
/*<--TO PRINT THE NEW TRANSITION STATES-STATES-->*/
void printr(char dar[],int n,int m, int r, int c){
    for(int i=0;i<m-1;i++){
            char a[100]="";
        for(int j=0;j<strlen(dar);j++){
            for(int k=0;k<n;k++){
                if(dar[j]==arr[k][0] && strcmp(dar,arr[k])!=0 && strlen(dar)>1){
                    if(strcmp(nf[k+1][i+1].arn,"-")==0){
                        strcat(a,"");
                    }else{
                        strcat(a,nf[k+1][i+1].arn);
                    }
                }
            }
        }
        int f=0;
        char b[100]="";
        for(int q=0;q<strlen(a);q++){
            for(int q1=q+1;q1<strlen(a);q1++){
                if(a[q]=='-' || a[q]=='9'){
                    a[q]='9';
                    break;
                }
                if(a[q]==a[q1] && (a[q]!='-' || a[q]!='9')){
                    a[q1]='9';
                }
            }
        }
        int v=0,as=0;
        for(int u=0;u<strlen(a);u++){
            as=0;
            if(a[u]=='-'){
                as=1;
            }
            if(a[u]=='9'){
                as=1;
            }
            if(as==0){
                b[v++]=a[u];
            }
        }
        strcpy(nf[r+n-1][i+1].arn,b);
        strcpy(df[r+1][i+1].ard,b);
    }
}
/*<--THE END OF NEW TRANSITON-->*/
/*<--TO CHECK THAT NO REPEATION OCCURS IN DFA-->*/
int checkd(char dar[], int n, int m){
    for(int i=1;i<n;i++){
        if(strcmp(dar,df[i][0].ard)==0){
            return 1;
        }
    }
    return 0;
}
/*<--THE END FOR CHECK OF REPEATION IN DFA-->*/
/*<--TO PRINT THE ELEMENTS FROM ORIGINAL NFA STATE-->*/
void printd(char dar[],int n,int m, int r, int c){
    for(int i=1;i<n;i++){
        if(strcmp(dar,nf[i][0].arn)==0){
            for(int h=1;h<m;h++){
                strcpy(df[r+1][h].ard,nf[i][h].arn);
            }
            break;
        }
    }
}
/*<--THE END FOR ORIGINAL NFA STATE-->*/
/*<--MAIN FUNCTION-->*/
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<m;i++)
        cin>>arc[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>nf[i][j].arn;
        }
    }
    n++;
    m++;
    /*----------------------------*/
    /*<-- To create NFA TABLE --> */
    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){
            strcpy(nf[i][j].arn,nf[i-1][j-1].arn);
        }
    }
    for(int i=0;i<n;i++){
            strcpy(nf[i+1][0].arn,arr[i]);
    }
    strcpy(nf[0][0].arn," ");
    for(int i=0;i<m;i++){
            strcpy(nf[0][i+1].arn,arc[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<nf[i][j].arn<<"  ";
        }
        cout<<"\n";
    }
    /*<-- The End of NFA TABULAR CREATION AND DISPLAYING-->*/
    /*----------------------------*/
    strcpy(arr1[g++],arr[0]);
    strcpy(df[0][0].ard," ");
    strcpy(df[1][0].ard,nf[1][0].arn);
    for(int i=1;i<m;i++){
        strcpy(df[0][i].ard,arc[i-1]);
    }
    strcpy(df[1][1].ard,nf[1][1].arn);
    strcpy(df[1][2].ard,nf[1][2].arn);
    int e1=1,r=1,s=0,cy=0;
    bool tru=true;
    while(tru){
    cy=0;
    s++;
    for(int i=1;i<m;i++){
        if(strcmp(df[s][i].ard,"-")==0){
            cy++;
        }
        else if(check(df[s][i].ard,n,m)){                    //check for not found and
            printr(df[s][i].ard,n,m,r,i);                    //to print corresponding new state transition states
            strcpy(arr1[g++],df[s][i].ard);                  //to store in an array where DFA transition state occurs
            strcpy(arr[n],df[s][i].ard);
            strcpy(nf[n][0].arn,df[s][i].ard);               //to store in NFA array the new transition element
            strcpy(df[++e1][0].ard,df[s][i].ard);            //to store in DFA array the new transition element
            n++;
            r++;
        }else{
            if(!check(df[s][i].ard,n,m) && !checkd(df[s][i].ard,n,m)){
                printd(df[s][i].ard,n,m,r,i);
                strcpy(df[++e1][0].ard,nf[s][i].arn);
                r++;
            }else{
            }
            cy++;
        }
    }
    if(cy==2){
        tru=false;
    }
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(strcmp(df[i][j].ard,"")==0 && j==0){
                break;
            }
            else if(strcmp(df[i][j].ard,"")==0){
                cout<<"-      ";
            }else{
                cout<<df[i][j].ard<<"       ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
