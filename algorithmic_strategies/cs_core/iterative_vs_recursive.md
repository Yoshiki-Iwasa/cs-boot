# Iteration vs recursion (factorial, tree search)

## Explain its definitional characteristics,
- **Iteration**: ループを使って繰り返し処理を行う。明示的なループ構造（例: forループ、whileループ）を使用して問題を解決する。
- **Recursion**: 関数が自身を呼び出すことで問題を解決する。基底条件で再帰を停止し、それ以外の場合に自身を呼び出す。

## Explain an example that demonstrates the paradigm including how this example satisfies the paradigm’s characteristics.
- **階乗計算**
  - **反復法**:
    ```rust
    fn factorial_iterative(n: u64) -> u64 {
        let mut result = 1;
        for i in 1..=n {
            result *= i;
        }
        result
    }
    ```
  - **再帰法**:
    ```rust
    fn factorial_recursive(n: u64) -> u64 {
        if n == 0 { 1 } else { n * factorial_recursive(n - 1) }
    }
    ```
  - 反復法は明示的なループを使い、再帰法は自身を呼び出して問題を解決。

## For each of the algorithms in the AL-Foundational unit, explain the paradigm used by the algorithm and how it exemplifies this paradigm.
- 例えばバイナリサーチは反復法と再帰法のどちらでも実装可能。反復法ではwhileループを使用し、再帰法では自身を呼び出す形で問題を分割して解決する。

## Given an algorithm, explain the paradigm used by the algorithm and how it exemplifies this paradigm.
- **マージソート**: 再帰法を用いる。リストを半分に分け、再帰的にそれぞれをソートし、最後にマージする。この再帰的分割が再帰の特徴を示している。

## Give a real-world problem, evaluate appropriate algorithmic paradigms and algorithms from these paradigms that address the problem including evaluating the tradeoffs among the paradigms and algorithms selected.
- 問題: 大規模なデータセットのソート
  - アルゴリズム: クイックソート（反復または再帰）、マージソート（再帰）
  - 評価: 反復法はスタックオーバーフローのリスクが少ないが、再帰法は自然で理解しやすいコードが可能。しかし、大規模データではスタックオーバーフローのリスクがある。

## Give examples of iterative and recursive algorithms that solve the same problem, explain the benefits and disadvantages of each approach.
- **二分木探索**
  - **反復法**: 明確な終了条件と状態管理が可能。
  - **再帰法**: コードがシンプルで直感的だが、深い木でスタックオーバーフローが起こりうる。

## Explain various approaches for addressing computational problems whose algorithmic solutions are exponential.
- **バックトラッキング**: 問題の潜在的な解の空間を探索し、解が見つかった場合はその場で戻る。
- **分枝限定法**: 探索空間を削減するために、解の上限や下限を計算し、有望でない部分を削除する。
- **ダイナミックプログラミング**: 問題を重複する小さな問題に分解し、それぞれの小さな問題を解いて全体の解を構築する。計算された結果はメモ化される。
