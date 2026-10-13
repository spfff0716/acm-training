#include <bits/stdc++.h>
using namespace std;

long long getceil(long long a, long long b)
{
	return (a + b - 1) / b;
}

pair<long long, long long> solve_deuce(
	long long start,
	long long ending,
	long long a,
	long long b)
{
	if(a == 0)
	{
		return {0, 0};
	}

	long long min1 = 0;
	long long max1 = 0;

	if(ending == 2)
	{
		max1 = min(a, 3LL);
	}
	else
	{
		max1 = min(a, 2LL);
	}

	if(ending == 2)
	{
		if(start == 1 && a == 1)
		{
			min1 = 1;
		}
		else if(start == -1 && b == 0)
		{
			min1 = 3;
		}
		else
		{
			min1 = 2;
		}
	}
	else if(start == -1 && ending == 1)
	{
		min1 = 2;
	}
	else
	{
		min1 = 1;
	}

	return {min1, max1};
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while(t--)
	{
		int k, x1, y1, x2, y2;
		cin >> k >> x1 >> y1 >> x2 >> y2;

		int max1 = 0;
		int min1 = 0;

		int d1 = x2 - x1;
		int d2 = y2 - y1;

		int ending = x2 - y2;

		if(max(x1, y1) >= k)
		{
			pair<long long, long long> result =
				solve_deuce(x1 - y1, ending, d1, d2);

			min1 = result.first;
			max1 = result.second;
		}
		else if(max(x2, y2) < k)
		{
			max1 = d1;
			min1 = getceil(d1, d2 + 1);
		}
		else if(max(x2, y2) == k && abs(x2 - y2) >= 2)
		{
			max1 = d1;

			if(x2 > y2)
			{
				min1 = getceil(d1, d2 + 1);
			}
			else
			{
				min1 = getceil(d1, d2);
			}
		}
		else
		{
			min1 = INT_MAX;
			max1 = 0;

			if(k >= x1 &&
			   k - 1 >= y1 &&
			   k <= x2 &&
			   k - 1 <= y2)
			{
				int before_d1 = k - x1;
				int before_d2 = k - 1 - y1;

				int after_d1 = x2 - k;
				int after_d2 = y2 - (k - 1);

				pair<long long, long long> result =
					solve_deuce(
						1,
						ending,
						after_d1,
						after_d2
					);

				int now_min1 = 0;
				int now_max1 = 0;

				if(after_d1 == 1 &&
				   after_d2 == 0 &&
				   ending == 2)
				{
					now_min1 = max(
						2LL,
						getceil(before_d1 + 1, before_d2 + 1)
					);

					now_max1 = before_d1 + 1;
				}
				else
				{
					int before_min1 =
						getceil(before_d1, before_d2 + 1);

					int before_max1 = before_d1;

					now_min1 = max(
						(long long)before_min1,
						result.first
					);

					now_max1 = max(
						(long long)before_max1,
						result.second
					);
				}

				min1 = min(min1, now_min1);
				max1 = max(max1, now_max1);
			}

			if(k - 1 >= x1 &&
			   k >= y1 &&
			   k - 1 <= x2 &&
			   k <= y2)
			{
				int before_d1 = k - 1 - x1;
				int before_d2 = k - y1;

				int after_d1 = x2 - (k - 1);
				int after_d2 = y2 - k;

				pair<long long, long long> result =
					solve_deuce(
						-1,
						ending,
						after_d1,
						after_d2
					);

				int before_min1 = 0;

				if(before_d1 == 0)
				{
					before_min1 = 0;
				}
				else
				{
					before_min1 =
						getceil(before_d1, before_d2);
				}

				int before_max1 = before_d1;

				int now_min1 = max(
					(long long)before_min1,
					result.first
				);

				int now_max1 = max(
					(long long)before_max1,
					result.second
				);

				min1 = min(min1, now_min1);
				max1 = max(max1, now_max1);
			}
		}

		cout << min1 << ' ' << max1 << '\n';
	}

	return 0;
}
