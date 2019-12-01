#include<fstream>
using namespace std;
ifstream fin("day1.in");
ofstream fout("day1.out");
long long x,s;
int main(){
    while(fin>>x){
        x/=3;x-=2;
        while(x>0){
            s+=x;
            x/=3;x-=2;

        }
    }
    fout<<s;
    return 0;
}
