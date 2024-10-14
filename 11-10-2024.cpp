#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        // Create a list of arrivals with friend index for tracking
        std::vector<std::pair<int, int>> arrivals;
        for (int i = 0; i < n; ++i) {
            arrivals.push_back({times[i][0], i});
        }
        
        // Sort friends based on their arrival time
        std::sort(arrivals.begin(), arrivals.end());
        
        // Min-Heap to track available chairs
        std::priority_queue<int, std::vector<int>, std::greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i); // All chairs start as available
        }

        // Priority queue to track when chairs are freed
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> leavingQueue;
        
        // Iterate through each friend based on arrival
        for (auto& arrival : arrivals) {
            int arrivalTime = arrival.first;
            int friendIndex = arrival.second;
            
            while (!leavingQueue.empty() && leavingQueue.top().first <= arrivalTime) {
                availableChairs.push(leavingQueue.top().second);
                leavingQueue.pop();
            }
            
            int chair = availableChairs.top();
            availableChairs.pop();
            
            if (friendIndex == targetFriend) {
                return chair;
            }
            
            leavingQueue.push({times[friendIndex][1], chair});
        }
        
        return -1;
    }
};