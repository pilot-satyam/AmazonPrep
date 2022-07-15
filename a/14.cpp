int countRotation(int arr[],int low,int high)
{
    int low = 0, high = n - 1;
    while (low <= high) {
 
        // if first element is mid or
        // last element is mid
        // then simply use modulo so it
        // never goes out of bound.
        int mid = low + (high - low) / 2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;
 
        if (arr[mid] <= arr[prev]
            && arr[mid] <= arr[next])
            return mid;
        else if (arr[mid] <= arr[high])
            high = mid - 1;
        else if (arr[mid] >= arr[low])
            low = mid + 1;
    }
    return 0;
}
