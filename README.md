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

Below is a sample run of the program. User input is prefixed with ’enter command:’.


enter command: N 20 5
----------------------
|                	|
|                	|
|                	|
|                	|
|                	|
----------------------

enter command: L 1 2 6 2
----------------------
|                	|
|xxxxxx          	|
|                	|
|                	|
|                	|
----------------------

enter command: L 6 3 6 5
----------------------
|                	|
|xxxxxx          	|
|     x          	|
|     x          	|
|     x          	|
----------------------

enter command: R 16 1 20 3
----------------------
|               xxxxx|
|xxxxxx     	x   x|
|     x     	xxxxx|
|     x              |
|     x              |
----------------------

enter command: C o
----------------------
|               xxxxx|
|xxxxxx         x   x|
|     x     	xxxxx|
|     x              |
|     x              |
----------------------

enter command: B 10 3
----------------------
|oooooooooooooooxxxxx|
|xxxxxxooooooooox   x|
|     xoooooooooxxxxx|
|     xoooooooooooooo|
|     xoooooooooooooo|
----------------------

enter command: Q



