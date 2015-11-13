#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long>bit1,bit2;

void update(vector<long long>&tree,long long index,long long value){
    while(index<tree.size()){
        tree[index] += value;
        index += (index & ((-1)*index));
    }
}
long long query(vector<long long>tree,long long index){
    long long ret = 0;
    while(index>0){
        ret += tree[index];
        index -= index & ((-1)*index);
    }
    return ret;
}

long long query(long long l,long long r){
    return (query(bit1,r)*r-query(bit2,r))-(query(bit1,l-1)*(l-1)-query(bit2,l-1));
}

int main(){
    long long t;
    scanf("%lld", &t);
    while(t--){
        long long n,c;scanf("%lld %lld", &n, &c);
        bit1.resize(0);bit1.resize(n+1,0);
        bit2.resize(0);bit2.resize(n+1,0);

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
