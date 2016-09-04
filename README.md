# PlayKnight
A gaming program to move a knight to the bottom right cell of a chess board [8x8] from a given position

This program simulates a play between two Knights on a chess board.
The name of the executable is "PlayKnight".
The chess board is assumed to be 8X8, with rows numbered a to h from 
top to bottom and columns numbered 1 to 8 from left to right.
The reperesentation is shown in the figure below.

	  1 2 3 4 5 6 7 8
	  _ _ _ _ _ _ _ _ 	
	a|_|_|_|_|_|_|_|_|
	b|_|_|_|_|_|_|_|_|
	c|_|_|_|_|_|_|_|_|
	d|_|_|_|_|_|_|_|_|
	e|_|_|_|_|_|_|_|_|
	f|_|_|_|_|_|_|_|_|
	g|_|_|_|_|_|_|_|_|
	h|_|_|_|_|_|_|_|_|

The input rows and colums are taken as command line arguments and verified.
Once both sets of inputs are validated, the game begins.
The movements of both the knights are displayed side by side as <row,column> .
A sample output is shown below.

Player 1 moves        
    a 5
    
    c 6
    
    e 7
    
    g 6
    

Player 2 moves

    d 4
    
    f 5
    
    h 6
    
    f 7
    


The Knight that reaches the destination <h,8> first is declared as the winner.
