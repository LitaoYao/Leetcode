// https://leetcode-cn.com/problems/k-th-smallest-prime-fraction/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Frac {
	Frac(int _i, int _j, vector<int>& arr): i(_i), j(_j), arr(arr) {}
	bool operator < (const Frac& other)
	{
		return arr[i] * arr[other.j] < arr[other.i] * arr[j];
	}
	int i;
	int j;
	vector<int>& arr;
};

class Solution {
public:
	void push(vector<Frac*>& heap, int& tail, Frac* frac)
	{
		heap[tail] = frac;
		shift_up(heap, tail);
		tail += 1;
	}

	void pop(vector<Frac*>& heap, int& tail)
	{
		heap[0] = heap[tail - 1];
		tail -= 1;
		shift_down(heap, 0, tail);
	}

	void shift_up(vector<Frac*>& heap, int tail)
	{
		Frac* tmp = heap[tail];
		while(tail > 0 && *tmp < *heap[(tail - 1) >> 1])
		{
			heap[tail] = heap[(tail - 1) >> 1];
			tail = (tail - 1) >> 1;
		}
		heap[tail] = tmp;
	}

	void shift_down(vector<Frac*>& heap, int cnt, int tail)
	{
		Frac* tmp = heap[cnt];
		while(2 * cnt + 1 < tail)
		{
			int left = 2 * cnt + 1;
			int right = left + 1;
			int child = left;
			if(right < tail && *heap[right] < *heap[left])
			{
				child = right;
			}
			if(*tmp < *heap[child])
			{
				break;
			}
			heap[cnt] = heap[child];
			cnt = child;
		}
		heap[cnt] = tmp;
	}
	vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
		int n = arr.size();
		vector<Frac*> heap(n, nullptr);
		int heap_tail = 0;
		for(int i = 1; i < n; ++i)
		{
			push(heap, heap_tail, new Frac(0, i, arr));
		}
		while(k > 1)
		{
			Frac* x = heap[0];
			pop(heap, heap_tail);
			--k;
			if(x->i + 1 < x->j)
			{
				push(heap, heap_tail, new Frac(x->i + 1, x->j, arr));
			}
		}
		Frac* ans = heap[0];
		return vector<int>({arr[ans->i], arr[ans->j]});
	}
};

int main()
{
	vector<int> arr = vector<int>({1, 29, 47});
	int k = 1;
	vector<int> ans = Solution().kthSmallestPrimeFraction(arr, k);
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}
