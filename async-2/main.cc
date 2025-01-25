#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <thread>

// Do some work.
std::string do_work(int dt) {
  using namespace std::chrono_literals;
  auto time = 1s * dt;
  std::this_thread::sleep_for(time); // Simulate a time-consuming work
  return "Hello from std::async! (worked for " + std::to_string(dt) + " s)";
}

int main() {
  // launch do_work() in two separate threads
  auto future_result1 = std::async(std::launch::async, do_work, 1);
  auto future_result2 = std::async(std::launch::async, do_work, 2);

  std::cout << "Main thread is free execute while do_work() runs...\n";

  // thread1 will finish first, then thread2
  std::string result1 = future_result1.get();
  std::cout << "Result from background thread1: " << result1 << "\n";

  std::string result2 = future_result2.get();
  std::cout << "Result from background thread2: " << result2 << "\n";

  return 0;
}