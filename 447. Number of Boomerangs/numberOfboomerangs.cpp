class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int totalBoomerangs = 0;
        for (auto& centerPoint : points) {
            unordered_map<int, int> distances;

            for (auto& targetPoint : points) {
                int squaredDistance = (centerPoint[0] - targetPoint[0]) * (centerPoint[0] - targetPoint[0]) +
                                      (centerPoint[1] - targetPoint[1]) * (centerPoint[1] - targetPoint[1]);

                totalBoomerangs += distances[squaredDistance];
                distances[squaredDistance]++;
            }
        }

        return totalBoomerangs << 1;
    }
};