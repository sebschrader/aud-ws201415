#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Include supplemental functions which are not required by the assignment
// and are too advanced.
#include "e06/readline.h"
#include "a3-supplemental.h"

// maximum length of strings (including trailing \0)
#define MAX_LENGTH 31

// maximum number of contacts
#define MAX_CONTACTS 20

/**
 * Contact data type
 *
 * Holds various bits of information about persons.
 */
typedef struct contact {
    char first_name[MAX_LENGTH];
    char last_name[MAX_LENGTH];
    char zip_code[6];
    char city[MAX_LENGTH];
    char email[MAX_LENGTH];
} contact_t;


/**
 * Tests if contact info is empty.
 *
 * This function is not mandatory, it's just very convenient to stop the
 * output if there are no more contacts.
 */
int isEmpty(struct contact *c) {
    return c->first_name[0] == '\0' && c->last_name[0] == '\0' &&
           c->zip_code[0] == '\0' && c->city[0] == '\0' && c->email[0] == '\0';
}

/**
 * Print the individual components of the contacts array to the console.
 */
void printToConsole(struct contact contacts[]) {
    for (int i = 0; i < MAX_CONTACTS && !isEmpty(contacts + i); i++) {
        printf("First name: %s\n", contacts[i].first_name);
        printf("Last name: %s\n", contacts[i].last_name);
        printf("Zip code: %s\n", contacts[i].zip_code);
        printf("City: %s\n", contacts[i].city);
        printf("Email: %s\n\n", contacts[i].email);
    }
}

/**
 * Write the contents of the contacts array to the persons.csv file.
 */
void writeToFile(struct contact contacts[]) {
    FILE *file = fopen("persons.csv", "w");
    if (file == NULL) {
        perror("Error in fopen() of persons.csv");
        return;
    }
    fprintf(file, "First name;Last name;Zip code;city;Email\n");
    for (int i = 0; i < MAX_CONTACTS && !isEmpty(contacts + i); i++) {
        fprintf(file, "%s;%s;%s;%s;%s\n",
                contacts[i].first_name, contacts[i].last_name,
                contacts[i].zip_code, contacts[i].city, contacts[i].email);
    }
    fclose(file);
}


/**
 * Ask the user for input of a specific attribute.
 *
 * @param prompt Text that prompts the user for input.
 * @param dest
 */
void readAttribute(const char *prompt, char *dest, size_t max_length) {
    // The exemplary solution just did
    // scanf("%s", &dest);
    // here, which works for legal input (<30 non-space characters), but as
    // always, doing it correctly in C requires a lot more code.
    char *line = readline(prompt);
    // Copy string to destination
    strncpy(dest, line, max_length);
    // Ensure that the string is terminated
    dest[max_length - 1] = '\0';
    // Free the temporary buffer
    free(line);
}


int main(void) {
    contact_t contacts[MAX_CONTACTS];
    // Initialize contacts memory to zero
    memset(contacts, 0, sizeof(contacts));
    for (int i = 0; i < MAX_CONTACTS; i++) {
        readAttribute("First name: ", contacts[i].first_name, MAX_LENGTH);
        readAttribute("Last name: ", contacts[i].last_name, MAX_LENGTH);
        readAttribute("Zip code: ", contacts[i].zip_code, 6);
        readAttribute("City: ", contacts[i].city, MAX_LENGTH);
        readAttribute("Email: ", contacts[i].email, MAX_LENGTH);
        // This is not required by the assignment;
        // it only eases playing with this program
        if (!shallContinue()) {
            break;
        }
    }
    printToConsole(contacts);
    return 0;
}

