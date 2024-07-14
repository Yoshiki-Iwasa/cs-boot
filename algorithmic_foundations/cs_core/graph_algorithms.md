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

# Minimum spanning tree

## explain its definition, properties, representation(s), and associated ADT operations.
- 最小全域木（MST）は、与えられた連結で重み付きの無向グラフにおいて、全ての頂点を最小の合計エッジ重みでつなぐエッジのサブセット。
- MSTはサイクルを含まず、グラフの全頂点を含む。
- 重要な性質として、MSTの全エッジの重みの合計が最小であること。
- MSTを見つけるアルゴリズムには、プリムのアルゴリズムやクラスカルのアルゴリズムがある。

## explain step-by-step how the ADT operations associated with the data structure transform it.
- プリムのアルゴリズム: 頂点を一つ選び、最小の重みのエッジを選んで成長させることでMSTを構築。
- クラスカルのアルゴリズム: 全エッジを重みの順にソートし、サイクルを形成しないようにエッジを選択してMSTを構築。

## For each algorithmic approach, apply a prototypical example of the approach
```rust
use std::collections::HashSet;

fn kruskal(nodes: usize, edges: Vec<(i32, usize, usize)>) -> Vec<(i32, usize, usize)> {
    let mut parent = (0..nodes).collect::<Vec<_>>();
    let mut rank = vec![0; nodes];

    fn find(parent: &mut Vec<usize>, i: usize) -> usize {
        if parent[i] != i {
            parent[i] = find(parent, parent[i]);
        }
        parent[i]
    }

    fn union(parent: &mut Vec<usize>, rank: &mut Vec<i32>, x: usize, y: usize) {
        let xroot = find(parent, x);
        let yroot = find(parent, y);
        if rank[xroot] < rank[yroot] {
            parent[xroot] = yroot;
        } else if rank[xroot] > rank[yroot] {
            parent[yroot] = xroot;
        } else {
            parent[yroot] = xroot;
            rank[xroot] += 1;
        }
    }

    let mut result = vec![];
    let mut e = 0;
    let mut i = 0;
    let mut sorted_edges = edges;
    sorted_edges.sort_by_key(|k| k.0);

    while e < nodes - 1 && i < sorted_edges.len() {
        let (weight, u, v) = sorted_edges[i];
        i += 1;
        let x = find(&mut parent, u);
        let y = find(&mut parent, v);
        if x != y {
            result.push((weight, u, v));
            union(&mut parent, &mut rank, x, y);
            e += 1;
        }
    }
    result
}
```

## Given requirements for a problem, develop multiple solutions using various data structures and algorithms. Subsequently, evaluate the suitability, strengths, and weaknesses selecting an approach that best satisfies the requirements.

- ネットワーク設計、回路設計、森林管理など、様々な分野での応用が可能。
- クラスカルのアルゴリズムはエッジが少ないグラフに効果的、プリムのアルゴリズムは密なグラフに適している。

## Explain factors beyond computational efficiency that influence the choice of algorithms, such as programming time, maintainability, and the use of application-specific patterns in the input data.

- アルゴリズムの選択は、グラフの種類（密または疎）、利用可能なデータ構造、特定のアプリケーションの要件に依存する。
- 実装の複雑さ、メンテナンスのしやすさも重要な要素であり、効率だけでなくこれらの要素を考慮する必要がある。

### クラスカル法とプリム法の比較

#### クラスカル法
- **基本アプローチ**: エッジ中心。全エッジをコストの昇順でソートし、サイクルを形成しないものを順に選択。
- **データ構造**: 重み付きエッジリストとユニオンファインド。
- **適用性**: エッジが比較的少ない疎なグラフに効果的。
- **計算コスト**: O(E log E) で、E はエッジの数。

#### プリム法
- **基本アプローチ**: 頂点中心。開始頂点を選び、接続された最小のエッジを持つ頂点を順に選択していく。
- **データ構造**: 隣接リストと優先度付きキュー（通常はバイナリヒープ）。
- **適用性**: 頂点の数が多い密なグラフに適している。
- **計算コスト**: O((V + E) log V) で、V は頂点の数、E はエッジの数。

#### 共通点
- どちらも非負のエッジ重みを持つ無向グラフで最小全域木を求めるアルゴリズム。
- 最終的な最小全域木の重みの合計は同じ。

#### 選択の基準
- クラスカル法はエッジの数が少ないとき、つまり疎なグラフで効率的。
- プリム法は頂点が密接に結ばれている場合（密なグラフ）に効率的。
- 使用するデータ構造によるメモリ使用量と処理速度の違いも選択の要因となる。
