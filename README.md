# Primer Portfolio
## Section 1 - Primer Challenges
### Primer 1 - Fahrenheit / Centigrade Conversion
This first challenge required us to capture user input for subsequent two values. The first was the value entered represented a temperature value and the second represented the unit of temperature it was to be converted to. 

For the initial design, it was assumed that conversion was only between Fahrenheit and Centigrade and algorithms needed to be designed to suit these conversions. 

In addition, robust input handling would be required in order to ensure the data entered for each value was in the correct format, so that the variables within the program can used to manipulate the data appropriately.

After review and careful consideration, the challenge itself could be broken down into these main tasks:
* Get data from the user
* Verify the data is in a suitable format
* Create a method to convert F->C
* Create a method to convert C->F
 
**Reflection (as well as issues, challenges & resolutions)**

On a surface level, the implementation of the initial design was not particularly difficult. However, I found the biggest challenge of this primer to be designing and implementing a robust enough input handling system to deal with the back-to-back user inputs. During experimentation with various input handling methods, I found that there were wider issues with my design that needed to be refactored. 

For example, there were issues with my control flow structures such as specific loops and conditional statements, that appeared unintentionally as the result of bad input, which either caused incorrect output to appear, or would not take input upon looping back around. Sometimes, due the conditions set for these loops and statements, some output would not appear at all. This required me to refactor the conditions for some of my loops to ensure they were working correctly.  

I opted to use the stringstream type and library when capturing user input and placing the values in their respective variables (such as int, float etc). This is because this method is a safe option that will produce and store a default value (usually 0 or 0.0) in the respective variable when using the << operator if conversion is not possible. This can be then handled appropriately when this default output is expected. 

My most reliable method of input validation was using the string::find_first_not_of() function, to search for any input beyond what was expected. This was especially useful for types other than strings.

I expanded upon the initial design of the primer to include conversion to and from Kelvin for both Fahrenheit and Celsius. 
To do this: I had to handle four extra input possibilities that each belonged to a respective conversion these were: 
“FK” and “CK” for conversion from Fahrenheit and Celsius to Kelvin and “KF” and “KC” for Kelvin to Fahrenheit and Celsius respectively. 

This necessitated the creation of two further functions for conversion to and from Kelvin. Depending on the user’s input with the above codes (and providing the input is valid), these functions are passed the user’s input string as a parameter, and perform the respective conversion to or from Kelvin using Celsius or Fahrenheit based on the first letter of the string when converting to Kelvin, or the second when converting from Kelvin. If the input is invalid, an error message appears. The process flow was reworked with the other conversion codes and methods, so the user can convert between the three temperature units in the same way as the initial design, with no subsequent input required. The user can also type “quit” at any time to exit the program.

### Primer 2 – Self-service checkout
The second primer also involved collecting two user inputs, this time repeatedly inside a loop to add to a running total under the umbrella of a “self-service checkout” system. The first value captured represented the quantity of the item and the second represented its price. Various output displays asking for each value and visually tracking the number of items entered were also included throughout. 

The two values (quantity and price) were then multiplied and added to a running subtotal. Once the user had entered all of their items, they can enter 0 when inputting quantity to conclude the “transaction” and display the total price of all of their items. The subtotal value was combined with a “shopping tax” modifier, stored as a constant value, to calculate a total price.

Because of the very specific flow of this program, and the conditions that control it, the task itself was quite easy to break down as follows:

While input is not <= 0:
* Get data from the user
* Validate input data, ensuring it is in the right format
  * If not, display appropriate error messages
* Calculate cost 
* add to subtotal

Then:
* Calculate tax
* Combine subtotal and tax to get total price for transaction

**Reflection (as well as issues, challenges & resolutions)**

For the initial design, the greatest challenge I faced was ensuring that the output strings displayed to the user would appear in the right order and with the correct spacing. This also challenged me when I came back to refactor my program to include extra functionality and input validation, as extra error messages needed to be displayed alongside existing text. 
Input validation also proved a challenge for this primer as I struggled to identify issues with my control flow structures when attempting to re-capture input from the user after rejecting their input and displaying an error message. 

