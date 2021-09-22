#ifndef EXPRESSION_PARSING_INCLUDED
#define EXPRESSION_PARSING_INCLUDED

#include <string>
#include <stack>
#include <algorithm>

/*
    Reference: https://cp-algorithms.com/string/expression_parsing.html
*/

bool isOperator(char c){
    return c=='+' || c=='-' || c=='*' || c=='/';
}

bool isUnary(char c){
    return c=='+' || c=='-';
}

int operatorPriority(char op){
    if(op<0){
        return 3;
    }

    switch(op){
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        default:
            return -1;
    }
}

long long int performOperation(char op, int opr1, int opr2){
    if(op<0){
        switch(-op){
            case '+':
                return opr1;
            case '-':
                return -opr1;
            default:
                return -1;
        }
    }else{
        switch(op){
            case '+':
                return opr1 + opr2;
            case '-':
                return opr1 - opr2;
            case '*':
                return opr1 * opr2;
            case '/':
                return opr1 / opr2;
            default:
                return -1;
        }
    }
}

void performOperationOnOperands(char op,  std::stack<long long int> &operands){
    long long int operand1; 
    long long int operand2;
    if(op<0){
        operand2= operands.top(); operands.pop();
    }else{
        operand1 = operands.top(); operands.pop();
        operand2= operands.top(); operands.pop();
    }

    operands.push(performOperation(op, operand2, operand1));
}

/*
    Left-associative(if the priorities are equal, they get executed from left to right)
    
    Time complexity: O(n)   // n is string length
    Space complexity: O(n)
*/
long long int expression_parsing(std::string str){
    std::stack<long long int> operands;
    std::stack<char> operators;

    bool may_be_unary = true;
    int str_len = str.length();
    for(int i=0; i<str_len; i++){
        if(isOperator(str[i]) || str[i]=='(' || str[i]==')'){
            if(str[i]=='('){
                operators.push(str[i]);
                may_be_unary = true;
            }else if(str[i]==')'){
                while(operators.top()!='('){
                    performOperationOnOperands(operators.top(), operands);
                    operators.pop();
                }
                operators.pop();
                may_be_unary = false;
            }else{
                char cur_op = str[i];
                if(may_be_unary && isUnary(cur_op)){
                    cur_op = -cur_op;
                }

                // '(' priority will be -1 hence while loop will exit
                while(!operators.empty() && (
                            (cur_op>=0 && operatorPriority(operators.top())>=operatorPriority(cur_op)) ||   // binary have left associativity
                            (cur_op<0 && operatorPriority(operators.top())>operatorPriority(cur_op))
                        )){  // unary have right associativity
                    performOperationOnOperands(operators.top(), operands);
                    operators.pop();
                }
                operators.push(cur_op);
                may_be_unary = true;
            }
        }else if((str[i]-'0')>=0 && (str[i]-'0')<=9){
            long long int number = 0;
            while (i < (int)str.size() && isalnum(str[i]))
                number = number * 10 + str[i++] - '0';
            --i;
            operands.push(number);
            may_be_unary = false;
        }
    }

    while(!operators.empty()){
        performOperationOnOperands(operators.top(), operands);
        operators.pop();
    }

    return operands.top();
}

#endif // EXPRESSION_PARSING_INCLUDED
