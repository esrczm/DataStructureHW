// AD SOYAD : Rukiye Esra Cizmeci
// Öğrenci numarası : 2310205021

//2.ödev: Hanoi Ödevi

#include <stdio.h>

void towerOfHanoi(int a, char from, char to, char aux)
{
    if (a == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from, to);
        return;
    }

    towerOfHanoi(a-1, from, aux, to);
    printf("\n Move disk %d from rod %c to rod %c", a, from, to);
    towerOfHanoi(a-1, aux, to, from);
}

int main()
{
    int a = 5;
    towerOfHanoi(a, 'X', 'Y', 'Z');
    return 0;
}