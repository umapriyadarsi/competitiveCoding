#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long>bit1(100001,0),bit2(100001,0);
long long n;

void update(vector<long long>&tree,long long index,long long value){
    for(;index<=n;index += (index & ((-1)*index)))tree[index] += value;
}
long long query(vector<long long>tree,long long index){
    long long ret = 0;
    for(;index;index -= (index & ((-1)*index)))ret += tree[index];
    return ret;
}

long long query(long long l,long long r){
    return (query(bit1,r)*r-query(bit2,r))-(query(bit1,l-1)*(l-1)-query(bit2,l-1));
}

int main(){
    long long t;
    scanf("%lld", &t);
    while(t--){
        long long c;scanf("%lld %lld", &n, &c);
        for(int i=0;i<=n;i++)bit1[i] = 0;
        for(int i=0;i<=n;i++)bit2[i] = 0;

        while(c--){
            long long a,l,r;
            scanf("%lld %lld %lld", &a, &l, &r);
            if(a){
                printf("%lld\n", query(l,r));
            }else{
                long long value;
                scanf("%lld", &value);
                update(bit1,l,value);
                update(bit1,r+1,(-1)*value);
                update(bit2,l,value*(l-1));
                update(bit2,r+1,(-1)*value*r);
            }
        }
    }
    return 0;
}
