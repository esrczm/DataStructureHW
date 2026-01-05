// AD SOYAD : Rukiye Esra Cizmeci
// Öğrenci numarası : 2310205021

// 3. ödev: Shunting Yard algoritması ile infix ifade postfix’e cevirme.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int check_precedence(char op) {
    if (op == '^') {
        return 3;
    }
    else if (op == '/' || op == '*') {
        return 2;
    }
    else if (op == '+' || op == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

int is_right_to_left(char op) {
    return op == '^';
}

void process_shunting_yard(char* input_stream) {
    int str_size = strlen(input_stream);
    char postfix_result[str_size + 1];
    char op_buffer[str_size];
    int res_idx = 0;
    int buffer_ptr = -1;

    for (int k = 0; k < str_size; k++) {
        char symbol = input_stream[k];

        if (isalnum(symbol)) {
            postfix_result[res_idx++] = symbol;
        }
        else if (symbol == '(') {
            op_buffer[++buffer_ptr] = '(';
        }
        else if (symbol == ')') {
            while (buffer_ptr != -1 && op_buffer[buffer_ptr] != '(') {
                postfix_result[res_idx++] = op_buffer[buffer_ptr--];
            }
            buffer_ptr--; 
        }
        else {
            while (buffer_ptr != -1 && op_buffer[buffer_ptr] != '(' &&
                  (check_precedence(op_buffer[buffer_ptr]) > check_precedence(symbol) ||
                  (check_precedence(op_buffer[buffer_ptr]) == check_precedence(symbol) && !is_right_to_left(symbol)))) {
                postfix_result[res_idx++] = op_buffer[buffer_ptr--];
            }
            op_buffer[++buffer_ptr] = symbol;
        }
    }

    while (buffer_ptr != -1) {
        postfix_result[res_idx++] = op_buffer[buffer_ptr--];
    }

    postfix_result[res_idx] = '\0';
    printf("Result: %s\n", postfix_result);
}

int main() {
    char sample_infix[] = "a*(b+c)/d";
    process_shunting_yard(sample_infix); 
    return 0;
}