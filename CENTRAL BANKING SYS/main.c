#include <stdio.h>
#include <unistd.h> // Added for the sleep function

struct BankAccount {
    int accountNumber;
    double balance;
};

void display_balances(struct BankAccount accounts[]) {
    long long phone_number;
    long long account_number1;
    long long account_number2;
    long long account_number3;


        printf("Please enter phone number: ");
        scanf("%lld", &phone_number);

        phone_number = phone_number % 10000000000LL;
        // Replace the last two digits with '4' and '2'
        account_number1 = (phone_number / 100) * 100 + 42;

        printf("Here are the account numbers and respective balances:\n");
        printf("Account number: %lld\n", account_number1);
        printf("Account Balance: %.2f Naira\n", accounts[0].balance);

        account_number2 = (phone_number / 100) * 100 + 53;
        printf("Account number: %lld\n", account_number2);
        printf("Account Balance: %.2f Naira\n", accounts[1].balance);

        account_number3 = (phone_number / 100) * 100 + 48;
        printf("Account number: %lld\n", account_number3);
        printf("Account Balance: %.2f Naira\n", accounts[2].balance);

        printf("\n");

}

void create_acct() {
    int bank_index;
    long long phone_number; // Declare phone_number as long long
    long long account_number1;
    long long account_number2;
    long long account_number3;

    printf("Which bank would you like to choose?\n");
    printf("Press 1 for Wema Bank, 2 for Polaris Bank, and 3 for First Bank\n");

    scanf("%d", &bank_index);

    if (bank_index == 1) {
        printf("Valid bank, please enter phone number: ");
        scanf("%lld", &phone_number);

        // Remove the first digit '0' from the phone number
        phone_number1 = phone_number % 10000000000LL;
        // Replace the last two digits with '4' and '2'
        account_number1 = (phone_number3 / 100) * 100 + 42;
        printf("Account number for Wema Bank is: %lld\n", account_number1);

        phone_number2 = phone_number % 10000000000LL;
        // Replace the last two digits with '5' and '3'
        account_number2 = (phone_number3 / 100) * 100 + 53;
        printf("Account number for Polaris Bank is: %lld\n", account_number2);

        phone_number3 =  phone_number % 10000000000LL;
        // Replace the last two digits with '4' and '8'
        account_number3 = (phone_number3 / 100) * 100 + 48;
        printf("Account number for First Bank is: %lld\n", account_number3);
    } else if (bank_index == 2) {
        printf("Valid bank, please enter phone number: ");
        scanf("%lld", &phone_number);

        // Remove the first digit '0' from the phone number
        phone_number = phone_number % 10000000000LL;

        // Replace the last two digits with '4' and '2'
        account_number1 = (phone_number / 100) * 100 + 42;
        printf("Account number for Polaris Bank is: %lld\n", account_number1);

        // Replace the last two digits with '5' and '3'
        account_number2 = (phone_number / 100) * 100 + 53;
        printf("Account number for Wema Bank is: %lld\n", account_number2);

        // Replace the last two digits with '4' and '8'
        account_number3 = (phone_number / 100) * 100 + 48;
        printf("Account number for First Bank is: %lld\n", account_number3);
    } else if (bank_index == 3) {
        printf("Valid bank, please enter phone number: ");
        scanf("%lld", &phone_number); // Change format specifier from %d to %lld

        // Remove the first digit '0' from the phone number
        phone_number = phone_number % 10000000000LL;

        // Replace the last two digits with '4' and '2'
        account_number1 = (phone_number / 100) * 100 + 42;
        printf("Account number for First Bank is: %lld\n", account_number1);

        // Replace the last two digits with '5' and '3'
        account_number2 = (phone_number / 100) * 100 + 53;
        printf("Account number for Wema Bank is: %lld\n", account_number2);

        // Replace the last two digits with '4' and '8'
        account_number3 = (phone_number / 100) * 100 + 48;
        printf("Account number for Polaris Bank is: %lld\n", account_number3);
    } else {
        printf("Invalid bank. Please choose within the scope of the provided banks.\n");
    }
}

