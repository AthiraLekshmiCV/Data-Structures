#ifndef __TOKEN_H__
#define __TOKEN_H__

#include<iostream>
#include<stdexcept>

using namespace std;
template<class Type>
class Stack{
public:
	typedef unsigned int size_type;
	typedef Type value_type;
private:
	static const unsigned int stack_size=10;
	value_type data[stack_size];
	signed int top_of_stack;
public:
	Stack():top_of_stack(-1){}
	bool empty () const{
		return ((top_of_stack==-1)?true:false);
	}
	size_type size()const{
		return (top_of_stack+1);
	}
	value_type& top(){
		return data[top_of_stack];
	}
	const value_type& top()const{
		return data[top_of_stack];
	}

	
	void push(const value_type& x);
	void pop() ;
};




enum Token_Type{
	EOL,
	VALUE,
	LPAREN,
	RPAREN,
	PLUS, 
	MINUS,
	DIV,
	MULT,
	EXP,
	UNKNOWN 
};

template<class T>
class Token{
private:
	Token_Type token_type;
	T token_value;
public:
	Token(Token_Type tt = EOL, const T& val = 0):token_type(tt),token_value(val){}
	Token_Type get_type()const
	{
		return token_type;
	}
	const T& get_value()const
	{
		return token_value;
	}
};
template<class T>
class Tokenizer
{
private:
	istream& in;
public:
	Tokenizer(istream& is):in(is){}
	Token<T> get_token();
	void clear(){in.clear();}
};
#include "Token.cpp"
#endif