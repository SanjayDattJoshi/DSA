//Problem - 12 --> Matrix traversal
vector<int> spiral_traversal(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
vector<int>result;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            result.push_back(arr[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            result.push_back(arr[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                result.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                result.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return result;
}
