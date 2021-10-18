#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "work10.h"
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
        return free_list(node->next);
        free(node);
    }
    else {
        return node;
    }
}

struct food * remove_node(struct food *node, float data) {
    struct food *x = node;
    struct food *y = node;
    if (node->price == data || node->weight == data) {
        x = node->next;
        free(node);
        return x;
    }
    while (x != NULL) {
        if (x->price == data || node->weight == data) {
            y->next = x->next;
            free(x);
            return node;
        }
        y = x;
        x = x->next;
    }
    return node;
}