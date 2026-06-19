// Asteroid Collisions
vector<int> asteroidCollision(vector<int> arr)
{
    int n = arr.size();
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            result.push_back(arr[i]);
        else
        {
            while (!result.empty() && result.back() > 0 &&
                   result.back() < abs(arr[i]))
                result.pop_back();

            if (!result.empty() && result.back() == abs(arr[i]))
                result.pop_back();

            else if (result.empty() || result.back() < 0)
                result.push_back(arr[i]);
        }
    }
    return result;
}
