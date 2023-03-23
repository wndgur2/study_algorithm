#include <iostream>
#include <cstring>

using namespace std;

int* parents = (int*)malloc( sizeof(int) * 500000 + 1 );
int* amount = (int*)malloc( sizeof(int) * 500000 + 1 );
int* depth = (int*)malloc( sizeof(int) * 500000 + 1 );
bool* exist = (bool*)malloc( sizeof(bool) * 500000 + 1 );
char** people = (char**)malloc( sizeof(char*) * 500000 + 1 );

int getParent(int i, int* parents){
    // printf("PARENT");
    if(i==parents[i]){
        return i;
    } else{
        parents[i] = getParent(parents[i], parents);
        return parents[i];
    }
}

void pushString(char** people, int idx, char* str){
    char* newStr = (char*)malloc( sizeof(char) * 20 + 1);
    for(int i=0; i<20; i++){
        newStr[i] = str[i];
    }
    people[idx] = newStr;
    return;
}

// int hash_f(char* s){
//     long result = 3;
//     for(int i=0; i<20; i++){
//         result *= int(s[i]) + 41;
//     }
//     result %= 200000000;
//     if (result <0) return -result;
//     return result;
// }
unsigned hash_f(const char* s, bool* exist, char** people, int base = 0){
    // printf("HASH");
    unsigned h = 3163 + base;
    int i = 0;
    while (s[i]) {
        h = (((h * 59) << 3) * (s[i] * 3)) % 500000;
        i++;
    }

    if(exist[h]){
        i=0;
        while(s[i]){
            if(s[i] != people[h][i])
                return hash_f(s, exist, people, base+1);
            i++;
        }
        return h;
    }

    if(!exist[h]){
        exist[h] = true;
        parents[h] = h;
        amount[h] = 1;
        depth[h] = 1;
        char* newStr = (char*)malloc( sizeof(char) * 20 + 1);
        for(int i=0; i<20; i++){
            newStr[i] = s[i];
        }
        people[h] = newStr;
    }
    return h;
}

int main(){
    int T, n_relations;
    int i, j, k, pA, pB;
    char *a = (char*)malloc( sizeof(char) * 20 + 1);
    char *b = (char*)malloc( sizeof(char) * 20 + 1);
    long idx_a, idx_b;

    scanf("%d", &T);

    for(i=0; i<T; i++){
        memset(exist, 0, 500000);
        scanf("%d", &n_relations);

        for(j=0; j<n_relations; j++){
            scanf("%s %s", a, b);
            idx_a = hash_f(a, exist, people);
            idx_b = hash_f(b, exist, people);
            // printf("%ld %ld\n", idx_a, idx_b);
            pA = getParent(idx_a, parents);
            pB = getParent(idx_b, parents);
            if(pA != pB){
                if(depth[pA] > depth[pB]){ // B를 A에
                    parents[pB] = pA;
                    amount[pA] += amount[pB];
                } else{
                    if(depth[pA] == depth[pB]) depth[pB] += 1;
                    parents[pA] = pB;
                    amount[pB] += amount[pA];
                }
            }
            printf("%d\n", amount[getParent(pA, parents)]);
        }
    }
    return 0;
}