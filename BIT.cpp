int n;
const int N = 1000000;
int Tree[1+N];

/*
    idx >= 1
*/

//cumulative sum
int read(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += Tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

//updateing notes in tree
void update(int idx, int val) {
  while (idx <= n) {
    Tree[idx] += val;
    idx += (idx & -idx);
  }
}