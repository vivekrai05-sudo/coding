class Solution {
public:

    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {

        int flowers = 0;
        int bouquets = 0;

        for (int bloom : bloomDay) {

            // Flower bloom ho gaya
            if (bloom <= day) {

                flowers++;

                // k adjacent flowers mil gaye
                if (flowers == k) {

                    bouquets++;

                    // Flowers used ho gaye
                    flowers = 0;
                }

            } 
            else {

                // Adjacency break ho gayi
                flowers = 0;
            }
        }

        return bouquets >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        // Impossible case
        if ((long long)m * k > n)
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());

        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int answer = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {

                answer = mid;

                // Aur smaller day try karo
                high = mid - 1;

            } else {

                // More flowers bloom hone chahiye
                low = mid + 1;
            }
        }

        return answer;
    }
};