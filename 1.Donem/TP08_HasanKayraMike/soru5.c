#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    for (int i = 0, n = argc; i < n; i++)
    {
        if (strcmp(argv[i], "C") == 0)
        {
            printf("C ile Programlamaya Giris ne kadar da guzel bir ders!\n");
            return 0;
        }
    }
    printf("Bana C ile ilgili soylemek istedigin hic mi bir sey yok?\n");
    return 1;
}