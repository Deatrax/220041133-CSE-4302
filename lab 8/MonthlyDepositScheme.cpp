#include "MonthlyDepositScheme.h"

string MDS::nextAccountNo(){
    return to_string(nextAccount++);
}
