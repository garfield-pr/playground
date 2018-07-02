#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <thread>
#include <mutex>


void calcpi(const long long N, long long &hits, std::mutex &mutex, const int seed)
{
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> distribution(0,1.0);
	// fixme
	// std::mutex m;
	for (long long i = 0; i < N; ++i)
	{
		double x = distribution(generator); // fixme
		double y = distribution(generator); // fixme
		if (std::sqrt(x*x + y*y) <= 1){
			mutex.lock();
			++hits;
			mutex.unlock();
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
	
	for (std::thread & t : threads)
		t.join();
	// fixme

	const double V = 2*2;
	long double my_PI = (V * hits) / N;
	std::cout << std::fixed
		<< "\t" << std::setprecision(10) << my_PI
		<< "\t" << "3.141592653589793" << std::endl;
	return 0;
}
