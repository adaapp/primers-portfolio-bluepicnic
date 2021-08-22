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

### Primer 3 -
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
