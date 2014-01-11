/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(!points.size()) return 0;
        map<int, map<float, int> >  p2slope2cnt;
        
        int maxNum, totalMax = 1, infSlope, overlap;
        for(int i = 0; i < points.size(); i++){
            maxNum = 1;
            infSlope = 1;
            overlap = 0;
            for(int j = 0; j < points.size(); j++){
                if(i != j){
                    if(points[j].y - points[i].y == 0 && points[j].x - points[i].x == 0){
                        overlap++;
                    }else if(points[j].y - points[i].y){
                        float slope = (float)(points[j].x - points[i].x)/(points[j].y - points[i].y);
                        if(p2slope2cnt[i].find(slope) == p2slope2cnt[i].end())
                            p2slope2cnt[i][slope] = 2;
                        else
                            p2slope2cnt[i][slope]++;
                        maxNum = max(maxNum, p2slope2cnt[i][slope]);
                    }else{
                        infSlope++;
                        maxNum = max(maxNum, infSlope);
                    }
                }
            }
            totalMax = max(maxNum + overlap, totalMax);
        }
        
        return totalMax;
    }
};

/*
carefule when converting int to float
*/