// AD SOYAD : Rukiye Esra Cizmeci
// Öğrenci numarası : 2310205021 

//7.  Array de ekleme silme işlemleri
#include <stdio.h>

#include <stdio.h>

void push(int arr[], int *n, int pos, int val) {
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*n)++;
}

void pull(int arr[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void view(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int vec[20] = {10, 20, 30, 40, 50};
    int sz = 5;

    view(vec, sz);

    push(vec, &sz, 2, 99);
    view(vec, sz);

    pull(vec, &sz, 3);
    view(vec, sz);

    return 0;
}