# Brute-Force (e.g., linear search, selection sort, traveling salesperson, knapsack)

## Explain its definitional characteristics,
- 総当たり探索は、すべての可能性を順番に試して解を見つける方法。最も単純だが、問題のサイズが大きくなると非効率。

## Explain an example that demonstrates the paradigm including how this example satisfies the paradigm’s characteristics.
- 例: 旅行販売員問題（TSP）。すべての都市の順路を試して最短ルートを探す。すべての可能性を検討するため、定義特性に一致。

## For each of the algorithms, explain the paradigm used by the algorithm and how it exemplifies this paradigm.
- 線形探索: 配列を一つずつ調べて目的の要素を探す。配列のサイズに比例する時間がかかるので、総当たりの特性を示す。

## Given an algorithm, explain the paradigm used by the algorithm and how it exemplifies this paradigm.
- 選択ソート: 未ソートの部分から最小値を探し、先頭に移動させる。各ステップで最小値を探す総当たり探索が使われる。

## Give a real-world problem, evaluate appropriate algorithmic paradigms and algorithms from these paradigms that address the problem including evaluating the tradeoffs among the paradigms and algorithms selected.
- 実世界問題: パスワードクラッキング。総当たり探索が可能だが、セキュリティが高いパスワードでは非効率。より高速なアルゴリズム（例: レインボーテーブル）とのトレードオフを評価する。

## Explain various approaches for addressing computational problems whose algorithmic solutions are exponential.
- 効率的なアルゴリズム（例: 分岐限定法）、ヒューリスティックまたは近似アルゴリズムを使って解決する手法がある。これにより、計算時間を抑えることが可能。

# 講義
脳筋探索
ヒューリスティックな方法で近似する方法はあるが、効率的な方法はない
13!=62億
3GHzでCPUが動くから、1命令1探索なら2秒くらいで解ける
