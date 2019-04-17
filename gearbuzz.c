#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct cons {
    uint32_t car;
    struct cons *cdr;
};

struct circle {
    uint32_t size;
    char *messages[2];
    struct cons *head;
};

void circle_init(struct circle *c, char *message, uint32_t n) {
    struct cons *start, *current;
    c->head = malloc(sizeof(*c->head));
    start = current = c->head;
    c->size = n;
    c->messages[0] = message;
    c->messages[1] = "";
    for (n ; n > 1 ; n--) {
        current->car = 1;
        current->cdr = malloc(sizeof(*current));
        current = current->cdr;
    }
    current->car = 0;
    current->cdr = start;
}

void circle_free(struct circle *c) {
    struct cons *current, *next;
    current = next = c->head;
    for (c->size ; c->size ; c->size--) {
        current = next;
        next = next->cdr;
        free(current);
    }   
}

#define CIRCLE_NUM 4

int main() {
    char *output[2];
    char number[11]; /* max number of digits for a 32 bit int + 1 */
    uint32_t fizzed, n, i;
    struct circle *c;
    struct circle circles[CIRCLE_NUM];
    output[0] = "";
    output[1] = number; 
    circle_init(&circles[0], "fizz", 3);
    circle_init(&circles[1], "buzz", 5);
    circle_init(&circles[2], "bang", 7);
    circle_init(&circles[3], "boop", 11);
    for (n = 1 ; n < 101 ; n++) {
        snprintf(number, 11, "%u", n);
        fizzed = 1;
        for (i = 0 ; i < CIRCLE_NUM ; i++) {
            c = &circles[i];
            fizzed *= c->head->car;
            printf("%s", c->messages[c->head->car]);
            c->head = c->head->cdr;
        }
        printf("%s\n", output[fizzed]);
    };
    for (i = 0 ; i < CIRCLE_NUM ; i++) {
        circle_free(&circles[i]);
    }
    return 0;
}
