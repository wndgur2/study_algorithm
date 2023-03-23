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

int main(){
    int T, n_relations, answer;
    int i, j, k, n_people, pA, pB;
    char *a = (char*)malloc( sizeof(char) * 20 + 1);
    char *b = (char*)malloc( sizeof(char) * 20 + 1);
    bool found_a, found_b;
    char** people = (char**)malloc( sizeof(char*) * 100000 + 1 );
    // char** people = (char**)malloc( sizeof((char*)malloc( sizeof(char) * 20 + 1)) * 100000 + 1 );
    int* parents = (int*)malloc( sizeof(int) * 100000 + 1 );
    int* amount = (int*)malloc( sizeof(int) * 100000 + 1 );

    scanf("%d", &T);

    for(i=0; i<T; i++){
        n_people = 0;
        scanf("%d", &n_relations);

        for(j=0; j<n_relations; j++){
            scanf("%s %s", a, b);
            found_a = findPerson(a, people, n_people)==n_people? false: true;
            found_b = findPerson(b, people, n_people)==n_people? false: true;

            if(!found_a){
                pushString(people, n_people, a);
                parents[n_people] = n_people; // a는 자신
                pA = n_people
                amount[pA] = 1;
                n_people += 1;
                if(!found_b){ // 둘다 처음
                    pushString(people, n_people, b);
                    pB = n_people;
                    parents[pB] = pA; // b는 a를 가리킴
                    amount[pB] = 1;
                    amount[pA] += amount[pB];
                    n_people += 1;
                } else{ // B는 있음
                    pB = getParent(findPerson(b, people, n_people), parents);
                    parents[pB] = pA; // b의 부모가 a를 가리킴
                    amount[pA] += amount[pB];
                }
            }else if(!found_b){ // B만 처음
                pushString(people, n_people, b);
                pA = getParent(findPerson(a, people, n_people), parents);
                pB = n_people;
                parents[pB] = pA; // b가 a의 부모를 가리킴
                amount[pB] = 1;
                amount[pA] += amount[pB];
                n_people += 1;
            }
            if(found_a & found_b){
                pA = getParent(findPerson(a, people, n_people), parents);
                pB = getParent(findPerson(b, people, n_people), parents);
                parents[pB] = pA; // b의 부모가 a의 부모를 가리킴
                amount[pA] += amount[pB];
            }
            printf("%d\n", amount[pA]);
        }
    }
    return 0;
}