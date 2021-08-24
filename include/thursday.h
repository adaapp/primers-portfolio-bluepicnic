/*Global variables for use in primer 8*/
int thread1Duration = 5, thread2Duration = 10;

/*Primer 8 function definitions*/
void timer1();
void timer2();
void joinDetachThreadsPartB();

void sleepTimer(void) {
	string timeToStop; 
  int timeInSeconds;

  getline(cin, timeToStop); //get input
  stringstream ss(timeToStop);

  if(!(ss >> timeInSeconds && timeToStop.find_first_not_of("0123456789"))) //if no suitable input is detected, or input is blank, set the duration to the default 10 seconds
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
  if(thread1.joinable()) //check if thread can be joined before 
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

void joinDetachThreadsPartB()
{
  cout << "\nMain Thread: " << this_thread::get_id() << " started" << endl;
  //create thread and immediately detach, execution will not be paused for the main thread, nor will it be interrupted 
  thread thread1(&timer1);
  thread1.detach();

  //create thread and immediately detach, execution will not be paused for the main thread, nor will it be interrupted 
  thread thread2(&timer2);
  thread2.detach();

  cout << "Main Thread: " << this_thread::get_id() << " Ended" << endl;
  return;
  //since both threads are detached, they will execute independantly of this main function. As a result, input from both threads appear even after this main function (and the function calling it) has returned.
}

/*Primer 8 function implementations*/
void timer1(){
  cout << "Thread 1: " << this_thread::get_id() << " started" << endl;
  this_thread::sleep_for(chrono::seconds(thread1Duration)); //prevent further execution for 5 seconds 
  cout << "Thread 1: " << this_thread::get_id() << " ended" << endl;
}

void timer2(){
  cout << "Thread 2: " << this_thread::get_id() << " started" << endl;
  this_thread::sleep_for(chrono::seconds(thread2Duration)); //prevent further execution for 10 seconds 
  cout << "Thread 2: " << this_thread::get_id() << " ended" << endl;
}