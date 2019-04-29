#pragma once
#ifndef CashflowEvent_hpp
#define CashflowEvent_hpp

#include <string>

using namespace std;

namespace bankLogProcess
{

	class ParserException {
	public:
		ParserException(const string& message_) : _message(message_) {}
		string getMessage() const { return _message + " cannot be parsed to EEventTypes"; }
	private:
		string _message;
	};

	//Az enum tipus be lett csomagolva egy osztalyba, igy az enum tipusu valtozon elvegzendo muveletek az osztalyon belul megvalosithatok, az enum tipusu valtozo hasznalata egyszerubbe valik.
	class EEventTypes {
	public:
		enum EventTypes {
			eDeposit,
			eWithdraw,
			eInterest
		};

		EEventTypes(const EventTypes& value_) : _value(value_) {}

		bool operator==(const EventTypes& rhs_) const {
			return _value == rhs_;
		}

		bool operator!=(const EventTypes& rhs_) const {
			return _value != rhs_;
		}

		//Parser static methodus - lehetove teszi, hogy megfelelo stringet enumma konvertaljunk. Ha a string nem megengedett, akkor egy ParserException dobodik el.
		static EEventTypes Parse(const string& input_) {
			if (input_ == "deposit")
				return EEventTypes(eDeposit);
			else if (input_ == "withdraw")
				return EEventTypes(eWithdraw);
			else if (input_ == "interest")
				return EEventTypes(eInterest);
			else
				throw ParserException(input_);
		}

		//Ez hivodik meg akkor, amikor az enum tipusu valtozot stringge kivanjuk konvertalni.
		operator string() const {
			switch (_value) {
			case EventTypes::eDeposit:
				return "deposit";
				break;
			case EventTypes::eWithdraw:
				return "withdraw";
				break;
			case EventTypes::eInterest:
				return "interest";
				break;
			}
		}
	private:
		EventTypes _value;
	};

	class CashflowEvent
	{
	public:
		CashflowEvent(const string& date_, const double& amount_, const EEventTypes& eventType_);
		double getAmount() const;
		EEventTypes getEventType() const;
		operator string() const;
	private:
		string _date;
		double _amount;
		EEventTypes _eventType;
	};

}

#endif /* CashflowEvent_hpp */
