# Space vs time tradeoffs (e.g., hashing)

## Explain its definitional characteristics
- **スペースと時間のトレードオフ**: アルゴリズムの設計において、メモリ使用量（スペース）と処理速度（時間）の間のバランスを取る必要がある。一般に、より多くのメモリを使用することで、計算速度を向上させることができる。
- **ハッシングの使用**: データを高速にアクセス、検索、挿入、削除するためにハッシュテーブルを使用する。ハッシュテーブルは、キーに基づいてデータを格納するためのスペースを予め確保するが、それにより操作時間を大幅に短縮する。

## Explain an example that demonstrates the paradigm including how this example satisfies the paradigm’s characteristics
- **例**: ハッシュテーブルを使ったデータベースのインデックス
- 特徴: データベースのインデックスにハッシュテーブルを使用すると、レコードの検索時間が大幅に短縮される。しかし、ハッシュテーブルのサイズが大きくなるほど、必要なメモリ量も増加する。スペースの増加と時間の減少の間にトレードオフが存在する。

## For each of the algorithms in the AL-Foundational unit, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **クイックソート**: スペースと時間のトレードオフはあまり明確ではないが、インプレースソートとしての性質により、追加のメモリをほとんど使用しない。これにより、少ないメモリで高速なソートが可能になる。

## Given an algorithm, explain the paradigm used by the algorithm and how it exemplifies this paradigm
- **ハッシュテーブル**: スペースを多く使用することで、データの挿入、削除、検索の速度を最適化する。これはスペースと時間のトレードオフの典型的な例である。

## Give a real-world problem, evaluate appropriate algorithmic paradigms and algorithms from these paradigms that address the problem including evaluating the tradeoffs among the paradigms and algorithms selected
- 問題: オンラインショッピングサイトでの商品検索機能
- アルゴリズム: ハッシュテーブル、バイナリサーチツリー
- 評価: ハッシュテーブルは即時に商品を検索できるが、多くのメモリを消費する。バイナリサーチツリーはメモリ効率が良いが、検索速度はハッシュテーブルに劣る。システムのリソースとユーザの要求に応じて選択する必要がある。

## Give examples of iterative and recursive algorithms that solve the same problem, explain the benefits and disadvantages of each approach
- 問題: 階乗の計算
- 反復的アプローチ: forループを使用。スタックオーバーフローの心配がないが、再帰的アプローチに比べ直感的ではない。
- 再帰的アプローチ: コードが簡潔で理解しやすいが、深い再帰によりスタックオーバーフローを引き起こすリスクがある。

## Explain various approaches for addressing computational problems whose algorithmic solutions are exponential
- **分枝限定法**: 効率的な探索を行うために、不必要な探索パスを剪定する。
- **ダイナミックプログラミング**: 問題を小さなサブプロブレムに分割し、各サブプロブレムの解を保存して再利用することで、計算量を削減する。
- **メモ化**: 再帰的なアプローチで計算された値を保存し、必要な時に再計算することなく再利用する。これにより、計算速度が向上する。

# 講義ノート
