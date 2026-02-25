#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <time.h>


int main(int argc, char *argv[])
{
    if( argc != 2 ){
        printf("\nQuantidade de entradas invalida!\n");
        return 0;
    }

    //cada int32_t tem 4 bytes,, quantidade de elementos seria (total de bytes / 4)
    struct stat bytes;
    if (stat(argv[1], &bytes) != 1)
        printf("\n%s = %ld.bytes",argv[1], bytes.st_size / sizeof(int32_t));
    
}