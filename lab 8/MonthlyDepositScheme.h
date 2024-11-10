#ifndef MonthlyDepositScheme_H
#define MonthlyDepositScheme_H
#include "account.h"

class MDS: protected account{
    private:
        static int nextAccount;

        /// @brief function for accessing the next account number, returns the next account number as a string and then increments it
        /// @return the next account number
        string nextAccountNo();
    
    public:

        void getvals(string& accnum, float& bal);
        void setVals(string& accname, float& bal);
};

#endif // MonthlyDepositScheme_H