For this primer’s additional functionality, I included the option to remove the most recently added item from the subtotal. This is done by entering “r” or “R” when prompted. To facilitate this, I used a vector object to store all the previous prices, which is added to just before the cost of an item is added to the subtotal. When removing an item, the element at the back of the previousPrices vector is taken away from the subtotal, and that element is “popped” from the back of the vector. An output message appears confirming this, and the total amount of items is decremented. 

I also refactored my code at this stage to separate calculating the total and checking if the input for price entry is valid from the main function into their own respective functions. The validity of a price input is tracked using the validPrice Boolean which assigned a value from the checkPrice function.  

### Primer 3 – Password Complexity Checker
The third primer takes a user input and returns an output evaluating the strength of the input string as a password, according to specified criteria. These are :
* A password is weak if it only has solely either numeric or alphabetic characters 
* A password is moderate if it has at least 4 characters and does not meet the criteria of the other strength classifications
* A password is Strong if it has 8 or more characters, at least two of which must be numeric and 4 or more of which must be alphabetic
* A password is Very Strong if it meets the criteria of a strong password, with at least one special character also included.

It was also specified that the password evaluation itself must take place in a separate function and returns a score from 1-4 to represent each of the password strength classifications in ascending order. 

Each of the password strength criteria provided a good starting point for dissecting the problem, as four key conditions were already outlined in the brief and a number of different tasks became apparent the more each condition was evaluated. I broke the program down as such:
* Capture user input
* Create a function to check against the criteria and calculate a strength score
* Create a function to count each type of character in the string (one for each of letters, numbers and special characters)
* Assign the returned strength score to an output that reflects the strength of the password

**Reflection (as well as issues, challenges & resolutions)**

Since many of the conditions were already laid out in the brief for this primer, and since we did not need to specifically validate user input and could just take the string at face value, I had less issues with this task than others. 

Where this task proved challenging was meeting the criteria of the “Weak” and “Moderate” password strengths. As I mentioned above, a function needed to be created to count each type of character in the user-supplied password string. This was used for the “Weak” password strength conditions.

This meant storing 3 separate values to track each type, and using the created function to loop through the string with an iterator to check against each character to see if they fall within a range of ASCII character codes. An iterator was used as it’s a more direct method that can make use of string class member functions to accurately loop through each character index of a string, without having to track integer index variable, and the ASCII codes were used as they provide ranges between multiple values that correspond to each character type, opposed to checking against each letter, number or special character individually.

For the “Moderate” strength, since it acts as a “default” case of sorts, it needed to be placed at the end of the control logic flow, which was a realisation made after testing the program extensively.

This primer’s additional functionality includes a default case when assigning password strengths after returning the score from the function, before displaying the evaluation string. Because of the tightly constructed cases for the other password strengths, this case can only occur if the password length is less than 3 characters. A corresponding input string is also added in this case to encourage the user to input a character with more than 3 characters. In addition, the “Weak” password type will also be assigned to passwords that include only special characters, similar to that of the existing cases for both numbers and letters. 

### Primer 4 – Employee List Removal
The fourth primer’s initial design was to display a pre-defined array of employees and take a user input. If the input matched one of the names in the array, that name is removed. 

The only input handling required for this primer is to check if the name supplied by the user input exists, and to display an error message if not.

There was also a second output string that displayed the current number of people in the list.

I broke down this problem in the following way:
* Populate name array
* Display number of employees
* Display employee list
* Capture user input
* Create a function that searches for the user supplied name
  *  remove if found
  * display “Employee not found” if not

**Reflection (as well as issues, challenges & resolutions)**

For this primer, I had significant difficulty using arrays to create an effective and simple solution. Arrays in C++ are immutable in size and require that size to be defined on creation. 

For the sake of this task, especially with the pre-defined data to include, arrays, as a data structure, would have been sufficient. However, in order to support the functionality required for this primer, I would have had to create a number of additional functions and kept track of the array size manually, which can be cumbersome,in addition to the flow above. 

In order to continue to create with simplicity in mind, to conserve system resources and to support my additional functionality for this task, I instead opted to use a vector as my data structure. This is because of several factors: 
* its size is variable 
* elements can be fully removed, not just changed or hidden, and the vector will change sizes accordingly
* there are a number of member functions and extended classes (such as iterators) part of the vector class that are well suited to this task

Because vectors have access to such a useful suite of functionality, especially when compared to arrays, I also made use of the “find” function from the algorithm library in tandem with the "erase" function built into the vector object to search for and erase a found employee. This is a significantly more optimised and simple solution to the problems posed by the primer, compared to a solution that using solely arrays would have required. 

