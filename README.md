Simple ASCII art drawing program. The program should support the following features:

	N w h   
Create a new canvas of width w and height h.

	C c
Set the color to the value of c. Default color should be "x".

	L x1 y1 x2 y2
Create a new line from (x1,y1) to (x2,y2). Support for horizontal or vertical lines is enough. Lines will be drawn using the selected color.
          	 
	R x1 y1 x2 y2
Create a new rectangle from  (left,top) (x1,y1) to (right,bottom) (x2,y2). Lines will be drawn using the selected color.
          	 
	B x y 
Fill the entire area connected to (x,y) with the selected color. This is the same as a "bucket fill" tool in paint programs.
          	 
	Q
Quit the program.

Below is a sample run of the program:
```bash

 Enter command: 
 N: Create new canvas 
 C: Set color 
 L: Create new line 
 R: Create new rectangle 
 B: Fill area 
 Q: Quit 
 
----------------------
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
----------------------
L
Enter first col 
...2
Enter first row 
...2
Enter second col 
...6
Enter second row 
...2
----------------------
|                    |
| xxxxx              |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
----------------------
R
Enter first col 
...4
Enter first row 
...4
Enter second col 
...10
Enter second row 
...10
----------------------
|                    |
| xxxxx              |
|                    |
|   xxxxxxx          |
|   x     x          |
|   x     x          |
|   x     x          |
|   x     x          |
|   x     x          |
|   xxxxxxx          |
----------------------
C
Enter color 
...o
----------------------
|                    |
| xxxxx              |
|                    |
|   xxxxxxx          |
|   x     x          |
|   x     x          |
|   x     x          |
|   x     x          |
|   x     x          |
|   xxxxxxx          |
----------------------
B
Enter row  
...8
Enter col  
...8
----------------------
|                    |
| xxxxx              |
|                    |
|   xxxxxxx          |
|   xooooox          |
|   xooooox          |
|   xooooox          |
|   xooooox          |
|   xooooox          |
|   xxxxxxx          |
----------------------
Q
Program ended with exit code: 0
```

