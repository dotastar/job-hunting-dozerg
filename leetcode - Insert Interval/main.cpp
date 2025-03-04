#include "..\inc.h"
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.empty())
            return vector<Interval>(1, newInterval);
        //find first overlap
        int f = 0, c = intervals.size();
        while(c > 0){
            int m = c / 2;
            if(intervals[f + m].end < newInterval.start){
                f += m + 1;
                c -= m + 1;
            }else
                c = m;
        }
        //combine intervals
        vector<Interval> r;
        if(f > 0)
            r.assign(intervals.begin(), intervals.begin() + f);
        if(f < int(intervals.size())){
            if(newInterval.end < intervals[f].start){
                c = f;
            }else{
                newInterval.start = min(newInterval.start, intervals[f].start);
                for(c = f;c < int(intervals.size());++c)
                    if(intervals[c].start > newInterval.end)
                        break;
                newInterval.end = max(newInterval.end, intervals[c - 1].end);
            }
            r.push_back(newInterval);
            if(c < int(intervals.size()))
                r.insert(r.end(), intervals.begin() + c, intervals.end());
        }else
            r.push_back(newInterval);
        return r;
    }
};

class Solution2 {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        const size_t f = help(intervals, 0, intervals.size(), newInterval.start);
        vector<Interval> ret(intervals.begin(), intervals.begin() + f);
        if(f < intervals.size())
            newInterval.start = min(newInterval.start, intervals[f].start);
        size_t t = help(intervals, f, intervals.size() - f, newInterval.end);
        if(t < intervals.size() && intervals[t].start <= newInterval.end)
            newInterval.end = max(newInterval.end, intervals[t++].end);
        ret.push_back(newInterval);
        ret.insert(ret.end(), intervals.begin() + t, intervals.end());
        return ret;
    }
    size_t help(const vector<Interval> & intervals, size_t from, size_t len, int val){
        while(len){
            size_t mid = len / 2;
            if(val <= intervals[from + mid].end){
                len = mid;
            }else{
                from += mid + 1;
                len -= mid + 1;
            }
        }
        return from;
    }
};

int main()
{
    {
        vector<Interval> v;
        v.push_back(Interval(1,3));
        v.push_back(Interval(6,9));
        //print(Solution().insert(v, Interval(2,5)));
    }{
        vector<Interval> v;
        v.push_back(Interval(1,2));
        v.push_back(Interval(3,5));
        v.push_back(Interval(6,7));
        v.push_back(Interval(8,10));
        v.push_back(Interval(12,16));
        //print(Solution().insert(v, Interval(4,9)));
    }{
        vector<Interval> v;
        v.push_back(Interval(1,5));
        //print(Solution().insert(v, Interval(0,0)));
    }
}