My additional functionality for this primer was the inclusion of an addNewEmployee function that, if the user inputs “+1”, prompts them to enter a name that is added to the vector. This function also adds additional input validation, ensuring that a string equal to “+1” cannot be added, since inputting that specific string as part of the initial design’s removal prompt will instead call the addNewEmployee function, effectively adding an element that cannot be deleted.

### Primer 5 – Phone Directory
The 5th Primer reads data from a file to be stored in the program. Each entry has two associated pieces of data, a name and telephone number. The initial design of the program is to capture user input to search for the entries and output both pieces of data if found, and an error message if not.

I broke down the program thusly into the following tasks:
* Read data from file
* Separate data entry from single string into two 
* Store in data structure 
* Capture user input
* Create function to search for data entry based on user input

**Reflection (as well as issues, challenges & resolutions)**

For this primer, I initially had trouble finding a reliable way of splitting the single string taken from the input file into two. The format of the file was CSV, so each name and telephone number pair were separated by a comma. I spent a significant amount of time developing a solution to split each line of text from the file at the comma delimiter, even delegating the task to its own function. This function would have been used for both primer 5 and primer 6, but in the end, I opted to use the getline function’s compatibility with the stringstream type to loop through each line from the file and separate the each time a specified delimiter, in this case a comma, was found. This was in the interests of simplicity and conserving system resources. 

Because the functionality of this primer requires searching for specific strings (or slight variations thereof, such as capitalised letters), I included the removeLeadTrailSpaces function to remove any instances of whitespace (including tabs, carriage returns, etc) from the beginning or end of a string read from the input file. This was implemented to aid the search functionality, as users would likely not be aware of any leading or trailing whitespace at the beginning of the string. Any spaces within the string itself before the last character remain unaffected. 

I once again used vectors as my chosen data structure, as we cannot be sure of the amount of data that comes from a given file. Instead of opting for 2-dimensional arrays to store the data from the file, I defined a structure to group both pieces of data under a single type: details. My vector was then made up of elements of the details type and I updated and accessed each variable in the structure individually, but was able to pass both elements as one variable. This was chosen for readability, and ease of use. 

I also included a check when opening the input file to extract data to ensure that the file requested exists in the active directory.

### Primer 6 – Data file parser
The objective of the initial design of this primer was to once again read data from a file, this time parsing and formatting the data for suitable output strings. Each of the three comma separated values needed to be formatted differently and displayed in “columns” of equal size, based on the longest item for that set of inputs.  

Similar to the task above, I needed to select appropriate data structures to store the incoming information from the input file, and once again opted to use vectors for their variable size and structures to store multiple variables under a single type object. This structure was named salaryIndicies.

I also broke the challenge down into the following tasks:
* Read data from file

While each line from the file is being read:

* Create a function that calculates the max field width based on input sizes.
* Remove any trailing or leading spaces
* Push each element separated by a comma to a string vector
* Initialise a salaryIndicies object with the data from the string and push to the back of the main vector

Then:

* Create a function that:
  *  Suitably formats each column used for the output string 
  * Suitably formats each member variable element from the salaryIndicies structure for the output string

**Reflection (as well as issues, challenges & resolutions)**

The challenges and issues I faced while developing this primer were all concerning formatting the output strings. Prior to the development of my removeLeadTrailSpaces function, which was used to assist with parsing the input strings for both primers, I had difficulty in getting the output strings to line up correctly if any leading or trailing spaces were present. Even with this problem resolved, thanks to the function, I still had issues getting the output string to line up correctly. 

Thankfully, after doing some research, I found the utilities of “setw” from the iomanip library and “left” from the iostream library especially useful for this purpose. However, I found that these member functions still required a significant learning curve in order to utilise them correctly. Once I’d overcome this hurdle, I refactored my code and placed any output operations into their own function, which I called from the main program. This was done to improve the readability of my code. 

I also continued to use the getline function’s overload (a varient of the same function, with differing parameters and functionality) with stringstream and delimiter parameters to separate values and store them in the salaryIndicies objects and subsequent vectors designated to store that defined type. 

