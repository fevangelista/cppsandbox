#include <chrono>
#include <future>
#include <iostream>
#include <string>

// do some work in a background thread
std::string do_work() {
  using namespace std::chrono_literals;
  std::this_thread::sleep_for(1s); // Simulate a time-consuming work
  return "Hello from std::async!";
}

int main() {
  // launch do_work() in a background thread and store the future result
  // *always* use std::launch::async here to ensure the function is executed in
  // a separate thread
  auto future_result = std::async(std::launch::async, do_work);

  // do some other work in the main thread
  std::cout << "Main thread continue execution while do_work() runs...\n";

  // wait for do_work() to finish, then retrieve the result
  auto result = future_result.get();
  std::cout << "Result from background thread: " << result << "\n";

  return 0;
}