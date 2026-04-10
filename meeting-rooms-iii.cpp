#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // Free rooms: smallest room number first
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int room = 0; room < n; ++room) {
            availableRooms.push(room);
        }

        // Busy rooms: {endTime, roomNumber}
        // earliest end time first, and if tie then smaller room number first
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busyRooms;

        vector<long long> meetingCount(n, 0);

        for (const auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;
            cout<< "start: "<< start<< ", end: "<<end<<endl;

            // Release every room that became free by meeting start time
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                int freedRoom = busyRooms.top().second;
                cout<< "freedRoom: " << freedRoom <<endl;
                busyRooms.pop();
                availableRooms.push(freedRoom);
            }

            if (!availableRooms.empty()) {
                // Use the smallest available room
                int room = availableRooms.top();
                cout<< "available room: " << room << endl;
                availableRooms.pop();

                busyRooms.push({end, room});
                meetingCount[room]++;
            } else {
                cout<< "no room is free. ";
                // No room is free: delay meeting to earliest available room
                auto [freeTime, room] = busyRooms.top();
                busyRooms.pop();

                long long newEnd = freeTime + duration;
                busyRooms.push({newEnd, room});
                meetingCount[room]++;
                cout<< " New end: " << newEnd <<endl;
    
            }
        }

        int answer = 0;
        for (int room = 1; room < n; ++room) {
            if (meetingCount[room] > meetingCount[answer]) {
                answer = room;
            }
        }

        return answer;
    }
};

int main() {
    Solution sol;

    // Example 1
    int n1 = 2;
    vector<vector<int>> meetings1 = {
        {0, 10},
        {1, 5},
        {2, 7},
        {3, 4}
    };

    int result1 = sol.mostBooked(n1, meetings1);
    cout << "Example 1 result: " << result1 << endl;   // Expected: 0

    // Example 2
    int n2 = 3;
    vector<vector<int>> meetings2 = {
        {1, 20},
        {2, 10},
        {3, 5},
        {4, 9},
        {6, 8}
    };

    int result2 = sol.mostBooked(n2, meetings2);
    cout << "Example 2 result: " << result2 << endl;   // Expected: 1

    return 0;
}