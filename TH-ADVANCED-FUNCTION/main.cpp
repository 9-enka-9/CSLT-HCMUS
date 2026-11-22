#include "time_utils.h"
using namespace std;

int main(){
    int hour,minute,second;
    
    cout<<is_valid_time(0,30,11)<<endl;
    hour = 0; minute = 20; second=45;
    get_next_time(hour, minute, second, 1, 10, 35);
    cout<<hour<<" "<<minute<<" "<<second<<endl;
    
    hour = 1; minute = 31; second=20;
    get_previous_time(hour,minute,second, 1, 10, 35);
    cout<<hour<<" "<<minute<<" "<<second<<endl;
    
    get_segment_time(23, 10, 30,0, 10, 0, hour,minute,second);
    cout<<hour<<" "<<minute<<" "<<second<<endl;
    
    cout<<convert_24_to_12(23 ,10, 0)<<endl;
    
    cout<<convert_time_to_second(0,30,10)<<endl;
    
    convert_second_to_time(1810, hour,minute,second);
    cout<<hour<<" "<<minute<<" "<<second<<endl;
}