The additional piece of functionality I added for this primer was the creation of a function that writes the formatted data to an output file, salaryList.txt. This contains the same output that is seen in the console. This needed to be formatted in the same way as the output string, and was also placed in its own function. Because these are two separate output streams (cout and the output file) and the data is identically formatted, much of the code is required to be similar for both of these functions.

### Primer 7 – Sleep timer
The 7th primer is designed to demonstrate an understanding of multithreading features and the functionality of the “thread” library. 

In particular, this primer focuses on the sleep_for function, which pauses execution of the program for a provided amount of time. The initial design was to capture user input for the amount of time that should be passed into the sleep_for function. If no valid input is provided, then the program will pause execution for a default 10 seconds. No output was expected for this task.

This problem did not require a significant amount of consideration or deconstruction, but was broken down as follows:
* Capture user input
* Check if user input is valid, or if there is any input at all
  * if yes, store the user’s input as the duration to use
  * if no, default to 10 seconds
* pause execution of the program for the amount of seconds specified

**Reflection (as well as issues, challenges & resolutions)**

Being a considerably smaller task compared to that of the other primers, I did not encounter any particular issues. The only aspect of this task that I had to contemplate was any input validation for the task itself. Since no output was expected, I was unsure whether to include an error message if any user input was invalid and whether or not to have the user be required to input again on a failed attempt. 

In the end, after refactoring my code, I opted to have the program default to 10 seconds for the sleep_for duration if invalid input, or a blank string is entered. 

I made use of the “chrono” library in order to provide a steady and accurate parameter for the this_thread::sleep_for function to use. The chrono library has member functions that can accurately represent a wide variety of time durations, ranging from nanoseconds to years. I felt this was a suitable inclusion due to the need to pause for a measurable amount of time. 

### Primer 8 – Joining and Detaching Threads

Primer 8 expands on concepts introduced in Primer 7, and was split into two parts. The initial design uses two global variables representing two durations that two different instances of the this_thread::sleep_for member function takes as parameters to pause execution for. These different instances were contained within their own functions to demonstrate multithreading functionality. 
Both of these functions were then defined as thread objects and relevant output within the functions tracks when each of these threads (including the thread in the main function for this primer) start and end. 

The two separate threads were then “joined” to the main thread, which prevents the main thread from executing fully until both joined threads terminated or completed.

The second part of this primer focussed on detaching threads, which necessitated the creation of a second function to act as another main thread. Two further threads were created, initialised using the same functions mentioned above and then were immediately detached, and executed them independently, which prevented them from blocking or synchronising with the main thread. The main thread then completes, releasing its resources and the two other threads completed independently. 

I broke down this problem like so:
PART A:
* Place output strings at the start and end of the main function
* Create first timer function
* Create second timer function
* Create thread objects for both functions
* Check if threads are joinable 
  * if so, join thread

PART B:
*Place output strings at the start and end of the new function
*Create thread object for first timer function
*Detach first thread object
*Create second thread object for second timer function
*Detach second thread object

**Reflection (as well as issues, challenges & resolutions)**

Similar to primer 7, the 8th primer I found was simple to execute, but took slightly longer to understand than others. It was not initially clear to me what the order of execution was for each of the thread object functions, especially when detaching threads for part B of the primer. 

The source of a considerable amount of confusion came when the two detached threads not only continued to output to the console after the main thread has terminated, but also seemingly executed out of order. An example of this can be seen below. 

![output from main thread](09491bc274b660d7836e0115ca0728b2.png)
 ![output detached threads, appearing after main thread has finished executing](4980a9a37c464eaa9ee9014d43b1b76a.png)



My expectation for the behaviour of the detached threads differed to what actually occurred. I misunderstood what was meant by detached thread’s executions becoming independent of one another, and the behaviour of the threads continuing to execute without blocking one another. As such, the inclusion of the additional output led me to believe I had approached the task in the wrong way, since only the output from the main thread was required. 

This happens due to the fact that the console output won’t always reflect the state of the program’s order of execution because of a delay in transmitting output from the program itself to an output stream, such as the console.

Instead, since the execution of the detached threads were essentially asynchronous (aside from the use of the sleep_now function) by executing without reliance on or waiting for one another, there was in fact no reliable way to model or anticipate an expected output. Once I had overcome this obstacle, I refactored my code to give it an extra level of readability.

### Primer 9 – Car Class
Primer 9 required us to pivot our development towards object oriented paradigms, using classes to represent the various functionalities found on a car. 

