// Problem - 12 --> Maximum consicutive 1's in an array of 0 and 1.
int max_ones(int arr[], int n)
{
    int count = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            maxi = max(count, maxi);
        }
        else
        {
            count = 0;
        }
    }

    return maxi;
}
