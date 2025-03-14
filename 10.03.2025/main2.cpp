#include<iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int number=0;

void increment(){
  mtx.lock();
  for(int i=0; i!=1'000'000; i++){
    number ++;
  }
  mtx.unlock();
}

int main(){
  std::thread t1(increment);
  std::thread t2(increment);
  t1.join();
  t2.join();

  std::cout<<"number after t1 and t2:"<<number<<"\n";

  return 0;
}
