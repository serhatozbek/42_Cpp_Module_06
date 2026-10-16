#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& other){(void)other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){(void)other; return *this;}
ScalarConverter::~ScalarConverter(){}

static bool isPseudoLiteral(const std::string& str) {
    return(str == "-inff" || str == "+inff" || str == "-inf" ||
        str == "+inf" || str == "nanf" || str == "nan");
}

void ScalarConverter::convert(const std::string& literal){
    int i = 0;
    double d = 0.0;
    float f = 0.0f;
    char c = 0;

    if (literal.length() == 1 && !isdigit(literal[0]))
    {
        c = literal[0];

        i = static_cast<int>(c);
        d = static_cast<double>(c);
        f = static_cast<float>(c);
    }
    else{
        char* endPtr;
        d = std::strtod(literal.c_str(), &endPtr);
        bool validEnd = (*endPtr == '\0') ||
            (*endPtr == 'f' && *(endPtr + 1) == '\0');
        if (literal.empty() || (!validEnd && !isPseudoLiteral(literal)))
        {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
            return;
        }
        f = static_cast<float>(d);
        i = static_cast<int>(d);
        c = static_cast<char>(i);
    }

    if (isPseudoLiteral(literal) || d < CHAR_MIN || d > CHAR_MAX || std::isnan(d))
        std::cout << "char: impossible" << std::endl;
    else if(!isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;

    if(isPseudoLiteral(literal) || d < INT_MIN || d > INT_MAX || std::isnan(d))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (isPseudoLiteral(literal))
    {
        if (literal == "-inff" || literal == "+inff" || literal == "nanf")
            std::cout << "float: " << literal << std::endl;
        else
            std::cout << "float: " << literal << "f" << std::endl;
    }
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    if (isPseudoLiteral(literal))
    {
        if (literal == "-inff" || literal == "+inff" || literal == "nanf")
            std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        else
            std::cout << "double: " << literal << std::endl;
    }
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
