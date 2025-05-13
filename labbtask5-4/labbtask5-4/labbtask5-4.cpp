#include <iostream>
#include <string>
#include <stack>
#include <vector>

int getPriority(char symbol)
{
    if (symbol == '+' || symbol == '-')
        return 1;
    if (symbol == '*' || symbol == '/' || symbol == '%')
        return 2;
    return 0;
}

bool Check_operands(char symbol)
{
    return (symbol >= '0' && symbol <= '9') || symbol == '.';
}

bool Check_operations(char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%';
}

int main()
{
    std::string expression;
    std::string symbols = { "0123456789-+/%()." };
    std::cout << "Enter the algebraic expression: ";
    std::cin >> expression;
    if (expression.empty())
    {
        std::cout << "Expression is empty!";
        return 0;
    }

    if (expression.find_last_not_of(symbols, 0) != std::string::npos)
    {
        std::cout << "Incorrect expression!";
        return 0;
    }

    std::stack<char> StackX;
    std::vector<std::string> result;

    for (size_t i = 0; i < expression.length(); i++)  // Преобразование в ОПН
    {
        if (Check_operands(expression.at(i)))
        {
            std::string num;
            while (i < expression.length() && Check_operands(expression[i]))
            {
                num += expression[i];
                i++;
            }
            i--;
            result.push_back(num);
        }
        else if (expression.at(i) == '(')
            StackX.push(expression.at(i));
        else if (Check_operations(expression.at(i)))
        {
            while (!StackX.empty() && StackX.top() != '(' && getPriority(StackX.top()) >= getPriority(expression.at(i)))
            {
                result.push_back(std::string(1, StackX.top()));
                StackX.pop();
            }
            StackX.push(expression.at(i));
        }
        else if (expression.at(i) == ')')
        {
            while (!StackX.empty() && StackX.top() != '(')
            {
                result.push_back(std::string(1, StackX.top()));
                StackX.pop();
            }
            if (StackX.empty())
            {
                std::cout << "Stack is empty!" << std::endl;
                return 0;
            }
            StackX.pop();
        }
        else
        {
            std::cout << "Something went wrong :|" << std::endl;
        }
    }
    while (!StackX.empty())
    {
        if (StackX.top() == '(')
        {
            std::cout << "Something went wrong :|" << std::endl;
            return 0;
        }
        result.push_back(std::string(1, StackX.top()));
        StackX.pop();
    }

    std::cout << "RPN: ";
    for (const auto& tok : result)
        std::cout << tok << ' ';
    std::cout << '\n';

    std::stack<float> evaluation;
    for (const auto& tok : result)      // Решение ОПН
    {
        if (!tok.empty() && Check_operands(tok[0]))
        {
            evaluation.push(stof(tok));
        }
        else if (tok.size() == 1 && Check_operations(tok[0]))
        {
            if (evaluation.size() < 2)
            {
                std::cout << "Error";
                return 0;
            }
            float b = evaluation.top(); evaluation.pop();
            float a = evaluation.top(); evaluation.pop();
            switch (tok[0])
            {
            case '+': evaluation.push(a + b); break;
            case '-': evaluation.push(a - b); break;
            case '*': evaluation.push(a * b); break;
            case '/':
                if (b == 0)
                {
                    std::cout << "Division by zero";
                    return 0;
                }
                evaluation.push(a / b); break;
            case '%':
                if (b == 0)
                {
                    std::cout << "Modulo by zero";
                    return 0;
                }
                evaluation.push(static_cast<int>(a) % static_cast<int>(b)); break; 
            default:
                std::cout << "Unknown operator";
                return 0;
            }
        }
        else
        {
            std::cout << "Error";
            return 0;
        }
    }

    if (evaluation.size() != 1)
    {
        std::cout << "Error";
        return 0;
    }

    std::cout << "Result: " << evaluation.top() << '\n';
    return 0;
}

        
