# Tractability and intractability

P: ある程度の時間で解ける問題。理論的にはもう解けたとみなしてOK
NP: ある程度の時間で検算（問題の正しさを証明）ができる問題

P vs NP: NPでありPでない問題は存在するか？
この問題の解決方法は、NP-HardというNP以上に難しい問題を定義する
NP && NP-Hard = NP-completeと呼ぶ。

NP-completeがPに属するかいなか


## Explain the significance of NP-Completeness.


- NP完全問題の重要性を説明する。
  - NP完全問題は、他のすべてのNP問題が多項式時間で帰着可能な最も困難な問題のクラスに属する。
  - NP完全問題を効率的に解くことができれば、すべてのNP問題も効率的に解けることになる。

## Explain how NP-Hard is a lower bound and NP is an upper bound for NP-Completeness.

- NP-Hardが下限であり、NPがNP完全問題の上限であることを説明する。
  - NP-Hard問題は、NP問題よりも難しい可能性があり、必ずしもNPに属するとは限らない。
  - NP問題は、多項式時間で検証可能な問題であり、NP完全問題はその中でも特に困難な問題。

## Explain examples of NP-complete problems.

- NP完全問題の例を説明する。
  - SAT問題（充足可能性問題）：ブール論理式が真となる割り当てが存在するかどうかを判断する問題。
  - ナップサック問題：価値と重さが与えられたアイテムを選び、ナップサックの容量を超えないようにしながら価値を最大化する問題。
  - 巡回セールスマン問題（TSP）：各都市を一度だけ訪れ、元の都市に戻る最短の巡回路を求める問題。

## Explain the concept of reductions in computational complexity.

- 計算複雑性における帰着の概念を説明する。
  - ある問題を他の問題に変換するプロセスを指す。
  - 問題Aが問題Bに帰着可能である場合、問題Aを解くために問題Bを解くアルゴリズムを利用できる。
  - 帰着を利用することで、未知の問題が既知の問題と同等の難易度であることを示すことができる。
  - NP完全問題の特定には、他の既知のNP完全問題への帰着がよく使われる。
