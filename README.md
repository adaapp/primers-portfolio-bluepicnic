# Primer Portfolio
# a description and review of the problem and outline of your general approach and any main issues
identified within
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
 
#### Reflection (as well as issues, challenges & resolutions)
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

#### Reflection (as well as issues, challenges & resolutions)
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

#### Reflection (as well as issues, challenges & resolutions)
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

#### Reflection (as well as issues, challenges & resolutions)
For this primer, I had significant difficulty using arrays to create an effective and simple solution. Arrays in C++ are immutable in size and require that size to be defined on creation. 

For the sake of this task, especially with the pre-defined data to include, arrays, as a data structure, would have been sufficient. However, in order to support the functionality required for this primer, I would have had to create a number of additional functions and kept track of the array size manually, which can be cumbersome,in addition to the flow above. 

In order to continue to create with simplicity in mind, to conserve system resources and to support my additional functionality for this task, I instead opted to use a vector as my data structure. This is because of several factors: 
* its size is variable 
* elements can be fully removed, not just changed or hidden, and the vector will change sizes accordingly
* there are a number of member functions and extended classes (such as iterators) part of the vector class that are well suited to this task

Because vectors have access to such a useful suite of functionality, especially when compared to arrays, I also made use of the “find” function from the algorithm library in tandem with the "erase" function built into the vector object to search for and erase a found employee. This is a significantly more optimised and simple solution to the problems posed by the primer, compared to a solution that using solely arrays would have required. 

My additional functionality for this primer was the inclusion of an addNewEmployee function that, if the user inputs “+1”, prompts them to enter a name that is added to the vector. This function also adds additional input validation, ensuring that a string equal to “+1” cannot be added, since inputting that specific string as part of the initial design’s removal prompt will instead call the addNewEmployee function, effectively adding an element that cannot be deleted.

..  
..  

---
## Section 2 - Programming Paradigms
### Programming Paradigms
Simply put, a programming paradigm, for example, procedural, object-oriented, functional, structured, declarative, imperative and event driven can be described as a specific approach used when trying to solve a problem.  Although many programming languages can (and do) support multiple paradigms this discussion will focus more specifically on the possible benefits with examples of the potential differences and similarities of five from the above list. These are ...

---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer
Vestibulum vitae semper sem. Duis leo leo, suscipit at felis non, pellentesque varius massa. Sed sit amet orci nibh. Morbi scelerisque faucibus elit, vitae mollis turpis finibus eget. In convallis euismod nunc non imperdiet. Duis ultricies pulvinar lorem, sed molestie nunc porta at. Aenean arcu ante, efficitur nec felis sed, feugiat iaculis turpis. Vestibulum eu elementum diam. Quisque nec tortor auctor, scelerisque ante vitae, fringilla tellus.

Quisque ligula lectus, efficitur quis malesuada sit amet, malesuada sed nibh. In lorem erat, elementum quis tempus nec, rhoncus ac ante. Mauris suscipit massa tempor, pulvinar neque vel, gravida nulla. Donec massa diam, molestie in diam nec, vulputate faucibus ligula. Aliquam erat volutpat. Aliquam sit amet dui ligula. Nullam euismod eros ultrices magna convallis lobortis. Proin convallis placerat tincidunt. Quisque interdum, nisi id egestas luctus, augue libero lacinia urna, sit amet tempus nisl sem nec quam. Vestibulum interdum urna mauris, vel dignissim nisi dignissim egestas. Donec volutpat dictum dui, at egestas sem tristique nec.
