#include<fstream>
#include<cstring>
using namespace std;
ifstream fin("day2.in");
ofstream fout("day2.out");
int x;
long long v[100000],w[100000];
char s[100010];
int main(){
    fin>>s;
    int n=strlen(s);
    int p=0;
    for(int i=0;i<n;i++){
        if(s[i]==','){
            v[x++]=p;
            p=0;
        }
        else{
            p=p*10+(s[i]-'0');
        }
    }
    v[x]=p;
    for(int i=0;i<=x;i++)
        w[i]=v[i];
    /// citire
    for(int i=0;i<=99;i++){

        for(int j=0;j<=99;j++){
            for(int k=0;k<=x;k++)
                v[k]=w[k];
            v[1]=i;
            v[2]=j;
            p=0;
            while(p<=x){
                if(p%4==0 || p==0){
                    if(v[p]==1){
                        v[v[p+3]]=v[v[p+1]]+v[v[p+2]];
                        p+=4;
                        continue;
                    }
                    if(v[p]==2){
                        v[v[p+3]]=v[v[p+1]]*v[v[p+2]];
                        p+=4;
                        continue;
                    }
                    if(v[p]==99)
                        break;
                }
            }
            if(v[0]==19690720){
                fout<<i*100+j;
                return 0;
            }
        }
    }
    fout<<v[0];
    return 0;
}

