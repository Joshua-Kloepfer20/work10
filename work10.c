#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct food {char name[100]; float price; float weight; struct food * next;};

void print_list(struct food * node) {
    if (node != NULL) {
        printf("%s cost %0.2f and weighs %0.2f\n", node->name, node->price, node->weight);
        print_list(node->next);
    }
}

struct food * insert_front(struct food * node, char *name, float price, float weight) {
    struct food *x = malloc(sizeof(struct food));
    strcpy(x->name, name);
    x->price = price;
    x->weight = weight;
    x->next = node;
    return x;
}

struct food * free_list(struct food * node) {
    if (node != NULL) {
        free_list(node->next);
        free(node);
    }
    else {
        return node;
    }
}

int main() {
    struct food *x = malloc(sizeof(struct food));
    strcpy(x->name, "apples");
    x->price = 3.76;
    x->weight = 5.48;
    int i;
    x = insert_front(x, "oranges", 3.85, 6.75);
    x = insert_front(x, "lolypops", .99, .59);
    x = insert_front(x, "chocholate", 2.99, 1.34);
    x = insert_front(x, "cheerios", 5.34, 3.21);
    x = insert_front(x, "potatoes", 5.75, 3.64);
    print_list(x);
    free_list(x);
    return 0;
}
