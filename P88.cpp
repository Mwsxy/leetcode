#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
	{
		int i = 0, j = 0;
		while (i < m && j < n)
		{
			if (nums1[i]<=nums2[j])
				i++;
			else {
				int t=nums1[i];
				nums1[i]=nums2[j];
				int k=j;
				while (k+1<n && nums2[k+1]<t) {
					nums2[k]=nums2[k+1];
					k++;
				}
				nums2[k]=t;				
			}
			
		}
		// for (i = 0; i < m; i++)
		// 	cout << nums1[i] << " ";
		// cout << endl;
		// for (j = 0; j < n; j++)
		// 	cout << nums2[j] << " ";
		// cout << endl;
		for (j = 0; j < n; j++)
			nums1[m + j] = nums2[j];
		return;
	}
};

int main() {
	vector<int> a={4,7,0,0,0,0,0};
	vector<int> b={1,2,3,5,6};
	int m=a.size();
	int n=b.size();
	Solution().merge(a,m-n,b,n);
	int i;
	for (i = 0; i < m; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