When constructing the class, we were required to do so in a specific way. This included a number of private member variables, only accessible with getters and setters. Other member variables were also only accessible through specific member functions which changed their values, and by extension, their states. 

The latter of the aforementioned member functions also included output strings that react to the states of the member variables. Should a user attempt to call one of these functions, but no change to state would happen as a result, then an error message is displayed. This is to emulate the states that a real car would have (such as attempting to lock an already locked vehicle)

Finally, the class’s constructor was designed to accept values upon object creation to initialise the class member variables.

**Reflection (as well as issues, challenges & resolutions)**
This specific primer underwent a number of revisions while I was developing the program. I initially misunderstood the requirement to include support for initialising member variables through the constructor, opting to use a default constructor that took no parameters, and setting relevant variables to defaults therein, but also using member setter functions where applicable. I later refactored this to allow the constructor to initialise values based on parameters passed when creating a car object.

Extensive refactoring was often my downfall, however. A challenge I encountered was input carrying over from selection to selection if a valid choice (i.e. 1-6) was followed by a blank input. This was because I changed an input validation check in my code, which caused a stringstream variable to not reset with each iteration of the main control flow while loop. 

Adding additional functionality also presented similar problems, since I was applying the same incorrect logic for input validation to my two additional menu options, which require user input.

The additional functionality made use of the setter functions as part of the car class to capture user input and set the Car colour and make member variables respectively. Once refactored and working correctly, my input validation also included an error message if the user supplied string was blank.

I opted to implement this functionality in particular since it made the most sense with the existing menu functionality and use of Car class member functions. This maintained consistency and readability in my code by using the existing switch case for the menu, and the implementation itself within the main program is quite simple.

I took the executive decision as part of the development of this primer to make the mEngine member variable a string rather than a Boolean to accurately reflect the state of variable itself. This also in turn conserves system resources and reduces repitition since we do not need to declare any extra variables in the Car::engine_on and Car::engine_off functions to output the state of the engine based on a Boolean condition.

### Primer 10 – AreaOf Class
The 10th and final primer built on our understanding of classes to utilise a single class “AreaOf” to calculate the areas of specific shapes (Circles, Rectangles and Trapezoids) using pure, overloaded functions.

I broke down the problem in the following way:
*Create Car Class
*Create Area function for Circle
*Create Area function overload for Rectangle
*Create Area function overload for Trapezoid
*Create display function (does not have to be pure)
*Calculate and display area

**Reflection (as well as issues, challenges & resolutions)**

Initially, I had difficulty visualising the structure of the AreaOf class. I was aware that I needed three overloaded size functions to calculate the area, but was unsure if each of the parameters needed to calculate the area of each shape also needed to be member variables of the AreaOf class. In the end, in the interest of conserving system resources, I opted to declare the variables needed to calculate the area in the main function of the program, and pass them as parameters to both calculate the area and to display as part of the output strings. If they were member variables instead, then with each instance of the AreaOf class created there would be 6 different variables created every time, for a total of 18 across the three instances, with 12 of them going unused. 

My AreaOf class went through many revisions. Initially, I did not have mArea as a member variable, and instead returned the values from the size functions. The calls to these functions were a part of the output, so the returned values would appear as part of the output strings. I amended this in the interests of readability. Now, the mArea member variable is retrieved using an output member function, which does not break encapsulation, while also making the code more readable. 

The output function itself also has three overloads, as the output strings for each shape were different, as they contained the relevant parameters needed to calculate the area for each shape. This was initially part of the main function, but was refactored to reduce the size of the primer’s main function, thus improving readability. These output functions were not required to be pure functions.



---
## Section 2 - Programming Paradigms
### Programming Paradigms

Programming paradigms are non-language specific problem solving techniques and styles that utilise different approaches and ways of thinking. Examples of programming paradigms include object-oriented, event driven, structured, functional, procedural, declarative and imperative paradigms. Certain programming languages lend themselves more strongly to some of these paradigms than others, and some are even actively designed and intrinsically linked to these paradigms. In this discussion, I will explore five of the above programming paradigms, their strengths and weaknesses, and what is shared between them. 
 
