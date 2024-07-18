# Divide-and-Conquer

## Explain its definitional characteristics
- 大きな問題を小さな問題に分割する。
- 分割した小さな問題を独立に解く。
- 小さな問題の解を組み合わせて、元の問題の解を得る。

## Explain an example that demonstrates the paradigm including how this example satisfies the paradigm’s characteristics
- 例：クイックソート
- 説明：リストをピボットを基準にして二つに分割し、それぞれのサブリストを再帰的にソートする。分割したサブリストが十分小さくなると、それぞれ独立して扱いやすくなり、最終的に全体がソートされる。

## For each of the algorithms in the AL-Foundational unit, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **マージソート**: 分割統治法。リストを半分に分割し、それぞれをソートしてから結合する。
- **クイックソート**: 分割統治法。リストをピボットで分割し、分割された各部分を再帰的にソートする。

## Given an algorithm, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **バイナリサーチ**: 分割統治法。配列を中央の値で分割し、目的の値が中央値より大きいか小さいかに応じて検索範囲を半分に絞り込む。

## Give a real-world problem, evaluate appropriate algorithmic paradigms and algorithms from these paradigms that address the problem including evaluating the tradeoffs among the paradigms and algorithms selected
- 問題：大量のデータを含むデータベースから特定の情報を検索する。
- アルゴリズム：バイナリサーチ（分割統治法）
- 評価：バイナリサーチはソートされたデータに対して非常に高速だが、データが未ソートの場合、ソートのコストが必要となる。

## Give examples of iterative and recursive algorithms that solve the same problem, explain the benefits and disadvantages of each approach
- 問題：リストの要素を反転する。
- 反復的アプローチ：forループを使用してリストの両端から中央に向かって要素を交換する。直感的でスタックのオーバーフローの心配がない。
- 再帰的アプローチ：リストを2つに分割し、それぞれを再帰的に反転する。シンプルなコードだが、ディープリカーションによるスタックオーバーフローのリスクがある。

## Explain various approaches for addressing computational problems whose algorithmic solutions are exponential
- **分枝限定法**: 探索中に非効率的なパスを事前に切り捨てることで探索空間を削減する。
- **ダイナミックプログラミング**: サブプロブレムの解をメモ化して重複計算を避ける。
- **近似アルゴリズム**: 完全な解を求める代わりに近似解を迅速に提供する。
