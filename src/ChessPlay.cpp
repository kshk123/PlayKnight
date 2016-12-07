#include <iostream>
#include <list>
#include "ChessPlay.h"
#include "ChessBoardPosition.h"

using namespace std;

ChessPlay::ChessPlay(char src1Row, int32_t src1Col, 
                     char src2Row, int32_t src2Col, 
                     char destRow, int32_t destCol)
{
	src_1 = new ChessBoardPosition(src1Row, src1Col);
	src_2 = new ChessBoardPosition(src2Row, src2Col);
	dest  = new ChessBoardPosition(destRow, destCol);

}

ChessPlay::~ChessPlay()
{
	delete src_1;
	delete src_2;
	delete dest;
}

ChessPlay::ChessPlay(const ChessPlay & rhs)
{
	if(rhs.src_1 != NULL)
		src_1 = new ChessBoardPosition(*rhs.src_1);
	
	if(rhs.src_2 != NULL)
		src_2 = new ChessBoardPosition(*rhs.src_2);

	if(rhs.dest != NULL)
		dest  = new ChessBoardPosition(*rhs.dest);
}

ChessPlay& 
ChessPlay::operator=(const ChessPlay & rhs)
{
	if(this != &rhs)
	{
		*src_1 = *(rhs.src_1);
		*src_2 = *(rhs.src_2);
		*dest  = *(rhs.dest);
	}

	return *this;
}


ChessBoardPosition * 
ChessPlay::appGetNewBoardPosition(
				int32_t position)
{
	return new ChessBoardPosition(position); 
}

ChessBoardPosition * 
ChessPlay::appGetNewBoardPosition(
				char row,
				int32_t col)
{
	return new ChessBoardPosition(row, col); 
}

//This function implements a modified breadth-first-search algorith to calculate
//the shortest path from source(src) to destination(dest).
bool 
ChessPlay::findSteps(
					ChessBoardPosition * src, 
					ChessBoardPosition * dest, 
					stack<int32_t> & stepStack, 
					int32_t ignorePos)
{
	uint32_t numNodes = chessBoardRows * chessBoardRows;
	vector<bool> nodeVisited(numNodes, false); //to keep track of visited nodes to avoid loops
	vector<int32_t> parentNode(numNodes, -1); //vector representing parent node of each node 

	list<int32_t> nodeQueue;

	//calculate absolute position based on row and columns for source and destination
	int32_t startNode = ((src->getXPos() - 'a') * chessBoardRows) + (src->getYPos() -1) ;
	int32_t endNode   = ((dest->getXPos() - 'a') * chessBoardRows) + (dest->getYPos() -1) ;

	nodeQueue.push_back(startNode);
	nodeVisited[startNode] = true;
	int32_t currNode = 0;
	vector<int32_t> adjNodes;
	bool found = false;
	
	while(!nodeQueue.empty())
	{
		currNode = nodeQueue.front();
		if(currNode == endNode) // destination reached, break from the search
		{
			found = true;
			break;
		}

		nodeQueue.pop_front();
	
		adjNodes.clear();
		//get valid adjacent nodes for current location
		ChessBoardPosition * currPos = appGetNewBoardPosition(currNode); 
		uint8_t count = currPos->getAdjacentPositions(adjNodes);
		for(uint8_t i = 0; i < count; i++)
		{
			//If position already not visited and not to be ignored, then examine this position
			if((!nodeVisited[adjNodes[i]]) && (adjNodes[i] != ignorePos))
			{
				nodeVisited[adjNodes[i]] = true;
				parentNode[adjNodes[i]] = currNode;
				nodeQueue.push_back(adjNodes[i]);
			}	
		}
		delete currPos;
	}	

	if(found)
	{
		//push the path on the stack
		while(currNode != startNode)
		{
			stepStack.push(currNode);
			currNode = parentNode[currNode];
		}
		stepStack.push(currNode);
		return true;
	}

	return false;
}

