//Back-end complete function template for C++
class Solution{
public:
	int maxSortedAdjacentDiff(int* arr, int n) {
	    if (n < 2) return 0;
	    // Find maximum and minimum in arr[]
	    int maxVal = arr[0], minVal = arr[0];
	    for (int i = 1; i < n; i++) {
	        maxVal = max(maxVal, arr[i]);
	        minVal = min(minVal, arr[i]);
	    }

	    // bucket size
	    int bSize = max(1, (maxVal - minVal) / (n - 1));
	    // number of buckets
	    int bNum = (maxVal - minVal) / bSize + 1;

	    // Arrays to store maximum and minimum values
	    // in bNum buckets of differences.
	    int maxBucket[bNum];
	    int minBucket[bNum];
	    fill_n(maxBucket, bNum, INT_MIN);
	    fill_n(minBucket, bNum, INT_MAX);

	    // Traversing through array elements and
	    // filling in appropriate bucket if bucket
	    // is empty. Else updating bucket values.
	    for (int i = 0; i < n; i++) {
	        if (arr[i] == maxVal || arr[i] == minVal) continue;

	        // Finding index of bucket.
	        int index = (float)(floor(arr[i] - minVal) / bSize);

	        // Filling/Updating maximum value of bucket
	        if (maxBucket[index] == INT_MIN)
	            maxBucket[index] = arr[i];
	        else
	            maxBucket[index] = max(maxBucket[index], arr[i]);

	        // Filling/Updating minimum value of bucket
	        if (minBucket[index] == INT_MAX)
	            minBucket[index] = arr[i];
	        else
	            minBucket[index] = min(minBucket[index], arr[i]);
	    }

	    // Finding maximum difference between maximum value
	    // of previous bucket minus minimum of current bucket.
	    int prev_val = minVal;
	    int max_gap = 0;
	    for (int i = 0; i < bNum; i++) {
	        if (minBucket[i] == INT_MAX) continue;
	        max_gap = max(max_gap, minBucket[i] - prev_val);
	        prev_val = maxBucket[i];
	    }
	    max_gap = max(max_gap, maxVal - prev_val);

	    return max_gap;
	}
};