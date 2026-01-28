// Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

// A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

// Note that points on the edge of a vertical area are not considered included in the area.

 

// Example 1:

// ​
// Input: points = [[8,7],[9,9],[7,4],[9,7]]
// Output: 1
// Explanation: Both the red and the blue area are optimal.
// Example 2:

// Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
// Output: 3









// Github code but not optimal solution

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            ans = max(ans, points[i + 1][0] - points[i][0]);
        }
        return ans;
    }
};








// Leetcode optimal solution

static const int _ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    struct Bucket
    {
        int min = INT_MAX;
        int max = -1;
        void add( int num )
        {
            min = std::min( min, num );
            max = std::max( max, num );
        }
    };

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {

        int min_val = INT_MAX;
        int max_val = -1;
        for( auto& point : points )
        {
            min_val = std::min( min_val, point[ 0 ] );
            max_val = std::max( max_val, point[ 0 ] );
        }

        if( min_val == max_val )
        {
            return 0;
        }

        // Need to handle the worst case where the input is evenly spread out
        // the worst case with points.size() buckets is 1 number per bucket which we can handle
        size_t num_buckets = points.size();

        // Get the bucket width, round up to handle the last bucket
        const int bucket_width = ( max_val - min_val + ( num_buckets - 1 ) ) / num_buckets;

        // Add a bucket if we didnt round up, since max / num_buckets will overflow the vector
        num_buckets += bucket_width == ( max_val - min_val ) / num_buckets;


        // Insert all the x points into the buckets, the bucket class will get the min/max per bucket
        std::vector<Bucket> buckets( num_buckets );
        for( auto& point : points )
        {
            int bucket_id = ( point[ 0 ] - min_val ) / bucket_width;
            buckets[ bucket_id ].add( point[ 0 ] );
        }

        // Iterate and find the biggest differnece between two buckets
        int prev_max = buckets[ 0 ].max;
        int res = 0;
        for( uint32_t i = 1; i < num_buckets; ++i )
        {
            auto& bucket = buckets[ i ];
            if( bucket.min == INT_MAX )
            {
                continue;
            }

            res = std::max( res, bucket.min - prev_max );
            prev_max = bucket.max;
        }


        return res;
    }
};