#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// ----------------------------
// Macro para declarar estructuras y prototipos
// ----------------------------
#define DECLARE_QUEUE(TYPE) \
    typedef struct Node_##TYPE { \
        TYPE data; \
        struct Node_##TYPE* next; \
    } Node_##TYPE; \
    Node_##TYPE* node_##TYPE##_create(TYPE);\
    Node_##TYPE* node_##TYPE##_destroy(Node_##TYPE*);\
    \
    typedef struct { \
        Node_##TYPE* head; \
        Node_##TYPE* tail; \
        size_t length; \
    } Queue_##TYPE; \
    \
    Queue_##TYPE* queue_##TYPE##_create(void); \
    bool queue_##TYPE##_enqueue(Queue_##TYPE* queue, TYPE data, int pos); \
    bool queue_##TYPE##_dequeue(Queue_##TYPE* queue, int pos); \
    bool queue_##TYPE##_get(const Queue_##TYPE* queue, TYPE* out); \
    size_t queue_##TYPE##_length(const Queue_##TYPE* queue); \
    void queue_##TYPE##_clear(Queue_##TYPE* queue); \
    void queue_##TYPE##_print(const Queue_##TYPE* queue, void (*print_fn)(TYPE)); \
    bool queue_##TYPE##_contains(const Queue_##TYPE* queue, TYPE data);

// ----------------------------
// Macro para implementación
// ----------------------------
#define IMPLEMENT_QUEUE(TYPE) \
    Node_##TYPE* node_##TYPE##_create(TYPE data){\
        Node_##TYPE* new_node = malloc(sizeof(Node_##TYPE)); \
        new_node->data = data;\
        new_node->next = NULL;\
        return new_node;\
    }\
    \
    Node_##TYPE* node_##TYPE##_destroy(Node_##TYPE *node){\
        if(node->next ==NULL){\
            free(node);\
            return NULL;\
        }\
        return node;\
    }\
    Queue_##TYPE* queue_##TYPE##_create(void) { \
        Queue_##TYPE* queue = malloc(sizeof(Queue_##TYPE)); \
        if (!queue) return NULL; \
        queue->head = queue->tail = NULL; \
        queue->length = 0; \
        return queue; \
    } \
    \
    void queue_##TYPE##_destroy(Queue_##TYPE* queue) { \
        if (!queue) return; \
        Node_##TYPE* current = queue->head; \
        while (current) { \
            Node_##TYPE* temp = current; \
            current = current->next; \
            free(temp); \
        } \
        free(queue); \
    } \
    \
    bool queue_##TYPE##_enqueue(Queue_##TYPE* queue, TYPE data, int pos) { \
        if (!queue) return false; \
        if(pos != 0 && pos != queue->length) return false; \
        \
        Node_##TYPE* new_node = node_##TYPE##_create(data); \
        if (!new_node) return false; \
        \
        new_node->next = NULL; \
        \
        if(queue->length == 0){ \
            queue->head = new_node; \
            queue->tail = new_node; \
        }else if(pos == queue->length){ \
            queue->tail->next = new_node; \
            queue->tail = new_node; \
        }else if(pos == 0){ \
            new_node->next = queue->head;\
            queue->head = new_node; \
        } \
        queue->length++; \
        return true; \
    } \
    \
    bool queue_##TYPE##_dequeue(Queue_##TYPE* queue, int pos) { \
        if (!queue || !queue->head) return false; \
        \
        if(pos != 0 && pos != queue->length) return false; \
        \
        Node_##TYPE* to_delete = queue->head; \
        \
        if(pos == 0){ \
        queue->head = queue->head->next; \
        if (!queue->head) queue->tail = NULL; \
        \
        } else if(pos == queue->length){ \
            Node_##TYPE* to_delete_prev = queue->head; \
            for(int i = 0; i < queue->length-2; i++){ \
                to_delete_prev = to_delete_prev->next; \
            } \
            to_delete = queue->tail; \
            queue->tail = to_delete_prev; \
            queue->tail->next = NULL; \
        } \
        to_delete->next = NULL; \
        free(to_delete); \
        queue->length--; \
        return true; \
    } \
    \
    bool queue_##TYPE##_get(const Queue_##TYPE* queue, TYPE* out) { \
        if (!queue || !out) return false; \
        \
        *out = queue->head->data; \
        return true; \
    } \
    \
    size_t queue_##TYPE##_length(const Queue_##TYPE* queue) { \
        return queue ? queue->length : 0; \
    } \
    \
    bool queue_##TYPE##_is_empty(const Queue_##TYPE* queue) { \
        return queue ? queue->length == 0 : true; \
    } \
    \
    void queue_##TYPE##_clear(Queue_##TYPE* queue) { \
        if (!queue) return; \
        \
        Node_##TYPE* current = queue->head; \
        while (current) { \
            Node_##TYPE* temp = current; \
            current = current->next; \
            free(temp); \
        } \
        \
        queue->head = queue->tail = NULL; \
        queue->length = 0; \
    } \
    \
    void queue_##TYPE##_print(const Queue_##TYPE* queue, void (*print_fn)(TYPE)) { \
        if (!queue || !print_fn) return; \
        \
        printf("["); \
        Node_##TYPE* current = queue->head; \
        while (current) { \
            print_fn(current->data); \
            if (current->next) printf(", "); \
            current = current->next; \
        } \
        printf("]\n"); \
    } \
    \
    bool queue_##TYPE##_contains(const Queue_##TYPE* queue, TYPE data) { \
        if (!queue) return false; \
        \
        Node_##TYPE* current = queue->head; \
        while (current) { \
            if (current->data == data) { \
                return true; \
            } \
            current = current->next; \
        } \
        \
        return false; \
    }

// ----------------------------
// Declaración para tipos concretos
// ----------------------------
DECLARE_QUEUE(int)
DECLARE_QUEUE(char)
DECLARE_QUEUE(float)

// ----------------------------
// Implementación para tipos concretos
// ----------------------------
#ifdef QUEUE_IMPLEMENTATION
IMPLEMENT_QUEUE(int)
IMPLEMENT_QUEUE(char)
IMPLEMENT_QUEUE(float)
#endif
