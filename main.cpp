#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>tree;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n,c;scanf("%d %d", &n, &c);
        tree.resizer(0);
        tree.resize(n);
        while(c--){
            int a,l,r;
            scanf("%d %d", &a, &l, &r);
            if(a){
                int value;
                scanf("%d", &value);
                update(bit1,l,value);
                update(bit1,r+1,(-1)*value);
                update(bit2,l,value*);
                update(bit2,r+1,(-1)*value*);
            }else{
                printf("%d\n", query(1,a-1,b-1).maxM);
            }
        }
    }
    return 0;
}
