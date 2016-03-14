struct Item final {
  int weight;
  int value;
};

double get_max_knapsack_value(int capacity, std::vector <Item> items) {
  double value = 0.0;
    for (int i = 0; i < items.size()-1; i++) {
    for (int j=0; j < items.size()-1-i; j++) {
      if (static_cast <double>(items[j].value)/items[j].weight < static_cast <double>(items[j+1].value)/items[j+1].weight) {
        int temp1 = items[j].value;
        int temp2 = items[j].weight; 
        //change for elements
        items[j].value = items[j+1].value;
        items[j].weight = items[j+1].weight;

        items[j+1].value = temp1;
        items[j+1].weight = temp2;
      }
    }
  }
  // take items while there is empty space in knapsack
  for (auto &item:items) {
    if (capacity >= item.weight) {
      // can take full item and continue
      capacity -= item.weight;
      value += item.value;
    } else {
      value += (static_cast <double>(capacity) * item.value / item.weight);
      break;
    }
  }

  return value;
}

int main(void) {
  int number_of_items;
  int knapsack_capacity;
  std::cin >> number_of_items >> knapsack_capacity;
  std::vector <Item> items(number_of_items);
  for (int i = 0; i < number_of_items; i++) {
    std::cin >> items[i].value >> items[i].weight;
  }

  double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

  std::cout.precision(10);
  std::cout << max_knapsack_value << std::endl;
  return 0;
}