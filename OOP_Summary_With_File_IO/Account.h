#pragma once
#ifndef Account_hpp
#define Account_hpp

#include <string>
#include <vector>
#include "CashflowEvent.h"

using namespace std;

namespace bankLogProcess
{

	class Account
	{
	public:
		Account(const string& name_, const string& id_, const int& initialDeposit_, const string& date_, int credit_ = 0);

		string getID() const;
		double getBalance() const;
		int getCredit() const;
		operator string() const;

		void newCashflowEvent(const CashflowEvent& event_);
	private:
		string _name;
		string _id;
		int _credit;
		double _balance;
		vector<CashflowEvent> _cashflowEvents;
	};

}


#endif /* Account_hpp */
