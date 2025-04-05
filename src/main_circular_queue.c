#define CQUEUE_IMPLEMENTATION
#include "circular_queue.h"
#include <stdio.h>

void print_int(int value) {
    printf("%d", value);
}

bool int_cmp(int a, int b) {
    return a == b;
}

void print_char(char value) {
    printf("%c", value);
}

bool char_cmp(char a, char b) {
    return a == b;
}

int main() {
    CQueue_int* nums = cqueue_int_create();
    cqueue_int_enqueue(nums, 10);
    cqueue_int_enqueue(nums, 20);

    printf("Cola: ");
    cqueue_int_print(nums, print_int); // Usar función concreta para evitar errores

    cqueue_int_dequeue(nums);
    printf("Cola: ");
    cqueue_int_print(nums, print_int);

    if(cqueue_int_is_empty(nums)){
        printf("Cola vacia\n");
    }else{
        printf("Cola no esta vacia\n");
    }

    cqueue_int_dequeue(nums);

    printf("Cola: ");
    cqueue_int_print(nums, print_int);

    if(cqueue_int_is_empty(nums)){
        printf("Cola vacia\n");
    }else{
        printf("Cola no esta vacia\n");
    }

    cqueue_int_clear(nums);

    CQueue_char *chars = cqueue_char_create();
    cqueue_char_enqueue(chars, 'a');
    cqueue_char_enqueue(chars, 'b');
    cqueue_char_enqueue(chars, 'c');
    cqueue_char_enqueue(chars, 'd');
    cqueue_char_enqueue(chars, 'e');

    printf("Cola: ");
    cqueue_char_print(chars, print_char);

    cqueue_char_dequeue(chars);
    cqueue_char_dequeue(chars);
    cqueue_char_dequeue(chars);

    printf("Cola: ");
    cqueue_char_print(chars, print_char);

    if(cqueue_char_is_empty(chars)){
        printf("Cola vacia\n");
    }else{
        printf("Cola no esta vacia\n");
    }

    cqueue_char_dequeue(chars);
    cqueue_char_dequeue(chars);

    printf("Cola: ");
    cqueue_char_print(chars, print_char);

    if(cqueue_int_is_empty(nums)){
        printf("Cola vacia\n");
    }else{
        printf("Cola no esta vacia\n");
    }

    cqueue_char_clear(chars);
    return 0;
}