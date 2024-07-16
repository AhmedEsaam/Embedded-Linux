#include <iostream>
#include <ctime>
#include <iomanip>

class Account
{
public:
    using acc = Account;

    /* brief Returns the number of accounts */
    static int getNoOfAccounts(void)
    {
        return acc::m_noOfAccounts;
    }

    /* Returns the total amount of all accounts */
    static int getTotalAmount(void)
    {
        return acc::m_totalAmount;
    }

    /* Returns the number of deposits */
    static int getNbDeposits(void)
    {
        return acc::m_totalNbDeposits;
    }

    /* Returns the number of withdrawals */
    static int getNoOfWithdrawals(void)
    {
        return acc::m_totalNbWithdrawals;
    }

    /* Displays the number of accounts, the total amount of deposits, the total amount of withdrawals, and the total amount of all accounts */
    static void displayAccountsInfos(void)
    {
        std::cout << std::endl
                  << "************ Accounts Info ************" << std::endl;
        std::cout << "Time: ";
        acc::m_displayTimestamp();
        std::cout << "Number of accounts: " << std::setw(19) << acc::m_noOfAccounts << std::endl;
        std::cout << "Total number of deposits: " << std::setw(13) << acc::m_totalNbDeposits << std::endl;
        std::cout << "Total number of withdrawals: " << std::setw(10) << acc::m_totalNbWithdrawals << std::endl;
        std::cout << "Total amount of all accounts: " << std::setw(9) << acc::m_totalAmount << std::endl;
    }

    /* Account Constructor */
    Account(int initial_deposit) : m_noOfDeposits(0), m_noOfWithdrawals(0)
    {
        acc::m_noOfAccounts++;
        m_accountIndex = acc::m_noOfAccounts;

        m_amount += initial_deposit;
        acc::m_totalAmount += initial_deposit;

        m_noOfDeposits++;
        acc::m_totalNbDeposits++;
    }

    /* Account Destructor */
    ~Account(void)
    {
        acc::m_noOfAccounts--;
        acc::m_totalAmount -= m_amount;
        acc::m_totalNbDeposits -= m_noOfDeposits;
        acc::m_totalNbWithdrawals -= m_noOfWithdrawals;
    }

    /* Making a Deposit */
    void makeDeposit(int deposit)
    {
        m_amount += deposit;
        acc::m_totalAmount += deposit;

        m_noOfDeposits++;
        acc::m_totalNbDeposits++;
    }

    /* Making a Withdrawal if Amount is Sufficient */
    bool makeWithdrawal(int withdrawal)
    {
        if (m_amount >= withdrawal)
        {
            m_amount -= withdrawal;
            acc::m_totalAmount -= withdrawal;

            m_noOfWithdrawals++;
            acc::m_totalNbWithdrawals++;

            return true;
        }
        else
        {
            return false;
        }
    }

    /* Get Amount */
    int checkAmount(void) const
    {
        return m_amount;
    }

    /* Display Account Info */
    void displayStatus(void) const
    {
        std::cout << std::endl
                  << "********** Account #" << m_accountIndex << " Status **********" << std::endl;
        std::cout << "Time: ";
        acc::m_displayTimestamp();
        std::cout << "Amount: " << std::setw(31) << m_amount << std::endl;
        std::cout << "Number of Deposits: " << std::setw(19) << m_noOfDeposits << std::endl;
        std::cout << "Number of Withdrawals: " << std::setw(16) << m_noOfWithdrawals << std::endl;
    }

private:
    static int m_noOfAccounts;
    static int m_totalAmount;
    static int m_totalNbDeposits;
    static int m_totalNbWithdrawals;

    /* Displays the current timestamp (used in displayAccountsInfos() */
    static void m_displayTimestamp(void)
    {
        time_t current_time = time(0);
        std::cout << ctime(&current_time);
    }

    int m_accountIndex;
    int m_amount;
    int m_noOfDeposits;
    int m_noOfWithdrawals;

    Account(void);
};

int Account::m_noOfAccounts = 0;
int Account::m_totalAmount = 0;
int Account::m_totalNbDeposits = 0;
int Account::m_totalNbWithdrawals = 0;

int main()
{
    /* Creating 3 accounts */
    Account *acc1 = new Account(1000);
    Account acc2(1500);
    Account acc3(2000);

    /* Account #1 -----------------------------------------------*/

    acc1->displayStatus();

    std::cout << std::endl;

    acc1->makeDeposit(300);
    std::cout << "Event: Account #1 deposit 300 $, new amount: " << acc1->checkAmount() << " $" << std::endl;

    acc1->makeWithdrawal(500);
    std::cout << "Event: Account #1 withdraw 500 $, new amount: " << acc1->checkAmount() << " $" << std::endl;

    acc1->displayStatus();

    /* Account #2 -----------------------------------------------*/

    acc2.displayStatus();

    acc2.makeWithdrawal(500);
    std::cout << std::endl
              << "Event: Account #2 withdraw 500 $, new amount: " << acc2.checkAmount() << " $" << std::endl;

    acc2.displayStatus();

    /* Account #3 -----------------------------------------------*/

    acc3.displayStatus();

    std::cout << std::endl;

    acc3.makeDeposit(500);
    std::cout << "Event: Account #3 deposit 500 $, new amount: " << acc3.checkAmount() << " $" << std::endl;

    acc3.makeWithdrawal(1500);
    std::cout << "Event: Account #3 withdraw 1500 $, new amount: " << acc3.checkAmount() << " $" << std::endl;

    acc3.makeWithdrawal(1001);
    std::cout << "Event: Account #3 withdraw 1001 $, new amount: " << acc3.checkAmount() << " $" << std::endl;

    acc3.displayStatus();

    /* Display All Accounts Infos */
    Account::displayAccountsInfos();

    /* Delete Account #1 */
    delete acc1;
    std::cout << std::endl
              << "Event: Account #1 is deleted. (it has made 2 deposits and 1 wthdrawal)" << std::endl;

    /* Display All Accounts Infos */
    Account::displayAccountsInfos();

    return 0;
}