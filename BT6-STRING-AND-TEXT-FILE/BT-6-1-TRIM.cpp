#include<iostream>
#include<ctype.h>
using namespace std;
#define MAX 1000

void trim(char s[]){
    int start=0, end=-1;
    int i=0;
    for (i;s[i]!='\0';i++){
        if (s[i]==' '){
            start++;
        } else break;
    }
    for (i;s[i]!='\0';i++){}
    end=--i;
    for (i;i>=0;i--){
        if (s[i]==' '){
            end--;
        } else break;
    }
    int j=0;
    i=start;
    for (i;i<=end;i++){
        if (s[i]==' '){
            if (s[j-1]!=' '){
                s[j]=' ';
                j++;
            }
        } else {
            s[j]=s[i];
            j++;
        }
    }
    s[j]='\0';
}

int main(){
    char sen[MAX];
    cout<<"Enter a sentence = ";
    cin.getline(sen,MAX);
    trim(sen);
    cout<<sen;
}