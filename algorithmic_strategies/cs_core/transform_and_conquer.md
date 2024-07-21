# Transform-and-Conquer (Instance simplification, Representation change, Problem reduction, Dynamic programming)
## Explain its definitional characteristics
- **Instance simplification**: 問題のインスタンスをより扱いやすい形に変換する。例えば、データを並び替えてから処理する。
- **Representation change**: 問題を表現する方法を変更して解決しやすくする。例えば、グラフの表現を隣接行列から隣接リストへ変更する。
- **Problem reduction**: 問題をより小さく、またはより簡単な複数の問題に分割する。例えば、大きな問題を小さなサブ問題に分割して、それぞれ独立に解決する。
- **Dynamic programming**: 複雑な問題を重複する小さな問題に分割し、それらの解を再利用することで全体の解を得る。

## Explain an example that demonstrates the paradigm including how this example satisfies the paradigm’s characteristics
- 例：動的計画法を使用したフィボナッチ数列の計算
- この例では、`n`番目のフィボナッチ数を計算するために、`n-1`と`n-2`番目の数の計算結果を利用する。問題を小さなサブ問題に分割し（Problem reduction）、計算済みの結果をメモ化することで（Representation change）、計算効率を大幅に向上させている（Instance simplification）。


## For each of the algorithms in the AL-Foundational unit, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **クイックソート**: 分割統治法を用いる。配列をピボットを基準に分割し、各部分を再帰的にソートする。これはProblem reductionの一例である。

## Given an algorithm, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **マージソート**: 分割統治法。配列を半分に分割し、それぞれをソートした後でマージする。小さな問題への分割（Problem reduction）と統合過程でのインスタンスの単純化（Instance simplification）が特徴。

## Give a real-world problem, evaluate appropriate algorithmic paradigms and algorithms from these paradigms that address the problem including evaluating the tradeoffs among the paradigms and algorithms selected
- 問題：大規模な社会ネットワークでの最短経路の検出
- アルゴリズム：ダイクストラ法（グリーディアルゴリズム）、A*（ヒューリスティック検索）
- 評価：ダイクストラ法は確実に最短経路を見つけるが計算量が大きい。A*はヒューリスティックを使用して効率を向上させるが、最適でない経路を選択する可能性がある。

## Give examples of iterative and recursive algorithms that solve the same problem, explain the benefits and disadvantages of each approach
- 問題：フィボナッチ数の計算
- 反復的アプローチ：状態を追跡するためにループを使用する。スタックオーバーフローのリスクがないが、理解しにくい場合がある。
- 再帰的アプローチ：自然で直感的な実装が可能だが、大きな入力値でスタックオーバーフローを引き起こす可能性がある。

## Explain various approaches for addressing computational problems whose algorithmic solutions are exponential
- **分枝限定法**: 探索空間を限定することで計算量を削減する。
- **バックトラッキング**: 可能性のある解を系統的に試み、条件に合わない場合は前のステップに戻る。
- **近似アルゴリズム**: 最適解に近い解を効率的に見つけるために使用される。

# 講義ノート
# 線形計画法のソルバー中身

制約条件のグラフを求める時グラフの交点を求めていくことになっていく
シンプレックス法：一番原始的ななやり方
最適化はヒューリスティックな方法で行われている
