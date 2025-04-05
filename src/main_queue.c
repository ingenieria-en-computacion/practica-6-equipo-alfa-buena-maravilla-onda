#define QUEUE_IMPLEMENTATION
#include "queue.h"
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
    Queue_int* nums = queue_int_create();
    queue_int_enqueue(nums, 10, nums->length);
    queue_int_enqueue(nums, 20, nums->length);

    printf("Cola: ");
    queue_int_print(nums, print_int); // Usar función concreta para evitar errores

    queue_int_dequeue(nums, 0);
    printf("Cola: ");
    queue_int_print(nums, print_int);

    if(queue_int_is_empty(nums)){
        printf("Cola vacia\n");
    }else{
        printf("Cola no esta vacia\n");
    }

    queue_int_dequeue(nums, 0);

    printf("Cola: ");
    queue_int_print(nums, print_int);

    if(queue_int_is_empty(nums)){
        printf("Cola vacia\n");
    }else{
        printf("Cola no esta vacia\n");
    }
    
    queue_int_clear(nums);
    
    Queue_char *chars = queue_char_create();
    queue_char_enqueue(chars, 'd', chars->length);
    queue_char_enqueue(chars, 'e', chars->length);
    queue_char_enqueue(chars, 'c', 0);
    queue_char_enqueue(chars, 'b', 0);
    queue_char_enqueue(chars, 'a', 0);

    printf("Cola: ");
    queue_char_print(chars, print_char);

    queue_char_dequeue(chars, 0);
    queue_char_dequeue(chars, 0);
    queue_char_dequeue(chars, 0);

    printf("Cola: ");
    queue_char_print(chars, print_char);

    if(queue_char_is_empty(chars)){
        printf("Cola vacia\n");
    }else{
        printf("Cola no esta vacia\n");
    }

    queue_char_dequeue(chars, chars->length);
    queue_char_dequeue(chars, chars->length);

    printf("Cola: ");
    queue_char_print(chars, print_char);

    if(queue_int_is_empty(nums)){
        printf("Cola vacia\n");
    }else{
        printf("Cola no esta vacia\n");
    }

    queue_char_clear(chars);
    return 0;
}
