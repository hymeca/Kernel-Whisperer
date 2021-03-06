#include <iostream>
#include <string>
#include <vector>
#include <sstream> 
#include <regex>
#include <cstring>
#include <iterator>
#include "logparser"
#include "util"

using namespace std; 


std::vector<std::wstring> LogParser::parse(std::wstring logLine){

	std::vector<std::wstring> emptyVector;
	
    std::wregex stringSeparatorRegex (std::wstring(L"<-->"));
    std::wsmatch match;
    bool hasMatch = false;

    hasMatch = std::regex_search(logLine,match,stringSeparatorRegex);

	if(hasMatch == false){
		cout << "LogParser->parse->find error: Pipe not found on log." << endl;
		return emptyVector;

	}

	if(match.prefix().str().compare(L"REG") == 0){

		return parseRegistryLog(logLine);

	} else if (match.prefix().str().compare(L"FILE") == 0){

		return parseFileSystemLog(logLine);
	
    } else if (match.prefix().str().compare(L"NET") == 0){

        return parseNetworkLog(logLine);
    }
    else if(match.prefix().str().compare(L"PROC") == 0){

        return parseProcessLog(logLine);
    }

    else if(match.prefix().str().compare(L"OBJECT") == 0){

        return parseObjectLog(logLine);
    }

    else if(match.prefix().str().compare(L"LOADIMAGE") == 0){

        return parseLoadImageLog(logLine);
    }  

    else if(match.prefix().str().compare(L"API") == 0){

        return parseAPILog(logLine);
    }    

	else{
		cout << "LogParser->parse->compare error: Invalid log type." << endl;
		return emptyVector;
	}

	return emptyVector;

}

std::vector<std::wstring> LogParser::parseRegistryLog(std::wstring logLine){

	std::vector<std::wstring> logComponents;
    int separatorIndex = 0;
    int substrBegin = 0;
    std::wstring tempString;
    
    std::wstring::const_iterator matchBegin = logLine.begin();
    std::wstring::const_iterator matchEnd = logLine.end();

    std::wregex stringSeparatorRegex (std::wstring(L"<-->"));
    std::wsmatch match;
    bool hasMatch = false;
    while (std::regex_search(matchBegin, matchEnd, match, stringSeparatorRegex)){

        separatorIndex = match.position(0);
        tempString = logLine.substr(substrBegin, separatorIndex);
        tempString = Util::escapeSpecialCharacters(tempString);
        logComponents.push_back(tempString);
        substrBegin += (separatorIndex + 4);
        matchBegin += (separatorIndex + 4); 
    }    

    tempString = logLine.substr(substrBegin, logLine.length() - substrBegin);
    tempString = Util::escapeSpecialCharacters(tempString);
    logComponents.push_back(tempString);
    return logComponents;
}


std::vector<std::wstring> LogParser::parseFileSystemLog(std::wstring logLine){

	std::vector<std::wstring> logComponents;
    int separatorIndex = 0;
    int substrBegin = 0;
    std::wstring tempString;
    
    std::wstring::const_iterator matchBegin = logLine.begin();
    std::wstring::const_iterator matchEnd = logLine.end();

    std::wregex stringSeparatorRegex (std::wstring(L"<-->"));
    std::wsmatch match;
    bool hasMatch = false;
    while (std::regex_search(matchBegin, matchEnd, match, stringSeparatorRegex)){

        separatorIndex = match.position(0);
        tempString = logLine.substr(substrBegin, separatorIndex);
        tempString = Util::escapeSpecialCharacters(tempString);
        logComponents.push_back(tempString);
        substrBegin += (separatorIndex + 4);
        matchBegin += (separatorIndex + 4); 
    }    

    tempString = logLine.substr(substrBegin, logLine.length() - substrBegin);
    tempString = Util::escapeSpecialCharacters(tempString);
    logComponents.push_back(tempString);
    return logComponents;



}




std::vector<std::wstring> LogParser::parseNetworkLog(std::wstring logLine){

    std::vector<std::wstring> logComponents;
    int separatorIndex = 0;
    int substrBegin = 0;
    std::wstring tempString;
    
    std::wstring::const_iterator matchBegin = logLine.begin();
    std::wstring::const_iterator matchEnd = logLine.end();

    std::wregex stringSeparatorRegex (std::wstring(L"<-->"));
    std::wsmatch match;
    bool hasMatch = false;
    while (std::regex_search(matchBegin, matchEnd, match, stringSeparatorRegex)){

        separatorIndex = match.position(0);
        tempString = logLine.substr(substrBegin, separatorIndex);
        tempString = Util::escapeSpecialCharacters(tempString);
        logComponents.push_back(tempString);
        substrBegin += (separatorIndex + 4);
        matchBegin += (separatorIndex + 4); 
    }    

    tempString = logLine.substr(substrBegin, logLine.length() - substrBegin);
    tempString = Util::escapeSpecialCharacters(tempString);
    logComponents.push_back(tempString);
    return logComponents;



}


