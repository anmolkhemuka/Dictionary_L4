#include <iostream>
#include <unordered_map>
using namespace std;
/**
 * @brief To find the lomgest subarray with given sum
 * 
 */
int main()
{
      clock_t t;
  t = clock();

    int n;
    cin >> n;
    int a[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int st, end;
    int k;
    cin >> k;
    int sum = 0;
    int len = 0;
    /**
     * @brief Unordered to map store the cumulative sum of array
     * 
     */
    unordered_map<int, int> mp;
    for (size_t i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == k)
        {
            len = i + 1;
            st = 0;
            end = i;
        }

        if (mp.find(sum) == mp.end())
            mp[sum] = i;
        if (mp.find(sum - k) != mp.end())
        {
            if ((mp[sum] - mp[sum - k]) > len)
            {
                len = mp[sum] - mp[sum - k];
                st = mp[sum - k] + 1;
                end = i;
            }
        }
    }
    /**
     * @brief Checking whether a valid subarray is found or not
     * 
     */
    if(len!=0){
    cout << "Length of the longest subarray is " << len << endl;
    cout << "Index from " << st << " to " << end << endl;}
    else
    cout<<"Not Found\n";
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC;
  printf("\ntotal execution time:%f seconds", time_taken);
    return 0;
}
