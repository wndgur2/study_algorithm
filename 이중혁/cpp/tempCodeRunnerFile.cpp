#include <iostream>
#include <string>

using namespace std;

int getParent(int i, int* parents){
    if(i==parents[i]){
        return i;
    } else{
        parents[i] = getParent(parents[i], parents);
        return parents[i];
    }
}

int findPerson(char* name, char** people, int n){
    for(int i=0; i<n; i++){
        // printf("COMPARING %s, %s\n", name, people[i]);
        for(int j=0; j<20; j++){
            if(people[i][j] != name[j]){
                break;
            } else if(j==19){
                return i;
            }
        }
    }
    return n;
}

void pushString(char** people, int idx, char* str){
    char* newStr = (char*)malloc( sizeof(char) * 20 + 1);
    for(int i=0; i<20; i++){
        newStr[i] = str[i];
    }
    people[idx] = newStr;
    return;
}

int hash_f(char* s){
    int result = 3;
    for(int i=0; i<20; i++){
        result *= int(s[i]) + 41;
    }
    return (result*result)%20000000;
}

int main(){
    int T, n_relations, answer;
    int i, j, k, pA, pB;
    char *a = (char*)malloc( sizeof(char) * 20 + 1);
    char *b = (char*)malloc( sizeof(char) * 20 + 1);
    int idx_a, idx_b;
    int* parents = (int*)malloc( sizeof(int) * 20000000 + 1 );
    int* amount = (int*)malloc( sizeof(int) * 20000000 + 1 );

    scanf("%d", &T);

    for(i=0; i<T; i++){
        for(j=0; j<20000000; j++) {parents[j] = j; amount[j] = 1;}

        scanf("%d", &n_relations);

        for(j=0; j<n_relations; j++){
            scanf("%s %s", a, b);
            idx_a = hash_f(a);
            idx_b = hash_f(b);
            // printf("%d %d\n", idx_a, idx_b);
            pA = getParent(idx_a, parents);
            pB = getParent(idx_b, parents);
            parents[pB] = pA;
            amount[pA] += amount[pB];
            printf("%d\n", amount[pA]);
        }
    }
    return 0;
}