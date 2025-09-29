#include <stdio.h>

unsigned int utoa(
    unsigned int number,
    char *buf,
    unsigned int bufsz,
    unsigned int base,
    const char *digits
);

int main() {

    char output_buffer[33]; // Buffer to hold the converted string (32 digits + null terminator)
    const char *vigesimal_digits = "0123456789ABCDEFGHIJ";
    // unsigned int number = 50; // Example number to convert
    // unsigned int base = 20; // Vigesimal base

    // unsigned int result = utoa(number, output_buffer, sizeof(output_buffer), base, vigesimal_digits);
    // if (result > 0) {
    //     printf("Conversion successful: %s\n", output_buffer);

    // } else {
    //     printf("Conversion failed!\n");
    // }
    for (unsigned int number = 0; number <= 100; number++) {
        unsigned int result = utoa(number, output_buffer, sizeof(output_buffer), 20, vigesimal_digits);
        if (result > 0) {
            printf("Number: %3u in base 20 is: %s\n", number, output_buffer);
        } else {
            printf("Conversion failed for number: %u\n", number);
        }
    }


}

/**
 * Converts a given unsigned int number to string for the given base.
 *
 * @note requires (1) bufsz > 1 and (2) base > 1.
 * @note appends NUL character at the end of the output.
 * @note writes buf[0] = 0 in case of failure.
 *
 * @return int 0 in case of overflow or invalid argument, or number of
 * written characters in case of success. (excluding NUL)
 */
unsigned int utoa(
    /** number to convert */
    unsigned int number,
    
    /** output buffer */
    char *buf,
    
    /** size of the output buffer */
    unsigned int bufsz,
    
    /** base (also the length of digits) */
    unsigned int base,
    
    /** digits in the base */
    const char *digits
){
    // Validate input parameters
    if (buf == NULL || digits == NULL || bufsz <= 1 || base <= 1) {
        if (buf && bufsz > 0) { // defensive check
            buf[0] = 0;
        }
        return 0;
    }


    // Special case for zero
    if (number == 0) {
        if (bufsz < 2) { // defensive check for place to write '\0'
            buf[0] = 0;
            return 0;
        }
        buf[0] = digits[0];
        buf[1] = '\0';
        return 1;
    }

    // temporary buffer to hold digits in reverse order
    char temp[33]; // enough for base 2 representation of 32-bit unsigned
    int temp_index = 0;

    int quotient = number;

    for (temp_index = 0; temp_index < 32; temp_index++){
        temp[temp_index] = digits[quotient % base];
        quotient /= base;

        if (quotient == 0) { // not < 0!!!
            temp_index++; // move to next index for correct count!!!!
            break;
        }
    }

    // while (quotient > 0 && temp_index < 32) {  // ✅ 改用 while 循环
    //     temp[temp_index] = digits[quotient % base];
    //     temp_index++;  // ✅ 先存储，再递增
    //     quotient /= base;
    // }

    // Check if the output buffer is large enough
    if (bufsz < temp_index + 1) {  // +1 for '\0'
        buf[0] = 0;
        return 0;
    }

    // Reverse the order of digits to get the correct representation
    
    // for (int i = temp_index; i >= 0; i--) {
    //     buf[temp_index - i] = temp[i];
    // }
    // buf[temp_index + 1] = '\0'; 

    // return temp_index + 1; // number of characters written (excluding '\0')

    for (int i = 0; i < temp_index; i++) { // ??? Why mine is wrong?
        buf[i] = temp[temp_index - 1 - i];
    }

    buf[temp_index] = '\0'; 
    return temp_index;

}
