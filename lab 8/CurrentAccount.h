#ifndef CurrentAccount_H
#define CurrentAccount_H
#include "account.h"

class CurrentAccount: public account{
    private:
        const static string accountPrefix;

        float interestRate;
        int monthlyDepositAmount;
        static int nextAccount;

        
        string nextAccountNo();

    public:
        CurrentAccount();

        void setVals(string &accname, int &Mamount, float &rate, float &inival);

        /// @brief function to get the details of the function
        /// @param accnum the account number
        /// @param name name of the account holder
        /// @param bal balance of the account
        /// @param rate interest rate
        /// @param Mdeposit monthly deposit amount
        void getvals(string &accnum, string &name, float &bal, float &rate, int &Mdeposit);

        /// @brief function to deposit amout
        /// @param n the money amout
        void deposit(float n);

    //END OF PUBLIC
};
#endif // CurrentAccount_H
