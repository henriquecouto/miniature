struct numeros {
    int a;
    int b;
};

program SOMA_PROG {
    version SOMA_VERS {
        int soma(numeros) = 1;
    } = 1;
} = 0x20000001;