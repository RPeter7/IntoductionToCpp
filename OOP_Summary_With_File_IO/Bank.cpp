#include "pch.h"
#include "Bank.h"
#include <cmath>

namespace bankLogProcess
{
	bool Bank::existingID(const string& id_) const
	{
		for (vector<Account>::const_iterator it = _accounts.begin(); it != _accounts.end(); it++)
		{
			if (it->getID() == id_)
			{
				return true;
			}
		}
		return false;
	}

	int Bank::searchID(const string& id_) const
	{
		for (int i = 0; i < _accounts.size(); i++)
		{
			if (_accounts[i].getID() == id_)
			{
				return i;
			}
		}
		return -1;
	}

	ELineTypes Bank::lineTypes(const string& line_) const
	{
		if (line_[0] >= '0' && line_[0] <= '9')
		{
			return ELineTypes::eDate;
		}
		if (line_.find(':') != string::npos)
		{
			return ELineTypes::eInterestRate;
		}
		size_t pos = line_.find(',');
		if (line_.substr(0, pos) == "new account")
		{
			return ELineTypes::eNewAccount;
		}
		return ELineTypes::eCashflow;
	}

	Bank& Bank::setDate(const string& date_)
	{
		_today = date_;
		return *this;
	}

	Bank& Bank::setInterestRate(const double& interestRate_)
	{
		_interestRate = interestRate_;
		return *this;
	}

	void Bank::createNewAccount(const string& name_, const string& id_, const int& balance_, int credit)
	{
		if (existingID(id_))
		{
			throw AlreadyExistingID(id_);
		}
		_accounts.push_back(Account(name_, id_, balance_, _today, credit));
	}

	void Bank::newCashflowEvent(const string& id_, const double& cashflow_, const EEventTypes& eventType_)
	{
		int pos = searchID(id_);
		if (pos == -1)
		{
			throw NonExistingID(id_);
		}
		_accounts[pos].newCashflowEvent(CashflowEvent(_today, eventType_ == EEventTypes::eInterest ? cashflow_ : abs(cashflow_), eventType_));
	}

	void Bank::newCashflowEvent(const string& id_, const double& cashflow_)
	{
		newCashflowEvent(id_, cashflow_, cashflow_ >= 0 ? EEventTypes::eDeposit : EEventTypes::eWithdraw);
	}

	void Bank::eraseNegativeAccounts()
	{
		int i = 0;
		while (i < _accounts.size())
		{
			if (_accounts[i].getBalance() < -1 * _accounts[i].getCredit())
			{
				cout << _accounts[i].getID() << " has been erased!" << endl;
				_accounts.erase(_accounts.begin() + i);
			}
			else
			{
				i++;
			}
		}
	}

	void Bank::endOfDayProcess()
	{
		for (vector<Account>::iterator it = _accounts.begin(); it != _accounts.end(); it++)
		{
			newCashflowEvent(it->getID(), it->getBalance() >= 0 ? exp(_interestRate / 365.0) : -1.0 * exp(4.0 * _interestRate / 365.0), EEventTypes::eInterest);
		}
		eraseNegativeAccounts();
	}

	ifstream& operator>>(ifstream& lhs_, Bank& rhs_)
	{
		string line;
		getline(lhs_, line);
		switch (rhs_.lineTypes(line).getValue())
		{
		case (ELineTypes::eDate):
		{
			rhs_.endOfDayProcess();
			rhs_.setDate(line);
			break;
		}
		case (ELineTypes::eInterestRate):
		{
			size_t pos = line.find(':');
			rhs_.setInterestRate(stod(line.substr(pos + 1)));
			break;
		}
		case (ELineTypes::eNewAccount):
		{
			size_t pos = line.find(',');
			string remainingLine = line.substr(pos + 1);
			pos = remainingLine.find(',');
			string name = remainingLine.substr(0, pos);

			remainingLine = remainingLine.substr(pos + 1);
			pos = remainingLine.find(',');
			string id = remainingLine.substr(0, pos);

			remainingLine = remainingLine.substr(pos + 1);
			int balance;
			int credit = 0;
			if (remainingLine.find(',') == string::npos)
			{
				balance = stoi(remainingLine);
			}
			else
			{
				pos = remainingLine.find(',');
				balance = stoi(remainingLine.substr(0, pos));
				credit = stoi(remainingLine.substr(pos + 1));
			}
			try
			{
				rhs_.createNewAccount(name, id, balance, credit);
			}
			catch (AlreadyExistingID e_)
			{
				cout << e_.getMessage() << endl;
			}
			break;
		}
		case (ELineTypes::eCashflow):
		{
			size_t pos = line.find(',');
			string id = line.substr(0, pos);
			string remainingLine = line.substr(pos + 1);
			pos = remainingLine.find(',');
			EEventTypes type = EEventTypes::Parse(remainingLine.substr(0, pos));
			double cashflow = stod(remainingLine.substr(pos + 1));
			try
			{
				rhs_.newCashflowEvent(id, type == EEventTypes::eDeposit ? cashflow : -cashflow);
			}
			catch (NonExistingID e_)
			{
				cout << e_.getMessage() << endl;
			}
			break;
		}
		}
		return lhs_;
	}

	ostream& operator<<(ostream& lhs_, const Bank& rhs_)
	{
		for (vector<Account>::const_iterator it = rhs_._accounts.begin(); it != rhs_._accounts.end(); it++)
		{
			lhs_ << string(*it);
		}
		return lhs_;
	}
}
