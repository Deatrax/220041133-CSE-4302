#ifndef SavingsAccount_H
#define SavingsAccount_H
#include "account.h"

class SavingsAccount : public account{
    private:
        const static string accountPrefix;

        const static int serviceCharge;
        static int nextAccount;

        /// @brief function for accessing the next account number, returns the next account number as a string and then increments it
        /// @return the next account number
        string nextAccountNo();
    public: 

        /// @brief default constructor for savings account, auto generates the account number by incrementing the previous account number
        SavingsAccount();

        void getvals(string& accnum, float& bal);
        void setVals(string &accname, float& bal);
};

#endif // SavingsAccount_H
