#include <stdio.h>
#include <math.h>
int main() {
    FILE *inputFile = fopen("input.bin", "rb"); 
    
    unsigned char bytes[4];
    fread(bytes, sizeof(unsigned char), 4, inputFile);

    fclose(inputFile); 

    int N;
    if (bytes[0] < bytes[3]) {
        printf("Big-endian\n");
    } else {
        printf("Little-endian\n");
    }
    N=bytes[3]+(bytes[2]<<8)+(bytes[1]<<16)+(bytes[0]<<24);
    printf(" %d",bytes[3]);

    return 0;
}
