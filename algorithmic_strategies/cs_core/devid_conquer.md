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

# 講義
分割統治法に他のdecreaseもtransformも分類できる


## Explain Strassen's Algorithm
- Strassenのアルゴリズムは、行列の掛け算を従来の方法よりも高速に行うアルゴリズム
  - 通常の行列の掛け算は、n×nの行列同士でO(n^3)の時間がかかる
  - Strassenのアルゴリズムは、この時間を約O(n^2.81)に短縮する

### 通常の行列の掛け算
- 2つのn×n行列AとBを掛け合わせて行列Cを得るとき、各要素C[i][j]は次のように計算する
  - C[i][j] = Σ (A[i][k] * B[k][j]), k=1からnまで
  - これにはn^3の乗算が必要

### Strassenのアルゴリズムの仕組み
1. 行列を4つのブロックに分割する
   - Aを4つのn/2×n/2行列 (A11, A12, A21, A22) に、Bも同様に4つのブロック (B11, B12, B21, B22) に分割する
2. 7つの新しい行列M1からM7を定義する
   - M1 = (A11 + A22) * (B11 + B22)
   - M2 = (A21 + A22) * B11
   - M3 = A11 * (B12 - B22)
   - M4 = A22 * (B21 - B11)
   - M5 = (A11 + A12) * B22
   - M6 = (A21 - A11) * (B11 + B12)
   - M7 = (A12 - A22) * (B21 + B22)
3. M1からM7を使って最終的な行列Cの各ブロックC11, C12, C21, C22を計算する
   - C11 = M1 + M4 - M5 + M7
   - C12 = M3 + M5
   - C21 = M2 + M4
   - C22 = M1 - M2 + M3 + M6
4. これにより、n×n行列の掛け算をO(n^2.81)の時間で行うことができる

### なぜ速いのか？
- Strassenのアルゴリズムは、従来のアルゴリズムが必要とするn^3の乗算をn^2.81に減らすことで、高速化を実現している
- 分割統治法を使用し、行列のサイズが大きくなるほど効果が顕著になる

### 応用例
- 大規模な行列の計算が必要な分野、例えば画像処理や科学計算、機械学習などで使用される