#### Object-Oriented programming
Object-Oriented programming as a paradigm is centred on the concept of objects, which are user defined. Object oriented programming languages include: C#, Python, PHP, C++, and Java, although these languages are not are not exclusive to this paradigm. Objects tend to be self-contained with their own variables and methods, storing data and code respectively. Access to these objects, (and their attributes and methods) from different parts of a program can be actively controlled by utilising access modifiers in programming languages that support object-orientation. 

Object-oriented programming incorporates the concepts of reusability and modularity by allowing objects to be built using other objects. Objects can also be modified, either through their variables or methods, to support and process other objects, which can be used to build new features and functionality.

Object oriented programming lends itself well to parallel development and pair programming, as its modularity allows for parts of the same or different objects to be developed independently from one another. This means that multiple people can work on different parts of a particular implementation without impeding one another, thus increasing productivity and reducing overall development time. Object oriented programs can also be modelled accurately using notation such as UML, which can help to visualise a given system. This is because objects can be broken down into their component parts, such as variables, functions and their access modifiers and types using domain modelling notations. 

There are some drawbacks to following this paradigm, however. Because the size of an object can vary wildly depending on how it is implemented and the types of attributes it utilises, some objects can become particularly inefficient memory wise. This could impact the performance of a program in the cases where objects are particularly large. Compared with programs created using the procedural paradigm, for example, object oriented programs are also less efficient, can take longer to compile and to execute due to the potentially large amount of instructions and states that are built into an object.

#### Functional programming
Functional programming is derived from mathematical operations and evolved from systems of computation that focuses only on functions, such as lambda calculus, which features clear parameters and results. Functional programming achieves architectural simplicity by encouraging and utilising pure functions, which subsequently also improves the readability of functional code. Recursion is a prominent feature, which is used to mimic iterative control flow structures, such as looping. Recursive functions will call themselves until a certain case is met. 

Functional programming also deals with the concept of immutability, as variables within functional programs will often not be changed outside of functions. In addition, new variables are created within functions to act as data to be returned as the result of an operation. This is designed to reinforce the idea of immutability, and eliminate unintended side effects. Functional programming languages include Wolfram, Racket and Erlang, although much like other paradigms many programming languages have received revisions to support more functional development approaches.

A clear benefit of functional programming is its logical approach that clearly defines what goes in and out of a given function. This makes functional programs more easily debug-able than that of imperative programs, which will also aim to avoid any side effects. Similar to Object-Oriented programming, functional programming also lends itself well to parallel programming, as parts of a program can be abstracted as needed.

A negative aspect of this paradigm is its ability to handle and manage input and output. I/O is inherently not functional, can only be developed using impure methods (although this depends on the programming language) and can lead to side effects. This is due to the fact that many I/O systems do not return values. The use of recursion as a control flow structure to support a key feature such as looping also has its downsides, as it is memory intensive, which can cause issues when memory is limited or at a premium. The concept itself is also quite complex, which does not make functional programming an entry-level paradigm.

#### Structured programming
Structured programming is a multi-language, non-platform specific paradigm which uses modular approaches to break down programs into reusable procedures, subprograms and subroutines. Structured programs also utilise templates to reuse solutions and methods across a variety of platforms. Examples of structured programming languages include Pascal and Ada, but many aspects of structured programming have been adopted by procedural programming languages. Some languages even omit certain features that can change the flow or order of execution in the program, such as GOTO, found in assembler languages, to make non-structured programming more difficult. Structured programs make extensive use of implicit control flow structures such as loops, conditions and switch/cases to maximise comprehension of a program and dictate program flow. 

Features such as return and break, found in C++ are seen as deviations from this paradigm, as they introduce early exit points from a given program.

An advantage of structured programming is that it is easy to read, maintain and debug, similar to that of functional programs, or programs that lend themselves to the functional paradigm. This is because statements resemble regular words and phrases (if, while, when etc). Another advantage of structured programming is that approaches can be considered problem-based rather than machine-based. This means that more time is spent solving problems and creating solutions rather than dealing with machine specific issues, which in turn means that structured programs can take less time to develop. However, this is not necessarily guaranteed. This is because some implementations may still be language or machine specific based if types and data structures differ, which could potentially increase the development time rather than reducing it, due to the number of solutions and cases that need to be programmed around.

Another disadvantage of structured programs is that, where they utilise templates and generic code, time needs to be taken to convert these solutions into relevant machine code, which can be a complex and time consuming process, where this is not handled explicitly by a language or platform.

