#ifndef LoanAccount_H
#define LoanAccount_H
#include "account.h"

class LoanAccount: protected account{
    private:
        static int nextAccount;

        
        string nextAccountNo();
    
    public:

        void getvals(string& accnum, float& bal);
        void setVals(string& accname, float& bal);

    //END OF PUBLIC
}

#endif // LoanAccount_H
