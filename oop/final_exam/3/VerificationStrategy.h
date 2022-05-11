#pragma once
# include <string>

class VerificationStrategy{
public:
	virtual std::string verify(std::string mes) = 0;
};

class PrefixStrategy : public VerificationStrategy
{
public:
	std::string verify(std::string mes)
	{
		std::string new_mes;
		new_mes = mes.substr(0, 3);
		return new_mes;
	}
};

class IntervalStrategy : public VerificationStrategy
{
public:
	std::string verify(std::string mes)
	{
		std::string new_mes;
		int pos = 0;
		for (auto i : mes)
		{
			if (pos % 2 == 0)
				new_mes += i;
			pos++;
		}
		return new_mes;
	}
};