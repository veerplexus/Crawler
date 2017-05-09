#include "parseCommons.h"
#include <iostream>
#include <string>
#include <vector>
#include <boost/iterator.hpp>
#include <boost/regex.hpp>

//PARSE ALL GENERIC FUNCTION FOR PARSEING CONTENT BASED ON REGEX
void parsefunctions::parseAll(const std::string& html, const regex& regularExpression, int i, std::vector< std::string >& matches)
{
    //PROFILE_FUNC();
    sregex_iterator it(html.begin(), html.end(), regularExpression);
    sregex_iterator itEnd;
    for (; it != itEnd; ++it)
    {
        matches.push_back((*it)[i].str());
    }
}

std::string parsefunctions::parseOne(const std::string& html, const regex& regularExpression, int i)
{
    //PROFILE_FUNC();
    sregex_iterator it(html.begin(), html.end(), regularExpression);
    sregex_iterator itEnd;
    if (it == itEnd)
        return "";

    return (*it)[i].str();
}

/*
Strings Vinay::parseAll(const std::string& html, const boost::regex& regularExpression, int i)
{
    Strings strings;
    parseAll(html, regularExpression, i, strings);
    return strings;
}
*/
/*To Test functions working
int parsefunctions::add( int a, int b)
{
    return ( a+b);
}
*/
