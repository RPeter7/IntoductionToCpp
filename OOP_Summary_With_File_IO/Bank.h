#pragma once
#ifndef Bank_hpp
#define Bank_hpp

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Account.h"

using namespace std;

namespace bankLogProcess
{
	class ELineTypes
	{
	public:
		enum LineTypes
		{
			eDate,
			eInterestRate,
			eNewAccount,
			eCashflow
		};

		ELineTypes(const LineTypes& value_) : _value(value_) {}
		LineTypes getValue() const { return _value; }
	private:
		LineTypes _value;
	};

	class Bank
	{
	private:
		bool existingID(const string& id_) const;
		int searchID(const string& id_) const;
		ELineTypes lineTypes(const string& line_) const;
		Bank& setDate(const string& date_);
		Bank& setInterestRate(const double& interestRate_);
		void createNewAccount(const string& name_, const string& id_, const int& balance_, int credit_ = 0);
		void newCashflowEvent(const string& id_, const double& cashflow_, const EEventTypes& eventType_);
		void newCashflowEvent(const string& id_, const double& cashflow_);
		void eraseNegativeAccounts();
	public:
		void endOfDayProcess();
		friend ifstream& operator>>(ifstream& lhs_, Bank& rhs_);
		friend ostream& operator<<(ostream& lhs_, const Bank& rhs_);
	private:
		string _today;
		double _interestRate;
		vector<Account> _accounts;
	};

	class AlreadyExistingID
	{
	public:
		AlreadyExistingID(const string& message_) : _message(message_) {}
		string getMessage() const { return _message + " already exists!"; }
	private:
		string _message;
	};

	class NonExistingID
	{
	public:
		NonExistingID(const string& message_) : _message(message_) {}
		string getMessage() const { return _message + " does not exist!"; }
	private:
		string _message;
	};
}

#endif /* Bank_hpp */
