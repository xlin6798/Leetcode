/**
 * @param {number[][]} moves
 * @return {string}
 */
var tictactoe = function(moves) {
    let squares = [];
    for (let i = 0; i < moves.length; i++) {
        squares[moves[i][0] * 3  + moves[i][1]] = i % 2 === 0 ? "A" : "B"; 
    }
    const lines = [
        [0, 1, 2],
        [3, 4, 5],
        [6, 7, 8],
        [0, 3, 6],
        [1, 4, 7],
        [2, 5, 8],
        [0, 4, 8],
        [2, 4, 6],
    ];
    for (let i = 0; i < lines.length; i++) {
        const [a, b, c] = lines[i];
        if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c]) {
            return squares[a];
        }
    }
    return moves.length === 9 ? "Draw" : "Pending";
};