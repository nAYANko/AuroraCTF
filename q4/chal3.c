#include <stdio.h>
#include <string.h>

#define MAX_LEN 256
#define WINNING_SCORE 1000
#define ASCII_ART "\
   SSSSSSSSSSSSSSS KKKKKKKKK    KKKKKKKIIIIIIIIIIBBBBBBBBBBBBBBBBB   IIIIIIIIIIDDDDDDDDDDDDD      IIIIIIIIII \n\
 SS:::::::::::::::SK:::::::K    K:::::KI::::::::IB::::::::::::::::B  I::::::::ID::::::::::::DDD   I::::::::I \n\
S:::::SSSSSS::::::SK:::::::K    K:::::KI::::::::IB::::::BBBBBB:::::B I::::::::ID:::::::::::::::DD I::::::::I \n\
S:::::S     SSSSSSSK:::::::K   K::::::KII::::::IIBB:::::B     B:::::BII::::::IIDDD:::::DDDDD:::::DII::::::II \n\
S:::::S            KK::::::K  K:::::KKK  I::::I    B::::B     B:::::B  I::::I    D:::::D    D:::::D I::::I   \n\
S:::::S              K:::::K K:::::K     I::::I    B::::B     B:::::B  I::::I    D:::::D     D:::::DI::::I   \n\
 S::::SSSS           K::::::K:::::K      I::::I    B::::BBBBBB:::::B   I::::I    D:::::D     D:::::DI::::I   \n\
  SS::::::SSSSS      K:::::::::::K       I::::I    B:::::::::::::BB    I::::I    D:::::D     D:::::DI::::I   \n\
    SSS::::::::SS    K:::::::::::K       I::::I    B::::BBBBBB:::::B   I::::I    D:::::D     D:::::DI::::I   \n\
       SSSSSS::::S   K::::::K:::::K      I::::I    B::::B     B:::::B  I::::I    D:::::D     D:::::DI::::I   \n\
            S:::::S  K:::::K K:::::K     I::::I    B::::B     B:::::B  I::::I    D:::::D     D:::::DI::::I   \n\
            S:::::SKK::::::K  K:::::KKK  I::::I    B::::B     B:::::B  I::::I    D:::::D    D:::::D I::::I   \n\
SSSSSSS     S:::::SK:::::::K   K::::::KII::::::IIBB:::::BBBBBB::::::BII::::::IIDDD:::::DDDDD:::::DII::::::II \n\
S::::::SSSSSS:::::SK:::::::K    K:::::KI::::::::IB:::::::::::::::::B I::::::::ID:::::::::::::::DD I::::::::I \n\
S:::::::::::::::SS K:::::::K    K:::::KI::::::::IB::::::::::::::::B  I::::::::ID::::::::::::DDD   I::::::::I \n\
 SSSSSSSSSSSSSSS   KKKKKKKKK    KKKKKKKIIIIIIIIIIBBBBBBBBBBBBBBBBB   IIIIIIIIIIDDDDDDDDDDDDD      IIIIIIIIII\n"

char plaintext[MAX_LEN], user_ciphertext[MAX_LEN], correct_ciphertext[MAX_LEN];
int key_pattern[] = {-1, -2, 17, 24, 3, 1, 9};
int pattern_length = 7, score = 0, correct_attempts = 0;

// Helper function to calculate key from a word
void calculate_key_from_word(const char *word, int *key_pattern, int *pattern_length) {
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            key_pattern[i] = word[i] - 'a' + 1;
        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            key_pattern[i] = word[i] - 'A' + 1;
        }
    }
    *pattern_length = i; // Update pattern length
}

// Encrypt the plaintext using position-specific shifts
void encrypt_text(const char *plaintext, char *ciphertext, const int *key_pattern, int pattern_length) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        int current_key = key_pattern[i % pattern_length]; // Get shift for this position
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = ((plaintext[i] - 'a' + current_key) % 26 + 26) % 26 + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = ((plaintext[i] - 'A' + current_key) % 26 + 26) % 26 + 'A';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

void shift_key_pattern() {
    for (int i = 0; i < pattern_length; i++) {
        key_pattern[i] = (key_pattern[i] + 1) % 26;  // Shift each key and wrap around
    }
}


int main() {

    printf("%s\n", ASCII_ART);
    printf("Welcome to the SKIBIDI Cipher Challenge!\n");
    printf("Rules: Enter pairs of plaintext and ciphertext. Score 1000 to win!\n");

    while (score < WINNING_SCORE) {
        printf("\nCurrent Score: %d\n", score);
        printf("Enter plaintext: ");
        scanf("%s", plaintext);
        printf("Enter ciphertext: ");
        scanf("%s", user_ciphertext);

        // Encrypt the plaintext using the position-specific shifts
        encrypt_text(plaintext, correct_ciphertext, key_pattern, pattern_length);

        // Check if the user-provided ciphertext matches
        if (strcmp(user_ciphertext, correct_ciphertext) == 0) {
            printf("Correct!\n");
            score++;
            correct_attempts++;
            shift_key_pattern();
        } else {
            printf("Incorrect! The correct ciphertext was: %s\n", correct_ciphertext);
            printf("Score reset to 0. Try again!\n");
            score = 0;
            correct_attempts = 0;
            continue;
        }

        // Update the key pattern after specific attempts
        if (correct_attempts % 2 == 0 && correct_attempts % 100 != 0) {
            calculate_key_from_word("skibidi", key_pattern, &pattern_length);
        } else if (correct_attempts % 100 == 0) {
            calculate_key_from_word("alpha", key_pattern, &pattern_length);
        }


        // Check for winning condition
        if (score >= WINNING_SCORE) {
            printf("\nCongratulations! You've won the challenge!\n");
            printf("The flag is: actf{th3_sk1b1d1_l0rd_a5k5_4_f4num_t4x}\n");
            break;
        }
    }

    return 0;
}
