#include <iostream>
#include <map>
#include <string>

#define nl "\n"
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));

typedef long long ll;
using namespace std;

class BankAccount {

    private:
        int acNum;
        string holder;
        bool ac_type;  // Changed the name to 'ac_type' to avoid confusion with 'type' keyword.
        double bal;
        const double minBal = 200;
        static double taxCol;

    public:
        BankAccount(): bal(0), acNum(0) {}

        BankAccount(int ac, string& holdr, string typ, double balnc)
            : acNum(ac),
            holder(holdr),
            bal(balnc) 
        {   
            if (balnc < minBal) {
                cout << " [error] initial deposit value is less than minimum\nPlease deposit minimum of 200/-\nAccount creation failed, please retry\n";
                return;
            }

            if (typ == "current") {
                ac_type = 1;
            } else if (typ == "savings") {
                ac_type = 0;
            } else {
                cout << " [error] Invalid account type, please create account again\n";
            }
        }

        ~BankAccount() {
            cout << "Account of Mr." << holder << " with account number " << acNum << " is destroyed with a balance of BDT " << bal << nl;
        }

        bool createAcc(int ac, string& holdr, string typ, double balnc) {
            if (typ == "current") {
                ac_type = 1;
            } else if (typ == "savings") {
                ac_type = 0;
            } else {
                cout << " [error] Invalid account type, please create account again\n";
                return false;
            }
            if (balnc < minBal) {
                cout << " [error] Initial deposit value is less than minimum\nPlease deposit minimum of 200/-\nAccount creation failed, please retry\n";
                return false;
            }
            bal = balnc;
            acNum = ac;
            holder = holdr;
            showInfo();
        }

        void showInfo() const {
            cout << "Account No\t\t=" << acNum << nl;
            cout << "Account Holder Name\t=" << holder << nl;
            cout << "Account Type\t\t=" << (ac_type ? "Current\n" : "Savings\n");
            cout << "Account balance\t\t=" << bal << nl;
        }

        void showBalance() const {
            cout << "The current balance is =" << bal << nl;
        }

        void deposit(double x) {
            if (x < 0) {
                cout << " [error] Invalid amount entered, negative amount cannot be deposited\n";
                return;
            }
            bal += x;
            cout << "Amount of money deposited =\t" << x << "\nThe current balance is\t=" << bal << nl;
        }

        void withdraw(double x) {
            if ((bal - x) < minBal) {
                cout << " [error] This amount of money cannot be withdrawn, insufficient balance\n";
                return;
            }
            bal -= x;
            cout << "Amount of money withdrawn =\t" << x << "\nThe current balance is\t=" << bal << nl;
        }

        void giveInterest(double x = .03) {
            double interestAmount = bal * x;
            taxCol += interestAmount * 0.1;
            interestAmount = (interestAmount - (interestAmount * 0.1));
            bal += interestAmount;
            cout << "Interest paid\t\t=" << interestAmount << nl << "Current Balance\t\t=" << bal << nl;
        }

        double baln() const {
            return bal;
        }

        void printTaxCollected() const {
            cout << "Total tax collected: " << taxCol << nl;
        }

    //END OF PUBLIC

};

double BankAccount::taxCol = 0.0;

void display_stat(const BankAccount& A) {
    A.showInfo();
}

BankAccount Larger(const BankAccount& A, const BankAccount& B) {
    if (A.baln() > B.baln()) {
        return A;
    } else {
        return B;
    }
}

map<int, BankAccount*>::iterator checkAcc(map<int, BankAccount*>& mp, int sel) {
    auto it = mp.find(sel);
    if (it == mp.end()) {
        cout << "Account doesn't exist\n";
        return mp.end();
    }
    else return it;
}

bool checkAccB(map<int, BankAccount*>& mp, int sel) {
    auto it = mp.find(sel);
    if (it == mp.end()) {
        cout << "Account doesn't exist\n";
        return false;
    }
    else return true;
}

