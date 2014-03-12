//#include "Token.h"
template <typename Type>
void Stack<Type>:: push(const value_type& x){
		if(top_of_stack==stack_size-1){
			throw overflow_error("Stack overflow");
		}
		data[++top_of_stack]=x;
		
		return;
	}

template <typename Type>
	void Stack<Type>:: pop() {
		if(top_of_stack==-1){
			throw underflow_error("Stack underflow");
		}
		top_of_stack--;
		return;
	}
template <class T>

Token<T> Tokenizer<T>::get_token()
{
	char ch;
	T value;
	while(in.get(ch)&&((ch==' ')||(ch=='\t')));
	switch(ch)
	{
		case '^': return EXP;
		case '+': return PLUS;
		case '-': return MINUS;
		case '*': return MULT;
		case '(': return LPAREN;
		case ')': return RPAREN;
		case '\n': return EOL;
		default: in.putback(ch);
		if(in>>value)
		{
			return Token<T>(VALUE,value);
		}
		else
		{
			cin.clear();
			cin.ignore(1000,'\n');
			return UNKNOWN;
		}
	}
}