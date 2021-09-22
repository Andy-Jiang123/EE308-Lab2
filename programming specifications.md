

#JHQ's programming specifications
## 1.Indentation
####The same level need using the same indentation
####next level need to use "Tab" as one indentation
### 
```	
		
        //take if-else structure 

		int a;  //The same level need using the same indentation
		int b;
		
		if
		{
			if  //next level need to use "Tab" as one indentation
			{
				if{

				  }
			}
			else
			{

			}
		}
		
```

##2. Variable naming
####2.1 Variable names are all lowercase, abbreviations are capitalized, and all nouns are used. Adjectives can be used to modify them, and "_" is used to list dependencies,first letter need capitalize. 
Ex. int a  ;  string Open_Door;
####2.2 Use one word to express the meaning of local variables
####2.3 When naming global variables, write the module name first.
Ex: have PID.h file make one of the variable PID_kp

##3.Function and class naming
####Function names 
####each word with the first letter capitalized and written in the form of subject predicate. The subject uses nouns and predicate pragmatic verbs. Abbreviations are capitalized and "_" is used to show subordination. The subject is usually the module name, while the predicate describes the action of the module. Because the function itself is used to perform a series of actions, combined with function parameters, smooth statements can be expressed.
ex Delay function. Define a ms level delay function as: void Delay(unsigned int ms)；

####class
####User defined type naming mainly refers to the new type name defined by typedef, as well as the type name of structure type and common body type (rather than the variable name of this type).Custom new type name, only one word, initial capital. However, when defining variables of this new type, the naming rules are exactly the same as those of variables.


##4.Annotation rules
####at the begin of the code write a note to brief introduce the mean of the code, the name of author and the time.
```	
		
        //------------------------------------------------
           Author:JHQ
           Time: 2021/01/20
		   This code is about ....
        //------------------------------------------------
		
```

##5.Space before and after operator

#### there should be a space between the operator and its operand. For example:a = a + b;


##6.Maximum line width
####The maximum line width can control by the IDE, the 80 is most suitable I think.
##7.Maximum number of function lines
#### I think the line of function on limit, we can write what we like.

##8.Other rules
####File Division

####A simple program, only a few lines to dozens of lines, can be seen at a glance in a file. However, there may be thousands of lines of code in a large project, and millions of lines of large program code. Code of this size is stored in a file. Please imagine its horror.

####When a function has more than a few lines of code, it is necessary to consider whether it is possible to extract some of its code and package it into another function and then call it. Similarly, when the amount of code in a file exceeds hundreds of lines, we should consider whether it is possible to separate some functions and put them in other files. All this is for the readability and debugging convenience of the program. After all, it is much easier to test the function of a short function than a long function.

####However, a better basis for dividing files should be by module. Of course, the corresponding division function should be divided according to function. In other words, a file stores the contents of a module, and a function completes a single function.



