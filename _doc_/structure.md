# Developing Structure
We now will consider syntax for developing the basic building blocks of programs. 
### Decsions
We consider two basic decision structures that allow for conditional logic when performing operations. These will be the standard if statement and switch statment. 

We begin with an **if** statement, and it's natural extension **else if** and **else**.
```
if(boolean_expression) {
   // statement(s) will execute if the boolean expression is true
} 
else if (boolean_expression) {
  // statement(s) will execute if the boolean expression is true
} 
else {
  // statement(s) will execute if all other boolean expression(s) is/are false
}
```
There also exists **switch** statements, that operate slightly different to the tradtional if-statement, which directs the flow of information through checks. The switch-statement works by first initializing an expression (encapsulated within the switch parentheses) and following by creating cases that represent conditions for said expression.   
 ```
 switch(expression) {
   case constant-expression  :
      statement(s);
      break; //optional
   case constant-expression  :
      statement(s);
      break; //optional
  
   // you can have any number of case statements.
   default : //Optional
      statement(s);
}
```
### Loops 
There are three major loop structures that we will be discussing **while**, **for**, and **do while** loops. We will start with the common "while loop:

A while loop statement repeatedly executes a target statement as long as a given condition is true, testing the condition before executing the loop body
```
while(condition) {
   statement(s);
}
```
A variant of the while loop is the do-while loop, that tests the condition at the end of the loop body rather than the begining 
```
do {
   statement(s);
} 
while( condition );
```
Finally, we have the for loop that executes a sequence of statements multiple times and abbreviates the code that manages the loop variable. Basically a condensed while loop.
```
for ( init; condition; increment ) {
   statement(s);
}
```
### Functions
