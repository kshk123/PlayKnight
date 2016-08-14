#include <list>
#include <stack>
#include "ChessBoardPosition.h"

using namespace std;

//Copy constructor
ChessBoardPosition::ChessBoardPosition(const ChessBoardPosition & rhs)
{
	xPos = rhs.xPos;
	yPos = rhs.yPos;
}

//Assignment operator
ChessBoardPosition& 
ChessBoardPosition::operator=(const ChessBoardPosition & rhs)
{
	if(this != &rhs)
	{
		xPos = rhs.xPos;
		yPos = rhs.yPos;
	}

	return *this;
}

uint8_t 
ChessBoardPosition::getAdjacentPositions(vector<int32_t> & positions)
{
	int32_t pos= 0;
	if((xPos - 'a' + 1) < chessBoardRows)
	{
		if((yPos + 1) <= chessBoardRows)
		{
			pos = ((xPos - 'a' + 1) * 8 ) + yPos; //yPos +1 -1
			positions.push_back(pos);
		}
		if((yPos -1) >= 1)
		{
			pos = ((xPos - 'a' + 1) * 8 ) + yPos -2; //yPos -1 -1
			positions.push_back(pos);
		}

		pos = ((xPos - 'a' + 1) * 8 ) + yPos;
		positions.push_back(pos);
	}
		
	if((xPos - 'a' - 1) >= 0)
	{
		if((yPos + 1) <= chessBoardRows)
		{
			pos = ((xPos - 'a' - 1) * 8 ) + yPos; //yPos +1 -1
			positions.push_back(pos);
		}
		if((yPos -1) >= 1)
		{
			pos = ((xPos - 'a' - 1) * 8 ) + yPos -2; //yPos -1 -1
			positions.push_back(pos);
		}

		pos = ((xPos - 'a' - 1) * 8 ) + yPos;
	}

	if((yPos + 1) <= chessBoardRows)
    {
    	pos = ((xPos ) * 8 ) + yPos; //yPos +1 -1
        positions.push_back(pos);
    }
    if((yPos -1) >= 1)
    {
    	pos = ((xPos ) * 8 ) + yPos -2; //yPos -1 -1
        positions.push_back(pos);
    }
		
	return positions.size();
}


uint8_t 
ChessBoardKnightPosition::getAdjacentPositions(vector<int32_t> & positions)
{
	int32_t pos= 0;
	if((xPos - 'a' + 2) < chessBoardRows)
	{
		if((yPos + 1) <= chessBoardRows)
		{
			pos = ((xPos - 'a' + 2) * 8 ) + yPos; //yPos +1 -1
			positions.push_back(pos);
		}
		if((yPos -1) >= 1)
		{
			pos = ((xPos - 'a' + 2) * 8 ) + yPos -2; //yPos -1 -1
			positions.push_back(pos);
		}

		//Since <xPos - 'a' + 2> is in range, <xPos - 'a' + 1> must be in range
		if((yPos + 2) <= chessBoardRows)
		{
			pos = ((xPos - 'a' + 1) * 8 ) + yPos +1; //yPos +2 -1
			positions.push_back(pos);
		}
		if((yPos -2) >= 1)
		{
			pos = ((xPos - 'a' + 1) * 8 ) + yPos -3; //yPos -2 -1
			positions.push_back(pos);
		}	
	}
	else if((xPos - 'a' + 1) < chessBoardRows)
    {
		if((yPos + 2) <= chessBoardRows)
        {
            pos = ((xPos - 'a' + 1) * 8 ) + yPos +1; //yPos +2 -1
            positions.push_back(pos);
        }
        if((yPos -2) >= 1)
        {
            pos = ((xPos - 'a' + 1) * 8 ) + yPos -3; //yPos -2 -1
            positions.push_back(pos);
        }   
	}

	if((xPos - 'a' - 2) >= 0)
	{
		if((yPos + 1) <= chessBoardRows)
		{
			pos = ((xPos - 'a' - 2) * 8 ) + yPos; //yPos +1 -1
			positions.push_back(pos);
		}
		if((yPos -1) >= 1)
		{
			pos = ((xPos - 'a' - 2) * 8 ) + yPos -2; //yPos -1 -1
			positions.push_back(pos);
		}

		//Since <xPos - 'a' - 2> is in range, <xPos - 'a' - 1> must be in range
		if((yPos + 2) <= chessBoardRows)
		{
			pos = ((xPos - 'a' - 1) * 8 ) + yPos +1; //yPos +2 -1
			positions.push_back(pos);
		}
		if((yPos -2) >= 1)
		{
			pos = ((xPos - 'a' - 1) * 8 ) + yPos -3; //yPos -2 -1
			positions.push_back(pos);
		}	
	}
	else if((xPos - 'a' - 1) >= 0)
    {
		if((yPos + 2) <= chessBoardRows)
        {
            pos = ((xPos - 'a' - 1) * 8 ) + yPos +1; //yPos +2 -1
            positions.push_back(pos);
        }
        if((yPos - 2) >= 1)
        {
            pos = ((xPos - 'a' - 1) * 8 ) + yPos -3; //yPos -2 -1
            positions.push_back(pos);
        }   
	}

	return positions.size();
}

//Copy constructor
ChessBoardKnightPosition::ChessBoardKnightPosition(const ChessBoardKnightPosition & rhs)
{
	xPos = rhs.xPos;
	yPos = rhs.yPos;
}

//Assignment operator
ChessBoardKnightPosition& 
ChessBoardKnightPosition::operator=(const ChessBoardKnightPosition & rhs)
{
	if(this != &rhs)
	{
		xPos = rhs.xPos;
		yPos = rhs.yPos;
	}

	return *this;
}


