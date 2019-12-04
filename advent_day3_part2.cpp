#include<fstream>
#include<cstring>
#include<map>
using namespace std;
ifstream fin("day3.in");
ofstream fout("day3.out");
int n,p,ok,minim,x,y;
map< pair<int,int> , pair<int,int> > v;
char s[10010],directie;
int di[]={0,1,0,-1};
int dj[]={1,0,-1,0};

int dist(int a, int b){
    if(a<0)
        a*=(-1);
    if(b<0)
        b*=(-1);
    return a+b;
}

int main(){
    fin>>s;n=strlen(s);
    x=y=0;
    int i=0;
    int D=0;
    while(i<n){
        if(s[i]==','){
            i++;
        }
        else{
            directie=s[i++];p=0;
            for(;s[i]!=','&&i<n;i++)
                p=p*10+(s[i]-'0');
            if(directie=='U'){
                for(int d=1;d<=p;d++){
                    y+=1;
                    D++;
                    if(!v[make_pair(x,y)].first)
                        v[make_pair(x,y)].first=D;
                }
            }
            if(directie=='R'){
                for(int d=1;d<=p;d++){
                    x+=1;
                    D++;
                    if(!v[make_pair(x,y)].first)
                        v[make_pair(x,y)].first=D;
                }
            }
            if(directie=='D'){
                for(int d=1;d<=p;d++){
                    y-=1;
                    D++;
                    if(!v[make_pair(x,y)].first)
                        v[make_pair(x,y)].first=D;
                }
            }
            if(directie=='L'){
                for(int d=1;d<=p;d++){
                    x-=1;
                    D++;
                    if(!v[make_pair(x,y)].first)
                        v[make_pair(x,y)].first=D;
                }
            }
        }
    }
    x=y=D=0;
    fin>>s;n=strlen(s);
    i=0;minim=1000000000;
    while(i<n){
        if(s[i]==','){
            i++;
        }
        else{
            directie=s[i++];p=0;
            for(;s[i]!=','&&i<n;i++)
                p=p*10+(s[i]-'0');
            if(directie=='U'){
                for(int d=1;d<=p;d++){
                    y+=1;
                    D++;
                    if(!v[make_pair(x,y)].second){
                        v[make_pair(x,y)].second=D;
                    }
                    if(v[make_pair(x,y)].second && v[make_pair(x,y)].first)
                        minim=min(minim,v[make_pair(x,y)].second+v[make_pair(x,y)].first);
                }
            }
            if(directie=='R'){
                for(int d=1;d<=p;d++){
                    x+=1;
                    D++;
                    if(!v[make_pair(x,y)].second){
                        v[make_pair(x,y)].second=D;
                    }
                    if(v[make_pair(x,y)].second && v[make_pair(x,y)].first)
                        minim=min(minim,v[make_pair(x,y)].second+v[make_pair(x,y)].first);
                }
            }
            if(directie=='D'){
                for(int d=1;d<=p;d++){
                    y-=1;
                    D++;
                    if(!v[make_pair(x,y)].second){
                        v[make_pair(x,y)].second=D;
                    }
                    if(v[make_pair(x,y)].second && v[make_pair(x,y)].first)
                        minim=min(minim,v[make_pair(x,y)].second+v[make_pair(x,y)].first);
                }
            }
            if(directie=='L'){
                for(int d=1;d<=p;d++){
                    x-=1;
                    D++;
                    if(!v[make_pair(x,y)].second){
                        v[make_pair(x,y)].second=D;
                    }
                    if(v[make_pair(x,y)].second && v[make_pair(x,y)].first)
                        minim=min(minim,v[make_pair(x,y)].second+v[make_pair(x,y)].first);
                }
            }
        }
    }
    fout<<minim;
    return 0;
}

