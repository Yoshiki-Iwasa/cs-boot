# Search Algorithms

# Binary Search

## explain step-by-step how the algorithm operates.
- **初期設定**: 配列と目標値を定義。左端（L）を0、右端（R）をn-1に設定。
- **繰り返し処理**: LがR以下である間、中間点mを計算（(L + R) / 2の床関数）。
- **比較と範囲の更新**: 目標値と中間点の値を比較し、探索範囲を半分に絞る。目標値が中間点の値より小さい場合、Rをm-1に更新。大きい場合、Lをm+1に更新。
- **結果の確認**: 目標値が見つかればそのインデックスmを返す。見つからなければ失敗を返す。

## For each algorithmic approach, apply a prototypical example of the approach
```rust
fn binary_search(arr: &[i32], target: i32) -> Option<usize> {
    let mut left = 0;
    let mut right = arr.len() - 1;
    while left <= right {
        let mid = (left + right) / 2;
        if arr[mid] == target {
            return Some(mid);
        } else if arr[mid] < target {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    None
}
```

## Given requirements for a problem, develop multiple solutions using various data structures and algorithms. Subsequently, evaluate the suitability, strengths, and weaknesses selecting an approach that best satisfies the requirements.

バイナリサーチは整列済み配列で最も効率的。探索時間はO(log n)。しかし、配列の事前整列が必要。

## Explain factors beyond computational efficiency that influence the choice of algorithms, such as programming time, maintainability, and the use of application-specific patterns in the input data.

バイナリサーチは配列が頻繁に更新されない場合に適している。データが頻繁に変更される場合、再整列のコストが問題となる可能性がある。

# Depth-first Search

## explain step-by-step how the algorithm operates.
- **初期設定**: スタック（または再帰関数）を使用して、訪問するノードを管理。スタートノードをスタックに追加。
- **探索の開始**: スタックが空でない間、スタックからノードをポップし、訪問。
- **隣接ノードのチェック**: 訪問したノードの隣接ノードを調べ、未訪問のノードがあればスタックにプッシュ。
- **バックトラッキング**: すべての隣接ノードを訪問した後、スタックから次のノードをポップし、探索を継続。

## For each algorithmic approach, apply a prototypical example of the approach
```python
def dfs(graph, start):
    visited, stack = set(), [start]
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            stack.extend([n for n in graph[vertex] if n not in visited])
    return visited
```

## Given requirements for a problem, develop multiple solutions using various data structures and algorithms. Subsequently, evaluate the suitability, strengths, and weaknesses selecting an approach that best satisfies the requirements.

- 再帰的アプローチ: 自然かつ簡単に理解可能。ただし、大規模なグラフではスタックオーバーフローのリスク。
- 反復的アプローチ: スタックを明示的に使用。スタックオーバーフローのリスクが少ないが、コードが複雑になることがある。

## Explain factors beyond computational efficiency that influence the choice of algorithms, such as programming time, maintainability, and the use of application-specific patterns in the input data.

- プログラミング時間と保守性: 再帰的アプローチは書きやすく理解しやすいが、大規模なデータに対しては非効率的かつリスクが伴う。
- 入力データのパターン: グラフの種類（密か疎か）やサイズによって最適な探索方法が異なる。大規模で疎なグラフでは反復的アプローチが有効。

# # Breadth-first Search

## explain step-by-step how the algorithm operates.
- **初期設定**: キューを用意し、スタートノードをキューに追加。
- **探索の開始**: キューが空になるまで、キューからノードを取り出し、訪問。
- **隣接ノードのチェック**: 取り出したノードに隣接する未訪問のノードを全てキューに追加。
- **ループの継続**: 新しいノードがキューに追加されるたびに上記を繰り返す。

## For each algorithmic approach, apply a prototypical example of the approach
```rust
use std::collections::VecDeque;

fn breadth_first_search(graph: &Vec<Vec<usize>>, start: usize) -> Vec<usize> {
    let mut visited = vec![false; graph.len()];
    let mut queue = VecDeque::new();
    let mut order = vec![];

    visited[start] = true;
    queue.push_back(start);

    while let Some(current) = queue.pop_front() {
        order.push(current);
        for &neighbor in &graph[current] {
            if !visited[neighbor] {
                visited[neighbor] = true;
                queue.push_back(neighbor);
            }
        }
    }
    order
}
```


## Given requirements for a problem, develop multiple solutions using various data structures and algorithms. Subsequently, evaluate the suitability, strengths, and weaknesses selecting an approach that best satisfies the requirements.

ブレッドス・ファースト探索は、最短経路や探索問題に適しているが、メモリ消費が大きいため、大規模なグラフでは不適切かもしれない。

## Explain factors beyond computational efficiency that influence the choice of algorithms, such as programming time, maintainability, and the use of application-specific patterns in the input data.

- メモリ使用: 大規模グラフではメモリ消費が増大。
- 実装の簡潔さ: BFSは実装が直感的で理解しやすいが、キュー管理に注意が必要。
