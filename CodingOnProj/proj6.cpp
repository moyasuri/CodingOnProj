#include <iostream>

using namespace std;


class Calculator {
public:
    virtual double calculate(double a, double b) = 0;

public:
    static double _result;
};

class Add : public Calculator {
public:
    double calculate(double a, double b) override {
        return a + b;
    }
};

class Subtract : public Calculator {
public:
    double calculate(double a, double b) override {
        return a - b;
    }
};

class Multiply : public Calculator {
public:
    double calculate(double a, double b) override {
        return a * b;
    }
};

class Divide : public Calculator {
public:
    double calculate(double a, double b) override {
        if (b != 0)
            return a / b;
        else
            throw std::runtime_error("Error: Division by zero");
    }
};


double Calculator::_result = 0;
int main() {
    
    
    
    char operation;
    bool loop = true, loop_cmd = true, loop_cmd2 = true;
    
    Calculator* calculator = nullptr;
    double num1, num2;
    string cmd = "first";
    while (loop)
    {
        if (cmd.compare("first")==0)
        {

        }
        else
        {
            cout << "연산을 계속하시겠습니까 ? (Y: 계속, AC : 초기화, EXIT : 종료) ";
            cin >> cmd;
        }
        

        
        while (loop_cmd)
        {


            if (cmd.compare("Y")==0)
            {
                loop_cmd = false;
                
            }
            else if (cmd.compare("AC")==0)
            {
                loop_cmd = false;
                Calculator::_result = 0;
            }
            else if (cmd.compare("EXIT")==0)
            {
                return 0;
            }
            else if (cmd.compare("first")==0)
            {
                loop_cmd = false;
            }
            else
            {
                cout << "잘못된 명령어 입니다.";
            }
        }
        if (cmd.compare("Y")==0)
        {
            num1 = Calculator::_result;
        }
        else
        {
            cout << "숫자를 입력해주세요 : ";
            cin >> num1;
        }
        
        std::cout << "연산자를 입력해주세요 (+, -, *, /): ";
        cin >> operation;
        cout << "숫자를 입력해주세요 : " ;
        cin >> num2;

        while (loop_cmd2)
        {
            switch (operation) {
            case '+':
                calculator = new Add();
                Calculator::_result = calculator->calculate(num1, num2);
                loop_cmd2 = false;

                break;
            case '-':
                calculator = new Subtract();
                Calculator::_result = calculator->calculate(num1, num2);
                loop_cmd2 = false;

                break;
            case '*':
                calculator = new Multiply();
                Calculator::_result = calculator->calculate(num1, num2);
                loop_cmd2 = false;

                break;
            case '/':
                calculator = new Divide();
                Calculator::_result = calculator->calculate(num1, num2);
                loop_cmd2 = false;

                break;
            default:
                std::cout << "Invalid operation" << std::endl;
            }


        }

        calculator = nullptr;
        loop_cmd = true;
        loop_cmd2 = true;
        cmd = "";
        cout << "결과 : " << Calculator::_result << endl;
        
        delete calculator; // 동적 할당 해제


    }


    return 0;
}