#include "time_utils.h"
using namespace std;

bool is_valid_time(int hour, int minute, int second){
    return (hour >= 0 && hour <= 23) &&
           (minute >= 0 && minute <= 59) &&
           (second >= 0 && second <= 59);
}

void get_next_time(int& hour, int& minute, int& second,
                   int dhour, int dminute, int dsecond)
{
    dhour%=24;
    if (second + dsecond<60) second=(second+dsecond);
    else{
        second=(second+dsecond)-60;
        dminute++;
    }
    if (minute + dminute<60) minute=(minute+dminute);
    else{
        minute = (minute+dminute)-60;
        dhour++;
    } 
    if (hour + dhour<24) hour=hour+dhour;
    else hour=hour +dhour-24;
}
                   
void get_previous_time(int& hour, int& minute, int& second,
                       int dhour, int dminute, int dsecond)
{
    dhour%=24;
    if (second-dsecond>=0) second-=dsecond;
    else {
        second = second - dsecond + 60;
        dminute++;
    }
    if (minute - dminute>=0) minute-=dminute;
    else {
        minute = minute - dminute + 60;
        dhour++;
    }
    if (hour - dhour>=0) hour-=dhour;
    else {
        hour = hour - dhour +24;
    }
}

void get_segment_time(int phour, int pminute, int psecond,
                      int nhour, int nminute, int nsecond,
                      int& dhour, int& dminute, int& dsecond)
{
    dhour = nhour-phour;
    dminute = nminute - pminute;
    dsecond = nsecond - psecond;
    if (dsecond <0){
        dsecond+=60;
        dminute--;
    }
    if (dminute <0){
        dminute+=60;
        dhour--;
    }
    if (dhour<0) dhour+=24;
}


string convert_24_to_12(int hour, int minute, int second){
    string res = "";
    if (hour>=12){
        hour-=12;
        if (minute<10) res=to_string(hour)+":0"+to_string(minute);
        else res=to_string(hour)+":"+to_string(minute);
        if (second<10) res+=":0"+to_string(second)+" PM";
        else res +=":"+to_string(second)+" PM";
    } else {
        if (minute<10) res=to_string(hour)+":0"+to_string(minute);
        else res=to_string(hour)+":"+to_string(minute);
        if (second<10) res+=":0"+to_string(second)+" AM";
        else res +=":"+to_string(second)+" AM";
    }
    return res;
}

int convert_time_to_second(int hour, int minute, int second){
    return hour*60*60 + minute*60 + second;
}

void convert_second_to_time(int total_second,
                            int& hour, int& minute, int& second)
{
    
    hour = total_second/(60*60);
    minute = total_second/60 - hour*60;
    second = total_second - hour*60*60 - minute*60;
    if (hour==24) hour=0;
}