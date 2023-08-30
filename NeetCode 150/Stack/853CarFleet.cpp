class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleet = 0;
        int n = position.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double timeToGetThere = (double) (target - position[i]) / speed[i];
            cars.push_back({position[i], timeToGetThere});
        }
        // sort by starting position
        sort(cars.begin(), cars.end());

        double maxTime = 0;
        for (int i = n-1; i >= 0; i--) {
            // 如果后面的A想要追上前面的B，那么A的速度必须大于B，反之fleet++
            if (cars[i].second > maxTime) {
                maxTime = cars[i].second;
                fleet++;
            }
        }
        return fleet;
    }
};