#### Declarative Programming
Declarative programming can be described as implicit, as many declarative languages, such as SQL for example, describe what to do rather than focus on how to do it. Instead, the “how” of a given solution is abstracted away in favour of a flow control that is not directly expressed. Instead, statements are interpreted and designed to simply retrieve requested pieces of information. Declarative programming languages are often high-level, that is, simple notation resembling natural language and following mathematical notation and logic, that does not deal with specific machine or platform issues. 

Declarative programs also tend to lack side effects as we specifically instruct the program to do what we want it to do or query. A lack of variables in declarative programming languages also helps to reduce side effects as operations are completed and data is returned without having to track states across a program.

Advantages of include its readability, similar to that of functional and structured programming. Code is inherently more understandable due to the notation resembling natural language. Declarative programs are also considerably easier to maintain, reuse and scale due to their high-level nature that does not require deep implementations to be developed.

However, declarative programs are considered less customizable than that of a structured or functional program, since declarative programming languages often have complete syntax, which is a specifically designed order and arrangement or words and phrases to follow. In some cases, due to this complete syntax, certain problems require long-winded or extensive solutions to achieve functionality found in other languages. This is best observed in SQL.

#### Event Driven Programming
Event Driven programming as a paradigm is designed with a specific style of program execution and flow control in mind. Instead of describing or structuring a program in way that executes code step by step, such as in programs which follow or lend themselves to the procedural paradigm, event driven programs are influenced by blocks of structured code to manage the behaviour of a given program, in response to particular events. 

Event driven programs use functions known as event handlers to respond to specific, defined sets of actions in a given program. Event handlers respond to these actions asynchronously depending on input, changes in state, or as a direct result of actions from other programs and threads. Examples of event driven programming languages include VB.net, Java and an offshoot of C++ called Visual C++.

The event driven paradigm is especially suitable for programs that feature graphical interfaces, as different event handlers can be assigned to different parts of an interface. Each element within a graphical interface can be used to break down a problem in a specific way, and abstract code and functionality for that specific event. Because of this, event driven systems, similar to that of object-orientated systems are also well suited to domain modelling.

A weakness of the event driven paradigm is that programs using the paradigm can be hard to debug, especially if subsequent functions are called from singular events. Event driven programs with intensive and extensive graphical user interfaces may also be quite intensive on memory and have significant memory overhead compared with that of structured programs. This potentially intensive memory usage is not dissimilar to that of functional programs, although the reasons for the high memory usages differ.


---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer
In terms of professional development, being a Polyglot programmer can make an individual a more appealing prospect due to their experience in multiple programming languages. This can lead to increased employability and prospective job opportunities. 

Being a Polyglot Programmer also can act beyond their usual boundaries in a business or personal context to solve a specific problem in a more efficient and suitable way if they know multiple programming languages. This also affects the variety of problems in which a developer can solve, and allows the developer to choose how to solve a problem using tools and languages.  

With rapidly changing standards between languages, frameworks, technologies and tools, a Polyglot programmer is highly adaptable and is unlikely to get left behind in an industry where tools can become obsolete and opportunities can dry up. 

By adopting languages that differ in paradigm, a Polyglot programmer could also improve upon adopting that paradigm in one of their more commonly used languages. Where the skills learned from these paradigms intersect across languages, presents an opportunity for a Polyglot programmer to apply different styles to their work. This may not always be beneficial and is dependent on the language, but could help to optimise work when these skills are combined. For example: a C++ programmer could also be proficient in Wolfram and apply the control flow found in a functional language and the concepts of recursion to a C++ project. 

Becoming a Polyglot programmer can also help to remove biases towards a particular language or paradigm. This not only makes an individual more versatile, but allows them to think outside the box beyond the “right” way of doing things (often the language or paradigm they are most familiar with). This also decouples the focus on syntax for a language or similar languages and allows the developer to improve their problem solving by becoming better and abstract concept and semantics. 

Widening one’s horizons with the prospect of learning new programming languages also presents the opportunity (if not already discovered) to learn new programming paradigms in their entirety. Many programming languages adopt multi paradigm functionality, which can make emulating the style of a particular paradigm vary in difficulty depending on the language. Learning programming languages that lean heavily towards a particular paradigm can be a good step in becoming more proficient in that paradigm.
