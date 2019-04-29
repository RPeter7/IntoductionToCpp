#include "pch.h"
#include "Account.h"

namespace  bankLogProcess
{
	Account::Account(const string& name_, const string& id_, const int& initialDeposit_, const string& date_, int credit_) :
		_name(name_),
		_id(id_),
		_credit(credit_),
		_balance(initialDeposit_)
	{
		//this->_name = name_;
		if (initialDeposit_ > 0)
		{
			_cashflowEvents.push_back(CashflowEvent(date_, initialDeposit_, EEventTypes::eDeposit));
		}
	}

	string Account::getID() const
	{
		return _id;
	}

	double Account::getBalance() const
	{
		return _balance;
	}

	int Account::getCredit() const
	{
		return _credit;
	}

	Account::operator string() const
	{
		string res = _name + " (" + _id + "): " + to_string(_balance) + "\n";
		for (vector<CashflowEvent>::const_iterator it = _cashflowEvents.begin(); it != _cashflowEvents.end(); it++)
		{
			res += string(*it) + "\n";
		}
		return res;
	}

	void Account::newCashflowEvent(const CashflowEvent& event_)
	{
		_balance = event_.getEventType() != EEventTypes::eWithdraw ? event_.getAmount() : -1.0 * event_.getAmount();
		_cashflowEvents.push_back(event_);
	}
}
