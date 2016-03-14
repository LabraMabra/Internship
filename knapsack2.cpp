int ks_bu(int w, const std::vector<int> &wis) {
  size_t size = wis.size();

  std::vector< std::vector<int> > dd(w+1);

  for (int j = 0; j <= w; j++) {
    dd[j].resize(size+1);
    dd[j][0] = 0;
  }

  for (int i = 0; i <= size; i++) {
      dd[0][i] = 0;
  }
  
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= w; j++) {
      dd[j][i] = dd [j][i-1];
      if ( wis[i-1] <= j)
      dd[j][i] = std::max(dd[j][i], dd[j-wis[i-1]][i-1] + wis[i-1]);
    }
  }
  
  return dd[w][size];
}

int main(void) {

  int w_total;
  int number_count;
  std::cin >> w_total >> number_count;
  std::vector<int> wis(number_count);
  for (int i = 0; i < number_count; i++) {
    std::cin >> wis[i];
  }
  
  std::cout << ks_bu(w_total, wis) << std::endl;
}