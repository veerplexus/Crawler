
#ifndef PARSECOMMONS_H_INCLUDED
#define PARSECOMMONS_H_INCLUDED
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <regex>
#include <boost/regex.hpp>
#include <stdlib.h>
#include <boost/algorithm/string/regex.hpp>
using namespace std;

typedef std::vector<std::string> Strings;

class parsefunctions
{

public:

void parseAll(const std::string& html, const regex& regularExpression, int i, std::vector< std::string >& matches);
std::string parseOne(const std::string& html, const regex& regularExpression, int i);
Strings parseAll(const std::string& html, const regex& regularExpression, int i);
int add( int a, int b);

};



#endif // PARSECOMMONS_H_INCLUDED
