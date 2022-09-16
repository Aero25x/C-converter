
// convert hex to unsigned char decimal
unsigned char div10(unsigned char *hex, unsigned size)
{
    unsigned rem = 0;
    for(int i = 0; i < size; i++)
    {
        unsigned n = rem * 256 + hex[i];
        hex[i] = n / 10;
        rem = n % 10;
    }
    return rem;
}


unsigned char hex_to_dec_summer(char *local){
    unsigned char result[32]={0};
    unsigned char output[18]={};

    char input[64];
    strcpy(input, local);

    unsigned char hexnr[sizeof(input)/2]={}; 
    for (int i=0; i<sizeof(input)/2; i++) {
        sscanf(&input[i*2], "%02xd", &hexnr[i]);
    }
    
    
    unsigned char hexzero[32] = {0};
    unsigned i = 0;
    while(memcmp(hexnr, hexzero, sizeof(hexnr)) != 0 && i < sizeof(result))
    {
        result[sizeof(result) - i - 1] = div10(hexnr, sizeof(hexnr));
        i++;
    }
    printf("\n");

    for(unsigned j = 0; j < sizeof output; j++)
    {
        output[j]=result[j];
        printf("%d", output[j]);
    }
    output[18]='\0';
}
