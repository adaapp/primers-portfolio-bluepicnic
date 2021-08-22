
int thread1Duration = 5, thread2Duration = 10;

void timer1();
void timer2();
void joinDetachThreadsPartB();

void sleepTimer(void) {
	string timeToStop; 
  int timeInSeconds;

  getline(cin, timeToStop);
  stringstream ss(timeToStop);
  if(!(ss >> timeInSeconds && timeToStop.find_first_not_of("0123456789"))) //if no suitable input is detected, run for the default 10 seconds
  {
    timeInSeconds = 10;
  }

  this_thread::sleep_for(chrono::seconds(timeInSeconds)); 
}

void joinDetachThreads(void) {
	cout << "\nMain Thread: " << this_thread::get_id() << " started" << endl;
  
  //call both timer functions as threads, which each have their own unique ID and cause their respective threads to cease execution until the specified amount of time passes
  thread thread1(&timer1); 
  thread thread2(&timer2);

  //prevent further execution of this main thread until thread1 and thread2 terminates or has completed
  if(thread1.joinable()) 
  {
    thread1.join();
  }
  if(thread2.joinable())
  {
    thread2.join();
  } 
  

  cout << "Main Thread: " << this_thread::get_id() << " Ended" << endl;
  joinDetachThreadsPartB();
}

void timer1(){
  cout << "Thread 1: " << this_thread::get_id() << " started" << endl;
  this_thread::sleep_for(chrono::seconds(thread1Duration)); //
  cout << "Thread 1: " << this_thread::get_id() << " ended" << endl;
}

void timer2(){
  cout << "Thread 2: " << this_thread::get_id() << " started" << endl;
  this_thread::sleep_for(chrono::seconds(thread2Duration));
  cout << "Thread 2: " << this_thread::get_id() << " ended" << endl;
}

void joinDetachThreadsPartB()
{
  cout << "\nMain Thread: " << this_thread::get_id() << " started" << endl;
  thread thread1(&timer1);
  thread1.detach();

  thread thread2(&timer2);
  thread2.detach();

  cout << "Main Thread: " << this_thread::get_id() << " Ended" << endl;
  return;

}