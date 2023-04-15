#include <stdio.h>
#include <stdlib.h>
// 역트리를 만들고
// 위상정렬로 개수 카운트

struct Node{
    int number;
    struct Node *next;
};

//큐에 새 노드를 삽입
void push(struct Node *queue, int new_number){
    if(queue->number != 0){
        struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->number = queue->number;
        new_node->next = queue->next;
        queue->next = new_node;
    }
    queue->number = new_number;
}

int pop(struct Node *queue){
    if(queue->number == 0)
        return 0;

    int res = queue->number;
    if(queue->next) {
        queue->number = queue->next->number;
        queue->next = queue->next->next;
    }
    else queue->number = 0;
    return res;
}

int main(){
    int n, root, q;
    scanf("%d %d %d", &n, &root, &q);
    
    int i, j, a, b;
    int **link = (int**)malloc(sizeof(int*)*(n+1));
    for(i=0; i<n+1; i++)
        link[i] = (int*)malloc(sizeof(int)*(n+1));

    for(i=0; i<n-1; i++){
        scanf("%d %d", &a, &b);
        link[a][b] = 1;
        link[b][a] = 1; //양방향으로 시작
    }

    //root부터 dfs해서 트리 생성
    struct Node queue = {root, NULL};
    int node, count = 0;
    while((node = pop(&queue)) != 0){ //첫 node = 5
        for(i=1; i<n+1; i++)
            if(link[node][i]==1){
                push(&queue, i);
                link[i][node] = 0; //단방향으로
            }
    }

    //query
    for(i=0; i<q; i++){
        int amount = 1;
        scanf("%d", &a);
        queue.number = a;
        queue.next = NULL;
        while((node = pop(&queue))){
            for(j=1; j<n+1; j++)
                if(link[node][j]){
                    push(&queue, j);
                    amount ++;
                }
        }
        printf("%d\n", amount);
    }
    return 0;
}
