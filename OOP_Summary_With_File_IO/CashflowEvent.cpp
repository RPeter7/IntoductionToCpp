#include "pch.h"
#include "CashflowEvent.h"

namespace bankLogProcess
{

	CashflowEvent::CashflowEvent(const string& date_, const double& amount_, const EEventTypes& eventType_) :
		_date(date_),
		_amount(amount_),
		_eventType(eventType_)
	{
	}

	double CashflowEvent::getAmount() const
	{
		return _amount;
	}

	EEventTypes CashflowEvent::getEventType() const
	{
		return _eventType;
	}

	CashflowEvent::operator string() const
	{
		return _date + ": " + to_string(_amount) + " *" + string(_eventType) + ")";
	}

}
