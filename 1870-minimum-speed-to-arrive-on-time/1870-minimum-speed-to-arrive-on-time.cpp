class Solution {
public:

    bool canReach(vector<int>& dist, double hour, int speed) {

        double totalTime = 0;

        int n = dist.size();

        // Last journey se pehle sab round up honge
        for (int i = 0; i < n - 1; i++) {

            totalTime += ceil((double)dist[i] / speed);

            // Optimization
            if (totalTime > hour) {
                return false;
            }
        }

        // Last journey ko round up nahi karna
        totalTime += (double)dist[n - 1] / speed;

        return totalTime <= hour;
    }


    int minSpeedOnTime(vector<int>& dist, double hour) {

        int low = 1;
        int high = 10000000;

        int answer = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canReach(dist, hour, mid)) {

                answer = mid;

                // Smaller speed try karo
                high = mid - 1;

            } else {

                // Speed badhao
                low = mid + 1;
            }
        }

        return answer;
    }
};