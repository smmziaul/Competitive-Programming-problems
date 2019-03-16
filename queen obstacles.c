// Given the obstacles, Find the total no. of moves a Queen can legally take in a Chess Board.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    int x;
    int y;
}position;
int board_size, board[25][25]={0}, i, j;

void print_board() {
    for(i=0;i<board_size;i++) {
        for(j=0;j<board_size;j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n\n");
    }
}

int calc_right(position queen1) {
    int queen1_y, moves=0;
    queen1_y = queen1.y+1;
    while(queen1_y < board_size) {
        if(board[queen1.x][queen1_y++]==1) {
            break;
        } else {
            moves++;
        }
    }
    printf("\nright moves: %d", moves);
    return moves;
}

int calc_left(position queen1) {
    int queen1_y, moves=0;
    for(queen1_y=queen1.y-1;queen1_y>=0;queen1_y--) {
        if(board[queen1.x][queen1_y]==1) {
            break;
        }else {
            moves++;
        }
    }
    printf("\nleft moves: %d", moves);
    return moves;
}

int calc_up(position queen1) {
    int queen1_x, moves=0;
    for(queen1_x=queen1.x-1;queen1_x>=0;queen1_x--) {
        if(board[queen1_x][queen1.y] == 1) {
            break;
        }else {
            moves++;
        }
    }
    printf("\nup moves: %d", moves);
    return moves;
}

int calc_down(position queen1) {
    int queen1_x, moves=0;
    for(queen1_x=queen1.x+1;queen1_x<board_size;queen1_x++) {
        if(board[queen1_x][queen1.y] == 1) {
            break;
        }else {
            moves++;
        }
    }
    printf("\ndown moves: %d", moves);
    return moves;
}

int calc_right_up(position queen1) {
    int queen1_x = queen1.x,
        queen1_y = queen1.y,
        moves = 0;
    while(--queen1_x>=0 && ++queen1_y<board_size) {
        if(board[queen1_x][queen1_y] == 1) {
            break;
        } else {
            moves++;
        }
    }
    printf("\nright up moves: %d", moves);
    return moves;
}

int calc_right_down(position queen1) {
    int queen1_x = queen1.x,
        queen1_y = queen1.y,
        moves = 0;
    while(++queen1_x<board_size && ++queen1_y<board_size) {
        if(board[queen1_x][queen1_y] == 1) {
            break;
        } else {
            moves++;
        }
    }
    printf("\nright down moves: %d", moves);
    return moves;
}


int calc_left_up(position queen1) {
    int queen1_x = queen1.x,
        queen1_y = queen1.y,
        moves = 0;
    while(--queen1_x>=0 && --queen1_y>=0) {
        if(board[queen1_x][queen1_y] == 1) {
            break;
        } else {
            moves++;
        }
    }
    printf("\nleft up moves: %d", moves);
    return moves;
}

int calc_left_down(position queen1) {
    int queen1_x = queen1.x,
        queen1_y = queen1.y,
        moves = 0;
    while(++queen1_x<board_size && --queen1_y>=0) {
        if(board[queen1_x][queen1_y] == 1) {
            break;
        } else {
            moves++;
        }
    }
    printf("\nleft down moves: %d", moves);
    return moves;
}


int main() {
    int obstacles_count, moves1, moves2, moves3, moves4, moves5, moves6, moves7, moves8, tot_moves;
    position obstacles[20], queen1;

    printf("\nthis pgm supports a 25x25 chess board and obstacles of count 20...!");
    printf("\nenter the board size: ");
    scanf("%d", &board_size);
    printf("\nenter the queen's position: ");
    scanf("%d%d", &queen1.x, &queen1.y);
    board[queen1.x][queen1.y]=9;
    printf("\nposition of queen is : \(%d, %d\)\n", queen1.x, queen1.y);
    print_board();
    printf("\nenter the no of obstacles: ");
    scanf("%d", &obstacles_count);
    for(i=0;i<obstacles_count;i++) {
        printf("\nenter the position of obstacle %d: ", i+1);
        scanf("%d%d", &obstacles[i].x, &obstacles[i].y);
        board[obstacles[i].x][obstacles[i].y] = 1;
    }
    printf("\nthe board is:\n");
    print_board();


    moves1 = calc_right(queen1);
    moves2 = calc_left(queen1);
    moves3 = calc_up(queen1);
    moves4 = calc_down(queen1);

    moves5 = calc_right_up(queen1);
    moves6 = calc_right_down(queen1);
    moves7 = calc_left_up(queen1);
    moves8 = calc_left_down(queen1);

    tot_moves = moves1+moves2+moves3+moves4+moves5+moves6+moves7+moves8;
    printf("\nTotal no. of moves a Queen can take legally, given obstacles: %d", tot_moves);

    getch();
    return 0;
}
