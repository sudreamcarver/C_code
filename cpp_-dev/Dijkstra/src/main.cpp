#include <cstddef>
#include <iostream>
#include <limits.h>
#include <limits>
#include <queue>
#include <vector>

struct edge {
  int to{};
  int cost{};
};

std::vector<std::vector<edge>> line{};

void AddLline(int from, int to, int cost) {
  line[static_cast<size_t>(from)].push_back({to, cost});
  // it can go back
  line[static_cast<size_t>(to)].push_back({from, cost});
}

void map() {
  AddLline(0, 1, 4);
  AddLline(0, 2, 7);
  AddLline(0, 3, 2);

  AddLline(1, 4, 3);

  AddLline(2, 3, 1);
  AddLline(2, 5, 6);

  AddLline(3, 4, 2);
  AddLline(3, 5, 5);
  AddLline(3, 6, 1);

  AddLline(4, 6, 7);

  AddLline(5, 6, 2);
}

int main() {
  int n{7};
  line.resize(static_cast<size_t>(n));
  const int INF{std::numeric_limits<int>::max()};
  map();

  std::vector<int> distance(static_cast<size_t>(n), INF);
  std::vector<int> prev(static_cast<size_t>(n), -1);

  distance[0] = 0;

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq{};

  pq.push({0, 0});

  while (!pq.empty()) {
    auto [current_distance, u]{pq.top()};
    pq.pop();
    if (current_distance > distance[static_cast<size_t>(u)]) {
      continue;
    }

    for (const auto &edge : line[static_cast<size_t>(u)]) {
      int targetNode = {edge.to};
      int cost{edge.cost};
      int newDistance{current_distance + cost};

      if (newDistance < distance[static_cast<size_t>(targetNode)]) {
        distance[static_cast<size_t>(targetNode)] = newDistance;
        prev[static_cast<size_t>(targetNode)] = u;
        pq.push({newDistance, targetNode});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << "distance from 0 to " << i << "=";
    if (distance[static_cast<size_t>(i)] == INF) {
      std::cout << "unreachable";
    } else {
      std::cout << distance[static_cast<size_t>(i)];
    }
    std::cout << std::endl;
  }
}
