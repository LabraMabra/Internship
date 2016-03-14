int get_levenshtein_distance(const std::string &str1, const std::string &str2) {
  size_t size1 = str1.size();
  size_t size2 = str2.size();
  int c = 0;

  if (str1.empty() || str2.empty()) {
    return size1 + size2;
  }

  std::vector< std::vector<int> > dd(size1+1);

  for (size_t i = 0; i <= size1; i++) {
    dd[i].resize(size2+1);
    dd[i][0] = i;
  }

  for (size_t j = 0; j <= size2; j++) {
      dd[0][j] = j;
  }
  
  for (size_t i = 1; i <= size1; i++) {
    for (size_t j = 1; j <= size2; j++) {
      c = (str1[i-1] != str2[j-1]);
      dd[i][j] = std::min({dd[i-1][j] + 1, dd[i][j-1] + 1, dd[i-1][j-1] + c});
    }
  }
  
  return dd[size1][size2];
}

int main(void) {
  std::string str1;
  std::string str2;

  std::cin >> str1 >> str2;  


  std::cout << get_levenshtein_distance(str1, str2) << std::endl;
}