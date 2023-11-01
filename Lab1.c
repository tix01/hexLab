#include <stdio.h>
#include <math.h>
int main() {
    FILE *inputFile = fopen("input.bin", "rb"); 
    
    unsigned char bytes[8];
    fread(bytes, sizeof(unsigned char), 8, inputFile);

    fclose(inputFile); 

    int A, B;
    A = bytes[0] + (bytes[1] << 8) + (bytes[2] << 16) + (bytes[3] << 24);
    B = bytes[4] + (bytes[5] << 8) + (bytes[6] << 16) + (bytes[7] << 24);

    int halfSum = (int)floor((A + B) / 2.0);
    printf("%d\n",halfSum);
    FILE *outputFile = fopen("output.bin", "wb");  

    unsigned char resultBytes[4];
    resultBytes[0] = halfSum & 0xFF;
    resultBytes[1] = (halfSum >> 8) & 0xFF;
    resultBytes[2] = (halfSum >> 16) & 0xFF;
    resultBytes[3] = (halfSum >> 24) & 0xFF;

    fwrite(resultBytes, sizeof(unsigned char), 4, outputFile);

    fclose(outputFile); 

    return 0;
}
