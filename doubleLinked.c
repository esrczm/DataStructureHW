// AD SOYAD : Rukiye Esra Cizmeci
// Öğrenci numarası : 2310205021

//5. ödev: Double Linked
// list silme kodu, araya ekleme, traversal

#include <stdio.h>
#include <stdlib.h>

typedef struct Unit {
    int content;
    struct Unit* after;
    struct Unit* before;
} Unit;

Unit* init_unit(int val) {
    Unit* obj = (Unit*)malloc(sizeof(Unit));
    obj->content = val;
    obj->after = NULL;
    obj->before = NULL;
    return obj;
}

void add_to_front(Unit** start, int val) {
    Unit* obj = init_unit(val);

    if (*start == NULL) {
        *start = obj;
        return;
    }
    obj->after = *start;
    (*start)->before = obj;
    *start = obj;
}

void add_to_back(Unit** start, int val) {
    Unit* obj = init_unit(val);

    if (*start == NULL) {
        *start = obj;
        return;
    }

    Unit* walker = *start;
    while (walker->after != NULL) {
        walker = walker->after;
    }
    walker->after = obj;
    obj->before = walker;
}

void add_at_index(Unit** start, int val, int idx) {
    if (idx < 1) {
        printf("Index error.\n");
        return;
    }

    if (idx == 1) {
        add_to_front(start, val);
        return;
    }
    Unit* obj = init_unit(val);
    Unit* walker = *start;
    for (int k = 1; walker != NULL && k < idx - 1; k++) {
        walker = walker->after;
    }
    if (walker == NULL) {
        printf("Index out of bounds.\n");
        return;
    }
    obj->after = walker->after;
    obj->before = walker;
    if (walker->after != NULL) {
        walker->after->before = obj;
    }
    walker->after = obj;
}

void remove_front(Unit** start) {
    if (*start == NULL) return;
    Unit* ptr = *start;
    *start = (*start)->after;
    if (*start != NULL) {
        (*start)->before = NULL;
    }
    free(ptr);
}

void remove_back(Unit** start) {
    if (*start == NULL) return;

    Unit* ptr = *start;
    if (ptr->after == NULL) {
        *start = NULL;
        free(ptr);
        return;
    }
    while (ptr->after != NULL) {
        ptr = ptr->after;
    }
    ptr->before->after = NULL;
    free(ptr);
}

void remove_at_index(Unit** start, int idx) {
    if (*start == NULL) return;
    Unit* ptr = *start;
    if (idx == 1) {
        remove_front(start);
        return;
    }
    for (int k = 1; ptr != NULL && k < idx; k++) {
        ptr = ptr->after;
    }
    if (ptr == NULL) return;
    
    if (ptr->after != NULL) {
        ptr->after->before = ptr->before;
    }
    if (ptr->before != NULL) {
        ptr->before->after = ptr->after;
    }
    free(ptr);
}

void display_forward(Unit* start) {
    Unit* ptr = start;
    printf("Forward: ");
    while (ptr != NULL) {
        printf("%d ", ptr->content);
        ptr = ptr->after;
    }
    printf("\n");
}

void display_backward(Unit* start) {
    Unit* ptr = start;
    if (ptr == NULL) return;
    while (ptr->after != NULL) {
        ptr = ptr->after;
    }
    printf("Backward: ");
    while (ptr != NULL) {
        printf("%d ", ptr->content);
        ptr = ptr->before;
    }
    printf("\n");
}

int main() {
    Unit* root = NULL;

    add_to_back(&root, 10);
    add_to_back(&root, 20);
    add_to_front(&root, 5);
    add_at_index(&root, 15, 2);

    display_forward(root);
    display_backward(root);

    remove_front(&root);
    remove_back(&root);
    remove_at_index(&root, 2);

    display_forward(root);

    return 0;
}