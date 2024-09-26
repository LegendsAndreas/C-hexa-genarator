// https://craftofcoding.wordpress.com/2020/01/21/converting-characters-to-hexadecimal/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HEXA_SIZE 16

/**
 * @brief Converts a given string into its hexadecimal representation.
 *
 * This function takes a null-terminated string and converts each character
 * to its two-digit hexadecimal equivalent. It allocates memory for the
 * resulting hexadecimal string, which the caller is responsible for freeing.
 *
 * @param str The input string to be converted.
 * @return A pointer to the hexadecimal string, or nullptr if memory allocation fails.
 *
 * @warning The caller is responsible for freeing the allocated memory for the returned string.
 */
char* convertStrToHex(const char *str) {
    // All our hexadecimal characters, which will be selected appropriately in the loop.
    const char *hexadecimals = "0123456789abcdef";

    // Gets the length of the actual characters in use, as opposed to "sizeof", times 2, since the hexadecimal
    // equivalent is twice as long.
    unsigned int hexaSize = strlen(str) * 2;
    // printf("Size =%d\n", hexaSize);
    // Plus 1 for null-boy (absolute beast).
    char *hexaStr = (char *)malloc(hexaSize+1);

    // Checks if malloc failed.
    if (hexaStr == NULL) {
        printf("Memory allocation failed");
        return nullptr;
    }

    unsigned int i = 0;
    while (i < strlen(str)) {
        uint8_t asciiValue = (uint8_t)str[i];     // We get the ASCII value for the current letter of the string.
        uint8_t hexNum1 = asciiValue / HEXA_SIZE; // We get our first hexadecimal by dividing the ASCII value by 16.
        uint8_t hexNum2 = asciiValue % HEXA_SIZE; // Then we get the second hexadecimal by getting the remainder og the ASCII value.

        // Adds the appropriate character to "hexaStr".
        hexaStr[0+(i*2)] = hexadecimals[hexNum1];
        hexaStr[1+(i*2)] = hexadecimals[hexNum2];
        i++;

        if (i > 1000) {
            printf("Okay, we are missing a null character.");
            break;
        }
    }

    // Null-terminate the string
    hexaStr[i * 2] = '\0';
    return hexaStr;
}
/*
int main() {
    printf("%s", convertStrToHex("This post was fact checked by REAL surgeons."));
}*/

/*
int main(int argc, char *argv[]) {
    // Check if an argument is passed
    if (argc < 2) {
        printf("Usage: %s <argument>\n", argv[0]);
        return 1; // Return an error code
    }

    // Print the first argument
    printf("Argument provided: %s\n", argv[1]);

    char *hexStr = convertStrToHex(argv[1]);
    printf("%s", hexStr);

    free(hexStr);

    return 0;
}*/
