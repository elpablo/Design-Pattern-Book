#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>

class ExpressionInterpreter
{
public:
    virtual ~ExpressionInterpreter() {}
    virtual int interpret() = 0;
};

class NumberExpression: public ExpressionInterpreter
{
    int _number;

public:
    NumberExpression(int n): _number(n) {}

    /*virtual*/ int interpret()
    {
        return _number;
    }
};

// nonterminal expression, contains left and right expressions below it
class AddExpression: public ExpressionInterpreter
{
    ExpressionInterpreter *_leftExpression;
    ExpressionInterpreter *_rightExpression;

public:
    AddExpression(ExpressionInterpreter *left, ExpressionInterpreter *right)
    {
        _leftExpression = left;
        _rightExpression = right;
    }

    /*virtual*/ int interpret()
    {
        return _leftExpression->interpret() + _rightExpression->interpret();
    }
};

// nonterminal expression, contains left and right expressions below it
class SubtractExpression : public ExpressionInterpreter
{
    ExpressionInterpreter *_leftExpression;
    ExpressionInterpreter *_rightExpression;

public:
    SubtractExpression(ExpressionInterpreter *left, ExpressionInterpreter *right)
    {
        _leftExpression = left;
        _rightExpression = right;
    }

    /*virtual*/ int interpret()
    {
        return _leftExpression->interpret() - _rightExpression->interpret();
    }
};

class TokenContext
{
public:
    TokenContext(std::string tokenString)
    {
        generateTokens(tokenString);
    }

    ExpressionInterpreter *readToken()
    {
        return readNextToken();
    }

private:
    // Helper function to generate list of token from the std::string
    void generateTokens(std::string token)
    {
        char *str = new char[token.size() + 1];
        std::copy(token.begin(), token.end(), str);

        _tokenList.clear();
        char *pch = strtok(str, " ");
        while (pch != NULL)
        {
            _tokenList.push_back(pch);
            pch = strtok(NULL, " ");
        }
        delete [] str;
    }

    ExpressionInterpreter *readNextToken()
    {
        std::string token = _tokenList.front();
        int i = atoi(token.c_str());
        // if the token is not an operand
        if (token.compare("+") != 0 && token.compare("-") != 0)
        {
            _tokenList.erase(_tokenList.begin());
            return new NumberExpression(i);
        }
        else
        {
            // process expression
            return ReadNonTerminal();
        }
    }

    ExpressionInterpreter *ReadNonTerminal()
    {
        // read the symbol
        std::string token = _tokenList.front();
        _tokenList.erase(_tokenList.begin());
        // read left expression
        ExpressionInterpreter *left = readNextToken();
        // read right expression
        ExpressionInterpreter *right = readNextToken();

        if (token.compare("+") == 0)
        {
            return new AddExpression(left, right);
        }
        else if (token.compare("-") == 0)
        {
            return new SubtractExpression(left, right);
        }
        return NULL;
    }

    std::vector<std::string> _tokenList;
};

int main()
{
    TokenContext *context = new TokenContext("+ - 10 2 3");
    ExpressionInterpreter *expression = context->readToken();
    std::cout << expression->interpret() << std::endl;    // (10 - 2) + 3 = 11
    delete context;

    context = new TokenContext("- + 10 5 - 8 2");
    expression = context->readToken();
    std::cout << expression->interpret() << std::endl;   // (10 + 5) - (8 - 2) = 9
    delete context;

    return 0;
}

/*
 Output

 11
 9

 */