//This function compares the shortest paths from both the sources to the destination.
//It then declares the winner based on who reaches destination first.
void 
ChessPlay::getSteps()
{
	stack<int32_t> src1Steps;
	findSteps(src_1, dest, src1Steps); // calculate the shortest path for the first player
	stack<int32_t> src2Steps;
	findSteps(src_2, dest, src2Steps); // calculate the shortest path for the second player

	cout << "Player 1 moves        Player 2 moves" << endl;

	int32_t currPos1 = src1Steps.top();
	int32_t currPos2 = src2Steps.top();

	while(true)
	{
		//There is a collision, player1 is trying to reach a position already occupied by player2.
		//Recalculate the path from the current position of player1, but don't consdier the collision position
		if(src1Steps.top() == currPos2)
		{
			int32_t ignorePos = src1Steps.top();
			src1Steps = stack<int32_t>(); //clear the stack
			ChessBoardPosition * currPos =  appGetNewBoardPosition(currPos1);
			findSteps(currPos, dest, src1Steps, ignorePos);			
			delete currPos;
			src1Steps.pop(); // since current positon was already printed, just pop it
		}

		currPos1 = src1Steps.top();
		src1Steps.pop();
		cout << "    " << (char)((currPos1 / chessBoardRows) + 'a') << " " << (currPos1 % chessBoardRows) + 1 << "         ";

		if(src1Steps.empty())
		{
			cout << endl << "***** Player 1 WINS *****" << endl;
			break;
		}

		//There is a collision, player2 is trying to reach a position already occupied by player1.
		//Recalculate the path from the current position of player2, but don't consdier the collision position
		if(src2Steps.top() == currPos1)
        {
			int32_t ignorePos = src2Steps.top();
			src2Steps = stack<int32_t>(); //clear the stack
			ChessBoardPosition * currPos =  appGetNewBoardPosition(currPos2);
            findSteps(currPos, dest, src2Steps, ignorePos);
			delete currPos;
        	src2Steps.pop(); // since current positon was already printed, just pop it
        }

		currPos2 = src2Steps.top();
        src2Steps.pop();
		cout << "          " << (char)((currPos2 / chessBoardRows) + 'a') << " " << (currPos2 % chessBoardRows) + 1 << endl;

		if(src2Steps.empty())
        {
            cout << endl << "***** Player 2 WINS *****" << endl;
            break;
        }
	}
}

KnightChessPlay::KnightChessPlay(char src1Row, int32_t src1Col,
                        	     char src2Row, int32_t src2Col,
                        		 char destRow, int32_t destCol)
							:ChessPlay()
{
    src_1 = new ChessBoardKnightPosition(src1Row, src1Col);
    src_2 = new ChessBoardKnightPosition(src2Row, src2Col);
    dest  = new ChessBoardKnightPosition(destRow, destCol);

}


KnightChessPlay::KnightChessPlay(const KnightChessPlay & rhs)
{
	if(rhs.src_1 != NULL)
		src_1 = new ChessBoardKnightPosition(static_cast<ChessBoardKnightPosition &>(*rhs.src_1));
	
	if(rhs.src_2 != NULL)
		src_2 = new ChessBoardKnightPosition(static_cast<ChessBoardKnightPosition &>(*rhs.src_2));

	if(rhs.dest != NULL)
		dest  = new ChessBoardKnightPosition(static_cast<ChessBoardKnightPosition &>(*rhs.dest));
}

KnightChessPlay& 
KnightChessPlay::operator=(const KnightChessPlay & rhs)
{
	if(this != &rhs)
	{
		*src_1 = *(rhs.src_1);
		*src_2 = *(rhs.src_2);
		*dest  = *(rhs.dest);
	}

	return *this;
}


ChessBoardPosition * 
KnightChessPlay::appGetNewBoardPosition(
				int32_t position)
{
	return new ChessBoardKnightPosition(position); 
}

ChessBoardPosition * 
KnightChessPlay::appGetNewBoardPosition(
				char row,
				int32_t col)
{
	return new ChessBoardKnightPosition(row, col); 
}


bool 
verifyInput(char row, int32_t col)
{
	if(row < 'a' || row > 'h' )
	{
		cout << "\nInvalid row position, row number should be between a to h [a -> topmost row]" << endl;
		return false;
	}

	if(col < 1 || col  > chessBoardRows)
	{
		cout << "\nInvalid column position, column number should be between 1 to 8 [1 -> leftmost column]" << endl;
		return false;
	}

	if(row == 'h' && col == chessBoardRows)
	{
		cout << "\nKnight cannot be placed at the destination position [h, 8]" << endl;
        return false;
	}

	return true;
}

int main()
{
	char row1;
	int32_t col1;

	do
	{
		cout << "\nPlayer 1: Please enter the row number (a to h [a -> topmost row]) : ";
		cin >> row1;
		cout << "Player 1: Please enter the column number (1 to 8 [1 -> leftmost column]) : ";
		cin >> col1;
	}while(!verifyInput(row1, col1));

	char row2;
	int32_t col2;

	bool samePos = false;

	do
	{
		samePos = false;
		cout << "\nPlayer 2: Please enter the row number (a to h [a -> topmost row]) : ";
		cin >> row2;
		cout << "Player 2: Please enter the column number (1 to 8 [1 -> leftmost column]) : ";
		cin >> col2;
	
		if((row1 == row2) && (col1 == col2))
		{
			cout << "\nPlayer 2 cannot place the knight at the same position as Player 1" << endl;
			samePos = true;
		}
	}while(samePos || !verifyInput(row2, col2));

	cout << endl;
	cout << endl;

	ChessPlay * newPlay = new KnightChessPlay(row1, col1, row2, col2, 'h', chessBoardRows);

	newPlay->getSteps(); 

	delete newPlay;

	return 0;
}


