struct numbers_to_calculate {
    int value1;
    int value2;
};

struct square_root_number {
    int value;
};

program MINIATURE_PROGRAM {
    version CALCULATOR_VERS {
        int sum(numbers_to_calculate) = 1;
        int subtraction(numbers_to_calculate) = 2;
        int division(numbers_to_calculate) = 3;
        int multiplication(numbers_to_calculate) = 4;
        int square_root(square_root_number) = 5;
    } = 1;
} = 0x20000001;