std::vector<std::wstring> LogParser::parseProcessLog(std::wstring logLine){

    
    std::vector<std::wstring> logComponents;
    int separatorIndex = 0;
    int substrBegin = 0;
    std::wstring tempString;
    
    std::wstring::const_iterator matchBegin = logLine.begin();
    std::wstring::const_iterator matchEnd = logLine.end();

    std::wregex stringSeparatorRegex (std::wstring(L"<-->"));
    std::wsmatch match;
    bool hasMatch = false;
    while (std::regex_search(matchBegin, matchEnd, match, stringSeparatorRegex)){

        separatorIndex = match.position(0);
        tempString = logLine.substr(substrBegin, separatorIndex);
        tempString = Util::escapeSpecialCharacters(tempString);
        logComponents.push_back(tempString);
        substrBegin += (separatorIndex + 4);
        matchBegin += (separatorIndex + 4); 
    }    

    tempString = logLine.substr(substrBegin, logLine.length() - substrBegin);
    tempString = Util::escapeSpecialCharacters(tempString);
    logComponents.push_back(tempString);
    return logComponents;


}


std::vector<std::wstring> LogParser::parseObjectLog(std::wstring logLine){

    std::vector<std::wstring> logComponents;
    int separatorIndex = 0;
    int substrBegin = 0;
    std::wstring tempString;
    
    std::wstring::const_iterator matchBegin = logLine.begin();
    std::wstring::const_iterator matchEnd = logLine.end();

    std::wregex stringSeparatorRegex (std::wstring(L"<-->"));
    std::wsmatch match;
    bool hasMatch = false;
    while (std::regex_search(matchBegin, matchEnd, match, stringSeparatorRegex)){

        separatorIndex = match.position(0);
        tempString = logLine.substr(substrBegin, separatorIndex);
        tempString = Util::escapeSpecialCharacters(tempString);
        logComponents.push_back(tempString);
        substrBegin += (separatorIndex + 4);
        matchBegin += (separatorIndex + 4); 
    }    

    tempString = logLine.substr(substrBegin, logLine.length() - substrBegin);
    tempString = Util::escapeSpecialCharacters(tempString);
    logComponents.push_back(tempString);
    return logComponents;
}


std::vector<std::wstring> LogParser::parseLoadImageLog(std::wstring logLine){

    std::vector<std::wstring> logComponents;
    int separatorIndex = 0;
    int substrBegin = 0;
    std::wstring tempString;
    
    std::wstring::const_iterator matchBegin = logLine.begin();
    std::wstring::const_iterator matchEnd = logLine.end();

    std::wregex stringSeparatorRegex (std::wstring(L"<-->"));
    std::wsmatch match;
    bool hasMatch = false;
    while (std::regex_search(matchBegin, matchEnd, match, stringSeparatorRegex)){

        separatorIndex = match.position(0);
        tempString = logLine.substr(substrBegin, separatorIndex);
        tempString = Util::escapeSpecialCharacters(tempString);
        logComponents.push_back(tempString);
        substrBegin += (separatorIndex + 4);
        matchBegin += (separatorIndex + 4); 
    }    

    tempString = logLine.substr(substrBegin, logLine.length() - substrBegin);
    tempString = Util::escapeSpecialCharacters(tempString);
    logComponents.push_back(tempString);
    return logComponents;
}


std::vector<std::wstring> LogParser::parseAPILog(std::wstring logLine){

    std::vector<std::wstring> logComponents;
    int separatorIndex = 0;
    int substrBegin = 0;
    std::wstring tempString;
    
    std::wstring::const_iterator matchBegin = logLine.begin();
    std::wstring::const_iterator matchEnd = logLine.end();

    std::wregex stringSeparatorRegex (std::wstring(L"<-->"));
    std::wsmatch match;
    bool hasMatch = false;
    while (std::regex_search(matchBegin, matchEnd, match, stringSeparatorRegex)){

        separatorIndex = match.position(0);
        tempString = logLine.substr(substrBegin, separatorIndex);
        tempString = Util::escapeSpecialCharacters(tempString);
        logComponents.push_back(tempString);
        substrBegin += (separatorIndex + 4);
        matchBegin += (separatorIndex + 4); 
    }    

    tempString = logLine.substr(substrBegin, logLine.length() - substrBegin);
    tempString = Util::escapeSpecialCharacters(tempString);
    logComponents.push_back(tempString);
    return logComponents;
}
