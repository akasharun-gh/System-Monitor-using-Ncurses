#include <string>

#include "format.h"

using std::string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) { 
    string hr = "";
    string min = "";
    string sec = "";

    hr = std::to_string(seconds/3600);
    min = std::to_string((seconds%3600)/60);
    sec = std::to_string((seconds%3600)%60);

    if(hr.length() == 1) hr = "0" + hr;
    if(min.length() == 1) min = "0" + min;
    if(sec.length() == 1) sec = "0" + sec;

    return hr + ":" + min + ":" + sec;

 }