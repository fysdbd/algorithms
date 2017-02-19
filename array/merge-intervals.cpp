
/*
	Merge Intervals
	
	Given a collection of intervals, merge all overlapping intervals.

	For example,
	Given [1,3],[2,6],[8,10],[15,18],
	return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool compare(const Interval& i1, const Interval& i2) {
        return i1.start < i2.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        using namespace std::placeholders;
        sort(intervals.begin(), intervals.end(), std::bind(&Solution::compare, this, _1, _2));
        
		vector<Interval> result;
        for (auto interval : intervals) {
            if (result.empty() || result.back().end < interval.start) {
                result.push_back(interval);
            } else {
                result.back().end = std::max(result.back().end, interval.end);
            }
        }
        return result;
    }
};
