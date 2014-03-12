#include "Token.h"

int main()
{
	Stack< Token<int> > stk;
	Tokenizer<int> tokenizer(cin);
	bool err_flag = false;
	try{
	while(1){
	cout<<"Enter expression"<<endl;
	Token<int> curr_token = tokenizer.get_token();
	while(curr_token.get_type()!=EOL)
	{
		if(curr_token.get_type()==LPAREN)
		{
			stk.push(curr_token);
		}
		else if(curr_token.get_type()==RPAREN)
		{
			if(stk.empty())
			{
				cerr<<"UNBALANCED LPAREN"<<endl;
				err_flag = true;
				cin.ignore(1000,'\n');
				break;
			}
			else
			{
				stk.pop();
			}
		}
		else if(curr_token.get_type()==UNKNOWN)
		{
			cerr<<"PARSE ERROR"<<endl;
			
			err_flag = true;
			break;
		}
		curr_token=tokenizer.get_token();
	}
	if(!err_flag)
	{
		(stk.empty())?(cout<<"BALANCED LPAREN & RPAREN"):(cout<<"UNBALANCED LPAREN");
		cout<<endl;
	}
	tokenizer.clear(), err_flag = false;
	if(!stk.empty())
	{
		stk.pop();
	}
   }
  }
	catch(const overflow_error& e){
		cout<<e.what();
	}
	catch(const underflow_error& e){
		cout<<e.what();
	}
	return 0;
}