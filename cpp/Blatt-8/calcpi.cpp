#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <thread>
#include <mutex>


void calcpi(const long long N, long long &hits, std::mutex &mutex, const int seed)
{
	// fixme
	for (long long i = 0; i < N; ++i)
	{
		double x = 0; // fixme
		double y = 0; // fixme
		if (std::sqrt(x*x + y*y) <= 1){
			++hits;
		}
	}
}

int main(int argc, char **argv)
{
	std::mutex mutex;
	const long long N = 1e7;
	long long hits = 0;

	int num_threads = 4;
	if (argc == 2) {
		num_threads = std::stoi(argv[1]);  // lese int von der kommandozeile - z.B. ./calcpi.bin 6
	}
	std::vector<std::thread> threads;
	for (int i = 0; i < num_threads; ++i) {
		threads.push_back(std::thread(calcpi, N / num_threads, std::ref(hits), std::ref(mutex), i + 100));
	}
	// fixme

	const double V = 2*2;
	long double my_PI = (V * hits) / N;
	std::cout << std::fixed
		<< "\t" << std::setprecision(10) << my_PI
		<< "\t" << "3.141592653589793" << std::endl;
	return 0;
}
