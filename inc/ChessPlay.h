#ifndef _CHESS_PLAY_H__
#define _CHESS_PLAY_H__

#include <stdint.h>
#include <stack>

//Forward declarations
class ChessBoardPosition;
class ChessBoardKnightPosition; 


//Generic base class to find the steps to move a Chess piece from a source position to another.
//It then compares the moves between two sources to a destination and decalres the winner.
//The class implies the logic of a modified breadth-first-search to calculate the shortest path
//from both the sources.
//The base class uses the base ChessBoardPosition class logic and hence works for two Kings pieces.
//This card can be specialized into any other chess piece to implement the logic for that piece.
class ChessPlay
{
	public:
		ChessPlay(){}; //default constructor, do nothing
		ChessPlay(char src1Row, int32_t src1Col, 
					char src2Row, int32_t src2Col, 
					char destRow, int32_t destCol);
		//Destructor
		virtual ~ChessPlay() ;

		//Copy constructor
		ChessPlay(const ChessPlay&);

		//Assignment operator
		ChessPlay& operator=(const ChessPlay&);

		//returns a pointer to a board position base class
		virtual ChessBoardPosition * appGetNewBoardPosition(int32_t position);
		//returns a pointer to a board position base class
		virtual ChessBoardPosition * appGetNewBoardPosition(char row, int32_t col);

		//Compares the steps on the route from both sources to destination and decalres the winner
        //
		void getSteps();

		//Return the steps from source to destination for the shortest route
		//
		//Parameters :
        //              src       : In parameter, the source location on the chess board
        //              dest      : In parameter, the destination location on the chess board
        //              stepStack : Out parameter, the steps from source to destination
        //              ignorePos : In parameter, if provided, ignore this position while calculating the shortest route
		//Returns :
        //              A boolean indicating if the route was found or not
		bool findSteps(ChessBoardPosition * src, ChessBoardPosition * dest, 
						std::stack<int32_t> & stepStack, int32_t ignorePos = -1);

	protected:
		ChessBoardPosition * src_1;
		ChessBoardPosition * src_2;
		ChessBoardPosition * dest;

};

//Specialized class to implement the logic for two Knight's pieces.
//It uses the logic from ChessBoardKnightPosition class. 
class KnightChessPlay : public ChessPlay
{
	public:
    	KnightChessPlay() {}; //default constructor
		KnightChessPlay(char src1Row, int32_t src1Col,
                    	char src2Row, int32_t src2Col,
                    	char destRow, int32_t destCol);

		//Destructor
    	~KnightChessPlay(){};
		
		//Copy constructor
		KnightChessPlay(const KnightChessPlay&);

		//Assignment operator
		KnightChessPlay& operator=(const KnightChessPlay&);

		//returns a pointer to a board position knight class
		virtual ChessBoardPosition * appGetNewBoardPosition(int32_t position);
		//returns a pointer to a board position knight class
		virtual ChessBoardPosition * appGetNewBoardPosition(char row, int32_t col);

};


#endif


