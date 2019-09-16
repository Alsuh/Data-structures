#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

const char blank = ' ';
const char step = '@';
const int MAX_ROWS = 38;     // Maximum number of rows in a maze
const int MAX_COLS = 78;     // Maximum number of columns in a maze

typedef char maze[MAX_ROWS][MAX_COLS];   // As big as a maze can be.

void open_input_file ( ifstream &in_f );
// Postcondition: A file named by the used has been opened for input.

void read_maze ( ifstream &f, maze m, int &rows, int &cols );
// Precondition: f represents a file opened for input that contains the
//   representation of a maze.
// Postcondition: The two-dimensional array m[][] contains the representation
//   of a maze as *'s and blanks. The maze's dimensions have been returned
//   in the parameters rows and cols.

void print_maze ( maze m, int rows, int cols );
// Precondition: The two-dimensional array m[][] holds the representation
//   of a maze and possibly a path through it. The maze's dimensions are
//   rows x cols.

void find_paths ( maze m, int r, int c, int rows, int cols );
// Precondition: The two-dimensional array m[][] holds the representation
//   of an array as *'s and blanks. The maze's dimensions are rows x cols.
//   The path has reached position (r,c).
// Postcondition: For each path thorugh the maze, the maze and that path have
//   been printed to the terminal.

int main()
{
  ifstream in_f;         // The input file
  int rows, cols;        // The maze's dimensions
  maze m;                // The maze

  // Read in the maze.
  open_input_file ( in_f );
  read_maze ( in_f, m, rows, cols );
  in_f.close();

  // Echo the maze.
  cout << "The maze:" << endl;
    print_maze(m,rows,cols);cout<<endl;

  // Find and display all paths through the maze.
  m[0][1] = step;
  find_paths ( m,1,0, rows, cols );

  return EXIT_SUCCESS;
}

void open_input_file ( ifstream &in_f )
{
  char input_file_name[80];

  do
  { cout << "Enter input file name: ";
    cin >> input_file_name;
    in_f.open(input_file_name);
  } while ( in_f.fail() );
}

void read_maze ( ifstream &f, maze m, int &rows, int &cols )
{
  int r, c;
  char dummy;

  f >> r;
  f >> c;
  f.get(dummy);
  
  for ( int i=0; i<=r; ++i )
  {
    for ( int j=0; j<=c; ++j )
      f.get(m[i][j]);
    f.get(dummy);  // eol
  }
  rows = r;
  cols = c;
}

void print_maze ( maze m, int rows, int cols )
{
  for (int i=0; i<=rows; ++i)
  {
    for (int j=0; j<=cols; ++j)
      cout << m[i][j];
    //cout << endl;
  }
  cout << endl;
}

void find_paths ( maze m, int r, int c, int rows, int cols )
{
  if ( r == rows-1 )
    print_maze(m,rows,cols);
  else
  {
    if ( r > 0 && m[r-1][c] == blank )  // UP
    {
      m[r-1][c] = step;
      find_paths(m,r-1,c,rows,cols);
      m[r-1][c] = blank;
    }
    if ( m[r+1][c] == blank )  // DOWN
    {
      m[r+1][c] = step;
      find_paths(m,r+1,c,rows,cols);
      m[r+1][c] = blank;
    }
    if ( m[r][c-1] == blank )  // LEFT
    {
      m[r][c-1] = step;
      find_paths(m,r,c-1,rows,cols);
      m[r][c-1] = blank;
    }
    if ( m[r][c+1] == blank )  // RIGHT
    {
      m[r][c+1] = step;
      find_paths(m,r,c+1,rows,cols);
      m[r][c+1] = blank;
    }
  }
}

