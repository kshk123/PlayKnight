#ifndef _CHESS_BOARD_POSITION_H__
#define _CHESS_BOARD_POSITION_H__

#include <stdio.h>
#include <stdint.h>
#include <vector>

//The number of rows(and columns) in the chessboard
const uint8_t chessBoardRows = 8;

// The generic class that represents the co-oridnates in a chess board
// The co-ordinates are represented as [a...h][1...8], (assuming an 8X8 chessboard)
// i.e., rows a to h from top to bottom, and columns 1 to 8 from left to right
class ChessBoardPosition
{
	public:
		//default contructor, it always points to the left-top corner of the chess board
		ChessBoardPosition(): xPos('a'), yPos(1) {};
		//Contructor taking the row and column as inputs and setting the co-ordinates
		ChessBoardPosition(char row, int32_t col): xPos(row), yPos(col) {};
		//Contructor taking the absolute psotion as input and setting the co-ordinates
		ChessBoardPosition(int32_t pos): xPos((char)((pos/chessBoardRows) + 'a')), yPos((pos % chessBoardRows) + 1) {};
		//destructor
		virtual ~ChessBoardPosition() {};

		//Copy constructor
		ChessBoardPosition(const ChessBoardPosition & rhs);
		
		//Assignment operator
		ChessBoardPosition& operator=(const ChessBoardPosition & rhs);

		char getXPos() {return xPos;}
		int  getYPos() {return yPos;}

		//This is a virtual function that returns the adjacent positions corresponding to a chess board position
		//By default, the generic base class function returns the adjacent postions corresponding to a King's move
		//Any other chess piece movement can be simulated by deriving from the base class and overriding this function
		//Parameters :
		//				positions : Out parameter, containing all the adjacent positions
		//Returns :
		//				The count of the number of valid adjacent positions
		virtual uint8_t getAdjacentPositions(std::vector<int32_t> & positions);

	protected:
		char 		xPos; // Member variable to store the row position of the chess piece
		int32_t  	yPos; // Member variable to store the column position of the chess piece

};

class ChessBoardKnightPosition : public ChessBoardPosition
{
	public:
		//default contructor, it always points to the left-top corner of the chess board
		ChessBoardKnightPosition() 
			: ChessBoardPosition() {};
		//Contructor taking the row and column as inputs and setting the co-ordinates
		ChessBoardKnightPosition(char row, int32_t col) 
			: ChessBoardPosition(row, col) {};
		//Contructor taking the absolute psotion as input and setting the co-ordinates
		ChessBoardKnightPosition(int32_t pos)
			: ChessBoardPosition(pos) {};

		//Destructor
		~ChessBoardKnightPosition() {};

		//Copy constructor
		ChessBoardKnightPosition(const ChessBoardKnightPosition & rhs);
		
		//Assignment operator
		ChessBoardKnightPosition& operator=(const ChessBoardKnightPosition & rhs);

		//This function returns the valid positions a Knight can move from the current position
		//Parameters :
		//				positions : Out parameter, containing all the adjacent positions
		//Returns :
		//				The count of the number of valid adjacent positions
		virtual uint8_t getAdjacentPositions(std::vector<int32_t> & positions);

};


#endif
