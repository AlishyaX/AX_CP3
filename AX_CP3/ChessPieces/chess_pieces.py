# AX Chess Game
# had to use a lot of copilot to figure out how to code the movements of the pieces especially because I don't know how to play chess

from abc import ABC, abstractmethod



class ChessPiece(ABC):
    def __init__(self, color: str, position: str, game=None):
        self.color = color # white or black
        self.position = position # ex. a1
        self.game = game

    def getPosition(self) -> str:
        return self.position

    def setPosition(self, newPos: str):
        self.position = newPos
    
    @abstractmethod
    def canMoveTo(self, newPos: str) -> bool:
        pass
    
    @abstractmethod
    def getSymbol(self) -> str:
        pass


class Pawn(ChessPiece):
    def canMoveTo(self, newPos: str):
        # find the pieces row and col
        current_col = self.position[0]
        current_row = int(self.position[1])

        # finds the target row and col
        target_col = newPos[0]
        target_row = int(newPos[1])

        # the direction of the piece moving
        if self.color == "white":
            direction = 1
        else:
            direction = -1

        # One square forward
        if target_col == current_col and target_row == current_row + direction:
            return True

        # Two squares forward from starting position
        if target_col == current_col and \
        ((self.color == "white" and current_row == 2 and target_row == 4) or
            (self.color == "black" and current_row == 7 and target_row == 5)):
            # Check if square in between is empty
            between_row = current_row + direction
            between_pos = f"{current_col}{between_row}"
            if not self.game.getPiecesAt(between_pos):
                return True

        return False

    def getSymbol(self):
        return "P"

class Rook(ChessPiece):
    def canMoveTo(self, newPos: str):
        #Moves in straight lines
        # The first one is up and down the same column and the second one is left or right the same row
        if self.position[0] != newPos[0] and self.position[1] != newPos[1]:
            return False
        # The code needs to make it so that the rook can't just skip over all of the pieces(Used Copilot specifically)

        columns = {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5, 'f': 6, 'g': 7, 'h': 8}
        start_col = columns[self.position[0]]
        start_row = int(self.position[1])
        end_col = columns[newPos[0]]
        end_row = int(newPos[1])

        # Determine direction
        col_step = 0 if start_col == end_col else (1 if end_col > start_col else -1)
        row_step = 0 if start_row == end_row else (1 if end_row > start_row else -1)

        # Check each square between start and end
        current_col = start_col + col_step
        current_row = start_row + row_step
        while current_col != end_col or current_row != end_row:
            pos = f"{chr(current_col + ord('a') - 1)}{current_row}"
            if self.game.getPiecesAt(pos):  # Access game context
                return False
            current_col += col_step
            current_row += row_step

        return True
    def getSymbol(self):
        return "R"

class Knight(ChessPiece):
    def canMoveTo(self, newPos: str):
        #still kinda confused
        # makes it so that the letters are corresponding with the numbers
        columns = {
            'a': 1, 'b': 2, 'c': 3, 'd': 4,
            'e': 5, 'f': 6, 'g': 7, 'h': 8
        }
        #Finds the current position
        start_col = columns[self.position[0]]
        start_row = int(self.position[1])

        #Finds the target position
        end_col = columns[newPos[0]]
        end_row = int(newPos[1])

        #calculates how much the piece moved
        col_diff = abs(start_col - end_col)
        row_diff = abs(start_row - end_row)

        #returns the l shape(2 by 1 or 1 by 2)
        return (col_diff, row_diff) in [(1,2), (2,1)]

    def getSymbol(self):
        return "K"

#Add comments
class Bishop(ChessPiece):
    def canMoveTo(self, newPos: str):
        #Moves diagonally
        columns = {
            'a': 1, 'b': 2, 'c': 3, 'd': 4,
            'e': 5, 'f': 6, 'g': 7, 'h': 8
        }
        start_col = columns[self.position[0]]
        start_row = int(self.position[1])

        #Finds the target position
        end_col = columns[newPos[0]]
        end_row = int(newPos[1])

        #Bishop moves diagonally which means that it has the same number of steps in both directions
        if abs(start_col - end_col) != abs(start_row - end_row):
            return False  # Not diagonal

        col_step = 1 if end_col > start_col else -1
        row_step = 1 if end_row > start_row else -1

        current_col = start_col + col_step
        current_row = start_row + row_step
        while current_col != end_col and current_row != end_row:
            pos = f"{chr(current_col + ord('a') - 1)}{current_row}"
            if self.game.getPiecesAt(pos):
                return False
            current_col += col_step
            current_row += row_step

        return True
    
    def getSymbol(self):
        return "B"

class Queen(ChessPiece):
    def canMoveTo(self, newPos: str):
        #The queen's movement is the combination of the Rook and Bishop
        return Rook(self.color, self.position, self.game).canMoveTo(newPos) or \
               Bishop(self.color, self.position, self.game).canMoveTo(newPos)

    def getSymbol(self):
        return "Q"

class King(ChessPiece):
    def canMoveTo(self, newPos: str) -> bool:
        #Can move one square in any direction
        columns = {
            'a': 1, 'b': 2, 'c': 3, 'd': 4,
            'e': 5, 'f': 6, 'g': 7, 'h': 8
        }
        start_col = columns[self.position[0]]
        start_row = int(self.position[1])

        #Finds the target position
        end_col = columns[newPos[0]]
        end_row = int(newPos[1])
        
        #This is the code to help it move those directions
        return abs(start_col - end_col) <= 1 and abs(start_row - end_row) <= 1

    def getSymbol(self):
        return "K"



class ChessGame:
    def __init__(self):
        self.whitePieces = []
        self.blackPieces = []
        self.setupBoard()
    
    def setupBoard(self):
        #This is to help set up the pawns
        for col in 'abcdefgh': #These are the columns of as chess board
            #Adds whit epawns to row 2 and black ones to row 7 for the starting position
            self.whitePieces.append(Pawn("white", f"{col}2", self))
            self.blackPieces.append(Pawn("black", f"{col}7", self))

            #The order in a list of all of the pieces
        layout = [Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook]

        #loops through all of the pieces and puts them on the board
        for i, pieceClass in enumerate(layout):
            #Converts the index of the piece to the letter and add the white pieces to row one and black to row 8
            col = chr(ord('a') + i)
            self.whitePieces.append(pieceClass("white", f"{col}1", self))
            self.blackPieces.append(pieceClass("black", f"{col}8", self))

    #Moves a piece to new position
    def movePiece(self, piece: ChessPiece, newPos:str) -> bool:
        #Checks if piece can move to position
        if piece.canMoveTo(newPos):
            target = self.getPiecesAt(newPos)
            #gets the opponent's piece if it is at target
            if target and target.color != piece.color:
                self.removePiece(target)
            
            #Updates the position to new position
            piece.setPosition(newPos)
            return True
        #returns false if you can't move there
        return False

    def removePiece(self, piece: ChessPiece):
        if piece.color == "white":
            self.whitePieces.remove(piece)
        else:
            self.blackPieces.remove(piece)

    #It gets all the remaining pieces of that color
    def getPiecesLeft(self, color: str) -> list:
        #returns the white pieces if it is white
        if color == "white":
            return self.whitePieces
        else:
            return self.blackPieces
    
    #gets the piece located at the specific position on the board
    def getPiecesAt(self, position: str) -> ChessPiece:
        #keeps looping through all the pieces on the board
        for piece in self.whitePieces + self.blackPieces:
            #If the piece is at its given position then return it else return None
            if piece.getPosition() == position:
                return piece
        return None



