int main() {
 int num_count_1;
 std::cin >> num_count_1;
 std::vector<int> seq1(num_count_1);
 for (size_t i = 0; i < num_count_1; ++i) {
  std::cin >> seq1[i];
 }
 
 int num_count_2;
 std::cin >> num_count_2;
 std::vector<int> seq2(num_count_2);
 for (size_t i = 0; i < num_count_2; ++i) {
  std::cin >> seq2[i];
 }
 
 int num_count_3;
 std::cin >> num_count_3;
 std::vector<int> seq3(num_count_3);
 for (size_t i = 0; i < num_count_3; ++i) {
  std::cin >> seq3[i];
 }

 std::vector< std::vector< std::vector<int> > > d( num_count_1 + 1 );
  
 for ( size_t i = 0; i <= num_count_1; ++i ) {
  d[i].resize( num_count_2 + 1 );
  for ( size_t j = 0; j <= num_count_2; ++j) {
   d[i][j].resize( num_count_3 + 1 );
  }
 }
 
 for ( size_t i = 0; i <= num_count_1; ++i ) {
  d[i][0][0] = 0;
 }
 for ( size_t i = 0; i <= num_count_2; ++i ) {
  d[0][i][0] = 0;
 }
 for ( size_t i = 0; i <= num_count_3; ++i ) {
  d[0][0][i] = 0;
 }
 
 for ( size_t i = 1; i <= num_count_1; ++i) {
  for ( size_t j = 1; j <= num_count_2; ++j ) {
   for ( size_t k = 1; k <= num_count_3; ++k ) {
    if ( seq1[i-1] == seq2[j-1] && seq1[i-1] == seq3[k-1] ) {
     d[i][j][k] = 1 + d[i-1][j-1][k-1];
    }
    else {
     int max = std::max( { d[i-1][j][k], d[i][j-1][k], d[i][j][k-1] } );
     d[i][j][k] = max;
     
    }
   }
  }
 }
 
 std::cout << d[num_count_1][num_count_2][num_count_3];
}