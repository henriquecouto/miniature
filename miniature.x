struct numbers_to_calculate {
    int value1;
    int value2;
};

struct square_root_number {
    int value;
};

struct chat_message {
    char sender_username[30];
    char message[120];
};

struct chat_messages {
    chat_message messages[30];
};

program MINIATURE_PROGRAM {
    version CALCULATOR_VERS {
        int sum(numbers_to_calculate) = 1;
        int subtraction(numbers_to_calculate) = 2;
        int division(numbers_to_calculate) = 3;
        int multiplication(numbers_to_calculate) = 4;
        int square_root(square_root_number) = 5;

        void send_message(chat_message) = 6;
        chat_messages get_messages(int) = 7;
    } = 1;
} = 0x20000001;