void deposit_money(struct BankAccount accounts[]) {
    int dep_amount;
    int bank_index;

    printf("Which account would you like to deposit money into?\n");
    printf("1. Wema Bank\n");
    printf("2. Polaris Bank\n");
    printf("3. First Bank\n");
    scanf("%d", &bank_index);

    printf("How much would you like to deposit?\n");
    scanf("%d", &dep_amount);

    // Add the deposited amount to the selected account
    accounts[bank_index - 1].balance += dep_amount;

    printf("Depositing money in progress...\n");
    sleep(4);
    printf("Deposited money successfully\n");

    // Display updated balance
    printf("Updated Balance for Account %d: $%.2f\n", bank_index, accounts[bank_index - 1].balance);
}

void withdraw_money(struct BankAccount accounts[]) {
    int wid_amt;
    int bank_index;
    int acct_choice;

    printf("Single withdrawal or split withdrawal?\n");
    printf("Press 1 for single and 2 for split withdrawal\n");
    scanf("%d", &acct_choice);

    if (acct_choice == 1) {
        printf("Which account would you prefer to withdraw from?\n");
        printf("1. Wema Bank\n");
        printf("2. Polaris Bank\n");
        printf("3. First Bank\n");

        scanf("%d", &bank_index);

        printf("How much do you want to withdraw?\n");
        scanf("%d", &wid_amt);

        // Check if there is enough balance for withdrawal
        if (accounts[bank_index - 1].balance >= wid_amt) {
            accounts[bank_index - 1].balance -= wid_amt;
            printf("Withdrawal successful. Remaining balance: $%.2f\n", accounts[bank_index - 1].balance);
        } else {
            printf("Insufficient funds for withdrawal.\n");
        }
    } else {
        // Implement split_acct function or logic
        split_acct(accounts);
    }
}

void split_acct(struct BankAccount accounts[]) {
    int bank_index;
    int curr_balance;

    printf("Press 1 to display your balances in your account\n");
    scanf("%d", &curr_balance);

    // Display balances function implementation
    display_balances(accounts);

    printf("Which accounts would you prefer to withdraw from?\n");
    printf("1. Wema and Polaris\n");
    printf("2. Wema and First Bank\n");
    printf("3. Polaris and First Bank\n");

    scanf("%d", &bank_index);

    // Implement logic for split withdrawal
    int wid_amt1, wid_amt2;
    printf("Enter the amount to withdraw from the first account: ");
    scanf("%d", &wid_amt1);

    printf("Enter the amount to withdraw from the second account: ");
    scanf("%d", &wid_amt2);

    // Check if there is enough balance for withdrawal in both accounts
    if (accounts[0].balance >= wid_amt1 && accounts[1].balance >= wid_amt2) {
        accounts[0].balance -= wid_amt1;
        accounts[1].balance -= wid_amt2;

        printf("Withdrawal successful from both accounts.\n");
        printf("Remaining balance in Wema Bank: $%.2f\n", accounts[0].balance);
        printf("Remaining balance in Polaris Bank: $%.2f\n", accounts[1].balance);
    } else {
        printf("Insufficient funds for withdrawal in one or more accounts.\n");
    }
}

int main() {
    struct BankAccount accounts[3];

    //accounts[0].accountNumber = 1001;
    accounts[0].balance = 1500.0;

    //accounts[1].accountNumber = 1002;
    accounts[1].balance = 2000.0;

    //accounts[2].accountNumber = 1003;
    accounts[2].balance = 2500.0;

    char choice;

    printf("Central Banking System\n");
    printf("What would you like to do?\n");

    printf("a. Create account\n");
    printf("b. Deposit money\n");
    printf("c. Withdraw money\n");

    scanf(" %c", &choice);

    switch (choice) {
        case 'a':
            create_acct();
            break;
        case 'b':
            deposit_money(accounts);
            break;
        case 'c':
            withdraw_money(accounts);
            break;
        default:
            printf("Invalid choice. Please choose a, b, or c.\n");
    }

    return 0;
}
