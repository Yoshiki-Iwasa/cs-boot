# Transitive closure

## Explain a prototypical example of the algorithm
例：空港間の直行便があるかどうかの関係を表す。トランジティブクロージャを用いて、一回以上の乗り継ぎを含む経路が可能かを判断する。

## Explain step-by-step how the algorithm operates.
1. 全ての頂点間の関係を無限大で初期化し、直接の関係のある頂点の距離を設定。
2. 三重ループを用いて、全頂点ペアの間に最短の経路を見つける。
3. 新しい中間頂点を通ることで距離が短くなる場合、その距離で更新。

## Relationship between Floyd–Warshall algorithm
フロイド・ワーシャルアルゴリズムは、トランジティブクロージャを計算する方法の一つとして使用される。各頂点を中間点として利用し、全ペアの最短経路を求める点で類似している。


# Topological sorting

## Explain a prototypical example of the algorithm
トポロジカルソートは、依存関係に基づいてタスクやデータを順序付ける手法。例えば、プロジェクトのタスクを依存関係に従って順序づける際に使用される。

## Explain step-by-step how the algorithm operates.
1. 全ての頂点の入次数を計算し、入次数が0の頂点をキューに入れる。
2. キューから頂点を取り出し、該当頂点から出るエッジを削除し、関連する頂点の入次数を減らす。
3. 入次数が0になった新たな頂点をキューに追加。
4. グラフにエッジがなくなるまでこのプロセスを繰り返す。

## Code sample
```rust
use std::collections::{VecDeque, HashSet};

fn topological_sort(adj_list: Vec<Vec<usize>>) -> Vec<usize> {
    let mut in_degree = vec![0; adj_list.len()];
    let mut queue = VecDeque::new();
    let mut order = Vec::new();

    // Compute in-degrees
    for nodes in &adj_list {
        for &node in nodes {
            in_degree[node] += 1;
        }
    }

    // Initialize the queue with nodes having zero in-degree
    for (i, &degree) in in_degree.iter().enumerate() {
        if degree == 0 {
            queue.push_back(i);
        }
    }

    // Process the graph
    while let Some(node) = queue.pop_front() {
        order.push(node);
        for &neighbor in &adj_list[node] {
            in_degree[neighbor] -= 1;
            if in_degree[neighbor] == 0 {
                queue.push_back(neighbor);
            }
        }
    }

    if order.len() == adj_list.len() {
        order
    } else {
        vec![]  // Cycle detected or incomplete graph
    }
}
```

## usecase
プロジェクトのタスク管理、スプレッドシートのセル計算順序の決定、コンパイラのタスク実行順序など、依存関係に基づく順序付けが必要な多くの場面で使用される。
