/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namejojo <namejojo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:33:32 by namejojo          #+#    #+#             */
/*   Updated: 2025/09/28 16:29:42 by namejojo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <iomanip>

/*          static funcions             */
	int	Account::getNbAccounts( void )	{	return (_nbAccounts);			}
	int	Account::getTotalAmount( void )	{	return (_totalAmount);			}
	int	Account::getNbDeposits( void )	{	return (_totalNbDeposits);		}
	int	Account::getNbWithdrawals( void ){	return (_totalNbWithdrawals);	}

	void	Account::displayAccountsInfos( void )
    {
		_displayTimestamp();
        std::cout << " accounts:" << getNbAccounts();
        std::cout << ";total:" << getTotalAmount();
        std::cout << ";deposits:" << getNbDeposits();
        std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
    }
/*          static funcions             */
/*          static variables             */
	int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;
/*          static variables             */

    Account::Account( int initial_deposit)
    {
        _amount = initial_deposit;
        _accountIndex = _nbAccounts;
        _nbAccounts++;
        _nbDeposits = 0;
        _nbWithdrawals = 0;
        _totalAmount += checkAmount();

		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
    }
	Account::Account( void )
    {
        _amount = 0;
        _accountIndex = _nbAccounts;
        _nbAccounts++;
        _nbDeposits = 0;
        _nbWithdrawals = 0;

		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
    }
	Account::~Account( void )
    {
		// [19920104_091532] index:7;amount:8942;closed
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;

        _nbAccounts--;
        _totalAmount -= checkAmount();
        _totalNbDeposits -= _nbDeposits;
        _totalNbWithdrawals -= _nbWithdrawals;
    }

	void	Account::makeDeposit( int deposit )
    {
		_displayTimestamp();
		_nbDeposits++;
		std::cout << " index:" << _accountIndex << ";p_amount:" << checkAmount() << ";deposit:" << deposit;
        _amount += deposit;
		std::cout << ";amount:" << _amount << ";nb_deposits:" << ++_totalNbDeposits << std::endl;
    }
	bool	Account::makeWithdrawal( int withdrawal )
    {
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:" << withdrawal;
        if (checkAmount() >= withdrawal)
		{
            _amount -= withdrawal;
			std::cout << ";amount:" << _amount << ";nb_withdrawals:" << ++_totalNbWithdrawals << std::endl;
			_nbWithdrawals++;
			return (true);
		}
		else
			std::cout << "withdrawal:refused" << std::endl;
		return (false);
    }

	int		Account::checkAmount( void ) const{	return (_amount);	}

	void	Account::displayStatus( void ) const
    {
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";total:" << checkAmount();
		std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals;
		std::cout << std::endl;
    }
	void	Account::_displayTimestamp( void )
    {
		time_t	var;
		tm		*time_var;

		var = time(NULL);
		time_var = localtime(&var);
		printf("[%d%02d%02d_", time_var->tm_year + 1900, time_var->tm_mon + 1, time_var->tm_mday);
		printf("%02d%02d%02d]", time_var->tm_hour, time_var->tm_min, time_var->tm_sec);
	}
