#include <iostream>
#include <cmath>


struct balloon
{
	int x;
	int y;
	int r;
};


int hit(int x, int y, int N, balloon arr[]) //counting shot down balloons 
{
	int shotdown = 0;
	if (x == 0 || y == 0)
	{
		for (int i = 0; i < N; i++)
		{

			if (x == 0)
			{

				if ((arr[i].y > 0 && y > 0) || (arr[i].y <0 && y<0))
				{
					if (arr[i].x < 0 && (arr[i].x + arr[i].r >= 0))
						shotdown++;
					if (arr[i].x > 0 && (arr[i].x - arr[i].r <= 0))
						shotdown++;
				}
			}
			if (y == 0)
			{
				if (arr[i].x > 0 && x > 0 || arr[i].x < 0 && x < 0)
				{
					if (arr[i].y < 0 && (arr[i].y + arr[i].r >= 0))
						shotdown++;
					if (arr[i].y > 0 && (arr[i].y - arr[i].r <= 0))
						shotdown++;
				}
			}
		}
	}
	else
	{
		float a = (static_cast<float>(y) / x);
		for (int i = 0; i < N; i++)
		{

			//rejecting balloons in opposite direction of shooting
			if (x >= 0 && y >= 0 && ((arr[i].x + arr[i].r < 0) || (arr[i].y + arr[i].r < 0))) continue;
			if (x <= 0 && y >= 0 && ((arr[i].x - arr[i].r > 0) || (arr[i].y + arr[i].r < 0))) continue;
			if (x <= 0 && y <= 0 && ((arr[i].x - arr[i].r > 0) || (arr[i].y - arr[i].r > 0))) continue;
			if (x >= 0 && y <= 0 && ((arr[i].x + arr[i].r < 0) || (arr[i].y - arr[i].r > 0))) continue;
			//collision finding
			if ((abs(a * arr[i].x - arr[i].y) / sqrt(a * a + 1)) <= arr[i].r)
				shotdown++;
		}
	}
	return shotdown;
}

int main()
{
	int T;

	std::cin >> T; //numbers of tests (not needed for the algorithm)
	
	for (int i = 0; i < T; i++)
	{
		int N, x, y;
		std::cin >> N >> x >> y;

		balloon *arr = new balloon[N]; //array with balloons coordinates
		for (int i = 0; i < N; i++) //filling array with coordinates
		{
			std::cin >> arr[i].x >> arr[i].y >> arr[i].r;
		}
		std::cout << hit(x, y, N, arr) << std::endl;
		delete[] arr;

	}
	
}