# Asymptotic complexity analysis (average and worst-case bounds)

## Using examples, explain each of the foundational complexity classes in this unit.

### Big-O, Big-Omega, and Big-Theta formal notations
- **Big-O (O)**: 上限の複雑さを示す。最悪の場合のシナリオでの成長率を表す。
  - 例: あるアルゴリズムがO(n)ならば、入力サイズがnに対して最大で線形に増加する。
- **Big-Omega (Ω)**: 下限の複雑さを示す。最良の場合のシナリオでの成長率を表す。
  - 例: あるアルゴリズムがΩ(n)ならば、入力サイズがnに対して少なくとも線形に増加する。
- **Big-Theta (Θ)**: 上下限の複雑さを示す。平均的なシナリオでの成長率を表す。
  - 例: あるアルゴリズムがΘ(n)ならば、入力サイズがnに対して線形に増加する。

### Foundational Complexity Classes and Representative Examples/Problems
#### i. O(1) Constant (e.g., array access)
- 説明: 入力サイズに関わらず、実行時間が一定のアルゴリズム。
- 例: 配列の特定のインデックスへのアクセス。

#### ii. O(log2 n) Logarithmic (e.g., binary search)
- 説明: 入力サイズが増加するにつれて、実行時間が対数的に増加するアルゴリズム。
- 例: 二分探索。

#### iii. O(n) Linear (e.g., linear search)
- 説明: 入力サイズに比例して実行時間が増加するアルゴリズム。
- 例: 線形探索。

#### iv. O(n log2 n) Log Linear (e.g., mergesort)
- 説明: 実行時間がnとlog nの積に比例して増加するアルゴリズム。
- 例: マージソート。

#### v. O(n^2) Quadratic (e.g., selection sort)
- 説明: 実行時間が入力サイズの二乗に比例して増加するアルゴリズム。
- 例: 選択ソート。

#### vi. O(n^c) Polynomial (e.g., O(n^3) Gaussian elimination)
- 説明: 実行時間が入力サイズの多項式に比例して増加するアルゴリズム。
- 例: ガウス消去法 (O(n^3))。

#### vii. O(2^n) Exponential (e.g., Knapsack, Satisfiability (SAT),Traveling Sales-Person (TSP), all subsets)
- 説明: 実行時間が入力サイズの指数関数に比例して増加するアルゴリズム。
- 例: ナップサック問題、充足可能性問題 (SAT)、巡回セールスマン問題 (TSP)。

#### viii. O(n!) Factorial (e.g., Hamiltonian circuit, all permutations)
- 説明: 実行時間が入力サイズの階乗に比例して増加するアルゴリズム。
- 例: ハミルトンサーキット、全ての順列生成。

## For each foundational complexity class in this unit, explain an algorithm that demonstrates the associated runtime complexity.

- **O(1)**: 配列のインデックスアクセスは定数時間で実行される。
- **O(log2 n)**: 二分探索はデータを半分に分割するので対数時間で実行される。
- **O(n)**: 線形探索は各要素を一度ずつ確認するので線形時間で実行される。
- **O(n log2 n)**: マージソートは分割と統合のステップを持ち、それぞれがlog nとnの時間を要するので、合計でn log nの時間がかかる。
- **O(n^2)**: 選択ソートは各要素に対して他の全要素を比較するので二乗時間で実行される。
- **O(n^c)**: ガウス消去法は行列のサイズに比例して多項式時間で実行される。
- **O(2^n)**: ナップサック問題は全ての部分集合を評価するので指数関数時間で実行される。
- **O(n!)**: 全ての順列生成は階乗時間で実行される。

## For each algorithm in the AL-Foundational unit, explain its runtime complexity class and why it belongs to this class.

- **配列のインデックスアクセス (O(1))**: 特定のインデックスに直接アクセスするため、時間は一定。
- **二分探索 (O(log2 n))**: データを半分に分割しながら検索するため、対数時間。
- **線形探索 (O(n))**: 各要素を順に確認するため、線形時間。
- **マージソート (O(n log2 n))**: 分割と統合のステップがあり、それぞれがnとlog nの時間を要するため、n log n時間。
- **選択ソート (O(n^2))**: 各要素に対して他の全要素を比較するため、二乗時間。
- **ガウス消去法 (O(n^3))**: 行列のサイズに比例して操作を行うため、多項式時間。
- **ナップサック問題 (O(2^n))**: 全ての部分集合を評価するため、指数関数時間。
- **全ての順列生成 (O(n!))**: 全ての順列を生成するため、階乗時間。
