# Graph Algorithms

# Shortest path

# Dijkstra's algorithm

## explain step-by-step how the algorithm operates.
- 全ての頂点の距離を無限大に設定し、開始頂点だけを0にする。
- 未訪問の頂点の中から最小の距離の頂点を選び、訪問済みとする。
- 選ばれた頂点の隣接頂点の距離を更新する。より小さい距離が見つかれば、その距離で更新。
- 全ての頂点を訪問するか、特定の頂点までの最短経路を求めるまで繰り返す。

## For each algorithmic approach, apply a prototypical example of the approach
```rust
use std::collections::{BinaryHeap, HashMap};

fn dijkstra(graph: &HashMap<usize, Vec<(usize, u32)>>, start: usize) -> HashMap<usize, u32> {
    let mut distances = HashMap::new();
    let mut priority_queue = BinaryHeap::new();

    for (key, _) in graph.iter() {
        distances.insert(*key, u32::MAX);
    }
    distances.insert(start, 0);
    priority_queue.push((std::cmp::Reverse(0), start));

    while let Some((std::cmp::Reverse(current_distance), current_vertex)) = priority_queue.pop() {
        if current_distance > distances[&current_vertex] {
            continue;
        }

        if let Some(neighbors) = graph.get(&current_vertex) {
            for &(neighbor, weight) in neighbors.iter() {
                let distance = current_distance + weight;
                if distance < distances[&neighbor] {
                    distances.insert(neighbor, distance);
                    priority_queue.push((std::cmp::Reverse(distance), neighbor));
                }
            }
        }
    }

    distances
}
```

## Given requirements for a problem, develop multiple solutions using various data structures and algorithms. Subsequently, evaluate the suitability, strengths, and weaknesses selecting an approach that best satisfies the requirements.

Dijkstraのアルゴリズムは非負の重みがあるグラフに適しており、効率的に最短経路を見つけることができる。

## Explain factors beyond computational efficiency that influence the choice of algorithms, such as programming time, maintainability, and the use of application-specific patterns in the input data.

Dijkstraのアルゴリズムは実装が複雑であり、優先度付きキューの使用が必要であるため、メンテナンスが難しい場合がある。しかし、最短経路問題には最も一般的な解法であり、多くのライブラリでサポートされている。

# Floyd–Warshall algorithm

## explain step-by-step how the algorithm operates.
- 各頂点間の距離を無限大で初期化し、各頂点の自己距離を0に設定。
- 三重のループを使用して、全頂点ペアの最短経路を計算。中間頂点を一つずつ増やしながら最短距離を更新。
- 各ステップで、新しい中間頂点を経由する場合の距離が現在の距離より短いかを確認し、必要に応じて更新。

## For each algorithmic approach, apply a prototypical example of the approach
```rust
fn floyd_warshall(weights: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let n = weights.len();
    let mut dist = weights.clone();
    for k in 0..n {
        for i in 0..n {
            for j in 0..n {
                if dist[i][k] + dist[k][j] < dist[i][j] {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    dist
}
```

## Given requirements for a problem, develop multiple solutions using various data structures and algorithms. Subsequently, evaluate the suitability, strengths, and weaknesses selecting an approach that best satisfies the requirements.

フロイド・ワーシャルアルゴリズムは、すべての頂点間の最短経路を求めるのに適しており、特に重み付きグラフにおいて有効。

## Explain factors beyond computational efficiency that influence the choice of algorithms, such as programming time, maintainability, and the use of application-specific patterns in the input data.

このアルゴリズムは実装が比較的単純であり、すべての最短経路を一度に計算できるため、多くの実用的なシナリオで有効です。
