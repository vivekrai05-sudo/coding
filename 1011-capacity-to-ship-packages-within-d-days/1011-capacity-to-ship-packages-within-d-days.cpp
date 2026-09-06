class Solution {
public:

    int requiredDays(vector<int>& weights, int capacity) {

        int days = 1;
        int currentWeight = 0;

        for (int weight : weights) {

            // Same day me package fit ho raha hai
            if (currentWeight + weight <= capacity) {
                currentWeight += weight;
            }

            // New day start karna padega
            else {
                days++;
                currentWeight = weight;
            }
        }

        return days;
    }


    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());

        int high = 0;

        for (int weight : weights) {
            high += weight;
        }

        int answer = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int required = requiredDays(weights, mid);

            if (required <= days) {

                // Capacity kaam kar rahi hai
                answer = mid;

                // Aur minimum capacity check karo
                high = mid - 1;

            } else {

                // Zyada days lag rahe hain
                // Capacity badhao
                low = mid + 1;
            }
        }

        return answer;
    }
};