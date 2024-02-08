#include<stdio.h>
#include<string.h>

typedef struct Account {
    int ac_number;
    char name[50];
    int age;
    float balance;
    int card;
    int pass;
} Account; // Renamed the typedef to 'Account'


void saveCustomer(int *index, Account clint[]) { // Changed the function argument type to 'Account'
    if (*index < 500) { // Check if the array has space to add a new customer

            // Loop to find an empty slot in the array
            for (int i = 0; i < 500; i++) {
            if (clint[i].ac_number == 0) { // Check if the account number is zero (indicating an empty slot)
                printf("\n");
                printf("***** ANDSIM BANK *****\n");
                printf("Enter The Name: ");
                scanf("%49s", clint[i].name);
                printf("Enter The Age: ");
                scanf("%d", &clint[i].age);
                clint[i].ac_number = *index + 1;
                clint[i].card = strlen(clint[i].name) * 4586 * clint[i].age; // Calculate card number
                clint[i].pass = strlen(clint[i].name) * 4586 + clint[i].age; // Calculate password
                clint[i].balance = 0;
                printf("Your Account Created Successfully\n");
                printf("-----------------------------\n");
                printf("Your Account Number is = %d\n", clint[i].ac_number);
                printf("Your Card Number is    = %d\n", clint[i].card);
                printf("Your Password is       = %d\n", clint[i].pass);
                (*index)++;
                break; // Exit the loop after adding the customer
            }
        }
    } else {
        printf("Array is full. Cannot add more entries.\n");
    }
}

void deposit(Account *customer) { // Changed the argument type to 'Account'
    float amount;
    printf("\nEnter the amount to deposit: ");
    scanf("%f", &amount);
    customer->balance += amount;
    printf("Amount deposited successfully. Your new balance is: %.2f\n", customer->balance);
}

void withdrawal(Account *customer) { // Changed the argument type to 'Account'
    float amount;
    printf("\nEnter the amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= customer->balance) { // Check if the amount to withdraw is less than or equal to the balance
        customer->balance -= amount;
        printf("Amount withdrawn successfully. Your new balance is: %.2f\n", customer->balance);
    } else {
        printf("Insufficient balance.\n");
    }
}
int main() {
    Account clint[500] = {0}; // Initialize all account numbers to zero (indicating empty slots)
    int index = 0;
    int op;

    do {
        printf("\n");
        printf("******* ANDSIM BANK ******\n");
        printf("1 - Create Bank Account\n");
        printf("2 - Deposit\n");
        printf("3 - Withdrawal\n");
        printf("4 - Balance Check\n");
        printf("5 - Exit\n");
        printf("Choose The Option (1-5): ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                saveCustomer(&index, clint);
                break;

            case 2:
                if (index > 0) {
                    int accountNumber;
                    int accountCard;
                    int accountPass;
                    printf("\n");
                    printf("===== DEPOSIT =====\n");
                    printf("Enter your account number: ");
                    scanf("%d", &accountNumber);
                    printf("Enter your account card number: ");
                    scanf("%d", &accountCard);
                    printf("Enter your account pass: ");
                    scanf("%d", &accountPass);

                    int i;
                    for (i = 0; i < index; i++) {
                        if (clint[i].ac_number == accountNumber && clint[i].card == accountCard && clint[i].pass == accountPass) {
                            deposit(&clint[i]);
                            break;
                        }
                    }

                    if (i == index) {
                        printf("Account not found.\n");
                    }
                } else {
                    printf("No accounts available. Please create an account first.\n");
                }
                break;

            case 3:
                if (index > 0) {
                    int accountNumber;
                    int accountCard;
                    int accountPass;
                    printf("\n");
                    printf("===== WITHDRAWAL =====\n");
                    printf("Enter your account number: ");
                    scanf("%d", &accountNumber);
                    printf("Enter your account card number: ");
                    scanf("%d", &accountCard);
                    printf("Enter your account pass: ");
                    scanf("%d", &accountPass);

                    int i;
                    for (i = 0; i < index; i++) {
                        if (clint[i].ac_number == accountNumber && clint[i].card == accountCard && clint[i].pass == accountPass) {
                            withdrawal(&clint[i]);
                            break;
                        }
                    }
    if (i == index) {
                        printf("Account not found.\n");
                    }
                } else {
                    printf("No accounts available. Please create an account first.\n");
                }
                break;

            case 4:
                if (index > 0) {
                    int accountNumber;
                    int accountCard;
                    int accountPass;
                    printf("\n");
                    printf("===== BALANCE CHECK =====\n");
                    printf("Enter your account number: ");
                    scanf("%d", &accountNumber);
                    printf("Enter your account card number: ");
                    scanf("%d", &accountCard);
                    printf("Enter your account pass: ");
                    scanf("%d", &accountPass);

                    int i;
                    for (i = 0; i < index; i++) {
                        if (clint[i].ac_number == accountNumber && clint[i].card == accountCard && clint[i].pass == accountPass) {
                            printf("\n");
                            printf("Account Number : %d\n", clint[i].ac_number);
                            printf("Name           : %s\n", clint[i].name);
                            printf("Age            : %d\n", clint[i].age);
                            printf("Balance        : %.2f\n", clint[i].balance);
                            printf("Card Number    : %d\n", clint[i].card);
                            printf("\n");
                            printf("========== THANK YOU =========\n");
                            break;
                        }
                    }

                    if (i == index) {
                        printf("Account not found.\n");
                    }
                } else {
                    printf("No accounts available. Please create an account first.\n");
                }
                break;
        }
    } while (op != 5);

    return 0;
}
