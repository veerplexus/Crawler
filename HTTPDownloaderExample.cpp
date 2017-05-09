/**
 * HTTPDownloaderExample.cpp
 *
 * A simple C++ wrapper for the libcurl easy API.
 * This file contains example code on how to use the HTTPDownloader class.
 *
 * Compile like this: g++ -o HTTPDownloaderExample HTTPDownloaderExample.cpp HTTPDownloader.cpp -lcurl
 *
 * Written by Uli Köhler (techoverflow.net)
 * Published under CC0 1.0 Universal (public domain)
 */
#include "HTTPDownloader.hpp"
#include "parseCommons.h"
#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include <vector>
#include <regex>

using namespace std;

int main( ) {

    parsefunctions pf;

    HTTPDownloader downloader;
    std::string content = downloader.download("http://biorxiv.org/");

    boost::regex expr("class=\"view-content\">(.*?)</section>");            //captures DIV
    bool flag = regex_match(content, expr);
    std::string div;

    if ( flag != true )
    {
        boost::smatch what;
        boost::regex_search( content, what, expr);
        div= what[1];        //points to captured information betweeen the tags specified in regex expression
    }

    std::vector<std::string> urls;

    regex link("<a href=\"(.*?)\"");
    std::string result =  pf.parseOne(div,link,1);

    std::cout << result  << "\n" << "Govardhan Rocks !!!!" << "\n";

    pf.parseAll( div, link, 1 , urls);
    for ( auto& i: urls)
    {
        std::cout << "\n Parse Link is :\t" << i <<std::endl;
    }




    return 0;
}


/*
        vi.parseAll(div, links, 1, urls);
        for ( auto& i: urls)
        {
            std::cout<<"\nParsesd Link is : \t"<<i;
        }
        */
