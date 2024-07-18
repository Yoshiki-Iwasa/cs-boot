# Approximation algorithms

## Explain its definitional characteristics
- 近似アルゴリズムは、計算が困難またはNP困難な最適化問題に対して、実用的な時間内に近似解を求めるアルゴリズム。
- これらのアルゴリズムは、最適解との間にある許容可能な誤差の範囲内で解を提供する。
- 近似比率（approximation ratio）と呼ばれる指標を用いて、アルゴリズムの性能を評価する。これは算出された近似解の質を最適解と比較して数値化したもの。

## Explain an example that demonstrates the paradigm including how this example satisfies the paradigm’s characteristics
- 例: 巡回セールスマン問題（TSP）の近似アルゴリズム。
- 特徴: この問題はNP困難であり、厳密な解を効率的に求めることは不可能。クリスティのアルゴリズムは、2倍の近似比率で解を提供する。このアルゴリズムは、最小全域木を構築し、その後、深さ優先探索を使用して巡回路を生成する。この手法では最適解のコストの最大2倍までのコストで解を見つけることができる。

## For each of the algorithms in the AL-Foundational unit, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **クイックソート**: 分割統治法。ピボットを選んで配列を分割し、再帰的にそれぞれのサブ配列をソートする。これは分割してそれぞれの部分を治す典型的な例。

## Given an algorithm, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **貪欲アルゴリズム**: 問題の解を一歩一歩構築し、各ステップで局所的に最適な選択を行う。例えば、コイン問題で最小数のコインを選ぶ場合、最大額面のコインから順に使用する。

## Give a real-world problem, evaluate appropriate algorithmic paradigms and algorithms from these paradigms that address the problem including evaluating the tradeoffs among the paradigms and algorithms selected
- 問題: ネットワーク上でのデータパケットの最適なルーティング。
- アルゴリズム: ダイクストラ法（最短経路問題）、貪欲アルゴリズム（最初に到達可能なノードから順に探索）。
- 評価: ダイクストラ法は正確だが計算コストが高い。貪欲アルゴリズムは速いが最適でない結果を出すことがある。

## Give examples of iterative and recursive algorithms that solve the same problem, explain the benefits and disadvantages of each approach
- 問題: 二分探索
- 反復的アプローチ: whileループを使用してリストの中間点を探索。明確でスタックオーバーフローのリスクがない。
- 再帰的アプローチ: 自分自身を呼び出してサブリストで探索を続ける。コードはシンプルだが、深いリストでスタックオーバーフローを引き起こす可能性がある。

## Explain various approaches for addressing computational problems whose algorithmic solutions are exponential
- **分枝限定法**: 問題の解空間を探索しながら、非効率的なパスを早期に排除する。
- **ダイナミックプログラミング**: 小さなサブ問題の解を再利用して、大きな問題を解決する。
- **近似アルゴリズム**: 完全な解よりも、計算効率の良い近似解を求める。
- **ランダム化アルゴリズム**: 確率的な選択を用いて解を求め、期待されるパフォーマンスを達成する。
