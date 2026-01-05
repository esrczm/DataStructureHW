// AD SOYAD : Rukiye Esra Cizmeci
// Öğrenci numarası : 2310205021

//10. ödev : Tree creation using array.
#include <stdio.h>

char t[50];

void init() {
    for (int i = 0; i < 50; i++) {
        t[i] = '-';
    }
}

void add_root(char v) {
    t[0] = v;
}

void add_l(char v, int p) {
    int idx = (p * 2) + 1;
    if (t[p] == '-') {
        printf("Parent error at %d\n", p);
    } else {
        t[idx] = v;
    }
}

void add_r(char v, int p) {
    int idx = (p * 2) + 2;
    if (t[p] == '-') {
        printf("Parent error at %d\n", p);
    } else {
        t[idx] = v;
    }
}

void out(int n) {
    for (int i = 0; i < n; i++) {
        if (t[i] != '-') {
            printf("%c ", t[i]);
        } else {
            printf(". ");
        }
    }
    printf("\n");
}

int main() {
    init();
    
    add_root('A');
    add_l('B', 0);
    add_r('C', 0);
    add_l('D', 1);
    add_r('E', 1);
    add_r('F', 2);

    out(10);

    return 0;
}