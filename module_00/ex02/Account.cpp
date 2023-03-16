#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>

//*******************************************//
//            NON-MEMBERS FUNCTIONS          //
//*******************************************//

int     Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int     Account::getTotalAmount(void)
{
	return (_totalAmount);uwcbwc
}

int     Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int     Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals: " << Account::_totalNbWithdrawals << std::endl;

}
//*******************************************//
//         CONSTRUCTORS/DESTRUCTORS          //
//*******************************************//

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";created" << std::endl;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";closed" << std::endl;
	return ;
}

//*******************************************//
//             MEMBERS FUNCTIONS             //
//*******************************************//

void    Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	if (deposit > 0)
	{
		this->_nbDeposits++;
		Account::_totalNbDeposits++;
	}
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposit:" << this->_nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount)
		std::cout << ";withdrawals:refused" << std::endl;
	else
	{
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return (1);
}

//amount verification
int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

//*******************************************//
//               TIME TREATMENT              //
//*******************************************//

void	Account::_displayTimestamp( void )
{
	static	std::time_t time_now = std::time(nullptr);
	std::cout << "[" << std::put_time(std::localtime(&time_now), "%Y%m%d_%H%M%S") << "] ";

}

//*******************************************//
//               STATICS    VAR              //
//*******************************************//

int     Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;