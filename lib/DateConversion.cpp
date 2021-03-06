//
//  DateConversion.cpp
//  logcollect
//
//  Created by Steffen Sørensen on 1/23/13.
//  Copyright (c) 2013 Steffen Sørensen. All rights reserved.
//

#include <iostream>
#include <vector>
#include "../include/DateConversion.h"

logcollect::DateConversion::DateConversion(){
	tzset();
}

bool logcollect::DateConversion::addFormat(std::string* format){
	this->formats.push_back(format);
	return true;
}

bool logcollect::DateConversion::addFormat(const char* format){
	std::string* str_format = new std::string(format);
	return this->addFormat(str_format);
}

time_t logcollect::DateConversion::getTime(const std::string* str_time){
	return this->getTime(str_time->c_str());
}

time_t logcollect::DateConversion::getTime(const char* str_time){
	std::vector<const std::string*>::iterator it;
	time_t detected_time = time(NULL);
	
	tm* result = new tm();
	bool found_format = false;
	
	std::cout << str_time << " " << this->formats.size() << std::endl;
	
	for (it = this->formats.begin() ; it != this->formats.end(); it++){
		char* first = strptime(str_time, (*it)->c_str(), result);
		
		std::cout << "Hit: " << (*it)->c_str() << std::endl;
		if(first != NULL){
			std::cout << "converted: " << (*it)->c_str() << std::endl;
			found_format = true;
			detected_time = timegm(result);
			std::cout << "time: " << detected_time << std::endl;
			break;
		}
	}
	
	delete[] result;
	return detected_time;
}
