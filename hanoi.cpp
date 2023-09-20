#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
stringstream ssr;
//print statment
void Print(int n, char start, char end) {
  ssr << n << " " << start << " " << end << endl;
  return;
}
//3 peg cases
void MoveTower3(int disk, char source, char mid, char dest) {
  if (disk == 0) {
    // ends 
  } else {
    MoveTower3(disk - 1, source, dest, mid);
    Print(disk, source, dest); 
    MoveTower3(disk - 1, mid, source, dest);
  }
  return;
}
//4 peg cases
void MoveTower4(int disk, char source, char mid, char mid2, char dest) {
  if (disk == 0) {
    // end
  }
  else {
    MoveTower4(disk - 1, source, dest, mid, mid2);
    Print(disk, source, dest);

    // output
    // cout << disk << " " << source << " " << dest << endl;
    MoveTower4(disk - 1, mid2, mid, source, dest);
  }
}

//exception cases for 3 pegs
void SmallDisk3(int disk, char start, char mid, char end) {

  if (disk == -1) {

  } else {
    // SmallDisk3(disk-1, start, end, mid);
    Print(1, start, mid);
    SmallDisk3(disk - 1, mid, end, start);
  }
}

//exception cases for 4 pegs
void SmallDisk4(int disk, char start, char mid, char mid2, char end) {
  if (disk == 0) {
    // end
  } else {
    SmallDisk4(disk - 1, start, mid2, end, mid);
    Print(disk, start, end);
    SmallDisk4(disk - 1, mid, end, start, mid2);
    SmallDisk4(disk - 1, mid2, mid, start, end);
  }
}
//single disk cases
void SingleDisk(int pegs, char start) {
  if (pegs > 1) {
    Print(1, start, start + 1);
    SingleDisk(pegs - 1, start + 1);
  }
}
//5 peg cases
void MoveTower5(int disk, char start, char a, char b, char c, char end) {
  if (disk == 0) {
  } else {
    MoveTower5(disk - 1, start, end, a, b, c);
    Print(disk, start, end);
    MoveTower5(disk - 1, c, b, a, start, end);
  }
}
//3 or less disk for 5 pegs
void SmallDisk5(int disk, char start, char a, char b, char c, char end) {
  if (disk == 0) {
  } else {
    SmallDisk5(disk - 1, start, b, end, a, c);
    Print(disk, start, end);
    SmallDisk5(disk - 1, c, a, start, b, end);
    // SmallDisk5(disk-1,c,b,a,start,end);
  }
}
int main(int argc, char **argv) {
  // want a function the can recusrivley move em
  // and said function can also release from which location and where
  /*
  int test;
  //TESTING 3
  //MoveTower3(test, 'A', 'B', 'C');
  //SmallDisk3(test, 'A', 'B', 'C');
  //TESTING 4
  //MoveTower4(test, 'A', 'B', 'C', 'D');
  //SmallDisk4(test, 'A', 'B', 'C', 'D');
  //TESTING 5
  MoveTower5(test, 'A', 'B', 'C', 'D', 'E');
  SmallDisk5(test, 'A', 'B', 'C', 'D', 'E');
  
    */
  /// GETS THE INPUT AND STUFFFS

  string arg1; // PEGS
  string arg2; // DISK
  string file;
  arg1 = argv[1]; //PEGS
  arg2 = argv[2]; // DISk
  file = argv[3];
  int disk;
  int peg;
  peg = stoi(arg1);
  disk = stoi(arg2);
  //////////SINGLE DISK
  if (disk == 1) {
    SingleDisk(peg, 'A');
  }
  ////////////PEG 3 STUFFF
  if (peg == 3 && disk > 1) {
    if (disk > 1) {
      MoveTower3(disk, 'A', 'B', 'C');

    } else {
      SmallDisk3(disk, 'A', 'B', 'C');

    }
  }

  ///////////PEG 4 STUFFFF
  if (peg == 4 && disk > 1) {
    if (disk > 2) {
      MoveTower4(disk, 'A', 'B', 'C', 'D');
    } else {
      SmallDisk4(disk, 'A', 'B', 'C', 'D');
    }
  }

  /////peg 5 stufffs
  if (peg == 5 && disk > 1) {
    if (disk > 3) {

      MoveTower5(disk, 'A', 'B', 'C', 'D', 'E');
    } else {
      SmallDisk5(disk, 'A', 'B', 'C', 'D', 'E');
    }
  }

  ofstream fout;
  fout.open(file);
  fout<<ssr.str();
  fout.close();
  
  return 0;
}
