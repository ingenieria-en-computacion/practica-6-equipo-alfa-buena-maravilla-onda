#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// ----------------------------
// Macro para declarar estructuras y prototipos
// ----------------------------
#define DECLARE_CQUEUE(TYPE) \
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
    } CQueue_##TYPE; \
    \
    CQueue_##TYPE* cqueue_##TYPE##_create(void); \
    bool cqueue_##TYPE##_enqueue(CQueue_##TYPE* cqueue, TYPE data); \
    bool cqueue_##TYPE##_dequeue(CQueue_##TYPE* cqueue); \
    bool cqueue_##TYPE##_get(const CQueue_##TYPE* cqueue, TYPE* out); \
    size_t cqueue_##TYPE##_length(const CQueue_##TYPE* cqueue); \
    void cqueue_##TYPE##_clear(CQueue_##TYPE* cqueue); \
    void cqueue_##TYPE##_print(const CQueue_##TYPE* cqueue, void (*print_fn)(TYPE)); \
    bool cqueue_##TYPE##_contains(const CQueue_##TYPE* cqueue, TYPE data);

// ----------------------------
// Macro para implementación
// ----------------------------
#define IMPLEMENT_CQUEUE(TYPE) \
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
    CQueue_##TYPE* cqueue_##TYPE##_create(void) { \
        CQueue_##TYPE* cqueue = malloc(sizeof(CQueue_##TYPE)); \
        if (!cqueue) return NULL; \
        cqueue->head = cqueue->tail = NULL; \
        cqueue->length = 0; \
        return cqueue; \
    } \
    \
    void cqueue_##TYPE##_destroy(CQueue_##TYPE* cqueue) { \
        if (!cqueue) return; \
        Node_##TYPE* current = cqueue->head; \
        while (current) { \
            Node_##TYPE* temp = current; \
            current = current->next; \
            free(temp); \
        } \
        free(cqueue); \
    } \
    \
    bool cqueue_##TYPE##_enqueue(CQueue_##TYPE* cqueue, TYPE data) { \
        if (!cqueue) return false; \
        \
        Node_##TYPE* new_node = node_##TYPE##_create(data); \
        if (!new_node) return false; \
        \
        new_node->next = NULL; \
        \
        if(cqueue->length == 0){ \
            cqueue->head = new_node; \
            cqueue->tail = new_node; \
        }else{ \
        cqueue->tail->next = new_node; \
        cqueue->tail = new_node; \
        } \
        cqueue->tail->next = cqueue->head; \
        cqueue->length++; \
        return true; \
    } \
    \
    bool cqueue_##TYPE##_dequeue(CQueue_##TYPE* cqueue) { \
        if (!cqueue || !cqueue->head) return false; \
        \
        Node_##TYPE* to_delete = cqueue->head; \
        \
        cqueue->head = cqueue->head->next; \
        if (!cqueue->head) cqueue->tail = NULL; \
        \
        to_delete->next = NULL; \
        free(to_delete); \
        cqueue->tail->next = cqueue->head; \
        cqueue->length--; \
        return true; \
    } \
    \
    bool cqueue_##TYPE##_get(const CQueue_##TYPE* cqueue, TYPE* out) { \
        if (!cqueue || !out) return false; \
        \
        *out = cqueue->head->data; \
        return true; \
    } \
    \
    size_t cqueue_##TYPE##_length(const CQueue_##TYPE* cqueue) { \
        return cqueue ? cqueue->length : 0; \
    } \
    \
    bool cqueue_##TYPE##_is_empty(const CQueue_##TYPE* cqueue) { \
        return cqueue ? cqueue->length == 0 : true; \
    } \
    \
    void cqueue_##TYPE##_clear(CQueue_##TYPE* cqueue) { \
        int i = 0; \
        if (!cqueue) return; \
        \
        Node_##TYPE* current = cqueue->head; \
        while (current && i < cqueue->length) { \
            Node_##TYPE* temp = current; \
            current = current->next; \
            free(temp); \
            i++; \
        } \
        \
        cqueue->head = cqueue->tail = NULL; \
        cqueue->length = 0; \
    } \
    \
    void cqueue_##TYPE##_print(const CQueue_##TYPE* cqueue, void (*print_fn)(TYPE)) { \
        int i = 0; \
        if (!cqueue || !print_fn) return; \
        \
        printf("["); \
        Node_##TYPE* current = cqueue->head; \
        while (current && i < cqueue->length) { \
            print_fn(current->data); \
            if (current->next && current->next != cqueue->head) printf(", "); \
            current = current->next; \
            i++; \
        } \
        printf("]\n"); \
    } \
    \
    bool cqueue_##TYPE##_contains(const CQueue_##TYPE* cqueue, TYPE data) { \
        if (!cqueue) return false; \
        \
        Node_##TYPE* current = cqueue->head; \
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
DECLARE_CQUEUE(int)
DECLARE_CQUEUE(char)
DECLARE_CQUEUE(float)

// ----------------------------
// Implementación para tipos concretos
// ----------------------------
#ifdef CQUEUE_IMPLEMENTATION
IMPLEMENT_CQUEUE(int)
IMPLEMENT_CQUEUE(char)
IMPLEMENT_CQUEUE(float)
#endif