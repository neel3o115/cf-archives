#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// Helper function to solve the "Largest Rectangle in Histogram" problem.
// Returns the maximum area calculated as (height + 2) * (width + 2)
// because a rectangle of 1s in the auxiliary matrix corresponds to 
// a (h+2)x(w+2) arithmetic rectangle in the original grid.
long long max_area_plot(const vector<int>& heights) {
    long long max_a = 0;
    stack<int> s;
    int m = heights.size();
    
    // Iterate through all bars, plus a fictional zero-height bar at the end
    for (int i = 0; i <= m; ++i) {
        int h = (i == m ? 0 : heights[i]);
        while (!s.empty() && heights[s.top()] >= h) {
            int height = heights[s.top()];
            s.pop();
            // Width is the distance between current index and the new top of stack
            int width = (s.empty() ? i : i - s.top() - 1);
            if (height > 0 && width > 0)
                max_a = max(max_a, (long long)(height + 2) * (width + 2));
        }
        s.push(i);
    }
    return max_a;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    // Use vector of vectors for the grid. 
    // Grid values can be up to 10^9, so we use int. 
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    // Basic base cases
    long long ans = 0;
    if (n * m > 0) ans = 1; // At least one cell
    if (n >= 1 && m >= 2) ans = max(ans, 2LL); // 1x2
    if (n >= 2 && m >= 1) ans = max(ans, 2LL); // 2x1
    if (n >= 2 && m >= 2) ans = max(ans, 4LL); // 2x2 is always arithmetic if rows/cols are APs, checked below

    // --- STEP 1: Process Rows (1xK and 2xK) ---
    
    // row_ap[i][j] stores the length of the arithmetic progression in row 'i' ending at index 'j'
    // We use 'unsigned short' to save memory (3000 fits in short).
    vector<vector<unsigned short>> row_ap(n, vector<unsigned short>(m, 1));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (j == 1) {
                row_ap[i][j] = 2;
            } else {
                long long d1 = (long long)grid[i][j] - grid[i][j-1];
                long long d2 = (long long)grid[i][j-1] - grid[i][j-2];
                if (d1 == d2) row_ap[i][j] = row_ap[i][j-1] + 1;
                else row_ap[i][j] = 2;
            }
            // Update answer for 1xK (Single row max length)
            ans = max(ans, (long long)row_ap[i][j]);
        }
    }

    // Check 2xK (Two adjacent rows)
    // A 2xK rect is valid if row i and row i+1 are both APs in that range.
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            int len = min(row_ap[i][j], row_ap[i+1][j]);
            ans = max(ans, (long long)len * 2);
        }
    }

    // --- STEP 2: Process Columns (Kx1 and Kx2) ---
    
    // col_ap[i][j] stores the length of AP in column 'j' ending at row 'i'
    vector<vector<unsigned short>> col_ap(n, vector<unsigned short>(m, 1));
    
    for (int j = 0; j < m; ++j) {
        for (int i = 1; i < n; ++i) {
            if (i == 1) {
                col_ap[i][j] = 2;
            } else {
                long long d1 = (long long)grid[i][j] - grid[i-1][j];
                long long d2 = (long long)grid[i-1][j] - grid[i-2][j];
                if (d1 == d2) col_ap[i][j] = col_ap[i-1][j] + 1;
                else col_ap[i][j] = 2;
            }
            // Update answer for Kx1 (Single column max length)
            ans = max(ans, (long long)col_ap[i][j]);
        }
    }

    // Check Kx2 (Two adjacent columns)
    for (int j = 0; j < m - 1; ++j) {
        for (int i = 0; i < n; ++i) {
            int len = min(col_ap[i][j], col_ap[i][j+1]);
            ans = max(ans, (long long)len * 2);
        }
    }

    // --- STEP 3: Process 3x3 and larger (The Plot Reduction) ---
    
    if (n >= 3 && m >= 3) {
        // Heights array for the histogram problem. 
        // Represents the consecutive 1s in the vertical direction of the auxiliary matrix.
        vector<int> heights(m - 2, 0); 
        
        // Iterate through the centers of possible 3x3 squares
        // Center (i, j) corresponds to grid[i][j]. 
        // i goes from 1 to n-2, j goes from 1 to m-2.
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                bool ok = true;
                
                // Check if rows i-1, i, i+1 form APs of length at least 3 centered at j
                // This corresponds to row_ap[r][j+1] >= 3
                if (row_ap[i-1][j+1] < 3) ok = false;
                else if (row_ap[i][j+1] < 3) ok = false;
                else if (row_ap[i+1][j+1] < 3) ok = false;
                
                // Check if cols j-1, j, j+1 form APs of length at least 3 centered at i
                // This corresponds to col_ap[i+1][c] >= 3
                if (ok) {
                   if (col_ap[i+1][j-1] < 3) ok = false;
                   else if (col_ap[i+1][j] < 3) ok = false;
                   else if (col_ap[i+1][j+1] < 3) ok = false;
                }

                // If 3x3 is valid, increment histogram height, otherwise reset
                if (ok) heights[j-1]++;
                else heights[j-1] = 0;
            }
            // Calculate max area for the current row of the auxiliary matrix
            ans = max(ans, max_area_plot(heights));
        }
    }

    cout << ans << "\n";
}

int main() {
    // Fast I/O is critical for large inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}