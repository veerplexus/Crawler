# Crawler
A collection of web crawlers.

Building

To build for linux, you need to have the g++ compiler and the CMake build system installed. You also need the following libraries:

	curl
	log4cxx
	mysql++
	mongodb
	boost
To install all the requirements with one command in Ubuntu 12.04+, just do:
	
	$ sudo apt-get install build-essential cmake cmake-curses-gui libcurl4-gnutls-dev liblog4cxx10-dev libmysql++-dev libboost-all-dev mongodb-dev mongodb-clients mongodb-server
