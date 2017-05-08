#include <iostream>
#include <string>
#include <curl/curl.h> //your directory may be different
#include <boost/regex.hpp>
#include <stdlib.h>

#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/archive/iterators/transform_width.hpp>

using namespace std;
using namespace boost;


string data; //will hold the url's contents
string parseContent ( string& );

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{ //callback must have this declaration
    //buf is a pointer to the data that curl has for us
    //size*nmemb is the size of the buffer

    for (int c = 0; c<size*nmemb; c++)
    {
        data.push_back(buf[c]);
    }
    return size*nmemb; //tell curl how many bytes we handled
}
//PARSE ALL GENERIC FUNCTION FOR PARSEING CONTENT BASED ON REGEX
void parseAll(const std::string& html, const regex& regularExpression, int i, std::vector< std::string >& matches)
{
    //PROFILE_FUNC();
    sregex_iterator it(html.begin(), html.end(), regularExpression);
    sregex_iterator itEnd;
    for (; it != itEnd; ++it)
    {
        matches.push_back((*it)[i].str());
    }
}
std::string parseOne(const std::string& html, const regex& regularExpression, int i) 
{
    //PROFILE_FUNC();
    sregex_iterator it(html.begin(), html.end(), regularExpression);
    sregex_iterator itEnd;
    if (it == itEnd)
        return "";
    
    return (*it)[i].str();
}
string parseContent( string& data)
{

    std::string name, div;
    std::vector<std::string> v;
    boost::regex expr("class=\"view-content\">(.*?)</section>");            //captures DIV 
    bool flag = regex_match(data, expr);
    if ( flag != true )
    {
        boost::smatch id,what;
        boost::regex_search( data, id, expr);

        div= id[1];        //points to captured information betweeen the tags specified in regex expression
        boost::regex links("<a href=\"(.*?)\"");
        std::vector<std::string> urls;
        std::string linkname= parseOne(div, links,1);
        parseAll(div, links, 1,urls);
        for ( auto& i: urls)
        {std::cout<<"\nParsesd Link is : \t"<<i;}
    std::cout<<"\n\nName of veer is \t"<<linkname;
        // int i=1;
        // while( !div.empty() )
        // {
        //     boost::regex_search( div, what , links);
        //     if ( what[1] != "")
        //     {
        //         v.push_back(what[1]);
        //     }
        //     div = what.suffix();  //
        //     i++;
        // }
    }
    else
    {
        std::cout<<"no response is captured!!!";
    }
    // for ( auto& i: urls)
    //     std::cout<<"\nParsesd Link is : \t"<<i;

    return "";
}
int main()
{
    CURL* curl; //our curl object

    curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, "http://biorxiv.org/");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress

    curl_easy_perform(curl);

    //cout << endl << data << endl;
    // std::cout<<"***********************************veer*************************************\n"
    // <<data<<"\n*********************************************************************************************************"<<std::endl;
   // std::cout<<data;
    parseContent(data);

    cin.get();

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}