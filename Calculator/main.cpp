#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

// Function declarations
void appendToResult(string &result, char value);
void clearResult(string &result);
double calculate(string expression);

int main()
{
    string result;

    while (true)
        {
        cout << "Enter an expression (or 'q' to quit): ";
        getline(cin, result);

        if (result == "q")
            break;

        double resultValue = calculate(result);
        cout << "Result: " << resultValue << endl;
    }

    return 0;
}

void appendToResult(string &result, char value)
{
    result += value;
}

void clearResult(string &result)
{
    result.clear();
}

double calculate(string expression)
{
    // Remove all whitespaces from the expression
    expression.erase(remove_if(expression.begin(), expression.end(), ::isspace), expression.end());

    // Evaluate the expression
    try
    {
        size_t pos = 0;
        while ((pos = expression.find_first_of("*/%")) != string::npos)
        {
            char op = expression[pos];
            size_t left_pos = expression.find_last_of("+-", pos - 1);
            size_t right_pos = expression.find_first_of("*/%", pos + 1);

            string left_str = expression.substr(left_pos + 1, pos - left_pos - 1);
            string right_str = expression.substr(pos + 1, right_pos - pos - 1);

            double left = stod(left_str);
            double right = stod(right_str);

            double result;
            if (op == '*')
                result = left * right;
            else if (op == '/')
                result = left / right;
            else if (op == '%')
                result = fmod(left, right);

            expression.replace(left_pos + 1, right_pos - left_pos - 1, to_string(result));
        }

        return stod(expression);
    }
    catch (const invalid_argument&)
    {
        cout << "Invalid expression!" << endl;
        return NAN; // Not a Number
    }
}



