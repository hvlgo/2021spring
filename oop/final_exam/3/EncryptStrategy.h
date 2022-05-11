#pragma once
# include <string>

class EncryptStrategy{
public:
	virtual std::string encode(std::string mes) = 0;
};

class InsertStrategy : public EncryptStrategy
{
public:
	std::string encode(std::string mes)
	{
		std::string new_mes;
		for (int i = 0; i < 2*mes.size(); i++)
		{
			if (i % 2 == 0)
				new_mes += mes[i/2];
			else
				new_mes += '#';
		}
		return new_mes;
	}
};

class InvertStrategy : public EncryptStrategy
{
public:
	std::string encode(std::string mes)
	{
		std::string new_mes;
		for (auto i = mes.rbegin(); i != mes.rend(); i++)
		{
			new_mes.push_back(*i);
		}
		return new_mes;
	}
};