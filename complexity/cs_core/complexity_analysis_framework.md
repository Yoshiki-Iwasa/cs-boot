# Complexity Analysis Framework

## a. Best, average, and worst-case performance of an algorithm
- アルゴリズムのパフォーマンスは、入力に対するアルゴリズムの動作時間を示す
- 最良ケース（Best-case）：入力がアルゴリズムにとって最も好都合な場合の動作時間
  - 例：線形探索では、目的の要素が最初に見つかる場合
- 平均ケース（Average-case）：様々な入力に対するアルゴリズムの平均的な動作時間
  - 例：バブルソートでは、平均的な入力に対する比較回数の平均値
- 最悪ケース（Worst-case）：入力がアルゴリズムにとって最も不利な場合の動作時間
  - 例：クイックソートでは、毎回最悪のピボットが選ばれる場合

## b. Empirical and relative (Order of Growth) measurements
- 実測値（Empirical measurement）：実際のデータを使ってアルゴリズムのパフォーマンスを測定
  - 実際の実行時間やメモリ使用量を計測
- 成長のオーダー（Order of Growth）：入力サイズが増加するにつれてアルゴリズムの動作時間やメモリ使用量がどのように増加するかを示す
  - Big-O表記：最悪ケースの上限を示す
  - Ω（Omega）表記：最良ケースの下限を示す
  - Θ（Theta）表記：平均的な動作時間を示す

## c. Input size and primitive operations
- 入力サイズ（Input size）：アルゴリズムが処理するデータの量
  - 例：配列の長さ、グラフの頂点数
- プリミティブ操作（Primitive operations）：アルゴリズムの基本的な操作
  - 例：比較、代入、加算

## d. Time and space efficiency
- 時間効率（Time efficiency）：アルゴリズムが動作を完了するまでに必要な時間
  - 時間計算量で表される
  - 例：O(n)、O(n^2)
- 空間効率（Space efficiency）：アルゴリズムが動作を完了するまでに必要なメモリ
  - 空間計算量で表される
  - 例：O(1)（定数空間）、O(n)（線形空間）
