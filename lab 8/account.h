#ifndef account_H
#define account_H

#include "includes.h"
class account{
    private:
        string accountNo;
        string accountName;
        float  balance;

    public:



        /// @brief 2 arguemnt setter of account base class
        /// @param str the account number
        /// @param name the name of the accout holder
        void accInit(string str, string name);
        
        /// @brief 1 argument setter of accoutn base class
        /// @param str the account number
        void accInit(string str);

        /// @brief function to get the details of an account
        /// @param acc account number
        /// @param name name of the account holder
        /// @param bal balance of the account
        void getter(string &acc, string &name, float &bal);

        /// @brief function to update the account name and the balance
        /// @param name 
        /// @param bal 
        void update(string& name, float& bal);

        /// @brief function to add  more money
        /// @param n amount of money
        void deposit(float n);

        /// @brief function to remove money
        /// @param n amount of money 
        void withdraw(float n);

        // END_OF_PUBLIC
};

#endif // account_H
