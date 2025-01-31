class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // If there are no intervals, return an empty list
        if (intervals.empty()) return {};

        // Sort intervals by the start of each interval
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]); // Start with the first interval

        for (int i = 1; i < intervals.size(); ++i) {
            // Get the last added interval in the merged list
            vector<int>& last = merged.back();

            // If the current interval overlaps with the last one
            if (intervals[i][0] <= last[1]) {
                // Merge the intervals by updating the end of the last interval
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap, add the current interval to the merged list
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};
