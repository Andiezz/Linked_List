#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
} *node;

node create_Node(int x){
    node nn = malloc(sizeof(struct node));
    nn->next = NULL;
    nn->value = x;
    return nn;
}

node push_back(node head, int x){
    node nn = create_Node(x);
    if(head == NULL){
        head == nn;
        return head;
    }
    node tmp = head;
    while(tmp->next == NULL){
        tmp = tmp->next;
    }
    tmp->next = nn;
    return(head);
}

node push_front(node head, int x){
    node nn = create_Node(x);
    if(head == NULL){
        head = nn;
        return head;
    }
    else{
        node h2 = head;
        nn->next = h2;
        head = nn;
        return head;
    }
}


// .........................................................................................................................continue
node locate(sll list, int x){
    node tmp = create_Node(x);
    tmp = list->front;
    while(tmp != NULL){
        if(tmp->value == x){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void insert_after(sll list, node nn, node pos, int x){
    if(pos == NULL) return;
    nn = create_Node(x);
    if(list->front == NULL){
        push_front(list, nn, x);
        return;
    }
    pos->next = nn->next;
    pos->next = nn;
}

node prev(sll list, node pos){
    node tmp = list->front;
    while(tmp != NULL){
        if(tmp->next == pos) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

sll insert_before(sll list, node pos, int x){
    if(pos == NULL){
        return list;
    }
    node nn = create_Node(x);
    if(list->front == NULL){
        list->front = list->back = nn;
        return list;
    }
    prev(list, pos)->next = nn;
    nn->next = pos;
    return list;
}

sll insert_before_recursive(sll list, node pos, int x){
    if(pos == NULL){
        return list;
    }
    if(list->front == NULL || pos == list->front){
        node nn = create_Node(x);
        nn->next = list->front;
        nn = list->front;
    }
    node tmp = list->front;
    while(list->front != pos){
        list->front = list->front->next;
        insert_before_recursive(list, pos, x);
    }
    list->front = tmp;
    return list;
}

int sum(sll list){
    int S = 0;
    node tmp = list->front;
    while(tmp != NULL){
        S = S + tmp->value;
        tmp = tmp->next;
    }
    return S;
}

int sum_recursive(sll list){
    if(list->front == NULL){
        return 0;
    }
    int tmp = list->front->value;
    node temp = list->front;
    list->front = list->front->next;
    return tmp + sum_recursive(list);
}

sll remove(sll list, node pos){
    if(list->front == NULL || pos == NULL) return list;
    if(list->front == pos){
        list->front = list->front->next;
        pos = NULL;
        free(pos);
        return list;
    }
    else{
        list->front->next = remove(list->front, pos);
        return list;
    }
}

int main(){
    sll list = create_List();
    list->front = create_Node(1);
    node n1, n0;
    push_back(list, n1, 2);
    push_front(list, n0, 0);
    locate(list, 2);
    return 0;
}