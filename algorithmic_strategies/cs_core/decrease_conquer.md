# Decrease-and-Conquer(By a Constant , By a Constant Factor, By a Variable Size)

## Explain its definitional characteristics
- **By a Constant**: 問題のサイズを一定の数だけ減少させる。例えば、一つの要素を取り除く。
- **By a Constant Factor**: 問題のサイズを一定の割合で減少させる。例えば、問題を半分のサイズに減らす。
- **By a Variable Size**: 問題のサイズを変動する量で減少させる。この減少量は、問題によって異なる。

## Explain an example that demonstrates the paradigm including how this example satisfies the paradigm’s characteristics
- **バイナリサーチ**: サイズを半分（constant factor）にして問題を解決する。
  - 配列がソートされていることを前提に、配列の中間の要素を調べ、探索する値と比較して、値が中間の要素より大きいか小さいかによって探索範囲を半分に削減する。

## For each of the algorithms in the AL-Foundational unit, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **インサートソート**: By a Constant。一つの要素を取り除き、残りをソートした後、その要素を適切な位置に挿入する。

## Given an algorithm, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **セレクションソート**: By a Constant。最小（または最大）の要素を見つけ出し、リストの先頭（または末尾）に移動させることで問題のサイズを1減少させる。

## Give a real-world problem, evaluate appropriate algorithmic paradigms and algorithms from these paradigms that address the problem including evaluating the tradeoffs among the paradigms and algorithms selected
- 問題: 電子メールのスパムフィルタリング
  - アルゴリズム: 決定木（Divide-and-Conquer）、ベイジアンフィルタ（Decrease-and-Conquer by Variable Size）
  - 評価: 決定木は明確なルールに基づいて高速に処理できるが、モデルの複雑さが問題になる場合がある。ベイジアンフィルタは柔軟で精度が高いが、訓練データに依存する。

## Give examples of iterative and recursive algorithms that solve the same problem, explain the benefits and disadvantages of each approach
- 問題: フィボナッチ数の計算
  - 反復的アプローチ: 連続する数を計算するためにループを使用。メモリ効率が良く、大きな数でも扱える。
  - 再帰的アプローチ: 自然な形で問題を表現できるが、大きな数での計算ではスタックオーバーフローを引き起こす可能性がある。

## Explain various approaches for addressing computational problems whose algorithmic solutions are exponential
- **分枝限定法**: 計算すべき範囲を絞り込むために、枝刈りを行いながら探索する。
- **ダイナミックプログラミング**: 重複する計算を避けるために、過去の計算結果を保存して利用する。
- **近似アルゴリズム**: 完全な解を求める代わりに、許容できる範囲での近似解を迅速に求める。
