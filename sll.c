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

node locate(node head, int x){
    node tmp = create_Node(x);
    tmp = head;
    while(tmp != NULL){
        if(tmp->value == x){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

node insert_after(node head, node pos, int x){
    if(pos == NULL) return head;
    node nn = create_Node(x);
    if(head == NULL){
        push_front(head, x);
        return head;
    }
    nn->next = pos->next;
    pos->next = nn;
}

node prev(node head, node pos){
    node tmp = head;
    while(tmp != NULL){
        if(tmp->next == pos) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

node insert_before(node head, node pos, int x){
    if(pos == NULL){
        return head;
    }
    node nn = create_Node(x);
    if(head == NULL){
        head = nn;
        return head;
    }
    prev(head, pos)->next = nn;
    nn->next = pos;
    return head;
}

node insert_before_recursive(node head, node pos, int x){
    if(pos == NULL){
        return head;
    }
    if(head == NULL || pos == head){
        node nn = create_Node(x);
        nn->next = head;
        nn = head;
    }
    else{
        head->next = insert_before_recursive(head->next, pos, x); //***********
    }
    return head;
}

int sum(node head){
    int S = 0;
    node tmp = head;
    while(tmp != NULL){
        S = S + tmp->value;
        tmp = tmp->next;
    }
    return S;
}

int sum_recursive(node head){
    if(head == NULL){
        return 0;
    }
    return head->value + sum_recursive(head->next);
}

node remove_an(node head, node pos){
    if(head == NULL || pos == NULL) return head;
    if(head == pos){
        head = head->next;
        pos = NULL;
        free(pos);
        return head;
    }
    else{
        head->next = remove_an(head->next, pos);
        return head;
    }
}

void print_list(node head){
    node tmp = head;
    while(tmp != NULL){
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(){
    node head = create_Node(1);
    push_back(head, 2);
    push_front(head, 0);
    print_list(head);
    return 0;
}