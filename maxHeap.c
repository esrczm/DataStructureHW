// AD SOYAD : Rukiye Esra Cizmeci
// Öğrenci numarası : 2310205021

//4. ödev:  Max Heap Kodu
#include <stdio.h>
#include <stdlib.h>

struct MaxHeapTree {
    int* store;
    int len;
    int limit;
};

typedef struct MaxHeapTree heap_tree;

void bubble_down(heap_tree* h, int idx) {
    int left_node = idx * 2 + 1;
    int right_node = idx * 2 + 2;
    int pivot = idx;

    if (left_node < h->len && left_node >= 0) {
        if (h->store[left_node] > h->store[pivot])
            pivot = left_node;
    }
    
    if (right_node < h->len && right_node >= 0) {
        if (h->store[right_node] > h->store[pivot])
            pivot = right_node;
    }

    if (pivot != idx) {
        int swap_val = h->store[pivot];
        h->store[pivot] = h->store[idx];
        h->store[idx] = swap_val;
        bubble_down(h, pivot);
    }
}

void bubble_up(heap_tree* h, int idx) {
    int p_idx = (idx - 1) / 2;

    if (h->store[p_idx] < h->store[idx]) {
        int swap_val = h->store[p_idx];
        h->store[p_idx] = h->store[idx];
        h->store[idx] = swap_val;
        bubble_up(h, p_idx);
    }
}

heap_tree* init_max_heap(int max_cap, int* initial_data) {
    heap_tree* h = (heap_tree*)malloc(sizeof(heap_tree));
    if (h == NULL) return NULL;

    h->len = 0;
    h->limit = max_cap;
    h->store = (int*)malloc(max_cap * sizeof(int));
    if (h->store == NULL) return NULL;

    int counter;
    for (counter = 0; counter < max_cap; counter++) {
        h->store[counter] = initial_data[counter];
    }

    h->len = counter;
    int start_node = (h->len - 2) / 2;
    while (start_node >= 0) {
        bubble_down(h, start_node);
        start_node--;
    }
    return h;
}

int pop_maximum(heap_tree* h) {
    int top_val;
    if (h->len == 0) return -1;

    top_val = h->store[0];
    h->store[0] = h->store[h->len - 1];
    h->len--;

    bubble_down(h, 0);
    return top_val;
}

void push_item(heap_tree* h, int val) {
    if (h->len < h->limit) {
        h->store[h->len] = val;
        bubble_up(h, h->len);
        h->len++;
    }
}

void display_content(heap_tree* h) {
    for (int i = 0; i < h->len; i++) {
        printf("%d ", h->store[i]);
    }
    printf("\n");
}

int main() {
    int source[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    heap_tree* my_hp = init_max_heap(9, source);

    display_content(my_hp);
    pop_maximum(my_hp);
    display_content(my_hp);

    return 0;
}