#include <bits/stdc++.h>
using namespace std;

int main()
{

    int num,base,mod,c=0;
    cin>>num>>base;
    char n[100];

    for(int i=0;; i++)
    {
        c++;
        mod = num%base;
        //cout<<"int-"<<mod<<endl;
        num=num/base;
        if(base==16 && mod>=10)
        {
            mod=mod-10;
            mod='A'+mod;


        }
        else
        {
            mod=mod+'0';
        }

       // cout<<"char-"<<char(mod)<<endl;
        n[i]=char(mod);
        if(num==0) break;

    }
    n[c]='\0';
    strrev(n);
    cout<<n;


    return 0;
}
