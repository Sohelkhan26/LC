class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false; // Cannot measure more than the total capacity
        if (target == 0) return true;    // Can always measure 0 liters

        set<pair<int, int>> vis;
        queue<pair<int, int>> q;
        q.push({0, 0});  // Start with both jugs empty
        vis.insert({0, 0});

        while (not q.empty()) {
            auto [a, b] = q.front();
            q.pop();

            if (a + b == target) return true;
            // if(a + b > target)continue;

            vector<pair<int, int>> temp = {
                {0, b},                 // Empty jug 1
                {a, 0},                 // Empty jug 2
                {x, b},                 // Fill jug 1
                {a, y},                 // Fill jug 2
                {min(x, a + b), b - (min(x, a + b) - a)}, // Pour jug 2 -> jug 1
                {a - (min(y, a + b) - b), min(y, a + b)}  // Pour jug 1 -> jug 2
            };

            for (auto [i, j] : temp) {
                if (not vis.contains({i, j})) {
                    q.push({i, j});
                    vis.insert({i, j});
                }
            }
        }

        return false; // If no solution is found
    }
};
