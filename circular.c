// AD SOYAD : Rukiye Esra Cizmeci
// Öğrenci numarası : 2310205021

//6. ödev : Çembersel Linked list silme kodu, araya ekleme, traversal
#include <stdio.h>
#include <stdlib.h>

struct RingUnit {
    int val;
    struct RingUnit* link;
};

struct RingUnit* build_unit(int val) {
    struct RingUnit* obj = (struct RingUnit*)malloc(sizeof(struct RingUnit));
    obj->val = val;
    obj->link = NULL;
    return obj;
}

void prepend_item(struct RingUnit** root, int val) {
    struct RingUnit* obj = build_unit(val);
    if (*root == NULL) {
        *root = obj;
        obj->link = *root;
    }
    else {
        struct RingUnit* runner = *root;
        while (runner->link != *root) {
            runner = runner->link;
        }
        runner->link = obj;
        obj->link = *root;
        *root = obj;
    }
}

void append_item(struct RingUnit** root, int val) {
    struct RingUnit* obj = build_unit(val);
    if (*root == NULL) {
        *root = obj;
        obj->link = *root;
    }
    else {
        struct RingUnit* runner = *root;
        while (runner->link != *root) {
            runner = runner->link;
        }
        runner->link = obj;
        obj->link = *root;
    }
}

void inject_at_pos(struct RingUnit** root, int val, int idx) {
    struct RingUnit* obj = build_unit(val);
    if (*root == NULL && idx == 0) {
        *root = obj;
        obj->link = *root;
    }
    else if (idx == 0) {
        prepend_item(root, val);
    }
    else {
        struct RingUnit* runner = *root;
        int k = 0;
        while (k < idx - 1) {
            runner = runner->link;
            k++;
        }
        obj->link = runner->link;
        runner->link = obj;
    }
}

void drop_start(struct RingUnit** root) {
    if (*root == NULL) return;
    
    if ((*root)->link == *root) {
        free(*root);
        *root = NULL;
    }
    else {
        struct RingUnit* runner = *root;
        while (runner->link != *root) {
            runner = runner->link;
        }
        runner->link = (*root)->link;
        struct RingUnit* old_head = *root;
        *root = (*root)->link;
        free(old_head);
    }
}

void drop_tail(struct RingUnit** root) {
    if (*root == NULL) return;

    if ((*root)->link == *root) {
        free(*root);
        *root = NULL;
    }
    else {
        struct RingUnit* pre_last = *root;
        while (pre_last->link->link != *root) {
            pre_last = pre_last->link;
        }
        struct RingUnit* last_node = pre_last->link;
        pre_last->link = *root;
        free(last_node);
    }
}

void drop_at_pos(struct RingUnit** root, int idx) {
    if (*root == NULL) return;

    if (idx == 0) {
        drop_start(root);
    }
    else {
        struct RingUnit* runner = *root;
        int k = 0;
        while (k < idx - 1) {
            runner = runner->link;
            k++;
        }
        struct RingUnit* target = runner->link;
        runner->link = runner->link->link;
        free(target);
    }
}

void walk_circle(struct RingUnit* root) {
    if (root == NULL) return;
    struct RingUnit* runner = root;
    do {
        printf("%d -> ", runner->val);
        runner = runner->link;
    } while (runner != root);
    printf("(LOOP)\n");
}

int locate_val(struct RingUnit* root, int key) {
    if (root == NULL) return 0;
    struct RingUnit* runner = root;
    do {
        if (runner->val == key) return 1;
        runner = runner->link;
    } while (runner != root);
    return 0;
}

int main() {
    struct RingUnit* head_ptr = NULL;

    append_item(&head_ptr, 10);
    append_item(&head_ptr, 20);
    prepend_item(&head_ptr, 5);
    inject_at_pos(&head_ptr, 15, 2);

    printf("Circle State: ");
    walk_circle(head_ptr);

    drop_tail(&head_ptr);
    drop_at_pos(&head_ptr, 1);

    printf("After Removal: ");
    walk_circle(head_ptr);

    int target_val = 10;
    if (locate_val(head_ptr, target_val)) {
        printf("Value %d found.\n", target_val);
    } else {
        printf("Value %d not found.\n", target_val);
    }

    return 0;
}