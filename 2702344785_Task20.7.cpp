#include<stdio.h>

union HexConvert{
    unsigned int value;
    unsigned char bytes[4];
};

int main(){
    union HexConvert data;
    printf("Masukkan bilangan unsigned int: ");
    scanf("%u", &data.value);

    printf("Hex: 0x%02X%02X%02X%02X\n",
           data.bytes[3], data.bytes[2], data.bytes[1], data.bytes[0]);

    return 0;
}

