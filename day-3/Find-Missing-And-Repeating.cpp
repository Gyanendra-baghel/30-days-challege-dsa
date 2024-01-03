class Solution {
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int> result(2);

        // Finding the repeating element
        for (int i = 0; i < n; i++) {
            if (arr[abs(arr[i]) - 1] > 0) {
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            } else {
                result[0] = abs(arr[i]);
            }
        }

        // Finding the missing element
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                result[1] = i + 1;
                break;
            }
        }

        return result;
    }
}