int main() {
    //fastread();
    cout << "Initialize the constructor? [y/n] >> ";
    char ch;
    cin >> ch;

    map<int, BankAccount*> accounts;
    if (ch == 'y') {
        int acNum;
        string holder;
        string ac_type;
        double bal;
        cout << "Give account number >> ";
        cin >> acNum;
        cout << "Give the account holder name >> ";
        cin.ignore();  // To avoid getline issues after cin.
        getline(cin, holder);
        cout << "Give the account type [current/savings] >> ";
        cin >> ac_type;
        cout << "Give the initial deposit amount >> ";
        cin >> bal;
        accounts[acNum] = new BankAccount(acNum, holder, ac_type, bal);
    }

    cout << "\nSelect operation\n\t[1] Create account\n\t[2] Deposit\n\t[3] Withdraw\n\t[4] Give interest\n\t[5] Display stat\n\t[6] Compare\n\t[7] Show Total Tax Collected\n\t[8] Exit\n\n [op code] >> ";
    int n;
    while ((cin >> n) && n != 8) {
        int acNum;
        string holder;
        string ac_type;
        double bal;
        int sel, sel2;
        double amount;
         BankAccount* inst;
        switch (n) {
        case 1:
            cout << "Give account number >> ";
            cin >> acNum;
            if (checkAccB(accounts, acNum)) {
                cout << "Account already exists, choose another number.\n";
                break;
            }
            cout << "Give the account holder name >> ";
            cin.ignore();  // To avoid getline issues after cin.
            getline(cin, holder);
            cout << "Give the account type [current/savings] >> ";
            cin >> ac_type;
            cout << "Give the initial deposit amount >> ";
            cin >> bal;
            inst=new BankAccount;
            if(inst->createAcc(acNum, holder, ac_type, bal))
            accounts[acNum] = inst;

            //accounts[acNum] = new BankAccount(acNum, holder, ac_type, bal);
            break;

        case 2:
            cout << "Give account number >> ";
            cin >> sel;
            if (checkAccB(accounts, sel)) {
                cout << "Give the amount >> ";
                cin >> amount;
                accounts[sel]->deposit(amount);
            }
            break;

        case 3:
            cout << "Give account number >> ";
            cin >> sel;
            if (checkAccB(accounts, sel)) {
                cout << "Give the amount >> ";
                cin >> amount;
                accounts[sel]->withdraw(amount);
            }
            break;

        case 4:
            cout << "Give account number >> ";
            cin >> sel;
            if (checkAccB(accounts, sel)) {
                cout << "Use default interest? [y/n] >> ";
                cin >> ch;
                if (ch == 'y') accounts[sel]->giveInterest();
                else {
                    cout << "Give interest rate >> ";
                    double a;
                    cin >> a;
                    accounts[sel]->giveInterest(a);
                }
            }
            break;

        case 5:
            cout << "Give account number >> ";
            cin >> sel;
            if (checkAccB(accounts, sel)) {
                display_stat(*(accounts[sel]));
            }
            break;

        case 6:
            cout << "Give first account number >> ";
            cin >> sel;
            if (checkAccB(accounts, sel)) {
                cout << "Give second account number >> ";
                cin >> sel2;
                if (checkAccB(accounts, sel2)) {
                    cout << "Larger account:\n";
                    Larger(*(accounts[sel]), *(accounts[sel2])).showInfo();
                }
            }
            break;


        case 7:
            accounts[acNum]->printTaxCollected();\
            break;

        default:
            cout << "Invalid option, please choose again\n";
        }
        cout << "\nSelect operation\n\t[1] Create account\n\t[2] Deposit\n\t[3] Withdraw\n\t[4] Give interest\n\t[5] Display stat\n\t[6] Compare\n\t[7] Show Total Tax Collected\n\t[8] Exit\n\n [op code] >> ";

    }

    // Deleting dynamically allocated memory.
    for (auto& pair : accounts) {
        delete pair.second;
    }

    return 0;
}
