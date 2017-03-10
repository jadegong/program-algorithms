/*
 * ENV: ubuntu 16.04, clang-3.9
 * linked list basic operations.
 */
#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

#define LINK_LIST struct LinkList
#define LEN sizeof(struct LinkList)
#define ELEMET_TYPE int

struct LinkList {
    ELEMET_TYPE val;
    struct LinkList *next;
};

LINK_LIST *InitList();
LINK_LIST *create(int n);
void TracersalList(LINK_LIST *L);
void ClearList(LINK_LIST *L);
ELEMET_TYPE GetElement(LINK_LIST *L, int k);

int main() {
    int n;
    LINK_LIST *l;
    while (printf("Please input list length: ") && scanf("%d", &n) != EOF && n > 0) {
        l = create(n);
        TracersalList(l);
        printf("The 3rd element: %d\n", GetElement(l, 3));
        ClearList(l);
    }
    return 0;
}

// Init
LINK_LIST *InitList() {
    LINK_LIST *l;
    l = (LINK_LIST *)malloc(LEN);
    if (l == NULL) {
        printf("Initialize failed!\n");
        return NULL;
    }
    l->next = NULL;
    return l;
}

// create
LINK_LIST *create(int n) {
    LINK_LIST *head, *tail, *temp; //head头, tail当前尾指针, temp每次新建的指针
    int i;
    printf("Please input values of linked list: ");
    for (i = 0; i < n; i++) {
        temp = (LINK_LIST *)malloc(LEN); //reinitialize temp
        scanf("%d", &temp->val);
        if (i == 0) tail = head = temp; // Init head
        else tail->next = temp;
        temp->next = NULL;
        tail = temp;
    }
    return head;
}

// traversal
void TracersalList(LINK_LIST *L) {
    LINK_LIST *p = L->next;;
    printf("All values: %d", L->val);
    while (p != NULL) {
        printf(" -> %d", p->val);
        p = p->next;
    }
    printf("\n");
}

// clear
void ClearList(LINK_LIST *L) {
    LINK_LIST *pNext;
    if (L == NULL) {
        printf("List is already NULL!\n");
        return;
    }
    while (L->next != NULL) {
        pNext = L->next;
        free(L);
        L = pNext;
    }
    printf("List has been cleared!\n");
}

// get k-th node value, Return INT_MIN if k is invalid
ELEMET_TYPE GetElement(LINK_LIST *L, int k) {
    if (k < 1) {
        printf("The position is invalid!\n");
        return INT_MIN;
    }
    int i = 1;
    LINK_LIST *pNext = L;
    while (pNext != NULL) {
        if (i == k) break;
        pNext = pNext->next;
        i++;
    }
    if (i < k) {
        printf("The position is out of list length!\n");
        return INT_MIN;
    }
    return pNext->val;
}

