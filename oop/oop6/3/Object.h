#pragma once
#include <list>
#include <iostream>
#include <string>
#include <memory>
#include "CustomClass.h"

class Object;
class Content
{
	virtual void output(std::ostream& out){ //virtual function for output
		std::cout << "the operator is not supported for this type." << std::endl;
	}
public:
	friend std::ostream& operator<<(std::ostream& out, const Object& obj);
};

class IntContent: public Content
{
private:
	int x;
public:
	IntContent(int _x): x(_x) {}
	void output(std::ostream& out){ //???
		out << x;
	}
	void operator +=(int s)
	{
		this->x += s;
	}
	friend class Object;
};
class StringContent: public Content
{
private:
	std::string x;
public:
	StringContent(std::string _x): x(_x) {}
	void output(std::ostream& out){  //???
		out << x;
	}
	void operator+=(const std::string & s)
	{
		this->x += s;
	}
	friend class Object;
};
// The following codes are not working
class VectorContent: public Content
{
private:
	std::vector<Object> x; //Object is not defined???
public:
	VectorContent(const std::vector<Object>& _x): x(_x) {}
	friend class Object;
};

class CustomContent: public Content
{
private:
	CustomClass x;
public:
	CustomContent(const CustomClass& _x): x(_x) {}
	friend class Object;
};

class Object
{
private:
	std::shared_ptr<Content> pt;

public:
	Object() {}
	Object(int x) {
		pt = std::make_shared<IntContent>(x); // where to delete? maybe use std::shared_ptr?
	}
	Object(const std::string &x){
		pt = std::make_shared<StringContent>(x);
	}
	//The following codes are not working
	Object(const std::vector<Object> &x){
		pt = std::make_shared<VectorContent>(x);
	}
	Object(const CustomClass &x){
		pt = std::make_shared<CustomContent>(x);
	}

	friend std::ostream& operator<<(std::ostream& out, const Object& obj) {
		obj.pt->output(out);
		return out;
	}

	Object& operator+=(int y){
		std::shared_ptr<IntContent> tmp = std::dynamic_pointer_cast<IntContent> (pt);
		tmp->operator+=(y);
		return *this;
	}
	Object& operator+=(const std::string &y){
		std::shared_ptr<StringContent> tmp = std::dynamic_pointer_cast<StringContent> (pt);
		tmp->operator+=(y);
		return *this;
	}

	//need more operators......
	Object& operator[] (int i)
	{
		std::shared_ptr<VectorContent> tmp = std::dynamic_pointer_cast<VectorContent> (pt);
		return (*tmp).x[i];
	}

	// Object& operator=(int x)
	// {
	// 	pt = std::make_shared<IntContent>(x);
	// 	return *this;
	// }
	// Object& operator=(std::string s)
	// {
	// 	pt = std::make_shared<StringContent>(s);
	// 	return *this;
	// }
};
