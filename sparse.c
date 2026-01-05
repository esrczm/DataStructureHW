// AD SOYAD : Rukiye Esra Cizmeci
// Öğrenci numarası : 2310205021

//1.ödev: Sparse matrix dönüşümü

#include <stdio.h>
#include <stdlib.h>

int main() {
    int limit_r, limit_c, r, c;
    int source_data[15][15];
    int zero_tally = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &limit_r);
    printf("Enter the number of columns: ");
    scanf("%d", &limit_c);

    printf("Please input the matrix elements:\n");
    for(r = 0; r < limit_r; r++) {
        for(c = 0; c < limit_c; c++) {
            scanf("%d", &source_data[r][c]);
        }
    }

    printf("\nOriginal Matrix View:\n");
    for(r = 0; r < limit_r; r++) {
        for(c = 0; c < limit_c; c++) {
            printf("%d\t", source_data[r][c]);
        }
        printf("\n");
    }

    for(r = 0; r < limit_r; r++) {
        for(c = 0; c < limit_c; c++) {
            if(source_data[r][c] == 0) {
                zero_tally++;
            }
        }
    }

    if(zero_tally > ((limit_r * limit_c) / 2)) {
        printf("\nStatus: This is a sparse matrix.\n");

        int stored_items = (limit_r * limit_c) - zero_tally;
        int triplet_map[stored_items][3];
        int ptr = 0;

        for(r = 0; r < limit_r; r++) {
            for(c = 0; c < limit_c; c++) {
                if(source_data[r][c] != 0) {
                    triplet_map[ptr][0] = r;
                    triplet_map[ptr][1] = c;
                    triplet_map[ptr][2] = source_data[r][c];
                    ptr++;
                }
            }
        }

        printf("\nTriplet Representation:\n");
        printf("Row\tCol\tValue\n");
        for(r = 0; r < stored_items; r++) {
            printf("%d\t%d\t%d\n", triplet_map[r][0], triplet_map[r][1], triplet_map[r][2]);
        }
    } else {
        printf("\nStatus: This is not a sparse matrix.\n");
    }

    return 0;
}