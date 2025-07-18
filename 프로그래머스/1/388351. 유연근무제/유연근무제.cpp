#include <string>
#include <vector>

using namespace std;

int add10(int time) {
    int hour = time / 100;
    int minute = time % 100;
    minute += 10;
    if (minute >= 60){
        hour += 1;
        minute -= 60;
    }
    return hour * 100 + minute;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    for(int i = 0; i < schedules.size(); i++){
        int day = startday;
        int attendance = 0;
        int target_time = add10(schedules[i]);
        
        for(int j = 0; j < timelogs[i].size(); j++){
            int today = (day + j - 1) % 7 + 1;
            if((today % 7 == 6) || (today % 7 == 0)){
                continue;
            }
            else{
                if(timelogs[i][j] <= target_time){
                    attendance += 1;
                }
            }
        }
        
        if(attendance >= 5){
            answer += 1;
        }
    }
    return answer;
}