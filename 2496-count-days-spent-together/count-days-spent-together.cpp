class Solution {
public:
int findDay(string date,vector<int>&monthsDays){
    int month= stoi(date.substr(0,2));
    int days= stoi(date.substr(3));

    return monthsDays[month-1]+days;

}

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>months={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        vector<int>monthsDays(12);
        monthsDays[0]=31;
        for(int i=1;i<12;i++){
            monthsDays[i]= monthsDays[i-1]+months[i-1];
        }
        int arriveAliceDay= findDay(arriveAlice,monthsDays);
        int leaveAliceDay= findDay(leaveAlice,monthsDays);
        int arriveBobDay=findDay(arriveBob,monthsDays);
        int leaveBobDay=findDay(leaveBob,monthsDays);

int ans= min(leaveAliceDay,leaveBobDay)-max(arriveAliceDay,arriveBobDay)+1;
   return ans<0?0:ans;


        
    }
};