typedef std::pair <int, int> Segment;

std::vector <int> get_covering_set(std::vector <Segment> segments) {
  std::vector <int> result;

  // bubble sort for segments
  for (int i = 0; i < segments.size()-1; i++) {
    for (int j=0; j < segments.size()-1-i; j++) {
      if (segments[j].second > segments[j+1].second) {
        int temp1 = segments[j].first;
        int temp2 = segments[j].second; 
        //change for elements
        segments[j].first = segments[j+1].first;
        segments[j].second = segments[j+1].second;

        segments[j+1].first = temp1;
        segments[j+1].second = temp2;
      }
    }
  }

  //compare
  result.push_back(segments[0].second);
  int prevPoint = segments[0].second;
  for (std::size_t i = 1; i < segments.size(); i++) {
        if (prevPoint < segments[i].first) {
        result.push_back(segments[i].second);
        prevPoint = segments[i].second;
    }
  }

  return result;
}

int main(void) {
  int segments_count;
  //считываем к-во отрезков
  std::cin >> segments_count;
  //организовываем вектор отрезков
  std::vector <Segment> segments(segments_count);
  //считываем отрезки (по началу и концу) в вектор отрезков
  for (int i = 0; i < segments_count; i++) {
    std::cin >> segments[i].first >> segments[i].second;
  }
  //заводим вектор точек и записываем туда найденные функцией точки
  std::vector <int> points = get_covering_set(segments);
  //выводим кол-во точек
  std::cout << points.size() << std::endl;
  //выводим сами точки
  for (std::size_t i = 0; i < points.size(); i++) {
    std::cout << points[i] << " ";
  }
  std::cout << std::endl;
}