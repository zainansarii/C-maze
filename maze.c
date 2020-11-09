#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 10
#define WIDTH 10

#define START_X 1
#define START_Y 0

#define W '#'
#define H ' '
#define X '*'
#define P '.'
#define T 'T'

enum bool{true, false};
typedef enum bool bool;

void print_maze(char a[HEIGHT][WIDTH]);
bool explore(int x, int y, char a[HEIGHT][WIDTH]);

int main(void)
{
  char maze[HEIGHT][WIDTH] = {
  {W,H,W,W,W,W,W,W,W,W},
  {W,H,H,H,H,W,W,H,H,W},
  {W,W,W,H,W,W,W,H,W,W},
  {W,W,W,H,H,H,H,H,W,W},
  {W,W,W,H,W,W,W,W,W,W},
  {W,H,H,H,H,H,H,H,W,W},
  {W,H,W,W,H,H,W,H,W,W},
  {W,H,W,W,H,H,W,H,W,W},
  {W,H,H,H,H,H,H,H,W,W},
  {W,W,W,X,W,W,W,W,W,W}};
  print_maze(maze);
  printf("\n");

  if(explore(START_X, START_Y, maze) == true){
    print_maze(maze);
  }
  else{
    printf("No valid route found\n");
  }
  return 0;
}

void print_maze(char a[HEIGHT][WIDTH])
{
  int i, j;
  for(i = 0; i < HEIGHT; i++){
    for(j = 0; j < WIDTH; j++){
      if(a[i][j] == T){
        a[i][j] = P;
      }
      printf("%c", a[i][j]);
    }
    printf("\n");
  }
}

bool explore(int x, int y, char a[HEIGHT][WIDTH])
{
  if(a[y][x] == X){
    return true;
  }
  /*else if check whether position is a wall/out of bounds (between 0 and max)*/
  if(y < 0 || y >= HEIGHT || x < 0 || x >= WIDTH){
    return false;
  }
  if(a[y][x] == W){
    return false;
  }
  /*tell your function don't go back to where you've been*/
  if(a[y][x] == T){
    return false;
  }
  a[y][x] = T;
  /*recursively check north/east/south/west*/
  if(explore(x, y+1, a) == true){
    return true;
  }
  if(explore(x, y-1, a) == true){
    return true;
  }
  if(explore(x+1, y, a) == true){
    return true;
  }
  if(explore(x-1, y, a) == true){
    return true;
  }
  a[y][x] = H;
  return false;
}
